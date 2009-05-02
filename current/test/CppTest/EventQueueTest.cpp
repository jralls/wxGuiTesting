///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppTest/EventQueueTest.cpp
// Author:      John Ralls
// Created:     2009
// Copyright:   (c) 2009 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#include "EventQueueTest.h"

using namespace wxTst;

namespace {
    const wxString testSrcDir(_T(TESTSRCDIR));
    EventQStore* store = NULL;
}


// Register test suite:
CPPUNIT_TEST_SUITE_REGISTRATION( EventQueueTest );


void EventQueueTest::setUp ()
{
    store = new EventQStore;
    CPPUNIT_ASSERT_MESSAGE("SetUp: Failed to create a new EventQStore", 
			   store != NULL);
}


void EventQueueTest::tearDown ()
{
    CPPUNIT_ASSERT_MESSAGE("TearDown: No EventQStore to delete", 
			   store != NULL);
    delete store;
    store = NULL;
}

void EventQueueTest::NewQueue() {
    EventQueue* q = new EventQueue;
    CPPUNIT_ASSERT_MESSAGE("NewQueue: Failed to create a new EventQueue", 
			   store != NULL);
    CPPUNIT_ASSERT_MESSAGE("NewQueue: EventQueue isn't empty", 
			   store->isEmpty() == true);
    store->push_back(q);
    CPPUNIT_ASSERT_MESSAGE("NewQueue: Failed to reset front pointer",
			   store->get_front() != NULL);
    CPPUNIT_ASSERT_MESSAGE("NewQueue: Failed to reset back pointer",
			   store->get_back() != NULL);
    CPPUNIT_ASSERT_MESSAGE("NewQueue: Front and Back pointers disagree",
			   store->get_back() == store->get_front());
}

void EventQueueTest::AddEvents() {
    EventQueue* q = new EventQueue;
    store->push_back(q);
    populate(q);
    CPPUNIT_ASSERT_MESSAGE("AddEvents: EventQueue empty", 
			   q->isEmpty() == false);
} 

void EventQueueTest::GetEvents() {
    store->push_back(new EventQueue);
    populate(store->get_back());
    EventQueue* q = store->pop_front();
    CPPUNIT_ASSERT_MESSAGE("GetEvents: EventQueue empty", 
			   q->isEmpty() == false);
    wxEvent* event1 = q->pop_front();
    CPPUNIT_ASSERT_MESSAGE("GetEvents: First Event NULL", 
			   event1 != NULL);
    wxEvent* event2 = q->pop_front();
    CPPUNIT_ASSERT_MESSAGE("GetEvents: Second Event NULL", 
			   event2 != NULL);
    CPPUNIT_ASSERT_MESSAGE("GetEvents: Event pointers the same", 
			   event2 != event1);
    CPPUNIT_ASSERT_MESSAGE("GetEvents: Events the same", 
			   event2->GetId() != event1->GetId());
    CPPUNIT_ASSERT_MESSAGE("AddEvents: EventQueue isn't empty", 
			   q->isEmpty() == true);
    CPPUNIT_ASSERT_MESSAGE("AddEvents: EventQStore isn't empty", 
			   store->isEmpty() == true);
    delete event1;
    delete event2;
    delete q;
}

void EventQueueTest::populate(EventQueue* q) {
    wxCommandEvent evt1(wxEVT_COMMAND_BUTTON_CLICKED, 1);
    wxCommandEvent evt2(wxEVT_COMMAND_BUTTON_CLICKED, 2);
    q->push_back(evt1.Clone());
    q->push_back(evt2.Clone());
}

