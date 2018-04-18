// 文件路径名:s6_2\smain6_2.cpp
#include <iostream>               			// 编译预处理命令
using namespace std;						// 使用命名空间std 

int sum = 0;								// 用于存储累加和

void Sum(int e)								// 累加求和
{
	sum = sum + e;							// sum累加e
}

template <class It, class Fun>
Fun &ForEach(const It &begin, const It &end, Fun &f)		// 遍历算法
{
	for (It it = begin; it != end; ++it)
	{	// 依次调用f()
		f(*it);								// 调用f() 
	}
	return f;								// 返回f
}

int main()									// 主函数main()
{
	int a[] = {1, 2, 3, 4, 5, 6};			// 定义数组a
	int n = 6;								// 元素个数
	int *begin = a;							// 开始
	int *end = a + n;						// 结束

	ForEach(begin, end, Sum);				// 调用遍历算法
	cout << "sum=" << sum << endl; 			// 输出累加和

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
