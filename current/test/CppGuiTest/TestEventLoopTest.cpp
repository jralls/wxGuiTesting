///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/TestEventLoopTest.cpp
// Author:      John Ralls
// Created:     2009
// Copyright:   (c) 2009 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#include "TestEventLoopTest.h"
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/timer.h>

#include <wxGuiTest/WxGuiTestApp.h>

using namespace wxTst;


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( TestEventLoopTest, "WxGuiTest" );

namespace {
    class LocalDialog : public wxDialog {
    public:
	LocalDialog();
	virtual void OnTimer(wxTimerEvent& event);
	virtual void OnOK(wxCommandEvent& event);
    private:
 	DECLARE_EVENT_TABLE()
    };

    const int TimerID = 9999;
    const int BadEnd = 99;
    BEGIN_EVENT_TABLE(LocalDialog, wxDialog)
    EVT_BUTTON(wxID_OK, LocalDialog::OnOK)
    EVT_TIMER(TimerID, LocalDialog::OnTimer)
    END_EVENT_TABLE()
}

LocalDialog::LocalDialog() : 
    wxDialog(NULL, -1, _T("Title"), wxDefaultPosition, wxDefaultSize,
	     wxDEFAULT_DIALOG_STYLE, _T("modalDialog"))
{
    wxTextCtrl *textCtrl = 
	new wxTextCtrl (this, wxID_ANY, _T(""), wxDefaultPosition, 
			wxDefaultSize, 0, wxDefaultValidator, _T("TestText"));

    wxBoxSizer *sizer = new wxBoxSizer (wxVERTICAL);
    wxSizer* btnsz = CreateButtonSizer(wxOK | wxCANCEL);
    sizer->Add (textCtrl, 1, wxGROW | wxADJUST_MINSIZE, 0);
    sizer->Add(btnsz, wxSizerFlags().Expand().Border());
    sizer->Layout();
    sizer->SetSizeHints (this);
    SetSizer (sizer);
}

void
LocalDialog::OnTimer(wxTimerEvent& WXUNUSED(event)) {
    SetReturnCode(BadEnd);
    EndDialog(BadEnd);
}

void
LocalDialog::OnOK(wxCommandEvent& WXUNUSED(e)) {
    SetReturnCode(wxID_OK);
    EndDialog(wxID_OK);
}


void TestEventLoopTest::setUp () {
//No-op
}


void TestEventLoopTest::tearDown () {
//No-op
}

void
TestEventLoopTest::testQueueEvent() {
    WxGuiTestApp& app = wxGetApp();
    app.newEventQueue();
    wxCommandEvent evt1(wxEVT_COMMAND_BUTTON_CLICKED, 1);
    CPPUNIT_ASSERT_MESSAGE("testQueueEvent: App Has Pending Events", 
			   !app.pending());
    app.queueEvent(evt1);
    CPPUNIT_ASSERT_MESSAGE("testQueueEvent: App failed to queue event", 
			   app.pending());
    app.discardCurrentQueue();
    CPPUNIT_ASSERT_MESSAGE("testQueueEvent: App Failed to delete queue", 
			   !app.pending());
}

void TestEventLoopTest::testDialog ()
{
    LocalDialog dialog;
    wxTextCtrl* textCtrl = 
	dynamic_cast<wxTextCtrl*>(dialog.FindWindow(_T("TestText")));
    CPPUNIT_ASSERT_MESSAGE("NULL wxTextCtrl*", textCtrl != NULL);

    wxCommandEvent evt1 (wxEVT_COMMAND_BUTTON_CLICKED, wxID_OK);
    evt1.SetEventObject (&dialog);
    WxGuiTestApp& app = wxGetApp();
//    app.newEventQueue();
    app.queueEvent(evt1);
    
    CPPUNIT_ASSERT_MESSAGE("testDialog: App failed to queue event", 
			   app.pending());
    dialog.Show();
    app.ProcessPendingEvents();
    CPPUNIT_ASSERT_MESSAGE("testDialog: postNextEvent returned false", 
			   app.postNextEvent());
    CPPUNIT_ASSERT_MESSAGE("testQueueEvent: App failed to post event", 
			   wxPendingEvents != NULL && 
			   !wxPendingEvents->IsEmpty());
    app.MainLoop();

    CPPUNIT_ASSERT_MESSAGE ("testQueueEvent: Dialog was not ended correctly",
            dialog.GetReturnCode () == wxID_OK);

}


