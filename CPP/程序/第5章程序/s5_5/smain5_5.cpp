//主文件，文件名：ch5_5\smain5_5.cpp

#include <iostream>			//包含头文件，使用iostream库
#include <string>			//包含头文件，使用string库
using namespace std;		//使用std名字空间

class CNode;				// CNode类前向声明，以便在TLinkList中使用

//声明一般链表的类模板——在该链表中的节点是无序的。
template <class Type>
class TLinkList
{
public:
	TLinkList( );						//构造函数
	virtual ~TLinkList( );				//析构函数

	virtual bool Insert( Type value );	//在链表中插入一个节点，仅在表头插入
	bool Delete( Type value );			//从链表中删除值为value的节点
	bool Search( Type value );			//判断链表中是否包含值为value的节点
	bool Modify( Type v1, Type v2 );	//查找节点值为v1的节点，并修改为v2
	virtual void Print( );				//按照链表顺序输出链表中的节点值

public:
	CNode *m_pHead;						//设置链表的头结点指针
};

//声明有序链表的模板——在该链表中的节点是有序的。
template<class Type>
class TOrderedLinkList : public TLinkList<Type>
{
public:
	TOrderedLinkList( );				//构造函数
	virtual ~TOrderedLinkList( );		//析构函数

public:
	virtual bool Insert( Type value );	//有序插入
	virtual void Print( );				//按照链表顺序输出链表中的节点值
};

//声明节点结构类
class CNode
{
	friend class TLinkList<int>;		//声明模板类为CNode的友元
	friend class TOrderedLinkList<int>;	//声明模板类为CNode的友元

public:
	CNode( int value );
	~CNode( );
	
private:
	int m_value;		//节点值
	CNode *m_pNext;		//节点后继，指向下一个节点
	CNode *m_pPre;		//节点前驱，指向上一个节点
};


//节点类构造函数
CNode::CNode( int value )
{
	m_value = value;			//节点值
	m_pNext = NULL;				//节点后继
	m_pPre = NULL;				//节点前驱
}

//节点类析构函数
CNode::~CNode( )
{
	;
}

//TLinkList类模板的构造函数
template <class Type>
TLinkList<Type>::TLinkList( )
{
	m_pHead = NULL;				//链表头
}

//TLinkList类模板的析构函数
template <class Type>
TLinkList<Type>::~TLinkList( )
{
	CNode *p = m_pHead;			//p指向第一个节点
	for (  ; p!=NULL;  )		//直到节点不为空
	{
		m_pHead = p->m_pNext;	//头指针指向下一个节点
		delete p;				//释放p所指向的节点
		p = m_pHead;			//p指向新的头节点
	}
}

//创建一个新节点，并只在头指针后面插入
template <class Type>
bool TLinkList<Type>::Insert( Type value )
{
	CNode  *pTemp = new CNode( value );		//创建一个新节点
	if ( pTemp == NULL )					//内存空间申请不成功
	{
		exit(0);							//停止执行程序
	}

	if (m_pHead == NULL)				//表头为空时插入过程有不同
	{
		pTemp->m_pNext = NULL;				//1. 节点后继为空
		pTemp->m_pPre = NULL;				//2. 节点前驱为空
		m_pHead = pTemp;					//3. 头指针指向该新节点
	}
	else								//表头不为空时
	{
		pTemp->m_pNext = m_pHead;		// 1. 将原头节点设置为新头节点的后继
		pTemp->m_pPre = NULL;			// 2. 将新头节点的前驱设置为NULL
		m_pHead->m_pPre = pTemp;		// 3. 将新头节点设置为原头节点的前驱
		m_pHead = pTemp;				// 4. 将新头节点设置为新的表头。
	}
	
	return true;
}

//删除值为value的所有节点。
//删除算法如下：首先创建一个临时节点(节点值随便设定)插入到链表头作为新的临时
//头结点，然后用p1指向新的头结点，p2指向其后继(原头结点)。然后查找p2所指是否
//应该删除，如果应该删除，则删除，删除后则p1不动，p2指向其后继。如果不应该删除
//则p1和p2都指向其后继。如此反复直到p2指向NULL为止。最后让m_pHead指向临时头结点。
template <class Type>
bool TLinkList<Type>::Delete( Type value )
{
	bool flag = false;					// 0表示没有删除任何节点，1表示删除了。
	//在链表头设置一个临时表头
	CNode oCN(0);					// 生成一个新节点以插入到表头作为临时头节点
	oCN.m_pNext = m_pHead;			// 将原头节点设置为临时头节点的后继	
	oCN.m_pPre = NULL;				// 将临时头节点的前驱设置为NULL
	m_pHead->m_pPre = &oCN;			// 将临时头节点设置为原头节点的前驱
	m_pHead = &oCN;					// 将临时头节点设置为新的表头。
	//删除值为value的所有节点
	CNode *p1=m_pHead, *p2=m_pHead->m_pNext;	//p1指向新表头节点，p2指向其后继	
	for (  ; p2!=NULL;  )			// p2为空的话说明链表已经遍历完全了			
	{
		if ( p2->m_value == value )	// 如p2所指节点正是要删除的节点
		{
			p1->m_pNext = p2->m_pNext;		//p2的后继赋值给p1的后继 
			(p2->m_pNext)->m_pPre = p1;		//p1赋值给p2的后继的前向地址
			delete p2;						//删除p2所指节点（调析构函数）
			p2 = p1->m_pNext;				//p2指向p1的新后继
			flag = true;						//说明有节点被删除
		}
		else								//如果p2所指不是要删除的节点
		{
			p1 = p2;						//p1指向p2
			p2 = p2->m_pNext;				//p2指向p1的后继
		}
	}
	// 将临时表头删除。注：oCN不是new的对象无须delete。
	m_pHead = oCN.m_pNext;
	(oCN.m_pNext)->m_pPre = NULL;

	return flag;
}

//查找链表中是否包含节点值为value的节点，有返回true，没有返回false
template <class Type>
bool TLinkList<Type>::Search( Type value )
{	
	for ( CNode  *p=m_pHead; p!=NULL; p=p->m_pNext )
	{
		if ( p->m_value == value )			//找到该节点，返回true
		{
			return true;
		}
	}
	return false;
}

//将链表中节点值为v1的节点全部修改为v2，修改成功返回true，否则false
template <class Type>
bool TLinkList<Type>::Modify( Type v1, Type v2 )
{	
	bool flag = false;				// 0表示没有任何修改节点，1表示有修改
	for ( CNode  *p=m_pHead; p!=NULL; p=p->m_pNext )
	{
		if ( p->m_value == v1 )			//找到该节点，修改为v2并返回true
		{
			p->m_value = v2;
			true = 1;
		}
	}
	return flag;
}

//按照链表顺序从表头开始取出节点值并显示
template <class Type>
void TLinkList<Type>::Print( )
{
	cout << "从TLinkList表头开始节点的值依次为:\n";
	//遍历链表以读出每一个节点的值并在终端上显示。
	for ( CNode  *p = m_pHead; p != NULL; p = p->m_pNext )
	{
		cout << " " << p->m_value << ", ";      //显示节点值
	}
	cout << endl;								//结束输出流
}


//TOrderedLinkList类模板的构造函数
template <class Type>
TOrderedLinkList<Type>::TOrderedLinkList( ):TLinkList<Type>()
{
	;
}

//TOrderedLinkList类模板的构造函数
template <class Type>
TOrderedLinkList<Type>::~TOrderedLinkList( )
{
	;
}

//TOrderedLinkList的节点插入方法与TLinkList的唯一不同就是做有序插入。
//也就是说插入位置不一定在表头。这里做排序插入。表头值小，表尾值大。
//这里可考虑另外一种算法：首先在表头和表尾分别插入一个最小值和一个最大值，
//其次在表头和表尾之间用后面的for循环寻找插入位置插入，最后删除表头和表尾
template <class Type>
bool TOrderedLinkList<Type>::Insert( Type value )
{
	CNode  *p1,*p2;							//定义两个指针插入操作时使用
	CNode  *pTemp = new CNode( value );		//定义pTemp指向new的待插入节点
	if ( pTemp == NULL )					//内存空间申请不成功
	{
		exit(0);							//停止执行程序
	}

	if (m_pHead == NULL)					//表头为空时插入为第一个节点
	{
		pTemp->m_pNext = NULL;				//1. 新节点的后继为NULL
		pTemp->m_pPre = NULL;				//2. 新节点的前驱为NULL
		m_pHead = pTemp;					//3. 头指针指向新节点
	}
	else			//当表头不为空时，首先要寻找插入位置，然后才能插入节点		
	{
		if (value<m_pHead->m_value)			//在表的头节点前插入
		{
			pTemp->m_pNext = m_pHead;		// 1. 将原头节点设置为新头节点的后继
			pTemp->m_pPre = NULL;			// 2. 将新头节点的前驱设置为NULL
			m_pHead->m_pPre = pTemp;		// 3. 将新头节点设置为原头节点的前驱
			m_pHead = pTemp;				// 4. 将新头节点设置为新的表头。
		}
		else								//不是在头节点前插入 
		{	//让p2指向p1的前驱(主要考虑链表尾部的插入)
			for ( p2=m_pHead,p1=m_pHead->m_pNext; p1!=NULL; p2=p1,p1=p1->m_pNext )
			{
				if (value<p1->m_value)		// 在链表中间插入
				{
					(p1->m_pPre)->m_pNext = pTemp;	// 1. p1的前驱的后继指向新节点
					pTemp->m_pPre = p1->m_pPre;		// 2. 新节点的前驱指向p1的前驱
					pTemp->m_pNext = p1;			// 3. 新节点的后继指向p1
					p1->m_pPre = pTemp;				// 4. p1的前驱指向新节点
					break;
				}
			}
			if (p1 == NULL)					// 在链表末尾插入
			{
				pTemp->m_pNext = NULL;		// 1. 新节点的后继设置为NULL
				pTemp->m_pPre = p2;			// 2. 新节点的前驱指向p2
				p2->m_pNext = pTemp;		// 3. p2的后继指向新节点
			}
		}
	}	
	return true;
}

//按照链表顺序从表头开始取出节点值并显示
template <class Type>
void TOrderedLinkList<Type>::Print( )
{
	cout << "从TOrderedLinkList表头开始,节点的值依次为:\n";
	//遍历链表以读出每一个节点的值并在终端上显示。
	for ( CNode  *p = m_pHead; p != NULL; p = p->m_pNext )
	{
		cout << " " << p->m_value << ", ";      //显示节点值
	}
	cout << endl;								//结束输出流
}

//主测试程序
void main( )  
{
	TLinkList<int> oILL;
	oILL.Insert( 12 );
	oILL.Insert( 24 );		//在链表oILL中，两次插入24
	oILL.Insert( 48 );		//在链表oILL中，两次插入48
	oILL.Insert( 96 );
	oILL.Insert( 24 );
	oILL.Insert( 48 );
	oILL.Insert( 96 );
	oILL.Insert( 35 );
	oILL.Print( );			//删除前显示
	oILL.Delete( 24 );		//删除值为24的节点
	oILL.Print( );			//删除后显示

	TOrderedLinkList<int> oDOLL;
	oDOLL.Insert( 12 );
	oDOLL.Insert( 24 );		//在集合oILL中，两次插入24
	oDOLL.Insert( 48 );		//在集合oILL中，两次插入48
	oDOLL.Insert( 96 );
	oDOLL.Insert( 24 );
	oDOLL.Insert( 48 );	
	oDOLL.Insert( 96 );
	oDOLL.Insert( 35 );	
	oDOLL.Print( );			//删除前显示
	oDOLL.Delete( 24 );		//删除值为24的节点
	oDOLL.Print( );			//删除后显示

	cin.get( );
}
