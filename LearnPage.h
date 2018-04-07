#if !defined(AFX_LEARNPAGE_H__410EAEF7_DFAF_4D87_9C54_95487701750F__INCLUDED_)
#define AFX_LEARNPAGE_H__410EAEF7_DFAF_4D87_9C54_95487701750F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LearnPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLearnPage dialog

class CLearnPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CLearnPage)

// Construction
public:
	CLearnPage();
	~CLearnPage();

// Dialog Data
	//{{AFX_DATA(CLearnPage)
	enum { IDD = IDD_LEARN_LEARNING };
	BOOL	m_bB;
	BOOL	m_bI;
	double	m_fC;
	double	m_fJ;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CLearnPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CLearnPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEARNPAGE_H__410EAEF7_DFAF_4D87_9C54_95487701750F__INCLUDED_)
