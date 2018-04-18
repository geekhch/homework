//�������ļ�
//�ļ�����s4_5\sclass4_5_student.h 

//����Ԥ������䣺���δ����__SCLASS4_4_STUDENT_H__��������
//ֱ������#endif����
#ifndef __SCLASS4_5_STUDENT_H__ 
#define __SCLASS4_5_STUDENT_H__ 

#include <iostream>							//����ͷ�ļ���ʹ��iostream��
#include <string>							//����ͷ�ļ���ʹ��string��

using namespace std;						//ʹ��std�����ռ�

//����CPerson��      
class CPerson  
{
public:
	CPerson(int age,						//����
		char sex,							//�Ա�
		string name							//��������
		);
	virtual void Show() const;				//����virtual���Ǹ��ǣ�ȥ����������

protected:
	int m_age;								//����
	char m_sex;								//�Ա�
	string m_name;							//��������
};  

//����CStudent��   
class CStudent : virtual public CPerson		//CPerson����CStudent��������
{
public:
	CStudent(int age,						//����
		char sex,							//�Ա�
		string name,						//��������
		string grade						//�꼶����
		);
	void Show() const;						//��ʾѧ�������䣬�������꼶

protected:
	string m_grade;							//�꼶����
};

//����CClerk(ְԱ)��   
class CClerk : virtual public CPerson		//CPerson����CClerk��������
{
public:
	CClerk(int age,							//����
		char sex,							//�Ա�
		string name,						//��������
		double salary						//����
		);
	void Show() const;						//��ʾְԱ�����䣬�����͹���

protected:
	double m_salary;						//ְԱ����
};

//����COnJobStudent��   
class COnJobStudent : virtual public CStudent, virtual public CClerk	//������࣬��̳� 
{
public:
	COnJobStudent(int age,					//����
		char sex,							//�Ա�
		string name,						//��������
		string grade,						//��ְѧ�����꼶����
		double salary						//��ְѧ���Ĺ���
		);
	void Show() const;						//��ʾ��ְѧ�������䡢�������꼶�͹���					
};

//�������ͨ��������
void Reference(const CPerson &roCP);

#endif   //��������Ԥ����
 



