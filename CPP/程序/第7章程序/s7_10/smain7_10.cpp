// �ļ�·����:s7_10\smain7_10.cpp
#include <iostream>               		// ����Ԥ��������
#include <fstream>               		// ����Ԥ��������
using namespace std;					// ʹ�������ռ�std 

int main()								// ������main()
{
	int a[] = {1, 5, 8, 10, 18, 98}, n = 6, x;	// �������������ͱ���
	fstream f;							// �����ļ�����
	
	f.open("test.dat", ios::out | ios::binary);	// �������ʽ���ļ�
	if (f.fail())	
	{	// ���ļ�ʧ��
		cout << "���ļ�ʧ��!" << endl;
		exit(1);						// �˳�����
	}
	for (int i = 0; i < n; i++)
		f.write((char *)&a[i], sizeof(int));	// д���ݵ��ļ���
	f.close();							// �ر��ļ�

	f.open("test.dat", ios::in | ios::binary);	// �����뷽ʽ���ļ�
	if (f.fail())	
	{	// ���ļ�ʧ��
		cout << "���ļ�ʧ��!" << endl;
		exit(2);						// �˳�����
	}
	f.read((char *)&x, sizeof(int));	// ���ļ��ж������ݵ�x
	while (!f.eof())
	{
		cout << x << " ";				// ���x����ʾ��
		f.read((char *)&x, sizeof(int));	// ���ļ��ж������ݵ�x
	}
	cout << endl;						// ����
	f.close();							// �ر��ļ�
	
	system("PAUSE");            		// ���ÿ⺯��system()�����ϵͳ��ʾ
	return 0;                    		// ����ֵ0, ���ز���ϵͳ
}
