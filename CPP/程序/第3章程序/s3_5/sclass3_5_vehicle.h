//文件名：s3_5\sclass3_5_vehicle.h
#include <iostream>
using namespace std; // 使用std命名空间

// 定义基类：交通工具
class Vehicle
{
public:
	//基类构造函数，用于初始化基类数据 
	Vehicle( int w ,int wei)
	{
		wheels = w;
		weight=wei;
	}
	void Show() const
	{
		cout<<"轮胎数："<<wheels<<endl;
		cout<<"车重："<<weight<<"kg"<<endl;
	}
private:
	int wheels;               //轮数
	int weight;               //车重
};

// 定义派生类
class Car : private Vehicle
{
public:	
	// 派生类构造函数的初始化列表
	Car( int w,int wei,  int p ):Vehicle( w , wei)        
	{
		 passengerLoad= p;  //初始化派生类新增数据成员	
	}
	void Show() const
	{
		//派生类成员访问同类私有数据成员
		cout <<"此轿车最多能载客:"<< passengerLoad<< "人" << endl; 
		Vehicle::Show();    //派生类成员访问基类同名成员函数show( )，显示轮数
	}
private: 
	int passengerLoad;       //载客人数
};