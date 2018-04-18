// 文件路径名:s6_14\smain6_14.cpp
#include <iostream>               			// 编译预处理命令
#include <list>			          			// 编译预处理命令
#include <queue>							// 编译预处理命令
using namespace std;						// 使用命名空间std 

int main()									// 主函数main()
{
	queue<int, list<int> > q;				// 定义队列对象
	for(int i = 1; i <= 5; ++i)
	{	// 依次入栈
		q.push(i);							// i入队
	}
    
	cout << "队列q:";						// 输出提示
	while (!q.empty())
	{	// 队列q非空
		cout << q.front() << " ";			// 输出队列
		q.pop();							// 出队
	}
	cout << endl;							// 换行

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
