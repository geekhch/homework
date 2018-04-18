//文件名：s3_10\smain3_10.cpp
#include <iostream>  
using namespace std; 

// 定义基类Base1
class Base1
{
public:
	Base1(){cout <<"class Base1"<<endl; }		//构造函数
};

// 定义基类Base2
class Base2
{
public:
	Base2() { cout <<"class Base2"<<endl; }		//构造函数
};

// 定义派生类Level1，使其拥有两个基类Base1和Base2，
// 其中指定Base1在其继承路径中为虚基类
class Level1: public Base2, virtual public Base1
{
public:
	Level1() { cout <<"class Level1"<<endl; }	//构造函数
};

// 定义派生类Level2
// Level2和Level1拥有共同的两个基类，并且基类Base1在Level2的继承路径中也为虚基类
class Level2: public Base2, virtual public Base1
{
public:
	Level2() { cout << "class Level2" <<endl; }      //构造函数
};

//定义派生类Leaf
//派生类Level2和Level1共同派生出Leaf类，并声明Level2为虚基类
class Leaf: public Level1, virtual public Level2
{
public:
	Leaf() { cout << "class Leaf" <<endl; }
};

// 测试程序
int main()
{
	Leaf obj;  //创建一个派生类Leaf的对象
	return 0;
}
