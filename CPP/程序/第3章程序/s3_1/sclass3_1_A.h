//类的声明文件：s3_1\sclass3_1_A.h
#ifndef _SCLASS_3_1_A_H
#define _SCLASS_3_1_A _H
#include<iostream>  
using namespace std; 

// 定义基类
class A
{
public:
	void SetX(int i);		//为数据成员x赋值
	int GetX() const;		//获取数据成员x的值
	int z;					//基类的公有数据成员
protected:
	int y;					//基类的保护数据成员
private:
	int x;					//基类的私有数据成员
};

//定义派生类
class B : public A			//类B公有继承类A
{
public:
	//为基类和本类中的所有数据成员赋值
	void SetValue(int, int, int, int, int);
	void Display() const;	//显示各数据成员的值
protected:
	int m;					//派生类的保护数据成员
private:
	int n;					//派生类的私有数据成员
};
#endif
