///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppTest/swCRCppEmitterTest.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRCPPEMITTERTEST_H
#define SWCRCPPEMITTERTEST_H

#ifdef __GNUG__
    #pragma interface "swCRCppEmitterTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

#include "wx/arrstr.h"

namespace swTst {


/*! \class CRCppEmitterTest
    \brief Test C++ code emitting.
*/
class CRCppEmitterTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CRCppEmitterTest );

        CPPUNIT_TEST( testExample );
        CPPUNIT_TEST( testMakeVarName );

    CPPUNIT_TEST_SUITE_END();

public:
    /*! \fn virtual void setUp ()
        \brief Set up context before running a test.
    */
    virtual void setUp ();


    /*! \fn virtual void tearDown ()
        \brief Clean up after the test run.
    */
    virtual void tearDown ();


    /*! \fn virtual void testExample ()
        \brief Example test case.
    */
    virtual void testExample ();


    /*! \fn virtual void testMakeVarName ()
        \brief Test making of variable names (incl. first letter lower case).
    */
    virtual void testMakeVarName ();

protected:
    /*! \fn void checkEmittedCode (const wxString &captureFilename, const wxArrayString &expectedCode) const
        \brief Helper method to verify emitted code.
    */
    virtual void checkEmittedCode (const wxString &captureFilename,
            const wxArrayString &expectedCode) const;

private:

};

} // End namespace swTst

#endif // SWCRCPPEMITTERTEST_H

