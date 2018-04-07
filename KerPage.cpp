// KerPage.cpp : implementation file
//

#include "stdafx.h"
#include "svm.h"
#include "KerPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKerPage property page

IMPLEMENT_DYNCREATE(CKerPage, CPropertyPage)

CKerPage::CKerPage() : CPropertyPage(CKerPage::IDD)
{
	//{{AFX_DATA_INIT(CKerPage)
	m_strU = _T("");
	m_fC = 0.0;
	m_fG = 0.0;
	m_fS = 0.0;
	m_iD = 0;
	m_iKernelType = -1;
	//}}AFX_DATA_INIT
}

CKerPage::~CKerPage()
{
}

void CKerPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKerPage)
	DDX_Control(pDX, IDC_COMBO_T, m_ComboKernel);
	DDX_Text(pDX, IDC_EDIT_U, m_strU);
	DDX_Text(pDX, IDC_EDIT_C, m_fC);
	DDX_Text(pDX, IDC_EDIT_G, m_fG);
	DDX_Text(pDX, IDC_EDIT_S, m_fS);
	DDX_Text(pDX, IDC_EDIT_D, m_iD);
	DDX_CBIndex(pDX, IDC_COMBO_T, m_iKernelType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKerPage, CPropertyPage)
	//{{AFX_MSG_MAP(CKerPage)
	ON_CBN_SELCHANGE(IDC_COMBO_T, OnSelchangeComboT)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKerPage message handlers

 

void CKerPage::OnSelchangeComboT() 
{

switch (m_ComboKernel.GetCurSel()) 
	{
	case 0://linear kernel 
		
		GetDlgItem(IDC_EDIT_G)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_S)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_C)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_U)->EnableWindow(FALSE);
		break;
	case 1://polynomial
		GetDlgItem(IDC_EDIT_D)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_G)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_S)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_C)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_U)->EnableWindow(FALSE);
		break;

	case 2://rbf kernel
		GetDlgItem(IDC_EDIT_D)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_G)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_S)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_C)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_U)->EnableWindow(FALSE);
		break;
	case 3:
		GetDlgItem(IDC_EDIT_D)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_G)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_S)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_C)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_U)->EnableWindow(FALSE);
		break;
	case 4:
		GetDlgItem(IDC_EDIT_D)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_G)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_S)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_C)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_U)->EnableWindow(TRUE);
		break;
	}

	
}

 
 


void CKerPage::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CPropertyPage::OnShowWindow(bShow, nStatus);
	switch (m_ComboKernel.GetCurSel()) 
	{
	case 0://linear kernel 
		
		GetDlgItem(IDC_EDIT_G)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_S)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_C)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_U)->EnableWindow(FALSE);
		break;
	case 1://polynomial
		GetDlgItem(IDC_EDIT_D)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_G)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_S)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_C)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_U)->EnableWindow(FALSE);
		break;

	case 2://rbf kernel
		GetDlgItem(IDC_EDIT_D)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_G)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_S)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_C)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_U)->EnableWindow(FALSE);
		break;
	case 3:
		GetDlgItem(IDC_EDIT_D)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_G)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_S)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_C)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_U)->EnableWindow(FALSE);
		break;
	case 4:
		GetDlgItem(IDC_EDIT_D)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_G)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_S)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_C)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_U)->EnableWindow(TRUE);
		break;
	}
 
}

 
