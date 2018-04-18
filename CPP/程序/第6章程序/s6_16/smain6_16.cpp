// 文件路径名:s6_16\smain6_16.cpp
#include <iostream>               		// 编译预处理命令
#include <vector>			          	// 编译预处理命令
#include <algorithm>			        // 编译预处理命令
using namespace std;					// 使用命名空间std 

// 定义类GetInfo
class GetInfo
{
private:
// 数据成员:
	int sum;							// 和
	int max;							// 最大值
	int min;							// 最小值
	int count;							// 元素个数

public:
// 公有函数:
	GetInfo(): sum(0), count(0) {}		// 构造函数
	int GetSum() const					// 获得最大值
	{
		return sum;						// 返回和sum
	}
	int GetMax() const					// 获得最大值
	{
		return max;						// 返回最大值max
	}
	int GetMin() const					// 获得最小值
	{
		return min;						// 返回最小值sum
	}
	void operator()(int e)				// 重载单参数的函数运算符
	{
		count++;						// 元素个数自加1
		sum = sum + e;					// 累加求和
		if (count == 1)
		{	// e为第一个元素
			max = min = e;				// 只有一个元素e时，最大值与最小值都为e
		}
		else
		{	// 有多个元素
			if (max < e)
			{	// e为当已求的最大值
				max = e;				// 将e赋值给max
			}
			else if (min > e)
			{	// e为当前已求的最小值
				min = e;				// 将e赋值给min
			}
		}
	}
};

int main()								// 主函数main()
{
	int a[] = {1, 4, 2, 8, 5, 6};		// 定义数组
    	int n = sizeof(a) / sizeof(int);// 数组元素个数
	int *begin = a;						// 开始
	int *end = a + n;					// 结束	

	GetInfo objGetInfo = for_each(begin, end, GetInfo());
		// 定义函数对象，通过for_each()算法进行初始化
	cout << "总和是:" << objGetInfo.GetSum() << endl;		// 输出总和
	cout << "最大值:" << objGetInfo.GetMax() << endl;		// 输出最大值
	cout << "最小值:" << objGetInfo.GetMin() << endl;		// 输出最小值

	system("PAUSE");            		// 调用库函数system( )，输出系统提示信息
	return 0;                    		// 返回值0, 返回操作系统
}
