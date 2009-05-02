# Microsoft Developer Studio Project File - Name="wxGuiTesting_wxGuiTesting" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "wxGuiTesting_wxGuiTesting.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "wxGuiTesting_wxGuiTesting.mak" CFG="wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\wxGuiTestingd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTestingd.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\wxGuiTesting"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\wxGuiTesting"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\wxGuiTesting.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"
# ADD LIB32 /nologo /out:"..\..\lib\wxGuiTesting.lib"

!ENDIF

# Begin Target

# Name "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"
# Name "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"
# Name "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"
# Name "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"
# Name "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"
# Name "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"
# Name "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"
# Name "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"
# Name "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"
# Name "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"
# Name "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"
# Name "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"
# Name "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"
# Name "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"
# Name "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"
# Name "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"
# Name "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"
# Name "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"
# Name "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"
# Name "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"
# Name "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"
# Name "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"
# Name "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"
# Name "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"
# Name "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"
# Name "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"
# Name "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"
# Name "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"
# Name "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"
# Name "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"
# Name "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"
# Name "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRAbstractTreeEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRButtonClickEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CRCapture.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CRCaptureControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRCapturedEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRCheckBoxClickEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRChoiceSelectionEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CRCppEmitter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CREventCaptureManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CREventFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRMenuSelectionEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRNotebookPageChangeEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRRadioBoxSelectionEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRSliderUpdateEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRSpinCtrlUpdateEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRTextUpdateEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRTreeItemRightClickEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturedEvents\CRTreeSelectionChangingEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\VtkGuiTesting\CRVtkCapture.cpp

!IF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\VtkGuiTesting\CRVtkCaptureControl.cpp

!IF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CRWindowHierarchyHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CapturePanel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\CppUnitWarningAsserter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\EventSimulationHelper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\InitWxGuiTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\InitWxGuiTestSetUp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\ModalDialogTimer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\ProvokedWarning.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\ProvokedWarningRegistry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\TempInteractive.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\TempInteractiveControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\TestEventLoop.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\TimedDialogEnder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\VtkGuiTesting\VtkCapturePanel.cpp

!IF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\VtkGuiTesting\VtkInteractorEventRecorder.cpp

!IF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\VtkGuiTesting\VtkWxGuiTestHelper.cpp

!IF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\WxGuiTestApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxGuiTest\WxGuiTestHelper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wxVTK\wxVTKRenderWindowInteractor.cpp

!IF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_1"


!ELSEIF  "$(CFG)" == "wxGuiTesting - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\include\wxGuiTest\CRCapture.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\CRCaptureControl.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\CRCppEmitter.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\CREventCaptureManager.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\CREventFilterInterface.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\CRLogInterface.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\VtkGuiTesting\CRVtkCapture.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\VtkGuiTesting\CRVtkCaptureControl.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\CRWindowHierarchyHandler.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\Common.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\CppUnitWarningAsserter.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\EventQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\EventSimulationHelper.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\InitWxGuiTest.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\ModalDialogInteractionInterface.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\ModalDialogTimer.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\ProvokedWarning.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\ProvokedWarningRegistry.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\TempInteractive.h
# End Source File
# Begin Source File

SOURCE=..\..\($WGTI)\TestEventLoop.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\TimedDialogEnder.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\VtkGuiTesting\VtkInteractorEventRecorder.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\VtkGuiTesting\VtkWxGuiTestHelper.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\WarningAsserterInterface.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\WxGuiTestApp.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wxGuiTest\WxGuiTestHelper.h
# End Source File
# Begin Source File

SOURCE=..\..\src\wxVTK\wxVTKRenderWindowInteractor.h
# End Source File
# End Group
# End Target
# End Project

