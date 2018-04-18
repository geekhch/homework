//文件路径名：s2_9\sclass2_9_date.cpp
#include "sclass2_9_date.h"
Date::Date( )
{
	year=2000;  
	month=1;   
	day=1;  
} 
Date::Date(int y, int m, int d)
{
	year=y;  
	month=m;   
	day=d;  
} 
Date::~Date()  
{
	cout<<"正在析构"<<year<<"年"<<month<<"月"<<day<<"日日期对象"<<endl;
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
