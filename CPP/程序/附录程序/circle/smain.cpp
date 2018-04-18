// 文件名:smain.cpp
#include <iostream>               				// 编译预处理命令
using namespace std;							// 使用命名空间std 
#include "sclass_ccircle.h"						// 圆的类构造头文件

// 已知半径显示圆面积
int main()										// 主函数main()
{
	double r, area;								// 半径与面积
	CCircle c;									// 圆对象
	
	cout << "请输入圆半径:";					// 输入提示
	cin >> r;									// 输入圆半径
	c.SetRadius(r);								// 设置圆半径
	area = c.GetArea();							// 求圆面积
   	cout << "圆面积是" << area << " ." << endl;	// 显示圆面积

	return 0;									// 返回值0, 返回操作系统
}
