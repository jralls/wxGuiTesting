///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CRCaptureControl.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRCaptureControl.h"
#endif

#include <wxGuiTest/CRCaptureControl.h>

#include <wx/xrc/xmlres.h>

#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/CREventCaptureManager.h>
#include <wxGuiTest/CRCppEmitter.h>

BEGIN_EVENT_TABLE(wxTst::CRCaptureControl, wxEvtHandler)
    EVT_BUTTON( XRCID("StartButton"), CRCaptureControl::OnStart )
    EVT_BUTTON( XRCID("StopButton"), CRCaptureControl::OnStop )
    EVT_BUTTON( XRCID("CommentButton"), CRCaptureControl::OnAddComment )
    EVT_BUTTON( XRCID("ExitButton"), CRCaptureControl::OnOK )
    EVT_CLOSE ( CRCaptureControl::OnClose )
END_EVENT_TABLE()

namespace wxTst {


CRCaptureControl::CRCaptureControl (wxDialog *dialog)
{
    m_dialog = dialog;
}


CRCaptureControl::~CRCaptureControl ()
{
    // Nothing to do; m_dialog is deleted elsewhere
}


void CRCaptureControl::OnStart (wxCommandEvent &event)
{
    CREventCaptureManager::GetInstance ()->On ();
    this->SetButtonStates (false);
}


void CRCaptureControl::OnStop (wxCommandEvent &event)
{
    CREventCaptureManager::GetInstance ()->Off ();
    this->SetButtonStates (true);
}


void CRCaptureControl::OnAddComment (wxCommandEvent &event)
{
	CREventCaptureManager::GetInstance ()->EmitPendingEvent ();
	
    wxTextCtrl *commentTextCtrl = XRCCTRL (*m_dialog, "CommentTextCtrl",
            wxTextCtrl);
    wxASSERT (commentTextCtrl != NULL);

    if (!commentTextCtrl->GetValue ().IsEmpty ()) {

        CRCppEmitter::GetInstance ()->AddComment (commentTextCtrl->GetValue ());
    }
}


void CRCaptureControl::OnOK (wxCommandEvent &event)
{
    Finish ();
}


void CRCaptureControl::OnClose (wxCloseEvent &event)
{
    Finish ();
}


void CRCaptureControl::Finish ()
{
    CREventCaptureManager::GetInstance ()->Off ();

    m_dialog->Hide ();
    wxTheApp->ExitMainLoop ();
}


void CRCaptureControl::SetButtonStates (bool isInit) const
{
    wxButton *startBtn = XRCCTRL (*m_dialog, "StartButton", wxButton);
    wxASSERT (startBtn != NULL);
    startBtn->Enable (isInit);

    wxButton *stopBtn = XRCCTRL (*m_dialog, "StopButton", wxButton);
    wxASSERT (stopBtn != NULL);
    stopBtn->Enable (!isInit);
}

} // End namespace wxTst
