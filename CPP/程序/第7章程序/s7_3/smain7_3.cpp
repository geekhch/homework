// �ļ�·����:s7_3\smain7_3.cpp
#include <iostream>               		// ����Ԥ��������
using namespace std;					// ʹ�������ռ�std 

int main()								// ������main()
{
	char s[256];						// �ַ���

	cout << "����һ���ַ�:" << endl;	// ������ʾ
	cin.getline(s, 8);					// ����һ���ַ�
	cout << s << endl;					// ���һ���ַ�
	
	system("PAUSE");            		// ���ÿ⺯��system()�����ϵͳ��ʾ
	return 0;                    		// ����ֵ0, ���ز���ϵͳ
}
