# Microsoft Developer Studio Project File - Name="swWxGuiTesting_swFramework" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=swFramework - Win32 Static ANSI Release Multilib USE_VTK_0
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "swWxGuiTesting_swFramework.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "swWxGuiTesting_swFramework.mak" CFG="swFramework - Win32 Static ANSI Release Multilib USE_VTK_0"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "swFramework - Win32 DLL Unicode Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL Unicode Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL Unicode Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL Unicode Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL Unicode Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL Unicode Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL Unicode Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL Unicode Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL ANSI Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL ANSI Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL ANSI Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL ANSI Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL ANSI Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL ANSI Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL ANSI Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 DLL ANSI Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static Unicode Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static Unicode Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static Unicode Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static Unicode Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static Unicode Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static Unicode Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static Unicode Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static Unicode Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static ANSI Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static ANSI Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static ANSI Debug Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static ANSI Debug Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static ANSI Release Monolithic USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static ANSI Release Monolithic USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static ANSI Release Multilib USE_VTK_1" (based on "Win32 (x86) Static Library")
!MESSAGE "swFramework - Win32 Static ANSI Release Multilib USE_VTK_0" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "swFramework - Win32 DLL Unicode Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL Unicode Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL Unicode Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL Unicode Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL ANSI Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL ANSI Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL ANSI Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL ANSI Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "WXUSINGDLL" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static Unicode Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static Unicode Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static Unicode Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static Unicode Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "_UNICODE" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static ANSI Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static ANSI Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\lib\swFrameworkd.pdb /D "WIN32" /D "_LIB" /D "__WXDEBUG__" /D "__WXMSW__" /D "_DEBUG" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFrameworkd.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static ANSI Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static ANSI Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ELSEIF  "$(CFG)" == "swFramework - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "objects\swFramework"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "objects\swFramework"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\swFrameworkDependent" /I "..\..\src\swWxGuiTesting" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\lib\swFramework.pdb /D "WIN32" /D "_LIB" /D "__WXMSW__" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\swFramework.lib"
# ADD LIB32 /nologo /out:"..\..\lib\swFramework.lib"

!ENDIF

# Begin Target

# Name "swFramework - Win32 DLL Unicode Debug Monolithic USE_VTK_1"
# Name "swFramework - Win32 DLL Unicode Debug Monolithic USE_VTK_0"
# Name "swFramework - Win32 DLL Unicode Debug Multilib USE_VTK_1"
# Name "swFramework - Win32 DLL Unicode Debug Multilib USE_VTK_0"
# Name "swFramework - Win32 DLL Unicode Release Monolithic USE_VTK_1"
# Name "swFramework - Win32 DLL Unicode Release Monolithic USE_VTK_0"
# Name "swFramework - Win32 DLL Unicode Release Multilib USE_VTK_1"
# Name "swFramework - Win32 DLL Unicode Release Multilib USE_VTK_0"
# Name "swFramework - Win32 DLL ANSI Debug Monolithic USE_VTK_1"
# Name "swFramework - Win32 DLL ANSI Debug Monolithic USE_VTK_0"
# Name "swFramework - Win32 DLL ANSI Debug Multilib USE_VTK_1"
# Name "swFramework - Win32 DLL ANSI Debug Multilib USE_VTK_0"
# Name "swFramework - Win32 DLL ANSI Release Monolithic USE_VTK_1"
# Name "swFramework - Win32 DLL ANSI Release Monolithic USE_VTK_0"
# Name "swFramework - Win32 DLL ANSI Release Multilib USE_VTK_1"
# Name "swFramework - Win32 DLL ANSI Release Multilib USE_VTK_0"
# Name "swFramework - Win32 Static Unicode Debug Monolithic USE_VTK_1"
# Name "swFramework - Win32 Static Unicode Debug Monolithic USE_VTK_0"
# Name "swFramework - Win32 Static Unicode Debug Multilib USE_VTK_1"
# Name "swFramework - Win32 Static Unicode Debug Multilib USE_VTK_0"
# Name "swFramework - Win32 Static Unicode Release Monolithic USE_VTK_1"
# Name "swFramework - Win32 Static Unicode Release Monolithic USE_VTK_0"
# Name "swFramework - Win32 Static Unicode Release Multilib USE_VTK_1"
# Name "swFramework - Win32 Static Unicode Release Multilib USE_VTK_0"
# Name "swFramework - Win32 Static ANSI Debug Monolithic USE_VTK_1"
# Name "swFramework - Win32 Static ANSI Debug Monolithic USE_VTK_0"
# Name "swFramework - Win32 Static ANSI Debug Multilib USE_VTK_1"
# Name "swFramework - Win32 Static ANSI Debug Multilib USE_VTK_0"
# Name "swFramework - Win32 Static ANSI Release Monolithic USE_VTK_1"
# Name "swFramework - Win32 Static ANSI Release Monolithic USE_VTK_0"
# Name "swFramework - Win32 Static ANSI Release Multilib USE_VTK_1"
# Name "swFramework - Win32 Static ANSI Release Multilib USE_VTK_0"
# Begin Group "Source Files"

# PROP Default_Filter ""
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

SOURCE=..\..\src\swFrameworkDependent\Widget\swNewBitmapButton.cpp
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

SOURCE=..\..\src\swFrameworkDependent\FrameFactory\swWindow.cpp
# End Source File
# End Group
# End Target
# End Project

