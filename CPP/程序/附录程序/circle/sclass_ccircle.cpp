// �ļ�·����: circle\sclass_ccircle.cpp
#include "sclass_ccircle.h"			// ����Բ�����ͷ�ļ�

// ��֪�뾶dRadius����Բ
CCircle::CCircle(double r)
{
	radius = r;						// ��ʼ��԰�뾶
}

// ����Բ�뾶
void CCircle::SetRadius(double r)
{
	radius = r;						// ����Բ�뾶
}

// ����Բ�뾶
double CCircle::GetRadius()
{
	return radius;					// ����Բ�뾶
}

// ��Բ���
double CCircle::GetArea()
{
	double area;					// �������
	area = PI * radius * radius;	// ����Բ���
	return area;					// ����Բ���
}
