// 文件路径名: s2_8\smain 2_8.cpp
#include "sclass2_8_cpoint.h"
int main()
{
	CPoint a(20, 50);			//系统调用构造函数，创建了一个坐标为(20,50)的点a
	CPoint b(a);				//系统调用拷贝构造函数，利用点a克隆点b
	CPoint c = a;				//系统调用拷贝构造函数，利用点a克隆点c
	cout << "a(" << a.GetX() << "," << a.GetY() << ")" << endl;
	cout << "b(" << b.GetX() << "," << b.GetY() << ")" << endl;
	cout << "c(" << c.GetX() << "," << c.GetY() << ")" << endl;
	return 0;
}
