//�ļ�·������s2_3\sclass2_3_date.cpp
#include "sclass2_3_date.h"
Date::Date( )             //����Date��Ĺ��캯�����������ʼ��Ϊ2000��1��1��
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
	cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
} 
