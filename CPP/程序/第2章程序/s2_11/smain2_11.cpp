// �ļ�·����: s2_11\smain2_11.cpp
#include "sclass2_11_rectangle.h"
int main() 
{
	//Ϊһ����10��5�ĳ����ζ�̬�����ڴ棬����ָ��rpָ������ڴ�
	Rectangle *rp= new Rectangle(10,5);  //�������ָ��
	rp->Print();      //����rp��ָ��Ķ���ĳ�Ա����print() 
	rp->SetSize(45, 20); 
	cout<<"��45��20�ĳ����ε������"<< rp->GetArea()<<endl;
	delete rp;        //�ͷ�ָ��rp��ָ��Ĵ洢�ռ�
	return 0; 
}

