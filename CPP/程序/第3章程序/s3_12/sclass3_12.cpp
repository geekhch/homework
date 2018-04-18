// 类实现文件名：s3_12\sclass3_12_ceducation.cpp
#include "sclass3_12.h"

int Staff::s_iCount = 1000;                   //初始化静态数据成员s_iCount
CEducation::CEducation( char cSchool[ ], char cDegree ) 
{
	strcpy( m_cSchool, cSchool );
	m_cDegree = cDegree;
}
void CEducation::GetEdu( void ) 
{
	cout << endl <<"  毕业学校：";
	cin >> m_cSchool;
	cout << endl <<"  最高学历：（专科H、本科B、硕研M、博研D）";
	cin >> m_cDegree;
	// 用toupper函数将用户输入的学历规范为大写字符
	m_cDegree = toupper( m_cDegree );	
}

//实现类CEducation的成员函数PutEdu，输出信息
void CEducation::PutEdu( void ) const
{
	cout << endl <<"  毕业学校："<< m_cSchool << endl;
	cout << endl <<"  最高学历：";
	switch ( m_cDegree )         
	{
		case 'H': 
			cout <<"专科"<< endl;
			break;
		case 'B': 
			cout <<"本科"<< endl;
			break;
		case 'M': 
			cout <<"硕研"<< endl;
			break;
		case 'D': 
			cout <<"博研"<< endl;
			break;
		default:  
			cout <<"空"<< endl;  //输入的学历在选项之外则为"空"
			break;
	}
}
void CAdminStaff::CalculateSal( void )                        
{
	cout << endl <<" 当月实发工资："
		<< m_fBasicSal + m_fPrize * m_fRateOfAttend <<"元"<< endl;
}
void CManager::SetMData( void )      //输入经理数据
{
	cout << endl <<"  公司总销售额：";
	cin >> m_fTAmount;
	cout << endl <<"  提成比例：";
	cin >> m_fDeductTRate;
}

//计算经理的实际发放工资：基本工资＋总销售额×提成比例
void CManager::CalculateSal( void )                          
{
	cout << endl <<"  当月实际发放工资：";
	cout << m_fBasicSal + m_fTAmount * m_fDeductTRate <<"元"<< endl;
}
void CSaleman::SetSData( void )      //设置销售员数据
{
	cout << endl <<"  个人销售额：";
	cin >> m_fPersonAmount;
	cout << endl <<"  提成比例：";
	cin >> m_fDeductRate;
}
 //计算销售员的实际发放工资：基本工资＋个人销售额×提成比例
void CSaleman::CalculateSal( void )             
{
	cout << endl <<"  当月实际发放工资：";
	cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate <<"元"<< endl;
}	
/* 	计算销售经理实发工资: 
	基本工资＋个人销售额×销售员提成比例＋总销售额×经理提成比例
*/
void CSaleManager::CalculateSal( void )                      
{
	cout << endl <<"  当月实际发放工资：";
	cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate 
			+ m_fTAmount * m_fDeductTRate; 
	cout <<"元"<< endl;
}
// 实现类Staff的成员函数InPut，输入员工各项数据
void Staff:: InPut( void )
{
	m_iStaffNum = ++s_iCount;     //静态累加器自加1后赋给工作编号
	cout << endl << "请输入编号为"<< m_iStaffNum <<"号员工的姓名：";
	cin >> m_cName;	         //输入员工姓名
	Edu.GetEdu( );               //子对象调用类CEducation的接口GetEdu，输入教育背景相关数据	
	cout << endl << "  基本工资：";
	cin >> m_fBasicSal;          //输入基本工资
	cout << endl << "  奖金：";
	cin >> m_fPrize;             //输入奖金
	cout << endl <<"  出勤率：";
	cin >> m_fRateOfAttend;      //输入出勤率

	//规范用户输入的出勤率的值
	if ( m_fRateOfAttend > 1.0 )
	{
		m_fRateOfAttend = 1.0;
	}
	else if ( m_fRateOfAttend < 0 )
	{
		m_fRateOfAttend = 0;
	}
}
//实现类Staff的成员函数OutPut，输出员工信息
void Staff:: OutPut( void )
{
	cout << endl << "显示员工" << m_cName <<"的基本数据：";
	cout << endl << "  工作编号：" << m_iStaffNum;
	Edu.PutEdu( );            //通过子对象调用类CEducation的接口PutEdu
	cout << endl << "  基本工资：" << m_fBasicSal;
	cout << endl << "  奖金：" << m_fPrize;	
	cout << endl << "  出勤率：" <<  m_fRateOfAttend * 100 << "%";
}

