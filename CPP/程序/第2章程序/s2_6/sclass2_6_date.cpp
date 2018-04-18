//文件路径名：s2_6\sclass2_6_date.cpp
#include "sclass2_6_date.h"
Date::Date(int y, int m, int d)
{
	year=y;  
	month=m;   
	day=d;  
} 
void Date::SetDate(int y, int m, int d) 
{
	year=y;  
	month=m;   
	day=d;  
} 
bool Date::IsLeapYear()
{
	return(year%4==0 && year%100!=0) || (year%400==0);
} 
void Date::Print()
{
	cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
} 
