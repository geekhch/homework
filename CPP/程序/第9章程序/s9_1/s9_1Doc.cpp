// s9_1Doc.cpp : implementation of the CS9_1Doc class
//

#include "stdafx.h"
#include "s9_1.h"

#include "s9_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CS9_1Doc

IMPLEMENT_DYNCREATE(CS9_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CS9_1Doc, CDocument)
	//{{AFX_MSG_MAP(CS9_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CS9_1Doc construction/destruction

CS9_1Doc::CS9_1Doc()
{
	// TODO: add one-time construction code here

}

CS9_1Doc::~CS9_1Doc()
{
}

BOOL CS9_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CS9_1Doc serialization

void CS9_1Doc::Serialize(CArchive& ar)
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
// CS9_1Doc diagnostics

#ifdef _DEBUG
void CS9_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CS9_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CS9_1Doc commands
