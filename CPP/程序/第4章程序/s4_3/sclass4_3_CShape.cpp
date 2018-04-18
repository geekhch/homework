//类的实现文件
//文件名：s4_3\sclass4_3_CShape.cpp

#include "sclass4_3_CShape.h"		//包含类声明头文件

//CShape构造函数  
CShape::CShape(double x,			//重心坐标
		double y,					//重心坐标
		double z					//重心坐标
		): m_x(x), m_y(y), m_z(z)	//初始化列表
{
	;
}

//显示重心坐标
void CShape::Show( ) const
{
	cout << "x=" << m_x << ",y=" << m_y << ",z=" << m_z << "."<< endl;  
}

//CCircle构造函数
CCircle::CCircle(double x,			//圆的重心坐标
		double y,					//圆的重心坐标
		double z,					//圆的重心坐标
		double radius				//圆的半径
		) : CShape(x, y, z), m_radius(radius)	//调用基类的构造函数    
{
	;
}

//显示圆的重心坐标和圆的半径
void CCircle::Show( ) const
{
	cout << "x=" << m_x << ",y=" << m_y << ",z=" << m_z 
		<< ",radius=" << m_radius <<"."<< endl;  
}

//CRectangle构造函数
CRectangle::CRectangle(double x,	//长方形的重心坐标
		double y,					//长方形的重心坐标
		double z,					//长方形的重心坐标
		double length,				//长方形的长
		double width				//长方形的宽
		) : CShape(x, y, z), m_length(length), m_width(width) //调用基类的构造函数  
{
	;
}

//显示长方形的重心坐标及其长和宽
void CRectangle::Show( ) const
{
	cout << "x=" << m_x << ",y=" << m_y << ",z=" << m_z 
		<< ",length=" << m_length << ",width=" << m_width << "."<< endl;  
}

//CSquare构造函数
CSquare::CSquare(double x,			//正方形的重心坐标
		double y,					//正方形的重心坐标
		double z,					//正方形的重心坐标
		double edge					//正方形的边长
		) : CShape(x, y, z), m_edge(edge)	//调用基类的构造函数     
{
	;
}

//显示正方形的重心坐标和边长
void CSquare::Show( ) const
{
	cout << "x=" << m_x << ",y=" << m_y << ",z=" << m_z 
		<< ",edge=" << m_edge <<"."<< endl;  
}