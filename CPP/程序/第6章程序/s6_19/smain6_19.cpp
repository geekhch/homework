// �ļ�·����:s6_19\smain6_19.cpp
#include <iostream>            				// ����Ԥ��������
#include <algorithm>						// ����Ԥ��������
using namespace std;						// ���������ռ�std 

template <class It>
void Show(const It &begin, const It &end)	// ������ʾ
{
	for (It it = begin; it!= end; ++it)
	{	// ������ʾ��Ԫ��
		cout << *it << " ";
	}
	cout << endl;							// ����
}

int main()									// ������main()
{
	int a[] = {1, 8, 6, 9, 5, 18};			// ��������
	int n = sizeof(a) / sizeof(int);		// Ԫ�ظ���
	int *begin = a;							// ��ʼ
	int *end = a + n;						// ����

	cout << "����ǰ:";						// �����ʾ
	Show(begin, end);						// ��������Ԫ��ֵ
	sort(begin, end);						// ����
	cout << "�����:";						// �����ʾ
	Show(begin, end);						// ��������Ԫ��ֵ

	system("PAUSE");						// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;               				// ����ֵ0, ���ز���ϵͳ
}
