// 文件路径名:s6_13\smain6_13.cpp
#include <iostream>               			// 编译预处理命令
#include <deque>				          	// 编译预处理命令
#include <stack>			          		// 编译预处理命令
using namespace std;						// 使用命名空间std 

int main()									// 主函数main()
{
	stack<int> s;							// 定义栈对象
	for(int i = 1; i <= 5; ++i)
	{	// 依次入栈
		s.push(i);							// i入栈
	}
    
	cout << "栈s:";							// 输出提示
	while (!s.empty())
	{	// 栈s非空
		cout << s.top() << " ";				// 输出栈顶
		s.pop();							// 出栈
	}
	cout << endl;							// 换行

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
