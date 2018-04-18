//类声明文件:在COperator类中声明重载运算符。
//文件名：s4_10\sclass4_10_operator.h 

//编译预处理语句：如果未定义__SCLASS4_10_OPERATOR_H__则定义它，
//直到遇到#endif结束
#ifndef __SCLASS4_10_OPERATOR_H__ 
#define __SCLASS4_10_OPERATOR_H__ 

#include <iostream>  //包含头文件。使用iostream库

using namespace std; //使用std命名空间

//声明运算符类
class COperator
{
public:
 	COperator(int b=0);						//构造函数
 	
  	int operator++(int i);				//重载后缀++
  	int operator++();					//重载前缀++
 	int operator()();					//重载函数运算符，功能：取m_v的值
	
	COperator operator+(const COperator &ob);	//重载算术运算符:对象+对象

	bool operator>(const COperator &ob);		//重载比较运算符:对象>对象
	bool operator<=(const COperator &ob);		//重载比较运算符:对象<=对象

public:
	int m_v;
};

#endif   //结束编译预处理

 



