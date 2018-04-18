// 文件路径名: s2_16\smain2_16.cpp
#include<iostream>   
using namespace std; 

class CDemo
{
public:
	CDemo(int ii=0):i(ii)
	{
		j=i;
	}
	static int Incr()					//定义一个静态成员函数实现对静态数据成员j的操作
	{
		return ++j;
	}
private:
	int i;       		      
	static int j;						//定义一个静态数据成员
};
int CDemo::j = 0;						//初始化静态数据成员
int main()
{	
	cout << "j=" << CDemo::Incr( ) << endl;   //通过类名访问静态成员函数
	return 0;
}
