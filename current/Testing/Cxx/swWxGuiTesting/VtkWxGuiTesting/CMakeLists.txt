###############################################################################
# Name:        swWxGuiTesting/VtkWxGuiTesting/CMakeLists.txt
# Author:      Reinhold Füreder
# Created:     2004
# Copyright:   (c) 2005 Reinhold Füreder
# Licence:     wxWindows licence
###############################################################################

PROJECT (swVtkWxGuiTesting)

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
# Get ThirdPartyLibs directory of user.
SET (THIRD_PARTY_LIBS_DIR CACHE PATH "ThirdPartyLibs Build Path")
IF (EXISTS ${THIRD_PARTY_LIBS_DIR})
    # Use wxVTK.
    INCLUDE (${THIRD_PARTY_LIBS_DIR}/UseWxVTK.cmake)
ELSE (EXISTS ${THIRD_PARTY_LIBS_DIR})
    MESSAGE (FATAL_ERROR "Cannot build without ThirdPartyLibs. Please set THIRD_PARTY_LIBS_DIR.")
ENDIF (EXISTS ${THIRD_PARTY_LIBS_DIR})
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Capture panel XRC file is compiled into a c++ file with embedded resources:
# %wxrcPath%/wxrc.exe -v -c -n InitVtkCapturePanelXRC -o VtkCapturePanel.cpp ./VtkCapturePanel_wdr.xrc
ADD_CUSTOM_COMMAND(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/VtkCapturePanel.cpp
    COMMAND ${WXRC_EXE}
    ARGS
        -v -c
        -n InitVtkCapturePanelXRC
        -o ${CMAKE_CURRENT_BINARY_DIR}/VtkCapturePanel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/VtkCapturePanel_wdr.xrc
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/VtkCapturePanel_wdr.xrc
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Sources:
FILE (GLOB CPP *.cpp)
FILE (GLOB HDR *.h)


SET (SRCS
    ${CPP}
    ${HDR}
    ${CMAKE_CURRENT_BINARY_DIR}/VtkCapturePanel.cpp
)
#-----------------------------------------------------------------------------
# Includes:
SET (INCS
    ${ThirdPartyLibs_CppUnit_INCLUDE_DIRS}
    ${ThirdPartyLibs_wxVTK_INCLUDE_DIRS}

    ${swFrameworkDependent_SOURCE_DIR}
    ${swFrameworkDependent_SOURCE_DIR}/Config
    ${swFrameworkDependent_SOURCE_DIR}/Exception
    ${swFrameworkDependent_SOURCE_DIR}/FrameFactory
    ${swFrameworkDependent_SOURCE_DIR}/GUI
    ${swFrameworkDependent_SOURCE_DIR}/Widget

    ${swWxGuiTesting_SOURCE_DIR}
)
#-----------------------------------------------------------------------------
# Libraries:
SET (LIBS
    ${ThirdPartyLibs_CppUnit_LIBRARIES}
    ${ThirdPartyLibs_wxVTK_LIBRARIES}
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Configuration of CMake usage file:

# The swVtkWxGuiTesting include file directories.
SET (swVtkWxGuiTesting_INCLUDE_DIRS_CONFIG
    ${INCS}
    ${swVtkWxGuiTesting_SOURCE_DIR}
)


# The swVtkWxGuiTesting link directories.
SET (swVtkWxGuiTesting_LIBRARY_DIRS_CONFIG
    ${swVtkWxGuiTesting_BINARY_DIR}
)


# A list of all libraries for swVtkWxGuiTesting.
SET (swVtkWxGuiTesting_LIBRARIES_CONFIG
    ${LIBS}
    swFrameworkDependent
    swVtkWxGuiTesting
)

# Create CMake usage file:
CONFIGURE_FILE ("${swVtkWxGuiTesting_SOURCE_DIR}/UseSwVtkWxGuiTesting.cmake.in"
    "${Testing_BINARY_DIR}/UseSwVtkWxGuiTesting.cmake"
    @ONLY
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Actually build swVtkWxGuiTesting framework:
INCLUDE_DIRECTORIES(
    ${swVtkWxGuiTesting_INCLUDE_DIRS_CONFIG}
)

ADD_LIBRARY (swVtkWxGuiTesting
    ${SRCS}
)

LINK_DIRECTORIES(
  	${ThirdPartyLibs_wxVTK_LIBRARY_DIRS}
)

TARGET_LINK_LIBRARIES (swVtkWxGuiTesting
    ${LIBS}
    swFrameworkDependent
    swWxGuiTesting
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Finally CppUnit testing of swVtkWxGuiTesting unit testing framework, what a nice
# recursion:
SUBDIRS (CppGuiTest)
#-----------------------------------------------------------------------------
