// �ļ�·����:s6_12\smain6_12.cpp
#include <iostream>               			// ����Ԥ��������
#include <deque>							// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 
    
int main()									// ������main()
{
	deque<int> q;							// ����˫�˶��ж���
	deque<int>::iterator it;				// ���������
	int a[] = {5, 1, 8, 18, 16, 19}, n = 6, i, e;	// �������鼰���ͱ���

	for (i = 0; i < n; ++i)
	{	// ������˫�˶����в���a[i]
		q.push_back(a[i]);					// ��˫�˶���β׷��a[i]
	}

	for (it = q.begin(); it != q.end(); ++it)		// ��ʾ˫�˶���
	{	// ���������Ԫ�ص�ֵ
		cout << *it << " ";					// ���*it
	}
	cout << endl;							// ����

	q.clear();								// ���˫�˶���
	for (i = 0; i < n; ++i)
	{	// ������˫�˶����в���a[i]
		q.push_front(a[i]);					// ��˫�˶����ײ�����a[i]
	}

	for (it = q.begin(); it != q.end(); ++it)		// ��ʾ˫�˶���
	{	// ���������Ԫ�ص�ֵ
		cout << *it << " ";					// ���*it
	}
	cout << endl;							// ����

	q.pop_front();							// ɾ����Ԫ��
	cout << q.front() << endl;				// �������Ԫ��

	q.pop_back();							// ɾ��βԪ��
	cout << q.back() << endl;				// �����βԪ��

	system("PAUSE");            			// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}
