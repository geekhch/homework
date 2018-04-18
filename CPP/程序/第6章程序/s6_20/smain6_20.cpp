// 文件路径名:s6_20\smain6_20.cpp
#include <iostream>            				// 编译预处理命令
#include <vector>							// 编译预处理命令
#include <functional>						// 编译预处理命令
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
	vector<int> v(n);						// 定义向量对象

	for (int i = 0; i < n; ++i)
	{	// 依向插入向量元素赋值
		v[i] = a[i];						// 将a[i]赋值给v[i]
	}

	cout << "排序前:";						// 输出提示
	Show(v.begin(), v.end());				// 输出数组各元素值
	sort(v.begin(), v.end(), greater<int>());// 降序排序
	cout << "排序后:";						// 输出提示
	Show(v.begin(), v.end());				// 输出数组各元素值

	system("PAUSE");						// 调用库函数system( )，输出系统提示信息
	return 0;               				// 返回值0, 返回操作系统
}
