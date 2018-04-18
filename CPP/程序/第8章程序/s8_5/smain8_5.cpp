//文件名：s8_5\smain8_5.cpp
//异常示例

#include <iostream>
#include <string>
using namespace std;

class CMyException 							//定义异常类
{
public:
    CMyException(){}
    ~CMyException(){}
    const char *GetExceptionReason() const	//显示异常原因
	{ return "CMyException Exception."; }
};

class CDemo				//定义一个工作类，用以显示其执行与异常抛出的顺序
{
public:
    CDemo() { cout << "Constructing CDemo." << endl; }
    ~CDemo() { cout << "Destructing CDemo." << endl; }
};

//异常也可以多层封装，例如：在MyFunC()中封装throw、try、catch机制
//在这里捕获相关异常，本实例程序中在main()中进行了异常捕获处理
void MyFunc()												
{
    CDemo D;
    cout << "\nIn MyFunc(). Throwing CMyException exception." << endl;
    throw CMyException();				//抛出异常
}

int main()
{
    try									//用try封装可能会出现异常的代码
    {
        cout << "In try block, calling MyFunc()." << endl;
        MyFunc();
    }
    catch(CMyException E)				//一路捕获并处理异常
    {
        cout << "Caught: ";
        cout << E.GetExceptionReason() << endl;
    }
    catch(string str)					//二路捕获并处理异常
    {
        cout << "Caught some other exception: " << str << endl;
    }

	system("PAUSE");					//等待键盘输入以实现暂停  
	return 0;							//返回0
}

