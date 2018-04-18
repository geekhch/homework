// 文件路径名: circle\sclass_ccircle.h
#ifndef __SCLASS_CCIRCLE_H__					// 如果没有定义__SCLASS_CCIRCLE_H__
#define __SCLASS_CCIRCLE_H__					// 那么定义__SCLASS_CCIRCLE_H__

const int DEFAULT_RADIUS = 10;					// 缺省圆半径
const double PI = 3.1415926;					// 圆周率常数

class CCircle
{
public:
	CCircle(double r = DEFAULT_RADIUS);			// 构造函数
	void SetRadius(double r = DEFAULT_RADIUS);	// 设置圆半径
	double GetRadius();							// 返回圆半径
	double GetArea();							// 返回求圆面积

private:
	double radius;								// 圆半径		
};

#endif
