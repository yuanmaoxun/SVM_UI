# Microsoft Developer Studio Project File - Name="svm" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=svm - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "svm.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "svm.mak" CFG="svm - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "svm - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "svm - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "svm - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "svm - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "svm - Win32 Release"
# Name "svm - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ClassifyDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Compute_Param.cpp
# End Source File
# Begin Source File

SOURCE=.\Compute_Prompt.cpp
# End Source File
# Begin Source File

SOURCE=.\Compute_Result.cpp
# End Source File
# Begin Source File

SOURCE=.\GeneralPage.cpp
# End Source File
# Begin Source File

SOURCE=.\KerPage.cpp
# End Source File
# Begin Source File

SOURCE=.\LearnDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LearnPage.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\OptimizePage.cpp
# End Source File
# Begin Source File

SOURCE=.\PerformPage.cpp
# End Source File
# Begin Source File

SOURCE=.\PromptDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\svm.cpp
# End Source File
# Begin Source File

SOURCE=.\svm.rc
# End Source File
# Begin Source File

SOURCE=.\svm_classify.cpp
# End Source File
# Begin Source File

SOURCE=.\svm_common.cpp
# End Source File
# Begin Source File

SOURCE=.\svm_learn.cpp
# End Source File
# Begin Source File

SOURCE=.\svm_learn_main.cpp
# End Source File
# Begin Source File

SOURCE=.\svmDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\svmView.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ClassifyDlg.h
# End Source File
# Begin Source File

SOURCE=.\Compute_Param.h
# End Source File
# Begin Source File

SOURCE=.\Compute_Prompt.h
# End Source File
# Begin Source File

SOURCE=.\Compute_Result.h
# End Source File
# Begin Source File

SOURCE=.\GeneralPage.h
# End Source File
# Begin Source File

SOURCE=.\KerPage.h
# End Source File
# Begin Source File

SOURCE=.\LearnDlg.h
# End Source File
# Begin Source File

SOURCE=.\LearnPage.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\OptimizePage.h
# End Source File
# Begin Source File

SOURCE=.\PerformPage.h
# End Source File
# Begin Source File

SOURCE=.\PromptDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\svm.h
# End Source File
# Begin Source File

SOURCE=.\svm_classify.h
# End Source File
# Begin Source File

SOURCE=.\svm_common.h
# End Source File
# Begin Source File

SOURCE=.\svm_hideo.h
# End Source File
# Begin Source File

SOURCE=.\svm_learn.h
# End Source File
# Begin Source File

SOURCE=.\svm_learn_main.h
# End Source File
# Begin Source File

SOURCE=.\svmDoc.h
# End Source File
# Begin Source File

SOURCE=.\svmView.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\CRDFLE07.ICO
# End Source File
# Begin Source File

SOURCE=.\res\ERASE01.ICO
# End Source File
# Begin Source File

SOURCE=.\res\FILES02A.ICO
# End Source File
# Begin Source File

SOURCE=.\res\FILES05A.ICO
# End Source File
# Begin Source File

SOURCE=.\res\GRAPH12.ICO
# End Source File
# Begin Source File

SOURCE=.\res\HAMMER.ICO
# End Source File
# Begin Source File

SOURCE=.\res\icon9.ico
# End Source File
# Begin Source File

SOURCE=.\res\MISC06.ICO
# End Source File
# Begin Source File

SOURCE=.\res\NOTE09.ICO
# End Source File
# Begin Source File

SOURCE=.\res\PENCIL03.ICO
# End Source File
# Begin Source File

SOURCE=.\res\svm.ico
# End Source File
# Begin Source File

SOURCE=.\res\svm.rc2
# End Source File
# Begin Source File

SOURCE=.\res\svmDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TRFFC14.ICO
# End Source File
# End Group
# End Target
# End Project
