// �ļ�·����: translator\smain.cpp 
#include "sclass_ctranslator.h"				// ������
#include <iostream>               			// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 

int main()
{
	string infName, outfName;				// �ļ���
	char ch;								// �ַ�����

	cout << "�������ļ���(ȱʡ: experiment.exp):";
	if ((ch = cin.get()) == '\n') 
	{
		infName = "experiment.exp";			// ֱ������س�����ʾȱʡ�ļ���
	}
	else 
	{
		cin.putback(ch);					// �������ַ�ch����������
		cin >> infName;						// �����ļ���
	}

	cout << "������ļ���(ȱʡ: experiment.cpp):";
	if ((ch = cin.get()) == '\n') 
	{
		outfName = "experiment.cpp";		// ֱ������س�����ʾȱʡ�ļ���
	}
	else 
	{
		cin.putback(ch);					// �������ַ�ch����������
		cin >> outfName;					// �����ļ���
	}

	CTranslator objTrans(infName, outfName);// ����������
	objTrans.Run();							// ����������

	system("PAUSE");            			// ���ÿ⺯��system()�����ϵͳ��ʾ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}

