// �ļ�·����: s2_23\smain2_23.cpp
#include <iostream>
#include <cmath>
using namespace std;

class CPoint
{
public:
   	CPoint(double xx=0, double yy=0)
	{
		x=xx;
		y=yy;
	}
   	double GetX()
	{
		return x;
	}
   	double GetY()
	{
		return y;
	}
   	friend double FDist(const CPoint &p1, const CPoint &p2);  
private:
 	double x,y;
};

double FDist(const CPoint &p1, const CPoint &p2)
{
	//��������Ԫ��ϵ��p1��p2����ֱ�ӷ�����ָ�����˽�г�Աx��y
	double x=p1.x - p2.x; 
	double y=p1.y - p2.y;
	return sqrt(x*x + y*y);
}
int main()
{
	CPoint a(1, 1);
	CPoint b(4, 5);
	cout<<"The distance is:";
	cout<< FDist(a, b)<<endl;
	return 0;
}
