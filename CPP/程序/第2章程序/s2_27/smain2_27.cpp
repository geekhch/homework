//文件路径名：s2_27\sclass2_27_staff.h

#include<iostream>   	     //包含头文件，使用iostream库用于输入输出
using namespace std; 		     //使用std命名空间

//Staff类的声明
class Staff
{
public:
	Staff( void );        	
	~Staff( void );         	
	void SetSalary( double s );
	int GetNumber( void ) ;             	
	double GetSalary( void ) ;
private:
	int number;              //工作编号
	float salary ;      	    //月薪
	static int count;  	         //编号递增器
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

//文件路径名：s2_27\smain2_27.cpp
//#include” sclass2_27_staff.h”
int main( )
{
	Staff staff1, staff2, staff3, staff4;
	cout<<"请输入下一个员工的月薪：";
	double s;
	cin>>s;
	staff1.	SetSalary( s );
	cout<<endl<<"请输入下一个员工的月薪：";
	cin>>s;
	staff2.SetSalary( s );
	cout<<endl <<"请输入下一个员工的月薪：";
	cin>>s;
	staff3.SetSalary( s );
	cout<<endl <<"请输入下一个员工的月薪：";
	cin>>s;
	staff4. SetSalary( s );

	//显示staff1的信息
	cout<<"编号"<< staff1.GetNumber ( )<<"的月薪是"<< staff1. GetSalary ( )<<endl;
	//显示staff2的信息
	cout<<"编号"<< staff2.GetNumber ( )<<"的月薪是"<< staff2. GetSalary ( )<<endl;
	//显示staff3的信息
	cout<<"编号"<< staff3.GetNumber ( )<<"的月薪是"<< staff3. GetSalary ( )<<endl;
	//显示staff4的信息
	cout<<"编号"<< staff4.GetNumber ( )<<"的月薪是"<< staff4. GetSalary ( )<<endl;
	return 0;
}
