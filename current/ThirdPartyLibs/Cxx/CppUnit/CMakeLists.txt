###############################################################################
# Name:        CppUnit/CMakeLists.txt
# Author:      Reinhold Fuereder
# Created:     2004
# Copyright:   (c) 2005 Reinhold Fuereder
# Licence:     wxWindows licence
###############################################################################

PROJECT (CppUnit)

# Get CppUnit directory of user.
SET (CPPUNIT_PATH CACHE PATH "CppUnit Path")

IF (EXISTS ${CPPUNIT_PATH})
    # Nothing to do
ELSE (EXISTS ${CPPUNIT_PATH})
    MESSAGE (FATAL_ERROR "Cannot build without CppUnit. Please set CPPUNIT_PATH.")
ENDIF (EXISTS ${CPPUNIT_PATH})


SET (CPPUNIT_INCLUDE_DIRS_CONFIG
    ${CPPUNIT_PATH}/include
)


SET (CPPUNIT_LIBRARY_DIRS_CONFIG
    ${CPPUNIT_PATH}/lib
)


IF (WIN32)
    SET (CPPUNIT_LIBRARIES_CONFIG
        debug cppunitd
        optimized cppunit
    )
ELSE (WIN32)
    SET (CPPUNIT_LIBRARIES_CONFIG
        cppunit
    )
ENDIF (WIN32)


CONFIGURE_FILE ("${CppUnit_SOURCE_DIR}/UseCppUnit.cmake.in"
    "${ThirdPartyLibs_BINARY_DIR}/UseCppUnit.cmake"
    @ONLY
)
