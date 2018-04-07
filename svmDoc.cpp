// svmDoc.cpp : implementation of the CSvmDoc class
//

#include "stdafx.h"
#include "svm.h"

#include "svmDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSvmDoc

IMPLEMENT_DYNCREATE(CSvmDoc, CDocument)

BEGIN_MESSAGE_MAP(CSvmDoc, CDocument)
	//{{AFX_MSG_MAP(CSvmDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSvmDoc construction/destruction

CSvmDoc::CSvmDoc()
{
}

CSvmDoc::~CSvmDoc()
{
}

BOOL CSvmDoc::OnNewDocument()
{
	
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSvmDoc serialization

void CSvmDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSvmDoc diagnostics

#ifdef _DEBUG
void CSvmDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSvmDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSvmDoc commands
