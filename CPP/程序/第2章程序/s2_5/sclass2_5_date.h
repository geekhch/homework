//�������ļ�
//�ļ�·������s2_5\sclass2_5_date.h 

//����Ԥ������䣺���δ����__SCLASS2_5_DATE_H__��������
//ֱ������#endif������
#ifndef __SCLASS2_5_DATE_H__ 
#define __SCLASS2_5_ DATE _H__ 

#include <iostream>  
using namespace std; 

class Date 
{ 
public: 		
	Date();							//����һ���޲����Ĺ��캯��
	Date(int y, int m, int d);		//����һ�������������Ĺ��캯��
	void SetDate(int y, int m, int d) ;
	bool IsLeapYear();
	void Print();
private: 
	int year, month, day;			//��������������ԣ��ꡢ�¡���
};
#endif
