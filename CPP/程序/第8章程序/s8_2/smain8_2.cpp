//文件名：s8_2\smain8_2.cpp
//数组与指针的比较

#include <iostream>
#include <string>
using namespace std;

//测试函数
int main()
{
	//数组定义：内存中有数组空间，没有字符串常量。
	char a1[ ] = "Hello Iron Man!";	//定义数组并初始化
	a1[14] = '2';				//数组的元素值是可以改变的。
	cout << a1 << endl;			//显示:Hello Iron Man2

	//指针变量定义并初始化：内存中有指针变量，并在静态存储区有一个字符串常量。
	//内存中分配两个空间：指针变量空间；字符串常量空间。
	char *p1 = "Hello World!";	// 注意p1指向常量字符串
	//p1[0]不可修而a1[0]可以。因为p1指向的是常量，不能修改常量。a1[0]是变量，可修改
	//p1[0] = 'X';				// 该语句编译器不能发现其错误，但运行时会发现。
	cout << p1 << endl;			//显示:Hello World!

	// 字符数组赋值的方法
	char a2[ ] = "Hello Baby!";	//数组初始化表示，内存中没有常量字符串。
	char b2[81];
	strcpy(b2, a2);				//赋值数组的方法。不能用b2 = a2;会发生编译错误
	cout << b2 << endl;			//显示:Hello World

	// 复制指针所指向的字符串的方法
	int len = strlen(a2);
	char *p2 = new char[len+1];	//注意空间大小，为何要＋1 ?
	if (p2 == NULL) return 1;
	strcpy(p2, a2);				//复制操作，不要用p2=a2,该语句只让p2指向了数组a2
	cout << b2 << endl;			//显示:Hello World
	//字符指针变量的长度和该指针所指向的字符串的长度的区别
	cout<< sizeof(a2) << endl;	// 12字节,a2是一个字符数组
	cout<< sizeof(p2) << endl;	// 4字节，p2是一个字符指针变量
	delete [ ]p2;
	p2 = NULL;					//为了安全，这种操作是必须的。
	
	system("PAUSE");			//等待键盘输入以实现暂停  
	return 0;					//返回0
}







