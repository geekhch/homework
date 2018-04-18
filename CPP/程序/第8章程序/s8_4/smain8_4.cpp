//文件名：s8_4\smain8_4.cpp
//用构造函数完成基本类型到类类型的转换，只能带一个非缺省参数
//用类类型转换函数将类类型转换为基本数据类型。

#include <iostream>
#include <string>
using namespace std;

//声明并定义CFigure类
class CFigure
{ 
public:
	//只带一个参数（注：一个参数可以不用带缺省值），将基本类型转换为类类型
	CFigure(double d=0): m_value(d), m_name("anonymity"){}		// 构造函数1

	//只带有一个非缺省参数(其余参数必须带缺省值)，完成标准类型到类类型的转换
	CFigure(int a, string name="pseudonym"): m_value(a), m_name(name) {} //构造函数2

	// 将类类型转化为一个int
	operator int() const { return m_value; } 			//类类型转换函数

	// 将类类型转化为一个double
	operator double() const	{ return m_value; }			//类类型转换函数

	void Print() const { cout << m_name << ": " << m_value << endl;	}

private:
	double m_value;			//对象的值
	string m_name;			//对象名
};

//测试函数
int main()
{
	int a;
	double b;
	CFigure oCF(5);			//调用构造函数2，创建一个对象
	oCF.Print();			//输出：pseudonym:5
	oCF = 10;				//调用构造函数2，将一个整数转化为一个对象
	oCF.Print();			//输出：pseudonym:10
	a = int(oCF);			//调用operator int( )，可不用强制类型转换
	cout << "a=" << a <<endl;	//输出：a=10
	oCF = 12.128;			//调用构造函数1，将一个浮点数转化为一个对象
	oCF.Print();			//输出：anonymity:12.128
	b = oCF;				//调用operator double( ),不显示加强制类型转换也一样
	cout << "a=" << a << ", b=" << b << endl; //输出：a=12,b=12.128

	system("PAUSE");		//等待键盘输入以实现暂停  
	return 0;				//返回0
}