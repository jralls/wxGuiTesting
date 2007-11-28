###############################################################################
# Name:        swWxGuiTesting/CMakeLists.txt
# Author:      Reinhold Füreder
# Created:     2004
# Copyright:   (c) 2005 Reinhold Füreder
# Licence:     wxWindows licence
###############################################################################

PROJECT (swWxGuiTesting)

#-----------------------------------------------------------------------------
# Use wxWidgets:
SET( wxWidgets_USE_LIBS  base core xrc)
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
# Get wxrc directory of user for subsequent capture panel XRC compilation:
SET (WXRC_DIR CACHE PATH "wxrc Executable Path")
SET (WXRC_EXE CACHE INTERNAL "wxrc Executable")
IF (EXISTS ${WXRC_DIR})
    IF (WIN32)
        SET (WXRC_EXE ${WXRC_DIR}/wxrc.exe)
    ELSE (WIN32)
        SET (WXRC_EXE ${WXRC_DIR}/wxrc)
    ENDIF (WIN32)

    IF (EXISTS ${WXRC_EXE})
        # Nothing to do
    ELSE (EXISTS ${WXRC_EXE})
        MESSAGE (FATAL_ERROR "Specifed path does not contain required wxrc executable. Please correct WXRC_DIR.")
    ENDIF (EXISTS ${WXRC_EXE})

ELSE (EXISTS ${WXRC_DIR})
    MESSAGE (FATAL_ERROR "Cannot build without wxrc executable. Please set WXRC_DIR.")
ENDIF (EXISTS ${WXRC_DIR})
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Capture panel XRC file is compiled into a c++ file with embedded resources:
# %wxrcPath%/wxrc.exe -v -c -n InitCapturePanelXRC -o CapturePanel.cpp ./CapturePanel_wdr.xrc
ADD_CUSTOM_COMMAND(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/CapturePanel.cpp
    COMMAND ${WXRC_EXE}
    ARGS
        -v -c
        -n InitCapturePanelXRC
        -o ${CMAKE_CURRENT_BINARY_DIR}/CapturePanel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CapturePanel_wdr.xrc
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/CapturePanel_wdr.xrc
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Sources:
FILE (GLOB CPP *.cpp)
FILE (GLOB HDR *.h)

FILE (GLOB EVENTS_CPP CapturedEvents/*.cpp)
FILE (GLOB EVENTS_HDR CapturedEvents/*.h)
SET (EVENTS_SRCS ${EVENTS_CPP} ${EVENTS_HDR})
SOURCE_GROUP ("Events" FILES ${EVENTS_SRCS})

SET (SRCS
    ${CPP}
    ${HDR}
    ${EVENTS_SRCS}
    ${CMAKE_CURRENT_BINARY_DIR}/CapturePanel.cpp
)
#-----------------------------------------------------------------------------
# Includes:
SET (INCS
    ${ThirdPartyLibs_CppUnit_INCLUDE_DIRS}
    ${swFrameworkDependent_SOURCE_DIR}
    ${swFrameworkDependent_SOURCE_DIR}/Config
    ${swFrameworkDependent_SOURCE_DIR}/Exception
    ${swFrameworkDependent_SOURCE_DIR}/FrameFactory
    ${swFrameworkDependent_SOURCE_DIR}/GUI
    ${swFrameworkDependent_SOURCE_DIR}/Widget
)
#-----------------------------------------------------------------------------
# Libraries:
SET (LIBS
    ${wxWidgets_LIBRARIES}

    ${ThirdPartyLibs_CppUnit_LIBRARIES}
)
MESSAGE(STATUS "${CMAKE_CURRENT_LIST_FILE}(${CMAKE_CURRENT_LIST_LINE}): wxWidgets_LIBRARIES ${wxWidgets_LIBRARIES}")
MESSAGE(STATUS "${CMAKE_CURRENT_LIST_FILE}(${CMAKE_CURRENT_LIST_LINE}): LIBRARIES ${LIBS}")
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Configuration of CMake usage file:

# The swWxGuiTesting include file directories.
SET (swWxGuiTesting_INCLUDE_DIRS_CONFIG
    ${INCS}
    ${swWxGuiTesting_SOURCE_DIR}
)

# A list of all libraries for swWxGuiTesting.
SET (swWxGuiTesting_LIBRARY_DIRS_CONFIG
    ${swFrameworkDependent_BINARY_DIR}
    ${swWxGuiTesting_BINARY_DIR}
    ${ThirdPartyLibs_CppUnit_LIBRARY_DIRS}
)

# A list of all libraries for swWxGuiTesting.
SET (swWxGuiTesting_LIBRARIES_CONFIG
    ${LIBS}
    swFrameworkDependent
    swWxGuiTesting
)

# Create CMake usage file:
CONFIGURE_FILE ("${swWxGuiTesting_SOURCE_DIR}/UseSwWxGuiTesting.cmake.in"
    "${Testing_BINARY_DIR}/UseSwWxGuiTesting.cmake"
    @ONLY
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Actually build swWxGuiTesting framework:
INCLUDE_DIRECTORIES(${swWxGuiTesting_INCLUDE_DIRS_CONFIG})
INCLUDE_DIRECTORIES(${swWxGuiTesting_SOURCE_DIR}/CapturedEvents)

ADD_LIBRARY (swWxGuiTesting
    ${SRCS}
)

TARGET_LINK_LIBRARIES (swWxGuiTesting
    ${LIBS}
    swFrameworkDependent
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# To avoid compile time dependencies wxVtk interaction recording is put into a
# separate project and conditionally included if during CMake building of
# ThirdPartyLibs USE_VTK_DEPENDENT_PARTS was set to on:
IF (EXISTS ${THIRD_PARTY_LIBS_DIR}/UseWxVTK.cmake)
  SUBDIRS (VtkWxGuiTesting)
ENDIF (EXISTS ${THIRD_PARTY_LIBS_DIR}/UseWxVTK.cmake)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Finally CppUnit testing of swWxGuiTesting unit testing framework, what a nice
# recursion:
SUBDIRS (CppTest)
SUBDIRS (CppGuiTest)
#-----------------------------------------------------------------------------
