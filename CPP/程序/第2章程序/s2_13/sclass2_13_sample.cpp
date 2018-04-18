//类实现文件
//文件路径名：s2_13\sclass2_13_sample.cpp 

#include "sclass2_13_sample.h"
CSample::CSample (int a)
{
	n = a;
}
CSample CSample::Add(CSample s1, CSample s2) 
//将个对象的数据成员n相加，结果赋给当前调用函数的对象的数据n
{
	this -> n = s1.n + s2.n;
	return *this;	// 返回this指针所指向的对象，该对象的n为两个参数对象的n之和
} 
int CSample::GetN() 
//获取数据成员n的值
{
	return n;
}
