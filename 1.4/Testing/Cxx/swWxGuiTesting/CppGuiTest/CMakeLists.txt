###############################################################################
# Name:        swWxGuiTesting/CppGuiTest/CMakeLists.txt
# Author:      Reinhold F�reder
# Created:     2004
# Copyright:   (c) 2005 Reinhold F�reder
# Licence:     wxWindows licence
###############################################################################

#-----------------------------------------------------------------------------
# Look for WXWINDOWS.
SET( wxWidgets_USE_LIBS  base core xrc adv html xml)
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
# Test event simulation.
LINK_DIRECTORIES(
    ${ThirdPartyLibs_CppUnit_LIBRARY_DIRS}
)


ADD_EXECUTABLE (CppGuiTestEventSimulation
    CppTextTestApp.cpp
    swWxGuiTestEventSimulationHelperTest.h
    swWxGuiTestEventSimulationHelperTest.cpp
    swWxGuiTestEvtSimHlpEvtHandler.h
    swWxGuiTestEvtSimHlpEvtHandler.cpp
)


TARGET_LINK_LIBRARIES (CppGuiTestEventSimulation
    ${wxWidgets_LIBRARIES}
    ${ThirdPartyLibs_CppUnit_LIBRARIES}
    swFrameworkDependent
    swWxGuiTesting
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Test capture and replay.
ADD_EXECUTABLE (CppGuiTestCaptureReplay
    CppTextTestApp.cpp
    swCRCaptureTest.h
    swCRCaptureTest.cpp
    swCRWindowHierarchyHandlerTest.h
    swCRWindowHierarchyHandlerTest.cpp
)


TARGET_LINK_LIBRARIES (CppGuiTestCaptureReplay
    ${wxWidgets_LIBRARIES}
    ${ThirdPartyLibs_CppUnit_LIBRARIES}
    swFrameworkDependent
    swWxGuiTesting
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Test modal dialogs.
ADD_EXECUTABLE (CppGuiTestModalDialog
    CppTextTestApp.cpp
    swModalDialogTest.h
	swModalDialogTest.cpp
	swModalDialogManipulator.cpp
	swModalDialogManipulator.h
	swDirDialogManipulator.cpp
	swDirDialogManipulator.h
)


TARGET_LINK_LIBRARIES (CppGuiTestModalDialog
    ${wxWidgets_LIBRARIES}
    ${ThirdPartyLibs_CppUnit_LIBRARIES}
    swFrameworkDependent
    swWxGuiTesting
)
#-----------------------------------------------------------------------------
