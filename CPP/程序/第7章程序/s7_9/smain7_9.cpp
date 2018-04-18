// 文件路径名:s7_9\smain7_9.cpp
#include <iostream>               	// 编译预处理命令
#include <fstream>               	// 编译预处理命令
using namespace std;				// 使用命名空间std 

int main()							// 主函数main()
{
	char s[318], fName[20];			// 字符串
	ifstream f;						// 文件流对象
	
	cout << "请输入文件名:";
	cin >> fName;					// 输入文件名
	f.open(fName);					// 打开文件
	if (f.fail())	
	{	// 打开文件失败
		cout << "打开文件失败!" << endl;
		exit(1);					// 退出程序
	}
	f.getline(s, 318);				// 从文件中输入一行字符
	while (!f.eof())
	{	// 文件末结束
		cout << s << endl;			// 输出一行字符
		f.getline(s, 318);			// 从文件中输入一行字符
	}
	f.close();						// 关闭文件
	
	system("PAUSE");            	// 调用库函数system()，输出系统提示
	return 0;                    	// 返回值0, 返回操作系统
}