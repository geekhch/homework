//�ļ�·����: s2_20\smain2_20.cpp
#include<iostream>
using namespace std;

//����Node��ջ��㣩��
class Node
{           
public:
	Node(int e, Node *p)
	{
		data = e;
		next = p;
	}
	//��Stack������Ϊ��Ԫ�࣬��Stack������г�Ա��������Ϊ�������Ԫ����
	friend class Stack;    
private:
	int data;            			//���ֵ
	Node *next;      				//ָ����
};

//����Stack��ջ����
class Stack
{           
 public:
	Stack() { top = NULL; }			//���캯��
	~Stack() { while (top != NULL) Pop(); }	//��������
	void Push(int e);    			//��ջ����
	int Pop();           			//��ջ����
private:
	Node *top;             			//ͷָ��
};

//��ջ
void Stack::Push(int e)              
{
	Node *p = new Node(e, top); 
	top = p;
}
//��ջ
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
		cout <<"ջ�ѿ�!" << endl;
		return 0;
	}
}

int main()
{
	Stack s;					//����һ��ջ�����
	// ��ջ����
	s.Push(1);
	s.Push(2);
	s.Push(3);
	// ��ջ����
	for (int i = 0; i < 3; i++)
	{
		cout << s.Pop( ) << "  ";
	}
	cout << endl;
	return 0;
}
