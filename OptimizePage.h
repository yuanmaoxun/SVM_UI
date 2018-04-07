#if !defined(AFX_OPTIMIZEPAGE_H__AF628297_F103_4D96_A21D_9DCB3E88140A__INCLUDED_)
#define AFX_OPTIMIZEPAGE_H__AF628297_F103_4D96_A21D_9DCB3E88140A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptimizePage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptimizePage dialog

class COptimizePage : public CPropertyPage
{
	DECLARE_DYNCREATE(COptimizePage)

// Construction
public:
	COptimizePage();
	~COptimizePage();

// Dialog Data
	//{{AFX_DATA(COptimizePage)
	enum { IDD = IDD_LEARN_OPTIMIZE };
	BOOL	m_bFinal;
	double	m_fE;
	double	m_fM;
	long	m_lgIterationTime;
	long	m_lgNewVariable;
	long	m_lgMaxQPSize;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COptimizePage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COptimizePage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIMIZEPAGE_H__AF628297_F103_4D96_A21D_9DCB3E88140A__INCLUDED_)
