// �ļ�·����:s1_4\main.cpp
#include <iostream>
using namespace std;

int i=10;
void fun()
{
	int i=20;
	printf("�ֲ����� i=%d",i); //���ʾֲ�����i
	printf(" ��ȫ�ֱ��� i=%d",::i); //����ȫ�ֱ���i����C�����У�
    //���ڶ����˾ֲ����� i���޷��� fun()�����ڷ���ͬ��ȫ�ֱ��� i
}
int main()
{
	fun();
	return 0;                    		// ����ֵ0, ���ز���ϵͳ
}
