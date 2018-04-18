//类声明文件
//文件名：s4_3\sclass4_3_CShape.h 

//编译预处理语句：如果未定义__SCLASS4_3_CSHAPE_H__则定义它，
//直到遇到#endif结束。
#ifndef __SCLASS4_3_CSHAPE_H__ 
#define __SCLASS4_3_CSHAPE_H__ 

#include <iostream>					//包含头文件。使用iostream库

using namespace std;				//使用std命名空间

//声明CShape类      
class CShape  
{
public:
	CShape(double x,				//重心坐标
		double y,					//重心坐标
		double z					//重心坐标
		);
	virtual void Show( ) const;		//添加关键字virtual表示虚函数

protected:
	double m_x;						//重心坐标
	double m_y;						//重心坐标
	double m_z;						//重心坐标
	double m_area;					//形状的面积
};  

//声明CCircle类   
class CCircle : public CShape		//CCircle类继承CShape类 
{
public:
	CCircle(double x,				//圆的重心坐标
		double y,					//圆的重心坐标
		double z,					//圆的重心坐标
		double radius				//圆的半径
		);
	void Show( ) const;				//显示圆的重心坐标和半径

protected:
	double m_radius;				//圆的半径
};

//声明CRectangle类   
class CRectangle : public CShape	//CRectangle类继承CShape类 
{
public:
	CRectangle(double x,			//长方形的重心坐标
		double y,					//长方形的重心坐标
		double z,					//长方形的重心坐标
		double length,				//长方形的长
		double width				//长方形的宽
		);
	void Show( ) const;				//显示长方形的重心坐标及其长和宽

protected:
	double m_length;				//长方形的长
	double m_width;					//长方形的宽
};

//声明CSquare类   
class CSquare : public CShape		//CSquare类继承CShape类 
{
public:
	CSquare(double x,				//正方形的重心坐标
		double y,					//正方形的重心坐标
		double z,					//正方形的重心坐标
		double edge					//正方形的边长
		);
	void Show( ) const;				//显示正方形的重心坐标和边长

protected:
	double m_edge;					//正方形的边长
};

#endif								//结束编译预处理
 