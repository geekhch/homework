// s9_2Doc.cpp : implementation of the CS9_2Doc class
//

#include "stdafx.h"
#include "s9_2.h"

#include "s9_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CS9_2Doc

IMPLEMENT_DYNCREATE(CS9_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CS9_2Doc, CDocument)
	//{{AFX_MSG_MAP(CS9_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CS9_2Doc construction/destruction

CS9_2Doc::CS9_2Doc()
{
	// TODO: add one-time construction code here

}

CS9_2Doc::~CS9_2Doc()
{
}

BOOL CS9_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CS9_2Doc serialization

void CS9_2Doc::Serialize(CArchive& ar)
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
// CS9_2Doc diagnostics

#ifdef _DEBUG
void CS9_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CS9_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CS9_2Doc commands
