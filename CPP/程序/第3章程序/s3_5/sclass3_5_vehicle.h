//�ļ�����s3_5\sclass3_5_vehicle.h
#include <iostream>
using namespace std; // ʹ��std�����ռ�

// ������ࣺ��ͨ����
class Vehicle
{
public:
	//���๹�캯�������ڳ�ʼ���������� 
	Vehicle( int w ,int wei)
	{
		wheels = w;
		weight=wei;
	}
	void Show() const
	{
		cout<<"��̥����"<<wheels<<endl;
		cout<<"���أ�"<<weight<<"kg"<<endl;
	}
private:
	int wheels;               //����
	int weight;               //����
};

// ����������
class Car : private Vehicle
{
public:	
	// �����๹�캯���ĳ�ʼ���б�
	Car( int w,int wei,  int p ):Vehicle( w , wei)        
	{
		 passengerLoad= p;  //��ʼ���������������ݳ�Ա	
	}
	void Show() const
	{
		//�������Ա����ͬ��˽�����ݳ�Ա
		cout <<"�˽γ�������ؿ�:"<< passengerLoad<< "��" << endl; 
		Vehicle::Show();    //�������Ա���ʻ���ͬ����Ա����show( )����ʾ����
	}
private: 
	int passengerLoad;       //�ؿ�����
};