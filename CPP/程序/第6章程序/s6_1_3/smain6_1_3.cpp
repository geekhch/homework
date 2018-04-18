// �ļ�·����:s6_1_3\smain6_1_3.cpp
#include <iostream>            				// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 

// ��������ģ��
template <class Type>
struct Node 
{	// ��struct�������(ģ��)�ĳ�ԱȱʡΪ���з���Ȩ��
	Type data;								// ����
	Node *next;								// ָ��
	Node(const Type &e, Node *nPtr = NULL): data(e), next(nPtr) {}	// ���캯��
};

// ����������ģ��
template <class Type>
class Link
{
private:
// ���ݳ�Ա:
	Node<Type> *head;						// ��ͷ
	Node<Type> *tail;						// ��β(Ϊ�˺���ʵ�ֵ���������Ҫ������ָ�����һ��Ԫ
											// �أ����Ǵ�Ԫ�صĺ��棬�˴�����β����ΪNULL)
	Node<Type> *prev;						// ��βǰ��(prev->next == tail), ʵ��ָ�����һ��Ԫ��

public:
// ���к���ģ��:	
	Link():head(NULL), prev(NULL), tail(NULL) {} // ���캯��ģ��
  	virtual ~Link()							// ��������ģ��
	{ 
		while (head != NULL)
		{	// ����ǿ�
			Node<Type> *p = head;			// pָ���һ������Ԫ�ؽ��
			head = p->next;					// headָ����һ���
			delete p;						// �ͷ�p��ָ�洢�ռ�
		}  
	}				
	void Append(const Type &e)				// ��ĩβ׷��Ԫ��
	{
		Node<Type> *p = new Node<Type>(e);	// ����洢�ռ�
		if (head == NULL)
		{	// ������
			head = prev = p;				// head��prev�����½��
			tail = p->next;					// tailΪprev�ĺ��(NULL)
		}
		else
		{	// �ǿ�����
			prev->next = p;					// �½��׷����ĩβ
			prev = p;						// pΪ�±�β
			tail = p->next;					// tailΪprev�ĺ��(NULL)
		}
	}
	Node<Type> *Begin()	const				// ���ؿ�ʼ
	{
		return head;	
	}
	Node<Type> *End() const   				// ���ؽ���
	{
		return tail;	
	}
};

// ���������������ģ��
template <class Type>
class LinkIterator
{
private:
// ���ݳ�Ա:
	Node<Type> *itPtr;						// �����������Ƕ�Node<Type> *�ķ�װ���Ƚ̲��ϵġ�Type *����ֱ�ӣ�������������
	
public:
// ���к���ģ��:
	LinkIterator(Node<Type> *p): itPtr(p) { }		// ���캯��ģ��
	bool operator != (const LinkIterator &it) const	// ����"!="��ϵ�����
	{
		return this->itPtr != it.itPtr;		// ����ֵ
	}
	LinkIterator operator++()				// ����ǰ׺"++"�����
	{
		return itPtr = itPtr->next;			// itPtrָ����һԪ�أ�������
	}
	Type operator*() const					// ����"*"ָ�������������
	{
		return itPtr->data;					// ����itPtrָ���Ԫ��ֵ�������������ء�<<�����Ƚ̲ĸ����
	}
};

template <class It>
void Show(It begin, It end)					// ������ʾ
{
	for (It it = begin; it != end; ++it)
	{	// ������ʾ��Ԫ��
		cout << *it << " ";
	}
	cout << endl;							// ����
}

int main()									// ������main()
{
	int a[] = {1, 2, 3, 4, 5, 6};			// ����C����a
	int n = 6;								// Ԫ�ظ���
	Link<int> la;							// �����������
	int i;									// ������ʱ����

	for (i = 0; i < n; i++)
		la.Append(a[i]);					// ��ĩβ׷��Ԫ��

	LinkIterator<int> begin(la.Begin());	// ����begin
	LinkIterator<int> end(la.End());		// ����end
	cout << "����Ԫ��:";					// �����ʾ
	Show(begin, end);						// ��ʾ����

	system("PAUSE");						// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;               				// ����ֵ0, ���ز���ϵͳ
}
