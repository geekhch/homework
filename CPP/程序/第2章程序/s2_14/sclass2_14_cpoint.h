// 文件路径名: s2_14\sclass2_14_cpoint.h
#ifndef _SCLASS_CPOINT_H_
#define _SCLASS_CPOINT_H_
#include <iostream>
using namespace std;

class Point 
{ 
public:
    Point()
	{
		x=0;
		y=0;
		counter++;		//当创建对象调用构造函数时，计数器的值递增一个
	} 
   	~Point()
	{
		counter--;		//当析构对象调用析构函数时，计数器的值递减一个
	} 
   	Point(float x, float y)
   	{
        this->x=x;
        this->y=y;
		counter++;		//当创建对象调用构造函数时，计数器的值递增一个
   	}    
    void Move(float x, float y)
    {       
       	this->x=x;
		this->y=y;
   	}
	float GetX()
	{
		return x;
	}
	float GetY()
	{
		return y;
	}
private:
	float x;  
	float y;
public:
	static int counter;
}; 
int Point::counter=0;    //在类外初始化静态数据成员counter
#endif
