//���ļ�
//�ļ�����s4_9\smain4_9.cpp

#include "sclass4_9_circle.h"	//����������ͷ�ļ�

//�����Գ���
int main()    
{
	CCircle oCC;				//��ȱʡ���캯������oCC����
	Reference( );				//����ȫ�����غ���Reference()
	Reference(oCC);				//����ȫ�����غ���Reference(CCircle &roCC)
	oCC.Reference( );			//����oCC�ĳ�Ա����

	system("PAUSE");			//�ȴ�����������ʵ����ͣ  
	return 0;					//����0
}

