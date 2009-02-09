///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CRCapture.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2009
// Modifications Copyright: (c) 2009 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRCapture.h"
#endif

#include <wxGuiTest/CRCapture.h>

#include <iostream>

#include <wx/xrc/xmlres.h>

#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/CREventCaptureManager.h>

// Capture panel XRC file is compiled into a c++ file with embedded resources:
extern void InitCapturePanelXRC ();

namespace wxTst {


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
    wxString filestr(file, *wxConvCurrent);
    CRCppEmitter::GetInstance ()->SetTestCaseFileContext (filestr, line);

    this->Show ();
}


void CRCapture::Log (const wxString &text)
{
    m_logTextCtrl->AppendText (text);
}


void CRCapture::Show ()
{
    // Store old main loop flag and set new one:
    bool oldInteractive = WxGuiTestHelper::GetInteractive();
    WxGuiTestHelper::SetInteractive (true);
    // Likewise, provide normal (= release, in opposition to testing mode)
    // behaviour:
    bool oldShowModalDialogsNonModal = WxGuiTestHelper::GetShowModalDialogsNonModalFlag ();
    WxGuiTestHelper::SetShowModalDialogsNonModalFlag (false);
    bool oldShowPopupMenus = WxGuiTestHelper::GetShowPopupMenusFlag ();
    WxGuiTestHelper::SetShowPopupMenusFlag (true);

    if (m_dialog == NULL) {

        this->CreateDialog ();
        m_control = this->CreateEvtHandler ();
        m_dialog->PushEventHandler (m_control);

        CREventCaptureManager::GetInstance ()->IgnoreWindow (m_dialog);
        CREventCaptureManager::GetInstance ()->SetLogger (this);
    }
    m_control->SetButtonStates ();
    m_dialog->Show ();

    // Main loop will be exited in CRCaptureControl::OnExit()
    wxTheApp->MainLoop ();

    // Restore main loop flag:
    WxGuiTestHelper::SetInteractive(oldInteractive);
    // Likewise, restore other flags:
    WxGuiTestHelper::SetShowModalDialogsNonModalFlag (oldShowModalDialogsNonModal);
    WxGuiTestHelper::SetShowPopupMenusFlag (oldShowPopupMenus);
}


CRCaptureControl * CRCapture::CreateEvtHandler () const
{
    return new CRCaptureControl (m_dialog);
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
    return wxXmlResource::Get ()->LoadPanel (m_dialog, _T("CapturePanel"));
}

} // End namespace wxTst
