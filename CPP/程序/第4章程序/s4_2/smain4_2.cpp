//主文件
//文件名：s4_2\smain4_2.cpp

#include "sclass4_2_CShape.h"				//包含类声明头文件

//测试引用参数
void Reference(const CShape &roCS)			//基类的引用作为形参  
{
	roCS.Show();  
}

//主测试程序
int main()    
{
	CShape oCS(1.1, 2.0, 3.0);				//创建一个CShape类的对象
	CCircle oCC(10.0, 20.1, 30.0, 100.0);	//创建一个CCircle类的对象
	Reference(oCS);							//以基类对象作引用参数
	Reference(oCC);							//以派生类对象作引用参数
	system("PAUSE");						//等待键盘输入以实现暂停  
	return 0;								//返回0
}
