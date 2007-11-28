###############################################################################
# Name:        swWxGuiTesting/CppTest/CMakeLists.txt
# Author:      Reinhold Füreder
# Created:     2004
# Copyright:   (c) 2005 Reinhold Füreder
# Licence:     wxWindows licence
###############################################################################

#-----------------------------------------------------------------------------
# Look for WXWINDOWS.
SET( wxWidgets_USE_LIBS  base core xrc xml)
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
INCLUDE_DIRECTORIES (${swWxGuiTesting_SOURCE_DIR})
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Sources:
FILE (GLOB CPPUNIT_TEST_SRC *.cpp)
FILE (GLOB CPPUNIT_TEST_HDR *.h)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Add testing with CppUnit.
LINK_DIRECTORIES(
    ${ThirdPartyLibs_CppUnit_LIBRARY_DIRS}
)


ADD_EXECUTABLE (CppTestSwWxGuiTesting
    ${CPPUNIT_TEST_SRC}
    ${CPPUNIT_TEST_HDR}
)


TARGET_LINK_LIBRARIES (CppTestSwWxGuiTesting
    ${wxWidgets_LIBRARIES}
    ${ThirdPartyLibs_CppUnit_LIBRARIES}
    swFrameworkDependent
    swWxGuiTesting
)
#-----------------------------------------------------------------------------
