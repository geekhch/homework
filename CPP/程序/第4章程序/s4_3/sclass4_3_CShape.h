//�������ļ�
//�ļ�����s4_3\sclass4_3_CShape.h 

//����Ԥ������䣺���δ����__SCLASS4_3_CSHAPE_H__��������
//ֱ������#endif������
#ifndef __SCLASS4_3_CSHAPE_H__ 
#define __SCLASS4_3_CSHAPE_H__ 

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
	virtual void Show( ) const;		//��ӹؼ���virtual��ʾ�麯��

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

//����CRectangle��   
class CRectangle : public CShape	//CRectangle��̳�CShape�� 
{
public:
	CRectangle(double x,			//�����ε���������
		double y,					//�����ε���������
		double z,					//�����ε���������
		double length,				//�����εĳ�
		double width				//�����εĿ�
		);
	void Show( ) const;				//��ʾ�����ε��������꼰�䳤�Ϳ�

protected:
	double m_length;				//�����εĳ�
	double m_width;					//�����εĿ�
};

//����CSquare��   
class CSquare : public CShape		//CSquare��̳�CShape�� 
{
public:
	CSquare(double x,				//�����ε���������
		double y,					//�����ε���������
		double z,					//�����ε���������
		double edge					//�����εı߳�
		);
	void Show( ) const;				//��ʾ�����ε���������ͱ߳�

protected:
	double m_edge;					//�����εı߳�
};

#endif								//��������Ԥ����
 