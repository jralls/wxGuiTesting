///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/TimedDialogEnder.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "TimedDialogEnder.h"
#endif

#include <wxGuiTest/TimedDialogEnder.h>

namespace wxTst {


IMPLEMENT_CLASS(TimedDialogEnder, wxEvtHandler)

BEGIN_EVENT_TABLE(TimedDialogEnder, wxEvtHandler)
    EVT_TIMER(-1, TimedDialogEnder::OnTimer)
END_EVENT_TABLE()


TimedDialogEnder::TimedDialogEnder (unsigned int milliseconds,
        const wxString &windowCaption, int returnCode)
{
    m_success = false;
    m_windowCaption = windowCaption;
    m_returnCode = returnCode;
    m_timerId = ::wxNewId ();
    m_timer = new wxTimer (this, m_timerId);
    m_timer->Start (milliseconds);
}


TimedDialogEnder::~TimedDialogEnder ()
{
    ::wxLogTrace (_T("TimedDialogEnder"), 
            _T("~TimedDialogEnder"));
    this->DestroyTimer ();
}


bool TimedDialogEnder::GetSuccess () const
{
    return m_success;
}


void TimedDialogEnder::DestroyTimer ()
{
    if (m_timer != NULL) {

        if (m_timer->IsRunning ()) {

            m_timer->Stop ();
        }
        delete m_timer;
        m_timer = NULL;
    }
}


void TimedDialogEnder::OnTimer (wxTimerEvent& event)
{
    ::wxLogTrace (_T("TimedDialogEnder"), _T("OnTimer"));

    if (event.GetId () == m_timerId) {

        // Hm, apparently the main thread is calling this event handling
        // function (this is standard?), even though the message box is
        // blocking the application??? Thus, ::wxMutexGuiEnter() and
        // ::wxMutexGuiLeave() functions must not be used in favour of:
        #if defined(__WXMSW__) || defined(__WXMAC__) || defined(__WXPM__)
            ::wxMutexGuiLeaveOrEnter ();
        #endif
        // Try using portable (standard wxWidgets) code - does not work even
        // when using wxMessageDialog and it's SetName() method which seems to
        // be the compared window identifier instead of the window caption?
        /*
        wxWindow* parent = NULL;
        wxWindow* dlgWdw = wxWindow::FindWindowByName (m_windowCaption, parent);
        if (dlgWdw) {

            wxDialog *dlg = wxDynamicCast (dlgWdw, wxDialog);
            if (dlg) {

                dlg->EndModal (m_returnCode);
                ::wxLogTrace (_T("TimedDialogEnder"), _T("Window killed"));
                this->DestroyTimer ();
            }
        }*/

        // So we currently have to use M$ specific code :-(((
        #ifndef WIN32
            wxFAIL_MSG (_T("Only supported under M$ Windows"));
        #else
            HWND wdw = FindWindow (NULL, m_windowCaption);
            if (wdw) {

                // Killing the message box using brute force is detected
                // because of an irregular return code of the message box:
                //if (DestroyWindow (wdw)) {
                // Interestingly the message box can be killed "softly" or as
                // not irregular detected:
                if (EndDialog (wdw, m_returnCode)) {

                    ::wxLogTrace (_T("TimedDialogEnder"), _T("Window killed"));
                    this->DestroyTimer ();
                    m_success = true;
                }
            }
        #endif

        #if defined(__WXMSW__) || defined(__WXMAC__) || defined(__WXPM__)
            ::wxMutexGuiLeaveOrEnter ();
        #endif
    }
}

} // End namespace wxTst

