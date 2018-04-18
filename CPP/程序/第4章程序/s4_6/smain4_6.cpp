//主文件
//文件名：s4_6\smain4_6.cpp

#include "sclass4_6_student.h"		//包含类声明头文件

//主测试程序
int main()    
{
	CPerson *poCP = new CStudent;	//构造一个CStudent的动态对象
	if (NULL == poCP)				//如果new操作失败，则退出
	{
		exit(1);					//参数0表示非正常退出程序
	}
	delete poCP;					//通过基类指针销毁派生类对象
	cout << "通过delete析构new运算符创建的对象结束! \n" << endl; 

	CStudent oCSt;		//构造一个CStudent对象，不使用delete时，对象都能够正确析构

	return 0;						//返回0
}
