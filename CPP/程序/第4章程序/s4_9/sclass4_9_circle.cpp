//���ʵ���ļ�
//�ļ�����s4_9\sclass4_9_circle.cpp

#include "sclass4_9_circle.h"    //����������ͷ�ļ�

//��Ա����Reference()��ʵ��
void CCircle::Reference()  
{
	cout << "���ǳ�Ա����." << endl;
}

//ȫ�����غ���Reference()��ʵ��
void Reference()  
{
	cout << "����ȫ�����غ���Reference()." << endl;
}

//ȫ�����غ���Reference(CCircle &roCC)��ʵ��
void Reference(CCircle &roCC)  
{
	cout << "����ȫ�����غ���Reference(CCircle &roCC)." << endl;
}