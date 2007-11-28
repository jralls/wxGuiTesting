###############################################################################
# Name:        CMakeLists.txt
# Author:      Reinhold Füreder
# Created:     2004
# Copyright:   (c) 2005 Reinhold Füreder
# Licence:     wxWindows licence
###############################################################################

PROJECT (ThirdPartyLibs)

#------------------------------------------------------------------------------
# This project allows the easy inclusion/usage of several third party projects
# which can all be used individually as well.
#
# Using it requires (1) building this parent project ("ThirdPartyLibs") with
# CMake, (2) copying and adapting the CMake code sequence shown below into
# your project specific CMakeLists.txt, and (3) using the variables holding
# include directories and libraries to her project.
#
# # ===========================================================================
# # Get ThirdPartyLibs directory of user.
# SET (THIRD_PARTY_LIBS_DIR CACHE PATH "ThirdPartyLibs Build Path")
#
# IF (EXISTS ${THIRD_PARTY_LIBS_DIR})
#
#     # Use CppUnit.
#     INCLUDE (${THIRD_PARTY_LIBS_DIR}/UseCppUnit.cmake)
#
#     # Use wxVTK.
#     INCLUDE (${THIRD_PARTY_LIBS_DIR}/UseWxVTK.cmake)
#
# ELSE (EXISTS ${THIRD_PARTY_LIBS_DIR})
#     MESSAGE (FATAL_ERROR "Cannot build without ThirdPartyLibs. Please set THIRD_PARTY_LIBS_DIR.")
# ENDIF (EXISTS ${THIRD_PARTY_LIBS_DIR})
# =============================================================================
#
#------------------------------------------------------------------------------

SUBDIRS (CppUnit)

#-----------------------------------------------------------------------------
# Optional VTK dependency:
OPTION (USE_VTK_DEPENDENT_PARTS "Use VTK dependent parts?" OFF)
IF (USE_VTK_DEPENDENT_PARTS)
    SUBDIRS (wxVTK)
ENDIF (USE_VTK_DEPENDENT_PARTS)
#-----------------------------------------------------------------------------
