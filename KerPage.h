#if !defined(AFX_KERPAGE_H__D82F9F66_3FB7_4999_959B_FEEA4C0D3381__INCLUDED_)
#define AFX_KERPAGE_H__D82F9F66_3FB7_4999_959B_FEEA4C0D3381__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KerPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKerPage dialog

class CKerPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CKerPage)

// Construction
public:
	CKerPage();
	~CKerPage();

// Dialog Data
	//{{AFX_DATA(CKerPage)
	enum { IDD = IDD_LEARN_KERNEL };
	CComboBox	m_ComboKernel;
	CString	m_strU;
	double	m_fC;
	double	m_fG;
	double	m_fS;
	long	m_iD;
	int		m_iKernelType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CKerPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CKerPage)
	afx_msg void OnSelchangeComboT();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KERPAGE_H__D82F9F66_3FB7_4999_959B_FEEA4C0D3381__INCLUDED_)
