//类的实现文件
//文件名：s4_2\sclass4_2_CShape.cpp

#include "sclass4_2_CShape.h"		//包含类声明头文件

//CShape构造函数  
CShape::CShape(double x,			//重心坐标
		double y,					//重心坐标
		double z					//重心坐标
		): m_x(x), m_y(y), m_z(z)
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
		) : CShape(x, y, z), m_radius(radius)    
{
	;
}

//显示圆的重心坐标和圆的半径
void CCircle::Show( ) const
{
	cout << "x=" << m_x << ",y=" << m_y << ",z=" << m_z 
		<< ",radius=" << m_radius <<"."<< endl;  
}
