//���ļ�
//�ļ�����ch4_5\smain4_5.cpp

#include "sclass4_5_student.h"	//����������ͷ�ļ�

//�����Գ���
void main()    
{
	CPerson oCP(7, 'm', "�ȶ�.�Ǵ�");						//����һ��CPerson��Ķ���
	CStudent oCS(8, 'f', "ϣ����.���ֶ�", "Grade Two");		//����һ��CStudent��Ķ���
	CClerk oCC(9, 'm', "л����.����", 5000.1);				//����һ��CClerk��Ķ���
	COnJobStudent oCO(10, 'm', "����.����", "Grade One", 4999.9);	//����һ����ְѧ������

	cout<<"\n1:-ͨ����������õ��ò�ͬ��Show( ):"<<endl;
	Reference(oCP);					//�Ի�����������ò���
	Reference(oCS);					//�����������oCS�����ò���
	Reference(oCC);					//�����������oCT�����ò���
	Reference(oCO);					//�����������oCO�����ò���

	cout<<"\n2:-ͨ������ָ����ò�ͬ��Show( ):"<<endl;
	CPerson *poCP;					//����һ������ָ��
	poCP = &oCP;					//ָ�����CPerson�����
	poCP->Show();					//����CPerson���Show()
	poCP = &oCS;					//ָ��������CStudent�����
	poCP->Show();					//����CStudent���Show()
	poCP = &oCC;					//ָ��������CTeacher�����
	poCP->Show();					//����CTeacher���Show()
	poCP = &oCO;					//ָ��������������oCO
	poCP->Show();					//����COnJobStudent���Show();
									//˵��ͨ������ָ��ɵ��ö����������麯�������麯�����д����ԡ�

	cout<<"\n3:-ͨ��һ��������ָ����ö����������Show( ):"<<endl;
	CStudent *poCS = &oCO;			//��һ��ָ��ָ����һ�������
	poCS->Show();					//����COnJobStudent���Show()
	COnJobStudent *poCO = &oCO;		//����ָ��ָ�������
	poCO->Show();					//����COnJobStudent���Show()

	cin.get();  
}
