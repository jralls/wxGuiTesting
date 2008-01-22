///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/GuiTestTempInteractive.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "GuiTestTempInteractive.h"
#endif

#include <wxGuiTest/GuiTestTempInteractive.h>

#include <wx/dialog.h>

#include <wxGuiTest/GuiTestHelper.h>
#include "GuiTestTempInteractiveControl.h"

using namespace wxTst;

void WxGuiTestTempInteractive::ShowCurrentGui (const wxString& file, int line)
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

    wxDialog* dialog = CreateDialog (file, line);
    WxGuiTestTempInteractiveControl* handler = 
	new WxGuiTestTempInteractiveControl(dialog);
    dialog->PushEventHandler (handler);
    dialog->Show ();

    // Main loop will be exited in WxGuiTestTempInteractiveControl::OnOK()
    wxTheApp->MainLoop ();

    // Restore main loop flag:
    WxGuiTestHelper::SetUseExitMainLoopOnIdleFlag (oldUseExitMainLoopOnIdle);
    // Likewise, restore other flags:
    WxGuiTestHelper::SetShowModalDialogsNonModalFlag (oldShowModalDialogsNonModal);
    WxGuiTestHelper::SetShowPopupMenusFlag (oldShowPopupMenus);
    dialog->PopEventHandler (true);
    dialog->Destroy ();
}




wxDialog* 
WxGuiTestTempInteractive::CreateDialog (const wxString& file, int line)
{
    wxDialog* dialog = new wxDialog (wxTheApp->GetTopWindow (), -1,
            _("wxGui CppUnit Testing Suspended"), wxDefaultPosition,
            wxDefaultSize, wxDEFAULT_DIALOG_STYLE);

    wxBoxSizer *sizer = new wxBoxSizer (wxVERTICAL);

    wxStaticText *text = new wxStaticText (dialog, -1,
            _("Temporary interactive test. -- Continue unit testing?"),
            wxDefaultPosition, wxDefaultSize, 0);
    sizer->Add (text, 0, wxALIGN_CENTER | wxALL, 10);

    if ((file != _T("")) && (line > -1)) {

        wxStaticText *fileInfoText = 
	    new wxStaticText (dialog, -1, 
			      wxString::Format (_T("%s: %s\n%s: %d"), _("File"),
						file.c_str(), _("Line"), line), 
			      wxDefaultPosition, wxDefaultSize, 0);
        sizer->Add (fileInfoText, 0, wxALIGN_CENTER | wxALL, 10);
    }

    wxButton *okBtn = new wxButton (dialog, -1, _("OK"), wxDefaultPosition,
            wxDefaultSize, 0);
    sizer->Add (okBtn, 0, wxALIGN_CENTER | wxALL, 10);

    dialog->SetSizer (sizer);
    sizer->SetSizeHints (dialog);
    dialog->Layout ();
    return dialog;
}

