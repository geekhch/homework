// �ļ�·����:s6_7\smain6_7.cpp
#include <iostream>               					// ����Ԥ��������
#include <functional>               				// ����Ԥ��������
using namespace std;								// ʹ�������ռ�std 

int main()											// ������main()
{
	// ���涨��һЩ�߼���������
	logical_and<int> objAnd;						// �����߼��뺯������
	logical_or<int> objOr;							// �����߼���������
	logical_not<int> objNot;						// �����߼��Ǻ�������
    
	// �����������涨��ĺ�������ʵ����Ӧ�ĺ�������
	cout << objAnd(true, true) << endl;				// ���1
	cout << objOr(true, false) << endl;				// ���1
	cout << objNot(true) << endl;					// ���0

	// ����ֱ�������ɵ���ʱ��������ʵ����غ�������
	cout << logical_and<int>()(true, true) << endl;	// ���1
	cout << logical_or<int>()(true, false) << endl;	// ���1
	cout << logical_not<int>()(true) << endl;		// ���0

	system("PAUSE");            					// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    					// ����ֵ0, ���ز���ϵͳ
}
