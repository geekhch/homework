// �ļ�·����:s7_1\smain7_1.cpp
#include <iostream>               	// ����Ԥ��������
using namespace std;				// ʹ�������ռ�std 

int main()							// ������main()
{
	char s[] = "Hello, world!";		// �����ַ���

	for (int i = 0; i < strlen(s); i++)	
		cout.put(s[i]);				// �����i+1���ַ�
	cout << endl;					// ����
	
	system("PAUSE");            	// ���ÿ⺯��system()�����ϵͳ��ʾ
	return 0;                    	// ����ֵ0, ���ز���ϵͳ
}
