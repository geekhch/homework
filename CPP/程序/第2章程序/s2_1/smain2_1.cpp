//文件路径名:s2_1\smain2_1.cpp
#include "sclass2_1_date.h" 
int main()
{
	Date d1;
	d1.SetDate(2012,11,11);
	d1.Print();
	if (d1.IsLeapYear()) cout<<"此年是闰年" << endl;
	else cout<<"此年不是闰年" << endl;
	return 0;
}