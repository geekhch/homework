//���ʵ���ļ���s3_1\sclass3_1_A.cpp
#include "sclass3_1_A.h"		//����������ͷ�ļ�

void A::SetX(int i)				//Ϊ���ݳ�Աx��ֵ
{
	x = i;
}
int A::GetX() const				//��ȡ���ݳ�Աx��ֵ
{
	return x;
}

void B::SetValue(int a, int b, int c, int d, int e)
{
	// x = a;					//�����˽������x�������಻�ɼ�����ֱ�ӷ��ʷǷ���
	SetX(a);   					//ͨ���ⲿ�ӿ�SetX( )����ӷ��ʻ����˽������x
	y = b;       				//��b��ֵ��������ı�����Աy�����ʺϷ�
	z = c;       				//��c��ֵ��������Ĺ��г�Աz�����ʺϷ�
	m = d;
	n = e;
}
void B::Display() const
{
	// cout << "x = " << x << endl; //x���������в��ɷ���
	cout << "x = " << GetX() << endl;
	cout << "y = " << y << endl;
	cout << "m = " << m << endl;
	cout << "n = "<< n << endl;		//�������˽�г�Ա�ڱ����п��Է���
}
