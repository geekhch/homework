// �ļ�·����:s6_1_4\smain6_1_4.cpp
#include <iostream>            				// ����Ԥ��������
using namespace std;						// ���������ռ�std 

// ����������ģ��
template <class Type>
class Link
{
public:
// ������Ƕ��ģ��
	// ������Ƕ�����ģ��
	struct Node 
	{	// ��struct�������(ģ��)�ĳ�ԱȱʡΪ���з���Ȩ��
		Type data;							// ����
		Node *next;							// ָ��
		Node(const Type &e, Node *nPtr = NULL):
			data(e), next(nPtr) {}			// ���캯��
	};

	// ������Ƕ�����������ģ��
	class LinkIterator
	{
	private:
	// ���ݳ�Ա:
		Node *itPtr;						// �����������Ƕ�Node *�ķ�װ
		
	public:
	// ���к���ģ��:
		LinkIterator(Node *p): itPtr(p) { } 			// ���캯��ģ��
		bool operator != (const LinkIterator &it) const	// ����"!="��ϵ�����
		{
			return this->itPtr != it.itPtr;	// ����ֵ
		}
		LinkIterator operator++()			// ����ǰ׺"++"�����
		{
			return itPtr = itPtr->next;		// itPtrָ����һԪ�أ�������
		}
		Type operator*() const				// ����"*"ָ�������������
		{
			return itPtr->data;				// ����itPtrָ���Ԫ��ֵ�������������ء�<<�����Ƚ̲ĸ����
		}
	};

public:
// ���к���ģ��	

	Link():head(NULL), prev(NULL), tail(NULL) {}// ���캯��ģ��
	virtual ~Link()							// ��������ģ��
	{ 
		while (head != NULL)
		{	// ����ǿ�
			Node *p = head;					// pָ���һ������Ԫ�ؽ��
			head = p->next;					// headָ����һ���
			delete p;						// �ͷ�p��ָ�洢�ռ�
		}
	}				
	void Append(const Type &e)				// ��ĩβ׷��Ԫ��
	{
		Node *p = new Node(e);				// ����洢�ռ�
		if (head == NULL)
		{	// ������
			head = prev = p;				// head��p�����½��
			tail = p->next;					// tailΪprev�ĺ��(NULL)
		}
		else
		{	// �ǿ�����
			prev->next = p;					// �½��׷����ĩβ
			prev = p;						// pΪ�±�β
			tail = p->next;					// tailΪprev�ĺ��(NULL)
		}
	}
	Node *Begin() const						// ���ؿ�ʼ
	{
		return head;	
	}
	Node *End()	const						// ���ؽ���
	{
		return tail;	
	}

private:
// ���ݳ�Ա:
	Node *head;								// ��ͷ
	Node *tail;								// ��β(Ϊ�˺���ʵ�ֵ���������Ҫ������ָ�����һ��Ԫ
											// �أ����Ǵ�Ԫ�صĺ��棬�˴�����β����ΪNULL)
	Node *prev;								// ��βǰ��(prev->next == tail)
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

	Link<int>::LinkIterator begin(la.Begin());	// ����begin
	Link<int>::LinkIterator end(la.End());		// ����end
	cout << "����Ԫ��:";					// �����ʾ
	Show(begin, end);						// ��ʾ����

	system("PAUSE");						// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;               				// ����ֵ0, ���ز���ϵͳ
}
