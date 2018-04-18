//主文件
//文件名：ch4_1\smain4_1.cpp

#include "sclass4_1_CShape.h"				//包含类声明头文件

//主测试程序
int main()    
{
	CShape oCS(1.1, 2.0, 3.0);				//创建一个CShape类的对象
	CShape *poCS;							//定义基类CShape的指针变量
	CCircle oCC(10.0, 20.1, 30.0, 100.0);	//创建一个CCircle类的对象
	poCS = &oCS;							//基类指针指向基类对象
	poCS->Show();							//通过基类指针调用Show()函数
	poCS = &oCC;							//基类基类指针指向派生类对象
	poCS->Show();							//通过基类指针调用Show()函数
	system("PAUSE");						//等待键盘输入以实现暂停  
	return 0;								//返回0
}