// �ļ�·����:s6_1_2\smain6_1_2.cpp
#include <iostream>            				// ����Ԥ��������
using namespace std;						// ���������ռ�std 

// ����������ģ��
template <class Type>
class Array
{
private:
// ���ݳ�Ա:
	Type *elem;								// �洢����Ԫ��ֵ
	int maxSize;							// �������Ԫ�ظ���
	int size;								// ���鵱ǰԪ�ظ���

public:
// ���к���ģ��:	
	Array(int sz = 3): maxSize(sz), size(0)	// ���캯��ģ��
	{ 
		elem = new Type[maxSize];			// ����洢�ռ�
	}	
	virtual ~Array()						// ��������ģ��
	{ 
		delete []elem;						// �ͷŴ洢�ռ�
	}				
	void Append(const Type &e)				// ��ĩβ׷��Ԫ��
	{
		if (size >= maxSize)
		{	// ������������������
			Type *tmpElem = new Type[maxSize *= 2];	// ����洢�ռ�
			for (int i = 0; i < size; i++)
			{	// ����Ԫ��ֵ
				tmpElem[i] = elem[i];		// ��elem��Ԫ��ֵ���Ƶ�tmpElem����ӦԪ��
			}
			delete []elem;					// �ͷŴ洢�ռ�
			elem = tmpElem;					// ʹelemָ���·���Ĵ洢�ռ�
		}
		elem[size++] = e;					// ��ĩβ׷��Ԫ��
	}
	Type *Begin() const						// ���ؿ�ʼ
	{
		return elem;	
	}
	Type *End()	const						// ���ؽ���
	{	
		return elem + size;	
	}
};

// ���������������ģ��
template <class Type>
class ArrayIterator
{
private:
// ���ݳ�Ա:
	Type *itPtr;							// �����������Ƕ�Type *�ķ�װ
	
public:
// ���к���ģ��:
	ArrayIterator(Type *p): itPtr(p) { } 	// ���캯��ģ��
	bool operator != (const ArrayIterator &it) const	// ����"!="��ϵ�����
	{
		return this->itPtr != it.itPtr;		// ����ֵ
	}
	ArrayIterator operator++()				// ����ǰ׺"++"�����
	{
		return itPtr++;						// itPtrָ����һԪ�أ�������		
	}
	Type operator*() const					// ����"*"ָ�������������
	{
		return *itPtr;						// ����itPtrָ���ֵ
	}
};

template <class It>
void Show(It begin, It end)					// ������ʾ
{
	for (It it = begin; it!= end; ++it)
	{	// ������ʾ��Ԫ��
		cout << *it << " ";
	}
	cout << endl;							// ����
}

int main()									// ������main()
{
	int a[] = {1, 2, 3, 4, 5, 6};			// ����C����a
	int n = 6;								// ����Ԫ�ظ���
	Array<int> arr;							// �����������
	int i;									// ������ʱ����

	for (i = 0; i < n; i++)
		arr.Append(a[i]);					// ��ĩβ׷��Ԫ��

	ArrayIterator<int> begin(arr.Begin());	// ����begin
	ArrayIterator<int> end(arr.End());		// ����end
	cout << "����Ԫ��:";					// �����ʾ
	Show(begin, end);						// ��ʾ����

	system("PAUSE");						// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;               				// ����ֵ0, ���ز���ϵͳ
}
