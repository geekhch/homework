// �ļ�·����:s2_1\sclass2_1_date.h
#include <iostream>               		//����Ԥ��������
using namespace std;					//ʹ�������ռ�std 

class Date 
{ 
public: 
	void SetDate(int y, int m, int d) 	//���������Ϊ�����õ�ǰ���ڵ�������
	{
		year=y;
		month=m;
		day=d;
	} 
	bool IsLeapYear( )					//���������Ϊ���жϵ�ǰ�����Ƿ���������
	{
		return(year%4==0 && year%100!=0) || (year%400==0);
 	} 
	void Print( )		//���������Ϊ�������ǰ���ڵ�������
	{
		cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
	} 
private: 
	int year; 			//��������������ԣ���
	int month; 			//��������������ԣ���
	int day; 			//��������������ԣ���
} ;
