// �ļ�·����:s6_6\smain6_6.cpp
#include <iostream>               				// ����Ԥ��������
#include <functional>               			// ����Ԥ��������
using namespace std;							// ʹ�������ռ�std 

int main()										// ������main()
{
	// ���涨��һЩ��ϵ��������
	equal_to<int> objEqual;						// ������ں�������
	not_equal_to<int> objNotEqual;				// ���岻���ں�������
	greater<int> objGreat;						// ������ں�������
	greater_equal<int> objGreatEqual;			// ������ڵ��ں�������
	less<int> objLess;							// ����С�ں�������
	less_equal<int> objLessEqual;				// ����С�ڵ��ں�������
    
	// �����������涨��ĺ�������ʵ����Ӧ�ĺ�������
	cout << objEqual(2, 6) << endl;				// ���0
	cout << objNotEqual(2, 6) << endl;			// ���1
	cout << objGreat(2, 6) << endl;				// ���0
	cout << objGreatEqual(2, 6) << endl;		// ���0
	cout << objLess(2, 6) << endl;				// ���1
	cout << objLessEqual(2, 6) << endl;			// ���1

	// ����ֱ�������ɵ���ʱ��������ʵ����غ�������
	cout << equal_to<int>()(2, 6) << endl;		// ���0
	cout << not_equal_to<int>()(2, 6) << endl;	// ���1
	cout << greater<int>()(2, 6) << endl;		// ���0
	cout << greater_equal<int>()(2, 6) << endl;	// ���0
	cout << less<int>()(2, 6) << endl;			// ���1
	cout << less_equal<int>()(2, 6) << endl;	// ���1

	system("PAUSE");            				// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    				// ����ֵ0, ���ز���ϵͳ
}
