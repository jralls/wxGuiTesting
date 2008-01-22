///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/CRCaptureTest.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRCaptureTest.h"
#endif

#include "CRCaptureTest.h"

#include <wx/xrc/xmlres.h>
#include <wx/frame.h>
#include <wx/treectrl.h>

#include <wxGuiTest/GuiTestHelper.h>
#include <wxGuiTest/EventSimulationHelper.h>
#include <wxGuiTest/TimedDialogEnder.h>
#include <wxGuiTest/TempInteractive.h>

#include <wxGuiTest/CRCapture.h>

#include <wx/notebook.h>
#include <wx/spinctrl.h>
#include <wx/treectrl.h>

using namespace wxTst;


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( CRCaptureTest, "WxGuiTest" );


void CRCaptureTest::setUp ()
{
    const wxString xrcDir = _T(XRCDIR);
    wxXmlResource::Get()->InitAllHandlers();
    wxXmlResource::Get()->Load (xrcDir + _T("/EvtSimHlpTest_wdr.xrc"));

    wxFrame *frame = new wxFrame (NULL, -1, _T("EvtSimHlpFrame"));

    wxMenuBar *menuBar = wxXmlResource::Get ()->LoadMenuBar (wxT("MenuBar"));
    wxASSERT (menuBar != NULL);
    frame->SetMenuBar (menuBar);
    
    wxBoxSizer *topsizer = new wxBoxSizer (wxVERTICAL);
    wxPanel *panel = wxXmlResource::Get ()->LoadPanel (frame, 
            _T("EvtSimHlpTestPanel"));
    wxASSERT (panel != NULL);
    wxTreeCtrl *treeCtrl = XRCCTRL (*frame, "TreeCtrl", wxTreeCtrl);
    wxTreeItemId root = treeCtrl->AddRoot (_T("Root"));
    wxTreeItemId item = treeCtrl->AppendItem (root, _T("item"));
    wxTreeItemId item2 = treeCtrl->AppendItem (root, _T("item2"));

    topsizer->Add (panel, 1, wxGROW | wxADJUST_MINSIZE, 0);
    topsizer->SetSizeHints (frame);
    frame->SetSizer (topsizer);
    frame->Show ();

    wxTheApp->SetTopWindow (frame);
    GuiTestHelper::Show (frame, true, false);
    GuiTestHelper::FlushEventQueue ();

}


void CRCaptureTest::tearDown ()
{
    wxWindow *topWdw = wxTheApp->GetTopWindow ();
    wxTheApp->SetTopWindow (NULL);
    topWdw->Hide ();
}


void CRCaptureTest::testCapture ()
{
    wxTst::TempInteractive interactive;
/*
    CPPUNIT_ASSERT_MESSAGE ("Application top window invalid", wxTheApp->
            GetTopWindow () != NULL);
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxMenuBar *menuBar = topFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);

    interactive.ShowCurrentGui ();

    int checkableMenuItemMenuItemId = menuBar->FindMenuItem (_("Menu"), _(
            "CheckableMenuItem"));
    CPPUNIT_ASSERT_MESSAGE ("Menu item ID 'CheckableMenuItem' not found", 
            checkableMenuItemMenuItemId != wxNOT_FOUND);
    wxMenuItem *checkableMenuItemMenuItem = menuBar->FindItem (
            checkableMenuItemMenuItemId);
    CPPUNIT_ASSERT_MESSAGE ("Menu item 'CheckableMenuItem' not found", 
            checkableMenuItemMenuItem != NULL);
    // Check if checkable menu item is not already checked?
    // if (!checkableMenuItemMenuItem->IsChecked ()) { ...
    wxTst::EventSimulationHelper::SelectAndCheckMenuItem (
            checkableMenuItemMenuItemId, topFrame);
    wxTst::GuiTestHelper::FlushEventQueue ();

    interactive.ShowCurrentGui ();

    wxWindow *evtSimHlpTestPanel = wxWindow::FindWindowByName (
            "EvtSimHlpTestPanel");
    CPPUNIT_ASSERT_MESSAGE ("Container window for button 'Button' not found", 
            evtSimHlpTestPanel != NULL);
    wxWindow *textCtrlWdw = evtSimHlpTestPanel->FindWindow (XRCID("TextCtrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for text control 'TextCtrl' not found", 
            textCtrlWdw != NULL);
    wxTextCtrl *textCtrl = wxDynamicCast (textCtrlWdw, wxTextCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for text control 'TextCtrl' "
            "failed", textCtrl != NULL);
    wxTst::EventSimulationHelper::SetTextCtrlValue (textCtrl, 
            "oh-la-la");
    wxTst::GuiTestHelper::FlushEventQueue ();

    interactive.ShowCurrentGui ();

    wxWindow *spinCtrlDblWdw = evtSimHlpTestPanel->FindWindow (XRCID(
            "SpinCtrlDbl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for spin control 'SpinCtrlDbl' not found", 
            spinCtrlDblWdw != NULL);
    ::SpinCtrlDouble *spinCtrlDbl = wxDynamicCast (spinCtrlDblWdw, 
            SpinCtrlDouble);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for spin control 'SpinCtrlDbl' "
            "failed", spinCtrlDbl != NULL);
    wxTst::EventSimulationHelper::SetSpinCtrlDblValue (spinCtrlDbl, 0.6);
    wxTst::GuiTestHelper::FlushEventQueue ();

    wxWindow *treeCtrlWdw = evtSimHlpTestPanel->FindWindow (XRCID("TreeCtrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for tree control 'TreeCtrl' not found", 
            treeCtrlWdw != NULL);
    wxTreeCtrl *treeCtrl = wxDynamicCast (treeCtrlWdw, wxTreeCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for tree control 'TreeCtrl' "
            "failed", treeCtrl != NULL);
    wxTreeItemId rootId = treeCtrl->GetRootItem ();
    CPPUNIT_ASSERT_MESSAGE ("Tree control root item is invalid", rootId.IsOk (
            ));
    wxTst::EventSimulationHelper::SelectTreeItem (rootId, treeCtrl);
    wxTst::GuiTestHelper::FlushEventQueue ();

    wxWindow *treeCtrlWdw1 = evtSimHlpTestPanel->FindWindow (XRCID("TreeCtrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for tree control 'TreeCtrl' not found", 
            treeCtrlWdw1 != NULL);
    wxTreeCtrl *treeCtrl1 = wxDynamicCast (treeCtrlWdw1, wxTreeCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for tree control 'TreeCtrl' "
            "failed", treeCtrl1 != NULL);
    wxTreeItemId treeItemId1 = ::TreeCtrl::GetNthChild (treeCtrl1, 1, rootId);
    CPPUNIT_ASSERT_MESSAGE ("Tree control item is invalid", treeItemId1.IsOk (
            ));
    wxTst::EventSimulationHelper::SelectTreeItem (treeItemId1, 
            treeCtrl1);
    wxTst::GuiTestHelper::FlushEventQueue ();

    wxWindow *treeCtrlWdw2 = evtSimHlpTestPanel->FindWindow (XRCID("TreeCtrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for tree control 'TreeCtrl' not found", 
            treeCtrlWdw2 != NULL);
    wxTreeCtrl *treeCtrl2 = wxDynamicCast (treeCtrlWdw2, wxTreeCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for tree control 'TreeCtrl' "
            "failed", treeCtrl2 != NULL);
    treeCtrl2->Expand (rootId);
    wxTreeItemId treeItemId11 = ::TreeCtrl::GetNthChild (treeCtrl2, 1, 
            rootId);
    CPPUNIT_ASSERT_MESSAGE ("Tree control item is invalid", treeItemId11.IsOk (
            ));
    wxTst::EventSimulationHelper::RightClickTreeItem (treeItemId11, 
            treeCtrl2);
    wxTst::GuiTestHelper::FlushEventQueue ();

    wxWindow *treeCtrlWdw3 = evtSimHlpTestPanel->FindWindow (XRCID("TreeCtrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for tree control 'TreeCtrl' not found", 
            treeCtrlWdw3 != NULL);
    wxTreeCtrl *treeCtrl3 = wxDynamicCast (treeCtrlWdw3, wxTreeCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for tree control 'TreeCtrl' "
            "failed", treeCtrl3 != NULL);
    wxTreeItemId treeItemId12 = ::TreeCtrl::GetNthChild (treeCtrl3, 2, 
            rootId);
    CPPUNIT_ASSERT_MESSAGE ("Tree control item is invalid", treeItemId12.IsOk (
            ));
    wxTst::EventSimulationHelper::SelectTreeItem (treeItemId12, 
            treeCtrl3);
    wxTst::GuiTestHelper::FlushEventQueue ();

    wxWindow *notebookWdw = wxWindow::FindWindowByName ("Notebook");
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
    wxTst::EventSimulationHelper::SelectNotebookPage (notebook, 
            notebookPage);
    wxTst::GuiTestHelper::FlushEventQueue ();

    wxWindow *choiceWdw = evtSimHlpTestPanel->FindWindow (XRCID("Choice"));
    CPPUNIT_ASSERT_MESSAGE ("Window for choice 'Choice' not found", choiceWdw 
            != NULL);
    wxChoice *choice = wxDynamicCast (choiceWdw, wxChoice);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for choice 'Choice' failed", 
            choice != NULL);
    const wxString choiceSelectionText (_("Item"));
    int choiceSelection = choice->FindString (choiceSelectionText);
    wxTst::EventSimulationHelper::SelectChoiceItem (choice, 
            choiceSelection);
    wxTst::GuiTestHelper::FlushEventQueue ();

    wxWindow *checkboxWdw = evtSimHlpTestPanel->FindWindow (XRCID("Checkbox"));
    CPPUNIT_ASSERT_MESSAGE ("Window for check box 'Checkbox' not found", 
            checkboxWdw != NULL);
    wxCheckBox *checkbox = wxDynamicCast (checkboxWdw, wxCheckBox);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for check box 'Checkbox' "
            "failed", checkbox != NULL);
    wxTst::EventSimulationHelper::SetCheckboxState (checkbox, true);
    wxTst::GuiTestHelper::FlushEventQueue ();

    wxWindow *radioBoxWdw = evtSimHlpTestPanel->FindWindow (XRCID("RadioBox"));
    CPPUNIT_ASSERT_MESSAGE ("Window for radio box 'RadioBox' not found", 
            radioBoxWdw != NULL);
    wxRadioBox *radioBox = wxDynamicCast (radioBoxWdw, wxRadioBox);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for radio box 'RadioBox' "
            "failed", radioBox != NULL);
    const wxString radioBoxSelectionText (_("Radio2"));
    int radioBoxSelection = radioBox->FindString (radioBoxSelectionText);
    wxTst::EventSimulationHelper::SelectRadioBoxItem (radioBox, 
            radioBoxSelection);
    wxTst::GuiTestHelper::FlushEventQueue ();

    wxWindow *sliderWdw = evtSimHlpTestPanel->FindWindow (XRCID("Slider"));
    CPPUNIT_ASSERT_MESSAGE ("Window for slider 'Slider' not found", sliderWdw 
            != NULL);
    wxSlider *slider = wxDynamicCast (sliderWdw, wxSlider);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for slider 'Slider' failed", 
            slider != NULL);
    wxTst::EventSimulationHelper::SetSliderValue (slider, 27);
    wxTst::GuiTestHelper::FlushEventQueue ();

    wxWindow *spinCtrlWdw = evtSimHlpTestPanel->FindWindow (XRCID("SpinCtrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for spin control 'SpinCtrl' not found", 
            spinCtrlWdw != NULL);
    wxSpinCtrl *spinCtrl = wxDynamicCast (spinCtrlWdw, wxSpinCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for spin control 'SpinCtrl' "
            "failed", spinCtrl != NULL);
    wxTst::EventSimulationHelper::SetSpinCtrlValue (spinCtrl, 1);
    wxTst::GuiTestHelper::FlushEventQueue ();
*/

    // Do bootstrap capturing:
/*
    {
        wxApp *app = wxTheApp;
        wxASSERT (app != NULL);
        Tst::WxGuiTestApp *guiTestApp = dynamic_cast< Tst::WxGuiTestApp * >(app);
        wxASSERT (guiTestApp != NULL);
        guiTestApp->SetEventFilter (Tst::CREventCaptureManager::GetInstance ());

        std::string excMsg;
        Tst::CRCapture *capture = new Tst::CRCapture ();
        try {
            capture->Capture (__FILE__, __LINE__);
        } catch (std::exception &e) {
            excMsg = e.what ();
        } catch (...) {
            excMsg = "Unexpected capturing exception";
        }
        guiTestApp->SetEventFilter (NULL);
        delete capture;
        Tst::CRCppEmitter::Destroy ();
        if (!excMsg.empty ()) {
            CPPUNIT_FAIL (excMsg.c_str ());
        }
    }
*/
    // Or use easier macro:
    CAPTURE

    interactive.ShowCurrentGui ();

    // Using the {...} notation we can have several CAPTUREs in one method:
    //CAPTURE
}



