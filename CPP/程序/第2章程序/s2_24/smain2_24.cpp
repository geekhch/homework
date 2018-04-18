// 文件路径名: s2_24\smain2_24.cpp
#include<iostream>
using namespace std;

class Point
{
public:
	Point(int a, int b)
	{
		x=a; 
		y=b;
	}
	void Move(int a, int b)
	{
		x+=a;
		y+=b;
	}
	void Print() const
	{
		cout<<"x="<<x<<", y="<<y<<endl;
	}
private:
	int x, y;
};
int main()
{
	const Point point1( 10,10);	//声明并初始化常量对象point1
	point1.Print();				//Print()函数现在变成常成员函数，所以可以被point1调用
	return 0;
}
