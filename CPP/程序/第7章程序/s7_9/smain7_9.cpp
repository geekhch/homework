// �ļ�·����:s7_9\smain7_9.cpp
#include <iostream>               	// ����Ԥ��������
#include <fstream>               	// ����Ԥ��������
using namespace std;				// ʹ�������ռ�std 

int main()							// ������main()
{
	char s[318], fName[20];			// �ַ���
	ifstream f;						// �ļ�������
	
	cout << "�������ļ���:";
	cin >> fName;					// �����ļ���
	f.open(fName);					// ���ļ�
	if (f.fail())	
	{	// ���ļ�ʧ��
		cout << "���ļ�ʧ��!" << endl;
		exit(1);					// �˳�����
	}
	f.getline(s, 318);				// ���ļ�������һ���ַ�
	while (!f.eof())
	{	// �ļ�ĩ����
		cout << s << endl;			// ���һ���ַ�
		f.getline(s, 318);			// ���ļ�������һ���ַ�
	}
	f.close();						// �ر��ļ�
	
	system("PAUSE");            	// ���ÿ⺯��system()�����ϵͳ��ʾ
	return 0;                    	// ����ֵ0, ���ز���ϵͳ
}