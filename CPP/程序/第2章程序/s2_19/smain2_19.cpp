//文件路径名: s2_19\smain2_19.cpp
#include<iostream>
#include<cstring>
using namespace std;

class A
{
private:
	friend class B;
	char *name;
	int age;
public:
	A(char *str, int n)
	{
		name=new char[strlen(str)+1];
		strcpy(name, str);
		age=n;
	}
};
class B
{
public: 
	void Show(const A &x)
	{
		cout<<"姓名:"<<x.name<<endl;
		cout<<"年龄:"<<x.age<<endl;
	}
};
int main()	
{
	A a("左力", 19);
	B b;
	b.Show(a);
	return 0;
}

