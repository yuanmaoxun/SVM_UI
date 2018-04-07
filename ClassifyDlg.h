#if !defined(AFX_CLASSIFYDLG_H__1DADF6D8_F51B_4306_8750_71D675E43F9A__INCLUDED_)
#define AFX_CLASSIFYDLG_H__1DADF6D8_F51B_4306_8750_71D675E43F9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClassifyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClassifyDlg dialog

class CClassifyDlg : public CDialog
{
// Construction
public:
	CClassifyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CClassifyDlg)
	enum { IDD = IDD_CLASSIFY_DLG };
	CString	m_strClassify;
	CString	m_strModel;
	CString	m_strResult;
	BOOL	m_bOpen;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassifyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClassifyDlg)
	afx_msg void OnBrowClassify();
	afx_msg void OnBrowModel();
	afx_msg void OnBrowResult();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSIFYDLG_H__1DADF6D8_F51B_4306_8750_71D675E43F9A__INCLUDED_)
