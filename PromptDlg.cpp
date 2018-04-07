// PromptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "svm.h"
#include "PromptDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPromptDlg dialog


CPromptDlg::CPromptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPromptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPromptDlg)
	m_bAction = FALSE;
	m_bReadFile = FALSE;
	m_bTestResult = FALSE;
	m_bTitle = FALSE;
	m_bWriteFile = FALSE;
	m_bWriteModel = FALSE;
	m_bTrainResult = FALSE;
	m_bCompute1 = FALSE;
	m_bCompute2 = FALSE;
	m_bCompute3 = FALSE;
	//}}AFX_DATA_INIT
}


void CPromptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPromptDlg)
	DDX_Check(pDX, IDC_SHOW_ACTION, m_bAction);
	DDX_Check(pDX, IDC_SHOW_READFILE, m_bReadFile);
	DDX_Check(pDX, IDC_SHOW_TESTRESULT, m_bTestResult);
	DDX_Check(pDX, IDC_SHOW_TITLE, m_bTitle);
	DDX_Check(pDX, IDC_SHOW_WRITEFILE, m_bWriteFile);
	DDX_Check(pDX, IDC_WRITE_MODEL, m_bWriteModel);
	DDX_Check(pDX, IDC_SHOW_TRAINRESULT, m_bTrainResult);
	DDX_Check(pDX, IDC_SHOW_COMPUTE_1, m_bCompute1);
	DDX_Check(pDX, IDC_SHOW_COMPUTE_2, m_bCompute2);
	DDX_Check(pDX, IDC_SHOW_COMPUTE_3, m_bCompute3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPromptDlg, CDialog)
	//{{AFX_MSG_MAP(CPromptDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPromptDlg message handlers
