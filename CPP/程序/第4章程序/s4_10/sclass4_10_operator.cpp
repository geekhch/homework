//���ʵ���ļ�
//�ļ�����s4_10\sclass4_10_operator.cpp

#include "sclass4_10_operator.h"		//����������ͷ�ļ�

//���캯��
COperator::COperator(int b): m_v(b)
{
	;
}
 	
int COperator::operator++(int i)	//���غ�׺++����ȡֵ�����Լ�
{
	int iRV = m_v;					//����һ����ʱ����ԭ���������ԭ����ֵ
	if(m_v<65635)
    	m_v++;						//�˴�++ΪϵͳĬ�Ϻ���;��Ϊm_v�ǻ�����������
	else					 
		m_v = 0;					//����65535����0
	return iRV;						//���ض���ԭֵ��Ҳ�����޸�ǰ��ֵ
}
  
int COperator::operator++()			//����ǰ׺++�����Լӣ���ȡֵ
{
	if(m_v<65635)
    	m_v++;						//�˴�++ΪϵͳĬ�Ϻ���;��Ϊm_v�ǻ�����������
	else					
		m_v = 0;					//����65535����0
	return m_v;						//�����޸ĺ�Ķ���ֵ
}
  
int COperator::operator()()			//���غ�������������ܣ�ȡm_v��ֵ
{
 	return m_v;
}

COperator COperator::operator+(const COperator &ob)	//�������������:����+����
{
	int v = m_v + ob.m_v;			//�����������m_vֵ��ӣ���Ϊ���ض����ֵ
	if (m_v>65635)
		v = v - 65636;				//��֤m_v��ֵ��0��65635֮��
	return COperator(v);
}

bool COperator::operator>(const COperator &ob)		//���رȽ������:����>����
{
	if (m_v > ob.m_v)
		return true;
	else
		return false;
}

bool COperator::operator<=(const COperator &ob)	//���رȽ������:����<=����
{
	if (m_v <= ob.m_v)
		return true;
	else
		return false;
}