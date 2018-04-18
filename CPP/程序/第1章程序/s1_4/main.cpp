// 文件路径名:s1_4\main.cpp
#include <iostream>
using namespace std;

int i=10;
void fun()
{
	int i=20;
	printf("局部变量 i=%d",i); //访问局部变量i
	printf(" ，全局变量 i=%d",::i); //访问全局变量i，在C语言中，
    //由于定义了局部变量 i，无法在 fun()函数内访问同名全局变量 i
}
int main()
{
	fun();
	return 0;                    		// 返回值0, 返回操作系统
}
