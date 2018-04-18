// 文件路径名:s6_17\smain6_17.cpp
#include <iostream>               			// 编译预处理命令
#include <vector>			          		// 编译预处理命令
#include <algorithm>			          	// 编译预处理命令
using namespace std;						// 使用命名空间std 

int main()									// 主函数main()
{
	int a[] = {1, 4, 2, 8, 5, 6};			// 定义数组
    	int n = sizeof(a) / sizeof(int);	// 数组元素个数
	int *begin = a;							// 开始
	int *end = a + n;						// 结束	
	int e = 8;								// 元素值

	int *p = find(begin, end, e);			// 指向首次元素值为e的数组元素的指针
	if (p != end) cout << "元素值为" << e << "的元素的下标为" << p - a << endl;	// 查找成功，输出相关信息
	else cout << "查找失败" << endl;		// 查找失败

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
