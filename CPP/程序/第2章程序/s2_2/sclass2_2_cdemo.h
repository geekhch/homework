//类声明文件
//文件路径名：s2_2\sclass2_2_cdemo.h 

#ifndef __SCLASS2_2_CDEMO_H__		// 如果未定义__SCLASS2_2_CDEMO_H__
#define __SCLASS2_2_CDEMO_H__		// 则定义它__SCLASS2_2_CDEMO_H__，直到遇到#endif结束

#include <iostream>  
using namespace std; 

//CDemo类的定义     
class CDemo
{
public:
	void SetI( int a )                 //设置外部接口SetI( )为i赋值
	{
		i = a;
	}
	void SetJ( int b )                 //设置外部接口SetJ( )为j赋值
	{
		j = b;
	}
	void GetI( ) 
	{
		cout << "i=" << i << endl;     //输出i的值
	}
	void GetJ( ) 
	{
		cout << "j=" << j << endl;     //输出j的值
	}
		
protected:
	int j;
private:
	int i;
};
#endif
