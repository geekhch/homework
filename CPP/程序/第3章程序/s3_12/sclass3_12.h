//�������ļ�����s3_12\sclass3_12_ ceducation.h
#ifndef _SCLASS_3_12_CEDUCATION_H
#define _SCLASS_3_12_CEDUCATION _H
#include<iostream>   
#include<string.h>     
using namespace std; 

const int LEN = 50;                             //����һ����������ʾ�ַ����鳤��

// CEducation�������������������
class CEducation 
{
public:
	CEducation( ){}; // ���캯��
	CEducation( char cSchool[], char cDegree );    //���ع��캯����Ϊ���ݳ�Ա����ֵ
	void GetEdu( void ) ;                  //��������������й�����	
	void PutEdu( void ) const;                  //��������������й���Ϣ
private:
	char m_cSchool[LEN];                    //��ҵѧУ
	char m_cDegree;                         //���ѧ����ר��H������B��˶��M������D
};

class Staff                                   //Ա���ࣨ�������ࡢ����ࣩ
{
public:
	Staff( void ){};                          //���캯��	
	~Staff( void ){};                         //����������		
	void CalculateSal( void ){};                //����ʵ������
	void OutPut( void );                      //���Ա��������Ϣ
	void InPut( void );                       //����Ա��������Ϣ

protected:
	CEducation Edu;                        //�Ӷ��󣨽���������
	int m_iStaffNum;                       //�������
	char m_cName[LEN];         	 	    //����
	float m_fRateOfAttend;    		         //������
	float m_fBasicSal ;         		    //��������
	float m_fPrize ;       		         //����
	static int s_iCount;                      //��̬�ۼ���
};

//���������ࣺCAdminStaff��������Ա��
class CAdminStaff : public Staff             
{
public:	
	CAdminStaff ( ){};                     //�����๹�캯��
	~ CAdminStaff ( ){};                   //�����๹�캯��
	void CalculateSal( void )  ;                      	
};

//���������ࣺCManager������
class CManager : virtual public Staff           //��Staffָ��Ϊ�����         
{
public:
	CManager( ){};                        //���캯��
	void SetMData( void );                  //���뾭������
	void CalculateSal( void );                          	
protected:
	float m_fDeductTRate;                  //������ɱ���
	float m_fTAmount;                     //�����۶�
};

//���������ࣺCSaleman��������Ա��
class CSaleman : virtual public Staff // ��Staffָ��Ϊ�����
{
public:
	CSaleman ( ){};                       //���캯��
	void SetSData( void );                  //��������Ա����
	void CalculateSal( void )  ;           	
protected:
	float m_fDeductRate;                   //����Ա��ɱ���
	float m_fPersonAmount;                //�������۶�
};

//���������ࣺCSaleManager�����۾���
class CSaleManager : public CSaleman, public CManager 
{
public:
	CSaleManager( ){};                                    
	void CalculateSal( void ) ;                     	
};

#endif
