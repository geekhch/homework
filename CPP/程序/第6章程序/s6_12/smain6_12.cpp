// 文件路径名:s6_12\smain6_12.cpp
#include <iostream>               			// 编译预处理命令
#include <deque>							// 编译预处理命令
using namespace std;						// 使用命名空间std 
    
int main()									// 主函数main()
{
	deque<int> q;							// 定义双端队列对象
	deque<int>::iterator it;				// 定义迭代器
	int a[] = {5, 1, 8, 18, 16, 19}, n = 6, i, e;	// 定义数组及整型变量

	for (i = 0; i < n; ++i)
	{	// 依次向双端队列中插入a[i]
		q.push_back(a[i]);					// 向双端队列尾追加a[i]
	}

	for (it = q.begin(); it != q.end(); ++it)		// 显示双端队列
	{	// 依次输出各元素的值
		cout << *it << " ";					// 输出*it
	}
	cout << endl;							// 换行

	q.clear();								// 清空双端队列
	for (i = 0; i < n; ++i)
	{	// 依次向双端队列中插入a[i]
		q.push_front(a[i]);					// 向双端队列首部插入a[i]
	}

	for (it = q.begin(); it != q.end(); ++it)		// 显示双端队列
	{	// 依次输出各元素的值
		cout << *it << " ";					// 输出*it
	}
	cout << endl;							// 换行

	q.pop_front();							// 删除首元素
	cout << q.front() << endl;				// 输出新首元素

	q.pop_back();							// 删除尾元素
	cout << q.back() << endl;				// 输出新尾元素

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
