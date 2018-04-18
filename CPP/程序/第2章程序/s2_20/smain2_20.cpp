//文件路径名: s2_20\smain2_20.cpp
#include<iostream>
using namespace std;

//定义Node（栈结点）类
class Node
{           
public:
	Node(int e, Node *p)
	{
		data = e;
		next = p;
	}
	//将Stack类声明为友元类，则Stack类的所有成员函数都成为本类的友元函数
	friend class Stack;    
private:
	int data;            			//结点值
	Node *next;      				//指向后继
};

//定义Stack（栈）类
class Stack
{           
 public:
	Stack() { top = NULL; }			//构造函数
	~Stack() { while (top != NULL) Pop(); }	//析构函数
	void Push(int e);    			//入栈操作
	int Pop();           			//出栈操作
private:
	Node *top;             			//头指针
};

//入栈
void Stack::Push(int e)              
{
	Node *p = new Node(e, top); 
	top = p;
}
//出栈
int Stack::Pop()
{
	Node *p = top;
	if (top != NULL)
	{
		top = top->next;
		int e = p->data;
		delete p;
		return e;
	}
	else
	{
		cout <<"栈已空!" << endl;
		return 0;
	}
}

int main()
{
	Stack s;					//建立一个栈类对象
	// 入栈操作
	s.Push(1);
	s.Push(2);
	s.Push(3);
	// 出栈操作
	for (int i = 0; i < 3; i++)
	{
		cout << s.Pop( ) << "  ";
	}
	cout << endl;
	return 0;
}
