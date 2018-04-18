// �ļ�·����: translator\sclass_ctranslator.h
#ifndef __SCALSS_CTRANSLATOR_H__					// ���û�ж���__SCALSS_CTRANSLATOR_H__
#define __SCALSS_CTRANSLATOR_H__					// ��ô����__SCALSS_CTRANSLATOR_H__

#include <iostream>               					// ����Ԥ��������
#include <fstream>               					// ����Ԥ��������
#include <string>									// ����Ԥ��������
using namespace std;								// ʹ�������ռ�std 

// ��������
class CTranslator
{
private:
// ���ݳ�Ա:
	ifstream fin;									// �����ļ�
	ofstream fout;									// ����ļ�
	string indent;									// �����հ״�

// ��������:
	void SkipSapces();								// �����հ�(�����ո�,�Ʊ��,���з�)
	bool GetToken(string &token);					// ��ȡ���,���ļ��ѽ���,�򷵻�false,���򷵻�true
	string IntToStr(int i);							// ������iת��Ϊ����Ϊ4�Ĵ� 
	void ForEach();									// ����foreachѭ��

public:
// ���캯��, ���������뷽��:
	CTranslator(const string &infName, const string &outfName);	// ���캯��
	virtual ~CTranslator()							// ��������
	{ 
		fin.close();								// �ر��ļ�
		fout.close(); 								// �ر��ļ�
	}			
	void Run();										// ����������
};

#endif
