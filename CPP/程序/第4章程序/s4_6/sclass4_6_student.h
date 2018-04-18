//类声明文件
//文件名：s4_6\sclass4_6_student.h 

//编译预处理语句：如果未定义__SCLASS4_7_STUDENT_H__则定义它，
//直到遇到#endif结束。
#ifndef __SCLASS4_6_STUDENT_H__ 
#define __SCLASS4_6_STUDENT_H__ 

#include <iostream>		//包含头文件，使用iostream库
#include <string>		//包含头文件，用string库

using namespace std;	//使用std命名空间

//声明CPerson类      
class CPerson  
{
public:
	 virtual ~CPerson();	//必须加virtual，声明为虚函数，否则用delete销毁对象时会出错
protected:
	int m_age;				//年龄
	string m_name;			//姓名对象
};  

//声明CStudent类   
class CStudent : public CPerson		//CStudent类继承自CPerson类 
{
public:
	~CStudent();					//派生类的析构函数也最好加上virtual

protected:
	string m_grade;					//年级对象
};

#endif   //结束编译预处理
 