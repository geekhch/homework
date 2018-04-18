//���ʵ���ļ�
//�ļ�����s4_7\sclass4_7_CShape.cpp

#include "sclass4_7_CShape.h"		//����������ͷ�ļ�

//CCircle���캯��
CCircle::CCircle(double radius				//Բ�İ뾶
				 ): CShape( ), m_radius(radius){}	//���û����Ĭ�Ϲ��캯��    

//����Բ�����
double CCircle::CalculateArea( ) const
{
	cout << "CCircle::" << 2*3.14*m_radius*m_radius << "."<< endl;
	return 2*3.14*m_radius*m_radius;
}

//CRectangle���캯��
CRectangle::CRectangle(double length,				//�����εĳ�
		double width								//�����εĿ�
		): CShape( ), m_length(length), m_width(width){} //���û����Ĭ�Ϲ��캯��  

//���㳤���ε����
double CRectangle::CalculateArea( ) const
{
	cout << "CRectangle::" << m_length*m_width << "."<< endl;
	return m_length*m_width;
}

//CSquare���캯��
CSquare::CSquare(double edge					//�����εı߳�
				 ): CShape( ), m_edge(edge){}				//���û����Ĭ�Ϲ��캯��     

//���������ε����
double CSquare::CalculateArea( ) const
{
	cout << "CSquare::" << m_edge*m_edge << "."<< endl;
	return m_edge*m_edge;
}

//�������ò���
void Reference(const CShape &roCS)	//�����������Ϊ�β�,���ڲ����޸����ö���Ӧʹ��const  
{
	roCS.CalculateArea();  
}