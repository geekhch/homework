// �ļ�·����:s6_5\smain6_5.cpp
#include <iostream>               			// ����Ԥ��������
#include <functional>              			// ����Ԥ��������
using namespace std;						// ʹ�������ռ�std 

int main()									// ������main()
{
	// ���涨��һЩ������������
	plus<int> objPlus;						// ����ӷ�������������
	minus<int> objMinus;					// �������������������
	multiplies<int> objMul;					// ����˷�������������
	divides<int> objDiv;					// �������������������
	modulus<int> objMod;					// ��������������������
	negate<int> objNeg;						// ����ȡ��������������
    
	// �����������涨��ĺ�������ʵ����Ӧ�ĺ�������
	cout << objPlus(2, 6) << endl;			// ���2+6
	cout << objMinus(2, 6) << endl;			// ���2-6
	cout << objMul(2, 6) << endl;			// ���2*6
	cout << objDiv(2, 6) << endl;			// ���2/6
	cout << objMod(2, 6) << endl;			// ���2%6
	cout << objNeg(2) << endl;				// ���-2

	// ����ֱ�������ɵ���ʱ��������ʵ����غ�������
	cout << plus<int>()(2, 6) << endl;		// ���2+6
	cout << minus<int>()(2, 6) << endl;		// ���2-6
	cout << multiplies<int>()(2, 6) << endl;// ���2*6
	cout << divides<int>()(2, 6) << endl;	// ���2/6
	cout << modulus<int>()(2, 6) << endl;	// ���2%6
	cout << negate<int>()(2) << endl;		// ���-2

	system("PAUSE");            			// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;                    			// ����ֵ0, ���ز���ϵͳ
}
