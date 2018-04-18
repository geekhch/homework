//类声明文件
//文件路径名：s2_4\sclass2_4_square.h

//编译预处理语句：如果未定义__SCLASS2_4_SQUARE_H__则定义它，
//直到遇到#endif结束。
#ifndef __SCLASS2_4_SQUARE_H__ 
#define __SCLASS2_4_SQUARE_H__ 

#include <iostream>  
using namespace std; 

class Square 
{ 
public: 	
	Square(double s);				//声明Date类的带参构造函数
	double GetSide(); 
	double GetCircumference();		//计算周长
	double GetArea();				//计算面积
	void Print();  
private: 
	double side;					//声明正方形类的属性：边长
};
#endif
