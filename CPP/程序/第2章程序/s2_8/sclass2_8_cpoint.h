//�������ļ�
//�ļ�·������s2_8\sclass2_8_cpoint.h 

//����Ԥ������䣺���δ����__SCLASS2_8_CPOINT_H__��������
//ֱ������#endif������
#ifndef __SCLASS2_8_CPOINT_H__ 
#define __SCLASS2_8_CPOINT_H__ 

#include <iostream>                    
using namespace std; 

class CPoint
{
public:    
	CPoint(int x1, int y1);     //�������캯��    
	CPoint(const CPoint &obj);	//�����������캯��
	int GetX();
	int GetY();	
private:
	int x;						//ˮƽ����
	int y;						//��ֱ����
};
#endif
