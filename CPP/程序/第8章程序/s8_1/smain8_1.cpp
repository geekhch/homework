//文件名：s8_1\smain8_1.cpp
//new和delete的使用

#include <iostream>
#include <string>
using namespace std;
const int LEN = 5;					//定义一个常量

class CNode							//声明CNode类
{
public:
	CNode(int value=0):m_value(value) {}	//构造函数，缺省参数value=0
	void Print() const				//显示，常成员函数
	{ cout<< "CNode value : " << m_value << endl; }

private:
	int m_value;					//节点值
};

//测试函数
int main()
{
	CNode *poCN1 = new CNode[LEN];	//创建对象数组，自动调用缺省或无参构造函数
	if (poCN1 == NULL) return 1;	//判断动态内存申请是否成功。
	delete []poCN1;					//释放对象数组，去掉[ ]数组将释放不完全
	poCN1 = NULL;					//让poCN指针指向NULL。否则，它依然指向原动态空间

	CNode *poCN2 = new CNode(5);
	if (poCN2 == NULL) return 2;	//判断动态内存申请是否成功
	delete poCN2;					//释放单个对象
	poCN2 = NULL;

	int *p1, *p2,(*p3)[3];			//p1，p2一般整型指针，p3行指针
	p1 = new int;					//new一个整数
	p2 = new int (200);				//new一个整数，其初值为200.
	p3 = new int[2][3];				//new一个关于一维数组的数组（元素具有三个整型元素的一维数组）
	delete p1;						//释放一个int数据
	delete p2;						//释放一个int数据
	delete []p3;					//释放一个关于一维数组的数组
	p1 = NULL;	p2 = NULL;	p3 = NULL;

	//oCP1, oCP2为在堆栈（注意不是堆）中分配的对象，无须delete，系统自动释放。
	CNode oCP1(1);					//生成一般对象，就是对象变量，其值可以改变
	const CNode oCP2(3);			//生成一个常对象。对象常量。其值不可改变

	system("PAUSE");				//等待键盘输入以实现暂停  
	return 0;						//返回0
}
