//类声明文件
//文件名：s4_5\sclass4_5_student.h 

//编译预处理语句：如果未定义__SCLASS4_4_STUDENT_H__则定义它，
//直到遇到#endif结束
#ifndef __SCLASS4_5_STUDENT_H__ 
#define __SCLASS4_5_STUDENT_H__ 

#include <iostream>							//包含头文件。使用iostream库
#include <string>							//包含头文件。使用string库

using namespace std;						//使用std命名空间

//声明CPerson类      
class CPerson  
{
public:
	CPerson(int age,						//年龄
		char sex,							//性别
		string name							//姓名对象
		);
	virtual void Show() const;				//加上virtual就是覆盖；去掉就是隐藏

protected:
	int m_age;								//年龄
	char m_sex;								//性别
	string m_name;							//姓名对象
};  

//声明CStudent类   
class CStudent : virtual public CPerson		//CPerson类是CStudent类的虚基类
{
public:
	CStudent(int age,						//年龄
		char sex,							//性别
		string name,						//姓名对象
		string grade						//年级对象
		);
	void Show() const;						//显示学生的年龄，姓名和年级

protected:
	string m_grade;							//年级对象
};

//声明CClerk(职员)类   
class CClerk : virtual public CPerson		//CPerson类是CClerk类的虚基类
{
public:
	CClerk(int age,							//年龄
		char sex,							//性别
		string name,						//姓名对象
		double salary						//工资
		);
	void Show() const;						//显示职员的年龄，姓名和工资

protected:
	double m_salary;						//职员工资
};

//声明COnJobStudent类   
class COnJobStudent : virtual public CStudent, virtual public CClerk	//多个基类，多继承 
{
public:
	COnJobStudent(int age,					//年龄
		char sex,							//性别
		string name,						//姓名对象
		string grade,						//在职学生的年级对象
		double salary						//在职学生的工资
		);
	void Show() const;						//显示在职学生的年龄、姓名、年级和工资					
};

//类外的普通函数声明
void Reference(const CPerson &roCP);

#endif   //结束编译预处理
 



