// �ļ�·����:s6_13\smain6_13.cpp
#include <iostream>               			// ����Ԥ��������
#include <deque>				          	// ����Ԥ��������
#include <stack>			          		// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 

int main()									// ������main()
{
	stack<int> s;							// ����ջ����
	for(int i = 1; i <= 5; ++i)
	{	// ������ջ
		s.push(i);							// i��ջ
	}
    
	cout << "ջs:";							// �����ʾ
	while (!s.empty())
	{	// ջs�ǿ�
		cout << s.top() << " ";				// ���ջ��
		s.pop();							// ��ջ
	}
	cout << endl;							// ����

	system("PAUSE");            			// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}
