// 文件路径名: s2_7\smain 2_7.cpp

class CDemo
{
public:
	CDemo()
	{
		a = 0;
	}
	CDemo(int x=1)
	{
		a = x;
	}
private:
	int a;
};

int main()
{
	CDemo d1(10);		//调用带默认参数的构造函数，将数据成员a初始化为10
	// CDemo d2;		//既可以调用无参构造函数，又可以调用带默认参数的构造函数，出现歧义！
	return 0;
}
