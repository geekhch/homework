//类的声明文件：s3_2\smain3_2

#include<iostream>  
using namespace std; 

const double PI=3.1415;
class Circle
{	
public:
	void SetRadius(double r)
	{
		radius=r;
	}
	double GetRadius() const
	{
		return radius;
	}
	double GetArea() const
	{
		return PI*radius*radius;
	}
	void Print()const
	{
		cout<<"半径为"<< radius <<"的圆的面积是"<< GetArea( )<<endl;
	}
private:
	double radius;
};


class Cylinder: private Circle
{	
public:
	void SetHeight(double h)  
	{
		height=h;
	}
	double GetHeight() const 
	{
		return height;
	}
	void SetRadius(double r)        //派生类定义与基类同名的公有成员函数，便于类外访问
	{
		Circle::SetRadius(r);		//使用作用域限定符来表明调用基类的同名函数
	}
	double GetRadius() const		//派生类定义与基类同名的公有成员函数，便于类外访问
	{
		return Circle::GetRadius();	//使用作用域限定符来表明调用基类的同名函数
	}
	//基类的公有成员GetRadius()在派生类中可见，调用它可以间接访问在派生类中不可见的radius
	double GetArea() const  
	{		
		return 2*PI*GetRadius()*GetRadius()+2*PI*GetRadius()*height;
	}
	double GetVolume() const        
	{
		return PI* GetRadius()*GetRadius()*height;
	}
	void Print() const   
	{
		cout<<"底半径为"<<GetRadius()<<"的圆柱体的表面积是"<<GetArea()
			<<"体积是"<<GetVolume()<<endl;
	}
private:
	double height;                    //新增
};
int main()
{
	Cylinder cylinder;
	cylinder.SetRadius(12.5);
	cylinder .SetHeight(10.5);
	cout<<"圆柱体的表面积是"<<cylinder.GetArea()<<endl;  
	cout<<"圆柱体的体积是"<<cylinder.GetVolume()<<endl;
}
