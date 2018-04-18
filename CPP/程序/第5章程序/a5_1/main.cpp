// �ļ�·����:a5_1\main.cpp
#include <iostream>               					// ����Ԥ��������
using namespace std;								// ʹ�������ռ�std 

// ����������ģ��
template <class Type>
class Array
{
private:
// ���ݳ�Ա
	Type *elem;										// �洢����Ԫ��ֵ
	int size;										// ����Ԫ�ظ���

public:
// ���к���ģ��	
	Array(int sz): size(sz) { elem = new int[size]; }	// ���캯��ģ��
	~Array(){ delete []elem; }						// ��������
	Type &operator[](int i)							// �±������"[]"ֻ������Ϊ��Ա����ģ��
	{
		if (i < 0 || i >= size)
		{
			cout << "Ԫ��λ�ô�!" << endl;
			exit(1);								// �˳����������,���ص�����ϵͳ
		}
		return elem[i];								// ����elem[i]
	}
};

int main()											// ������main()
{
	int a[] = {1, 9, 7, 5, 6, 3};					// ��������a
	int n = 6;										// ����Ԫ�ظ���
	Array<int> obj(n);								// �����������
	int i;											// ������ʱ����
	for (i = 0; i < n; i++) obj[i] = a[i];			// ��������Ԫ��ֵ, obj[i]�ȼ���obj.operator[i]
	for (i = 0; i < n; i++) cout << obj[i] << " ";	// ���Ԫ��ֵ, obj[i]�ȼ���obj.operator[i]
	cout << endl;									// ����

	system("PAUSE");								// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;               						// ����ֵ0, ���ز���ϵͳ
}
