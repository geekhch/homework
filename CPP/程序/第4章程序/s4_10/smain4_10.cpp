//���ļ�
//�ļ�����s4_10\smain4_10.cpp

#include "sclass4_10_operator.h"		//����������ͷ�ļ�

//������
int main()    
{ 
	COperator oCO1, oCO2(10);

  	oCO1 = ++oCO2;			//�˴�Ϊ���ص�ǰ׺++,��ΪoCO2��COperator�Ķ���
							//oCO1()��������(),��ΪoCO1��COperator�Ķ���
  	cout << "ǰ׺++: " << oCO1() <<  " = " <<  oCO2.m_v << endl; 

  	oCO1 = oCO2++;			//�˴�Ϊ���غ�׺++,��ΪoCO2��COperator�Ķ���
  	cout << "��׺++: " <<  oCO1.m_v <<  " < " <<  oCO2.m_v << endl; 

 
  	oCO1 = 10;				//��Ĭ�����������������ʽת������10��ֵ������
  	cout << "��ֵ��: " <<  oCO1.m_v << endl;  
  	oCO2 = oCO2 + oCO1;
  	cout << "����+����: " <<  oCO1.m_v <<  "; " <<  oCO2.m_v<< endl;  	

  	cout << "����>����: " <<  (oCO2 > oCO1) << endl;  
  	cout << "����<=����: " << (oCO2 <= oCO1) << endl;  

	system("PAUSE");		//�ȴ�����������ʵ����ͣ  
	return 0;				//����0
}

