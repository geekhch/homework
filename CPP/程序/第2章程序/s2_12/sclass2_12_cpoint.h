//类声明文件
//文件路径名：s2_12\sclass2_12_point.h 

//编译预处理语句：如果未定义__SCLASS2_12_POINT_H__则定义它，
//直到遇到#endif结束。
#ifndef __SCLASS2_12_POINT_H__ 
#define __SCLASS2_12_POINTE_H__ 

#include <iostream>
using namespace std;

class CPoint 
{ 
public:
	CPoint(){} 
	~CPoint(){} 
	CPoint(float, float);    
	void Move(float, float);  
	//为了便于类外访问，以下声明公有数据成员，分别代表属性：横、纵坐标
	float x;  
	float y;
}; 
#endif
