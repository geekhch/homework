// 文件路径名:s7_3\smain7_3.cpp
#include <iostream>               		// 编译预处理命令
using namespace std;					// 使用命名空间std 

int main()								// 主函数main()
{
	char s[256];						// 字符串

	cout << "输入一行字符:" << endl;	// 输入提示
	cin.getline(s, 8);					// 输入一行字符
	cout << s << endl;					// 输出一行字符
	
	system("PAUSE");            		// 调用库函数system()，输出系统提示
	return 0;                    		// 返回值0, 返回操作系统
}
