// �ļ�·����: s2_24\smain2_24.cpp
#include<iostream>
using namespace std;

class Point
{
public:
	Point(int a, int b)
	{
		x=a; 
		y=b;
	}
	void Move(int a, int b)
	{
		x+=a;
		y+=b;
	}
	void Print() const
	{
		cout<<"x="<<x<<", y="<<y<<endl;
	}
private:
	int x, y;
};
int main()
{
	const Point point1( 10,10);	//��������ʼ����������point1
	point1.Print();				//Print()�������ڱ�ɳ���Ա���������Կ��Ա�point1����
	return 0;
}
