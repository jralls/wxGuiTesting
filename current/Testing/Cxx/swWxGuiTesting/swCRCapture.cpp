///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRCapture.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRCapture.h"
#endif

#include "swCRCapture.h"

#include <iostream>

#include "wx/xrc/xmlres.h"

#include "swWxGuiTestHelper.h"
#include "swCREventCaptureManager.h"

// Capture panel XRC file is compiled into a c++ file with embedded resources:
extern void InitCapturePanelXRC ();

namespace swTst {


CRCapture::CRCapture ()
{
    wxXmlResource::Get()->InitAllHandlers();

    m_dialog = NULL;
    m_control = NULL;
    m_logTextCtrl = NULL;
}


CRCapture::~CRCapture ()
{
    if (m_dialog != NULL) {

        m_dialog->PopEventHandler (true);
        m_dialog->Destroy ();
    }
}


void CRCapture::Capture (const char *file, int line)
{
    CRCppEmitter::GetInstance ()->SetTestCaseFileContext (file, line);

    this->Show ();
}


void CRCapture::Log (const wxString &text)
{
    m_logTextCtrl->AppendText (text);
}


void CRCapture::Show ()
{
    // Store old main loop flag and set new one:
    bool oldUseExitMainLoopOnIdle = WxGuiTestHelper::GetUseExitMainLoopOnIdleFlag ();
    WxGuiTestHelper::SetUseExitMainLoopOnIdleFlag (false);
    // Likewise, provide normal (= release, in opposition to testing mode)
    // behaviour:
    bool oldShowModalDialogsNonModal = WxGuiTestHelper::GetShowModalDialogsNonModalFlag ();
    WxGuiTestHelper::SetShowModalDialogsNonModalFlag (false);
    bool oldShowPopupMenus = WxGuiTestHelper::GetShowPopupMenusFlag ();
    WxGuiTestHelper::SetShowPopupMenusFlag (true);

    if (m_dialog == NULL) {

        this->CreateDialog ();
        this->CreateEvtHandler ();
        m_dialog->PushEventHandler (m_control);

        CREventCaptureManager::GetInstance ()->IgnoreWindow (m_dialog);
        CREventCaptureManager::GetInstance ()->SetLogger (this);
    }
    m_control->SetButtonStates ();
    m_dialog->Show ();

    // Main loop will be exited in CRCaptureControl::OnExit()
    wxTheApp->MainLoop ();

    // Restore main loop flag:
    WxGuiTestHelper::SetUseExitMainLoopOnIdleFlag (oldUseExitMainLoopOnIdle);
    // Likewise, restore other flags:
    WxGuiTestHelper::SetShowModalDialogsNonModalFlag (oldShowModalDialogsNonModal);
    WxGuiTestHelper::SetShowPopupMenusFlag (oldShowPopupMenus);
}


void CRCapture::CreateEvtHandler ()
{
    m_control = new CRCaptureControl (m_dialog);
}


void CRCapture::CreateDialog ()
{
    m_dialog = new wxDialog (NULL, -1, _("Capture Dialog"), wxDefaultPosition,
            wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);

    wxBoxSizer *topsizer = new wxBoxSizer (wxVERTICAL);

    wxPanel *panel = this->LoadPanel ();
    wxASSERT (panel != NULL);
    topsizer->Add (panel, 1, wxGROW | wxADJUST_MINSIZE, 0);

    m_logTextCtrl = XRCCTRL (*panel, "LoggingTextCtrl", wxTextCtrl);
    wxASSERT (m_logTextCtrl != NULL);

    m_dialog->SetSizer (topsizer);
    topsizer->SetSizeHints (m_dialog);
	m_dialog->Layout ();
}


wxPanel * CRCapture::LoadPanel ()
{
    InitCapturePanelXRC ();
    return wxXmlResource::Get ()->LoadPanel (m_dialog, "CapturePanel");
}

} // End namespace swTst
