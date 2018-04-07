// LearnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "svm.h"
#include "LearnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLearnDlg dialog
static char BASED_CODE szModelFilter[] = "Model Files (*.mdl)|*.mdl|All Files (*.*)|*.*||";
static char BASED_CODE szTrainFilter[] = "Train Files (*.trn)|*.trn|All Files (*.*)|*.*||";
static char BASED_CODE szResultFilter[] = "Result Files (*.rsl)|*.rsl|All Files (*.*)|*.*||";
static char BASED_CODE szTestFilter[] = "Test Files (*.tst)|*.tstd|All Files (*.*)|*.*||";
 

CLearnDlg::CLearnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLearnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLearnDlg)
	m_strModel = _T("");
	m_strTrain = _T("");
	m_bOpen = FALSE;
	//}}AFX_DATA_INIT
}


void CLearnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLearnDlg)
	DDX_Text(pDX, IDC_EDIT_MODEL, m_strModel);
	DDX_Text(pDX, IDC_EDIT_TRAIN, m_strTrain);
	DDX_Check(pDX, IDC_CHECK_OPEN_MODEL, m_bOpen);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLearnDlg, CDialog)
	//{{AFX_MSG_MAP(CLearnDlg)
	ON_BN_CLICKED(IDC_BROW_TRAIN, OnBrowTrain)
	ON_BN_CLICKED(IDC_BROW_MODEL, OnBrowModel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLearnDlg message handlers

void CLearnDlg::OnBrowTrain() 
{
	CFileDialog cfd(TRUE,szTrainFilter,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szTrainFilter,NULL);
	if (cfd.DoModal()==IDOK) 
	{
		m_strTrain=cfd.GetPathName();
		UpdateData(FALSE);
	}
}

void CLearnDlg::OnBrowModel() 
{
	CFileDialog cfd(FALSE,szModelFilter,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szModelFilter,NULL);
	if (cfd.DoModal()==IDOK) 
	{
		m_strModel=cfd.GetPathName();
		UpdateData(FALSE);
	}
 	
}
