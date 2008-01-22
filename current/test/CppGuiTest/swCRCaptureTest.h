///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/CRCaptureTest.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef CRCAPTURETEST_H
#define CRCAPTURETEST_H

#ifdef __GNUG__
    #pragma interface "CRCaptureTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

namespace wxTst {


/*! \class CRCaptureTest
    \brief Test capturing of GUI interaction.
*/
class CRCaptureTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CRCaptureTest );

        CPPUNIT_TEST( testCapture );

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


    /*! \fn virtual void testCapture ()
        \brief Minimal capture test case.
    */
    virtual void testCapture ();

protected:

private:

};

} // End namespace wxTst

#endif // CRCAPTURETEST_H

