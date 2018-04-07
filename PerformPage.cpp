// PerformPage.cpp : implementation file
//

#include "stdafx.h"
#include "svm.h"
#include "PerformPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPerformPage property page

IMPLEMENT_DYNCREATE(CPerformPage, CPropertyPage)

CPerformPage::CPerformPage() : CPropertyPage(CPerformPage::IDD)
{
	//{{AFX_DATA_INIT(CPerformPage)
	m_bX = FALSE;
	m_fO = 0.0;
	m_fK = 0;
	m_fP = 0.0;
	//}}AFX_DATA_INIT
}

CPerformPage::~CPerformPage()
{
}

void CPerformPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPerformPage)
	DDX_Check(pDX, IDC_CHECK_X, m_bX);
	DDX_Text(pDX, IDC_EDIT_O, m_fO);
	DDX_Text(pDX, IDC_EDIT_K, m_fK);
	DDX_Text(pDX, IDC_EDIT_P, m_fP);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPerformPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPerformPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPerformPage message handlers
