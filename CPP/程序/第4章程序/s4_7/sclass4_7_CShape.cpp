//类的实现文件
//文件名：s4_7\sclass4_7_CShape.cpp

#include "sclass4_7_CShape.h"		//包含类声明头文件

//CCircle构造函数
CCircle::CCircle(double radius				//圆的半径
				 ): CShape( ), m_radius(radius){}	//调用基类的默认构造函数    

//计算圆的面积
double CCircle::CalculateArea( ) const
{
	cout << "CCircle::" << 2*3.14*m_radius*m_radius << "."<< endl;
	return 2*3.14*m_radius*m_radius;
}

//CRectangle构造函数
CRectangle::CRectangle(double length,				//长方形的长
		double width								//长方形的宽
		): CShape( ), m_length(length), m_width(width){} //调用基类的默认构造函数  

//计算长方形的面积
double CRectangle::CalculateArea( ) const
{
	cout << "CRectangle::" << m_length*m_width << "."<< endl;
	return m_length*m_width;
}

//CSquare构造函数
CSquare::CSquare(double edge					//正方形的边长
				 ): CShape( ), m_edge(edge){}				//调用基类的默认构造函数     

//计算正方形的面积
double CSquare::CalculateArea( ) const
{
	cout << "CSquare::" << m_edge*m_edge << "."<< endl;
	return m_edge*m_edge;
}

//测试引用参数
void Reference(const CShape &roCS)	//基类的引用作为形参,由于不需修改引用对象，应使用const  
{
	roCS.CalculateArea();  
}