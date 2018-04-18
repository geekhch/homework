// 文件路径名:a4_2\main.cpp
#include <iostream>               				// 编译预处理命令
using namespace std;							// 使用命名空间std 

// 声明复数数
class Complex
{
private:
// 数据成员
	double real;								// 实部
	double image;								// 虚部

public:
// 公有函数	
	Complex(double r = 0, double i = 0): real(r), image(i){ }			// 构造函数
	double GetReal() const { return real; }		// 返回实部
	double GetImage() const { return image; }	// 返回虚部
	void SetReal(double r) { real = r; }			// 设置实部
	void SetImage(double i) { image = i; }		// 设置虚部
};

istream &operator>>(istream &in, Complex &z)	// 重载输入运算符">>"
{
	double r, i;								// 表示实部(r)和虚部(i)
	cout << "输入实部:";
	in >> r;									// 输入实部
	cout << "输入虚部:";
	in >> i;									// 输入虚部
	z.SetReal(r);								// 设置实部
	z.SetImage(i);								// 设置虚部
	return in;									// 返回输入流对象
}

ostream &operator<<(ostream &out, const Complex &z)						// 重载输出运算符"<<"
{
	if (z.GetImage() < 0) cout << z.GetReal() << z.GetImage() << "i";	// 虚部为负
	else if (z.GetImage() == 0) cout << z.GetReal();					// 虚部为0
	else cout << z.GetReal() << "+" << z.GetImage() << "i";				// 虚部为正
	return out;									// 返回输出流对象
}

int main()										// 主函数main()
{
	Complex z;									// 定义复数对象
	cin >> z;									// 输入z, cin >> z等价于operator>>(cin, z)
	cout << z << endl;							// 输出z, cout << z等价于operator<<(cout, z)

	system("PAUSE");							// 调用库函数system( )，输出系统提示信息
	return 0;               					// 返回值0, 返回操作系统
}
