//�������ļ�
//�ļ�����ch4_1\sclass4_1_CShape.h 

//����Ԥ������䣺���δ����__SCLASS4_1_CSHAPE_H__��������
//ֱ������#endif������
#ifndef __SCLASS4_1_CSHAPE_H__ 
#define __SCLASS4_1_CSHAPE_H__ 

#include <iostream>					//����ͷ�ļ���ʹ��iostream��

using namespace std;				//ʹ��std�����ռ�

//����CShape��      
class CShape  
{
public:
	CShape(double x,				//��������
		double y,					//��������
		double z					//��������
		);
	void Show() const;				//��ʾ��������

protected:
	double m_x;						//��������
	double m_y;						//��������
	double m_z;						//��������
	double m_area;					//��״�����
};  

//����CCircle��   
class CCircle : public CShape		//CCircle��̳�CShape�� 
{
public:
	CCircle(double x,				//Բ����������
		double y,					//Բ����������
		double z,					//Բ����������
		double radius				//Բ�İ뾶
		);
	void Show( ) const;				//��ʾԲ����������Ͱ뾶

protected:
	double m_radius;				//Բ�İ뾶
};

#endif								//��������Ԥ����
 