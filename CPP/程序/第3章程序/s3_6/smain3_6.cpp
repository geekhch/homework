//�ļ�����s3_6\smain3_6.cpp
#include <iostream>  
using namespace std;  

// ������ࣺA
class A
{
public:	 
	A() 
	{ 
		cout << "������A�Ĺ��캯��" << endl;
	}
	~A()
	{ 
	 	cout << "������A����������" << endl;
	}	
};
class B : public A     //����������B��Ϊ��ָ�����༰�̳з�ʽ
{
public:	 
	B() 
	{ 
		cout << "������B�Ĺ��캯��" << endl;
	}
	~B()
	{ 
		cout << "������B����������" << endl;
	}	
};
int main()
{
	B b;   //ͨ�����������b�Ĵ������۲�����������๹�캯���ĵ���˳��
	   	   //ͨ������b���������۲�ϵͳ���û���������������������˳��
	return 0;
}
