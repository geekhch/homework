//���ʵ���ļ�
//�ļ�����s4_5\sclass4_5_student.cpp

#include "sclass4_5_student.h"  //����������ͷ�ļ�

//CPerson���캯��  
CPerson::CPerson(int age,			//����
		char sex,					//�Ա�
		string name					//��������
		): m_age(age), m_sex(sex), m_name(name){}

//��ʾ�˵����䣬����
void CPerson::Show() const  
{
	cout << "CPerson::age:" << m_age << ",name:" << m_name << "."<< endl;  
}

//CStudent���캯��  
CStudent::CStudent(int age,			//����
		char sex,					//�Ա�
		string name,				//��������
		string grade				//�꼶����
		): CPerson(age, sex, name), m_grade(grade){}

//��ʾѧ�������䣬�������꼶
void CStudent::Show( ) const		
{
	cout << "CStudent::age:" << m_age << ",name:" << m_name 
		<< ",grade:" << m_grade << "." << endl;  
}

//CClerk���캯��  
CClerk::CClerk(int age,				//����
		char sex,					//�Ա�
		string name,				//��������
		double salary				//����
		): CPerson(age, sex, name), m_salary(salary){}

//��ʾְԱ�����䣬�����͹���
void CClerk::Show( ) const		
{
	cout << "CClerk::age:" << m_age << ",name:" << m_name 
		<< ",salary:" << m_salary << "." << endl;  
}  

//COnJobStudent���캯��  
COnJobStudent::COnJobStudent(int age,	//����
		char sex,					//�Ա�
		string name,				//��������
		string grade,				//�꼶����
		double salary				//����
		): CStudent(age,sex,name,grade), CClerk(age,sex,name,salary), CPerson(age, sex, name){}

//��ʾְԱ�����䣬�������꼶�͹���
void COnJobStudent::Show( ) const		
{
	cout << "COnJobStudent::age:" << m_age << ",name:" << m_name << ",grade:" 
		<< m_grade << ",salary:" << m_salary << "." << endl;  
}

//�������õ�����
void Reference(const CPerson &roCP)	//�����������Ϊ�β�  
{
	roCP.Show();  
}