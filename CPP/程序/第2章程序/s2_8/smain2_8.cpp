// �ļ�·����: s2_8\smain 2_8.cpp
#include "sclass2_8_cpoint.h"
int main()
{
	CPoint a(20, 50);			//ϵͳ���ù��캯����������һ������Ϊ(20,50)�ĵ�a
	CPoint b(a);				//ϵͳ���ÿ������캯�������õ�a��¡��b
	CPoint c = a;				//ϵͳ���ÿ������캯�������õ�a��¡��c
	cout << "a(" << a.GetX() << "," << a.GetY() << ")" << endl;
	cout << "b(" << b.GetX() << "," << b.GetY() << ")" << endl;
	cout << "c(" << c.GetX() << "," << c.GetY() << ")" << endl;
	return 0;
}
