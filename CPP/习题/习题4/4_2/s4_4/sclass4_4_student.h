//类声明文件
//文件名：s4_4\sclass4_4_student.h 

//编译预处理语句：如果未定义__SCLASS4_4_STUDENT_H__则定义它，
//直到遇到#endif结束
#ifndef __SCLASS4_4_STUDENT_H__ 
#define __SCLASS4_4_STUDENT_H__ 

#include <iostream>							//包含头文件。使用iostream库
#include <string>							//包含头文件。使用string库

using namespace std;						//使用std命名空间

//声明CPerson类      
class CPerson  
{
public:
	CPerson(int age,						//年龄
		string name							//姓名对象
		);
	// 请将Show()函数设定为虚函数和非虚函数分别运行程序
	virtual void Show(int age) const;		//显示人的年龄，姓名
	void Show() const;						//显示人的姓名


protected:
	int m_age;								//年龄
	string m_name;							//姓名对象
};  

//声明CStudent类   
class CStudent : public CPerson				//CStudent类继承CPerson类 
{
public:
	CStudent(int age,						//年龄
		string name,						//姓名对象
		string grade						//年级对象
		);
	void Show(int age) const;				//显示学生的年龄，姓名和年级

protected:
	string m_grade;							//年级对象
};

//CPerson构造函数
CPerson::CPerson(int age,	//年龄
				 string name //姓名对象
				 ) : m_age(age), m_name(name)
{
}

//显示人的年龄，姓名
void CPerson::Show(int age) const
{
	cout << "CPerson::Show(age):" << m_age << ",name:" << m_name << "." << endl;
}

//显示人的姓名
void CPerson::Show() const
{
	cout << "CPerson::Show():"
		 << "name:" << m_name << "." << endl;
}

//CStudent构造函数
CStudent::CStudent(int age,		//年龄
				   string name, //姓名对象
				   string grade //年级对象
				   ) : CPerson(age, name), m_grade(grade)
{
}

//显示学生的年龄，姓名和年级
void CStudent::Show(int age) const
{
	cout << "CStudent::Show(age):" << m_age << ",name:" << m_name
		 << ",grade:" << m_grade << "." << endl;
}
#endif   //结束编译预处理
 



