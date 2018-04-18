// 文件路径名:s6_19\smain6_19.cpp
#include <iostream>            				// 编译预处理命令
#include <algorithm>						// 编译预处理命令
using namespace std;						// 便用命名空间std 

template <class It>
void Show(const It &begin, const It &end)	// 泛型显示
{
	for (It it = begin; it!= end; ++it)
	{	// 依次显示各元素
		cout << *it << " ";
	}
	cout << endl;							// 换行
}

int main()									// 主函数main()
{
	int a[] = {1, 8, 6, 9, 5, 18};			// 定义数组
	int n = sizeof(a) / sizeof(int);		// 元素个数
	int *begin = a;							// 开始
	int *end = a + n;						// 结束

	cout << "排序前:";						// 输出提示
	Show(begin, end);						// 输出数组各元素值
	sort(begin, end);						// 排序
	cout << "排序后:";						// 输出提示
	Show(begin, end);						// 输出数组各元素值

	system("PAUSE");						// 调用库函数system( )，输出系统提示信息
	return 0;               				// 返回值0, 返回操作系统
}
