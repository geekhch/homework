//类的实现文件：s3_1\sclass3_1_A.cpp
#include "sclass3_1_A.h"		//包含类声明头文件

void A::SetX(int i)				//为数据成员x赋值
{
	x = i;
}
int A::GetX() const				//获取数据成员x的值
{
	return x;
}

void B::SetValue(int a, int b, int c, int d, int e)
{
	// x = a;					//基类的私有数据x对派生类不可见，故直接访问非法！
	SetX(a);   					//通过外部接口SetX( )来间接访问基类的私有数据x
	y = b;       				//将b的值赋给基类的保护成员y，访问合法
	z = c;       				//将c的值赋给基类的公有成员z，访问合法
	m = d;
	n = e;
}
void B::Display() const
{
	// cout << "x = " << x << endl; //x在派生类中不可访问
	cout << "x = " << GetX() << endl;
	cout << "y = " << y << endl;
	cout << "m = " << m << endl;
	cout << "n = "<< n << endl;		//派生类的私有成员在本类中可以访问
}
