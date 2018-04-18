// 文件路径名:s1_5\main.cpp
#include <iostream>
using namespace std;

inline int add(int x, int y)
{
	return x+y; 
} 
int main()
{ 
	for(int i = 10; i>=0; i--)
		cout<<add(i, i)<<" "; 
	return 0;                    		// 返回值0, 返回操作系统
} 
