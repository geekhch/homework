// 文件路径名:a4_1\main.cpp
#include <iostream>               				// 编译预处理命令
using namespace std;							// 使用命名空间std 

class String
{
private:
// 数据成员
	char *strValue;								// 串值

public:
// 公有成员	
	String(char *s = "")						// 构造函数
	{
		if (s == NULL) s = "";					// 将空指针转化为空串
		strValue = new char[strlen(s) + 1];		// 分配存储空间
		strcpy(strValue, s);					// 复制串值
	}
	String(const String &copy)					// 复制构造函数
	{
		strValue = new char[strlen(copy.strValue) + 1];	// 分配存储空间
		strcpy(strValue, copy.strValue);		// 复制串值
	}
	String &operator=(const String &copy);		// 重载赋值运算符
	~String() { delete []strValue; }			// 析构函数
	void Show() const { cout << strValue <<  endl; }	// 显示串
	
};

String &String::operator=(const String &copy)	// 重载赋值运算符
{
	if (this != &copy)
	{	// 目的对象与源对象不是同一个对象
		delete []strValue;						// 释放存储空间
		strValue = new char[strlen(copy.strValue) + 1];	// 分配存储空间
		strcpy(strValue, copy.strValue);		// 复制串值
	}
	return *this;								// 返回目的对象
}

int main()										// 主函数main()
{
	String s1("try"), s2, s3(s1);				// 定义对象
	s2 = s1;									// 使用重载赋值运算符
	
	s1.Show();									// 显示串s1
	s2.Show();									// 显示串s2
	s3.Show();									// 显示串s3

	system("PAUSE");							// 调用库函数system( )，输出系统提示信息
	return 0;               					// 返回值0, 返回操作系统
}
