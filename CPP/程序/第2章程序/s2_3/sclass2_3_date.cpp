//文件路径名：s2_3\sclass2_3_date.cpp
#include "sclass2_3_date.h"
Date::Date( )             //定义Date类的构造函数，将对象初始化为2000年1月1日
{
	year=2000;  
	month=1;   
	day=1;  
} 
void Date::SetDate(int y, int m, int d) 
{
	year=y;  
	month=m;   
	day=d;  
} 
bool Date::IsLeapYear( ) 
{
	return (year%4==0 && year%100!=0) || (year%400==0);
} 
void Date::Print( ) 
{
	cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
} 
