//类声明文件
//文件名：s4_9\sclass4_9_circle.h 

//编译预处理语句：如果未定义__SCLASS4_9_CIRCLE_H__则定义它，
//直到遇到#endif结束
#ifndef __SCLASS4_9_CIRCLE_H__ 
#define __SCLASS4_9_CIRCLE_H__ 

#include <iostream>  //包含头文件。使用iostream库

using namespace std; //使用std命名空间

//声明CCircle类      
class CCircle  
{
public:
	void Reference();				//类内成员函数
};  

void Reference();					//类外，全局重载函数
void Reference(CCircle &oCC);		//类外，全局重载函数

#endif   //结束编译预处理
 



