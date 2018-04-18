// 文件路径名:s1_3\main.cpp
#include <iostream>
using namespace std;

void fun()
{
	printf("The first line\n");
	int i=10;  //C 语言中i必须在fun()函数的开始处定义
	printf("i=%d ",i);
}
int main()
{
	fun();
	return 0;                    		// 返回值0, 返回操作系统
}

