// �ļ�·����:s7_4\smain7_4.cpp
#include <iostream>               		// ����Ԥ��������
using namespace std;					// ʹ�������ռ�std 

char GetChar(istream &in = cin)			// ��������in�������ո��ȡһ�ַ�
{
	char ch;							// �ַ�����
	
	while (!in.eof()					// δ�����ļ�������
		&& (ch = in.get()) == ' '); 	// ������ַ�Ϊ�ո�	

	return ch;							// �����ַ�
}

int main()								// ������main()
{
	char ch;							// �ַ�����

	cout << "������һ���ַ�:" << endl;	// ������ʾ
	ch = GetChar();						// �����ַ�,�Զ������ո�
	while (ch != '\n' && ch != EOF)		// ch != EOF�ɸ�Ϊ!cin.eof()
	{	
		cout.put(ch);					// ����ַ�
		ch = GetChar();					// �����ַ�,�Զ������ո�
	}
	cout << endl;						// ����
	
	system("PAUSE");            		// ���ÿ⺯��system()�����ϵͳ��ʾ
	return 0;                    		// ����ֵ0, ���ز���ϵͳ
}
