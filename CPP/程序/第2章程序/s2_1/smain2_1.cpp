//�ļ�·����:s2_1\smain2_1.cpp
#include "sclass2_1_date.h" 
int main()
{
	Date d1;
	d1.SetDate(2012,11,11);
	d1.Print();
	if (d1.IsLeapYear()) cout<<"����������" << endl;
	else cout<<"���겻������" << endl;
	return 0;
}