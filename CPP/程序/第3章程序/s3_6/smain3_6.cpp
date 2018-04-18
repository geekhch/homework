//文件名：s3_6\smain3_6.cpp
#include <iostream>  
using namespace std;  

// 定义基类：A
class A
{
public:	 
	A() 
	{ 
		cout << "调用类A的构造函数" << endl;
	}
	~A()
	{ 
	 	cout << "调用类A的析构函数" << endl;
	}	
};
class B : public A     //定义派生类B，为其指定基类及继承方式
{
public:	 
	B() 
	{ 
		cout << "调用类B的构造函数" << endl;
	}
	~B()
	{ 
		cout << "调用类B的析构函数" << endl;
	}	
};
int main()
{
	B b;   //通过派生类对象b的创建，观察基类与派生类构造函数的调用顺序；
	   	   //通过对象b的消亡，观察系统调用基类与派生类析构函数的顺序；
	return 0;
}
