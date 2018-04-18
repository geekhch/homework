//类的实现文件
//文件名：s4_5\sclass4_5_student.cpp

#include "sclass4_5_student.h"  //包含类声明头文件

//CPerson构造函数  
CPerson::CPerson(int age,			//年龄
		char sex,					//性别
		string name					//姓名对象
		): m_age(age), m_sex(sex), m_name(name){}

//显示人的年龄，姓名
void CPerson::Show() const  
{
	cout << "CPerson::age:" << m_age << ",name:" << m_name << "."<< endl;  
}

//CStudent构造函数  
CStudent::CStudent(int age,			//年龄
		char sex,					//性别
		string name,				//姓名对象
		string grade				//年级对象
		): CPerson(age, sex, name), m_grade(grade){}

//显示学生的年龄，姓名和年级
void CStudent::Show( ) const		
{
	cout << "CStudent::age:" << m_age << ",name:" << m_name 
		<< ",grade:" << m_grade << "." << endl;  
}

//CClerk构造函数  
CClerk::CClerk(int age,				//年龄
		char sex,					//性别
		string name,				//姓名对象
		double salary				//工资
		): CPerson(age, sex, name), m_salary(salary){}

//显示职员的年龄，姓名和工资
void CClerk::Show( ) const		
{
	cout << "CClerk::age:" << m_age << ",name:" << m_name 
		<< ",salary:" << m_salary << "." << endl;  
}  

//COnJobStudent构造函数  
COnJobStudent::COnJobStudent(int age,	//年龄
		char sex,					//性别
		string name,				//姓名对象
		string grade,				//年级对象
		double salary				//工资
		): CStudent(age,sex,name,grade), CClerk(age,sex,name,salary), CPerson(age, sex, name){}

//显示职员的年龄，姓名、年级和工资
void COnJobStudent::Show( ) const		
{
	cout << "COnJobStudent::age:" << m_age << ",name:" << m_name << ",grade:" 
		<< m_grade << ",salary:" << m_salary << "." << endl;  
}

//测试引用的作用
void Reference(const CPerson &roCP)	//基类的引用作为形参  
{
	roCP.Show();  
}