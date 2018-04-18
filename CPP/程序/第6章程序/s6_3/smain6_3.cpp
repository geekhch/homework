// 文件路径名:s6_3\smain6_3.cpp
#include <iostream>               			// 编译预处理命令
using namespace std;						// 使用命名空间std 

// 这义累加求和类
class Sum
{
private:
// 数据成员:
	int sum;								// 用于存储累加和

public:
// 公有成员:
	Sum(): sum(0) {}						// 构造函数
	void operator()(int e)					// 重载函数运算符
	{
		sum = sum + e;						// sum累加e
	}
	int GetSum() const						// 求累加和
	{
		return sum;							// 返回累加和sum
	}
};

template <class It, class Fun>
Fun &ForEach(const It &begin, const It &end, Fun &f)	// 遍历算法
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
	
	Sum &objSum = ForEach(begin, end, Sum());				// 定义函数对象引用，并调用遍历算法
	cout << "sum=" << objSum.GetSum() << endl;				// 输出累加和

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
