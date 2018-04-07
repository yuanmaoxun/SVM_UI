// svm.h : main header file for the SVM application
//

#if !defined(AFX_SVM_H__A2EFB38D_8878_4EEA_9AEC_4F0F72FCBBBD__INCLUDED_)
#define AFX_SVM_H__A2EFB38D_8878_4EEA_9AEC_4F0F72FCBBBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "Compute_Param.h"
#include "Compute_Prompt.h"
#include "Compute_Result.h"

/////////////////////////////////////////////////////////////////////////////
// CSvmApp:
// See svm.cpp for the implementation of this class
//

class CSvmApp : public CWinApp
{
	void Init_computation_param();
public:
	int ShowM(char* str);
	CSvmApp();
	CSingleDocTemplate* pDocTemplate;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSvmApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSvmApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CSvmApp theApp;
extern CCompute_Param com_param;
extern CCompute_Prompt com_pro;
extern CCompute_Result com_result;
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SVM_H__A2EFB38D_8878_4EEA_9AEC_4F0F72FCBBBD__INCLUDED_)
