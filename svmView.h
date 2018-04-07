// svmView.h : interface of the CSvmView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SVMVIEW_H__BD0C6D00_634F_44CE_81C7_FB3509E21448__INCLUDED_)
#define AFX_SVMVIEW_H__BD0C6D00_634F_44CE_81C7_FB3509E21448__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

int View_show(char* str);

class CSvmView : public CEditView
{
protected: // create from serialization only
	CSvmView();
	DECLARE_DYNCREATE(CSvmView)

// Attributes
public:
	CSvmDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSvmView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSvmView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSvmView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in svmView.cpp
inline CSvmDoc* CSvmView::GetDocument()
   { return (CSvmDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SVMVIEW_H__BD0C6D00_634F_44CE_81C7_FB3509E21448__INCLUDED_)
