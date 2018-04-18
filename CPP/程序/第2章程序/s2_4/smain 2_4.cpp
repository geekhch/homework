// 文件路径名:s2_4\smain 2_4.cpp
#include "sclass2_4_square.h "
int main()
{    
	Square square1(20.5);	//创建对象square1，系统调用构造函数时利用实参20.5初始化边长
	square1.Print();		//square1调用print()成员函数，输出square1的周长和面积 		
	Square square2(13.5);	//创建对象square2，系统调用构造函数时利用实参13.5初始化边长
	square2.Print();		//square2调用print()成员函数，输出square2的周长和面积
	Square square3(35.9);	//创建对象square3，系统调用构造函数时利用实参35.9初始化边长
	square3.Print();		//square3调用print()成员函数，输出square3的周长和面积
	return 0;
}
