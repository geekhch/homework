//类声明文件
//文件路径名：s2_13\sclass2_13_sample.h 

//编译预处理语句：如果未定义__SCLASS2_13_SAMPLE_H__则定义它，
//直到遇到#endif结束。
#ifndef __SCLASS2_13_SAMPLE_H__ 
#define __SCLASS2_13_SAMPLE_H__ 

#include<iostream> 
using namespace std;

class CSample
{
public:	
	CSample(){};	
	CSample(int a);							//重载构造函数
	CSample Add(CSample s1, CSample s2);	//将2个对象的数据成员n相加，结果赋给当前调用函数的对象的数据n
	int GetN();								//获取数据成员n的值
private:
	int n;              	 
};
#endif

