//类声明文件名：s3_12\sclass3_12_ ceducation.h
#ifndef _SCLASS_3_12_CEDUCATION_H
#define _SCLASS_3_12_CEDUCATION _H
#include<iostream>   
#include<string.h>     
using namespace std; 

const int LEN = 50;                             //定义一个常量，表示字符数组长度

// CEducation（教育背景）类的声明
class CEducation 
{
public:
	CEducation( ){}; // 构造函数
	CEducation( char cSchool[], char cDegree );    //重载构造函数，为数据成员赋初值
	void GetEdu( void ) ;                  //输入教育背景的有关数据	
	void PutEdu( void ) const;                  //输出教育背景的有关信息
private:
	char m_cSchool[LEN];                    //毕业学校
	char m_cDegree;                         //最高学历：专科H、本科B、硕研M、博研D
};

class Staff                                   //员工类（公共基类、组合类）
{
public:
	Staff( void ){};                          //构造函数	
	~Staff( void ){};                         //空析构函数		
	void CalculateSal( void ){};                //计算实发工资
	void OutPut( void );                      //输出员工基本信息
	void InPut( void );                       //输入员工基本信息

protected:
	CEducation Edu;                        //子对象（教育背景）
	int m_iStaffNum;                       //工作编号
	char m_cName[LEN];         	 	    //姓名
	float m_fRateOfAttend;    		         //出勤率
	float m_fBasicSal ;         		    //基本工资
	float m_fPrize ;       		         //奖金
	static int s_iCount;                      //静态累加器
};

//声明派生类：CAdminStaff（行政人员）
class CAdminStaff : public Staff             
{
public:	
	CAdminStaff ( ){};                     //派生类构造函数
	~ CAdminStaff ( ){};                   //派生类构造函数
	void CalculateSal( void )  ;                      	
};

//声明派生类：CManager（经理）
class CManager : virtual public Staff           //将Staff指定为虚基类         
{
public:
	CManager( ){};                        //构造函数
	void SetMData( void );                  //输入经理数据
	void CalculateSal( void );                          	
protected:
	float m_fDeductTRate;                  //经理提成比例
	float m_fTAmount;                     //总销售额
};

//声明派生类：CSaleman（销售人员）
class CSaleman : virtual public Staff // 将Staff指定为虚基类
{
public:
	CSaleman ( ){};                       //构造函数
	void SetSData( void );                  //设置销售员数据
	void CalculateSal( void )  ;           	
protected:
	float m_fDeductRate;                   //销售员提成比例
	float m_fPersonAmount;                //个人销售额
};

//声明派生类：CSaleManager（销售经理）
class CSaleManager : public CSaleman, public CManager 
{
public:
	CSaleManager( ){};                                    
	void CalculateSal( void ) ;                     	
};

#endif
