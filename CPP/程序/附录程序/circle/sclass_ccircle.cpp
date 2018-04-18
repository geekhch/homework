// 文件路径名: circle\sclass_ccircle.cpp
#include "sclass_ccircle.h"			// 声明圆的类的头文件

// 已知半径dRadius构造圆
CCircle::CCircle(double r)
{
	radius = r;						// 初始化园半径
}

// 设置圆半径
void CCircle::SetRadius(double r)
{
	radius = r;						// 设置圆半径
}

// 返回圆半径
double CCircle::GetRadius()
{
	return radius;					// 返回圆半径
}

// 求圆面积
double CCircle::GetArea()
{
	double area;					// 定义变量
	area = PI * radius * radius;	// 计算圆面积
	return area;					// 返回圆面积
}
