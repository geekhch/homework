// �ļ�·����:s6_1_1\smain6_1_1.cpp
#include <iostream>               		// ����Ԥ��������
using namespace std;					// ʹ�������ռ�std 

void Show(int *begin, int *end)			// ��ʾ
{
	for (int *it = begin; it != end; ++it)
	{	// ������ʾ��Ԫ��
		cout << *it << " ";
	}
	cout << endl;						// ����
}

int main()								// ������main()
{
	int a[] = {1, 2, 3, 4, 5, 6};		// ����C����a
	int n = 6;							// Ԫ�ظ���
	int *begin = a;						// ��ʼ
	int *end = a + n;					// ����

	Show(begin, end);					// ��ʾ

	system("PAUSE");            		// ���ÿ⺯��system( )�����ϵͳ��ʾ�����ز���ϵͳ
	return 0;                    		// ����ֵ0, ���ز���ϵͳ
}
