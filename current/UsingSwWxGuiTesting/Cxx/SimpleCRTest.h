///////////////////////////////////////////////////////////////////////////////
// Name:        SimpleCRTest.h
// Author:      Reinhold Füreder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SIMPLECRTEST_H
#define SIMPLECRTEST_H

#ifdef __GNUG__
    #pragma interface "SimpleCRTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>


/*! \class SimpleCRTest
    \brief Test capturing of GUI interaction.
*/
class SimpleCRTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SimpleCRTest );

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

#endif // SIMPLECRTEST_H

