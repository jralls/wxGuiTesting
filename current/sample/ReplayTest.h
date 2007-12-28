///////////////////////////////////////////////////////////////////////////////
// Name:        SimpleCRTest.h
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef REPLAYTEST_H
#define REPLAYTEST_H

#ifdef __GNUG__
    #pragma interface "ReplayTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>


/*! \class ReplayTest
    \brief Test capturing of GUI interaction.
*/
class ReplayTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( ReplayTest );

        CPPUNIT_TEST( testDialog );
        CPPUNIT_TEST( testUncentered );
        CPPUNIT_TEST( testArtProvider );
        CPPUNIT_TEST( testPlatformSpecific );

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
    virtual void testDialog ();
    void testUncentered();
    void testArtProvider();
    void testPlatformSpecific();

protected:

private:

};

#endif // REPLAYTEST_H

