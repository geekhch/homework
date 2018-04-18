//类的实现文件：s3_3\sclass3_3_cbase.cpp
#include "sclass3_3_cbase.h"

void CBase::SetValue(int a, int b)	//为数据成员m和n赋值
{
	n = a;
	m = b;
	cout << "基类成员n ＝ " << n << endl; 
	cout << "基类成员m ＝ " << m << endl; 
}
void CBase::CalcuValue()			//用于计算的接口，并将计算结果显示在屏幕上   
{ 
	cout << "n×m ＝ " << m*n << endl; 
}

void CDerived::SetJ()
{
	j = 2 * m;						//派生类成员可以访问基类的保护数据m
}
void CDerived::SetK()
{
	//k = n;						//非法！派生类成员不能访问基类的私有数据n
	k = 0;
}
void CDerived::DisplayVal() const
{
	cout << "派生类成员j ＝ " << j << endl;
	cout << "派生类成员k ＝ " << k << endl;
}