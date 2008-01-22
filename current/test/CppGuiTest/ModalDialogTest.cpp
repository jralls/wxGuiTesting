///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/ModalDialogTest.cpp
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
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

#include <wxGuiTest/GuiTestHelper.h>
#include <wxGuiTest/EventSimulationHelper.h>
#include <wxGuiTest/ModalDialogTimer.h>

#include "ModalDialogManipulator.h"
#include "DirDialogManipulator.h"


using namespace wxTst;


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( ModalDialogTest, "WxGuiTest" );


void ModalDialogTest::setUp ()
{
    // Nothing to do
}


void ModalDialogTest::tearDown ()
{
    // Nothing to do
}


void ModalDialogTest::testModalDialog ()
{
    wxDialog dialog (NULL, -1, _T("Title"), wxDefaultPosition, wxDefaultSize,
            wxDEFAULT_DIALOG_STYLE, _T("modalDialog"));
    
    wxTextCtrl *textCtrl = new wxTextCtrl (&dialog, -1);

    wxBoxSizer *sizer = new wxBoxSizer (wxVERTICAL);
    sizer->Add (textCtrl, 1, wxGROW | wxADJUST_MINSIZE, 0);
    sizer->SetSizeHints (&dialog);
    dialog.SetSizer (sizer);

    ModalDialogTimer timer (wxID_OK);
    timer.SetModalDialog (&dialog);
    timer.Start (1000, true);

    EventSimulationHelper::SetTextCtrlValue (textCtrl, _T("init"));
    GuiTestHelper::FlushEventQueue ();

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


void ModalDialogTest::testStdModalDialog ()
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

