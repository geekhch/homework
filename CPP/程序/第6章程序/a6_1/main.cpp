// �ļ�·����:a6_1\main.cpp
#include <iostream>               				// ����Ԥ��������
#include <string>               				// ����Ԥ��������
using namespace std;							// ʹ�������ռ�std 

int main()										// ������main()
{
   	string s("How are");						// ����C��񴮹��촮����
	s = s + " you?";							// ���ַ���������" you?"
 	cout << s << endl;							// ���s
	for (int i = s.size() - 1; i >= 0; i--)
	{	// ������������ַ�
		cout << s[i];							// ����ַ�s[i]
	}
	cout << endl;								// ����

	system("PAUSE");            				// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    				// ����ֵ0, ���ز���ϵͳ
}
