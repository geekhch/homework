// �ļ�·����:train_judge\smain.cpp
#include <iostream>               			// ����Ԥ��������
#include <deque>							// ����Ԥ��������
#include <stack>			          		// ����Ԥ��������
#include <queue>			          		// ����Ԥ��������
using namespace std;						// ���������ռ�std 

bool TrainJudge(int a[], int n)
{
	int i;									// �������
	queue<int> inq;							// �����վ����
	stack<int> s;							// �������ջ

	for (i = 1; i <= n; i++)
	{	// �������
		inq.push(i);						// i���
	}

	for (i = 0; i < n; i++)
	{	// ����a[i]
		if (a[i] < 1 || a[i] > n)
		{	// �����ȵ��г���Ӧ��1~n֮��
			cout << "�����ȵĳ�����Ӧ��1~" << n << "֮��" << endl;
			return false;					// ����ʧ��
		}
		else if (!s.empty() && a[i] == s.top())
		{	// �����ȵ��г�����ջ�������ȳɹ�
			cout << s.top() << "���г���վ" << endl;
			s.pop();						// ��ջ
		}
		else if (!inq.empty() && a[i] >= inq.front())
		{	// �����ȵ��г�����վ����inq��
			while (!inq.empty() && a[i] >= inq.front())
			{	// inq.front()��վ
				s.push(inq.front());		// inq.front()��վ
				cout << inq.front() << "���г���վ" << endl;
				inq.pop();					// ����
			}

			cout << s.top() << "���г���վ" << endl;	// ��ʱs.top()==a[i]
			s.pop();						// ��ջ
		}
		else
		{	// a[i]����sջ��������sջ�е��м䣬�޷���ջ
			cout << "���Ȳ���ʵ��" << endl;
			return false;					// ����ʧ��
		}
	}

	return true;							// ���ȳɹ�
}

int main()									// ������main()
{
	int *a, i, n = 6;						// �������
	char select;							// �������

	do
	{
		cout << "�����г���:";				// ������ʾ
		cin >> n;							// ����n
		a = new int[n];						// ����ռ�			
		cout << "��������ȵ��г���:";		// ������ʾ
		for (i = 0; i < n; i++)
		{	// ������������ȵ��г���
			cin >> a[i];					// ����a[i]
		}

		if (TrainJudge(a, n))
		{	// ���ȳɹ�
			cout << "ף��! ���ȳɹ�!" << endl;
		}
		else
		{	// ����ʧ��
			cout << "ʧ���˳ɹ�֮ĸ��������µ���" << endl;
		}

		delete []a;							// �ͷſռ�

		cout << "�Ƿ��������(Y/N)?" << endl;
		cin >> select;						// ����ѡ��

	} while (select == 'Y' || select == 'y');


	system("PAUSE");						// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;               				// ����ֵ0, ���ز���ϵͳ
}
