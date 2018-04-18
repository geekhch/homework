//���ʵ���ļ�
//�ļ�����s4_3\sclass4_3_CShape.cpp

#include "sclass4_3_CShape.h"		//����������ͷ�ļ�

//CShape���캯��  
CShape::CShape(double x,			//��������
		double y,					//��������
		double z					//��������
		): m_x(x), m_y(y), m_z(z)	//��ʼ���б�
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
		) : CShape(x, y, z), m_radius(radius)	//���û���Ĺ��캯��    
{
	;
}

//��ʾԲ�����������Բ�İ뾶
void CCircle::Show( ) const
{
	cout << "x=" << m_x << ",y=" << m_y << ",z=" << m_z 
		<< ",radius=" << m_radius <<"."<< endl;  
}

//CRectangle���캯��
CRectangle::CRectangle(double x,	//�����ε���������
		double y,					//�����ε���������
		double z,					//�����ε���������
		double length,				//�����εĳ�
		double width				//�����εĿ�
		) : CShape(x, y, z), m_length(length), m_width(width) //���û���Ĺ��캯��  
{
	;
}

//��ʾ�����ε��������꼰�䳤�Ϳ�
void CRectangle::Show( ) const
{
	cout << "x=" << m_x << ",y=" << m_y << ",z=" << m_z 
		<< ",length=" << m_length << ",width=" << m_width << "."<< endl;  
}

//CSquare���캯��
CSquare::CSquare(double x,			//�����ε���������
		double y,					//�����ε���������
		double z,					//�����ε���������
		double edge					//�����εı߳�
		) : CShape(x, y, z), m_edge(edge)	//���û���Ĺ��캯��     
{
	;
}

//��ʾ�����ε���������ͱ߳�
void CSquare::Show( ) const
{
	cout << "x=" << m_x << ",y=" << m_y << ",z=" << m_z 
		<< ",edge=" << m_edge <<"."<< endl;  
}