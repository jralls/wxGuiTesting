# Microsoft Developer Studio Project File - Name="wxGuiTesting_CppUnitTest" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=CppUnitTest - Win32 Static ANSI Release Multilib USE_VTK_0
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "wxGuiTesting_CppUnitTest.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "wxGuiTesting_CppUnitTest.mak" CFG="CppUnitTest - Win32 Static ANSI Release Multilib USE_VTK_0"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CppUnitTest - Win32 DLL Unicode Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL Unicode Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL Unicode Debug Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL Unicode Debug Multilib USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL Unicode Release Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL Unicode Release Monolithic USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL Unicode Release Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL Unicode Release Multilib USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL ANSI Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL ANSI Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL ANSI Debug Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL ANSI Debug Multilib USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL ANSI Release Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL ANSI Release Monolithic USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL ANSI Release Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 DLL ANSI Release Multilib USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static Unicode Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static Unicode Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static Unicode Debug Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static Unicode Debug Multilib USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static Unicode Release Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static Unicode Release Monolithic USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static Unicode Release Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static Unicode Release Multilib USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static ANSI Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static ANSI Debug Monolithic USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static ANSI Debug Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static ANSI Debug Multilib USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static ANSI Release Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static ANSI Release Monolithic USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static ANSI Release Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "CppUnitTest - Win32 Static ANSI Release Multilib USE_VTK_0" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CppUnitTest - Win32 DLL Unicode Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL Unicode Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL Unicode Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL Unicode Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL Unicode Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL Unicode Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL Unicode Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL Unicode Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL ANSI Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL ANSI Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL ANSI Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL ANSI Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL ANSI Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL ANSI Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL ANSI Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 DLL ANSI Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static Unicode Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static Unicode Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static Unicode Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static Unicode Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static Unicode Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static Unicode Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static Unicode Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static Unicode Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static ANSI Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static ANSI Debug Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static ANSI Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static ANSI Debug Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /Od /Gm /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /Zi /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /d "_CONSOLE" /d "_DEBUG" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTestingd.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /debug /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static ANSI Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static ANSI Release Monolithic USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static ANSI Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ELSEIF  "$(CFG)" == "CppUnitTest - Win32 Static ANSI Release Multilib USE_VTK_0"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\CppUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\CppUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "..\..\src\wxGuiTest" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /Fd..\..\bin\CppUnitTest.pdb /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D TESTDIR=\"../../test/TestData\" /D XRCDIR=\"../../test/TestData/xrc\" /D TESTSRCDIR=\"../../test/CppGuiTest\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
# ADD RSC /l 0x409 /i "..\..\include" /i "..\..\src\wxGuiTest" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /d "_CONSOLE" /d TESTDIR="../../test/TestData" /d XRCDIR="../../test/TestData/xrc" /d TESTSRCDIR="../../test/CppGuiTest"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"
# ADD LINK32 $(CPPUNIT_LIB).lib ..\..\lib\wxGuiTesting.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\CppUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /subsystem:console /pdb:"..\..\bin\CppUnitTest.pdb"

!ENDIF

# Begin Target

# Name "CppUnitTest - Win32 DLL Unicode Debug Monolithic USE_VTK_1"
# Name "CppUnitTest - Win32 DLL Unicode Debug Monolithic USE_VTK_0"
# Name "CppUnitTest - Win32 DLL Unicode Debug Multilib USE_VTK_1"
# Name "CppUnitTest - Win32 DLL Unicode Debug Multilib USE_VTK_0"
# Name "CppUnitTest - Win32 DLL Unicode Release Monolithic USE_VTK_1"
# Name "CppUnitTest - Win32 DLL Unicode Release Monolithic USE_VTK_0"
# Name "CppUnitTest - Win32 DLL Unicode Release Multilib USE_VTK_1"
# Name "CppUnitTest - Win32 DLL Unicode Release Multilib USE_VTK_0"
# Name "CppUnitTest - Win32 DLL ANSI Debug Monolithic USE_VTK_1"
# Name "CppUnitTest - Win32 DLL ANSI Debug Monolithic USE_VTK_0"
# Name "CppUnitTest - Win32 DLL ANSI Debug Multilib USE_VTK_1"
# Name "CppUnitTest - Win32 DLL ANSI Debug Multilib USE_VTK_0"
# Name "CppUnitTest - Win32 DLL ANSI Release Monolithic USE_VTK_1"
# Name "CppUnitTest - Win32 DLL ANSI Release Monolithic USE_VTK_0"
# Name "CppUnitTest - Win32 DLL ANSI Release Multilib USE_VTK_1"
# Name "CppUnitTest - Win32 DLL ANSI Release Multilib USE_VTK_0"
# Name "CppUnitTest - Win32 Static Unicode Debug Monolithic USE_VTK_1"
# Name "CppUnitTest - Win32 Static Unicode Debug Monolithic USE_VTK_0"
# Name "CppUnitTest - Win32 Static Unicode Debug Multilib USE_VTK_1"
# Name "CppUnitTest - Win32 Static Unicode Debug Multilib USE_VTK_0"
# Name "CppUnitTest - Win32 Static Unicode Release Monolithic USE_VTK_1"
# Name "CppUnitTest - Win32 Static Unicode Release Monolithic USE_VTK_0"
# Name "CppUnitTest - Win32 Static Unicode Release Multilib USE_VTK_1"
# Name "CppUnitTest - Win32 Static Unicode Release Multilib USE_VTK_0"
# Name "CppUnitTest - Win32 Static ANSI Debug Monolithic USE_VTK_1"
# Name "CppUnitTest - Win32 Static ANSI Debug Monolithic USE_VTK_0"
# Name "CppUnitTest - Win32 Static ANSI Debug Multilib USE_VTK_1"
# Name "CppUnitTest - Win32 Static ANSI Debug Multilib USE_VTK_0"
# Name "CppUnitTest - Win32 Static ANSI Release Monolithic USE_VTK_1"
# Name "CppUnitTest - Win32 Static ANSI Release Monolithic USE_VTK_0"
# Name "CppUnitTest - Win32 Static ANSI Release Multilib USE_VTK_1"
# Name "CppUnitTest - Win32 Static ANSI Release Multilib USE_VTK_0"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\test\CppTest\CRCppEmitterTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\test\CppTest\CppUnitTextTestApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\test\CppTest\ProvokedWarningRegistryTest.cpp
# End Source File
# End Group
# End Target
# End Project

