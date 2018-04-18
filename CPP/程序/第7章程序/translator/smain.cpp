// 文件路径名: translator\smain.cpp 
#include "sclass_ctranslator.h"				// 译码器
#include <iostream>               			// 编译预处理命令
using namespace std;						// 使用命名空间std 

int main()
{
	string infName, outfName;				// 文件名
	char ch;								// 字符变量

	cout << "请输入文件名(缺省: experiment.exp):";
	if ((ch = cin.get()) == '\n') 
	{
		infName = "experiment.exp";			// 直接输入回车，表示缺省文件名
	}
	else 
	{
		cin.putback(ch);					// 将其他字符ch回送输入流
		cin >> infName;						// 输入文件名
	}

	cout << "请输出文件名(缺省: experiment.cpp):";
	if ((ch = cin.get()) == '\n') 
	{
		outfName = "experiment.cpp";		// 直接输入回车，表示缺省文件名
	}
	else 
	{
		cin.putback(ch);					// 将其他字符ch回送输入流
		cin >> outfName;					// 输入文件名
	}

	CTranslator objTrans(infName, outfName);// 译码器对象
	objTrans.Run();							// 运行译码器

	system("PAUSE");            			// 调用库函数system()，输出系统提示
	return 0;                    			// 返回值0, 返回操作系统
}

