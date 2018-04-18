//类声明文件
//文件路径名：s2_11\sclass2_11_rectangle.h 

//编译预处理语句：如果未定义__SCLASS2_11_RECTANGLE_H__则定义它，
//直到遇到#endif结束。
#ifndef __SCLASS2_11_RECTANGLE_H__ 
#define __SCLASS2_11_RECTANGLE_H__ 

#include <iostream>
using namespace std;

class Rectangle 
{ 
public:
	Rectangle();   	 
	Rectangle(double, double);  
	~ Rectangle(){}; 	  
	void SetSize(double, double); 	
	double GetLength();    
	double GetWidth();
	double GetArea();    	
	void Print();		
private:
	double length;  
	double width;
};
#endif
