// �ļ���:smain.cpp
#include <iostream>               				// ����Ԥ��������
using namespace std;							// ʹ�������ռ�std 
#include "sclass_ccircle.h"						// Բ���๹��ͷ�ļ�

// ��֪�뾶��ʾԲ���
int main()										// ������main()
{
	double r, area;								// �뾶�����
	CCircle c;									// Բ����
	
	cout << "������Բ�뾶:";					// ������ʾ
	cin >> r;									// ����Բ�뾶
	c.SetRadius(r);								// ����Բ�뾶
	area = c.GetArea();							// ��Բ���
   	cout << "Բ�����" << area << " ." << endl;	// ��ʾԲ���

	return 0;									// ����ֵ0, ���ز���ϵͳ
}
