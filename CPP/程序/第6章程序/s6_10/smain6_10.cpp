// 文件路径名:s6_10\smain6_10.cpp
#include <iostream>               			// 编译预处理命令
#include <list>				         		// 编译预处理命令
using namespace std;						// 使用命名空间std 

int main()									// 主函数main()
{
	list<int> la;							// 定义链表对象

	for (int i = 1; i <= 6; i++)
	{	// 依次向线性表中插入值
		la.push_back(i);					// 向链表表尾追加i
	}

	// 正向显示链表
	for (list<int>::iterator it = la.begin(); it != la.end(); ++it)
	{	// 依次输出各元素的值
		cout << *it << " ";					// 输出*it
	}	
	cout << endl;							// 换行

	// 逆向显示链表
	for (list<int>::reverse_iterator rit = la.rbegin(); rit != la.rend(); ++rit)
	{	// 依次输出各元素的值
		cout << *rit << " ";				// 输出*rit
	}
	cout << endl;							// 换行
	
	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
