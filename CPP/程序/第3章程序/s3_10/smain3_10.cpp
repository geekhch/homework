//�ļ�����s3_10\smain3_10.cpp
#include <iostream>  
using namespace std; 

// �������Base1
class Base1
{
public:
	Base1(){cout <<"class Base1"<<endl; }		//���캯��
};

// �������Base2
class Base2
{
public:
	Base2() { cout <<"class Base2"<<endl; }		//���캯��
};

// ����������Level1��ʹ��ӵ����������Base1��Base2��
// ����ָ��Base1����̳�·����Ϊ�����
class Level1: public Base2, virtual public Base1
{
public:
	Level1() { cout <<"class Level1"<<endl; }	//���캯��
};

// ����������Level2
// Level2��Level1ӵ�й�ͬ���������࣬���һ���Base1��Level2�ļ̳�·����ҲΪ�����
class Level2: public Base2, virtual public Base1
{
public:
	Level2() { cout << "class Level2" <<endl; }      //���캯��
};

//����������Leaf
//������Level2��Level1��ͬ������Leaf�࣬������Level2Ϊ�����
class Leaf: public Level1, virtual public Level2
{
public:
	Leaf() { cout << "class Leaf" <<endl; }
};

// ���Գ���
int main()
{
	Leaf obj;  //����һ��������Leaf�Ķ���
	return 0;
}
