
#include "sclass4_4_student.h"	//����������ͷ�ļ�
#include <stdlib.h>

void Test(CPerson & p)
{
	p.Show();
	p.Show(1);
}
//�����Գ���
int main()    
{
	CPerson *poCP;							//����ָ���������ָ��?
	CStudent oCS(8, "Clinton", "Grade Two");//����һ�����������?
	poCP = &oCS;		//����ָ��ָ�����������?
	oCS.Show(1);		//ͨ�����������ֻ�ܵ������������¶����ͬ������
	//oCS.Show();		//ͨ������������ܵ��ñ����صĻ��ຯ��?
	poCP->Show();		//ͨ������ָ����ຯ��Show()
	poCP->Show(1);		//���麯��ʱ��ͨ������ָ����Ե��ñ����صĻ���Show()
	Test(oCS);
	Test(*poCP);
						//�麯��ʱ���γɸ��ǹ�ϵ�����Ե����������Show(1)
	system("pause");						//�ȴ�����������ʵ����ͣ  
	return 0;								//����0
}



