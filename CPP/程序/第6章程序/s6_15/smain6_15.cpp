// �ļ�·����:s6_15\smain6_15.cpp
#include <iostream>               			// ����Ԥ��������
#include <vector>						  	// ����Ԥ��������
#include <algorithm>			          	// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 

void ShowCube(int n)						//  ��ʾ��������Ӧ������
{
	cout << n << ":\t" << n * n * n << endl;// ��������Ϣ
}

int main()									// ������main()
{
	int n = 8;								// Ԫ�ظ���
	vector<int> v(n);						// �����СΪn������

	for (int i = 0; i < n; ++i)
	{	// ͨ�����鷽ʽΪ����Ԫ�ظ�ֵ
		v[i] = i + 1;
	}

	cout << "i:\ti*i*i" << endl;			// �����ʾ
	for_each(v.begin(), v.end(), ShowCube);	// ���v��ÿ��Ԫ�ؼ�����Ӧ������

	system("PAUSE");            			// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}
