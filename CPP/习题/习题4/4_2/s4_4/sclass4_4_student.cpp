//���ʵ���ļ�
//�ļ�����s4_4\sclass4_4_student.cpp

#include "sclass4_4_student.h"  //����������ͷ�ļ�


//CPerson���캯��  
CPerson::CPerson(int age,			//����
		string name					//��������
		): m_age(age), m_name(name) {}

//��ʾ�˵����䣬����
void CPerson::Show(int age) const  
{
	cout << "CPerson::Show(age):" << m_age << ",name:" << m_name << "."<< endl;  
}


//��ʾ�˵�����
void CPerson::Show() const  
{
	cout << "CPerson::Show():" << "name:" << m_name << "."<< endl;  
}


//CStudent���캯��  
CStudent::CStudent(int age,			//����
		string name,				//��������
		string grade				//�꼶����
		): CPerson(age, name), m_grade(grade){}

//��ʾѧ�������䣬�������꼶
void CStudent::Show(int age) const		
{
	cout << "CStudent::Show(age):" << m_age << ",name:" << m_name 
		<< ",grade:" << m_grade << "." << endl;  
}