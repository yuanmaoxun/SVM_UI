; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "svm.h"
LastPage=0

ClassCount=13
Class1=CSvmApp
Class2=CSvmDoc
Class3=CSvmView
Class4=CMainFrame

ResourceCount=11
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_LEARN_OPTIMIZE (English (U.S.))
Class6=CGeneralPage
Resource3=IDD_LEARN_DLG (English (U.S.))
Resource4=IDD_PROMPT_DLG
Class7=CLearnPage
Resource5=IDD_CLASSIFY_DLG (English (U.S.))
Class8=CPerformPage
Resource6=IDD_LEARN_LEARNING (English (U.S.))
Resource7=IDD_ABOUTBOX (English (U.S.))
Class9=COptimizePage
Class10=CKerPage
Resource8=IDD_LEARN_PERFORM (English (U.S.))
Class11=CLearnDlg
Resource9=IDD_LEARN_GENERAL (English (U.S.))
Class12=CClassifyDlg
Resource10=IDD_LEARN_KERNEL (English (U.S.))
Class13=CPromptDlg
Resource11=IDR_MAINFRAME (English (U.S.))

[CLS:CSvmApp]
Type=0
HeaderFile=svm.h
ImplementationFile=svm.cpp
Filter=N
LastObject=CSvmApp

[CLS:CSvmDoc]
Type=0
HeaderFile=svmDoc.h
ImplementationFile=svmDoc.cpp
Filter=N

[CLS:CSvmView]
Type=0
HeaderFile=svmView.h
ImplementationFile=svmView.cpp
Filter=C
LastObject=CSvmView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_FILE_LEARN




[CLS:CAboutDlg]
Type=0
HeaderFile=svm.cpp
ImplementationFile=svm.cpp
Filter=D

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_LEARN
Command2=ID_FILE_CLASSIFY
Command3=ID_OPTION_PROMPT
Command4=ID_OPTION_LEARN
Command5=ID_CLEAR_TEXT
Command6=ID_STOP_RUNNING
Command7=ID_APP_ABOUT
CommandCount=7

[DLG:IDD_LEARN_GENERAL (English (U.S.))]
Type=1
Class=CGeneralPage
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_V,edit,1350631552
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_L,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_A,edit,1350631552

[CLS:CGeneralPage]
Type=0
HeaderFile=GeneralPage.h
ImplementationFile=GeneralPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CGeneralPage
VirtualFilter=idWC

[DLG:IDD_LEARN_LEARNING (English (U.S.))]
Type=1
Class=CLearnPage
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_C,edit,1350631552
Control3=IDC_EDIT_J,edit,1350631552
Control4=IDC_CHECK_B,button,1342242819
Control5=IDC_CHECK_I,button,1342242819
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDC_STATIC,static,1342177283
Control2=IDOK,button,1342373889
Control3=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_LEARN
Command2=ID_FILE_CLASSIFY
Command3=ID_APP_EXIT
Command4=ID_VIEW_TOOLBAR
Command5=ID_VIEW_STATUS_BAR
Command6=ID_OPTION_LEARN
Command7=ID_OPTION_PROMPT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CLearnPage]
Type=0
HeaderFile=LearnPage.h
ImplementationFile=LearnPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CLearnPage
VirtualFilter=idWC

[DLG:IDD_LEARN_PERFORM (English (U.S.))]
Type=1
Class=CPerformPage
ControlCount=7
Control1=IDC_EDIT_O,edit,1350631552
Control2=IDC_CHECK_X,button,1342242819
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_P,edit,1350631552
Control6=IDC_EDIT_K,edit,1350631552
Control7=IDC_STATIC,static,1342308352

[CLS:CPerformPage]
Type=0
HeaderFile=PerformPage.h
ImplementationFile=PerformPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPerformPage
VirtualFilter=idWC

[DLG:IDD_LEARN_KERNEL (English (U.S.))]
Type=1
Class=CKerPage
ControlCount=12
Control1=IDC_EDIT_D,edit,1484849280
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_S,edit,1484849280
Control6=IDC_COMBO_T,combobox,1344340227
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_G,edit,1484849280
Control11=IDC_EDIT_C,edit,1484849280
Control12=IDC_EDIT_U,edit,1484849280

[DLG:IDD_LEARN_OPTIMIZE (English (U.S.))]
Type=1
Class=COptimizePage
ControlCount=11
Control1=IDC_EDIT_Q,edit,1350631552
Control2=IDC_EDIT_N,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_M,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_E,edit,1350631552
Control10=IDC_EDIT_H,edit,1350631552
Control11=IDC_FINAL_CHECK,button,1342242819

[CLS:COptimizePage]
Type=0
HeaderFile=OptimizePage.h
ImplementationFile=OptimizePage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=COptimizePage
VirtualFilter=idWC

[CLS:CKerPage]
Type=0
HeaderFile=KerPage.h
ImplementationFile=KerPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CKerPage
VirtualFilter=idWC

[DLG:IDD_LEARN_DLG (English (U.S.))]
Type=1
Class=CLearnDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_TRAIN,edit,1350631552
Control6=IDC_BROW_TRAIN,button,1342242816
Control7=IDC_BROW_MODEL,button,1342242816
Control8=IDC_EDIT_MODEL,edit,1350631552
Control9=IDC_CHECK_OPEN_MODEL,button,1342242819

[CLS:CLearnDlg]
Type=0
HeaderFile=LearnDlg.h
ImplementationFile=LearnDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLearnDlg
VirtualFilter=dWC

[DLG:IDD_CLASSIFY_DLG (English (U.S.))]
Type=1
Class=CClassifyDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_CLASSIFY,edit,1350631552
Control6=IDC_BROW_CLASSIFY,button,1342242816
Control7=IDC_BROW_MODEL,button,1342242816
Control8=IDC_EDIT_MODEL,edit,1350631552
Control9=IDC_CHECK_OPEN_MODEL,button,1342242819
Control10=IDC_STATIC,static,1342308352
Control11=IDC_BROW_RESULT,button,1342242816
Control12=IDC_EDIT_RESULT,edit,1350631552

[CLS:CClassifyDlg]
Type=0
HeaderFile=ClassifyDlg.h
ImplementationFile=ClassifyDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CClassifyDlg
VirtualFilter=dWC

[DLG:IDD_PROMPT_DLG]
Type=1
Class=CPromptDlg
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SHOW_ACTION,button,1342242819
Control4=IDC_SHOW_TESTRESULT,button,1342242819
Control5=IDC_SHOW_TITLE,button,1342242819
Control6=IDC_SHOW_COMPUTE_1,button,1342242819
Control7=IDC_WRITE_MODEL,button,1342242819
Control8=IDC_SHOW_TRAINRESULT,button,1342242819
Control9=IDC_SHOW_WRITEFILE,button,1342242819
Control10=IDC_SHOW_READFILE,button,1342242819
Control11=IDC_SHOW_COMPUTE_2,button,1342242819
Control12=IDC_SHOW_COMPUTE_3,button,1342242819
Control13=IDC_STATIC,button,1342177287

[CLS:CPromptDlg]
Type=0
HeaderFile=PromptDlg.h
ImplementationFile=PromptDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPromptDlg

