// �ļ�·����:s6_10\smain6_10.cpp
#include <iostream>               			// ����Ԥ��������
#include <list>				         		// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 

int main()									// ������main()
{
	list<int> la;							// �����������

	for (int i = 1; i <= 6; i++)
	{	// ���������Ա��в���ֵ
		la.push_back(i);					// �������β׷��i
	}

	// ������ʾ����
	for (list<int>::iterator it = la.begin(); it != la.end(); ++it)
	{	// ���������Ԫ�ص�ֵ
		cout << *it << " ";					// ���*it
	}	
	cout << endl;							// ����

	// ������ʾ����
	for (list<int>::reverse_iterator rit = la.rbegin(); rit != la.rend(); ++rit)
	{	// ���������Ԫ�ص�ֵ
		cout << *rit << " ";				// ���*rit
	}
	cout << endl;							// ����
	
	system("PAUSE");            			// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}
