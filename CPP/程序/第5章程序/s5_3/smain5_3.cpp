//���ļ����ļ�����ch5_3\smain5_3.cpp

#include <iostream>			//����ͷ�ļ���ʹ��iostream��
#include <string>			//����ͷ�ļ���ʹ��string��
using namespace std;		//ʹ��std���ֿռ�

//����Integer��
class CInteger				
{
public:
	CInteger(int item): m_item(item) {}
	void SetItem(int item) { m_item = item; }
	int GetItem() const;

private:
	int m_item;
};

//����CFloat��
class CFloat					 
{
public:
	CFloat(float item): m_item(item) {}
	void SetItem(float item) { m_item = item; }
	float GetItem() const;

private:
	float m_item;
};

//����CInteger��Ա����
int CInteger::GetItem() const
{
	return m_item;
}

//����CFloat��Ա����
float CFloat::GetItem() const
{
	return m_item;
}

//���Գ���
int main()    
{
	CInteger Obj1(128);					//����һ��CInteger����
	cout << Obj1.GetItem( ) << endl;
	Obj1.SetItem(218);
	cout << Obj1.GetItem( ) << endl;

	CFloat Obj2(0.128);					//����һ��CFloat����
	cout << Obj2.GetItem( ) << endl;
	Obj2.SetItem(0.218);
	cout << Obj2.GetItem( ) << endl;

	system("PAUSE");					//�ȴ�����������ʵ����ͣ  
	return 0;							//����0
}

