///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/GuiTestTempInteractiveControl.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "GuiTestTempInteractiveControl.h"
#endif

#include "GuiTestTempInteractiveControl.h"

#include <wxGuiTest/GuiTestHelper.h>

BEGIN_EVENT_TABLE(wxTst::WxGuiTestTempInteractiveControl, wxEvtHandler)
    EVT_BUTTON( -1, WxGuiTestTempInteractiveControl::OnOK )
    EVT_CLOSE ( WxGuiTestTempInteractiveControl::OnClose )
END_EVENT_TABLE()

namespace wxTst {


WxGuiTestTempInteractiveControl::WxGuiTestTempInteractiveControl (
        wxDialog *dialog)
{
    m_dialog = dialog;
}


WxGuiTestTempInteractiveControl::~WxGuiTestTempInteractiveControl ()
{
    // Nothing to do; m_dialog is deleted elsewhere
}


void WxGuiTestTempInteractiveControl::OnOK (wxCommandEvent &event)
{
    Finish ();
}


void WxGuiTestTempInteractiveControl::OnClose (wxCloseEvent &event)
{
    Finish ();
}


void WxGuiTestTempInteractiveControl::Finish ()
{
    m_dialog->Hide ();
    wxTheApp->ExitMainLoop ();
}

} // End namespace wxTst
