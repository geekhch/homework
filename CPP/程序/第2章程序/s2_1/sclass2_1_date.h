// 文件路径名:s2_1\sclass2_1_date.h
#include <iostream>               		//编译预处理命令
using namespace std;					//使用命名空间std 

class Date 
{ 
public: 
	void SetDate(int y, int m, int d) 	//日期类的行为：设置当前日期的年月日
	{
		year=y;
		month=m;
		day=d;
	} 
	bool IsLeapYear( )					//日期类的行为：判断当前日期是否属于闰年
	{
		return(year%4==0 && year%100!=0) || (year%400==0);
 	} 
	void Print( )		//日期类的行为：输出当前日期的年月日
	{
		cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
	} 
private: 
	int year; 			//声明日期类的属性：年
	int month; 			//声明日期类的属性：月
	int day; 			//声明日期类的属性：日
} ;
