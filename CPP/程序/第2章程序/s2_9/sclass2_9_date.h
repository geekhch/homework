//�������ļ�
//�ļ�·������s2_9\sclass2_9_date.h

//����Ԥ������䣺���δ����__SCLASS2_9_DATE_H__��������
//ֱ������#endif������
#ifndef __SCLASS2_9_DATE_H__ 
#define __SCLASS2_9_DATE_H__ 

#include <iostream>  
using namespace std; 

class Date 
{ 
public: 	
	Date();                //����һ���޲����Ĺ��캯��
	Date(int y, int m, int d);   //�����������������Ĺ��캯��	
	~Date() ;				//������������
	void SetDate(int y, int m, int d) ;
	bool IsLeapYear();
	void Print();
 
private: 
	int year, month, day;     //��������������ԣ��ꡢ�¡���
} ;
#endif
