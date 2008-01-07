# Microsoft Developer Studio Project File - Name="swWxGuiTesting_VTKUnitTest" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=VTKUnitTest - Win32 Static ANSI Release Multilib USE_VTK_1
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "swWxGuiTesting_VTKUnitTest.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "swWxGuiTesting_VTKUnitTest.mak" CFG="VTKUnitTest - Win32 Static ANSI Release Multilib USE_VTK_1"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "VTKUnitTest - Win32 DLL Unicode Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 DLL Unicode Debug Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 DLL Unicode Release Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 DLL Unicode Release Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 DLL ANSI Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 DLL ANSI Debug Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 DLL ANSI Release Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 DLL ANSI Release Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 Static Unicode Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 Static Unicode Debug Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 Static Unicode Release Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 Static Unicode Release Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 Static ANSI Debug Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 Static ANSI Debug Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 Static ANSI Release Monolithic USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE "VTKUnitTest - Win32 Static ANSI Release Multilib USE_VTK_1" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "VTKUnitTest - Win32 DLL Unicode Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console /debug
# ADD LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console /debug

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 DLL Unicode Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_dll\mswud" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswud" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28ud_gl.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console /debug
# ADD LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28ud_gl.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console /debug

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 DLL Unicode Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console
# ADD LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 DLL Unicode Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\mswu" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswu" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28u_gl.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console
# ADD LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28u_gl.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 DLL ANSI Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console /debug
# ADD LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console /debug

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 DLL ANSI Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_dll\mswd" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\mswd" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28d_gl.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console /debug
# ADD LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28d_gl.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console /debug

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 DLL ANSI Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console
# ADD LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 DLL ANSI Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_dll\msw" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "WXUSINGDLL" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "WXUSINGDLL" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_dll\msw" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28_gl.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console
# ADD LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28_gl.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_dll" /libpath:"$(VTK)\lib" /subsystem:console

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 Static Unicode Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console /debug
# ADD LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console /debug

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 Static Unicode Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_lib\mswud" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "_UNICODE" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswud" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28ud_gl.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console /debug
# ADD LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28ud_gl.lib wxmsw28ud_xrc.lib wxmsw28ud_html.lib wxmsw28ud_adv.lib wxbase28ud_xml.lib wxmsw28ud_core.lib wxbase28ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console /debug

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 Static Unicode Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console
# ADD LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 Static Unicode Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\mswu" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "_UNICODE" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "_UNICODE" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswu" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28u_gl.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console
# ADD LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28u_gl.lib wxmsw28u_xrc.lib wxmsw28u_html.lib wxmsw28u_adv.lib wxbase28u_xml.lib wxmsw28u_core.lib wxbase28u.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 Static ANSI Debug Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console /debug
# ADD LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console /debug

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 Static ANSI Debug Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MDd /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /Od /I "$(WXWIN)\lib\vc_lib\mswd" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Zi /Gm /GZ /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "__WXDEBUG__" /D "__WXMSW__" /D "_CONSOLE" /D "_DEBUG" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "__WXDEBUG__" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\mswd" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /d "_DEBUG" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28d_gl.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console /debug
# ADD LINK32 cppunitd_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTestingd.lib opengl32.lib glu32.lib wxmsw28d_gl.lib wxmsw28d_xrc.lib wxmsw28d_html.lib wxmsw28d_adv.lib wxbase28d_xml.lib wxmsw28d_core.lib wxbase28d.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexd.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console /debug

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 Static ANSI Release Monolithic USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console
# ADD LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console

!ELSEIF  "$(CFG)" == "VTKUnitTest - Win32 Static ANSI Release Multilib USE_VTK_1"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\bin"
# PROP BASE Intermediate_Dir "objects\VTKUnitTest"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\bin"
# PROP Intermediate_Dir "objects\VTKUnitTest"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD CPP /nologo /FD /MD /W1 /GR /EHsc /I "..\..\include" /I "$(CPPUNIT)\include" /O2 /I "$(WXWIN)\lib\vc_lib\msw" /I "$(WXWIN)\include" /I "$(VTK)\include" /I "..\..\src\wxVTK" /Fd..\..\bin\VTKUnitTest.pdb /I "..\..\include\wxGuiTest\VtkWxGuiTesting" /D "WIN32" /D "__WXMSW__" /D "_CONSOLE" /D VTKDIR=\"../../test/TestData/vtk\" /D XRCDIR=\"../../test/TestData/xrc\" /D SRCDIR=\"../..\" /c
# ADD BASE RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
# ADD RSC /l 0x409 /i "..\..\include" /i "$(CPPUNIT)\include" /d "__WXMSW__" /i "$(WXWIN)\lib\vc_lib\msw" /i "$(WXWIN)\include" /i "$(VTK)\include" /i "..\..\src\wxVTK" /d "_CONSOLE" /i "..\..\include\wxGuiTest\VtkWxGuiTesting" /d VTKDIR="../../test/TestData/vtk" /d XRCDIR="../../test/TestData/xrc" /d SRCDIR="../.."
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28_gl.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console
# ADD LINK32 cppunit_dll.lib vtkCommon.lib vtkDICOMParser.lib vtkexpat.lib vtkFiltering.lib vtkfreetype.lib vtkftgl.lib vtkGraphics.lib vtkHybrid.lib vtkImaging.lib vtkIO.lib vtkjpeg.lib vtkpng.lib vtkRendering.lib vtktiff.lib vtkzlib.lib ..\..\lib\swWxGuiTesting.lib opengl32.lib glu32.lib wxmsw28_gl.lib wxmsw28_xrc.lib wxmsw28_html.lib wxmsw28_adv.lib wxbase28_xml.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib /nologo /machine:i386 /out:"..\..\bin\VTKUnitTest.exe" /libpath:"$(CPPUNIT)\lib" /libpath:"$(WXWIN)\lib\vc_lib" /libpath:"$(VTK)\lib" /subsystem:console

!ENDIF

# Begin Target

# Name "VTKUnitTest - Win32 DLL Unicode Debug Monolithic USE_VTK_1"
# Name "VTKUnitTest - Win32 DLL Unicode Debug Multilib USE_VTK_1"
# Name "VTKUnitTest - Win32 DLL Unicode Release Monolithic USE_VTK_1"
# Name "VTKUnitTest - Win32 DLL Unicode Release Multilib USE_VTK_1"
# Name "VTKUnitTest - Win32 DLL ANSI Debug Monolithic USE_VTK_1"
# Name "VTKUnitTest - Win32 DLL ANSI Debug Multilib USE_VTK_1"
# Name "VTKUnitTest - Win32 DLL ANSI Release Monolithic USE_VTK_1"
# Name "VTKUnitTest - Win32 DLL ANSI Release Multilib USE_VTK_1"
# Name "VTKUnitTest - Win32 Static Unicode Debug Monolithic USE_VTK_1"
# Name "VTKUnitTest - Win32 Static Unicode Debug Multilib USE_VTK_1"
# Name "VTKUnitTest - Win32 Static Unicode Release Monolithic USE_VTK_1"
# Name "VTKUnitTest - Win32 Static Unicode Release Multilib USE_VTK_1"
# Name "VTKUnitTest - Win32 Static ANSI Debug Monolithic USE_VTK_1"
# Name "VTKUnitTest - Win32 Static ANSI Debug Multilib USE_VTK_1"
# Name "VTKUnitTest - Win32 Static ANSI Release Monolithic USE_VTK_1"
# Name "VTKUnitTest - Win32 Static ANSI Release Multilib USE_VTK_1"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\test\VtkTest\CppTextTestApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\test\VtkTest\swCRVtkCaptureTest.cpp
# End Source File
# End Group
# End Target
# End Project

