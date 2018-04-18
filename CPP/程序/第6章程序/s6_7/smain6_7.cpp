// 文件路径名:s6_7\smain6_7.cpp
#include <iostream>               					// 编译预处理命令
#include <functional>               				// 编译预处理命令
using namespace std;								// 使用命名空间std 

int main()											// 主函数main()
{
	// 下面定义一些逻辑函数对象
	logical_and<int> objAnd;						// 定义逻辑与函数对象
	logical_or<int> objOr;							// 定义逻辑或函数对象
	logical_not<int> objNot;						// 定义逻辑非函数对象
    
	// 下面运用上面定义的函数对象，实现相应的函数功能
	cout << objAnd(true, true) << endl;				// 输出1
	cout << objOr(true, false) << endl;				// 输出1
	cout << objNot(true) << endl;					// 输出0

	// 下面直接以生成的临时函数对象实现相关函数功能
	cout << logical_and<int>()(true, true) << endl;	// 输出1
	cout << logical_or<int>()(true, false) << endl;	// 输出1
	cout << logical_not<int>()(true) << endl;		// 输出0

	system("PAUSE");            					// 调用库函数system( )，输出系统提示信息
	return 0;                    					// 返回值0, 返回操作系统
}
