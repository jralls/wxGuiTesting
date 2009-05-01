///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/WxGuiTestApp.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2009
// Modifications Copyright: (c) 2009 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef WXGUITESTAPP_H
#define WXGUITESTAPP_H

#include <wxGuiTest/Common.h>
#include <wx/app.h>
#include <wx/event.h>
#include <wxGuiTest/EventQueue.h>


namespace wxTst {

class InitWxGuiTestSetUp;
class CREventFilterInterface;

/*! \class WxGuiTestApp
    \brief Control & do running of wxWidgets GUI CppUnit tests.

    wxWidgets GUI initialisation requires a real wxApp based application.

    Controlling the code flow in/of the wxWidgets GUI CppUnit tests requires
    overridding OnRun() and OnIdle(). The latter one serves the purpose of
    exiting the main loop which can be equated to flushing the event queue.

    This class works closely together with WxGuiTestHelper which provides
    some convenience or helper methods to (a) configure the behaviour of this
    class (e.g. showing modal dialogs non-modal), and (b) facilitate the usage
    of some common features (e.g. flushing the event queue, or making the test
    temporary interactive for manual visual checks during GUI test
    implementation).

    For the purpose of testing whole applications (denoted applications under
    test = AUT) at least wxApp's OnInit() and OnExit() methods must be
    forwarded or delegated to it.

    TODO:
      - Allow configuration of wxApp::m_exitOnFrameDelete flag which can
        influence if the application is shut down when the last of its top
        level windows is closed.
*/
class WxGuiTestApp : public wxApp
{
    DECLARE_EVENT_TABLE()

public:
    /*! \fn WxGuiTestApp (wxApp *app = NULL)
        \brief Constructor

        \param app actual application under test (AUT)
    */
    WxGuiTestApp (wxApp* app = NULL);


    /*! \fn virtual ~WxGuiTestApp ()
        \brief Destructor
    */
    virtual ~WxGuiTestApp ();


    /*! \fn static App * GetInstance ()
        \brief Get single instance of application (Singleton pattern).

      	\return application instance
    */
    static wxApp* GetInstance ();


    /*! \fn static void SetInstance (App *app)
      	\brief [TEST] Set single instance of application (Singleton pattern).

      	Only required for testing!

      	\param app application instance to set
    */
    static void SetInstance (wxApp* app);


    /*! \fn static void Nullify ()
      	\brief [TEST] Pseudo destruction of application.

      	Only required for testing!

	In fact only sets ms_instance to NULL.
    */
    static void Nullify ();


    /*! \fn virtual int FilterEvent (wxEvent& event)
        \brief Each event is processed for C&R using the set event filter.

        \param event event to process
        \return always returns -1 to resume normal processing
    */
    virtual int FilterEvent (wxEvent& event);


    /*! \fn virtual void SetEventFilter (CREventFilterInterface *eventFilter)
        \brief Set concrete event filter used in FilterEvent() method for
        processing all events in capturing mode.

        Set event filter is deleted when set again, as well as in destructor.
        Using a NULL pointer means "switching off" the event filtering.

        \param eventFilter event filter for processing events
    */
    virtual void SetEventFilter (CREventFilterInterface *eventFilter);


    /*! \fn virtual void OnAssert (const wxChar *file, int line, const wxChar *cond, const wxChar *msg)
        \brief Is called when an assert failure in debug mode occurs.

        As a result the current running test case has failed as well, but
        the default behaviour just pops-up a warning dialog.

        \param file the name of the source file where the assert occured
        \param line the line number in this file where the assert occured
        \param cond the condition of the failed assert in string form
        \param msg the assertion message if specified, or NULL
    */
    virtual void OnAssert (const wxChar *file, int line, const wxChar *cond,
            const wxChar *msg);

    /*! \fn virtual int OnRun ()
        \brief Run the wxWidgets GUI CppUnit tests.

        \return return value of final main loop run (intending to process all pending events)
    */
    virtual int OnRun ();


    /*! \fn virtual void SetTestRunnerProxy (InitWxGuiTestSetUp &testRunnerProxy)
        \brief Set the "proxy" instance which acutally runs the CppUnit tests.

        \param testRunnerProxy "proxy" for actually running the tests
    */
    virtual void SetTestRunnerProxy (InitWxGuiTestSetUp &testRunnerProxy);

    //-------------------------------------------------------------------------
    // Methods of wxApp overridden for delegation to AUT; because we correct
    // the single App instance, App's methods don't have to be delegated:
    //-------------------------------------------------------------------------

    /*! \fn virtual bool OnInit ()
        \brief Initialise application.

        \return true, if initialisation successful and application should be continued
    */
    virtual bool OnInit ();


    /*! \fn virtual int OnExit ()
        \brief Clean up at exit of application.

        \return exit code
    */
    virtual int OnExit ();

/** 
 * \fn virtual int MainLoop()
 * \brief Override MainLoop() to be a manually executed event loop. This
 * replaces the somewhat fragile OnIdle (for replay) approaches.
 * 
 * @return  Event Loop's return code
 */	
	virtual int MainLoop();

/** 
 * \fn virtual int MainLoop()
 * \brief Override ExitMainLoop()
 */
	virtual void ExitMainLoop();

/** \fn bool Yield (onlyIfNeeded)
 *  \brief Override Yield so that it doesn't have us go out and get
 *  platform events
 *  
 * \param onlyIfNeeded true if you want a recursive call to return
 * false instead of asserting
 *  
 *  \return true unless called recursively with onlyIfNeeded == true
 */
	virtual bool Yield(bool onlyIfNeeded);

#if defined(__WXMC_CARBON__) && !wxCHECK_VERSION(2, 9, 0)
/** \fn void MacDoOneEvent()
    \brief Hide wxCarbon's MacDoOneEvent so that we can control modal dialogs.
*/
    void MacDoOneEvent() { m_eventLoop->Dispatch();}
#endif

/// \fn virtual EventQueue* newEventQueue()
/// \brief Create a new EventQueue in the event store
///
/// Create a new event queue to post to. Call this from your test
/// program every time an event loop is created or destroyed -- for
/// example, if a test case will result in a modal dialog, call
/// newEventQueue() at the beginning of the test case and call
/// queueEvent() to place each synthetic or recorded event on the
/// queue. When the event which will launch the modal dialog has been
/// placed on the queue, call newEventQueue again and call
/// queueEvent() for each event that the dialog will need to
/// process. You will likely want the event loop to finish at this
/// point so that you can check the contents of the dialog box before
/// it calls EndModal() and the function which called it destroys
/// it. You can then either create a new queue and queue the final
/// event to it or just post the event, then call MainLoop().
///
    virtual void newEventQueue();

/** \fn void queueEvent (event)
 *  \brief Queues a wxEvent onto the current active event queue.
 *  
 *  Because it calls event->Clone(), it doesn't take ownership of the
 *  pointer, so the calling code can delete it (and EventStore doesn't
 *  have to worry about a pointer getting invalidated.
 *  \param event The event to queue
 */

    virtual void queueEvent(wxEvent& event);

/** \fn void nextEventQueue ()
 *  \brief make the 
 *  
 */
    virtual void nextEventQueue();

/** \fn bool postNextEvent ()
 *  \brief Pops the next event from the current front queue and posts
 *  it to its handler.
 *  \return true if there is another event in the current queue.
 */
    virtual bool postNextEvent();

/** \fn bool pending ()
 *  \brief Test the current queue and all wxEventHandlers the
 *  existence of pending events.
 *  
 *  \return true if there are pending events.
 */
    virtual bool pending();


private:
    InitWxGuiTestSetUp* m_testRunnerProxy;
    wxApp* m_appUnderTest;
    CREventFilterInterface* m_eventFilter;
    static wxApp* ms_instance;
//This flag set to true when OnIdle is in control of the current event loop.
    bool m_idleCtrlFlag ;
    wxEventLoop* m_eventLoop;
    EventQStore* m_eventStore;

};

} // End namespace wxTst

DECLARE_APP(wxTst::WxGuiTestApp)

#endif // WXGUITESTAPP_H

