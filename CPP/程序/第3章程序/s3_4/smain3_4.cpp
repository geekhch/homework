//文件名：s3_4\smain3_4.cpp
#include <iostream> 
#include <string>
using namespace std; 

// 定义基类：CBase
class CBase
{
public:
   	CBase() { n = 0; m = 0; }	//构造函数
	void SetValue(int a, int b) //为数据成员m和n赋值
	{
		n = a;
		m = b;
	}
	void CalcuValue()			//用于计算的接口，并将计算结果显示在屏幕上   
	{ 
	cout << "n×m ＝ " << m*n << endl; 
	}
protected:
	int m;						//保护成员
	int n;						//保护成员 
};

//定义派生类：CDerived。为其指定基类CBase及继承方式CBase。
class CDerived : protected CBase 
{
public:
	CDerived() {}
	void SetJ(int j)
	{
		this->j =j+m;				//派生类成员可以访问基类的保护数据m
	}
	void SetK(int k)
	{
		this->k = k;
	}
	void DisplayVal() const
	{
		cout << "派生类成员j ＝ " << j << endl;
		cout << "派生类成员k ＝ " << k << endl;
	}
private:
	int j;
	int k;
};
// 测试程序
int main()
{
	CDerived d;             //创建派生类对象d		
	//d.SetValue(10,20);    //错误，因为SetValue( )已变成CDerived类的保护成员，类外不能访问
	//d.CalcuValue();		//错误，因为CalcuValue ( )已变成CDerived类的保护成员，类外不能访问
	d.SetJ(10);				//正确，因为d调用本类的公有成员函数
	d.SetK(15);				//正确，因为d调用本类的公有成员函数
	d.DisplayVal();			//正确，因为d调用本类的公有成员函数
	CBase b;                //创建基类对象b
	b. SetValue(10,20);     //正确，因为b可以在类外访问本类的公有成员函数SetValue
	b. CalcuValue();		//正确，因为b可以在类外访问本类的公有成员函数CalcuValue
	return 0;
}
