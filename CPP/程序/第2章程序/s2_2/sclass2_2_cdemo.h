//�������ļ�
//�ļ�·������s2_2\sclass2_2_cdemo.h 

#ifndef __SCLASS2_2_CDEMO_H__		// ���δ����__SCLASS2_2_CDEMO_H__
#define __SCLASS2_2_CDEMO_H__		// ������__SCLASS2_2_CDEMO_H__��ֱ������#endif����

#include <iostream>  
using namespace std; 

//CDemo��Ķ���     
class CDemo
{
public:
	void SetI( int a )                 //�����ⲿ�ӿ�SetI( )Ϊi��ֵ
	{
		i = a;
	}
	void SetJ( int b )                 //�����ⲿ�ӿ�SetJ( )Ϊj��ֵ
	{
		j = b;
	}
	void GetI( ) 
	{
		cout << "i=" << i << endl;     //���i��ֵ
	}
	void GetJ( ) 
	{
		cout << "j=" << j << endl;     //���j��ֵ
	}
		
protected:
	int j;
private:
	int i;
};
#endif
