//��ʵ���ļ�
//�ļ�·������s2_13\sclass2_13_sample.cpp 

#include "sclass2_13_sample.h"
CSample::CSample (int a)
{
	n = a;
}
CSample CSample::Add(CSample s1, CSample s2) 
//������������ݳ�Աn��ӣ����������ǰ���ú����Ķ��������n
{
	this -> n = s1.n + s2.n;
	return *this;	// ����thisָ����ָ��Ķ��󣬸ö����nΪ�������������n֮��
} 
int CSample::GetN() 
//��ȡ���ݳ�Աn��ֵ
{
	return n;
}
