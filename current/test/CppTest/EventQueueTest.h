///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppTest/EventQueueTest.h
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


/*! \class EventQueueTest
    \brief Test C++ code emitting.
*/
class EventQueueTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( EventQueueTest );

        CPPUNIT_TEST( NewQueue );
        CPPUNIT_TEST( AddEvents );
        CPPUNIT_TEST( GetEvents );

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

/** \fn void NewQueue ()
 *  \brief Test the creation of a queue in the store
 */
    virtual void NewQueue();

/** \fn void AddEvents ()
 *  \brief Check the addition of events to the queue
 */
    virtual void AddEvents();

/** \fn void GetEvents ()
 *  \brief Test that event retrieval works  
 *  and that the queue is cleaned up when the last item is popped.
 */
    virtual void GetEvents();
 
private:

/** \fn void populate ()
 *  \brief Add two events to the current queue
 */
    virtual void populate(EventQueue* q);

};

} // End namespace wxTst

#endif // EVENTQUEUETEST_H

