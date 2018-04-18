//文件路径名：s2_8\sclass2_8_cpoint.cpp 
#include "sclass2_8_cpoint.h"
CPoint::CPoint(int x1, int y1)      
{
	x = x1;
	y = y1;
}
CPoint::CPoint(const CPoint &obj)	//拷贝构造函数
{
	x = obj.x;
	y = obj.y;
}
int CPoint::GetX()					//通过接口间接访问x坐标
{
	return x;
}
int CPoint::GetY()					//通过接口间接访问y坐标
{
	return y;
}
