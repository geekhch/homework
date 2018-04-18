// 文件路径名: s2_5\smain 2_5.cpp
#include "sclass2_5_date.h"
int main()
{
	Date date1;
	date1.Print();		//对象date2调用Print()成员函数，输出date1的状态
	Date date2(2012, 9, 1); 		
	date2.Print();		//对象date2调用Print()成员函数，输出date2的状态
	return 0;
}
