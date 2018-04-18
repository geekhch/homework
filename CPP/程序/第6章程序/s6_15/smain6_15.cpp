// 文件路径名:s6_15\smain6_15.cpp
#include <iostream>               			// 编译预处理命令
#include <vector>						  	// 编译预处理命令
#include <algorithm>			          	// 编译预处理命令
using namespace std;						// 使用命名空间std 

void ShowCube(int n)						//  显示参数及相应的立方
{
	cout << n << ":\t" << n * n * n << endl;// 输出相关信息
}

int main()									// 主函数main()
{
	int n = 8;								// 元素个数
	vector<int> v(n);						// 定义大小为n的向量

	for (int i = 0; i < n; ++i)
	{	// 通过数组方式为向量元素赋值
		v[i] = i + 1;
	}

	cout << "i:\ti*i*i" << endl;			// 输出提示
	for_each(v.begin(), v.end(), ShowCube);	// 输出v的每个元素及其相应的立方

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
