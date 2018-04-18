// 文件路径名:s7_2\smain7_2.cpp
#include <iostream>               		// 编译预处理命令
using namespace std;					// 使用命名空间std 

int main()								// 主函数main()
{
	char ch;							// 定义字符变量

	cout << "输入一行字符:" << endl;	// 输入提示
	ch = cin.get();						// 输入字符
	while (ch != '\n')
	{	
		cout.put(ch);					// 输出字符
		ch = cin.get();					// 输入字符
	}
	cout << endl;						// 换行
	
	system("PAUSE");            		// 调用库函数system()，输出系统提示
	return 0;                    		// 返回值0, 返回操作系统
}
