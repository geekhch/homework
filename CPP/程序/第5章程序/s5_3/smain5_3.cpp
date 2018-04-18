//主文件，文件名：ch5_3\smain5_3.cpp

#include <iostream>			//包含头文件，使用iostream库
#include <string>			//包含头文件，使用string库
using namespace std;		//使用std名字空间

//声明Integer类
class CInteger				
{
public:
	CInteger(int item): m_item(item) {}
	void SetItem(int item) { m_item = item; }
	int GetItem() const;

private:
	int m_item;
};

//声明CFloat类
class CFloat					 
{
public:
	CFloat(float item): m_item(item) {}
	void SetItem(float item) { m_item = item; }
	float GetItem() const;

private:
	float m_item;
};

//定义CInteger成员函数
int CInteger::GetItem() const
{
	return m_item;
}

//定义CFloat成员函数
float CFloat::GetItem() const
{
	return m_item;
}

//测试程序
int main()    
{
	CInteger Obj1(128);					//定义一个CInteger对象
	cout << Obj1.GetItem( ) << endl;
	Obj1.SetItem(218);
	cout << Obj1.GetItem( ) << endl;

	CFloat Obj2(0.128);					//定义一个CFloat对象
	cout << Obj2.GetItem( ) << endl;
	Obj2.SetItem(0.218);
	cout << Obj2.GetItem( ) << endl;

	system("PAUSE");					//等待键盘输入以实现暂停  
	return 0;							//返回0
}

