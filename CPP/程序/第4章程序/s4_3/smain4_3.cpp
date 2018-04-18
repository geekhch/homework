//主文件
//文件名：s4_3\smain4_3.cpp

#include "sclass4_3_CShape.h"				//包含类声明头文件

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
	CRectangle oCR(1.1, 1.2, 1.3, 5.4, 5.5);//创建一个CRectangle类的对象
	CSquare oCSq(2.2, 2.3, 2.4, 10.8);		//创建一个CSquare类的对象

	cout<<"\n 1 : -通过基类的引用调用虚函数具有虚特性----。"<<endl;
	Reference(oCS);							//以基类CShape对象作引用参数
	Reference(oCC);							//以派生类CCircle对象作引用参数
	Reference(oCR);							//以派生类CRectangle对象作引用参数
	Reference(oCSq);						//以派生类CSquare对象作引用参数

	cout<<"\n 2 : -通过基类的指针调用虚函数具有虚特性----。"<<endl;
	CShape *poCS;							//定义基类CShape的指针变量
	poCS = &oCS;							//基类指针指向基类对象oCS
	poCS->Show();							//通过基类指针调用基类的Show( )函数
	poCS = &oCC;							//基类基类指针指向派生类对象oCC
	poCS->Show();							//通过基类指针调用派生类的Show( )函数
	poCS = &oCR;							//基类指针指向基类对象oCR
	poCS->Show();							//通过基类指针调用基类的Show( )函数
	poCS = &oCSq;							//基类基类指针指向派生类对象oCSq
	poCS->Show();							//通过基类指针调用派生类的Show( )函数

	cout<<"\n 3 : -通过对象调用不具有虚特性，但调用正确----。"<<endl;
	oCS.Show();								//直接通过基类对象oCS调用Show( )函数
	oCC.Show();								//直接通过派生类对象oCC调用Show( )函数
	oCR.Show();								//直接通过派生类对象oCR调用Show( )函数
	oCSq.Show();							//直接通过派生类对象oCSq调用Show( )函数

	system("PAUSE");						//等待键盘输入以实现暂停  
	return 0;								//返回0
}
