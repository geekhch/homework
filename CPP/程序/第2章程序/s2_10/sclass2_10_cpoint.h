//�������ļ�
//�ļ�·������s2_10\sclass2_10_cpoint.h

//����Ԥ������䣺���δ����__SCLASS2_10_CPOINT_H__��������
//ֱ������#endif������
#ifndef __SCLASS2_10_CPOINT_H__ 
#define __SCLASS2_10_CPOINT_H__ 

#include <iostream>
using namespace std;

class CPoint 
{ 
public:
	CPoint(){} 
	~CPoint(){} 
	CPoint(float x1, float y1);
	void Move(float x1, float y1);
   
	//Ϊ�˱���������ʣ����������������ݳ�Ա���ֱ�������ԣ��ᡢ������
	float x;  
	float y;
};
#endif
