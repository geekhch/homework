//类的实现文件
//文件名：s4_8\sclass4_8_addition.cpp

#include "sclass4_8_addition.h"    //包含类声明头文件

//Add(int a, int b)函数的实现
int CAddition::Add(int a, int b)  
{
	int c = (a+b)%250;
	cout << "两个整数的和对250取余:=" << c << endl;
	return c;
}

//Add(string s1, string s2)函数的实现
string CAddition::Add(string s1, string s2)  
{
	string s = s1+s2;			
	cout << "子曰:" << s << endl;
	return s;
}  

//Add(double d1, double d2)函数的实现
int CAddition::Add(double d1, double d2)  
{
	int d = d1+d2;				// 自动类型转换
	cout << "两个双精度浮点数之和取整:=" << d << endl;
	return d;
}  
