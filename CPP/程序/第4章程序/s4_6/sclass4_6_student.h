//�������ļ�
//�ļ�����s4_6\sclass4_6_student.h 

//����Ԥ������䣺���δ����__SCLASS4_7_STUDENT_H__��������
//ֱ������#endif������
#ifndef __SCLASS4_6_STUDENT_H__ 
#define __SCLASS4_6_STUDENT_H__ 

#include <iostream>		//����ͷ�ļ���ʹ��iostream��
#include <string>		//����ͷ�ļ�����string��

using namespace std;	//ʹ��std�����ռ�

//����CPerson��      
class CPerson  
{
public:
	 virtual ~CPerson();	//�����virtual������Ϊ�麯����������delete���ٶ���ʱ�����
protected:
	int m_age;				//����
	string m_name;			//��������
};  

//����CStudent��   
class CStudent : public CPerson		//CStudent��̳���CPerson�� 
{
public:
	~CStudent();					//���������������Ҳ��ü���virtual

protected:
	string m_grade;					//�꼶����
};

#endif   //��������Ԥ����
 