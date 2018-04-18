// �ļ�·����:s6_16\smain6_16.cpp
#include <iostream>               		// ����Ԥ��������
#include <vector>			          	// ����Ԥ��������
#include <algorithm>			        // ����Ԥ��������
using namespace std;					// ʹ�������ռ�std 

// ������GetInfo
class GetInfo
{
private:
// ���ݳ�Ա:
	int sum;							// ��
	int max;							// ���ֵ
	int min;							// ��Сֵ
	int count;							// Ԫ�ظ���

public:
// ���к���:
	GetInfo(): sum(0), count(0) {}		// ���캯��
	int GetSum() const					// ������ֵ
	{
		return sum;						// ���غ�sum
	}
	int GetMax() const					// ������ֵ
	{
		return max;						// �������ֵmax
	}
	int GetMin() const					// �����Сֵ
	{
		return min;						// ������Сֵsum
	}
	void operator()(int e)				// ���ص������ĺ��������
	{
		count++;						// Ԫ�ظ����Լ�1
		sum = sum + e;					// �ۼ����
		if (count == 1)
		{	// eΪ��һ��Ԫ��
			max = min = e;				// ֻ��һ��Ԫ��eʱ�����ֵ����Сֵ��Ϊe
		}
		else
		{	// �ж��Ԫ��
			if (max < e)
			{	// eΪ����������ֵ
				max = e;				// ��e��ֵ��max
			}
			else if (min > e)
			{	// eΪ��ǰ�������Сֵ
				min = e;				// ��e��ֵ��min
			}
		}
	}
};

int main()								// ������main()
{
	int a[] = {1, 4, 2, 8, 5, 6};		// ��������
    	int n = sizeof(a) / sizeof(int);// ����Ԫ�ظ���
	int *begin = a;						// ��ʼ
	int *end = a + n;					// ����	

	GetInfo objGetInfo = for_each(begin, end, GetInfo());
		// ���庯������ͨ��for_each()�㷨���г�ʼ��
	cout << "�ܺ���:" << objGetInfo.GetSum() << endl;		// ����ܺ�
	cout << "���ֵ:" << objGetInfo.GetMax() << endl;		// ������ֵ
	cout << "��Сֵ:" << objGetInfo.GetMin() << endl;		// �����Сֵ

	system("PAUSE");            		// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    		// ����ֵ0, ���ز���ϵͳ
}
