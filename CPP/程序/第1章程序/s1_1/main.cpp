// 文件路径名:s1_1\main.cpp
#include <iostream>
using namespace std;

int main()
{
	int i=10;
	char c='a';
	float f=20.325;
	int *pi=&i;
	char *pa="Hellow World!";
	cout<<i<<'\t'<<c<<'\t'<<f<<endl;
	cout<<pi<<'\t'<<pa<<endl;
	cout<<"这是一个串常量！";
	return 0;                    		// 返回值0, 返回操作系统
}
