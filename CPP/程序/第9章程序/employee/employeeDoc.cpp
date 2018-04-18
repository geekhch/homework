// employeeDoc.cpp : implementation of the CEmployeeDoc class
//

#include "stdafx.h"
#include "employee.h"

#include "employeeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDoc

IMPLEMENT_DYNCREATE(CEmployeeDoc, CDocument)

BEGIN_MESSAGE_MAP(CEmployeeDoc, CDocument)
	//{{AFX_MSG_MAP(CEmployeeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDoc construction/destruction

CEmployeeDoc::CEmployeeDoc()
{
	// TODO: add one-time construction code here

}

CEmployeeDoc::~CEmployeeDoc()
{
}

BOOL CEmployeeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEmployeeDoc serialization

void CEmployeeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDoc diagnostics

#ifdef _DEBUG
void CEmployeeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEmployeeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDoc commands
