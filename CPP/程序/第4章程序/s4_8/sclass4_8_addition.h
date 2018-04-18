//类声明文件
//文件名：s4_8\sclass4_8_addition.h 

//编译预处理语句：如果未定义__SCLASS4_8_ADDITION_H__则定义它，
//直到遇到#endif结束
#ifndef __SCLASS4_8_ADDITION_H__ 
#define __SCLASS4_8_ADDITION_H__ 

#include <iostream>		//包含头文件,使用iostream库
#include <string>		//包含头文件,使用string库

using namespace std;	//使用std命名空间

//声明CAddition类     
class CAddition  
{
public:
	int Add(int a, int b);				//两个整数相加
	string Add(string s1, string s2);	//两个字符串对象相加
	int Add(double d1, double d2);		//两个双精度浮点数相加
	//double Add(double d1, double d2);	//不能重载，与上一个函数仅仅返回值类型不同
};  

#endif   //结束编译预处理 