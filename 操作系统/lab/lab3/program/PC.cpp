#include<windows.h>
#include<fstream.h>
#include<stdio.h>
#include<string>
#include<conio.h>
//修改方案：1.根据生产者睡眠时间修改消费者请求队列
//
//定义一些常量；

//本程序允许的最大临界区数；
#define MAX_BUFFER_NUM    10

//秒到微秒的乘法因子；
#define INTE_PER_SEC 1000

//本程序允许的生产和消费线程的总数；
#define MAX_THREAD_NUM 64

//定义一个结构，记录在测试文件中指定的每一个线程的参数
struct ThreadInfo
{
    int    serial;                                //线程序列号
    char    entity;                            //是P还是C
    double    delay;                            //线程延迟
    int    thread_request[MAX_THREAD_NUM];     //线程请求队列
    int    n_request;                            //请求个数
};

//全局变量的定义

//临界区对象的声明,用于管理缓冲区的互斥访问；
int            Buffer_Critical[MAX_BUFFER_NUM]; //缓冲区声明，用于存放产品；
ThreadInfo    Thread_Info[MAX_THREAD_NUM];     //线程信息数组；
HANDLE        h_Thread[MAX_THREAD_NUM];         //用于存储每个线程句柄的数组；

HANDLE    empty_semaphore;                     //一个信号量；
HANDLE    h_mutex;                             //一个互斥量；
HANDLE    h_Semaphore[MAX_THREAD_NUM];         //生产者允许消费者开始消费的信号量；
CRITICAL_SECTION    PC_Critical[MAX_BUFFER_NUM];    

DWORD        n_Thread = 0;                     //实际的线程的数目；
DWORD        n_Buffer_or_Critical;             //实际的缓冲区或者临界区的数目；

//生产消费及辅助函数的声明
void  Produce(void *p);
void  Consume(void *p);    
bool  IfInOtherRequest(int);
int      FindProducePositon();
int      FindBufferPosition(int);

int main(int argc, char **argv)
{
    //声明所需变量；
    DWORD        wait_for_all;
    ifstream    inFile;
    
    if (argc!=2)    {
        printf("Usage:%s <File>\n",argv[0]);
        return 1;
    }

    //初始化缓冲区；
    for(int i=0;i< MAX_BUFFER_NUM;i++)
        Buffer_Critical[i] = -1;        
    
    //初始化每个线程的请求队列；
    for(int j=0;j<；;j++) {
        for(int k=0;k<MAX_THREAD_NUM;k++)
            Thread_Info[j].thread_request[k] = -1;

        Thread_Info[j].n_request = 0;
    }
    
    //初始化临界区；
    for(i =0;i< MAX_BUFFER_NUM;i++) 
        InitializeCriticalSection(&PC_Critical[i]);

    //打开输入文件，按照规定的格式提取线程等信息；
    inFile.open(argv[1]);

    //从文件中获得实际的缓冲区的数目；
    inFile >> n_Buffer_or_Critical;
    inFile.get();
    printf("输入文件是:\n");

    //回显获得的缓冲区的数目信息；
    printf("%d \n",(int) n_Buffer_or_Critical);

    //提取每个线程的信息到相应数据结构中；
    while(inFile){
        inFile >> Thread_Info[n_Thread].serial;
        inFile >> Thread_Info[n_Thread].entity;
        inFile >> Thread_Info[n_Thread].delay;

        char c;
        inFile.get(c);
		//如果是消费者会执行如下内容
        while(c!='\n'&& !inFile.eof()) {
         inFile>> Thread_Info[n_Thread].thread_request[Thread_Info[n_Thread].n_request++];
         inFile.get(c);    
        }
        
        n_Thread++;
    }  

    //回显获得的线程信息，便于确认正确性；    
    for(j=0;j<(int) n_Thread;j++) {
        int    Temp_serial  = Thread_Info[j].serial;
        char   Temp_entity  = Thread_Info[j].entity;
        double Temp_delay   = Thread_Info[j].delay;
        
        printf(" \nthread%2d    %c    %f   ",Temp_serial,Temp_entity,Temp_delay);

        int Temp_request = Thread_Info[j].n_request;

        for(int k=0;k<Temp_request;k++)
            printf(" %d    ", Thread_Info[j].thread_request[k]);

        cout<<endl;
    }
    
    printf("\n\n");

     //创建在模拟过程中几个必要的信号量//根据缓冲区确定
    empty_semaphore = CreateSemaphore(NULL,n_Buffer_or_Critical,n_Buffer_or_Critical,
                                  "semaphore_for_empty");
    h_mutex    = CreateMutex(NULL,FALSE,"mutex_for_update");

    //下面这个循环用线程的ID号来为相应生产线程的产品读写时所
    //使用的同步信号量命名；
    for(j=0;j<(int)n_Thread;j++) {              
        char lp[]="semaphore_for_produce_";
        int temp =j;
		while(temp){
			char c = (char)(temp%10);
			strcat(lp,&c);
			temp/=10;
        }

        h_Semaphore[j+1]=CreateSemaphore(NULL,0,n_Thread,lp);
    }

    //创建生产者和消费者线程；
    for(i =0;i< (int) n_Thread;i++) {
        if(Thread_Info[i].entity =='P')
            h_Thread[i]= CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(Produce),
                                    &(Thread_Info[i]),0,NULL);
        else
           h_Thread[i]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(Consume),
                                &(Thread_Info[i]),0,NULL);
    }

    //主程序等待各个线程的动作结束；
    wait_for_all = WaitForMultipleObjects(n_Thread,h_Thread,TRUE,-1);

    printf(" \n \nALL Producer and consumer have finished their work. \n");
    printf("Press any key to quit!\n");
    _getch();
    return 0;
}

//确认是否还有对同一产品的消费请求未执行；
bool IfInOtherRequest(int req)
{
    for(int i=0;i<n_Thread;i++)
        for(int j=0;j<Thread_Info[i].n_request;j++) //n_request为消费者的请求消费队列
            if(Thread_Info[i].thread_request[j] == req)  //req为被检查的生产者线程对应临界区
                return TRUE;
    return FALSE;
}

//找出当前可以进行产品生产的空缓冲区-1位置，如果找到，将其标记为被写状态-2
int FindProducePosition()
{
    int EmptyPosition;
    for (int i =0;i<n_Buffer_or_Critical;i++)
        if(Buffer_Critical[i] == -1) {
            EmptyPosition = i;

            //用下面这个特殊值表示本缓冲区正处于被写状态；
            Buffer_Critical[i] = -2;
            break;
        }
    return  EmptyPosition;
}

//找出当前所需生产者生产的产品的位置，如果没找到返回0？？？？？？？？？？？？？？？？=================================================
int FindBufferPosition(int ProPos)
{
    int TempPos;
    for (int i =0 ;i<n_Buffer_or_Critical;i++)
        if(Buffer_Critical[i]==ProPos){
            TempPos = i;
            break;
        }
    return TempPos;
}

//生产者进程
void Produce(void *p)
{
    //局部变量声明；
    DWORD    wait_for_semaphore,wait_for_mutex,m_delay;
    int        m_serial;

    //获得本线程的信息；
    m_serial = ((ThreadInfo*)(p))->serial;
    m_delay  = (DWORD)(((ThreadInfo*)(p))->delay *INTE_PER_SEC);

    Sleep(m_delay);
    //开始请求生产
    printf("Producer %2d sends the produce require.\n",m_serial);

    //确认有空缓冲区可供生产，同时将空位置数empty减1；用于生产者和消费者的同步；
    wait_for_semaphore    =  WaitForSingleObject(empty_semaphore,-1);
                        
    //互斥访问下一个可用于生产的空临界区，实现写写互斥；？？？？？？？？为何只有释放没有P操作
	//======================================
	puts("debug1");
	//======================================
    wait_for_mutex  = WaitForSingleObject(h_mutex,-1); //相当于P操作，-1为信号量所加状态
	//======================================
	puts("debug2");
	//======================================
    int  ProducePos = FindProducePosition();
    ReleaseMutex(h_mutex);

    //生产者在获得自己的空位置并做上标记后，以下的写操作在生产者之间可以并发；
    //核心生产步骤中，程序将生产者的ID作为产品编号放入，方便消费者识别;
    printf("Producer %2d begin  to produce at position %2d.\n",m_serial,ProducePos);
    Buffer_Critical[ProducePos] = m_serial;
    printf("Producer %2d finish producing :\n ",m_serial);
    printf("     position[ %2d ]:%3d \n\n" ,ProducePos,Buffer_Critical[ProducePos]);

    //使生产者写的缓冲区可以被多个消费者使用，实现读写同步；
    ReleaseSemaphore(h_Semaphore[m_serial],n_Thread,NULL);
}

//消费者进程
void Consume(void * p)
{
    //局部变量声明；
    DWORD    wait_for_semaphore,m_delay;
    int    m_serial,m_requestNum;                //消费者的序列号和请求的数目；
    int    m_thread_request[MAX_THREAD_NUM];    //本消费线程的请求队列；
    
    //提取本线程的信息到本地；
    m_serial = ((ThreadInfo*)(p))->serial;
    m_delay  = (DWORD)(((ThreadInfo*)(p))->delay *INTE_PER_SEC);
    m_requestNum = ((ThreadInfo *)(p))->n_request;
    
    for (int i = 0;i<m_requestNum;i++)
        m_thread_request[i] = ((ThreadInfo*)(p))->thread_request[i];

    Sleep(m_delay);    

    //循环进行所需产品的消费
    for(i =0;i<m_requestNum;i++){   
        
      //请求消费下一个产品
      printf("Consumer %2d request to consume %2d product\n",m_serial,m_thread_request[i]);

      //如果对应生产者没有生产，则等待；如果生产了,允许的消费者数目-1；实现了读写同步；
		//======================================
		puts("debug2");
		//======================================
      wait_for_semaphore=WaitForSingleObject(h_Semaphore[m_thread_request[i]],-1); //由于信号量初值关闭，需要等待生产者先执行

      //查询所需产品放到缓冲区的号        
      int BufferPos=FindBufferPosition(m_thread_request[i]);      
      
      //开始进行具体缓冲区的消费处理，读和读在该缓冲区上仍然是互斥的；
      //进入临界区后执行消费动作；并在完成此次请求后，通知另外的消费者本处请求已
      //经满足；同时如果对应的产品使用完毕，就做相应处理；并给出相应动作的界面提
      //示；该相应处理指将相应缓冲区清空，并增加代表空缓冲区的信号量；
      EnterCriticalSection(&PC_Critical[BufferPos]);
      printf("Consumer %2d begin to consume %2d product \n",m_serial,m_thread_request[i]);
           ((ThreadInfo*)(p))->thread_request[i] =-1;

      if(!IfInOtherRequest(m_thread_request[i])) {
        Buffer_Critical[BufferPos] = -1;        //-1标记缓冲区为空；
        printf("Consumer %2d finish consuming %2d:\n ",m_serial,m_thread_request[i]);
        printf("     position[ %2d ]:%3d \n\n" ,BufferPos,Buffer_Critical[BufferPos]);
        ReleaseSemaphore(empty_semaphore,1,NULL);
      }        
      else {
        printf("Consumer %2d finish consuming product %2d\n\n ",m_serial,m_thread_request[i]);
      }

      //离开临界区
      LeaveCriticalSection(&PC_Critical[BufferPos]);
    }
}