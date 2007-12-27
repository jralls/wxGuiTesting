///////////////////////////////////////////////////////////////////////////////
// Name:        SimpleTest.h
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SIMPLETEST_H
#define SIMPLETEST_H

#ifdef __GNUG__
    #pragma interface "SimpleTest.h"
#endif

#include "xrcdemo.h"
#include "myframe.h"
#include <cppunit/extensions/HelperMacros.h>


/*! \class SimpleTest
    \brief Test capturing of GUI interaction.
*/
class SimpleTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SimpleTest );

        CPPUNIT_TEST( testExample );
        CPPUNIT_TEST( testTrivial );

    CPPUNIT_TEST_SUITE_END();

public:
    /*! \fn virtual void setUp ()
        \brief Set up context before running a test.
    */
    SimpleTest();
    ~SimpleTest();
    virtual void setUp ();


    /*! \fn virtual void tearDown ()
        \brief Clean up after the test run.
    */
    virtual void tearDown ();


    /*! \fn virtual void testCapture ()
        \brief Minimal capture test case.
    */
    virtual void testExample ();
    void testTrivial();

protected:

private:
};

#endif // SIMPLETEST_H

