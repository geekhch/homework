//���ļ�����s3_1\smain3_1.cpp
#include "sclass3_1_A.h"   
int main()
{
	B ObjB;
	ObjB.SetValue(1, 2, 3, 4, 5);
	ObjB.Display();
	cout << "z = "<< ObjB.z << endl;	//�������ݣ���ͨ���������
	// cout << "y="<< ObjB.y << endl;	//����ı������ݣ�����ͨ���������
	// cout << "x="<< ObjB.x << endl;	//�����˽�����ݣ���������ɷ���
	// cout << "m="<< ObjB.m << endl;	//������ı������ݣ�����ͨ���������
	// cout << "n="<< ObjB.n << endl;	//�������˽�����ݣ�����ͨ���������
	return 0;
}
