//s5_2\smain5_2.cpp
//���к���ģ���ͬ�����غ�����ƥ�����

#include <iostream>
#include <string>
using namespace std;

//����ȫ�����غ���
int GetMax(int a, int b)				//�����������������ֵ
{
	cout << "����GetMax(int, int): "; 	//������ʾ�����õĺ���
	return a > b ? a : b;
}

//����ȫ�����غ���
char GetMax(char a, char b)				//������˫�������������ֵ
{
	cout << "����GetMax(char, char): ";
	return a > b ? a : b;
}

//���庯��ģ��1�������غ���ģ��
template <class Type1, class Type2>
Type1 GetMax( Type1 x, Type2 y )
{
	cout << "���ú���ģ��1: ";
	return  x > y ? x:y;				//�Զ�ת��Ϊ�������ٱȽ�
}

//���庯��ģ��2�������غ���ģ��
template <class Type1, class Type2,class Type3>
Type1 GetMax(Type1 a, Type2 b, Type3 c)
{
	Type1 t;
	t = a > b ? a:b;					//��a��b�Ľϴ���
	cout << "���ú���ģ��2: ";
	return t > c ? t : c;				//����a��b��c������ߡ�
}

//������
int main()    
{ 
	cout << " " << GetMax(10, 20) << endl;		//�������غ���
	cout << " " << GetMax('A', 'i') << endl;	//�������غ���

	cout << " " << GetMax(1.0, 2.0) << endl;	//ʹ�ú���ģ��1
	cout << " " << GetMax('A', 100) << endl;	//ʹ�ú���ģ��1

	cout << " " << GetMax(10, 5.0) << endl;		//ʹ�ú���ģ��1
	cout << " " << GetMax(11.1, 5) << endl;		//ʹ�ú���ģ��1
	cout << " " << GetMax(22, 10L) << endl;		//ʹ�ú���ģ��1
	cout << " " << GetMax(2L, 'A') << endl;		//ʹ�ú���ģ��1	
	cout << " " << GetMax(1.0, 200L) << endl;	//ʹ�ú���ģ��1

	cout << " " << GetMax(10, 20, 30) << endl;	//ʹ�ú���ģ��2
	cout << " " << GetMax(10L, 20, 30) << endl;	//ʹ�ú���ģ��2
	cout << " " << GetMax(1.1, 2.2, 3) << endl;	//ʹ�ú���ģ��2  
	cout << " " << GetMax(99.9, 8, 'A') << endl;//ʹ�ú���ģ��2

	system("PAUSE");					//�ȴ�����������ʵ����ͣ  
	return 0;							//����0
}
