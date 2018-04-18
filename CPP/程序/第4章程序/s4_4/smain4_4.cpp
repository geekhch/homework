//主文件
//文件名：s4_4\smain4_4.cpp

#include "sclass4_4_student.h"	//包含类声明头文件

//主测试程序
int main()    
{
	CPerson *poCP;							//定义指向基类对象的指针
	CStudent oCS(8, "Clinton", "Grade Two");//创建一个派生类对象
	poCP = &oCS;		//基类指针指向派生类对象
	oCS.Show(1);		//通过派生类对象只能调用派生类重新定义的同名函数
	//oCS.Show();		//通过派生类对象不能调用被隐藏的基类函数
	poCP->Show();		//通过基类指针基类函数Show()
	poCP->Show(1);		//非虚函数时，通过基类指针可以调用被隐藏的基类Show()
						//虚函数时，形成覆盖关系，可以调用派生类的Show(1)
	system("PAUSE");						//等待键盘输入以实现暂停  
	return 0;								//返回0
}



