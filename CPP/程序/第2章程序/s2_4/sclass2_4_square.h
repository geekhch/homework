//�������ļ�
//�ļ�·������s2_4\sclass2_4_square.h

//����Ԥ������䣺���δ����__SCLASS2_4_SQUARE_H__��������
//ֱ������#endif������
#ifndef __SCLASS2_4_SQUARE_H__ 
#define __SCLASS2_4_SQUARE_H__ 

#include <iostream>  
using namespace std; 

class Square 
{ 
public: 	
	Square(double s);				//����Date��Ĵ��ι��캯��
	double GetSide(); 
	double GetCircumference();		//�����ܳ�
	double GetArea();				//�������
	void Print();  
private: 
	double side;					//����������������ԣ��߳�
};
#endif
