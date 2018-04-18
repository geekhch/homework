// �ļ�·����: circle\sclass_ccircle.h
#ifndef __SCLASS_CCIRCLE_H__					// ���û�ж���__SCLASS_CCIRCLE_H__
#define __SCLASS_CCIRCLE_H__					// ��ô����__SCLASS_CCIRCLE_H__

const int DEFAULT_RADIUS = 10;					// ȱʡԲ�뾶
const double PI = 3.1415926;					// Բ���ʳ���

class CCircle
{
public:
	CCircle(double r = DEFAULT_RADIUS);			// ���캯��
	void SetRadius(double r = DEFAULT_RADIUS);	// ����Բ�뾶
	double GetRadius();							// ����Բ�뾶
	double GetArea();							// ������Բ���

private:
	double radius;								// Բ�뾶		
};

#endif
