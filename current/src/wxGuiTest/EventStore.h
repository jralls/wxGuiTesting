///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/EventStore.h
// Author:      John Ralls
// Created:     2009
// Copyright:   (c) 2009 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

namespace wxTst {

/**
 * A list of events ready to be posted to windows and processed
 * 
 */

    class EventQueue {
    public:
	EventQueue();
	~EventQueue();
	PutEvent();
	GetEvent();
	PeekEvent();
    private:
	wxList m_queue;
    };

/**
 * A list of EventQueues. 
 * wxGuiTestApp can stack up event queues so that each nested event
 * loop will have its own set of events to pull from.
 */
    class EventQStore {
    public:
	EventQStore();
	~EventQStore();
/** \fn EventQueue& PopEventQueue ()
 *  \brief Remove the next EventQueue from the store for processing
 *  \return The EventStore
 */
	EventQueue& PopEventQueue();
	void PushEventQueue(EventQueue& queue);
	EventQStore& CreateStore();

    private:
	EventQStore(EventQStore&);

	wxList m_store;
    };
};
