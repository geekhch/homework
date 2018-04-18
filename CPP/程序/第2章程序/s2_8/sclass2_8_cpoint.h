//类声明文件
//文件路径名：s2_8\sclass2_8_cpoint.h 

//编译预处理语句：如果未定义__SCLASS2_8_CPOINT_H__则定义它，
//直到遇到#endif结束。
#ifndef __SCLASS2_8_CPOINT_H__ 
#define __SCLASS2_8_CPOINT_H__ 

#include <iostream>                    
using namespace std; 

class CPoint
{
public:    
	CPoint(int x1, int y1);     //声明构造函数    
	CPoint(const CPoint &obj);	//声明拷贝构造函数
	int GetX();
	int GetY();	
private:
	int x;						//水平坐标
	int y;						//垂直坐标
};
#endif
