// �ļ�·����:s7_8\smain7_8.cpp
#include <iostream>               	// ����Ԥ��������
#include <fstream>               	// ����Ԥ��������
using namespace std;				// ʹ�������ռ�std 

int main()							// ������main()
{
	char ch;						// �ַ����� 
	ofstream outFile("test.txt");	// ��������ļ�����,Ĭ���������ʽ���ļ�
	if (outFile.fail())	
	{	// ���ļ�ʧ��
		cout << "���ļ�ʧ��!" << endl;
		exit(1);					// �˳�����
	}
	cout << "����һ������:" << endl;
	ch = cin.get();					// ����һ���ַ�ch
	while (ch != '\n')
	{
		outFile.put(ch);			// ��ch������ļ���
		ch = cin.get();				// ����һ���ַ�ch
	}
	outFile.close();				// �ر��ļ�

	int letters = 0;				// ��ĸ����
	ifstream inFile("test.txt");	// ���������ļ�����,Ĭ�������뷽ʽ���ļ�
	if (inFile.fail())	
	{	// ���ļ�ʧ��
		cout << "���ļ�ʧ��!" << endl;
		exit(2);					// �˳�����
	}
	ch = inFile.get();				// ���ļ�������һ���ַ�ch
	while (!inFile.eof())
	{	// �ļ�ĩ����
		if (ch >= 'a' && ch <= 'z')
			letters++;				// ��Ӣ��Сд��ĸ���м���
		ch = inFile.get();			// ���ļ�������һ���ַ�ch
	}
	cout << "����Ӣ��Сд��ĸ" << letters << "��" << endl;
	inFile.close();					// �ر��ļ�
	
	system("PAUSE");            	// ���ÿ⺯��system()�����ϵͳ��ʾ
	return 0;                    	// ����ֵ0, ���ز���ϵͳ
}


