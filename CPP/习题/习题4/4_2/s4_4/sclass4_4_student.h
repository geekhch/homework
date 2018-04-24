//�������ļ�
//�ļ�����s4_4\sclass4_4_student.h 

//����Ԥ������䣺���δ����__SCLASS4_4_STUDENT_H__��������
//ֱ������#endif����
#ifndef __SCLASS4_4_STUDENT_H__ 
#define __SCLASS4_4_STUDENT_H__ 

#include <iostream>							//����ͷ�ļ���ʹ��iostream��
#include <string>							//����ͷ�ļ���ʹ��string��

using namespace std;						//ʹ��std�����ռ�

//����CPerson��      
class CPerson  
{
public:
	CPerson(int age,						//����
		string name							//��������
		);
	// �뽫Show()�����趨Ϊ�麯���ͷ��麯���ֱ����г���
	virtual void Show(int age) const;		//��ʾ�˵����䣬����
	void Show() const;						//��ʾ�˵�����


protected:
	int m_age;								//����
	string m_name;							//��������
};  

//����CStudent��   
class CStudent : public CPerson				//CStudent��̳�CPerson�� 
{
public:
	CStudent(int age,						//����
		string name,						//��������
		string grade						//�꼶����
		);
	void Show(int age) const;				//��ʾѧ�������䣬�������꼶

protected:
	string m_grade;							//�꼶����
};

//CPerson���캯��
CPerson::CPerson(int age,	//����
				 string name //��������
				 ) : m_age(age), m_name(name)
{
}

//��ʾ�˵����䣬����
void CPerson::Show(int age) const
{
	cout << "CPerson::Show(age):" << m_age << ",name:" << m_name << "." << endl;
}

//��ʾ�˵�����
void CPerson::Show() const
{
	cout << "CPerson::Show():"
		 << "name:" << m_name << "." << endl;
}

//CStudent���캯��
CStudent::CStudent(int age,		//����
				   string name, //��������
				   string grade //�꼶����
				   ) : CPerson(age, name), m_grade(grade)
{
}

//��ʾѧ�������䣬�������꼶
void CStudent::Show(int age) const
{
	cout << "CStudent::Show(age):" << m_age << ",name:" << m_name
		 << ",grade:" << m_grade << "." << endl;
}
#endif   //��������Ԥ����
 



