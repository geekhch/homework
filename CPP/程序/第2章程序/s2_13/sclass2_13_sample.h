//�������ļ�
//�ļ�·������s2_13\sclass2_13_sample.h 

//����Ԥ������䣺���δ����__SCLASS2_13_SAMPLE_H__��������
//ֱ������#endif������
#ifndef __SCLASS2_13_SAMPLE_H__ 
#define __SCLASS2_13_SAMPLE_H__ 

#include<iostream> 
using namespace std;

class CSample
{
public:	
	CSample(){};	
	CSample(int a);							//���ع��캯��
	CSample Add(CSample s1, CSample s2);	//��2����������ݳ�Աn��ӣ����������ǰ���ú����Ķ��������n
	int GetN();								//��ȡ���ݳ�Աn��ֵ
private:
	int n;              	 
};
#endif

