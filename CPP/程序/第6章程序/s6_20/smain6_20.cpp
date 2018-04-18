// �ļ�·����:s6_20\smain6_20.cpp
#include <iostream>            				// ����Ԥ��������
#include <vector>							// ����Ԥ��������
#include <functional>						// ����Ԥ��������
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
	vector<int> v(n);						// ������������

	for (int i = 0; i < n; ++i)
	{	// �����������Ԫ�ظ�ֵ
		v[i] = a[i];						// ��a[i]��ֵ��v[i]
	}

	cout << "����ǰ:";						// �����ʾ
	Show(v.begin(), v.end());				// ��������Ԫ��ֵ
	sort(v.begin(), v.end(), greater<int>());// ��������
	cout << "�����:";						// �����ʾ
	Show(v.begin(), v.end());				// ��������Ԫ��ֵ

	system("PAUSE");						// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;               				// ����ֵ0, ���ز���ϵͳ
}
