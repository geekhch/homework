// �ļ�·����:s6_11\smain6_11.cpp
#include <iostream>               			// ����Ԥ��������
#include <list>				         		// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 

int main()									// ������main()
{
	list<int> la;							// �����������
	list<int>::iterator it;					// ���������
	int a[] = {1, 6, 3, 5, 4, 2}, n = 6;	// �������鼰���ͱ���

	for (int i = 0; i < n; ++i)
	{	// ���������Ա��в���a[i]
		la.push_back(a[i]);					// �������β׷��a[i]
	}

	for (it = la.begin(); it != la.end(); ++it)		// ��ʾ����
	{	// ���������Ԫ�ص�ֵ
		cout << *it << " ";					// ���*it
	}
	cout << endl;							// ����

	la.reverse();							// ��ת����Ԫ��˳��
	for (it = la.begin(); it != la.end(); ++it)		// ��ʾ����
	{	// ���������Ԫ�ص�ֵ
		cout << *it << " ";					// ���*it
	}
	cout << endl;							// ����

	la.sort();								// ������������
	for (it = la.begin(); it != la.end(); ++it)		// ��ʾ����
	{	// ���������Ԫ�ص�ֵ
		cout << *it << " ";					// ���*it
	}
	cout << endl;							// ����

	system("PAUSE");            			// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}
