//���ļ���s3_3\smain3_3.cpp
#include "sclass3_3_cbase.h"
int main()
{	
	CDerived d;			//�������������d
	d.SetValue(10,20);	//���������d���û�����ⲿ�ӿ�SetValue()��Ϊ��������ݳ�Աm��n����ֵ
	d.CalcuValue();		//����d���û�����ⲿ�ӿ�CalcuValue()������������ʾ����Ļ��
	d.SetJ();			//����d���ñ�����ⲿ�ӿ�SetJ()��Ϊͬ������ݳ�Աj����ֵ
	d.SetK();			//����d���ñ�����ⲿ�ӿ�SetK()��Ϊͬ������ݳ�Աk����ֵ
	d.DisplayVal();		//����d���ñ�����ⲿ�ӿ�DisplayVal()����ͬ����j��k��ֵ��ʾ����Ļ��
	return 0;
}
