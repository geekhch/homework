// �ļ�·����:a8_1\main.cpp
//#include <iostream>		// ����Ԥ��������˴���Bug
//using namespace std;		// ʹ�������ռ�std���˴���Bug 
#include <iostream.h>		// ����Ԥ��������
#include <stdlib.h>			// ����Ԥ��������

void *operator new(size_t size)		// ȫ��new���غ���
{	// typedef unsigned int size_t;
	cout << "����ȫ��operator new(size_t)���غ���" << endl;
	return malloc(size == 0 ? 1 : size);
}

void *operator new(size_t size, char *s)	// ȫ��new���غ���
{	// typedef unsignedf int size_t;
	cout << s << "����ȫ��operator new(size_t, char *)���غ���" << endl;
	return malloc(size == 0 ? 1 : size);
}

void operator delete (void *ptr)	// ȫ��operator delete���غ���
{ if(ptr != NULL) free(ptr); }

class Test 
{
public:
	void* operator new(size_t size)// ��Test��new���غ���
	{	
		if (size != sizeof(Test)) { cout << "�ڴ�����쳣!" << endl; exit(1); }
		cout << "������Test��operator new(size_t)���غ���" << endl;
		return malloc(size == 0 ? 1 : size);
	}

	void operator delete (void *ptr, size_t size)// ��Test��operator delete(void *, size_t)���غ���
	{	
		if (size != sizeof(Test)) { cout << "�ڴ��ͷ��쳣!" << endl; exit(2); }
        if(ptr != NULL) free(ptr);
    }
};

int main()					// ������main()
{
	int *p1 = new int;		// ����ȫ��operator new(size_t)���غ���
	delete p1;				// ����ȫ��operator delete(void *)���غ���
	int *p2 = new("Hello,")int;	// ����ȫ��operator new(size_t, char *)���غ���
	delete p2;				// ����ȫ��operator delete(void *)���غ���
	Test *p3 = new Test;	// ������Test��operator new(size_t)���غ���
	delete p3;				// ������Test��operator delete(void *, size_t)���غ���
	
	system("PAUSE");		// ���ϵͳ��ʾ�����ز���ϵͳ
	return 0;        		// ����ֵ0, ���ز���ϵͳ
}
