//�ļ�·������s2_27\sclass2_27_staff.h

#include<iostream>   	     //����ͷ�ļ���ʹ��iostream�������������
using namespace std; 		     //ʹ��std�����ռ�

//Staff�������
class Staff
{
public:
	Staff( void );        	
	~Staff( void );         	
	void SetSalary( double s );
	int GetNumber( void ) ;             	
	double GetSalary( void ) ;
private:
	int number;              //�������
	float salary ;      	    //��н
	static int count;  	         //��ŵ�����
};
int Staff::count=1000;

Staff::Staff( void )
{	
	number=++count;  
	salary=1000.0; 
}         	
Staff::~Staff( void ){ }          	
void Staff::SetSalary( double s )
{
	salary=s;
}
int Staff::GetNumber( void ) 
{
	return number;
}                	
double Staff::GetSalary( void ) 
{
	return salary;
}

//�ļ�·������s2_27\smain2_27.cpp
//#include�� sclass2_27_staff.h��
int main( )
{
	Staff staff1, staff2, staff3, staff4;
	cout<<"��������һ��Ա������н��";
	double s;
	cin>>s;
	staff1.	SetSalary( s );
	cout<<endl<<"��������һ��Ա������н��";
	cin>>s;
	staff2.SetSalary( s );
	cout<<endl <<"��������һ��Ա������н��";
	cin>>s;
	staff3.SetSalary( s );
	cout<<endl <<"��������һ��Ա������н��";
	cin>>s;
	staff4. SetSalary( s );

	//��ʾstaff1����Ϣ
	cout<<"���"<< staff1.GetNumber ( )<<"����н��"<< staff1. GetSalary ( )<<endl;
	//��ʾstaff2����Ϣ
	cout<<"���"<< staff2.GetNumber ( )<<"����н��"<< staff2. GetSalary ( )<<endl;
	//��ʾstaff3����Ϣ
	cout<<"���"<< staff3.GetNumber ( )<<"����н��"<< staff3. GetSalary ( )<<endl;
	//��ʾstaff4����Ϣ
	cout<<"���"<< staff4.GetNumber ( )<<"����н��"<< staff4. GetSalary ( )<<endl;
	return 0;
}
