// 文件路径名:s6_8\smain6_8.cpp
#include <iostream>               			// 编译预处理命令
#include <vector>	        				// 编译预处理命令
using namespace std;						// 使用命名空间std 

int main()									// 主函数main()
{
	vector<int> v;							// 定义向量
	int a[] = {1, 2, 3, 4, 5}, n = 5, i;	// 定义数组及整型变量

	for(i = 0; i < n; ++i)
	{	// 依次向v添加元素
		v.push_back(a[i]);					// 通过push_back()函数添加元素
	}

	n = v.size();							// 获得向量元素个数
	cout << "通过数组方式输出:" << endl;	// 输出提示
	for(i = 0; i < n; ++i)
	{	// 依次输出各元素
		cout<< v[i] << " ";					// 输出v[i]
	}
	cout << endl;							// 换行

	cout << "通过获得引用输出:" << endl;	// 输出提示
    for(i = 0; i < n; ++i)
	{	// 依次输出各元素
		int &e = v.at(i);					// 定义引用	
		cout << e << " ";					// 输出e
	}
	cout << endl;							// 换行

    cout << "通过迭代器输出:" << endl;		// 输出提示
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{	// 依次输出各元素
		cout << *it << " ";					// 输出*it
	}
	cout << endl;							// 换行

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
