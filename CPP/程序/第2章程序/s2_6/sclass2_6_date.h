//�������ļ�
//�ļ�·������s2_6\sclass2_6_date.h 

//����Ԥ������䣺���δ����__SCLASS2_6_DATE_H__��������
//ֱ������#endif������
#ifndef __SCLASS2_6_DATE_H__ 
#define __SCLASS2_6_DATE_H__ 

#include <iostream>  
using namespace std; 

class Date 
{ 
public: 		
	Date(int y=2000, int m=1, int d=1);		//���������������Ĺ��캯��
	void SetDate(int y, int m, int d) ;
	bool IsLeapYear();
	void Print();
private: 
	int year, month, day;					//�������ԣ��ꡢ�¡���
};
#endif
