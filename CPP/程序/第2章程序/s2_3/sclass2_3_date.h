//�������ļ�
//�ļ�·������s2_3\sclass2_3_date.h 

//����Ԥ������䣺���δ����__SCLASS2_3_DATE_H__��������
//ֱ������#endif������
#ifndef __SCLASS2_3_DATE_H__ 
#define __SCLASS2_3_DATE_H__ 

#include <iostream>  
using namespace std; 

class Date 
{ 
public: 
	Date( );	 
	void SetDate(int y, int m, int d) ;
	bool IsLeapYear( );
	void Print( );
private: 
	int year, month, day;  //��������������ԣ��ꡢ�¡���
};
#endif
