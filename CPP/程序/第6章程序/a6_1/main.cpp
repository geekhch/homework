// 文件路径名:a6_1\main.cpp
#include <iostream>               				// 编译预处理命令
#include <string>               				// 编译预处理命令
using namespace std;							// 使用命名空间std 

int main()										// 主函数main()
{
   	string s("How are");						// 利用C风格串构造串对象
	s = s + " you?";							// 在字符串后连接" you?"
 	cout << s << endl;							// 输出s
	for (int i = s.size() - 1; i >= 0; i--)
	{	// 逆向依次输出字符
		cout << s[i];							// 输出字符s[i]
	}
	cout << endl;								// 换行

	system("PAUSE");            				// 调用库函数system( )，输出系统提示信息
	return 0;                    				// 返回值0, 返回操作系统
}
