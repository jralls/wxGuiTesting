///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/TestEventLoopTest.h
// Author:      John Ralls
// Created:     2009
// Copyright:   (c) 2009 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef EVENTQUEUETEST_H
#define EVENTQUEUETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <wxGuiTest/EventQueue.h>

#include <wx/arrstr.h>

namespace wxTst {

/*! \class TestEventLoopTest
    \brief Test C++ code emitting.
*/
class TestEventLoopTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( TestEventLoopTest );

        CPPUNIT_TEST( testQueueEvent );
        CPPUNIT_TEST( testDialog );

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

    virtual void testQueueEvent();

    virtual void testDialog();

 
private:

};

} // End namespace wxTst

#endif // EVENTQUEUETEST_H

