///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swWxGuiTestTempInteractive.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swWxGuiTestTempInteractive.h"
#endif

#include "swWxGuiTestTempInteractive.h"

#include "wx/dialog.h"

#include "swWxGuiTestHelper.h"
#include "swWxGuiTestTempInteractiveControl.h"

#include "swWxLogicErrorException.h"

namespace swTst {


WxGuiTestTempInteractive::WxGuiTestTempInteractive ()
{
    m_dialog = NULL;

    m_file = NULL;
    m_line = -1;
}


WxGuiTestTempInteractive::~WxGuiTestTempInteractive ()
{
    if (m_dialog != NULL) {

        m_dialog->PopEventHandler (true);
        m_dialog->Destroy ();
    }

    if (m_file != NULL) {

        delete [] m_file;
    }
}


void WxGuiTestTempInteractive::ShowCurrentGui ()
{
	if (WxGuiTestHelper::GetDisableTestInteractivity ()) {

		return;
	}

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
        m_dialog->PushEventHandler (new WxGuiTestTempInteractiveControl (
                m_dialog));
    }
    m_dialog->Show ();

    // Main loop will be exited in WxGuiTestTempInteractiveControl::OnOK()
    wxTheApp->MainLoop ();

    // Restore main loop flag:
    WxGuiTestHelper::SetUseExitMainLoopOnIdleFlag (oldUseExitMainLoopOnIdle);
    // Likewise, restore other flags:
    WxGuiTestHelper::SetShowModalDialogsNonModalFlag (oldShowModalDialogsNonModal);
    WxGuiTestHelper::SetShowPopupMenusFlag (oldShowPopupMenus);
}


void WxGuiTestTempInteractive::ShowCurrentGui (const char *file, int line)
{
    if (!file) {

        return;
    }
    if (strcmp (file, "") == 0) {

        throw sw::WxLogicErrorException ("WxGuiTestTempInteractive: Empty filename");
    }
    if (m_file) {
        
        delete [] m_file;
    }
    m_file = new char[strlen(file) + 1];
    strcpy (m_file, file);

    if (line < 0) {

        throw sw::WxLogicErrorException ("WxGuiTestTempInteractive: Invalid line number");
    }
    m_line = line;

    this->ShowCurrentGui ();
}


void WxGuiTestTempInteractive::CreateDialog ()
{
    m_dialog = new wxDialog (wxTheApp->GetTopWindow (), -1,
            _("wxGui CppUnit Testing Suspended"), wxDefaultPosition,
            wxDefaultSize, wxDEFAULT_DIALOG_STYLE);

    wxBoxSizer *sizer = new wxBoxSizer (wxVERTICAL);

    wxStaticText *text = new wxStaticText (m_dialog, -1,
            _("Temporary interactive test. -- Continue unit testing?"),
            wxDefaultPosition, wxDefaultSize, 0);
    sizer->Add (text, 0, wxALIGN_CENTER | wxALL, 10);

    if ((m_file) && (m_line > -1)) {

        wxStaticText *fileInfoText = new wxStaticText (m_dialog, -1,
                wxString::Format ("%s: %s\n%s: %d", _("File"), m_file,
                _("Line"), m_line), wxDefaultPosition, wxDefaultSize, 0);
        sizer->Add (fileInfoText, 0, wxALIGN_CENTER | wxALL, 10);
    }

    wxButton *okBtn = new wxButton (m_dialog, -1, _("OK"), wxDefaultPosition,
            wxDefaultSize, 0);
    sizer->Add (okBtn, 0, wxALIGN_CENTER | wxALL, 10);

    m_dialog->SetSizer (sizer);
    sizer->SetSizeHints (m_dialog);
	m_dialog->Layout ();
}

} // End namespace swTst

