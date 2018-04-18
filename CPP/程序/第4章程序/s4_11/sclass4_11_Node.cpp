//类的实现文件
//文件名：s4_11\sclass4_11_Node.cpp

#include <iostream>  					//包含头文件,使用iostream库
#include "sclass4_11_Node.h"    		//包含类声明头文件

/*****************************************************************************/
//CNode的带参构造函数
CNode::CNode(string str)				//节点构造函数
{
	m_pStr = new string(str);			//new字符串对象空间，存节点名
	if( m_pStr==NULL )
	{
		cout << "内存分配失败。" << endl;
		exit(0);						//内存分配失败，退出
	}
	m_nodeNum = GetNumber();			//取得节点编号，并赋值给m_nodeNum
	cout << "CNode全新创建节点,No: "<<m_nodeNum<<",Name: " << *m_pStr << endl;
}

//CNode的拷贝构造函数
CNode::CNode(const CNode &oCN)
{
	m_pStr = new string(*oCN.m_pStr);	//new字符串对象空间，存节点名
	if( m_pStr==NULL )
	{
		cout << "内存分配失败。" << endl;
		exit(0);						//内存分配失败，退出
	}
	m_nodeNum = GetNumber();			//取得节点编号，并赋值给m_nodeNum
	cout << "CNode拷贝创建节点,No: "<<m_nodeNum<<",Name: " << *m_pStr << endl;
}

//CNode的析构函数
CNode::~CNode()
{
	cout << "~CNode销毁节点,No: "<<m_nodeNum<<",Name: " << *m_pStr << endl;
	delete m_pStr;						//自动销毁m_pStr指向的string对象
}

//重载CNode的赋值运算符（允许节点名、节点编号相同的对象存在）
CNode &CNode::operator=(const CNode &oCN)
{
	if (this == &oCN)							//判断是否自己赋值给自己
	{
		return *this;							//如果是，不必复制，返回
	}
	delete m_pStr;		//释放赋值运算符左边对象的字符串对象指针所指对象
	m_pStr = new string(*oCN.m_pStr);	//new字符串对象空间，存节点名
	if( m_pStr==NULL )
	{
		cout << "内存分配失败。" << endl;
		exit(0);		//内存分配失败，退出
	}
	// 注：此处只能考虑赋值，以体现赋值运算符的本意。但m_nodeNum出现重复。
	m_nodeNum = oCN.m_nodeNum;			//取得节点编号，并赋值给m_nodeNum
	cout << "CNode复制了对象,No: "<<m_nodeNum<<",Name: " << *m_pStr << endl;
	return *this;
}

//重载CNode的','运算符重载
const CNode & CNode::operator,(const CNode &oCN)
{
	return oCN;								//直接返回第二操作数
}

//重载CNode的输出运算符,
ostream& operator<<(ostream& scout, CNode& obj)	//重载<<
{
	scout << "Node Name: " << *(obj.GetStr()) << ",";
	scout << "Node Number: "<< obj.GetNodeNum() << "." << endl;
	return scout; 
}

//重载CNode的输入运算符  		 
istream& operator>>(istream& scin, CNode& obj)			//重载>>
{
	char s[81];						// 设置81仅仅为了编程方便
    cout << "Please Enter Node Name: ";
 	scin.getline(s, 81, '\n');		//getline(scin, *(obj.GetStr()));
	*(obj.GetStr()) = s;			//s转换为string对象后再赋值
    cout << "Please enter Node Number: ";
    scin >> obj.GetNodeNum();		//此处对输入的节点编号大小未予限制
	return scin;
}

//返回当前sNodeNum,并自增1.
int CNode::GetNumber(void)				
{
	return sNodeNum<LEN-1 ? sNodeNum++:(sNodeNum=0,LEN-1);	//确保小于LEN
}

//返回指向节点名字的字符串指针
string *CNode::GetStr()					
{
	return m_pStr;
}

//返回节点的编号,也是m_nodeNum
int &CNode::GetNodeNum()					
{
	return m_nodeNum;
}

//CNodeArray类的构造函数
CNodeArray::CNodeArray(int aLength)	
{
	for (int i=0; i<aLength; i++)
	{
		m_poCN[i] = NULL;		//指针数组初始化，全部指向NULL
	}
    m_aLength = aLength;		//数组长度设置
	m_aIndex = 0;				//当前节点下标设置为0
	cout << "CNodeArray，创建一个节点数组对象，length=: " << m_aLength << endl;
}

//~CNodeArray析构函数,确认m_poCN指向的对象的指针所指向的空间是否析构了
CNodeArray::~CNodeArray(void)							
{
	for (int i=0; i<m_aIndex; i++)
	{
		if ( m_poCN[i]!=NULL )	//m_poCN[i]指向对象时,才调用delete运算符
		{
			delete m_poCN[i];	//如m_poCN[i]指向CNode对象，会自动调用~CNode( )
			cout << "delete: m_poCN[" << i << "]." << endl;
		}
	}
	cout << "~CNodeArray:析构完成。" << endl;
}

//这里设计了很简单的节点插入功能，即只是让数组的CNode指针指向新节点而已。
//为了安全，先对插入位置做判断，如果原来有节点，报插入失败，返回。
//也可销毁原节点，强制插入。
bool CNodeArray::Insert(CNode &oCN)	//插入一个节点
{
	if( m_aIndex>=m_aLength )
	{
		cout << "对不起，超过了数组最大下标，不可再插入!" << endl;
		return false;
	}

	//将要插入的节点复制到节点数组中
	if (m_poCN[m_aIndex] != NULL)
	{
		cout << "此位置已有节点，不可再插入!" << endl;
		return false;
	}

	m_poCN[m_aIndex] = &oCN;
	cout << "插入新节点,Pos: "<< m_aIndex << ",No: " << oCN.GetNodeNum( ) 
		<<",Name:" << *oCN.GetStr( ) << endl;
	m_aIndex++;
	return true;
}

//这里不是链表操作，相当于delete一个节点，并让指针为空即可
bool CNodeArray::Delete(int index)			//删除一个节点
{
	if (m_poCN[index] == NULL)
	{
		cout << "Pos: " << index << "=NULL,无须调用delete运算符." << endl;
		return false;
	}
	delete m_poCN[index];					//释放当前节点
	m_poCN[index] = NULL;
	cout << "delete: m_poCN[" << index << "]," << "Pos: " <<  index 
		<< ",此位置指向的节点delete成功!" << endl;
	return true;
}


//CNodeArray的'[ ]'运算符重载. 这里返回了一个对象，当[ ]被调用时
//可以观察到CNode的拷贝构造函数和析构函数的调用过程。
CNode CNodeArray::operator[](int i)
{
	if ( (i<=m_aIndex)&&( i>=0 ) )
	{
		if (m_poCN[i]==NULL)	
		{
			cout << "没有元素,出错." << endl;
			exit(0);
		}
		return *m_poCN[i];			//返回第i个节点指针所指向的对象
	}
	else 
	{
		cout << "数组越界" << endl;
		exit(0);					//越界则终止程序
	}
}

//重载CNodeArray的new运算符
void *CNodeArray::operator new(size_t size)
{
	cout << "调用CNodeArray自定义的new创建对象.\n";
	return malloc(size);
}

//重载CNodeArray的delete运算符
void CNodeArray::operator delete(void *p)
{
	cout << "调用CNodeArray自定义的delete销毁对象.\n";
	free(p);
}


