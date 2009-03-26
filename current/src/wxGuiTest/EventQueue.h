////////////////////////////////////////////////////////////////////////
/// \file   	wxGuiTest/EventQueue.h
/// \author 	John Ralls <john@ceridwen.fremont.ca.us>
/// Created: 	24 Mar 2009
/// Copyright 	John Ralls 2009
/// License: 	wxWindows License
////////////////////////////////////////////////////////////////////////

#ifdef __EVENT_QUEUE_H__
#define  __EVENT_QUEUE_H__

namespace wxTst {
    template <T> struct Item {
	Item(T* item) : m_item(item), m_next(NULL) {};
	~Item() {}
	T* m_item;
	Item* m_next;
    private:
	Item(Item);
	Item operator=(Item);
    };

    template <T> class Queue {
    public:
	Queue() {}
	~Queue() {
	    do {
		T* ptr = pop_front();
		if (ptr)
		    delete ptr;
	    } until (ptr == NULL);
	}

	inline void push_back(T* ptr) {
	    Item* item = new Item(ptr);
	    if (m_back)
		m_back->m_next = item;
	    m_back = item;
	    if (m_front == NULL) 
		m_front = m_back;
	}

	inline T* pop_front() {
	    Item* item = m_front;
	    if (item) {
		m_front = item->m_next;
		T* ptr = item->m_item;
		delete item;
		if (m_front = NULL)
		    m_back = NULL;
		return ptr;
	    }
	    return NULL;
	}
    private:
	Item* m_front;
	Item* m_back;
    };

    class EventQueue {
    public:
	EventQueue() m_q(new Queue<wxEvent>) {}
	~EventQueue() { delete m_q; }
	bool isEmpty { return (!(m_q && m_q->m_front)); }

    private:
	Queue<wxEvent> m_q;
    };

    typedef Queue<EventQueue> EventQStore;

}; //wxTst
#endif // __EVENT_QUEUE_H__

