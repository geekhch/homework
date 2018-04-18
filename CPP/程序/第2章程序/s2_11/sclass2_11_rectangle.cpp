//类的实现文件
//文件路径名：s2_11\sclass2_11_rectangle.cpp 
#include "sclass2_11_rectangle.h"
Rectangle::Rectangle()
{
	length=0;
	width=0;
}
Rectangle ::Rectangle(double l, double w)
{
	length=l;
	width=w;
}    
void Rectangle::SetSize(double l, double w)
{
	length=l;
	width=w;
} 
double Rectangle::GetLength()
{       
	return length;
}
double Rectangle::GetWidth() 
{       
	return width;
}
double Rectangle:: GetArea() 
{       
	return length*width;
}
void Rectangle::Print()
{
	cout<<"长方形的长是"<< length<<"宽是"<< width
		<<"面积是"<< GetArea( )<<endl;
}
