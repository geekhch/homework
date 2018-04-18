//�������ļ�
//�ļ�����s4_7\sclass4_7_CShape.h 

//����Ԥ������䣺���δ����__SCLASS4_7_CSHAPE_H__��������
//ֱ������#endif������
#ifndef __SCLASS4_7_CSHAPE_H__ 
#define __SCLASS4_7_CSHAPE_H__ 

#include <iostream>					//����ͷ�ļ���ʹ��iostream��

using namespace std;				//ʹ��std�����ռ�

//����CShape��      
class CShape  
{
public:
	virtual double CalculateArea() const = 0;	//�������麯��

protected:
	double m_area;					//��״�����
};  

//����CCircle��   
class CCircle : public CShape		//CCircle��̳�CShape�� 
{
public:
	CCircle(double radius);			//Բ�İ뾶
	double CalculateArea() const;	//������Ա����

protected:
	double m_radius;				//Բ�İ뾶
};

//����CRectangle��   
class CRectangle : public CShape	//CRectangle��̳�CShape�� 
{
public:
	CRectangle(double length,		//�����εĳ�
		double width				//�����εĿ�
		);
	double CalculateArea() const;	//������Ա����

protected:
	double m_length;				//�����εĳ�
	double m_width;					//�����εĿ�
};

//����CSquare��   
class CSquare : public CShape		//CSquare��̳�CShape�� 
{
public:
	CSquare(double edge);			//�����εı߳�
	double CalculateArea() const;	//������Ա����

protected:
	double m_edge;					//�����εı߳�
};

void Reference(const CShape &roCS);	//�����������Ϊ�β�

#endif								//��������Ԥ����
 