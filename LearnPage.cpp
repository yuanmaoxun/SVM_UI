// LearnPage.cpp : implementation file
//

#include "stdafx.h"
#include "svm.h"
#include "LearnPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLearnPage property page

IMPLEMENT_DYNCREATE(CLearnPage, CPropertyPage)

CLearnPage::CLearnPage() : CPropertyPage(CLearnPage::IDD)
{
	//{{AFX_DATA_INIT(CLearnPage)
	m_bB = FALSE;
	m_bI = FALSE;
	m_fC = 0.0;
	m_fJ = 0.0;
	//}}AFX_DATA_INIT
}

CLearnPage::~CLearnPage()
{
}

void CLearnPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLearnPage)
	DDX_Check(pDX, IDC_CHECK_B, m_bB);
	DDX_Check(pDX, IDC_CHECK_I, m_bI);
	DDX_Text(pDX, IDC_EDIT_C, m_fC);
	DDX_Text(pDX, IDC_EDIT_J, m_fJ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLearnPage, CPropertyPage)
	//{{AFX_MSG_MAP(CLearnPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLearnPage message handlers
