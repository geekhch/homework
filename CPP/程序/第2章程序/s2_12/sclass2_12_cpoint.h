//�������ļ�
//�ļ�·������s2_12\sclass2_12_point.h 

//����Ԥ������䣺���δ����__SCLASS2_12_POINT_H__��������
//ֱ������#endif������
#ifndef __SCLASS2_12_POINT_H__ 
#define __SCLASS2_12_POINTE_H__ 

#include <iostream>
using namespace std;

class CPoint 
{ 
public:
	CPoint(){} 
	~CPoint(){} 
	CPoint(float, float);    
	void Move(float, float);  
	//Ϊ�˱���������ʣ����������������ݳ�Ա���ֱ�������ԣ��ᡢ������
	float x;  
	float y;
}; 
#endif
