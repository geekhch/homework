// �ļ�·����:s6_8\smain6_8.cpp
#include <iostream>               			// ����Ԥ��������
#include <vector>	        				// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 

int main()									// ������main()
{
	vector<int> v;							// ��������
	int a[] = {1, 2, 3, 4, 5}, n = 5, i;	// �������鼰���ͱ���

	for(i = 0; i < n; ++i)
	{	// ������v���Ԫ��
		v.push_back(a[i]);					// ͨ��push_back()�������Ԫ��
	}

	n = v.size();							// �������Ԫ�ظ���
	cout << "ͨ�����鷽ʽ���:" << endl;	// �����ʾ
	for(i = 0; i < n; ++i)
	{	// ���������Ԫ��
		cout<< v[i] << " ";					// ���v[i]
	}
	cout << endl;							// ����

	cout << "ͨ������������:" << endl;	// �����ʾ
    for(i = 0; i < n; ++i)
	{	// ���������Ԫ��
		int &e = v.at(i);					// ��������	
		cout << e << " ";					// ���e
	}
	cout << endl;							// ����

    cout << "ͨ�����������:" << endl;		// �����ʾ
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{	// ���������Ԫ��
		cout << *it << " ";					// ���*it
	}
	cout << endl;							// ����

	system("PAUSE");            			// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}
