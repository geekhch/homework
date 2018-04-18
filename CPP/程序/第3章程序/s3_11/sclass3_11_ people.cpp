//类实现文件：s3_11\sclass3_11_ people.cpp
#include "sclass3_11_ people.h"

Date::Date( )						//定义一个无参数的构造函数
{
	year=2000;  
	month=1;   
	day=1;  
} 
Date::Date(int y, int m, int d)		//定义一个带三个参数的构造函数
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
int Date::IsLeapYear() const { return year%4==0 && year%100!=0 || year%400==0; } 
void Date::Print() const { cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl; }

People::People( int num, char s, int n, int m, int d ):birthday ( n, m, d )
{
	number = num;
	sex = s;
}

void People::SetNum(int n) { number = n; }

void People::SetSex(char s) { sex = s; }
