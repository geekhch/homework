// 文件路径名:s6_1_2\smain6_1_2.cpp
#include <iostream>            				// 编译预处理命令
using namespace std;						// 便用命名空间std 

// 定义数组类模板
template <class Type>
class Array
{
private:
// 数据成员:
	Type *elem;								// 存储数据元素值
	int maxSize;							// 数组最多元素个数
	int size;								// 数组当前元素个数

public:
// 公有函数模板:	
	Array(int sz = 3): maxSize(sz), size(0)	// 构造函数模板
	{ 
		elem = new Type[maxSize];			// 分配存储空间
	}	
	virtual ~Array()						// 析构函数模板
	{ 
		delete []elem;						// 释放存储空间
	}				
	void Append(const Type &e)				// 向末尾追加元素
	{
		if (size >= maxSize)
		{	// 数组已满，必须扩容
			Type *tmpElem = new Type[maxSize *= 2];	// 分配存储空间
			for (int i = 0; i < size; i++)
			{	// 复制元素值
				tmpElem[i] = elem[i];		// 将elem的元素值复制到tmpElem的相应元素
			}
			delete []elem;					// 释放存储空间
			elem = tmpElem;					// 使elem指向新分配的存储空间
		}
		elem[size++] = e;					// 向末尾追加元素
	}
	Type *Begin() const						// 返回开始
	{
		return elem;	
	}
	Type *End()	const						// 返回结束
	{	
		return elem + size;	
	}
};

// 定义数组迭代器类模板
template <class Type>
class ArrayIterator
{
private:
// 数据成员:
	Type *itPtr;							// 迭代器本质是对Type *的封装
	
public:
// 公有函数模板:
	ArrayIterator(Type *p): itPtr(p) { } 	// 构造函数模板
	bool operator != (const ArrayIterator &it) const	// 重载"!="关系运算符
	{
		return this->itPtr != it.itPtr;		// 返回值
	}
	ArrayIterator operator++()				// 重载前缀"++"运算符
	{
		return itPtr++;						// itPtr指向下一元素，并返回		
	}
	Type operator*() const					// 重载"*"指针间接引用运算符
	{
		return *itPtr;						// 返回itPtr指向的值
	}
};

template <class It>
void Show(It begin, It end)					// 泛型显示
{
	for (It it = begin; it!= end; ++it)
	{	// 依次显示各元素
		cout << *it << " ";
	}
	cout << endl;							// 换行
}

int main()									// 主函数main()
{
	int a[] = {1, 2, 3, 4, 5, 6};			// 定义C数组a
	int n = 6;								// 数组元素个数
	Array<int> arr;							// 定义数组对象
	int i;									// 定义临时变量

	for (i = 0; i < n; i++)
		arr.Append(a[i]);					// 向末尾追加元素

	ArrayIterator<int> begin(arr.Begin());	// 定义begin
	ArrayIterator<int> end(arr.End());		// 定义end
	cout << "数组元素:";					// 输出提示
	Show(begin, end);						// 显示数组

	system("PAUSE");						// 调用库函数system( )，输出系统提示信息
	return 0;               				// 返回值0, 返回操作系统
}
