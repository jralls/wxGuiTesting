///////////////////////////////////////////////////////////////////////////////
// Name:        include/wxGuiTest/TestEventLooop.h
// Author:      John Ralls
// Created:     2009
// Copyright:   (c) 2009 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////
#ifndef __TEST_EVENT_LOOP_H__
#define __TEST_EVENT_LOOP_H__

#include <wx/evtloop.h>

namespace wxTst {
/*! \class wxTestEventLoop
    \brief Provide a custom event loop for testing.

In order to test event handling, we need to run an event loop to post
events to and to dispatch the events from. WxWidgets implements this
already, of course, but the test program loses control if we let that
one run. WxWidgets generally wraps the underlying platform event loop,
and we don't need to do that, because we're only testing wxWidgets
events, not platform events. Unfortunately, wxWidgets uses native
controls which run their own event loops on some platforms (message
dialogs are one example, and popup menus are another). There's no way
for wxGuiTesting to interrupt those loops, so the actual elements
aren't testable. Program around it using a test double or mock object
of some sort.
*/
//NB: This works fine on wxGTK, which calls wxTheApp->MainLoop, and
//wxMac for trunk, which just sets a modal state on the window and
//then keeps running the existing loop (via Dispatch(), so we'll have
//to override it) until it gets an EndModal(). wxMac 2.8, though calls
//wxTheApp->MacDoOneEvent (which is OK, we can hide it with our
//own). wxMSW uses the wxModalEventLoop construct, which will have to
//be patched in wx.
    class wxTestEventLoop : public wxEventLoop {
    public:
	wxTestEventLoop() : m_exitCode(0), m_loopRunning(false) { }
/** 
 * \fn int Run()
 * \brief Run the loop until there are no more events from the store.
 * 
 * \return int, the exit code from the loop. Defaults to 0.
 */
	int Run();
/** 
 * \fn void Exit(int exitCode);
 * \brief Exit a running loop, causing it to return exitCode
 * \param exitCode The intended return value from Run().
 */
	void Exit(int exitCode);
/** \fn bool Pending ()
 *  \brief Tests the event store to see if there are available events
 *  \return True if there are events waiting
 */
	bool Pending() const;
/** \fn bool Dispatch ()
 *  \brief Process one event
 *  Retrieves the next event from the current store, posts it to its
 *  wxEvtHandler, and calls ProcessPendingEvents().
 *  
 *  \return true if there is another event to process
 */
	bool Dispatch();

    private:
	int m_exitCode;
	bool m_loopRunning;
	inline int doExitCode() {
	    int tmp = m_exitcode;
	    m_exitCode = 0;
	    return tmp;
	};
    };

}; //namespace wxTst

#endif //__TEST_EVENT_LOOP_H__
