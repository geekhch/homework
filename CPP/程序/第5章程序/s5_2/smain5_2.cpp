//s5_2\smain5_2.cpp
//具有函数模板和同名重载函数的匹配过程

#include <iostream>
#include <string>
using namespace std;

//定义全局重载函数
int GetMax(int a, int b)				//求两个整型数的最大值
{
	cout << "调用GetMax(int, int): "; 	//用于显示所调用的函数
	return a > b ? a : b;
}

//定义全局重载函数
char GetMax(char a, char b)				//求两个双精度型数的最大值
{
	cout << "调用GetMax(char, char): ";
	return a > b ? a : b;
}

//定义函数模板1——重载函数模板
template <class Type1, class Type2>
Type1 GetMax( Type1 x, Type2 y )
{
	cout << "调用函数模板1: ";
	return  x > y ? x:y;				//自动转化为高类型再比较
}

//定义函数模板2——重载函数模板
template <class Type1, class Type2,class Type3>
Type1 GetMax(Type1 a, Type2 b, Type3 c)
{
	Type1 t;
	t = a > b ? a:b;					//求a和b的较大者
	cout << "调用函数模板2: ";
	return t > c ? t : c;				//返回a、b、c的最大者。
}

//主函数
int main()    
{ 
	cout << " " << GetMax(10, 20) << endl;		//调用重载函数
	cout << " " << GetMax('A', 'i') << endl;	//调用重载函数

	cout << " " << GetMax(1.0, 2.0) << endl;	//使用函数模板1
	cout << " " << GetMax('A', 100) << endl;	//使用函数模板1

	cout << " " << GetMax(10, 5.0) << endl;		//使用函数模板1
	cout << " " << GetMax(11.1, 5) << endl;		//使用函数模板1
	cout << " " << GetMax(22, 10L) << endl;		//使用函数模板1
	cout << " " << GetMax(2L, 'A') << endl;		//使用函数模板1	
	cout << " " << GetMax(1.0, 200L) << endl;	//使用函数模板1

	cout << " " << GetMax(10, 20, 30) << endl;	//使用函数模板2
	cout << " " << GetMax(10L, 20, 30) << endl;	//使用函数模板2
	cout << " " << GetMax(1.1, 2.2, 3) << endl;	//使用函数模板2  
	cout << " " << GetMax(99.9, 8, 'A') << endl;//使用函数模板2

	system("PAUSE");					//等待键盘输入以实现暂停  
	return 0;							//返回0
}
