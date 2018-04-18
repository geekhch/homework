// 文件路径名:s6_1_1\smain6_1_1.cpp
#include <iostream>               		// 编译预处理命令
using namespace std;					// 使用命名空间std 

void Show(int *begin, int *end)			// 显示
{
	for (int *it = begin; it != end; ++it)
	{	// 依次显示各元素
		cout << *it << " ";
	}
	cout << endl;						// 换行
}

int main()								// 主函数main()
{
	int a[] = {1, 2, 3, 4, 5, 6};		// 定义C数组a
	int n = 6;							// 元素个数
	int *begin = a;						// 开始
	int *end = a + n;					// 结束

	Show(begin, end);					// 显示

	system("PAUSE");            		// 调用库函数system( )，输出系统提示并返回操作系统
	return 0;                    		// 返回值0, 返回操作系统
}
