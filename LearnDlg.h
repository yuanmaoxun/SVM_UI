#if !defined(AFX_LEARNDLG_H__1BDF3CD3_F452_4C6F_9876_5806D701AC3A__INCLUDED_)
#define AFX_LEARNDLG_H__1BDF3CD3_F452_4C6F_9876_5806D701AC3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LearnDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLearnDlg dialog

class CLearnDlg : public CDialog
{
// Construction
public:
	CLearnDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLearnDlg)
	enum { IDD = IDD_LEARN_DLG };
	CString	m_strModel;
	CString	m_strTrain;
	BOOL	m_bOpen;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLearnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLearnDlg)
	afx_msg void OnBrowTrain();
	afx_msg void OnBrowModel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEARNDLG_H__1BDF3CD3_F452_4C6F_9876_5806D701AC3A__INCLUDED_)
