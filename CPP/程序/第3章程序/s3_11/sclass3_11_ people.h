//�������ļ���s3_11\sclass3_11_ people.h
#ifndef _SCLASS_3_11_PEOPLE_H
#define _SCLASS_3_11_PEOPLE _H
#include <iostream>  
using namespace std; 

class Date 
{ 
public: 		
	Date();						//����һ���޲����Ĺ��캯��
	Date(int y, int m, int d);	//����һ�������������Ĺ��캯��
	void SetDate(int y, int m, int d) ;
	int IsLeapYear() const;
	void Print() const;
private: 
	int year, month, day;		//��������������ԣ��ꡢ�¡���
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
		cout<<"���Ϊ"<<number<<"����Ա�ĳ���������";
		birthday.Print( );   // birthday ���ù��г�Ա����Print�����birthday ��������
	}
private:
	int number;
	char sex;
	Date birthday ;
};
#endif
