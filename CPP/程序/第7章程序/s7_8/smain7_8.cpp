// 文件路径名:s7_8\smain7_8.cpp
#include <iostream>               	// 编译预处理命令
#include <fstream>               	// 编译预处理命令
using namespace std;				// 使用命名空间std 

int main()							// 主函数main()
{
	char ch;						// 字符变量 
	ofstream outFile("test.txt");	// 定义输出文件对象,默认以输出方式打开文件
	if (outFile.fail())	
	{	// 打开文件失败
		cout << "打开文件失败!" << endl;
		exit(1);					// 退出程序
	}
	cout << "输入一行文字:" << endl;
	ch = cin.get();					// 输入一个字符ch
	while (ch != '\n')
	{
		outFile.put(ch);			// 将ch输出到文件中
		ch = cin.get();				// 输入一个字符ch
	}
	outFile.close();				// 关闭文件

	int letters = 0;				// 字母个数
	ifstream inFile("test.txt");	// 定义输入文件对象,默认以输入方式打开文件
	if (inFile.fail())	
	{	// 打开文件失败
		cout << "打开文件失败!" << endl;
		exit(2);					// 退出程序
	}
	ch = inFile.get();				// 从文件中输入一个字符ch
	while (!inFile.eof())
	{	// 文件末结束
		if (ch >= 'a' && ch <= 'z')
			letters++;				// 对英文小写字母进行记数
		ch = inFile.get();			// 从文件中输入一个字符ch
	}
	cout << "共有英文小写字母" << letters << "个" << endl;
	inFile.close();					// 关闭文件
	
	system("PAUSE");            	// 调用库函数system()，输出系统提示
	return 0;                    	// 返回值0, 返回操作系统
}


