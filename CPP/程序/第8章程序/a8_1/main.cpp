// 文件路径名:a8_1\main.cpp
//#include <iostream>		// 编译预处理命令，此处有Bug
//using namespace std;		// 使用命名空间std，此处有Bug 
#include <iostream.h>		// 编译预处理命令
#include <stdlib.h>			// 编译预处理命令

void *operator new(size_t size)		// 全局new重载函数
{	// typedef unsigned int size_t;
	cout << "调用全局operator new(size_t)重载函数" << endl;
	return malloc(size == 0 ? 1 : size);
}

void *operator new(size_t size, char *s)	// 全局new重载函数
{	// typedef unsignedf int size_t;
	cout << s << "调用全局operator new(size_t, char *)重载函数" << endl;
	return malloc(size == 0 ? 1 : size);
}

void operator delete (void *ptr)	// 全局operator delete重载函数
{ if(ptr != NULL) free(ptr); }

class Test 
{
public:
	void* operator new(size_t size)// 类Test的new重载函数
	{	
		if (size != sizeof(Test)) { cout << "内存分配异常!" << endl; exit(1); }
		cout << "调用类Test的operator new(size_t)重载函数" << endl;
		return malloc(size == 0 ? 1 : size);
	}

	void operator delete (void *ptr, size_t size)// 类Test的operator delete(void *, size_t)重载函数
	{	
		if (size != sizeof(Test)) { cout << "内存释放异常!" << endl; exit(2); }
        if(ptr != NULL) free(ptr);
    }
};

int main()					// 主函数main()
{
	int *p1 = new int;		// 调用全局operator new(size_t)重载函数
	delete p1;				// 调用全局operator delete(void *)重载函数
	int *p2 = new("Hello,")int;	// 调用全局operator new(size_t, char *)重载函数
	delete p2;				// 调用全局operator delete(void *)重载函数
	Test *p3 = new Test;	// 调用类Test的operator new(size_t)重载函数
	delete p3;				// 调用类Test的operator delete(void *, size_t)重载函数
	
	system("PAUSE");		// 输出系统提示并返回操作系统
	return 0;        		// 返回值0, 返回操作系统
}
