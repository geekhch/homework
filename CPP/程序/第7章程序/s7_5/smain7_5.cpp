// �ļ�·����:s7_5\smain7_5.cpp
#include <iostream>               		// ����Ԥ��������
using namespace std;					// ʹ�������ռ�std 

char GetChar(istream &in = cin)			// ��������in�������ո��ȡһ�ַ�
{
	char ch;							// �ַ�����
	
	while (in.peek() != EOF				// δ�����ļ�������
		&& (ch = in.get()) == ' ');		// ������ַ�Ϊ�ո�
	
	return ch;							// �����ַ�
}

int main()								// ������main()
{
	char ch;							// �ַ�����
	
	cout << "������һ���ַ�:" << endl;	// ������ʾ
	ch = GetChar();						// �����ַ�,�Զ������ո�
	while (ch != '\n' && ch != EOF)
	{	
		cout.put(ch);					// ����ַ�
		ch = GetChar();					// �����ַ�,�Զ������ո�
	}
	cout << endl;						// ����
	
	system("PAUSE");            		// ���ÿ⺯��system()�����ϵͳ��ʾ
	return 0;                    		// ����ֵ0, ���ز���ϵͳ
}
