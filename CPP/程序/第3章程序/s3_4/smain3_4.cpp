//�ļ�����s3_4\smain3_4.cpp
#include <iostream> 
#include <string>
using namespace std; 

// ������ࣺCBase
class CBase
{
public:
   	CBase() { n = 0; m = 0; }	//���캯��
	void SetValue(int a, int b) //Ϊ���ݳ�Աm��n��ֵ
	{
		n = a;
		m = b;
	}
	void CalcuValue()			//���ڼ���Ľӿڣ�������������ʾ����Ļ��   
	{ 
	cout << "n��m �� " << m*n << endl; 
	}
protected:
	int m;						//������Ա
	int n;						//������Ա 
};

//���������ࣺCDerived��Ϊ��ָ������CBase���̳з�ʽCBase��
class CDerived : protected CBase 
{
public:
	CDerived() {}
	void SetJ(int j)
	{
		this->j =j+m;				//�������Ա���Է��ʻ���ı�������m
	}
	void SetK(int k)
	{
		this->k = k;
	}
	void DisplayVal() const
	{
		cout << "�������Աj �� " << j << endl;
		cout << "�������Աk �� " << k << endl;
	}
private:
	int j;
	int k;
};
// ���Գ���
int main()
{
	CDerived d;             //�������������d		
	//d.SetValue(10,20);    //������ΪSetValue( )�ѱ��CDerived��ı�����Ա�����ⲻ�ܷ���
	//d.CalcuValue();		//������ΪCalcuValue ( )�ѱ��CDerived��ı�����Ա�����ⲻ�ܷ���
	d.SetJ(10);				//��ȷ����Ϊd���ñ���Ĺ��г�Ա����
	d.SetK(15);				//��ȷ����Ϊd���ñ���Ĺ��г�Ա����
	d.DisplayVal();			//��ȷ����Ϊd���ñ���Ĺ��г�Ա����
	CBase b;                //�����������b
	b. SetValue(10,20);     //��ȷ����Ϊb������������ʱ���Ĺ��г�Ա����SetValue
	b. CalcuValue();		//��ȷ����Ϊb������������ʱ���Ĺ��г�Ա����CalcuValue
	return 0;
}
