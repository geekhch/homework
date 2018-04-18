//���ʵ���ļ�
//�ļ�����s4_2\sclass4_2_CShape.cpp

#include "sclass4_2_CShape.h"		//����������ͷ�ļ�

//CShape���캯��  
CShape::CShape(double x,			//��������
		double y,					//��������
		double z					//��������
		): m_x(x), m_y(y), m_z(z)
{
	;
}

//��ʾ��������
void CShape::Show( ) const
{
	cout << "x=" << m_x << ",y=" << m_y << ",z=" << m_z << "."<< endl;  
}


//CCircle���캯��
CCircle::CCircle(double x,			//Բ����������
		double y,					//Բ����������
		double z,					//Բ����������
		double radius				//Բ�İ뾶
		) : CShape(x, y, z), m_radius(radius)    
{
	;
}

//��ʾԲ�����������Բ�İ뾶
void CCircle::Show( ) const
{
	cout << "x=" << m_x << ",y=" << m_y << ",z=" << m_z 
		<< ",radius=" << m_radius <<"."<< endl;  
}
