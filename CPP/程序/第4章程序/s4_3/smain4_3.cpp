//���ļ�
//�ļ�����s4_3\smain4_3.cpp

#include "sclass4_3_CShape.h"				//����������ͷ�ļ�

//�������ò���
void Reference(const CShape &roCS)			//�����������Ϊ�β�  
{
	roCS.Show();  
}

//�����Գ���
int main()    
{
	CShape oCS(1.1, 2.0, 3.0);				//����һ��CShape��Ķ���
	CCircle oCC(10.0, 20.1, 30.0, 100.0);	//����һ��CCircle��Ķ���
	CRectangle oCR(1.1, 1.2, 1.3, 5.4, 5.5);//����һ��CRectangle��Ķ���
	CSquare oCSq(2.2, 2.3, 2.4, 10.8);		//����һ��CSquare��Ķ���

	cout<<"\n 1 : -ͨ����������õ����麯������������----��"<<endl;
	Reference(oCS);							//�Ի���CShape���������ò���
	Reference(oCC);							//��������CCircle���������ò���
	Reference(oCR);							//��������CRectangle���������ò���
	Reference(oCSq);						//��������CSquare���������ò���

	cout<<"\n 2 : -ͨ�������ָ������麯������������----��"<<endl;
	CShape *poCS;							//�������CShape��ָ�����
	poCS = &oCS;							//����ָ��ָ��������oCS
	poCS->Show();							//ͨ������ָ����û����Show( )����
	poCS = &oCC;							//�������ָ��ָ�����������oCC
	poCS->Show();							//ͨ������ָ������������Show( )����
	poCS = &oCR;							//����ָ��ָ��������oCR
	poCS->Show();							//ͨ������ָ����û����Show( )����
	poCS = &oCSq;							//�������ָ��ָ�����������oCSq
	poCS->Show();							//ͨ������ָ������������Show( )����

	cout<<"\n 3 : -ͨ��������ò����������ԣ���������ȷ----��"<<endl;
	oCS.Show();								//ֱ��ͨ���������oCS����Show( )����
	oCC.Show();								//ֱ��ͨ�����������oCC����Show( )����
	oCR.Show();								//ֱ��ͨ�����������oCR����Show( )����
	oCSq.Show();							//ֱ��ͨ�����������oCSq����Show( )����

	system("PAUSE");						//�ȴ�����������ʵ����ͣ  
	return 0;								//����0
}
