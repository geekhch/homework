// �ļ�·����:s7_6\smain7_6.cpp
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
	double x;							// ˫����ʵ�ͱ���

	ch = GetChar();						// �����ո�����һ���ַ�
	while (ch != '\n' && ch != EOF)
	{
		if (ch >= '0' && ch <= '9')
		{	// ��ʵ���Ŀ�ʼ�ַ�
			cin.putback(ch);			// ��ch���͵�����������cin��
			cin >> x;					// ����˫����ʵ��x
			cout << x << " ";			// ���˫����ʵ��x
		}
		else
		{	// �Ƿ��ַ�
			cout << "���ַǷ��ַ�!" << endl;
			exit(1);					// �˳�����
		}
		ch = GetChar();					// �����ո�����һ���ַ�
	}
	cout << endl;						// ����
	
	system("PAUSE");            		// ���ÿ⺯��system()�����ϵͳ��ʾ
	return 0;                    		// ����ֵ0, ���ز���ϵͳ
}

