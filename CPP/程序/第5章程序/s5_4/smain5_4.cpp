//���ļ����ļ�����ch5_4\smain5_4.cpp

#include <iostream>			//����ͷ�ļ���ʹ��iostream��
#include <string>			//����ͷ�ļ���ʹ��string��
using namespace std;		//ʹ��std���ֿռ�

//TClass����ģ�壬��CInteger���CFloat��ĳ�������������һ����ģ�壬
//����ģ��������ɾ����ģ���࣬ģ������������ڴ�������

//������ģ��
template <class Type> 
class TClass           
{
public:
	TClass(Type item): m_item(item) {}		//ʹ��ȱʡ����������
	void SetItem(Type item) { m_item = item; }
	Type GetItem() const;

private:
	Type m_item;
};
 
//������ģ���Ա����
template <class Type>
Type TClass<Type>::GetItem() const
{
	return m_item;
}

//���Գ���
int main()    
{
	TClass<int> Obj1(128);				//����һ��TClass<int>ģ�������
	cout << Obj1.GetItem( ) << endl;
	Obj1.SetItem(218);
	cout << Obj1.GetItem( ) << endl;

	TClass<float> Obj2(0.128);			//����һ��TClass<float>ģ�������
	cout << Obj2.GetItem( ) << endl;
	Obj2.SetItem(0.218);
	cout << Obj2.GetItem( ) << endl;

	system("PAUSE");					//�ȴ�����������ʵ����ͣ  
	return 0;							//����0
}

