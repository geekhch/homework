//���ʵ���ļ�
//�ļ�����s4_8\sclass4_8_addition.cpp

#include "sclass4_8_addition.h"    //����������ͷ�ļ�

//Add(int a, int b)������ʵ��
int CAddition::Add(int a, int b)  
{
	int c = (a+b)%250;
	cout << "���������ĺͶ�250ȡ��:=" << c << endl;
	return c;
}

//Add(string s1, string s2)������ʵ��
string CAddition::Add(string s1, string s2)  
{
	string s = s1+s2;			
	cout << "��Ի:" << s << endl;
	return s;
}  

//Add(double d1, double d2)������ʵ��
int CAddition::Add(double d1, double d2)  
{
	int d = d1+d2;				// �Զ�����ת��
	cout << "����˫���ȸ�����֮��ȡ��:=" << d << endl;
	return d;
}  
