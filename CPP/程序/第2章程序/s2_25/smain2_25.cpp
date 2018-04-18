// 文件路径名: s2_25\smain2_25.cpp
#include<iostream>
using namespace std;

class A
{
public:
	int GetValue() const { return w*h; }
	int GetValue() { return w+h; }
	A(int x,int y) { w=x,h=y; }
	A(){};
private:
	int w, h;
};
int main( )
{ 
	A const a(3,4);
	A c(2,6);
	cout<<a.GetValue()<<endl<<c.GetValue()<<endl;  //输出12和8
	return 0;
}
