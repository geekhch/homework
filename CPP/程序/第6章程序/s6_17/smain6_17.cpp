// �ļ�·����:s6_17\smain6_17.cpp
#include <iostream>               			// ����Ԥ��������
#include <vector>			          		// ����Ԥ��������
#include <algorithm>			          	// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 

int main()									// ������main()
{
	int a[] = {1, 4, 2, 8, 5, 6};			// ��������
    	int n = sizeof(a) / sizeof(int);	// ����Ԫ�ظ���
	int *begin = a;							// ��ʼ
	int *end = a + n;						// ����	
	int e = 8;								// Ԫ��ֵ

	int *p = find(begin, end, e);			// ָ���״�Ԫ��ֵΪe������Ԫ�ص�ָ��
	if (p != end) cout << "Ԫ��ֵΪ" << e << "��Ԫ�ص��±�Ϊ" << p - a << endl;	// ���ҳɹ�����������Ϣ
	else cout << "����ʧ��" << endl;		// ����ʧ��

	system("PAUSE");            			// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}
