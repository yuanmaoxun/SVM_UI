// OptimizePage.cpp : implementation file
//

#include "stdafx.h"
#include "svm.h"
#include "OptimizePage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptimizePage property page

IMPLEMENT_DYNCREATE(COptimizePage, CPropertyPage)

COptimizePage::COptimizePage() : CPropertyPage(COptimizePage::IDD)
{
	//{{AFX_DATA_INIT(COptimizePage)
	m_bFinal = FALSE;
	m_fE = 0.0;
	m_fM = 0.0;
	m_lgIterationTime = 0;
	m_lgNewVariable = 0;
	m_lgMaxQPSize = 0;
	//}}AFX_DATA_INIT
}

COptimizePage::~COptimizePage()
{
}

void COptimizePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptimizePage)
	DDX_Check(pDX, IDC_FINAL_CHECK, m_bFinal);
	DDX_Text(pDX, IDC_EDIT_E, m_fE);
	DDX_Text(pDX, IDC_EDIT_M, m_fM);
	DDX_Text(pDX, IDC_EDIT_H, m_lgIterationTime);
	DDX_Text(pDX, IDC_EDIT_N, m_lgNewVariable);
	DDX_Text(pDX, IDC_EDIT_Q, m_lgMaxQPSize);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptimizePage, CPropertyPage)
	//{{AFX_MSG_MAP(COptimizePage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptimizePage message handlers
