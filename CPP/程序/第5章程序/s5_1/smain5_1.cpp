//s5_1\smain5_1.cpp
//通过模板实现求三个不太能够类型数中最大的一个

#include <iostream>
#include <string>

using namespace std;

//定义函数模板
template <class Type>
Type GetMax(Type a, Type b, Type c)
{
	Type t;
	t = a>b ? a:b;			//求a和b的较大者
	return t>c ? t:c;		//返回a、b、c的最大者。
}

//主函数
int main()    
{
	string str1("Rong Ji"), str2("Zhe Ming"), str3("Jing Tao");
	//使用函数模板
	cout << "int:10, 30, 21, max=" << GetMax(10, 30, 21) << endl;
	cout << "double:51.8,20.8,31.6,max="<<GetMax(51.8,20.8,31.6)<<endl; 
	cout << "char:'A','b','Z',max="<<GetMax('A','b','Z')<<endl; 
	cout << "string: str1(\"Rong Ji\"), str2(\"Zhe Ming\"), str3(\"Jing Tao\")," 
		"max=" << GetMax(str1,str2,str3) << endl;	//注：两个字符串的自然连接	
	//cout << "'A','b',97,max="<<GetMax('A','b',97)<<endl; //出错，函数模板类型参数不具有隐式类型转换的作用

	system("PAUSE");		//等待键盘输入以实现暂停  
	return 0;				//返回0
}

