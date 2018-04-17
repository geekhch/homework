/*########################################################################
	【文件名】: 	ado.h
	【名  称】:		ADO 封装类.
	【版  本】:		0.20
	【作  者】:		成真
	【E-mail】:		anyou@sina.com
  ########################################################################*/
#if !defined(_ANYOU_COOL_ADOCOMMAND_H)
#define _ANYOU_COOL_ADOCOMMAND_H
#include "Ado.h"

/*########################################################################
			------------------------------------------------
						   CAdoParameter class
			------------------------------------------------
  ########################################################################*/
class CAdoParameter
{
// 构建/折构 -------------------------------------------
public:
	CAdoParameter();
	CAdoParameter(DataTypeEnum DataType, long lSize, ParameterDirectionEnum Direction, CString strName);
	virtual ~CAdoParameter();
// 属性 ------------------------------------------------
public:
	_ParameterPtr GetParameter() {return m_pParameter;}

	// 参数精度 ---------------------------
	BOOL SetPrecision(char nPrecision);

	// 参数小数位数 -----------------------
	BOOL SetNumericScale(int nScale);

	// 参数类型 ---------------------------
	ParameterDirectionEnum GetDirection();
	BOOL SetDirection(ParameterDirectionEnum Direction);
	
	// 参数名称 ---------------------------
	CString GetName();
	BOOL SetName(CString strName);

	// 参数长度 ---------------------------
	int GetSize();
	BOOL SetSize(int size);

	// 参数据类型 -------------------------
	DataTypeEnum GetType();
	BOOL SetType(DataTypeEnum DataType);

// 方法 ------------------------------------------------
public:	
	BOOL GetValue(COleDateTime &value);
	BOOL GetValue(CString &value);
	BOOL GetValue(double &value);
	BOOL GetValue(long &value);
	BOOL GetValue(int &value);
	BOOL GetValue(short &value);
	BOOL GetValue(BYTE &value);
	BOOL GetValue(bool &value);

	BOOL SetValue(const float &value);
	BOOL SetValue(const short &value);
	BOOL SetValue(const BYTE &value);
	BOOL SetValue(const COleDateTime &value);
	BOOL SetValue(const CString &value);
	BOOL SetValue(const double &value);
	BOOL SetValue(const long &value);
	BOOL SetValue(const int &value);
	BOOL SetValue(const bool &value);
	BOOL SetValue(const _variant_t &value);

//其他方法 ------------------------------
public:
	_ParameterPtr& operator =(_ParameterPtr& pParameter);

// 数据 ------------------------------------------------
protected:
	_ParameterPtr m_pParameter;
	CString m_strName;
	DataTypeEnum m_nType;
};


/*########################################################################
			------------------------------------------------
						   CAdoCommand class
			------------------------------------------------
  ########################################################################*/

class CAdoCommand
{
// 构建/折构 -------------------------------------------
public:
	CAdoCommand();
	CAdoCommand(CAdoConnection* pAdoConnection, CString strCommandText = _T(""), CommandTypeEnum CommandType = adCmdStoredProc);
	virtual ~CAdoCommand();

// 属性 ------------------------------------------------
public:
	_variant_t GetValue(LPCTSTR lpstrName);
	_variant_t GetValue(long index);

	_ParameterPtr GetParameter(long index);
	_ParameterPtr GetParamter(LPCTSTR lpstrName);

	BOOL Append(_ParameterPtr param);

	ParametersPtr GetParameters();
	
	BOOL SetCommandTimeOut(long lTime);

	long GetState();

	BOOL SetCommandType(CommandTypeEnum CommandType);
	BOOL SetCommandText(LPCTSTR lpstrCommand);

	CAdoParameter operator [](int index);
	CAdoParameter operator [](LPCTSTR lpszParamName);

// 实现 ------------------------------------------------
public:
	_ParameterPtr CreateParameter(LPCTSTR lpstrName, DataTypeEnum Type, 
								  ParameterDirectionEnum Direction, 
								  long Size, _variant_t Value);
	_RecordsetPtr CAdoCommand::Execute(long Options = adCmdStoredProc);
	BOOL Cancel();
	
// 其他方法 --------------------------------------------
public:
	_CommandPtr& GetCommand();
	BOOL SetConnection(CAdoConnection *pConnect);

// 数据 ------------------------------------------------
protected:
	void Release();
	_CommandPtr		m_pCommand;
	CString			m_strSQL;
};

#endif // !defined(_ANYOU_COOL_ADOCOMMAND_H)
