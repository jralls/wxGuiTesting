///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/ModalDialogTest.cpp
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Modifications: John Ralls, 2007-2009
// Modifications Copyright: (c) 2009 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "ModalDialogTest.h"
#endif

#include "ModalDialogTest.h"

#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>

#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/EventSimulationHelper.h>
#include <wxGuiTest/ModalDialogTimer.h>

#include "ModalDialogManipulator.h"
#include "DirDialogManipulator.h"


using namespace wxTst;


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( ModalDialogTest, "WxGuiTest" );

namespace {
    class LocalDialog : public wxDialog {
    public:
	LocalDialog();
	virtual void OnTimer(wxTimerEvent& event);
    private:
 	DECLARE_EVENT_TABLE()
    };

    const int TimerID = 9999;
    const int BadEnd = 99;
    BEGIN_EVENT_TABLE(LocalDialog, wxDialog)
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
    sizer->Add (textCtrl, 1, wxGROW | wxADJUST_MINSIZE, 0);
    sizer->SetSizeHints (this);
    SetSizer (sizer);
}

void
LocalDialog::OnTimer(wxTimerEvent& WXUNUSED(event)) {
    EndDialog(BadEnd);
}




void ModalDialogTest::setUp ()
{
    // Nothing to do
}


void ModalDialogTest::tearDown ()
{
    // Nothing to do
}


void ModalDialogTest::testModalDialogTimer ()
{
    LocalDialog dialog;
    wxTextCtrl* textCtrl = 
	dynamic_cast<wxTextCtrl*>(dialog.FindWindow(_T("TestText")));
    CPPUNIT_ASSERT_MESSAGE("NULL wxTextCtrl*", textCtrl != NULL);
    
    ModalDialogTimer timer (wxID_OK);
    timer.SetModalDialog (&dialog);
    timer.Start (1000, true);

    EventSimulationHelper::SetTextCtrlValue (textCtrl, _T("init"));
    WxGuiTestHelper::FlushEventQueue ();

    ModalDialogManipulator * manip = new ModalDialogManipulator (textCtrl);
    timer.SetModalDialogInteractor (manip);

    dialog.ShowModal ();

    // Note: when the timer fires, the manip object will interact with the
    // modal dialog before the timer closes dialog with specified return code.

    CPPUNIT_ASSERT_MESSAGE ("Dialog was not ended correctly",
            dialog.GetReturnCode () == wxID_OK);

    CPPUNIT_ASSERT_MESSAGE ("Text control value was not set correctly",
            textCtrl->GetValue () == _T("hello"));
}


void ModalDialogTest::testStdModalDialogTimer ()
{
    wxDirDialog dialog (NULL);

    ModalDialogTimer timer (wxID_OK);
    timer.SetModalDialog (&dialog);
    timer.Start (1000, true);

    DirDialogManipulator * manip = new DirDialogManipulator (&dialog);
    timer.SetModalDialogInteractor (manip);

    if (dialog.ShowModal() == wxID_OK) {

        CPPUNIT_ASSERT_MESSAGE ("Invalid directory was selected",
                dialog.GetPath () == _T("z:\\test"));
    
    } else {
        
        CPPUNIT_FAIL ("Dialog was not ended correctly");
    }
}

void ModalDialogTest::testModalDialogEventLoop() {
    LocalDialog dialog;
    wxTimer timer(&dialog, TimerID);
    wxTextCtrl* textCtrl = 
	dynamic_cast<wxTextCtrl*>(dialog.FindWindow(_T("TestText")));
    CPPUNIT_ASSERT_MESSAGE("NULL wxTextCtrl*", textCtrl != NULL);
    EventSimulationHelper::SetTextCtrlValue (textCtrl, _T("init"));
    timer.Start(10, true);
    WxGuiTestHelper::FlushEventQueue ();
    dialog.ShowModal ();

//Need a timer here to tell dialog to end its modal loop so the test
//can properly fail.

    CPPUNIT_ASSERT_MESSAGE ("Dialog was not ended correctly",
            dialog.GetReturnCode () == wxID_OK);

    CPPUNIT_ASSERT_MESSAGE ("Text control value was not set correctly",
            textCtrl->GetValue () == _T("hello"));

}
