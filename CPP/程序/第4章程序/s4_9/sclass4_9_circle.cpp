//类的实现文件
//文件名：s4_9\sclass4_9_circle.cpp

#include "sclass4_9_circle.h"    //包含类声明头文件

//成员函数Reference()的实现
void CCircle::Reference()  
{
	cout << "我是成员函数." << endl;
}

//全局重载函数Reference()的实现
void Reference()  
{
	cout << "我是全局重载函数Reference()." << endl;
}

//全局重载函数Reference(CCircle &roCC)的实现
void Reference(CCircle &roCC)  
{
	cout << "我是全局重载函数Reference(CCircle &roCC)." << endl;
}