// �ļ�·����: s2_6\smain 2_6.cpp
#include "sclass2_6_date.h"
int main()
{
    Date date1;              //��������û���ṩʵ�Σ�����ȡĬ��ֵ
	Date date2(2012, 10, 1); //���ô��������캯��������ʵ��ֵ����ʼ�����ݳ�Ա
	
	date1.Print();
	if (date1.IsLeapYear())	cout<<"����������"<<endl<<endl;
	else cout<<"���겻������"<<endl<<endl;
	
	date2.Print();
	if (date2.IsLeapYear())	cout<<"����������"<<endl;
	else cout<<"���겻������"<<endl;
	
	return 0;
}
