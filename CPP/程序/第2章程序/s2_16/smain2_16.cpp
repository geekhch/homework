// �ļ�·����: s2_16\smain2_16.cpp
#include<iostream>   
using namespace std; 

class CDemo
{
public:
	CDemo(int ii=0):i(ii)
	{
		j=i;
	}
	static int Incr()					//����һ����̬��Ա����ʵ�ֶԾ�̬���ݳ�Աj�Ĳ���
	{
		return ++j;
	}
private:
	int i;       		      
	static int j;						//����һ����̬���ݳ�Ա
};
int CDemo::j = 0;						//��ʼ����̬���ݳ�Ա
int main()
{	
	cout << "j=" << CDemo::Incr( ) << endl;   //ͨ���������ʾ�̬��Ա����
	return 0;
}
