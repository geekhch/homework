//���ļ���s3_12\smain3_12.cpp
#include "sclass3_12.h"  

//���Գ���
int main( void )
{
	char flag ='Y';                        //�����ж��Ƿ����¼��ı�־����ʼ��Ϊ'Y'

	while ( toupper( flag ) == 'Y')
	{
		cout <<"��ѡ��¼�����1.����2.����Ա3.���۾���4.������Ա��";
		int n;
		cin >> n;

		switch ( n )
		{
			case 1:
			{
				CManager staff;        //����һ�����������
				staff.InPut( );          //���û���Ľӿ�
		 		staff.SetMData( );	  //���þ�����Ľӿ�
				staff.OutPut( );        //���û���Ľӿ�
				staff.CalculateSal( );    //���þ�����Ľӿ�
				break;
			}
			case 2:
			{
				CSaleman staff;       //����һ��������Ա�����
				staff.InPut( );
		 		staff.SetSData( );
				staff.OutPut( );
				staff.CalculateSal( );   //����������Ա��Ľӿ�
				break;
			}
			case 3:
			{
				CSaleManager staff;   //����һ�����۾��������
				staff.InPut( );
				staff.SetMData( );
		 		staff.SetSData( );	 				
				staff.OutPut( );
				staff.CalculateSal( );   //�������۾�����Ľӿ�
				break;
			}
			case 4:
			{
				CAdminStaff staff;     //����һ��������Ա�����
				staff.InPut( ); 	 				
				staff.OutPut( );
				staff.CalculateSal( );    //����������Ա��Ľӿ�
				break;
			}
			default: 
			{
				cout << "ѡ������!"<< endl;
				break;
			}
		}
		
		cout << endl <<"�Ƿ����¼����Ϣ����Y/N��";
		cin >> flag;		
	}
	return 0;
}
