// �ļ�·����:a5_2\main.cpp
#include <iostream>               					// ����Ԥ��������
using namespace std;								// ʹ�������ռ�std 

// ����������ģ��
template <class Type, int size>
class Array
{
private:
// ���ݳ�Ա
	Type elem[size];								// �洢����Ԫ��ֵ

public:
// ���к���ģ��	
	Array(){ }										// ���캯��ģ��
	~Array(){ }										// ��������
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
	const int n = 6;								// ����Ԫ�ظ���
	Array<int, n> obj;								// �����������
	int i;											// ������ʱ����
	for (i = 0; i < n; i++) obj[i] = a[i];			// ��������Ԫ��ֵ, obj[i]�ȼ���obj.operator[i]
	for (i = 0; i < n; i++) cout << obj[i] << " ";	// ���Ԫ��ֵ, obj[i]�ȼ���obj.operator[i]
	cout << endl;									// ����

	system("PAUSE");								// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
	return 0;               						// ����ֵ0, ���ز���ϵͳ
}
