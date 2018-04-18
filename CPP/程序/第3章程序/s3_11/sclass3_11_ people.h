//类声明文件：s3_11\sclass3_11_ people.h
#ifndef _SCLASS_3_11_PEOPLE_H
#define _SCLASS_3_11_PEOPLE _H
#include <iostream>  
using namespace std; 

class Date 
{ 
public: 		
	Date();						//声明一个无参数的构造函数
	Date(int y, int m, int d);	//声明一个带三个参数的构造函数
	void SetDate(int y, int m, int d) ;
	int IsLeapYear() const;
	void Print() const;
private: 
	int year, month, day;		//声明日期类的属性：年、月、日
} ;

class People
{
public:
	People(int num, char s, int n, int m, int d);
	void SetNum(int n);
	void SetSex(char s);
	int GetNum() const { return number;	}
	char GetSex() const { return sex; }
	void Print() const 
	{
		cout<<"编号为"<<number<<"的人员的出生日期是";
		birthday.Print( );   // birthday 调用公有成员函数Print，输出birthday 的年月日
	}
private:
	int number;
	char sex;
	Date birthday ;
};
#endif
