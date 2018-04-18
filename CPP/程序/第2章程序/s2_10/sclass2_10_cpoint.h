//类声明文件
//文件路径名：s2_10\sclass2_10_cpoint.h

//编译预处理语句：如果未定义__SCLASS2_10_CPOINT_H__则定义它，
//直到遇到#endif结束。
#ifndef __SCLASS2_10_CPOINT_H__ 
#define __SCLASS2_10_CPOINT_H__ 

#include <iostream>
using namespace std;

class CPoint 
{ 
public:
	CPoint(){} 
	~CPoint(){} 
	CPoint(float x1, float y1);
	void Move(float x1, float y1);
   
	//为了便于类外访问，以下声明公有数据成员，分别代表属性：横、纵坐标
	float x;  
	float y;
};
#endif
