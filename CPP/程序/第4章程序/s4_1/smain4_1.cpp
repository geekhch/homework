//���ļ�
//�ļ�����ch4_1\smain4_1.cpp

#include "sclass4_1_CShape.h"				//����������ͷ�ļ�

//�����Գ���
int main()    
{
	CShape oCS(1.1, 2.0, 3.0);				//����һ��CShape��Ķ���
	CShape *poCS;							//�������CShape��ָ�����
	CCircle oCC(10.0, 20.1, 30.0, 100.0);	//����һ��CCircle��Ķ���
	poCS = &oCS;							//����ָ��ָ��������
	poCS->Show();							//ͨ������ָ�����Show()����
	poCS = &oCC;							//�������ָ��ָ�����������
	poCS->Show();							//ͨ������ָ�����Show()����
	system("PAUSE");						//�ȴ�����������ʵ����ͣ  
	return 0;								//����0
}