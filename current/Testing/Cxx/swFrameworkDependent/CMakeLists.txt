###############################################################################
# Name:        swFrameworkDependent/CMakeLists.txt
# Author:      Reinhold Füreder
# Created:     2004
# Copyright:   (c) 2005 Reinhold Füreder
# Licence:     wxWindows licence
###############################################################################

PROJECT (swFrameworkDependent)

#-----------------------------------------------------------------------------
# Look for WXWINDOWS.
SET( wxWidgets_USE_LIBS  base core xrc adv html)
FIND_PACKAGE(wxWidgets REQUIRED)
INCLUDE( ${wxWidgets_USE_FILE} )
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Sources and grouping in MSVC:
FILE (GLOB MAIN_CPP ${swFrameworkDependent_SOURCE_DIR}/*.cpp)
FILE (GLOB MAIN_HDR ${swFrameworkDependent_SOURCE_DIR}/*.h)
SET (MAIN_SRCS ${MAIN_CPP} ${MAIN_HDR})
SOURCE_GROUP ("Main" FILES ${MAIN_SRCS})

FILE (GLOB_RECURSE EXCEPTION_CPP ${swFrameworkDependent_SOURCE_DIR}/Exception/*.cpp)
FILE (GLOB_RECURSE EXCEPTION_HDR ${swFrameworkDependent_SOURCE_DIR}/Exception/*.h)
SET (EXCEPTION_SRCS ${EXCEPTION_CPP} ${EXCEPTION_HDR})
SOURCE_GROUP ("Exception" FILES ${EXCEPTION_SRCS})

FILE (GLOB_RECURSE FRAMEFACTORY_CPP ${swFrameworkDependent_SOURCE_DIR}/FrameFactory/*.cpp)
FILE (GLOB_RECURSE FRAMEFACTORY_HDR ${swFrameworkDependent_SOURCE_DIR}/FrameFactory/*.h)
SET (FRAMEFACTORY_SRCS ${FRAMEFACTORY_CPP} ${FRAMEFACTORY_HDR})
SOURCE_GROUP ("FrameFactory" FILES ${FRAMEFACTORY_SRCS})

FILE (GLOB_RECURSE GUI_CPP ${swFrameworkDependent_SOURCE_DIR}/GUI/*.cpp)
FILE (GLOB_RECURSE GUI_HDR ${swFrameworkDependent_SOURCE_DIR}/GUI/*.h)
SET (GUI_SRCS ${GUI_CPP} ${GUI_HDR})
SOURCE_GROUP ("GUI" FILES ${GUI_SRCS})

FILE (GLOB_RECURSE WIDGET_CPP ${swFrameworkDependent_SOURCE_DIR}/Widget/*.cpp)
FILE (GLOB_RECURSE WIDGET_HDR ${swFrameworkDependent_SOURCE_DIR}/Widget/*.h)
SET (WIDGET_SRCS ${WIDGET_CPP} ${WIDGET_HDR})
SOURCE_GROUP ("Widget" FILES ${WIDGET_SRCS})

FILE (GLOB_RECURSE CONFIG_CPP ${swFrameworkDependent_SOURCE_DIR}/Config/*.cpp)
FILE (GLOB_RECURSE CONFIG_HDR ${swFrameworkDependent_SOURCE_DIR}/Config/*.h)
SET (CONFIG_SRCS ${CONFIG_CPP} ${CONFIG_HDR})
SOURCE_GROUP ("Config" FILES ${CONFIG_SRCS})

SET (LIB_SRCS
    ${MAIN_SRCS}
    ${EXCEPTION_SRCS}
    ${FRAMEFACTORY_SRCS}
    ${GUI_SRCS}
    ${WIDGET_SRCS}
    ${CONFIG_SRCS}
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Configuration of CMake usage file:

# The swFrameworkDependent include file directories.
SET (swFrameworkDependent_INCLUDE_DIRS_CONFIG
    ${swFrameworkDependent_SOURCE_DIR}
    ${swFrameworkDependent_SOURCE_DIR}/Exception
    ${swFrameworkDependent_SOURCE_DIR}/FrameFactory
    ${swFrameworkDependent_SOURCE_DIR}/GUI
    ${swFrameworkDependent_SOURCE_DIR}/Config
    ${swFrameworkDependent_SOURCE_DIR}/Widget
)


# A list of all libraries for Common.
IF (WIN32)
  SET (swFrameworkDependent_LIBRARY_DIRS_CONFIG
    ${swFrameworkDependent_BINARY_DIR}/${CMAKE_CFG_INTDIR}
  )
ELSE (WIN32)
  SET (swFrameworkDependent_LIBRARY_DIRS_CONFIG
    ${swFrameworkDependent_BINARY_DIR}
  )
ENDIF (WIN32)


SET (swFrameworkDependent_LIBRARIES_CONFIG
	swFrameworkDependent
)


# Create CMake usage file:
CONFIGURE_FILE ("${swFrameworkDependent_SOURCE_DIR}/UseSwFrameworkDependent.cmake.in"
    "${Testing_BINARY_DIR}/UseSwFrameworkDependent.cmake"
    @ONLY
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Include directories:
INCLUDE_DIRECTORIES (
    ${swFrameworkDependent_INCLUDE_DIRS_CONFIG}
)
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# Create library target.
ADD_LIBRARY (swFrameworkDependent ${LIB_SRCS})

TARGET_LINK_LIBRARIES (swFrameworkDependent
    ${wxWidgets_LIBRARIES}
)
#-----------------------------------------------------------------------------
