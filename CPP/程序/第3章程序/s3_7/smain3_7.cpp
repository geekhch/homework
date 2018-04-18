//ÎÄ¼şÃû£ºs3_7\smain3_7.cpp
#include<iostream>
using namespace std;

class A
{
 public:
	void SetA(int x) { a=x; }
	void ShowA() const { cout<<"a="<<a<<endl; }
private :
   	int a;
};

class B
{
public:
	void SetB(int x) { b=x; }
	void ShowB() const { cout<<"b="<<b<<endl; }
private:
	int b;
};

class C: public A, public B
{
public:
	void SetC(int x, int y, int z)
	{
		SetA(x);
		SetB(y);
		c=z;
	}
	void ShowC() const { cout<<"c="<<c<<endl; }
private:
	int c;
};

int main()
{
	C c;
	c.SetC(1,2,3);
	c.ShowA();
	c.ShowB();
	c.ShowC();
	return 0;
}
