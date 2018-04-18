//��������ļ���s3_2\smain3_2

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
		cout<<"�뾶Ϊ"<< radius <<"��Բ�������"<< GetArea( )<<endl;
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
	void SetRadius(double r)        //�����ඨ�������ͬ���Ĺ��г�Ա�����������������
	{
		Circle::SetRadius(r);		//ʹ���������޶������������û����ͬ������
	}
	double GetRadius() const		//�����ඨ�������ͬ���Ĺ��г�Ա�����������������
	{
		return Circle::GetRadius();	//ʹ���������޶������������û����ͬ������
	}
	//����Ĺ��г�ԱGetRadius()���������пɼ������������Լ�ӷ������������в��ɼ���radius
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
		cout<<"�װ뾶Ϊ"<<GetRadius()<<"��Բ����ı������"<<GetArea()
			<<"�����"<<GetVolume()<<endl;
	}
private:
	double height;                    //����
};
int main()
{
	Cylinder cylinder;
	cylinder.SetRadius(12.5);
	cylinder .SetHeight(10.5);
	cout<<"Բ����ı������"<<cylinder.GetArea()<<endl;  
	cout<<"Բ����������"<<cylinder.GetVolume()<<endl;
}
