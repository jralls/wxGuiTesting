###############################################################################
# Name:        swWxGuiTesting/VtkWxGuiTesting/CppGuiTest/CMakeLists.txt
# Author:      Reinhold Füreder
# Created:     2004
# Copyright:   (c) 2005 Reinhold Füreder
# Licence:     wxWindows licence
###############################################################################

#-----------------------------------------------------------------------------
# Use VTK:
FIND_PACKAGE (VTK)
IF (VTK_FOUND)
    INCLUDE (${VTK_USE_FILE})
ELSE (VTK_FOUND)
    MESSAGE (FATAL_ERROR "Cannot build without VTK. Please set VTK_DIR.")
ENDIF (VTK_FOUND)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Look for WXWINDOWS.
SET( wxWidgets_USE_LIBS  base core gl xrc adv html xml)
FIND_PACKAGE(wxWidgets REQUIRED)
INCLUDE( ${wxWidgets_USE_FILE} )
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Get ThirdPartyLibs directory of user.
SET (THIRD_PARTY_LIBS_DIR CACHE PATH "ThirdPartyLibs Build Path")
IF (EXISTS ${THIRD_PARTY_LIBS_DIR})
    # Use CppUnit.
    INCLUDE (${THIRD_PARTY_LIBS_DIR}/UseCppUnit.cmake)
ELSE (EXISTS ${THIRD_PARTY_LIBS_DIR})
    MESSAGE (FATAL_ERROR "Cannot build without ThirdPartyLibs. Please set THIRD_PARTY_LIBS_DIR.")
ENDIF (EXISTS ${THIRD_PARTY_LIBS_DIR})
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Include directories:
INCLUDE_DIRECTORIES (${ThirdPartyLibs_CppUnit_INCLUDE_DIRS})
INCLUDE_DIRECTORIES (${swFrameworkDependent_SOURCE_DIR})
INCLUDE_DIRECTORIES (${swFrameworkDependent_SOURCE_DIR}/Exception)
INCLUDE_DIRECTORIES (${swFrameworkDependent_SOURCE_DIR}/Widget)
INCLUDE_DIRECTORIES (${swWxGuiTesting_SOURCE_DIR})
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Test capture and replay.
LINK_DIRECTORIES (
    ${ThirdPartyLibs_CppUnit_LIBRARY_DIRS}
    ${swWxGuiTesting_BINARY_DIR}
)


ADD_EXECUTABLE (CppGuiTestVtkCaptureReplay
    CppTextTestApp.cpp
    swCRVtkCaptureTest.h
    swCRVtkCaptureTest.cpp
)


TARGET_LINK_LIBRARIES (CppGuiTestVtkCaptureReplay
    ${wxWidgets_LIBRARIES}
    ${ThirdPartyLibs_CppUnit_LIBRARIES}

    vtkCommon
    vtkRendering

    swFrameworkDependent
    swWxGuiTesting
    swVtkWxGuiTesting
)
#-----------------------------------------------------------------------------
