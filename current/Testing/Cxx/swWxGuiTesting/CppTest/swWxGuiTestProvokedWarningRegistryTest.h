///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppTest/swWxGuiTestProvokedWarningRegistryTest.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWWXGUITESTPROVOKEDWARNINGREGISTRYTEST_H
#define SWWXGUITESTPROVOKEDWARNINGREGISTRYTEST_H

#ifdef __GNUG__
    #pragma interface "swWxGuiTestProvokedWarningRegistryTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

namespace swTst {


/*! \class WxGuiTestProvokedWarningRegistryTest
    \brief Test WxGuiTestProvokedWarningRegistry.
*/
class WxGuiTestProvokedWarningRegistryTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( WxGuiTestProvokedWarningRegistryTest );

        CPPUNIT_TEST( testUnRegister );
        CPPUNIT_TEST( testTimeout );
        CPPUNIT_TEST( testDetection );
        CPPUNIT_TEST( testFinding );

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


    /*! \fn virtual void testUnRegister ()
        \brief Test case for simple registration and unregistration.
    */
    virtual void testUnRegister ();


    /*! \fn virtual void testTimeout ()
        \brief Test case for timeout exceeding.
    */
    virtual void testTimeout ();


    /*! \fn virtual void testDetection ()
        \brief Test case for warning detection.
    */
    virtual void testDetection ();


    /*! \fn virtual void testFinding ()
        \brief Test case for finding registered warnings.
    */
    virtual void testFinding ();

protected:

private:

};

} // End namespace swTst

#endif // SWWXGUITESTPROVOKEDWARNINGREGISTRYTEST_H

