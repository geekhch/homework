// 文件路径名:s7_1\smain7_1.cpp
#include <iostream>               	// 编译预处理命令
using namespace std;				// 使用命名空间std 

int main()							// 主函数main()
{
	char s[] = "Hello, world!";		// 定义字符串

	for (int i = 0; i < strlen(s); i++)	
		cout.put(s[i]);				// 输出第i+1个字符
	cout << endl;					// 换行
	
	system("PAUSE");            	// 调用库函数system()，输出系统提示
	return 0;                    	// 返回值0, 返回操作系统
}
