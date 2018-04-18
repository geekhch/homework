// 文件路径名: s2_26\smain2_26.cpp
#include<iostream>
using namespace std;

class A
{
public:
	A(int i): a(i){}
	void Print() const
	{
		cout<<a<<":"<<b<<endl;
	}

private:
	const int a;
	static const int b;
};
const int A::b=10;
int main()
{
	A a1(100), a2(0);
	a1.Print();
	a2.Print();
}
