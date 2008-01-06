# Microsoft Developer Studio Project File - Name="swWxGuiTesting_swWxGuiTesting" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "swWxGuiTesting_swWxGuiTesting.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "swWxGuiTesting_swWxGuiTesting.mak" CFG="swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd../..\lib\swWxGuiTestingd.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../..\lib"
# PROP BASE Intermediate_Dir "objects\swWxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../..\lib"
# PROP Intermediate_Dir "objects\swWxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "../..\include" /I "../..\src\swFrameworkDependent" /I "../..\src\swWxGuiTesting" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd../..\lib\swWxGuiTesting.pdb /I "$(VTK)\include" /I "..\..\src\wxVTK" /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"
# ADD LIB32 /nologo /out:"../..\lib\swWxGuiTesting.lib"

!ENDIF

# Begin Target

# Name "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"
# Name "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"
# Name "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"
# Name "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"
# Name "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"
# Name "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"
# Name "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"
# Name "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"
# Name "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"
# Name "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"
# Name "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"
# Name "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"
# Name "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"
# Name "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"
# Name "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"
# Name "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"
# Name "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"
# Name "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"
# Name "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"
# Name "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"
# Name "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"
# Name "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"
# Name "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"
# Name "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"
# Name "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"
# Name "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"
# Name "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"
# Name "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"
# Name "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"
# Name "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"
# Name "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"
# Name "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturePanel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\VtkWxGuiTesting\VtkCapturePanel.cpp

!IF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\swApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRAbstractTreeEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRButtonClickEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swCRCapture.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swCRCaptureControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRCapturedEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRCheckBoxClickEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRChoiceSelectionEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swCRCppEmitter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swCREventCaptureManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swCREventFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRMenuSelectionEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRNotebookPageChangeEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRRadioBoxSelectionEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRSliderUpdateEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRSpinCtrlUpdateEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRTextUpdateEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRTreeItemRightClickEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\CapturedEvents\swCRTreeSelectionChangingEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\VtkWxGuiTesting\swCRVtkCapture.cpp

!IF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\VtkWxGuiTesting\swCRVtkCaptureControl.cpp

!IF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swCRWindowHierarchyHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swCRXRCNode.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swCRXRCObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swCRXRCReader.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swCRXRCResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\Config\swConfig.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\Config\swConfigInterface.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\Config\swConfigManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\FrameFactory\swDefaultDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\FrameFactory\swFrameFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\GUI\swGuiObjectManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swInitWxGuiTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swInitWxGuiTestSetUp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\FrameFactory\swMainFrame.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\FrameFactory\swMdiDefaultDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\FrameFactory\swMdiFrameFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\FrameFactory\swMdiMainFrame.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\FrameFactory\swMdiToolBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swModalDialogTimer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\Widget\swNewBitmapButton.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\swPseudoApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\Widget\swSpinCtrlDouble.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\FrameFactory\swToolBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\FrameFactory\swToolBarRegistry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\GUI\swToolGuiObjectManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\Widget\swTreeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\VtkWxGuiTesting\swVtkWxGuiTestHelper.cpp

!IF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\FrameFactory\swWindow.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swWxGuiTestApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swWxGuiTestCppUnitWarningAsserter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swWxGuiTestEventSimulationHelper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swWxGuiTestHelper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swWxGuiTestProvokedWarning.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swWxGuiTestProvokedWarningRegistry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swWxGuiTestTempInteractive.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swWxGuiTestTempInteractiveControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\swWxGuiTestTimedDialogEnder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swFrameworkDependent\Exception\swWxLogicErrorException.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\swWxGuiTesting\VtkWxGuiTesting\swWxVtkInteractorEventRecorder.cpp

!IF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=..\..\src\wxVTK\wxVTKRenderWindowInteractor.cpp

!IF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "swWxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\include\wxGuiTest\Common.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swApp.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swCRCapture.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swCRCaptureControl.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swCRCppEmitter.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swCREventCaptureManager.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swCREventFilterInterface.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swCRLogInterface.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\VtkGuiTesting\swCRVtkCapture.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\VtkGuiTesting\swCRVtkCaptureControl.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swCRWindowHierarchyHandler.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\Config\swConfig.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\Config\swConfigInterface.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\Config\swConfigManager.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swInitWxGuiTest.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swModalDialogInteractionInterface.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swModalDialogTimer.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\Widget\swNewBitmapButton.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swPseudoApp.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\Widget\swSpinCtrlDouble.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\Widget\swTreeCtrl.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\VtkGuiTesting\swVtkWxGuiTestHelper.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swWxGuiTestApp.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swWxGuiTestCppUnitWarningAsserter.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swWxGuiTestEventSimulationHelper.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swWxGuiTestHelper.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swWxGuiTestProvokedWarning.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swWxGuiTestProvokedWarningRegistry.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swWxGuiTestTempInteractive.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swWxGuiTestTimedDialogEnder.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\swWxGuiTestWarningAsserterInterface.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\VtkGuiTesting\swWxVtkInteractorEventRecorder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\wxVTK\wxVTKRenderWindowInteractor.h
# End Source File
# End Group
# End Target
# End Project

