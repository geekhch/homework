// �ļ�·����:s6_2\smain6_2.cpp
#include <iostream>               			// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 

int sum = 0;								// ���ڴ洢�ۼӺ�

void Sum(int e)								// �ۼ����
{
	sum = sum + e;							// sum�ۼ�e
}

template <class It, class Fun>
Fun &ForEach(const It &begin, const It &end, Fun &f)		// �����㷨
{
	for (It it = begin; it != end; ++it)
	{	// ���ε���f()
		f(*it);								// ����f() 
	}
	return f;								// ����f
}

int main()									// ������main()
{
	int a[] = {1, 2, 3, 4, 5, 6};			// ��������a
	int n = 6;								// Ԫ�ظ���
	int *begin = a;							// ��ʼ
	int *end = a + n;						// ����

	ForEach(begin, end, Sum);				// ���ñ����㷨
	cout << "sum=" << sum << endl; 			// ����ۼӺ�

	system("PAUSE");            			// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}
