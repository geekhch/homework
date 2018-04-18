// 文件路径名:s6_11\smain6_11.cpp
#include <iostream>               			// 编译预处理命令
#include <list>				         		// 编译预处理命令
using namespace std;						// 使用命名空间std 

int main()									// 主函数main()
{
	list<int> la;							// 定义链表对象
	list<int>::iterator it;					// 定义迭代器
	int a[] = {1, 6, 3, 5, 4, 2}, n = 6;	// 定义数组及整型变量

	for (int i = 0; i < n; ++i)
	{	// 依次向线性表中插入a[i]
		la.push_back(a[i]);					// 向链表表尾追加a[i]
	}

	for (it = la.begin(); it != la.end(); ++it)		// 显示链表
	{	// 依次输出各元素的值
		cout << *it << " ";					// 输出*it
	}
	cout << endl;							// 换行

	la.reverse();							// 反转链表元素顺序
	for (it = la.begin(); it != la.end(); ++it)		// 显示链表
	{	// 依次输出各元素的值
		cout << *it << " ";					// 输出*it
	}
	cout << endl;							// 换行

	la.sort();								// 升序排序链表
	for (it = la.begin(); it != la.end(); ++it)		// 显示链表
	{	// 依次输出各元素的值
		cout << *it << " ";					// 输出*it
	}
	cout << endl;							// 换行

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
