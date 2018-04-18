// �ļ�·����: s2_14\sclass2_14_cpoint.h
#ifndef _SCLASS_CPOINT_H_
#define _SCLASS_CPOINT_H_
#include <iostream>
using namespace std;

class Point 
{ 
public:
    Point()
	{
		x=0;
		y=0;
		counter++;		//������������ù��캯��ʱ����������ֵ����һ��
	} 
   	~Point()
	{
		counter--;		//���������������������ʱ����������ֵ�ݼ�һ��
	} 
   	Point(float x, float y)
   	{
        this->x=x;
        this->y=y;
		counter++;		//������������ù��캯��ʱ����������ֵ����һ��
   	}    
    void Move(float x, float y)
    {       
       	this->x=x;
		this->y=y;
   	}
	float GetX()
	{
		return x;
	}
	float GetY()
	{
		return y;
	}
private:
	float x;  
	float y;
public:
	static int counter;
}; 
int Point::counter=0;    //�������ʼ����̬���ݳ�Աcounter
#endif
