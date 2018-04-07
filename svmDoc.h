// svmDoc.h : interface of the CSvmDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SVMDOC_H__295FE1AE_4F6C_4F65_8C35_B0AB22E3BFC3__INCLUDED_)
#define AFX_SVMDOC_H__295FE1AE_4F6C_4F65_8C35_B0AB22E3BFC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSvmDoc : public CDocument
{
protected: // create from serialization only
	CSvmDoc();
	DECLARE_DYNCREATE(CSvmDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSvmDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSvmDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSvmDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SVMDOC_H__295FE1AE_4F6C_4F65_8C35_B0AB22E3BFC3__INCLUDED_)
