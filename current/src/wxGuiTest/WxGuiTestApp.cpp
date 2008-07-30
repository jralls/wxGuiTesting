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

#include <wx/evtloop.h>
#include "InitWxGuiTestSetUp.h"
#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/CREventFilterInterface.h>
#include <stdexcept>
#ifdef __WXGTK__
#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <gdk/gdkkeysyms.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#endif //__WXGTK__

IMPLEMENT_APP_NO_MAIN(wxTst::WxGuiTestApp)

BEGIN_EVENT_TABLE(wxTst::WxGuiTestApp, wxApp)
    EVT_IDLE(wxTst::WxGuiTestApp::OnIdle)
END_EVENT_TABLE()

using namespace wxTst;

wxApp* WxGuiTestApp::ms_instance = NULL;

#ifdef __WXGTK__

namespace wxTst {



class wxTestEventLoop : public wxEventLoop {
public:
	wxTestEventLoop() : m_loop(NULL),
		m_exitFlag(false), m_loopRunning(false) { }
	~wxTestEventLoop() {
//		g_main_loop_unref(m_loop);
		m_loop = NULL;
	}

	int Run();
	void Exit(int exitCode);
	static void inactivateIdleHandler() { s_activeIdleHandler = 0; }

private:
	GMainLoop *m_loop;
	bool m_exitFlag;
	bool m_loopRunning;
	static gint s_activeIdleHandler;
	static unsigned int s_depth;

};

}; //namespace wxTst

unsigned int wxTestEventLoop::s_depth = 0;
gint wxTestEventLoop::s_activeIdleHandler = 0;


struct loopData {
	unsigned int m_lvl;
	wxString m_msg;

	loopData(int level, wxString message) : m_lvl(level), m_msg(message) {}
};



static wxString innerMsg(_T("From inner invocation "));


extern "C" {

// static gboolean
// handleIdle(gpointer data) {
// 	loopData* loop = (loopData*)data;
// 	::wxLogTrace (_T("wxGuiTestCallTrace"), 
// 				  _T("handleIdle: %s depth %d"), loop->m_msg.c_str(), 
// 				  g_main_depth());
// 	unsigned int events = 0;
// 	while (WxGuiTestHelper::DoNextEvent()) {
// 		::wxLogTrace (_T("wxGuiTestCallTrace"), 
// 					  _T("handleIdle: pushing event"));
// 		wxTheApp->ProcessPendingEvents();
// 		while(g_main_context_pending(NULL))
// 			events += (g_main_context_iteration(NULL, FALSE) ? 1 : 0);

// 	}
// 	wxLogTrace(_T("wxGuiTestCallTrace"), 
// 			   _T("handleIdle: finished, processed %d events"), events);
//  	wxTheApp->ExitMainLoop();
// 	return TRUE;

// }

// static void
// handlerRemoved(gpointer data) {
// 	loopData* loop = (loopData*)data;
// 	wxTestEventLoop::inactivateIdleHandler();
// }

	static void 
	map_handler(GdkEvent* event, gpointer) {
		GtkWidget* widget;
		g_return_if_fail(event != NULL);
		widget = gtk_get_event_widget(event);
		if (widget == NULL) {
			if (event->type == GDK_MAP || event->type == GDK_UNMAP)
				wxLogDebug(_T("wxGuiTestApp::map_handler: Map/Unmap event with no widget"));
			gtk_main_do_event(event);
			return;
		}
		WxGuiTestApp* app = dynamic_cast<WxGuiTestApp*>(wxTheApp);
		g_return_if_fail(app != NULL);
		NativeWindowRegistryEntry entry(widget);
		switch(event->type) {
		case GDK_MAP:
			app->NewNativeWin(entry);
			break;
		case GDK_UNMAP:
			app->InactivateNativeWin(entry);
			break;
		default:
			break;
		}
		gtk_main_do_event(event);
	}

	static void 
	map_handler_remove_notify(gpointer) {
		wxLogDebug(_T("Map Handler Superceded"));
	}

}//extern "C"


int
wxTestEventLoop::Run() {
	++s_depth;
	    ::wxLogTrace (_T("wxGuiTestCallTrace"), 
					  _T("wxTestEventLoop::Run depth %d begin"), s_depth);
	if (s_activeIdleHandler)
		g_source_remove(s_activeIdleHandler);


 	m_loopRunning = true;
	m_exitFlag = false;
	wxEventLoop* oldActive = wxEventLoop::GetActive();
	wxEventLoop::SetActive(this);

	m_loop = g_main_loop_new(NULL, TRUE);
	GMainContext* context = g_main_context_default();
	unsigned int events = 0, loop_count = 0;
	gint maxPri;
	wxTheApp->ProcessPendingEvents();
	while (!m_exitFlag && g_main_context_pending(context)) {
		wxTheApp->SuspendIdleCallback();
		g_main_context_iteration(context, TRUE);
	}

	gdk_flush();
	g_main_loop_unref(m_loop);
	m_loop = NULL;
	wxLogTrace(_T("wxGuiTestCallTrace"), 
			   _T("wxTestEventLoop::Run depth %d completed"), s_depth--);

	wxEventLoop::SetActive(oldActive);
	m_loopRunning = false;
	return 0;

} 

void
wxTestEventLoop::Exit(int exitCode) {
	::wxLogTrace (_T("wxGuiTestCallTrace"), 
				  _T("wxTestEventLoop::Exit Code %d level %d"), exitCode,
				  g_main_depth());

	wxASSERT(m_loop != NULL);
	m_exitFlag = true;
}

NativeWindowRegistryEntry::~NativeWindowRegistryEntry()  { 
//	g_object_unref(m_window); 
}

bool 
wxTst::operator==(const NativeWindowRegistryEntry& left, 
				const NativeWindowRegistryEntry& right) {
	return left.m_window == right.m_window;
}
bool 
wxTst::operator!=(const NativeWindowRegistryEntry& left, 
				const NativeWindowRegistryEntry& right) {
	return left.m_window != right.m_window;
}


#endif //__WXGTK__

WxGuiTestApp::WxGuiTestApp (wxApp *appUnderTest) :
    m_testRunnerProxy(NULL),
    m_appUnderTest(appUnderTest),
    m_eventFilter(NULL),
	m_idleCtrlFlag(false),
	m_mapHandlerFlag(false)
{
    wxASSERT (ms_instance == NULL);
    ms_instance = this;
	m_mainLoop = new wxTestEventLoop;

}


WxGuiTestApp::~WxGuiTestApp ()
{
    // m_testRunnerProxy is delete elsewhere
    // It is illegal to delete m_appUnderTest :-(
    if (m_eventFilter != NULL) {

        delete m_eventFilter;
        m_eventFilter = NULL;
    }
	wxEventLoop::SetActive(NULL);
}

void
WxGuiTestApp::SetMapHandler() {
	if (!m_mapHandlerFlag) {
#ifdef __WXGTK__
		gdk_event_handler_set(map_handler, NULL, map_handler_remove_notify);
#endif
		m_mapHandlerFlag = true;
	}
}

int
WxGuiTestApp::MainLoop ()
{
	wxLogTrace (_T("wxGuiTestCallTrace"), _T("WxGuiTestApp::MainLoop"));
	SetMapHandler();
	int retval;
//m_mainLoop is a special loop which processes the events pushed by wxPostEvent and returns. We use this loop to maintain control during test case execution.
    if (WxGuiTestHelper::GetUseExitMainLoopOnIdleFlag () &&
		WxGuiTestHelper::GetExitMainLoopOnIdleFlag ()) {
		retval = m_mainLoop->Run();
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

void
WxGuiTestApp::ExitMainLoop () {
	WxGuiTestHelper::SetExitMainLoopOnIdleFlag(false);
	wxApp::ExitMainLoop();
}

unsigned int
WxGuiTestApp::NewNativeWin(NativeWindowRegistryEntry& win) {
	try {
		GetNativeWinIndex(win);
	}
	catch(std::range_error& e) {
		m_winReg.push_back(win);
		return m_winReg.size();
	}
}

void
WxGuiTestApp::InactivateNativeWin(NativeWindowRegistryEntry& win) {
	NativeWindowRegistry::iterator pos = 
		std::find(m_winReg.begin(), m_winReg.end(), win);
	if (pos != m_winReg.end())
		pos->m_isActive = false;
}

NativeWindowRegistryEntry&
WxGuiTestApp::GetNativeWin(unsigned int index) {
	return m_winReg.at(index);
}

unsigned int
WxGuiTestApp::GetNativeWinIndex(NativeWindowRegistryEntry& win) {
	unsigned int i;
	unsigned int size = m_winReg.size();
	for (i = 0; i < size && win != m_winReg[i]; i++);
	if (i == size) 
		throw std::range_error(std::string("Window not found!"));
	return i;
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

