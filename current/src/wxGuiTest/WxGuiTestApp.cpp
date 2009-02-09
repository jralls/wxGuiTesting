///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/WxGuiTestApp.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "WxGuiTestApp.h"
#endif

#include <wxGuiTest/WxGuiTestApp.h>

#include "InitWxGuiTestSetUp.h"
#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/CREventFilterInterface.h>


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
    m_idleCtrlFlag(false)
{

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

}

int
WxGuiTestApp::MainLoop ()
{
    wxLogTrace (_T("wxGuiTestCallTrace"), _T("WxGuiTestApp::MainLoop"));
    int retval;
//m_mainLoop is a special loop which processes the events pushed by wxPostEvent and returns. We use this loop to maintain control during test case execution.
    if (WxGuiTestHelper::GetUseExitMainLoopOnIdleFlag () &&
	WxGuiTestHelper::GetExitMainLoopOnIdleFlag ()) {
	::wxLogTrace (_T("wxGuiTestCallTrace"), 
		      _T("WxGuiTestApp::MainLoop: Running test loop"));
		retval = 0;
		ProcessPendingEvents();
	::wxLogTrace (_T("wxGuiTestCallTrace"), 
		      _T("WxGuiTestApp::MainLoop: Exiting test loop"));
    }
    else {
//wxApp::MainLoop runs the regular event loop, which we need during capture and interaction.
	::wxLogTrace (_T("wxGuiTestCallTrace"), 
		      _T("WxGuiTestApp::MainLoop: Running platform loop"));
	retval = wxApp::MainLoop();
	::wxLogTrace (_T("wxGuiTestCallTrace"), 
		      _T("WxGuiTestApp::MainLoop: Exiting platform loop"));
    }

    return retval;

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


void WxGuiTestApp::OnIdle (wxIdleEvent &event)
{
    // Called too often, maybe in combination with a boolean flag, temporarily
    // set to true => show OnIdle() call trace:
    ::wxLogTrace (_T("wxGuiTestCallTrace"), 
            _T("void WxGuiTestApp::OnIdle (wxIdleEvent &event)"));

    wxApp::OnIdle (event);

    if (WxGuiTestHelper::GetUseExitMainLoopOnIdleFlag () &&
            WxGuiTestHelper::GetExitMainLoopOnIdleFlag ()) {
    
	::wxLogTrace (_T("wxGuiTestCallTrace"), 
		      _T("void WxGuiTestApp::OnIdle wxIdleEvent &event)"));
        wxTheApp->ExitMainLoop ();
	wxApp::OnIdle (event);
	event.Skip();
    }
    else
	wxApp::OnIdle (event);


    // While it is said in the wxWidgets documentation that "instead of
    // explicitly calling the base class version [of an event handler] as you
    // would have done with C++ virtual functions, you should instead call
    // event.Skip()".
    // But in this case it is assumed that first doing the base class version
    // event handling (initiated by PseudoApp::OnIdle() call above), is
    // correcter, as the main loop is likely to be exited otherwise (either
    // without processing the events if the above call is not executed, or by
    // another in the best case unnecessary attempt to process events if both
    // statements are used:
    //event.Skip ();
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
    // Final processing of all pending events seems to be no more necessary (at least not for the
    // simple test cases that are part of this framework). Used to be:
    /*
    WxGuiTestHelper::SetUseExitMainLoopOnIdleFlag (false);
    return wxTheApp->MainLoop ();
    */
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

