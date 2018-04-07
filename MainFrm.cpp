// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "svm.h"

#include "MainFrm.h"
#include "svm_learn_main.h"
#include "GeneralPage.h"
#include "LearnPage.h" 
#include "PerformPage.h"
#include "KerPage.h"
#include <conio.h>
#include <process.h>
#include "svm_learn_main.h"
#include <string.h>
#include "svm_classify.h"
#include "PromptDlg.h"


#include "OptimizePage.h"
#include "LearnDlg.h"
#include "ClassifyDlg.h"

 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
//{{AFX_MSG_MAP(CMainFrame)
ON_WM_CREATE()
ON_COMMAND(ID_OPTION_LEARN, OnOptionLearn)
ON_COMMAND(ID_FILE_LEARN, OnFileLearn)
ON_COMMAND(ID_FILE_CLASSIFY, OnFileClassify)
	ON_COMMAND(ID_OPTION_PROMPT, OnOptionPrompt)
	ON_COMMAND(ID_TOOL_TEMP, OnToolTemp)
	ON_UPDATE_COMMAND_UI(ID_OPTION_PROMPT, OnUpdateOptionPrompt)
	ON_UPDATE_COMMAND_UI(ID_TOOL_TEMP, OnUpdateToolTemp)
	ON_UPDATE_COMMAND_UI(ID_FILE_LEARN, OnUpdateFileLearn)
	ON_UPDATE_COMMAND_UI(ID_FILE_CLASSIFY, OnUpdateFileClassify)
	ON_UPDATE_COMMAND_UI(ID_OPTION_LEARN, OnUpdateOptionLearn)
	ON_COMMAND(ID_STOP_RUNNING, OnStopRunning)
	ON_UPDATE_COMMAND_UI(ID_STOP_RUNNING, OnUpdateStopRunning)
	ON_MESSAGE(WM_COMPUTATION_FINISH,&OnComputationFinish)
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_TIME,OnUpdateTime)
	ON_COMMAND(ID_CLEAR_TEXT, OnClearText)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	//	ID_INDICATOR_CAPS,
 		ID_INDICATOR_TIME,
	//	ID_INDICATOR_NUM,
	//	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
 
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	 m_wndStatusBar.SetPaneInfo(1,ID_INDICATOR_TIME,SBPS_NORMAL,150);
//	 m_wndStatusBar.GetDlgItem(
	m_nTimeIndex=m_wndStatusBar.CommandToIndex(ID_INDICATOR_TIME);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers



UINT ComputeThreadProc(LPVOID pParam)
{
	
	svm_learn_main();
	if (com_pro.show_openfile) 
	{
		char* cmdline;
		char  oldline[200]="notepad ";
		cmdline=strcat(oldline, com_param.modelfile);
		WinExec(cmdline,3);
	}
	::PostMessage((HWND)pParam,WM_COMPUTATION_FINISH,0,0);
	return 0;
}

UINT ClassifyThreadProc(LPVOID pParam)
{
	svm_classify( );
	if (com_pro.show_action)
		printm("finish classification...");
	if (com_pro.show_openfile) 
	{
		char* cmdline;
		char  oldline[200]="notepad ";
		cmdline=strcat(oldline, com_param.resultfile);
		WinExec(cmdline,3);
	}
	::PostMessage((HWND)pParam,WM_COMPUTATION_FINISH,0,0);
	return 0;
}


void CMainFrame::OnOptionLearn() 
{
	
	CPropertySheet ps("Modify the Computation parameters");
	CLearnPage pp2;
	CPerformPage pp3;
	CKerPage pp4;
	COptimizePage pp5;
	
	pp2.m_bB=com_param.biased_Hyperplane;
	pp2.m_bI=com_param.remove_inconsitant;
	pp2.m_fC=com_param.C;
	pp2.m_fJ=com_param.cost_factor;
	pp3.m_bX=com_param.loo;
	pp3.m_fK=com_param.search_depth;
	pp3.m_fO=com_param.rho;
	pp3.m_fP=com_param.fraction;
	pp4.m_fG=com_param.rbf_gamma;
	pp4.m_fC=com_param.poly_c;
	pp4.m_fS=com_param.poly_s;
	pp4.m_iD=com_param.poly_degree;
	pp4.m_iKernelType=com_param.kernel_type;
//	pp4.m_strU=com_param.user_u;
	pp5.m_fE=com_param.epsion;
	pp5.m_lgIterationTime=com_param.iteration_time;
	pp5.m_fM=com_param.cache_size;
	pp5.m_lgNewVariable=com_param.new_variable;
	pp5.m_lgMaxQPSize=com_param.maximum_size;
	pp5.m_bFinal=com_param.final_test;
	
 
	ps.AddPage(&pp2);
	ps.AddPage(&pp3);
	ps.AddPage(&pp4);
	ps.AddPage(&pp5);
	
	if (ps.DoModal()==IDOK){
		
		com_param.biased_Hyperplane=pp2.m_bB ;
		com_param.remove_inconsitant=pp2.m_bI;
		com_param.C                = 	pp2.m_fC;
		com_param.cost_factor      = 	pp2.m_fJ;
		com_param.loo              = 	pp3.m_bX;
		com_param.search_depth     = 	pp3.m_fK;
		com_param.rho           = 	pp3.m_fO;
		com_param.fraction        = 	pp3.m_fP;
		com_param.rbf_gamma        = 	pp4.m_fG  ;
		com_param.poly_c           = 	pp4.m_fC;
		com_param.poly_s           = 	pp4.m_fS;
		com_param.poly_degree      = 	pp4.m_iD  ;
		com_param.kernel_type      = 	pp4.m_iKernelType ;
	//	com_param.user_u   =            pp4.m_strU  ;                            
		com_param.epsion           = 	pp5.m_fE;
		com_param.iteration_time   = 	pp5.m_lgIterationTime;
		com_param.cache_size       = 	pp5.m_fM  ;
		com_param.new_variable     = 	pp5.m_lgNewVariable;
		com_param.maximum_size     = 	pp5.m_lgMaxQPSize;
		com_param.final_test       = 	pp5.m_bFinal  ;
	}

}


void CMainFrame::OnFileLearn() 
{
	CLearnDlg Ld;
	
	Ld.m_strModel=com_param.modelfile;
	Ld.m_strTrain=com_param.trainfile;
	if (Ld.DoModal()==IDOK) 
	{
		com_pro.show_openfile=Ld.m_bOpen;
		strcpy(com_param.trainfile,Ld.m_strTrain);
		strcpy(com_param.modelfile,Ld.m_strModel);
		GetActiveView()->SetWindowText(NULL);
		BeginComputation();
		
		CWinThread* pThread=
			AfxBeginThread(ComputeThreadProc,GetSafeHwnd(),THREAD_PRIORITY_NORMAL);
	}
	
}

void CMainFrame::OnFileClassify() 
{
	CClassifyDlg Ld;
	Ld.m_strResult=com_param.resultfile;
	Ld.m_strModel=com_param.modelfile;
	Ld.m_strClassify=com_param.classifyfile;
	
	if (Ld.DoModal()==IDOK) 
	{
		strcpy(com_param.classifyfile,Ld.m_strClassify);
		strcpy(com_param.modelfile,Ld.m_strModel);
		strcpy(com_param.resultfile,Ld.m_strResult);
		com_pro.show_openfile=Ld.m_bOpen;
		GetActiveView()->SetWindowText(NULL);
		BeginComputation();
		CWinThread* pThread=
			AfxBeginThread(ClassifyThreadProc,GetSafeHwnd(),THREAD_PRIORITY_NORMAL);
	}
}


void CMainFrame::OnOptionPrompt() 
{
	CPromptDlg pd;
	pd.m_bAction		=com_pro.show_action;
	pd.m_bCompute1		=com_pro.show_compute_1;
	pd.m_bCompute2		=com_pro.show_compute_2;
	pd.m_bCompute3		=com_pro.show_compute_3;

	pd.m_bReadFile		=com_pro.show_readfile;
	pd.m_bWriteFile		=com_pro.show_writefile;
	pd.m_bTestResult	=com_pro.show_testresult;
	pd.m_bTitle			=com_pro.show_title;
	pd.m_bTrainResult	=com_pro.show_trainresult;
	pd.m_bWriteModel	=com_param.blWriteModel;

	if (pd.DoModal()==IDOK) 
	{
		com_pro.show_action    =       pd.m_bAction	;
		com_pro.show_compute_1   =       pd.m_bCompute1	;
		com_pro.show_compute_2   =       pd.m_bCompute2	;
		com_pro.show_compute_3   =       pd.m_bCompute3	;

		com_pro.show_readfile  =       pd.m_bReadFile	;
		com_pro.show_writefile =       pd.m_bWriteFile	;
		com_pro.show_testresult=       pd.m_bTestResult	;
		com_pro.show_title     =	pd.m_bTitle	;
		com_pro.show_trainresult=      pd.m_bTrainResult;
		com_param.blWriteModel=pd.m_bWriteModel	;
	}

}
UINT TempOperationThreadProc(LPVOID pParam)
{
	char filestr[200]="D:\\Digit\\Digit_";
	char trainfile[200];
	char testfile[200];
	char modelfile[200];
	char resultfile[200];

	char trainstr[20];
	char teststr[20];
	char modelstr[20];
	char resultstr[20];

	for (int i=1;i<=100&&com_param.Running;i++)
	{
		sprintf(trainstr,"%d.trn",i);
		sprintf(teststr,"%d.tst",i);
		sprintf(modelstr,"%d.mdl",i);
		sprintf(resultstr,"%d.rsl",i);
		strcpy(trainfile,filestr);
		strcat(trainfile,trainstr);
		strcpy(testfile,filestr);
		strcat(testfile,teststr);
		strcpy(modelfile,filestr);
		strcat(modelfile,modelstr);
		strcpy(resultfile,filestr);
		strcat(resultfile,resultstr);

		strcpy(com_param.trainfile,trainfile);
		strcpy(com_param.classifyfile,testfile);
		strcpy(com_param.modelfile,modelfile);
		strcpy(com_param.resultfile,resultfile);

		svm_learn_main();
		svm_classify();
	}
	::PostMessage((HWND)pParam,WM_COMPUTATION_FINISH,0,0);
	return 1;
	
}


void CMainFrame::OnToolTemp() 
{
	
	BeginComputation();
	CWinThread* pThread=
			AfxBeginThread(TempOperationThreadProc,GetSafeHwnd(),THREAD_PRIORITY_NORMAL);

		
}

void CMainFrame::OnUpdateOptionPrompt(CCmdUI* pCmdUI) 
{
// pCmdUI->Enable(!com_param.Running);
}
	


void CMainFrame::OnUpdateToolTemp(CCmdUI* pCmdUI) 
{
  pCmdUI->Enable(com_param.Finished&&!com_param.Running);
}
	


void CMainFrame::OnUpdateFileLearn(CCmdUI* pCmdUI) 
{
 pCmdUI->Enable(com_param.Finished&&!com_param.Running);
}
	


void CMainFrame::OnUpdateFileClassify(CCmdUI* pCmdUI) 
{
	  pCmdUI->Enable(com_param.Finished&&!com_param.Running);
}

void CMainFrame::OnUpdateOptionLearn(CCmdUI* pCmdUI) 
{
 	pCmdUI->Enable(com_param.Finished&&!com_param.Running);
}

void CMainFrame::OnStopRunning() 
{
	if (AfxMessageBox("Do u wanna stop?",MB_YESNO)==IDYES)
	{
	com_param.Running=FALSE;	
	temp_pro.Copy(com_pro);
	com_pro.Clear();
	m_wndStatusBar.SetPaneText(1,"Trying to stop....");
	}
}

void CMainFrame::OnUpdateStopRunning(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(!com_param.Finished&&com_param.Running);
	
}
void CMainFrame::BeginComputation()
{
	com_param.Running=TRUE;
	com_param.Finished=FALSE;
	temp_pro.Copy(com_pro);
	m_nTimer=SetTimer(1001,500,NULL);
	m_tmBegin=CTime::GetCurrentTime();

}
LRESULT CMainFrame::OnComputationFinish(WPARAM wParam, LPARAM lParam)
{
	CeaseComputation();
	return true;
}

void CMainFrame::CeaseComputation()
{
	
	if (com_param.Running==FALSE)
		printm("----Computation was stop by user.");
	com_param.Running=FALSE;
	com_param.Finished=TRUE;
	com_pro.Copy(temp_pro);
	


	KillTimer(m_nTimer);
	m_wndStatusBar.SetPaneText(1,"Waiting...");
	if (com_param.Close)
		CFrameWnd::OnClose();
}

	

void CMainFrame::OnTimer(UINT_PTR  nIDEvent)
{
	CTimeSpan t=CTime::GetCurrentTime()-m_tmBegin;
	m_strTime=t.Format("Computing %H:%M:%S already ");
//	m_wndStatusBar.SetPaneText(1,m_strTime,TRUE);
	CFrameWnd::OnTimer(nIDEvent);
}
void CMainFrame::OnUpdateTime(CCmdUI* pCmdUI)
{
	pCmdUI->Enable();
	pCmdUI->SetText(m_strTime);
}

void CMainFrame::OnClearText() 
{
 	GetActiveView()->SetWindowText(NULL);
}

void CMainFrame::OnClose() 
{
	if (!com_param.Finished)
	{
		if( AfxMessageBox("Still computing ,Do u wanna exit?",MB_YESNO)==IDYES)
		{
			com_param.Running=FALSE;
			com_param.Close=TRUE;
			return ;
		}
		else return ;

	}
	else 	CFrameWnd::OnClose();
}
