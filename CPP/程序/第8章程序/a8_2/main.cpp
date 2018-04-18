// 文件路径名:a8_2\main.cpp
#include <iostream>		// 编译预处理命令
using namespace std;	// 使用命名空间std 

namespace MyName		// 命名空间MyName
{ 
	int x = 10;			// 命名空间MyName中的变量x
}

namespace				// 无名命名空间
{ 
	int x = 20;			// 无名命名空间中的变量x
}

int main()				// 主函数main()
{
	cout << "命名空间MyName中的变量x:" << MyName::x << endl;
	cout << "无名命名空间中的变量x:" << x << endl;
	
	system("PAUSE");	// 输出系统提示并返回操作系统
	return 0;        	// 返回值0, 返回操作系统
}
