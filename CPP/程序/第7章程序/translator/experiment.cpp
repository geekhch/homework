#include <iostream>						// 预处理命令
using namespace std;					// 使用标准命名空间std

int main()								// 主函数main()
{
	double s = 0, a[] = {1, 2, 3, 4, 5, 6};	// 定义变量s与数组a
	
	int _i0001 = 0;
	for ( double v = a[0];
		_i0001 < sizeof(a) / sizeof(a[0]);
		_i0001++, v = a[_i0001]) s += v;		// 测试foreach循环
	cout << "数组a的各元素之和为" << s << endl;

    system("PAUSE");            		// 调用库函数system( )，输出系统提示
    return 0;                    		// 返回值0,返回操作系统
}
