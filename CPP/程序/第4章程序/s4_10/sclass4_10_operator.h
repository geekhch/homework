//�������ļ�:��COperator�������������������
//�ļ�����s4_10\sclass4_10_operator.h 

//����Ԥ������䣺���δ����__SCLASS4_10_OPERATOR_H__��������
//ֱ������#endif����
#ifndef __SCLASS4_10_OPERATOR_H__ 
#define __SCLASS4_10_OPERATOR_H__ 

#include <iostream>  //����ͷ�ļ���ʹ��iostream��

using namespace std; //ʹ��std�����ռ�

//�����������
class COperator
{
public:
 	COperator(int b=0);						//���캯��
 	
  	int operator++(int i);				//���غ�׺++
  	int operator++();					//����ǰ׺++
 	int operator()();					//���غ�������������ܣ�ȡm_v��ֵ
	
	COperator operator+(const COperator &ob);	//�������������:����+����

	bool operator>(const COperator &ob);		//���رȽ������:����>����
	bool operator<=(const COperator &ob);		//���رȽ������:����<=����

public:
	int m_v;
};

#endif   //��������Ԥ����

 



