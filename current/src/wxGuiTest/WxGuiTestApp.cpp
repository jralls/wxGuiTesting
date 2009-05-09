///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/WxGuiTestApp.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2009
// Modifications Copyright: (c) 2009 John Ralls
// Licence:     wxWindows licence
////////////////////////////////////////////////////////////////////////////////

#include <wxGuiTest/WxGuiTestApp.h>
#include "InitWxGuiTestSetUp.h"
#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/CREventFilterInterface.h>
#include <wxGuiTest/TestEventLoop.h>


IMPLEMENT_APP_NO_MAIN(wxTst::WxGuiTestApp)

BEGIN_EVENT_TABLE(wxTst::WxGuiTestApp, wxApp)
    EVT_IDLE(wxTst::WxGuiTestApp::OnIdle)
END_EVENT_TABLE()

using namespace wxTst;

wxApp* WxGuiTestApp::ms_instance = NULL;

WxGuiTestApp::WxGuiTestApp (wxApp *appUnderTest) :
    m_testRunnerProxy(NULL),
    m_appUnderTest(appUnderTest),
    m_eventFilter(NULL),
    m_idleCtrlFlag(false),
    m_eventStore(new EventQStore)
{
    m_mainLoop = new wxTestEventLoop;
    wxASSERT_MSG(ms_instance == NULL, _T("WxGuiTestApp constructed twice"));
    ms_instance = this;
}


WxGuiTestApp::~WxGuiTestApp ()
{
    // m_testRunnerProxy is delete elsewhere
    // It is illegal to delete m_appUnderTest :-(
    if (m_eventFilter != NULL) {

        delete m_eventFilter;
        m_eventFilter = NULL;
    }
    if(m_mainLoop != NULL) {
	delete m_mainLoop;
	m_mainLoop = NULL;
    }
}

int
WxGuiTestApp::MainLoop ()
{
    wxLogTrace (_T("wxGuiTestCallTrace"), _T("WxGuiTestApp::MainLoop"));
    int retval;
//m_mainLoop is a special loop which processes the events pushed by wxPostEvent and returns. We use this loop to maintain control during test case execution.
    if (WxGuiTestHelper::GetInteractive ()) {
//wxApp::MainLoop runs the regular event loop, which we need during capture and interaction.
	::wxLogTrace (_T("wxGuiTestCallTrace"), 
		      _T("WxGuiTestApp::MainLoop: Running platform loop"));
	retval = m_mainLoop->Run();
	::wxLogTrace (_T("wxGuiTestCallTrace"), 
		      _T("WxGuiTestApp::MainLoop: Exiting platform loop"));
    }
    else {
//We only want to process events which are already on the various
//wxEventHandler queues -- which should be only the ones the test
//program put there!
	::wxLogTrace (_T("wxGuiTestCallTrace"), 
		      _T("WxGuiTestApp::MainLoop: Running test loop"));
	retval = m_eventLoop -> Run();
	::wxLogTrace (_T("wxGuiTestCallTrace"), 
		      _T("WxGuiTestApp::MainLoop: Exiting test loop"));
    }

    return retval;

}

void WxGuiTestApp::ExitMainLoop() {
    m_mainLoop->Exit();
}

wxEventLoop* WxGuiTestApp::SetMainLoop(wxEventLoop* newLoop) {
    wxCHECK_MSG(newLoop != NULL, NULL, 
		_T("WxGuiTestApp::SetMainLoop: Received NULL Pointer"));
    wxEventLoop* oldLoop = m_mainLoop;
    m_mainLoop = newLoop;
    return oldLoop;
}

const wxEventLoop* const WxGuiTestApp::GetMainLoop() const {
    return m_mainLoop;
}

bool WxGuiTestApp::Yield(bool WXUNUSED(onlyIfNeeded)) {
    return true;
}


wxApp *WxGuiTestApp::GetInstance ()
{
	return ms_instance;
}


void WxGuiTestApp::SetInstance (wxApp *app)
{
    wxASSERT (app != NULL);

    WxGuiTestApp::Nullify ();
    ms_instance = app;
}


void WxGuiTestApp::Nullify ()
{
    if (ms_instance != NULL) {

        // This causes an exception:
        //delete ms_instance;
        ms_instance = NULL;
    }
}

int WxGuiTestApp::FilterEvent (wxEvent& event)
{
    if (m_eventFilter != NULL) {

        m_eventFilter->FilterEvent (event);
    }

    return -1;
}


void WxGuiTestApp::SetEventFilter (CREventFilterInterface *eventFilter)
{
    if ((m_eventFilter != NULL) && (eventFilter != m_eventFilter)) {

        delete m_eventFilter;
    }
    m_eventFilter = eventFilter;
}


void WxGuiTestApp::OnAssert (const wxChar *file, int line,
        const wxChar *cond, const wxChar *msg)
{
    if (WxGuiTestHelper::GetPopupWarningForFailingAssert ()) {

#ifdef __WXDEBUG__
        wxApp::OnAssert (file, line, cond, msg);
#endif // __WXDEBUG__

    } else {

        wxString failMsg = wxString::Format (_T("Assert \"%s\" failed"), cond);
        if (msg != NULL) {

            failMsg << _T(": ") << msg;
        }

        WxGuiTestHelper::AddTestFailure (file, line,
                _T("wxWidgets assert failure"), failMsg);
        //WxGuiTestHelper::SetCheckForProvokedWarnings (false);
        wxTheApp->ExitMainLoop ();
    }
}

int WxGuiTestApp::OnRun ()
{
    ::wxLogTrace (_T("wxGuiTestCallTrace"), _T("int WxGuiTestApp::OnRun ()"));

    // TODO: Allow configuration of m_exitOnFrameDelete flag by means of
    //   WxGuiTestHelper?

    // see the comment in ctor: if the initial value hasn't been changed, use
    // the default Yes from now on
    if (m_exitOnFrameDelete == Later) {

        m_exitOnFrameDelete = Yes;
    }
    //else: it has been changed, assume the user knows what he is doing

    wxASSERT (m_testRunnerProxy);
    m_testRunnerProxy->RunAsDecorator ();

    // For a clean exit all windows must be closed; otherwise their "proxy"
    // classes can not be de-registered. At least the existence of the
    // applications top window can be checked & closed by default:

    // TODO: sometimes a clean exit seems to be not possible :-(
    //return 0;

    if (wxTheApp->GetTopWindow ()) {

        wxTheApp->GetTopWindow ()->Close ();
    }
    return 0;
}


void WxGuiTestApp::SetTestRunnerProxy (InitWxGuiTestSetUp &testRunnerProxy)
{
    m_testRunnerProxy = &testRunnerProxy;
}


//-------------------------------------------------------------------------
// Methods overridden for delegation to AUT:
//-------------------------------------------------------------------------

bool WxGuiTestApp::OnInit ()
{
    if (m_appUnderTest != NULL) {

        // Somehow in release mode argc was initialised to an arbitrary value
        // making AUT->OnInit() thinking there is a document specified on the
        // command line to load up:
        m_appUnderTest->argc = 0;
        return m_appUnderTest->OnInit ();

    } else {

        return wxApp::OnInit ();
    }
}

int WxGuiTestApp::OnExit ()
{
    if (m_appUnderTest != NULL) {

        return m_appUnderTest->OnExit ();

    } else {

        return wxApp::OnExit ();
    }
}

////////////////////////////////////////////////////////////////////////////
// Functions for managing queued events:
///////////////////////////////////////////////////////////////////////////

void
WxGuiTestApp::newEventQueue() {
    m_eventStore->push_back(new EventQueue);
}

void 
WxGuiTestApp::queueEvent(wxEvent& event) {
    if (m_eventStore->isEmpty()) newEventQueue();
    EventQueue* const q = m_eventStore->get_back();
    q->push_back(event.Clone());
}

void
WxGuiTestApp::nextEventQueue() {
    EventQueue* q = m_eventStore->pop_front();
    if (q == NULL) return;
    delete q;
    q = NULL;
}

bool 
WxGuiTestApp::postNextEvent() {
    EventQueue* q = m_eventStore->get_front();
    if (q == NULL) 
	return false;
    wxEvent* e = q->pop_front();
    if (e == NULL) {
	q = m_eventStore->pop_front();
	delete q;
	return false;
    }
    wxEvtHandler* handler = dynamic_cast<wxEvtHandler*>(e->GetEventObject());
    if (!handler) {
	delete e; 
	return false;
    }
    handler->AddPendingEvent(*e);
    delete e;
    return true;
}

bool
WxGuiTestApp::pending() { 
    return (m_eventStore->get_front() && 
	     !(m_eventStore->get_front()->isEmpty()));
}

void
WxGuiTestApp::discardCurrentQueue() {
    EventQueue* q = m_eventStore->pop_front();
    if (q == NULL)
	delete q;
}
