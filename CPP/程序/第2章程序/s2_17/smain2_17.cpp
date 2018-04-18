// 文件路径名: s2_17\smain2_17.cpp
#include <iostream>
#include <math.h>
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
	friend double FDist(CPoint *p1, CPoint*p2);  
private:
 	double x,y;
};
double FDist( CPoint *p1, CPoint *p2 )
{
	//由于是友元关系，p1、p2可以直接访问所指对象的私有成员x和y
	double x = p1->x - p2->x; 
	double y = p1->y - p2->y;
	return sqrt(x*x+y*y);
};
int main()
{
	CPoint *p1=new CPoint(1,1);
	CPoint *p2=new CPoint(4,5);
	cout<<"The distance is:";
	cout<< FDist(p1, p2)<<endl;
	delete p1;
	delete p2;
	return 0;
}
