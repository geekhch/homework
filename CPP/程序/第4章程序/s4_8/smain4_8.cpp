//���ļ�
//�ļ�����s4_8\smain4_8.cpp

#include "sclass4_8_addition.h"			//����������ͷ�ļ�

//�����Գ���
int main()    
{
	CAddition oCA;						//����һ��CAddition��Ķ���
	oCA.Add(250, 250);					//����Add(int a, int b)
	oCA.Add("�ܶ�250������","====0");	//����Add(string s1, string s2)
	oCA.Add(128.118, 128.218);			//����Add(double d1, double d2)

	system("PAUSE");					//�ȴ�����������ʵ����ͣ  
	return 0;							//����0
}