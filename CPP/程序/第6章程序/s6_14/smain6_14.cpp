// �ļ�·����:s6_14\smain6_14.cpp
#include <iostream>               			// ����Ԥ��������
#include <list>			          			// ����Ԥ��������
#include <queue>							// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 

int main()									// ������main()
{
	queue<int, list<int> > q;				// ������ж���
	for(int i = 1; i <= 5; ++i)
	{	// ������ջ
		q.push(i);							// i���
	}
    
	cout << "����q:";						// �����ʾ
	while (!q.empty())
	{	// ����q�ǿ�
		cout << q.front() << " ";			// �������
		q.pop();							// ����
	}
	cout << endl;							// ����

	system("PAUSE");            			// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}
