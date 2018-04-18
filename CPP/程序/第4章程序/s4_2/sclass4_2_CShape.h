//�������ļ�
//�ļ�����s4_2\sclass4_2_CShape.h 

//����Ԥ������䣺���δ����__SCLASS4_2_CSHAPE_H__��������
//ֱ������#endif������
#ifndef __SCLASS4_2_CSHAPE_H__ 
#define __SCLASS4_2_CSHAPE_H__ 

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
	void Show( ) const;				//��ʾ��������
	//void Output( ) const;			//������
	//double CalculateArea( );		//�������

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
	//void Output( ) const;			//���Զ�����
	//double CalculateArea( );		//����Բ�����

protected:
	double m_radius;					//Բ�İ뾶
};

#endif								//��������Ԥ����
 