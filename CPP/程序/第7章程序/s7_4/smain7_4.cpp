// 文件路径名:s7_4\smain7_4.cpp
#include <iostream>               		// 编译预处理命令
using namespace std;					// 使用命名空间std 

char GetChar(istream &in = cin)			// 从输入流in中跳过空格获取一字符
{
	char ch;							// 字符变量
	
	while (!in.eof()					// 未遇到文件结束符
		&& (ch = in.get()) == ' '); 	// 输入的字符为空格	

	return ch;							// 返回字符
}

int main()								// 主函数main()
{
	char ch;							// 字符变量

	cout << "请输入一行字符:" << endl;	// 输入提示
	ch = GetChar();						// 输入字符,自动跳过空格
	while (ch != '\n' && ch != EOF)		// ch != EOF可改为!cin.eof()
	{	
		cout.put(ch);					// 输出字符
		ch = GetChar();					// 输入字符,自动跳过空格
	}
	cout << endl;						// 换行
	
	system("PAUSE");            		// 调用库函数system()，输出系统提示
	return 0;                    		// 返回值0, 返回操作系统
}
