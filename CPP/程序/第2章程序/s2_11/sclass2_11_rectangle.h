//�������ļ�
//�ļ�·������s2_11\sclass2_11_rectangle.h 

//����Ԥ������䣺���δ����__SCLASS2_11_RECTANGLE_H__��������
//ֱ������#endif������
#ifndef __SCLASS2_11_RECTANGLE_H__ 
#define __SCLASS2_11_RECTANGLE_H__ 

#include <iostream>
using namespace std;

class Rectangle 
{ 
public:
	Rectangle();   	 
	Rectangle(double, double);  
	~ Rectangle(){}; 	  
	void SetSize(double, double); 	
	double GetLength();    
	double GetWidth();
	double GetArea();    	
	void Print();		
private:
	double length;  
	double width;
};
#endif
