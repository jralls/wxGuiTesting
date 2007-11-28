###############################################################################
# Name:        CMakeLists.txt
# Author:      Reinhold Fuereder
# Created:     2004
# Copyright:   (c) 2005 Reinhold Fuereder
# Licence:     wxWindows licence
###############################################################################

PROJECT(UsingSwWxGuiTesting)

#-----------------------------------------------------------------------------
# Use wxWidgets:
SET( wxWidgets_USE_LIBS  base core xrc adv html xml)
IF (APPLE)
   SET (wxWidgets_INCLUDE_DIRS_NO_SYSTEM 1)
   SET (GUI_EXECUTABLE MACOSX_BUNDLE)
ENDIF (APPLE)
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
# Get swWxGuiTesting Testing directory of user.
SET (TESTING_DIR CACHE PATH "swWxGuiTesting Testing Build Path")
IF (EXISTS ${TESTING_DIR})

    # Use swFrameworkDependent.
    INCLUDE (${TESTING_DIR}/UseSwFrameworkDependent.cmake)

    # Use swWxGuiTesting.
    INCLUDE (${TESTING_DIR}/UseSwWxGuiTesting.cmake)

ELSE (EXISTS ${TESTING_DIR})
    MESSAGE (FATAL_ERROR "Cannot build without swWxGuiTesting Testing. Please set TESTING_DIR.")
ENDIF (EXISTS ${TESTING_DIR})
#-----------------------------------------------------------------------------


INCLUDE_DIRECTORIES (${Testing_swFrameworkDependent_INCLUDE_DIRS})
INCLUDE_DIRECTORIES (${Testing_swWxGuiTesting_INCLUDE_DIRS})

LINK_DIRECTORIES (${Testing_swFrameworkDependent_LIBRARY_DIRS})
LINK_DIRECTORIES (${Testing_swWxGuiTesting_LIBRARY_DIRS})

FILE (GLOB CPP *.cpp)
FILE (GLOB HDR *.h)

ADD_EXECUTABLE (UsingSwWxGuiTesting ${GUI_EXECUTABLE}
    ${CPP}
    ${HDR}
)


TARGET_LINK_LIBRARIES (UsingSwWxGuiTesting
    ${Testing_swWxGuiTesting_LIBRARIES}
    ${Testing_swFrameworkDependent_LIBRARIES}
    ${wxWidgets_LIBRARIES}
)
#-----------------------------------------------------------------------------
