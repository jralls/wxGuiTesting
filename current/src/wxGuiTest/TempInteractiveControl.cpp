///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/TempInteractiveControl.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "TempInteractiveControl.h"
#endif

#include "TempInteractiveControl.h"

#include <wxGuiTest/WxGuiTestHelper.h>

BEGIN_EVENT_TABLE(wxTst::TempInteractiveControl, wxEvtHandler)
    EVT_BUTTON( -1, TempInteractiveControl::OnOK )
    EVT_CLOSE ( TempInteractiveControl::OnClose )
END_EVENT_TABLE()

using namespace wxTst;


TempInteractiveControl::TempInteractiveControl (
        wxDialog *dialog)
{
    m_dialog = dialog;
}


TempInteractiveControl::~TempInteractiveControl ()
{
    // Nothing to do; m_dialog is deleted elsewhere
}


void TempInteractiveControl::OnOK (wxCommandEvent& WXUNUSED(event))
{
    Finish ();
}


void TempInteractiveControl::OnClose (wxCloseEvent& WXUNUSED(event))
{
    Finish ();
}


void TempInteractiveControl::Finish ()
{
    m_dialog->Hide ();
    wxTheApp->ExitMainLoop ();
}

