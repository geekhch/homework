#include <iostream>						// Ԥ��������
using namespace std;					// ʹ�ñ�׼�����ռ�std

int main()								// ������main()
{
	double s = 0, a[] = {1, 2, 3, 4, 5, 6};	// �������s������a
	
	int _i0001 = 0;
	for ( double v = a[0];
		_i0001 < sizeof(a) / sizeof(a[0]);
		_i0001++, v = a[_i0001]) s += v;		// ����foreachѭ��
	cout << "����a�ĸ�Ԫ��֮��Ϊ" << s << endl;

    system("PAUSE");            		// ���ÿ⺯��system( )�����ϵͳ��ʾ
    return 0;                    		// ����ֵ0,���ز���ϵͳ
}
