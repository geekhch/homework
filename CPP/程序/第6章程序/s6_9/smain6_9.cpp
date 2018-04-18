// 文件路径名:s6_9\smain6_9.cpp
#include <iostream>               			// 编译预处理命令
#include <string>	              			// 编译预处理命令
#include <list>			          			// 编译预处理命令
using namespace std;						// 使用命名空间std 
    
typedef list<string> StrList;				// 类型定义

int main()									// 主函数main()
{
	StrList la;								// 定义链表对象
	
	la.push_back("back");					// 向链表尾后插入"back"
	la.push_front("middle");				// 向链表首元素前插入"middle"
	la.push_front("front");					// 向链表首元素前插入"front"
    
	cout << la.front() << endl;				// 输出首元素"front"
	cout << *la.begin() << endl;			// 输出首元素"front"
	cout << la.back() << endl;				// 输出尾元素"back"
	cout << *la.rbegin() << endl;			// 输出尾元素"back"
	la.pop_front();							// 删除"front"
	la.pop_back();							// 删除"back"
	cout << la.front() << endl;				// 输出"middle"

	system("PAUSE");            			// 调用库函数system( )，输出系统提示信息
	return 0;                    			// 返回值0, 返回操作系统
}
