// ��ʵ���ļ�����s3_12\sclass3_12_ceducation.cpp
#include "sclass3_12.h"

int Staff::s_iCount = 1000;                   //��ʼ����̬���ݳ�Աs_iCount
CEducation::CEducation( char cSchool[ ], char cDegree ) 
{
	strcpy( m_cSchool, cSchool );
	m_cDegree = cDegree;
}
void CEducation::GetEdu( void ) 
{
	cout << endl <<"  ��ҵѧУ��";
	cin >> m_cSchool;
	cout << endl <<"  ���ѧ������ר��H������B��˶��M������D��";
	cin >> m_cDegree;
	// ��toupper�������û������ѧ���淶Ϊ��д�ַ�
	m_cDegree = toupper( m_cDegree );	
}

//ʵ����CEducation�ĳ�Ա����PutEdu�������Ϣ
void CEducation::PutEdu( void ) const
{
	cout << endl <<"  ��ҵѧУ��"<< m_cSchool << endl;
	cout << endl <<"  ���ѧ����";
	switch ( m_cDegree )         
	{
		case 'H': 
			cout <<"ר��"<< endl;
			break;
		case 'B': 
			cout <<"����"<< endl;
			break;
		case 'M': 
			cout <<"˶��"<< endl;
			break;
		case 'D': 
			cout <<"����"<< endl;
			break;
		default:  
			cout <<"��"<< endl;  //�����ѧ����ѡ��֮����Ϊ"��"
			break;
	}
}
void CAdminStaff::CalculateSal( void )                        
{
	cout << endl <<" ����ʵ�����ʣ�"
		<< m_fBasicSal + m_fPrize * m_fRateOfAttend <<"Ԫ"<< endl;
}
void CManager::SetMData( void )      //���뾭������
{
	cout << endl <<"  ��˾�����۶";
	cin >> m_fTAmount;
	cout << endl <<"  ��ɱ�����";
	cin >> m_fDeductTRate;
}

//���㾭���ʵ�ʷ��Ź��ʣ��������ʣ������۶����ɱ���
void CManager::CalculateSal( void )                          
{
	cout << endl <<"  ����ʵ�ʷ��Ź��ʣ�";
	cout << m_fBasicSal + m_fTAmount * m_fDeductTRate <<"Ԫ"<< endl;
}
void CSaleman::SetSData( void )      //��������Ա����
{
	cout << endl <<"  �������۶";
	cin >> m_fPersonAmount;
	cout << endl <<"  ��ɱ�����";
	cin >> m_fDeductRate;
}
 //��������Ա��ʵ�ʷ��Ź��ʣ��������ʣ��������۶����ɱ���
void CSaleman::CalculateSal( void )             
{
	cout << endl <<"  ����ʵ�ʷ��Ź��ʣ�";
	cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate <<"Ԫ"<< endl;
}	
/* 	�������۾���ʵ������: 
	�������ʣ��������۶������Ա��ɱ����������۶��������ɱ���
*/
void CSaleManager::CalculateSal( void )                      
{
	cout << endl <<"  ����ʵ�ʷ��Ź��ʣ�";
	cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate 
			+ m_fTAmount * m_fDeductTRate; 
	cout <<"Ԫ"<< endl;
}
// ʵ����Staff�ĳ�Ա����InPut������Ա����������
void Staff:: InPut( void )
{
	m_iStaffNum = ++s_iCount;     //��̬�ۼ����Լ�1�󸳸��������
	cout << endl << "��������Ϊ"<< m_iStaffNum <<"��Ա����������";
	cin >> m_cName;	         //����Ա������
	Edu.GetEdu( );               //�Ӷ��������CEducation�Ľӿ�GetEdu��������������������	
	cout << endl << "  �������ʣ�";
	cin >> m_fBasicSal;          //�����������
	cout << endl << "  ����";
	cin >> m_fPrize;             //���뽱��
	cout << endl <<"  �����ʣ�";
	cin >> m_fRateOfAttend;      //���������

	//�淶�û�����ĳ����ʵ�ֵ
	if ( m_fRateOfAttend > 1.0 )
	{
		m_fRateOfAttend = 1.0;
	}
	else if ( m_fRateOfAttend < 0 )
	{
		m_fRateOfAttend = 0;
	}
}
//ʵ����Staff�ĳ�Ա����OutPut�����Ա����Ϣ
void Staff:: OutPut( void )
{
	cout << endl << "��ʾԱ��" << m_cName <<"�Ļ������ݣ�";
	cout << endl << "  ������ţ�" << m_iStaffNum;
	Edu.PutEdu( );            //ͨ���Ӷ��������CEducation�Ľӿ�PutEdu
	cout << endl << "  �������ʣ�" << m_fBasicSal;
	cout << endl << "  ����" << m_fPrize;	
	cout << endl << "  �����ʣ�" <<  m_fRateOfAttend * 100 << "%";
}

