//类声明文件
//文件名：s4_7\sclass4_7_CShape.h 

//编译预处理语句：如果未定义__SCLASS4_7_CSHAPE_H__则定义它，
//直到遇到#endif结束。
#ifndef __SCLASS4_7_CSHAPE_H__ 
#define __SCLASS4_7_CSHAPE_H__ 

#include <iostream>					//包含头文件。使用iostream库

using namespace std;				//使用std命名空间

//声明CShape类      
class CShape  
{
public:
	virtual double CalculateArea() const = 0;	//声明纯虚函数

protected:
	double m_area;					//形状的面积
};  

//声明CCircle类   
class CCircle : public CShape		//CCircle类继承CShape类 
{
public:
	CCircle(double radius);			//圆的半径
	double CalculateArea() const;	//声明成员函数

protected:
	double m_radius;				//圆的半径
};

//声明CRectangle类   
class CRectangle : public CShape	//CRectangle类继承CShape类 
{
public:
	CRectangle(double length,		//长方形的长
		double width				//长方形的宽
		);
	double CalculateArea() const;	//声明成员函数

protected:
	double m_length;				//长方形的长
	double m_width;					//长方形的宽
};

//声明CSquare类   
class CSquare : public CShape		//CSquare类继承CShape类 
{
public:
	CSquare(double edge);			//正方形的边长
	double CalculateArea() const;	//声明成员函数

protected:
	double m_edge;					//正方形的边长
};

void Reference(const CShape &roCS);	//基类的引用作为形参

#endif								//结束编译预处理
 