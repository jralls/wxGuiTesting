###############################################################################
# Name:        wxVTK/CMakeLists.txt
# Author:      Reinhold Füreder
# Created:     2004
# Copyright:   (c) 2005 Reinhold Füreder
# Licence:     wxWindows licence
###############################################################################

PROJECT (wxVTK)

#-----------------------------------------------------------------------------
# Look for VTK.
FIND_PACKAGE(VTK)
IF (VTK_FOUND)
   INCLUDE (${VTK_USE_FILE})
ELSE(VTK_FOUND)
   MESSAGE(FATAL_ERROR "Cannot build without VTK. Please set VTK_DIR.")
ENDIF(VTK_FOUND)


#-----------------------------------------------------------------------------
# Look for WXWINDOWS.
SET( wxWidgets_USE_LIBS  base core gl xml xrc )
FIND_PACKAGE(wxWidgets REQUIRED)
INCLUDE( ${wxWidgets_USE_FILE} )

IF (NOT WIN32)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} `pkg-config --cflags gtk+-2.0`")
	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D__WXDEBUG__ -DWXDEBUG=1")

	IF(LINUX)
		ADD_DEFINITIONS( -DLINUX=1 )
	ENDIF(LINUX)
ENDIF (NOT WIN32)


SET (wxVTK_INCLUDE_DIRS_CONFIG
    ${wxVTK_SOURCE_DIR}
)


IF (WIN32)
	SET (wxVTK_LIBRARY_DIRS_CONFIG
    	${wxVTK_BINARY_DIR}/${CMAKE_CFG_INTDIR}
	)
ELSE (WIN32)
	SET (wxVTK_LIBRARY_DIRS_CONFIG
    	${wxVTK_BINARY_DIR}
	)
ENDIF (WIN32)


SET (wxVTK_LIBRARIES_CONFIG
   	wxVTK
)


SET (wxVTK_SRC
    wxVTKRenderWindowInteractor.cpp
    wxVTKRenderWindowInteractor.h
)


INCLUDE_DIRECTORIES (${WXWIDGETS_INCLUDE_DIR})


ADD_LIBRARY (wxVTK
    ${wxVTK_SRC}
)


LINK_DIRECTORIES(${WXWIDGETS_LINK_DIRECTORIES})


TARGET_LINK_LIBRARIES (wxVTK
    ${wxWidgets_LIBRARIES}
)


CONFIGURE_FILE ("${wxVTK_SOURCE_DIR}/UseWxVTK.cmake.in"
    "${ThirdPartyLibs_BINARY_DIR}/UseWxVTK.cmake"
    @ONLY
)
