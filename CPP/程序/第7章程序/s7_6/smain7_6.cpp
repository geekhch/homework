// 文件路径名:s7_6\smain7_6.cpp
#include <iostream>               		// 编译预处理命令
using namespace std;					// 使用命名空间std 

char GetChar(istream &in = cin)			// 从输入流in中跳过空格获取一字符
{
	char ch;							// 字符变量
	
	while (in.peek() != EOF				// 未遇到文件结束符
		&& (ch = in.get()) == ' ');		// 输入的字符为空格
	
	return ch;							// 返回字符
}

int main()								// 主函数main()
{
	char ch;							// 字符变量
	double x;							// 双精度实型变量

	ch = GetChar();						// 跳过空格输入一个字符
	while (ch != '\n' && ch != EOF)
	{
		if (ch >= '0' && ch <= '9')
		{	// 是实数的开始字符
			cin.putback(ch);			// 将ch回送到输入流对象cin中
			cin >> x;					// 输入双精度实数x
			cout << x << " ";			// 输出双精度实数x
		}
		else
		{	// 非法字符
			cout << "出现非法字符!" << endl;
			exit(1);					// 退出程序
		}
		ch = GetChar();					// 跳过空格输入一个字符
	}
	cout << endl;						// 换行
	
	system("PAUSE");            		// 调用库函数system()，输出系统提示
	return 0;                    		// 返回值0, 返回操作系统
}

