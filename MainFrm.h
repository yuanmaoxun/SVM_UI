// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__1D252647_39DA_43A3_AE8F_F64724508875__INCLUDED_)
#define AFX_MAINFRM_H__1D252647_39DA_43A3_AE8F_F64724508875__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Compute_Param.h"

const WM_COMPUTATION_FINISH =WM_USER+100;
class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

 
// Attributes
public:
	void BeginComputation();
	void CeaseComputation();
	int m_nTimer;
	CTime m_tmBegin;
	int m_nTimeIndex;
	CString m_strTime;
// Operations
public:

 
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

	CCompute_Prompt temp_pro;
 
// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnOptionLearn();
	afx_msg void OnFileLearn();
	afx_msg void OnFileClassify();
	afx_msg void OnOptionPrompt();
	afx_msg void OnToolTemp();
	afx_msg void OnUpdateOptionPrompt(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolTemp(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileLearn(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileClassify(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOptionLearn(CCmdUI* pCmdUI);
	afx_msg void OnStopRunning();
	afx_msg void OnUpdateStopRunning(CCmdUI* pCmdUI);
	afx_msg LRESULT OnComputationFinish(WPARAM wParam, LPARAM lParam);
	afx_msg void OnTimer(UINT_PTR  nIDEvent);
	afx_msg void OnUpdateTime(CCmdUI * pCmdUI);
	afx_msg void OnClearText();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__1D252647_39DA_43A3_AE8F_F64724508875__INCLUDED_)
