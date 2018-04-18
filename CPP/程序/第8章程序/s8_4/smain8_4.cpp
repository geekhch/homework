//�ļ�����s8_4\smain8_4.cpp
//�ù��캯����ɻ������͵������͵�ת����ֻ�ܴ�һ����ȱʡ����
//��������ת��������������ת��Ϊ�����������͡�

#include <iostream>
#include <string>
using namespace std;

//����������CFigure��
class CFigure
{ 
public:
	//ֻ��һ��������ע��һ���������Բ��ô�ȱʡֵ��������������ת��Ϊ������
	CFigure(double d=0): m_value(d), m_name("anonymity"){}		// ���캯��1

	//ֻ����һ����ȱʡ����(������������ȱʡֵ)����ɱ�׼���͵������͵�ת��
	CFigure(int a, string name="pseudonym"): m_value(a), m_name(name) {} //���캯��2

	// ��������ת��Ϊһ��int
	operator int() const { return m_value; } 			//������ת������

	// ��������ת��Ϊһ��double
	operator double() const	{ return m_value; }			//������ת������

	void Print() const { cout << m_name << ": " << m_value << endl;	}

private:
	double m_value;			//�����ֵ
	string m_name;			//������
};

//���Ժ���
int main()
{
	int a;
	double b;
	CFigure oCF(5);			//���ù��캯��2������һ������
	oCF.Print();			//�����pseudonym:5
	oCF = 10;				//���ù��캯��2����һ������ת��Ϊһ������
	oCF.Print();			//�����pseudonym:10
	a = int(oCF);			//����operator int( )���ɲ���ǿ������ת��
	cout << "a=" << a <<endl;	//�����a=10
	oCF = 12.128;			//���ù��캯��1����һ��������ת��Ϊһ������
	oCF.Print();			//�����anonymity:12.128
	b = oCF;				//����operator double( ),����ʾ��ǿ������ת��Ҳһ��
	cout << "a=" << a << ", b=" << b << endl; //�����a=12,b=12.128

	system("PAUSE");		//�ȴ�����������ʵ����ͣ  
	return 0;				//����0
}