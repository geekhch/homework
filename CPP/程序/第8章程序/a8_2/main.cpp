// �ļ�·����:a8_2\main.cpp
#include <iostream>		// ����Ԥ��������
using namespace std;	// ʹ�������ռ�std 

namespace MyName		// �����ռ�MyName
{ 
	int x = 10;			// �����ռ�MyName�еı���x
}

namespace				// ���������ռ�
{ 
	int x = 20;			// ���������ռ��еı���x
}

int main()				// ������main()
{
	cout << "�����ռ�MyName�еı���x:" << MyName::x << endl;
	cout << "���������ռ��еı���x:" << x << endl;
	
	system("PAUSE");	// ���ϵͳ��ʾ�����ز���ϵͳ
	return 0;        	// ����ֵ0, ���ز���ϵͳ
}
