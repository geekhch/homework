//��������ļ���s3_1\sclass3_1_A.h
#ifndef _SCLASS_3_1_A_H
#define _SCLASS_3_1_A _H
#include<iostream>  
using namespace std; 

// �������
class A
{
public:
	void SetX(int i);		//Ϊ���ݳ�Աx��ֵ
	int GetX() const;		//��ȡ���ݳ�Աx��ֵ
	int z;					//����Ĺ������ݳ�Ա
protected:
	int y;					//����ı������ݳ�Ա
private:
	int x;					//�����˽�����ݳ�Ա
};

//����������
class B : public A			//��B���м̳���A
{
public:
	//Ϊ����ͱ����е��������ݳ�Ա��ֵ
	void SetValue(int, int, int, int, int);
	void Display() const;	//��ʾ�����ݳ�Ա��ֵ
protected:
	int m;					//������ı������ݳ�Ա
private:
	int n;					//�������˽�����ݳ�Ա
};
#endif
