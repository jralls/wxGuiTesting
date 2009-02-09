///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/EventSimulationHelperTest.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2009
// Modifications Copyright: (c) 2009 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "EventSimulationHelperTest.h"
#endif

#include "EventSimulationHelperTest.h"
#include <wx/wx.h>
#include <wx/xrc/xmlres.h>
#include <wx/minifram.h>
#include <wx/image.h>
#include <wx/notebook.h>
#include <wx/spinctrl.h>

#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/EventSimulationHelper.h>
#include <wxGuiTest/TimedDialogEnder.h>
#include <wxGuiTest/TempInteractive.h>


namespace {
    const wxString testDir(_T(TESTDIR));
}

using namespace wxTst;


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( EventSimulationHelperTest, "WxGuiTest" );

struct MyButton : public wxButton {
void OnButton(wxCommandEvent& event) {
	wxMessageBox(_T("You pressed the button!"));
	wxLogTrace(_T("wxGuiTestCallTrace"), _T("On Button Event"));

	event.Skip();
}
};


EventSimulationHelperTest::EventSimulationHelperTest () :
    m_testFrame(NULL), m_testEvtHandler(NULL), m_miniFrame(NULL)
{
    wxXmlResource::Get()->InitAllHandlers();

   wxLog::AddTraceMask (_T("wxGuiTestIdle"));
}


EventSimulationHelperTest::~EventSimulationHelperTest ()
{
    // Nothing to do? m_testFrame and m_testEvtHandler are deleted automatically
}


void EventSimulationHelperTest::setUp ()
{
    const wxString xrcDir = _T(XRCDIR);
    wxXmlResource::Get()->Load (xrcDir + _T("/EvtSimHlpTest_wdr.xrc"));
    m_testFrame = new wxFrame(NULL, wxID_ANY, _T("Event Simulation Test"),
			      wxDefaultPosition, wxSize(250, 700));

    m_testEvtHandler = new EvtSimHlpEvtHandler (m_testFrame);
    m_testFrame->PushEventHandler (m_testEvtHandler);
    
    wxMenuBar *menuBar = wxXmlResource::Get ()->LoadMenuBar (wxT("MenuBar"));
    wxASSERT (menuBar != NULL);
    m_testFrame->SetMenuBar (menuBar);

    // Because generic toolbars are only creatable by the frame factory for
    // registration only abuse symbolic IDs from XRC test file:
    wxToolBar* toolBar = new wxToolBar(m_testFrame, wxID_ANY,
				       wxDefaultPosition, wxDefaultSize,
				       wxNO_BORDER | wxTB_FLAT | wxTB_HORIZONTAL,
				       _T("ToolBar"));
    wxBitmap *icon1 = new wxBitmap (wxImage (testDir + wxString(_T("/res/icon1.bmp"))));
    wxBitmap *icon2 = new wxBitmap (wxImage (testDir + wxString(_T("/res/icon2.bmp"))));
    toolBar->AddTool (XRCID ("Tool"), _T(""), *icon1, _T("Tool"));
    toolBar->AddCheckTool (XRCID ("ToggleTool"), _T(""), *icon2, wxNullBitmap,_T("ToggleTool"));
    delete icon1;
    delete icon2;
    toolBar->Realize ();
    m_testFrame->SetToolBar(toolBar);

    m_miniFrame = new wxMiniFrame (m_testFrame, -1, _T("EvtSimHlpMiniFrame"));
    wxBoxSizer *topsizer = new wxBoxSizer (wxVERTICAL);
    wxPanel *panel = wxXmlResource::Get ()->LoadPanel (m_miniFrame, _T("EvtSimHlpTestPanel"));
    wxASSERT (panel != NULL);
    wxButton* button = dynamic_cast<wxButton*>(panel->FindWindow(_T("Button")));
    if (button)
	button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, 
			wxCommandEventHandler(MyButton::OnButton));
 
    topsizer->Add (panel, 1, wxGROW | wxADJUST_MINSIZE, 0);
    topsizer->SetSizeHints (m_miniFrame);
    m_miniFrame->SetSizer (topsizer);
    m_miniFrame->Show ();
    m_miniFrame->Move (m_testFrame->GetPosition ().x + 30, m_testFrame->GetPosition ().y + 90);

    wxTheApp->SetTopWindow (m_testFrame);
    WxGuiTestHelper::Show (m_testFrame, true, false);

    // Flushing the event queue here is necessary to avoid confusion because of
    // the next showing of a MyFrame instance, while the old one is - due to no
    // time in the message processing loop for actually destructing and hiding
    // the closed window (see tearDown() method) - still visible. On the other
    // hand, flushing the event queue in tearDown() method directly, may close
    // whole application because it is the top window. Interestingly it only
    // causes a problem at the very end - maybe the last idle event is used in
    // tearDown() method, while it would be expected at the very end of
    // WxGuiTestApp::OnRun() method:
    WxGuiTestHelper::FlushEventQueue ();
}


void EventSimulationHelperTest::tearDown ()
{
    m_miniFrame->Close ();
    m_testFrame->PopEventHandler ();
    m_testFrame->Destroy();
    m_testFrame = NULL;
    WxGuiTestHelper::FlushEventQueue ();
}


void EventSimulationHelperTest::testSelectMenuItem ()
{
    EventSimulationHelper::SelectMenuItem (XRCID("MenuItem"), m_testFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of menu item selection failed",
            m_testEvtHandler->HasMenuItemSelProcessed ());

    wxTst::TempInteractive interactive;
    interactive.ShowCurrentGui ();
}


void EventSimulationHelperTest::testSelectCheckableMenuItem ()
{
    wxMenuBar *menuBar = m_testFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);
    int checkableMenuItemId = menuBar->FindMenuItem (_("Menu"), _("CheckableMenuItem"));
    CPPUNIT_ASSERT_MESSAGE ("CheckableMenuItem menu item ID not found",
            checkableMenuItemId != wxNOT_FOUND);
    wxMenu* menu = menuBar->GetMenu (0);
    CPPUNIT_ASSERT_MESSAGE ("Menu menu not found", menu != NULL);
    wxMenuItem *item = menuBar->FindItem (checkableMenuItemId, &menu);
    CPPUNIT_ASSERT_MESSAGE ("MenuItem menu item not found", item != NULL);

    EventSimulationHelper::SelectAndCheckMenuItem (XRCID("CheckableMenuItem"), m_testFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checking menu item selection failed",
            m_testEvtHandler->HasCheckableMenuItemProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checking menu item selection failed to check menu item",
            item->IsChecked ());

    m_testEvtHandler->Init ();

    EventSimulationHelper::SelectAndCheckMenuItem (XRCID("CheckableMenuItem"), m_testFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of unchecking menu item selection failed",
            m_testEvtHandler->HasCheckableMenuItemProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of unchecking menu item selection failed to uncheck menu item",
            !item->IsChecked ());
}


void EventSimulationHelperTest::testClickButton ()
{
    wxButton *button = XRCCTRL (*m_testFrame, "Button", wxButton);
    wxString name = button->GetName ();

    EventSimulationHelper::ClickButton (XRCID("Button"), button);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of button clicking failed",
            m_testEvtHandler->HasButtonClickProcessed ());
}


void EventSimulationHelperTest::testSetTextCtrlValue ()
{
    const wxString value = _T("VaLuE");

    wxTextCtrl *textCtrl = XRCCTRL (*m_testFrame, "TextCtrl", wxTextCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Text control not found", textCtrl != NULL);
    CPPUNIT_ASSERT_MESSAGE ("Text control value already correctly set",
            textCtrl->GetValue () != value);

    EventSimulationHelper::SetTextCtrlValue (textCtrl, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of setting text control must generate an event",
            m_testEvtHandler->HasTextCtrlValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of text control value changing failed",
            textCtrl->GetValue () == value);
}




void EventSimulationHelperTest::testSelectTreeItem ()
{
    wxTreeCtrl *treeCtrl = XRCCTRL (*m_testFrame, "TreeCtrl", wxTreeCtrl);
    wxTreeItemId root = treeCtrl->AddRoot (_T("Root"));
    wxTreeItemId item = treeCtrl->AppendItem (root, _T("item"));

    CPPUNIT_ASSERT_MESSAGE ("Tree item already selected",
        treeCtrl->GetSelection () != item);

    EventSimulationHelper::SelectTreeItem (item, treeCtrl);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of tree item selection must generate an event",
            m_testEvtHandler->HasTreeItemSelProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of tree item selection failed",
        treeCtrl->GetSelection () == item);
}


void EventSimulationHelperTest::testRightClickTreeItem ()
{
    wxTreeCtrl *treeCtrl = XRCCTRL (*m_testFrame, "TreeCtrl", wxTreeCtrl);
    wxTreeItemId root = treeCtrl->AddRoot (_T("Root"));
    wxTreeItemId item = treeCtrl->AppendItem (root, _T("item"));
    // Expand tree to show item required for bounding box calculation in right
    // click event simulation:
    treeCtrl->Expand (root);

    EventSimulationHelper::RightClickTreeItem (item, treeCtrl);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of right clicking tree item must generate an event",
            m_testEvtHandler->HasTreeItemRightClickProcessed ());
}


void EventSimulationHelperTest::testSelectNotebookPage ()
{
    m_testEvtHandler->Init ();

    const int page = 1;

    wxNotebook *notebook = XRCCTRL (*m_testFrame, "Notebook", wxNotebook);

    CPPUNIT_ASSERT_MESSAGE ("Notebook page already selected",
        notebook->GetSelection () != page);

    EventSimulationHelper::SelectNotebookPage (notebook, page);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of notebook page selection must generate an event",
            m_testEvtHandler->HasNotebookPageSelProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of notebook page selection failed",
            notebook->GetSelection () == page);
}


void EventSimulationHelperTest::testSelectChoiceItem ()
{
    const int index = 1;

    wxChoice *choice = XRCCTRL (*m_testFrame, "Choice", wxChoice);

    CPPUNIT_ASSERT_MESSAGE ("Choice item already selected",
        choice->GetSelection () != index);

    EventSimulationHelper::SelectChoiceItem (choice, index);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of choice item selection must generate an event",
            m_testEvtHandler->HasChoiceSelProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of choice item selection failed",
            choice->GetSelection () == index);
}


void EventSimulationHelperTest::testSetCheckboxState ()
{
    wxCheckBox *checkbox = XRCCTRL (*m_testFrame, "Checkbox", wxCheckBox);

    CPPUNIT_ASSERT_MESSAGE ("Checkbox already checked", !checkbox->IsChecked ());

    EventSimulationHelper::SetCheckboxState (checkbox, true);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checkbox checking must generate an event",
            m_testEvtHandler->HasCheckboxCheckingProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checkbox checking failed",
            checkbox->IsChecked ());

    m_testEvtHandler->Init ();

    EventSimulationHelper::SetCheckboxState (checkbox, false);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checkbox unchecking failed",
            !checkbox->IsChecked ());
}


void EventSimulationHelperTest::testSelectRadioBoxItem ()
{
    wxRadioBox *radioBox = XRCCTRL (*m_testFrame, "RadioBox", wxRadioBox);

    int selection = 0;
    EventSimulationHelper::SelectRadioBoxItem (radioBox, selection);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of radiobox checking must generate an event",
            m_testEvtHandler->HasRadioBoxSelProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of radiobox selection failed",
            radioBox->GetSelection () == selection);

    m_testEvtHandler->Init ();

    selection = 1;
    EventSimulationHelper::SelectRadioBoxItem (radioBox, selection);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of radiobox selection failed",
            radioBox->GetSelection () == selection);

    m_testEvtHandler->Init ();

    selection = 2;
    EventSimulationHelper::SelectRadioBoxItem (radioBox, selection);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of radiobox selection failed",
            radioBox->GetSelection () == selection);
}


void EventSimulationHelperTest::testSetSliderValue ()
{
    wxSlider *slider = XRCCTRL (*m_testFrame, "Slider", wxSlider);
    CPPUNIT_ASSERT_MESSAGE ("No slider to test!", slider);

    int value = 10;
    EventSimulationHelper::SetSliderValue (slider, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider must generate an event",
            m_testEvtHandler->HasSliderValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            slider->GetValue () == value);

    m_testEvtHandler->Init ();

    value = 1;
    EventSimulationHelper::SetSliderValue (slider, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider must generate an event",
            m_testEvtHandler->HasSliderValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            slider->GetValue () == value);

    m_testEvtHandler->Init ();

    value = 5;
    EventSimulationHelper::SetSliderValue (slider, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider must generate an event",
            m_testEvtHandler->HasSliderValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            slider->GetValue () == value);

}


void EventSimulationHelperTest::testSetSpinCtrlValue ()
{
    wxSpinCtrl *spinCtrl = XRCCTRL (*m_testFrame, "SpinCtrl", wxSpinCtrl);
    CPPUNIT_ASSERT_MESSAGE ("No spintCtrl to test!", spinCtrl);

    int value = 10;
    EventSimulationHelper::SetSpinCtrlValue (spinCtrl, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of spintCtrl must generate an event",
            m_testEvtHandler->HasSpinCtrlValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            spinCtrl->GetValue () == value);

    m_testEvtHandler->Init ();

    value = 1;
    EventSimulationHelper::SetSpinCtrlValue (spinCtrl, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider checking must generate an event",
            m_testEvtHandler->HasSpinCtrlValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            spinCtrl->GetValue () == value);

    m_testEvtHandler->Init ();

    value = 5;
    EventSimulationHelper::SetSpinCtrlValue (spinCtrl, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider checking must generate an event",
            m_testEvtHandler->HasSpinCtrlValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            spinCtrl->GetValue () == value);

}


void EventSimulationHelperTest::testToggleTool ()
{
    EventSimulationHelper::ToggleToolOnlyEvent (XRCID ("Tool"), true, m_testFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of tool toggling failed",
            m_testEvtHandler->HasToolTogglingProcessed ());
}


void EventSimulationHelperTest::testToggleCheckableTool ()
{
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxToolBar* wxtoolbar = topFrame->GetToolBar();
    CPPUNIT_ASSERT_MESSAGE ("Toolbar 'wxtoolbar' not found", wxtoolbar != 
            NULL);
    EventSimulationHelper::ToggleTool (XRCID ("ToggleTool"), true, wxtoolbar, topFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Checkable tool should be toggled on",
            wxtoolbar->GetToolState(XRCID ("ToggleTool")));
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checkable tool toggling failed",
            m_testEvtHandler->HasCheckableToolTogglingProcessed ());

    m_testEvtHandler->Init ();

    EventSimulationHelper::ToggleTool (XRCID ("ToggleTool"), false, wxtoolbar, m_testFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Checkable tool should be toggled off",
            !wxtoolbar->GetToolState(XRCID ("ToggleTool")));
}


