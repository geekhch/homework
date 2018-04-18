// 文件路径名: s2_6\smain 2_6.cpp
#include "sclass2_6_date.h"
int main()
{
    Date date1;              //创建对象没有提供实参，参数取默认值
	Date date2(2012, 10, 1); //调用带参数构造函数，采用实参值来初始化数据成员
	
	date1.Print();
	if (date1.IsLeapYear())	cout<<"此年是闰年"<<endl<<endl;
	else cout<<"此年不是闰年"<<endl<<endl;
	
	date2.Print();
	if (date2.IsLeapYear())	cout<<"此年是闰年"<<endl;
	else cout<<"此年不是闰年"<<endl;
	
	return 0;
}
