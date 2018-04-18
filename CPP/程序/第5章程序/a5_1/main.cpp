// 文件路径名:a5_1\main.cpp
#include <iostream>               					// 编译预处理命令
using namespace std;								// 使用命名空间std 

// 声明数组类模板
template <class Type>
class Array
{
private:
// 数据成员
	Type *elem;										// 存储数据元素值
	int size;										// 数组元素个数

public:
// 公有函数模板	
	Array(int sz): size(sz) { elem = new int[size]; }	// 构造函数模板
	~Array(){ delete []elem; }						// 析构函数
	Type &operator[](int i)							// 下标运算符"[]"只能重载为成员函数模板
	{
		if (i < 0 || i >= size)
		{
			cout << "元素位置错!" << endl;
			exit(1);								// 退出程序的行运,返回到操作系统
		}
		return elem[i];								// 返回elem[i]
	}
};

int main()											// 主函数main()
{
	int a[] = {1, 9, 7, 5, 6, 3};					// 定义数组a
	int n = 6;										// 数组元素个数
	Array<int> obj(n);								// 定义数组对象
	int i;											// 定义临时变量
	for (i = 0; i < n; i++) obj[i] = a[i];			// 设置数组元素值, obj[i]等价于obj.operator[i]
	for (i = 0; i < n; i++) cout << obj[i] << " ";	// 输出元素值, obj[i]等价于obj.operator[i]
	cout << endl;									// 换行

	system("PAUSE");								// 调用库函数system( )，输出系统提示信息
	return 0;               						// 返回值0, 返回操作系统
}
