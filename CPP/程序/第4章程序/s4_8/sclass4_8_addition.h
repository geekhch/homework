//�������ļ�
//�ļ�����s4_8\sclass4_8_addition.h 

//����Ԥ������䣺���δ����__SCLASS4_8_ADDITION_H__��������
//ֱ������#endif����
#ifndef __SCLASS4_8_ADDITION_H__ 
#define __SCLASS4_8_ADDITION_H__ 

#include <iostream>		//����ͷ�ļ�,ʹ��iostream��
#include <string>		//����ͷ�ļ�,ʹ��string��

using namespace std;	//ʹ��std�����ռ�

//����CAddition��     
class CAddition  
{
public:
	int Add(int a, int b);				//�����������
	string Add(string s1, string s2);	//�����ַ����������
	int Add(double d1, double d2);		//����˫���ȸ��������
	//double Add(double d1, double d2);	//�������أ�����һ��������������ֵ���Ͳ�ͬ
};  

#endif   //��������Ԥ���� 