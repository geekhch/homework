//主文件
//文件名：s4_8\smain4_8.cpp

#include "sclass4_8_addition.h"			//包含类声明头文件

//主测试程序
int main()    
{
	CAddition oCA;						//创建一个CAddition类的对象
	oCA.Add(250, 250);					//调用Add(int a, int b)
	oCA.Add("很多250加起来","====0");	//调用Add(string s1, string s2)
	oCA.Add(128.118, 128.218);			//调用Add(double d1, double d2)

	system("PAUSE");					//等待键盘输入以实现暂停  
	return 0;							//返回0
}