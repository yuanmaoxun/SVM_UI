// svmView.cpp : implementation of the CSvmView class
//

#include "stdafx.h"
#include "svm.h"

#include "svmDoc.h"
#include "svmView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSvmView

IMPLEMENT_DYNCREATE(CSvmView, CEditView)

BEGIN_MESSAGE_MAP(CSvmView, CEditView)
	//{{AFX_MSG_MAP(CSvmView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSvmView construction/destruction

CSvmView::CSvmView()
{
}

CSvmView::~CSvmView()
{
}

BOOL CSvmView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CEditView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSvmView drawing

void CSvmView::OnDraw(CDC* pDC)
{
	CSvmDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CSvmView printing

BOOL CSvmView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSvmView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CSvmView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CSvmView diagnostics

#ifdef _DEBUG
void CSvmView::AssertValid() const
{
	CEditView::AssertValid();
}

void CSvmView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CSvmDoc* CSvmView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSvmDoc)));
	return (CSvmDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSvmView message handlers
