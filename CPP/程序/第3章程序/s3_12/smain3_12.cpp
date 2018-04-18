//主文件：s3_12\smain3_12.cpp
#include "sclass3_12.h"  

//测试程序
int main( void )
{
	char flag ='Y';                        //设置判断是否继续录入的标志并初始化为'Y'

	while ( toupper( flag ) == 'Y')
	{
		cout <<"请选择录入类别（1.经理2.销售员3.销售经理4.行政人员）";
		int n;
		cin >> n;

		switch ( n )
		{
			case 1:
			{
				CManager staff;        //创建一个经理类对象
				staff.InPut( );          //调用基类的接口
		 		staff.SetMData( );	  //调用经理类的接口
				staff.OutPut( );        //调用基类的接口
				staff.CalculateSal( );    //调用经理类的接口
				break;
			}
			case 2:
			{
				CSaleman staff;       //创建一个销售人员类对象
				staff.InPut( );
		 		staff.SetSData( );
				staff.OutPut( );
				staff.CalculateSal( );   //调用销售人员类的接口
				break;
			}
			case 3:
			{
				CSaleManager staff;   //创建一个销售经理类对象
				staff.InPut( );
				staff.SetMData( );
		 		staff.SetSData( );	 				
				staff.OutPut( );
				staff.CalculateSal( );   //调用销售经理类的接口
				break;
			}
			case 4:
			{
				CAdminStaff staff;     //创建一个行政人员类对象
				staff.InPut( ); 	 				
				staff.OutPut( );
				staff.CalculateSal( );    //调用行政人员类的接口
				break;
			}
			default: 
			{
				cout << "选择有误!"<< endl;
				break;
			}
		}
		
		cout << endl <<"是否继续录入信息？（Y/N）";
		cin >> flag;		
	}
	return 0;
}
