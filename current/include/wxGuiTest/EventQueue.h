////////////////////////////////////////////////////////////////////////
/// \file   	wxGuiTest/EventQueue.h
/// \author 	John Ralls <john@ceridwen.fremont.ca.us>
/// Created: 	24 Mar 2009
/// Copyright 	John Ralls 2009
/// License: 	wxWindows License
////////////////////////////////////////////////////////////////////////

#ifndef __EVENT_QUEUE_H__
#define  __EVENT_QUEUE_H__
#include <wx/event.h>

namespace wxTst {
    template <typename T> struct Item {
	Item<T>(T* item) : m_item(item), m_next(NULL) {};
	~Item<T>() {}
	T* m_item;
	Item* m_next;
    private:
	Item<T>(const Item<T>&);
	Item<T> operator=(Item<T>);
    };

    template <typename T> class Queue {
    public:
	Queue() : m_front(NULL), m_back(NULL) {}
	~Queue() {
	    T* ptr;
	    do {
		ptr = pop_front();
		if (ptr)
		    delete ptr;
	    } while (ptr != NULL);
	}
/** \fn void push_back (ptr)
 *  \brief Create a new Item<T> on the heap and add it to the back of the Queue.
 *  
 * \param ptr The object-pointer of type T to add. 
 */

	inline void push_back(T* ptr) {
	    Item<T>* item = new Item<T>(ptr);
	    if (m_back)
		m_back->m_next = item;
	    m_back = item;
	    if (m_front == NULL) 
		m_front = m_back;
	}

/** \fn T* pop_front ()
 *  \brief Retrieve the Item from the front of the Queue, extract its
 *  pointer, and delete the Item.
 *  
 *  \return The pointer stored in Item.
 */
	inline T* const pop_front() {
	    Item<T>* item = m_front;
	    if (item) {
		m_front = item->m_next;
		T* ptr = item->m_item;
		delete item;
		if (m_front == NULL)
		    m_back = NULL;
		return ptr;
	    }
	    return NULL;
	}

/** \fn const T* get_front ()
 *  \brief Return the objectptr managed by the Item at the front of the Queue.
 *  This will be the place to retrieve events. Note that this doesn't
 *  change the state of the queue.
 *  
 *  \return Objectptr.
 */
	inline T* const get_front() { return m_front ? m_front->m_item : NULL; }

/** \fn const T* get_back ()
 *  \brief Return the objectptr managed by the Item at the back of the Queue.
 *  This will be the place to store events. Note that this doesn't
 *  change the state of the queue.
 *  
 *  \return Objectptr.
 */

	inline T* const get_back() { return m_back ? m_back->m_item : NULL; }

	inline bool isEmpty() { return (m_front == NULL); }

    private:
	Item<T>* m_front;
	Item<T>* m_back;
    };

    typedef Queue<wxEvent> EventQueue;
    typedef Queue<EventQueue> EventQStore;

}; //wxTst
#endif // __EVENT_QUEUE_H__

