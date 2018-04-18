//类声明文件
//文件路径名：s2_6\sclass2_6_date.h 

//编译预处理语句：如果未定义__SCLASS2_6_DATE_H__则定义它，
//直到遇到#endif结束。
#ifndef __SCLASS2_6_DATE_H__ 
#define __SCLASS2_6_DATE_H__ 

#include <iostream>  
using namespace std; 

class Date 
{ 
public: 		
	Date(int y=2000, int m=1, int d=1);		//声明带三个参数的构造函数
	void SetDate(int y, int m, int d) ;
	bool IsLeapYear();
	void Print();
private: 
	int year, month, day;					//声明属性：年、月、日
};
#endif
