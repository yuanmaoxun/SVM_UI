// ClassifyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "svm.h"
#include "ClassifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClassifyDlg dialog
static char BASED_CODE szModelFilter[] = "Model Files (*.mdl)|*.mdl|All Files (*.*)|*.*||";
static char BASED_CODE szResultFilter[] = "Result Files (*.rsl)|*.rsl|All Files (*.*)|*.*||";
static char BASED_CODE szTestFilter[] = "Test Files (*.tst)|*.tst|All Files (*.*)|*.*||";


CClassifyDlg::CClassifyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClassifyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClassifyDlg)
	m_strClassify = _T("");
	m_strModel = _T("");
	m_strResult = _T("");
	m_bOpen = FALSE;
	//}}AFX_DATA_INIT
}


void CClassifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClassifyDlg)
	DDX_Text(pDX, IDC_EDIT_CLASSIFY, m_strClassify);
	DDX_Text(pDX, IDC_EDIT_MODEL, m_strModel);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_strResult);
	DDX_Check(pDX, IDC_CHECK_OPEN_MODEL, m_bOpen);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClassifyDlg, CDialog)
	//{{AFX_MSG_MAP(CClassifyDlg)
	ON_BN_CLICKED(IDC_BROW_CLASSIFY, OnBrowClassify)
	ON_BN_CLICKED(IDC_BROW_MODEL, OnBrowModel)
	ON_BN_CLICKED(IDC_BROW_RESULT, OnBrowResult)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassifyDlg message handlers

void CClassifyDlg::OnBrowClassify() 
{
	CFileDialog cfd(TRUE,szTestFilter,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szTestFilter,NULL);
	if (cfd.DoModal()==IDOK) 
	{
		m_strClassify=cfd.GetPathName();
		UpdateData(FALSE);
	}
 	
}

void CClassifyDlg::OnBrowModel() 
{
	CFileDialog cfd(TRUE,szModelFilter,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szModelFilter,NULL);

	if (cfd.DoModal()==IDOK) 
	{
		m_strModel=cfd.GetPathName();
		UpdateData(FALSE);
	}
 	
}

void CClassifyDlg::OnBrowResult() 
{
	CFileDialog cfd(FALSE,szResultFilter,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szResultFilter,NULL);
	if (cfd.DoModal()==IDOK) 
	{
		m_strResult=cfd.GetPathName();
		UpdateData(FALSE);
	}
 	
}
