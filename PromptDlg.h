#if !defined(AFX_PROMPTDLG_H__6482BD00_89DF_40CD_99A0_921B9ADA02B4__INCLUDED_)
#define AFX_PROMPTDLG_H__6482BD00_89DF_40CD_99A0_921B9ADA02B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PromptDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPromptDlg dialog

class CPromptDlg : public CDialog
{
// Construction
public:
	CPromptDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPromptDlg)
	enum { IDD = IDD_PROMPT_DLG };
	BOOL	m_bAction;
	BOOL	m_bReadFile;
	BOOL	m_bTestResult;
	BOOL	m_bTitle;
	BOOL	m_bWriteFile;
	BOOL	m_bWriteModel;
	BOOL	m_bTrainResult;
	BOOL	m_bCompute1;
	BOOL	m_bCompute2;
	BOOL	m_bCompute3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPromptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPromptDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROMPTDLG_H__6482BD00_89DF_40CD_99A0_921B9ADA02B4__INCLUDED_)
