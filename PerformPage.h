#if !defined(AFX_PERFORMPAGE_H__D8C1C28F_D83F_415E_B8FB_81924910B2CA__INCLUDED_)
#define AFX_PERFORMPAGE_H__D8C1C28F_D83F_415E_B8FB_81924910B2CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PerformPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPerformPage dialog

class CPerformPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CPerformPage)

// Construction
public:
	CPerformPage();
	~CPerformPage();

// Dialog Data
	//{{AFX_DATA(CPerformPage)
	enum { IDD = IDD_LEARN_PERFORM };
	BOOL	m_bX;
	double	m_fO;
	long	m_fK;
	double	m_fP;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPerformPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPerformPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERFORMPAGE_H__D8C1C28F_D83F_415E_B8FB_81924910B2CA__INCLUDED_)
