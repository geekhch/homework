//���ļ���s3_9\smain3_9.cpp
#include <iostream>  
using namespace std; 

// ������������
class Furniture 
{
public:
	Furniture (float w): weight(w){}            
	void SetWeight(float w) { weight=w;}	//��������
	float GetWeight() const { return weight; }	//�õ�����
protected:
	float weight;							//����
};

class Bed: virtual public Furniture			//��������������Ϊ�����
{
public:
	Bed(float w): Furniture(w) {}			//һ�������๹�캯���������ʼ��������������ݳ�Ա
	void Sleep() { cout<<"��ʼ˯��"<<endl; }	//˯��		
};

class Sofa: virtual public Furniture		//�ڶ���һ��������ʱ���뽫������������Ϊ�����
{
public:
	Sofa(float w): Furniture(w) {}			//һ�������๹�캯���������ʼ��������������ݳ�Ա
	void WatchTV() { cout<<"���ڿ�����"<<endl; }//������		
};

class SofaBed : public Sofa, public Bed  
{
public:
	SofaBed(float w): Furniture(w), Sofa(w), Bed(w) {}  //��ʼ��3����������ݳ�Ա  
	void FoldOut() { cout<<"�����۵��ʹ�"<<endl; }	//�۵�
};

int main( )
{
	SofaBed sb(50.5);
	sb.SetWeight(51.9);
	cout<<"�Ҿ���"<<sb.GetWeight()<<"ǧ��"<<endl;
	sb.WatchTV();
	sb.FoldOut();
	sb.Sleep();

	return 0;
}
