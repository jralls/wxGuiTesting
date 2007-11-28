///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/SimpleTest.cpp
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "SimpleTest.h"
#endif

#include "SimpleTest.h"

#include "wx/xrc/xmlres.h"
#include "wx/frame.h"
#include "wx/treectrl.h"

#include "swWxGuiTestHelper.h"
#include "swWxGuiTestEventSimulationHelper.h"
#include "swWxGuiTestTimedDialogEnder.h"
#include "swWxGuiTestTempInteractive.h"

#include "swCRCapture.h"

#include "swConfigManager.h"
#include "swConfig.h"

#include "wx/notebook.h"
#include "swSpinCtrlDouble.h"
#include "swTreeCtrl.h"

using sw::SpinCtrlDouble;


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( SimpleTest, "WxGuiTest_" );


void SimpleTest::setUp ()
{
    wxXmlResource::Get()->InitAllHandlers();
    wxXmlResource::Get()->Load (_T("../Cxx/EvtSimHlpTest_wdr.xrc"));

    wxFrame *frame = new wxFrame (NULL, -1, _T("EvtSimHlpFrame"));

    wxMenuBar *menuBar = wxXmlResource::Get ()->LoadMenuBar (wxT("MenuBar"));
    wxASSERT (menuBar != NULL);
    frame->SetMenuBar (menuBar);

    wxBoxSizer *topsizer = new wxBoxSizer (wxVERTICAL);
    wxPanel *panel = wxXmlResource::Get ()->LoadPanel (frame, _T("EvtSimHlpTestPanel"));
    wxASSERT (panel != NULL);
    // Include the unknown double spin control:
    sw::SpinCtrlDouble *spinCtrl = new sw::SpinCtrlDouble (frame,
            -1,
            _T(""),
            wxDefaultPosition,
            wxSize (80, 21),
            wxNO_BORDER,
            0.00000,
            9999.99999,
            0.5,
            0.1);
    spinCtrl->SetDigits (5, false);
    wxXmlResource::Get ()->AttachUnknownControl (_T("SpinCtrlDbl"), spinCtrl, frame);

    wxTreeCtrl *treeCtrl = XRCCTRL (*frame, "TreeCtrl", wxTreeCtrl);
    wxTreeItemId root = treeCtrl->AddRoot (_T("Root"));
    wxTreeItemId item = treeCtrl->AppendItem (root, _T("item"));
    wxTreeItemId item2 = treeCtrl->AppendItem (root, _T("item2"));

    topsizer->Add (panel, 1, wxGROW | wxADJUST_MINSIZE, 0);
    topsizer->SetSizeHints (frame);
    frame->SetSizer (topsizer);
    frame->Show ();

    wxTheApp->SetTopWindow (frame);
    swTst::WxGuiTestHelper::Show (frame, true, false);
    swTst::WxGuiTestHelper::FlushEventQueue ();
}


void SimpleTest::tearDown ()
{
    sw::ConfigManager::SetInstance (NULL);

    wxWindow *topWdw = wxTheApp->GetTopWindow ();
    wxTheApp->SetTopWindow (NULL);
    topWdw->Hide ();
}


void SimpleTest::testCapture ()
{
    swTst::WxGuiTestTempInteractive interactive;

    // *** Loop up top level containers ***
    CPPUNIT_ASSERT_MESSAGE ("Application top window invalid", wxTheApp->
            GetTopWindow () != NULL);
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxMenuBar *menuBar = topFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);

    interactive.ShowCurrentGui ();

    // *** Check menu item ***
    int checkableMenuItemMenuItemId = menuBar->FindMenuItem (_("Menu"), _(
            "CheckableMenuItem"));
    CPPUNIT_ASSERT_MESSAGE ("Menu item ID 'CheckableMenuItem' not found",
            checkableMenuItemMenuItemId != wxNOT_FOUND);
    wxMenuItem *checkableMenuItemMenuItem = menuBar->FindItem (
            checkableMenuItemMenuItemId);
    CPPUNIT_ASSERT_MESSAGE ("Menu item 'CheckableMenuItem' not found",
            checkableMenuItemMenuItem != NULL);
    swTst::WxGuiTestEventSimulationHelper::SelectAndCheckMenuItem (
            checkableMenuItemMenuItemId, topFrame);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    interactive.ShowCurrentGui ();

    // *** Set text control value ***
    wxWindow *evtSimHlpTestPanel = wxWindow::FindWindowByName (
            _T("EvtSimHlpTestPanel"));
    CPPUNIT_ASSERT_MESSAGE ("Container window for button 'Button' not found",
            evtSimHlpTestPanel != NULL);
    wxWindow *textCtrlWdw = evtSimHlpTestPanel->FindWindow (XRCID("TextCtrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for text control 'TextCtrl' not found",
            textCtrlWdw != NULL);
    wxTextCtrl *textCtrl = wxDynamicCast (textCtrlWdw, wxTextCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for text control 'TextCtrl' "
            "failed", textCtrl != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetTextCtrlValue (textCtrl,
            _T("oh-la-la"));
    swTst::WxGuiTestHelper::FlushEventQueue ();

    interactive.ShowCurrentGui ();

    // *** Set spin control value ***
    wxWindow *spinCtrlDblWdw = evtSimHlpTestPanel->FindWindow (XRCID(
            "SpinCtrlDbl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for spin control 'SpinCtrlDbl' not found",
            spinCtrlDblWdw != NULL);
    sw::SpinCtrlDouble *spinCtrlDbl = wxDynamicCast (spinCtrlDblWdw,
            SpinCtrlDouble);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for spin control 'SpinCtrlDbl' "
            "failed", spinCtrlDbl != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetSpinCtrlDblValue (spinCtrlDbl, 0.6);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    // *** Select tree root node ***
    wxWindow *treeCtrlWdw = evtSimHlpTestPanel->FindWindow (XRCID("TreeCtrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for tree control 'TreeCtrl' not found",
            treeCtrlWdw != NULL);
    wxTreeCtrl *treeCtrl = wxDynamicCast (treeCtrlWdw, wxTreeCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for tree control 'TreeCtrl' "
            "failed", treeCtrl != NULL);
    wxTreeItemId rootId = treeCtrl->GetRootItem ();
    CPPUNIT_ASSERT_MESSAGE ("Tree control root item is invalid", rootId.IsOk (
            ));
    swTst::WxGuiTestEventSimulationHelper::SelectTreeItem (rootId, treeCtrl);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    // *** Select first sub node ***
    wxWindow *treeCtrlWdw1 = evtSimHlpTestPanel->FindWindow (XRCID("TreeCtrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for tree control 'TreeCtrl' not found",
            treeCtrlWdw1 != NULL);
    wxTreeCtrl *treeCtrl1 = wxDynamicCast (treeCtrlWdw1, wxTreeCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for tree control 'TreeCtrl' "
            "failed", treeCtrl1 != NULL);
    wxTreeItemId treeItemId1 = sw::TreeCtrl::GetNthChild (treeCtrl1, 1, rootId);
    CPPUNIT_ASSERT_MESSAGE ("Tree control item is invalid", treeItemId1.IsOk (
            ));
    swTst::WxGuiTestEventSimulationHelper::SelectTreeItem (treeItemId1,
            treeCtrl1);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    // *** Go to second notebook tab/page ***
    wxWindow *notebookWdw = wxWindow::FindWindowByName (_T("Notebook"));
    CPPUNIT_ASSERT_MESSAGE ("Container window for notebook 'Notebook' not "
            "found", notebookWdw != NULL);
    wxNotebook *notebook = wxDynamicCast (notebookWdw, wxNotebook);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for notebook 'Notebook' failed",
             notebook != NULL);
    const wxString notebookPageText (_("Page2"));
    int notebookPage = 0;
    while ((notebookPage < notebook->GetPageCount ()) && (notebook->
            GetPageText (notebookPage) != notebookPageText)) {

        notebookPage++;
    }
    CPPUNIT_ASSERT_MESSAGE ("Page of notebook 'Notebook' not found",
            notebookPage < notebook->GetPageCount ());
    swTst::WxGuiTestEventSimulationHelper::SelectNotebookPage (notebook,
            notebookPage);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    // *** Select choice ***
    wxWindow *choiceWdw = evtSimHlpTestPanel->FindWindow (XRCID("Choice"));
    CPPUNIT_ASSERT_MESSAGE ("Window for choice 'Choice' not found", choiceWdw
            != NULL);
    wxChoice *choice = wxDynamicCast (choiceWdw, wxChoice);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for choice 'Choice' failed",
            choice != NULL);
    const wxString choiceSelectionText (_("Item"));
    int choiceSelection = choice->FindString (choiceSelectionText);
    swTst::WxGuiTestEventSimulationHelper::SelectChoiceItem (choice,
            choiceSelection);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    // *** Change checkbox ***
    wxWindow *checkboxWdw = evtSimHlpTestPanel->FindWindow (XRCID("Checkbox"));
    CPPUNIT_ASSERT_MESSAGE ("Window for check box 'Checkbox' not found",
            checkboxWdw != NULL);
    wxCheckBox *checkbox = wxDynamicCast (checkboxWdw, wxCheckBox);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for check box 'Checkbox' "
            "failed", checkbox != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetCheckboxState (checkbox, true);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    // *** Select radio button ***
    wxWindow *radioBoxWdw = evtSimHlpTestPanel->FindWindow (XRCID("RadioBox"));
    CPPUNIT_ASSERT_MESSAGE ("Window for radio box 'RadioBox' not found",
            radioBoxWdw != NULL);
    wxRadioBox *radioBox = wxDynamicCast (radioBoxWdw, wxRadioBox);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for radio box 'RadioBox' "
            "failed", radioBox != NULL);
    const wxString radioBoxSelectionText (_("Radio2"));
    int radioBoxSelection = radioBox->FindString (radioBoxSelectionText);
    swTst::WxGuiTestEventSimulationHelper::SelectRadioBoxItem (radioBox,
            radioBoxSelection);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    // *** Set slider value ***
    wxWindow *sliderWdw = evtSimHlpTestPanel->FindWindow (XRCID("Slider"));
    CPPUNIT_ASSERT_MESSAGE ("Window for slider 'Slider' not found", sliderWdw
            != NULL);
    wxSlider *slider = wxDynamicCast (sliderWdw, wxSlider);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for slider 'Slider' failed",
            slider != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetSliderValue (slider, 27);
    swTst::WxGuiTestHelper::FlushEventQueue ();
}
