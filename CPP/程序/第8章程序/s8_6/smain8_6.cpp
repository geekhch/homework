//�ļ�����s8_6\smain8_6.cpp
//�����ռ��ʹ��

#include <iostream>
using namespace std;

int iNum = 10000;			//ȫ�ֱ���

// MyNameSpace.h
namespace MyNameSpace		//���������ռ�MyNameSpace
{
	int  iNum = 2000;		//MyNameSpace�ռ��еı���
	int Add(int iNum)		//MyMameSpace�ռ��еĺ���Add( )
	{
		iNum = iNum + iNum;	//���ʵ���Add�ڵľֲ�����
		return iNum;
	}
} 

// YourNameSpace.h
namespace YourNameSpace		//���������ռ�YourNameSpace
{
	int  iNum = 300000;		//YourNameSpace�ռ��еı���
	int Add(int iNum)		//YourNameSpace�ռ��е�Add( )
	{
		iNum = ::iNum + iNum;	//::iNum����ȫ��iNum
		return iNum;
	}
}

//���Գ���
int main()
{
	cout << MyNameSpace::Add(1)+::iNum << endl;	//ʹ��ȫ��iNum
	cout << MyNameSpace::Add(1)+iNum << endl;	//ʹ��ȫ��iNum
	
	namespace N2 = YourNameSpace;			//����YourNameSpace�ı���
	cout << N2::Add(1)+N2::iNum << endl;		//��ʾʹ�õ���YourNameSpace�����ռ�

	using namespace YourNameSpace;				//ʹ��using�ؼ��֡�
	cout << Add(1)+MyNameSpace::iNum << endl;	//������ȫ��iNum������Ҫʹ�����ƣ�
	//����ȫ��Add���������������޶���ϵͳ֪������YourNameSpace�ռ��е�Add
	//cout << iNum << endl;	//�����������iNum���ֶ�����

	system("PAUSE");					//�ȴ�����������ʵ����ͣ  
	return 0;							//����0
}
