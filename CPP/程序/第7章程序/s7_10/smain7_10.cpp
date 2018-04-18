// 文件路径名:s7_10\smain7_10.cpp
#include <iostream>               		// 编译预处理命令
#include <fstream>               		// 编译预处理命令
using namespace std;					// 使用命名空间std 

int main()								// 主函数main()
{
	int a[] = {1, 5, 8, 10, 18, 98}, n = 6, x;	// 定义数组与整型变量
	fstream f;							// 定义文件对象
	
	f.open("test.dat", ios::out | ios::binary);	// 以输出方式打开文件
	if (f.fail())	
	{	// 打开文件失败
		cout << "打开文件失败!" << endl;
		exit(1);						// 退出程序
	}
	for (int i = 0; i < n; i++)
		f.write((char *)&a[i], sizeof(int));	// 写数据到文件中
	f.close();							// 关闭文件

	f.open("test.dat", ios::in | ios::binary);	// 以输入方式打开文件
	if (f.fail())	
	{	// 打开文件失败
		cout << "打开文件失败!" << endl;
		exit(2);						// 退出程序
	}
	f.read((char *)&x, sizeof(int));	// 从文件中读出数据到x
	while (!f.eof())
	{
		cout << x << " ";				// 输出x到显示器
		f.read((char *)&x, sizeof(int));	// 从文件中读出数据到x
	}
	cout << endl;						// 换行
	f.close();							// 关闭文件
	
	system("PAUSE");            		// 调用库函数system()，输出系统提示
	return 0;                    		// 返回值0, 返回操作系统
}
