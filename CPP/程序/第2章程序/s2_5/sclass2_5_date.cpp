//�ļ�·������s2_5\sclass2_5_date.cpp
#include "sclass2_5_date.h"
Date::Date()					//����һ���޲����Ĺ��캯��
{
	year=2000;  
	month=1;   
	day=1;  
} 
Date::Date(int y, int m, int d)  //����һ�������������Ĺ��캯��
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
	return (year%4==0 && year%100!=0) || (year%400==0);
} 
void Date::Print()
{
	cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
}
