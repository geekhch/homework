//���ļ�
//�ļ�����s4_7\smain4_7.cpp

#include "sclass4_7_CShape.h"		//����������ͷ�ļ�


//�����Գ���
int main()    
{
	//CShape oCPerson;				//���ܴ���������CPerson�Ķ���
	CShape * poCP;					//���Զ���һ�������ָ��
	CCircle oCC(10.0);				//����һ��CCircle��Ķ���
	CRectangle oCR(6.18, 5.0);		//����һ��CRectangle��Ķ���
	CSquare oCS(11.1);				//����һ��CSquare��Ķ���

	poCP = &oCC;					//�ó�����ָ��ָ��oCC����
	poCP->CalculateArea();			//ͨ��ָ�����oCC�ĳ�Ա����
	poCP = &oCR;					//�ó�����ָ��ָ��oCR����
	poCP->CalculateArea();			//ͨ��ָ�����oCR�ĳ�Ա����
	poCP = &oCS;					//�ó�����ָ��ָ��oCS����
	poCP->CalculateArea();			//ͨ��ָ�����oCS�ĳ�Ա����

	Reference(oCC);					//�����������oCC�����ò���
	Reference(oCR);					//�����������oCR�����ò���
	Reference(oCS);					//�����������oCS�����ò���

	system("PAUSE");				//�ȴ�����������ʵ����ͣ  
	return 0;						//����0
}
