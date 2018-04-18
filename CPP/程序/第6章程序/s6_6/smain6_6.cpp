// 文件路径名:s6_6\smain6_6.cpp
#include <iostream>               				// 编译预处理命令
#include <functional>               			// 编译预处理命令
using namespace std;							// 使用命名空间std 

int main()										// 主函数main()
{
	// 下面定义一些关系函数对象
	equal_to<int> objEqual;						// 定义等于函数对象
	not_equal_to<int> objNotEqual;				// 定义不等于函数对象
	greater<int> objGreat;						// 定义大于函数对象
	greater_equal<int> objGreatEqual;			// 定义大于等于函数对象
	less<int> objLess;							// 定义小于函数对象
	less_equal<int> objLessEqual;				// 定义小于等于函数对象
    
	// 下面运用上面定义的函数对象，实现相应的函数功能
	cout << objEqual(2, 6) << endl;				// 输出0
	cout << objNotEqual(2, 6) << endl;			// 输出1
	cout << objGreat(2, 6) << endl;				// 输出0
	cout << objGreatEqual(2, 6) << endl;		// 输出0
	cout << objLess(2, 6) << endl;				// 输出1
	cout << objLessEqual(2, 6) << endl;			// 输出1

	// 下面直接以生成的临时函数对象实现相关函数功能
	cout << equal_to<int>()(2, 6) << endl;		// 输出0
	cout << not_equal_to<int>()(2, 6) << endl;	// 输出1
	cout << greater<int>()(2, 6) << endl;		// 输出0
	cout << greater_equal<int>()(2, 6) << endl;	// 输出0
	cout << less<int>()(2, 6) << endl;			// 输出1
	cout << less_equal<int>()(2, 6) << endl;	// 输出1

	system("PAUSE");            				// 调用库函数system( )，输出系统提示信息
	return 0;                    				// 返回值0, 返回操作系统
}
