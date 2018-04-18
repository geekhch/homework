//主文件，文件名：ch5_4\smain5_4.cpp

#include <iostream>			//包含头文件，使用iostream库
#include <string>			//包含头文件，使用string库
using namespace std;		//使用std名字空间

//TClass是类模板，是CInteger类和CFloat类的抽象描述，它是一个类模板，
//用类模板可以生成具体的模板类，模板类则可以用于创建对象

//声明类模板
template <class Type> 
class TClass           
{
public:
	TClass(Type item): m_item(item) {}		//使用缺省的析构函数
	void SetItem(Type item) { m_item = item; }
	Type GetItem() const;

private:
	Type m_item;
};
 
//定义类模板成员函数
template <class Type>
Type TClass<Type>::GetItem() const
{
	return m_item;
}

//测试程序
int main()    
{
	TClass<int> Obj1(128);				//定义一个TClass<int>模板类对象
	cout << Obj1.GetItem( ) << endl;
	Obj1.SetItem(218);
	cout << Obj1.GetItem( ) << endl;

	TClass<float> Obj2(0.128);			//定义一个TClass<float>模板类对象
	cout << Obj2.GetItem( ) << endl;
	Obj2.SetItem(0.218);
	cout << Obj2.GetItem( ) << endl;

	system("PAUSE");					//等待键盘输入以实现暂停  
	return 0;							//返回0
}

