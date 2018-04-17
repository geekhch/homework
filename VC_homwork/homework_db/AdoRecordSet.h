/*########################################################################
	【文件名】: 	ado.h
	【名  称】:		ADO 封装类.
	【版  本】:		0.20
	【作  者】:		成真
	【E-mail】:		anyou@sina.com
  ########################################################################*/
#if !defined(_ANYOU_COOL_ADORECORDSET_H)
#define _ANYOU_COOL_ADORECORDSET_H
#include "Ado.h"

/*########################################################################
			 ------------------------------------------------
						  CAdoRecordSet class
			 ------------------------------------------------
  ########################################################################*/

class CAdoRecordSet 
{
// 构建/折构 --------------------------------------------
public:
	CAdoRecordSet();
	CAdoRecordSet(CAdoConnection *pConnection);

	virtual ~CAdoRecordSet();
	
protected:
	void Release();
	
// 属性 ------------------------------------------------	
public:
	// 当前编辑状态 ----------------------------
	EditModeEnum GetEditMode();
	
	// 当前状态 --------------------------------
	BOOL IsEOF();
	BOOL IsBOF();
	BOOL IsOpen();
	long GetState();
	long GetStatus();

	// 充许返回的最大记录数 --------------------
	long GetMaxRecordCount();
	BOOL SetMaxRecordCount(long count);
	
	// 光标位置 --------------------------------
	CursorLocationEnum GetCursorLocation();
	BOOL SetCursorLocation(CursorLocationEnum CursorLocation = adUseClient);
	
	// 光标类型 --------------------------------
	CursorTypeEnum GetCursorType();
	BOOL SetCursorType(CursorTypeEnum CursorType = adOpenStatic);
	
	// 书签 --------------------------------
	_variant_t GetBookmark();
	BOOL SetBookmark(_variant_t varBookMark = _variant_t((long)adBookmarkFirst));
	
	// 当前记录位置 ------------------------
	long GetAbsolutePosition();
	BOOL SetAbsolutePosition(int nPosition);

	long GetAbsolutePage();
	BOOL SetAbsolutePage(int nPage);

	// 每页的记录数 ------------------------
	long GetPageSize();
	BOOL SetCacheSize(const long& lCacheSize);	

	// 页数 --------------------------------
	long GetPageCount();

	// 记录数及字段数 ----------------------
	long GetRecordCount();
	long GetFieldsCount();
	
	// 查询字符串 --------------------------
	CString GetSQLText() {return m_strSQL;}
	void SetSQLText(LPCTSTR strSQL) {m_strSQL = strSQL;}
	
	// 连接对象 ----------------------------
	CAdoConnection* GetConnection() {return m_pConnection;}
	void SetAdoConnection(CAdoConnection *pConnection);

	// 记录集对象 --------------------------
	_RecordsetPtr& GetRecordset();

	CString GetLastError();

// 字段属性 ----------------------------------------------
public:
	// 字段集 -------------------------------
	FieldsPtr GetFields();

	// 字段对象 -----------------------------
	FieldPtr  GetField(long lIndex);
	FieldPtr  GetField(LPCTSTR lpszFieldName);
	
	// 字段名 -------------------------------
	CString GetFieldName(long lIndex);
	
	// 字段数据类型 -------------------------
	DataTypeEnum GetFieldType(long lIndex);
	DataTypeEnum GetFieldType(LPCTSTR lpszFieldName);

	// 字段属性 -----------------------------
	long  GetFieldAttributes(long lIndex);
	long  GetFieldAttributes(LPCTSTR lpszFieldName);

	// 字段定义长度 -------------------------
	long  GetFieldDefineSize(long lIndex);
	long  GetFieldDefineSize(LPCTSTR lpszFieldName);

	// 字段实际长度 -------------------------
	long  GetFieldActualSize(long lIndex);
	long  GetFieldActualSize(LPCTSTR lpszFieldName);

	// 字段是否为NULL -----------------------
	BOOL  IsFieldNull(long index);
	BOOL  IsFieldNull(LPCTSTR lpFieldName);

// 记录更改 --------------------------------------------
public:
	BOOL AddNew();
	BOOL Update();
	BOOL UpdateBatch(AffectEnum AffectRecords = adAffectAll); 
	BOOL CancelUpdate();
	BOOL CancelBatch(AffectEnum AffectRecords = adAffectAll);
	BOOL Delete(AffectEnum AffectRecords = adAffectCurrent);
	
	// 刷新记录集中的数据 ------------------
	BOOL Requery(long Options = adConnectUnspecified);
	BOOL Resync(AffectEnum AffectRecords = adAffectAll, ResyncEnum ResyncValues = adResyncAllValues);   

	BOOL RecordBinding(CADORecordBinding &pAdoRecordBinding);
	BOOL AddNew(CADORecordBinding &pAdoRecordBinding);
	
// 记录集导航操作 --------------------------------------
public:
	BOOL MoveFirst();
	BOOL MovePrevious();
	BOOL MoveNext();
	BOOL MoveLast();
	BOOL Move(long lRecords, _variant_t Start = _variant_t((long)adBookmarkFirst));
	
	// 查找指定的记录 ----------------------
	BOOL Find(LPCTSTR lpszFind, SearchDirectionEnum SearchDirection = adSearchForward);
	BOOL FindNext();

// 查询 ------------------------------------------------
public:
	BOOL Open(LPCTSTR strSQL, long lOption = adCmdText, CursorTypeEnum CursorType = adOpenStatic, LockTypeEnum LockType = adLockOptimistic);
	BOOL Cancel();
	void Close();

	// 保存/载入持久性文件 -----------------
	BOOL Save(LPCTSTR strFileName = _T(""), PersistFormatEnum PersistFormat = adPersistXML);
	BOOL Load(LPCTSTR strFileName);
	
// 字段存取 --------------------------------------------
public:
	BOOL PutCollect(long index, const _variant_t &value);
	BOOL PutCollect(long index, const CString &value);
	BOOL PutCollect(long index, const double &value);
	BOOL PutCollect(long index, const float  &value);
	BOOL PutCollect(long index, const long   &value);
	BOOL PutCollect(long index, const DWORD  &value);
	BOOL PutCollect(long index, const int    &value);
	BOOL PutCollect(long index, const short  &value);
	BOOL PutCollect(long index, const BYTE   &value);
	BOOL PutCollect(long index, const bool   &value);
	BOOL PutCollect(long index, const COleDateTime &value);
	BOOL PutCollect(long index, const COleCurrency &value);

	BOOL PutCollect(LPCTSTR strFieldName, const _variant_t &value);
	BOOL PutCollect(LPCTSTR strFieldName, const CString &value);
	BOOL PutCollect(LPCTSTR strFieldName, const double &value);
	BOOL PutCollect(LPCTSTR strFieldName, const float  &value);
	BOOL PutCollect(LPCTSTR strFieldName, const long   &value);
	BOOL PutCollect(LPCTSTR strFieldName, const DWORD  &value);
	BOOL PutCollect(LPCTSTR strFieldName, const int    &value);
	BOOL PutCollect(LPCTSTR strFieldName, const short  &value);
	BOOL PutCollect(LPCTSTR strFieldName, const BYTE   &value);
	BOOL PutCollect(LPCTSTR strFieldName, const bool   &value);
	BOOL PutCollect(LPCTSTR strFieldName, const COleDateTime &value);
	BOOL PutCollect(LPCTSTR strFieldName, const COleCurrency &value);

	// ---------------------------------------------------------

	BOOL GetCollect(long index, CString &value);
	BOOL GetCollect(long index, double  &value);
	BOOL GetCollect(long index, float   &value);
	BOOL GetCollect(long index, long    &value);
	BOOL GetCollect(long index, DWORD   &value);
	BOOL GetCollect(long index, int     &value);
	BOOL GetCollect(long index, short   &value);
	BOOL GetCollect(long index, BYTE    &value);
	BOOL GetCollect(long index, bool   &value);
	BOOL GetCollect(long index, COleDateTime &value);
	BOOL GetCollect(long index, COleCurrency &value);

	BOOL GetCollect(LPCSTR strFieldName, CString &strValue);
	BOOL GetCollect(LPCSTR strFieldName, double &value);
	BOOL GetCollect(LPCSTR strFieldName, float  &value);
	BOOL GetCollect(LPCSTR strFieldName, long   &value);
	BOOL GetCollect(LPCSTR strFieldName, DWORD  &value);
	BOOL GetCollect(LPCSTR strFieldName, int    &value);
	BOOL GetCollect(LPCSTR strFieldName, short  &value);
	BOOL GetCollect(LPCSTR strFieldName, BYTE   &value);
	BOOL GetCollect(LPCSTR strFieldName, bool   &value);
	BOOL GetCollect(LPCSTR strFieldName, COleDateTime &value);
	BOOL GetCollect(LPCSTR strFieldName, COleCurrency &value);

	// BLOB 数据存取 ------------------------------------------
	BOOL AppendChunk(FieldPtr pField, LPVOID lpData, UINT nBytes);
	BOOL AppendChunk(long index, LPVOID lpData, UINT nBytes);
	BOOL AppendChunk(LPCSTR strFieldName, LPVOID lpData, UINT nBytes);
	BOOL AppendChunk(long index, LPCTSTR lpszFileName);
	BOOL AppendChunk(LPCSTR strFieldName, LPCTSTR lpszFileName);

	BOOL GetChunk(FieldPtr pField, LPVOID lpData);
	BOOL GetChunk(long index, LPVOID lpData);
	BOOL GetChunk(LPCSTR strFieldName, LPVOID lpData);
	BOOL GetChunk(long index, CBitmap &bitmap);
	BOOL GetChunk(LPCSTR strFieldName, CBitmap &bitmap);

// 其他方法 --------------------------------------------
public:
	// 过滤记录 ---------------------------------
	BOOL SetFilter(LPCTSTR lpszFilter);

	// 排序 -------------------------------------
	BOOL SetSort(LPCTSTR lpszCriteria);

	// 测试是否支持某方法 -----------------------
	BOOL Supports(CursorOptionEnum CursorOptions = adAddNew);

	// 克隆 -------------------------------------
	BOOL Clone(CAdoRecordSet &pRecordSet);
	_RecordsetPtr operator = (_RecordsetPtr &pRecordSet);
	
	// 格式化 _variant_t 类型值 -----------------
	
//成员变量 --------------------------------------------
protected:
	CAdoConnection     *m_pConnection;
	_RecordsetPtr		m_pRecordset;
	CString				m_strSQL;
	CString				m_strFind;
	CString				m_strFileName;
	IADORecordBinding	*m_pAdoRecordBinding;
	SearchDirectionEnum m_SearchDirection;
public:
	_variant_t			m_varBookmark;
};
//________________________________________________________________________

#endif //_ANYOU_COOL_ADORECORDSET_H