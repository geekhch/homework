//���ļ�
//�ļ�����s4_6\smain4_6.cpp

#include "sclass4_6_student.h"		//����������ͷ�ļ�

//�����Գ���
int main()    
{
	CPerson *poCP = new CStudent;	//����һ��CStudent�Ķ�̬����
	if (NULL == poCP)				//���new����ʧ�ܣ����˳�
	{
		exit(1);					//����0��ʾ�������˳�����
	}
	delete poCP;					//ͨ������ָ���������������
	cout << "ͨ��delete����new����������Ķ������! \n" << endl; 

	CStudent oCSt;		//����һ��CStudent���󣬲�ʹ��deleteʱ�������ܹ���ȷ����

	return 0;						//����0
}
