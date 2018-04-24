//类的实现文件
//文件名：s4_4\sclass4_4_student.cpp

#include "sclass4_4_student.h"  //包含类声明头文件


//CPerson构造函数  
CPerson::CPerson(int age,			//年龄
		string name					//姓名对象
		): m_age(age), m_name(name) {}

//显示人的年龄，姓名
void CPerson::Show(int age) const  
{
	cout << "CPerson::Show(age):" << m_age << ",name:" << m_name << "."<< endl;  
}


//显示人的姓名
void CPerson::Show() const  
{
	cout << "CPerson::Show():" << "name:" << m_name << "."<< endl;  
}


//CStudent构造函数  
CStudent::CStudent(int age,			//年龄
		string name,				//姓名对象
		string grade				//年级对象
		): CPerson(age, name), m_grade(grade){}

//显示学生的年龄，姓名和年级
void CStudent::Show(int age) const		
{
	cout << "CStudent::Show(age):" << m_age << ",name:" << m_name 
		<< ",grade:" << m_grade << "." << endl;  
}