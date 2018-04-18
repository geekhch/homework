//类声明文件
//文件名：s4_11\sclass4_11_Node.h 

//编译预处理语句：如果未定义__SCLASS4_11_NODE_H__则定义它，
//直到遇到#endif结束
#ifndef __SCLASS4_11_NODE_H__ 
#define __SCLASS4_11_NODE_H__ 

#include <iostream>  					//包含头文件,使用iostream库
#include <string>  						//包含头文件,使用string库
using namespace std; 					//使用std命名空间

const int LEN = 20;	//数组指针的数组长度，可设置长点，比如:1000个节点
class CNodeArray;	//前向声明节点数组类，以便在CNode类中声明为友元类时使用

/******************************************************************************
//声明节点类, 这里只声明了节点名字和节点编号两种数据成员。
//为了说明拷贝构造函数及部分运算符重载的必要性，将节点名字定义为string类型指针。
//在节点类中定义了拷贝构造函数等。
//练习时了可用一个类族代替CNode设计复杂的节点结构，如：图5.6中的CEmployee类族。
******************************************************************************/
class CNode
{
	friend CNodeArray;	//CNodeArray是CNode的友元，方便访问私有成员
	friend ostream& operator<<(ostream& cout,CNode& obj);	//重载<<
   	friend istream& operator>>(istream& cin,CNode& obj);		//重载>>
	static int sNodeNum;	//静态成员,每生成一个节点对象自动加1,

public:
	CNode(string str);		//构造函数,节点编号调用CreatNumber()函数取得
	CNode(const CNode &oCN);			//拷贝构造函数
	virtual ~CNode();					//虚析构函数
	CNode &operator=(const CNode &oCN);	//重载赋值运算符 
	const CNode &operator,(const CNode &oCN);		//重载","
	int GetNumber(void);				//返回当前sNodeNum,并自增1.
	string *GetStr();					//返回指向节点名字的字符串指针
	int &GetNodeNum();					//返回节点的编号

private:
	string *m_pStr;			//字符串对象指针，可以指向一个字符串对象。
	int m_nodeNum;			//节点编号，代表雇员编号等，该编号要具有唯一性。
};

/******************************************************************************
//声明节点数组类,它主要用于管理众多节点。它的数据成员和函数成员设计主要基于
//方便管理众多节点的需要。为了操作简单，在本例子中设计了一个长度为LEN的指针
//数组。数组的每一个成员都可以指向一个CNode节点对象。当系统生成一个节点后，
//就根据m_aIndex确定节点在数组中的位置。当节点销毁后，也不考虑收回与其对应
//的元素指针以作他用。练习时，可从以下几个角度考虑扩展：
//1. 考虑回收节点删除后的数组指针以作后用；
//2. 考虑设计一个比较小的数组，比如长度为26，然后按照节点名字的首字母不同对
//   应存放在不同的数组指针位置，名字首字母相同的节点按照链表方式存放其后。
//3. 其他功能扩展。本程序的设计目的主要是为了方便观察程序的执行过程。
******************************************************************************/
class CNodeArray
{
	friend CNode;
public:
	CNodeArray(int aLength = LEN);				//构造函数,默认数组长度为LEN个
	virtual ~CNodeArray(void);					//虚析构函数
	CNode operator[](int i);					//重载"[ ]"
	void *operator new(size_t size);			//重载new
	void operator delete(void *p);				//重载delete
	bool Insert(CNode &oCN);					//在节点数组中插入一个节点
	bool Delete(int index);						//在节点数组中删除一个节点

private:
	CNode *m_poCN[LEN];			//节点指针数组,用来存放指向节点的指针
	int m_aLength;				//指针数组长度
	int m_aIndex;				//节点指针数组中数组的当前操下标值
};

#endif   //结束编译预处理 
