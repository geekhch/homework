// �ļ�·����:s7_2\smain7_2.cpp
#include <iostream>               		// ����Ԥ��������
using namespace std;					// ʹ�������ռ�std 

int main()								// ������main()
{
	char ch;							// �����ַ�����

	cout << "����һ���ַ�:" << endl;	// ������ʾ
	ch = cin.get();						// �����ַ�
	while (ch != '\n')
	{	
		cout.put(ch);					// ����ַ�
		ch = cin.get();					// �����ַ�
	}
	cout << endl;						// ����
	
	system("PAUSE");            		// ���ÿ⺯��system()�����ϵͳ��ʾ
	return 0;                    		// ����ֵ0, ���ز���ϵͳ
}
