///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swWxGuiTestApp.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swWxGuiTestApp.h"
#endif

#include "swWxGuiTestApp.h"

#include "swInitWxGuiTestSetUp.h"
#include "swWxGuiTestHelper.h"
#include "swCREventFilterInterface.h"

IMPLEMENT_APP_NO_MAIN(swTst::WxGuiTestApp)

BEGIN_EVENT_TABLE(swTst::WxGuiTestApp, sw::PseudoApp)
    EVT_IDLE(swTst::WxGuiTestApp::OnIdle)
END_EVENT_TABLE()

namespace swTst {


WxGuiTestApp::WxGuiTestApp (sw::App *appUnderTest)
{
    m_testRunnerProxy = NULL;
    m_appUnderTest = appUnderTest;
    m_eventFilter = NULL;
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

    PseudoApp::OnIdle (event);

    if (WxGuiTestHelper::GetUseExitMainLoopOnIdleFlag () &&
            WxGuiTestHelper::GetExitMainLoopOnIdleFlag ()) {
    
        wxTheApp->ExitMainLoop ();
    }

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

        return PseudoApp::OnInit ();
    }
}

int WxGuiTestApp::OnExit ()
{
    if (m_appUnderTest != NULL) {

        return m_appUnderTest->OnExit ();

    } else {

        return PseudoApp::OnExit ();
    }
}

} // End namespace swTst

