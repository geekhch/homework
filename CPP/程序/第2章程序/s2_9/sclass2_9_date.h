//类声明文件
//文件路径名：s2_9\sclass2_9_date.h

//编译预处理语句：如果未定义__SCLASS2_9_DATE_H__则定义它，
//直到遇到#endif结束。
#ifndef __SCLASS2_9_DATE_H__ 
#define __SCLASS2_9_DATE_H__ 

#include <iostream>  
using namespace std; 

class Date 
{ 
public: 	
	Date();                //声明一个无参数的构造函数
	Date(int y, int m, int d);   //声明个带三个参数的构造函数	
	~Date() ;				//声明析构函数
	void SetDate(int y, int m, int d) ;
	bool IsLeapYear();
	void Print();
 
private: 
	int year, month, day;     //声明日期类的属性：年、月、日
} ;
#endif
