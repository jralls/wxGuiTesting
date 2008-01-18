///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swWxGuiTestEventSimulationHelperTest.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swWxGuiTestEventSimulationHelperTest.h"
#endif

#include "swWxGuiTestEventSimulationHelperTest.h"

#include <wx/xrc/xmlres.h>
#include <wx/minifram.h>
#include <wx/image.h>
#include <wx/notebook.h>
#include <wx/spinctrl.h>

#include <wxGuiTest/swWxGuiTestHelper.h>
#include <wxGuiTest/swWxGuiTestEventSimulationHelper.h>
#include <wxGuiTest/swWxGuiTestTimedDialogEnder.h>
#include <wxGuiTest/swWxGuiTestTempInteractive.h>

#include <wxGuiTest/swApp.h>
#include <FrameFactory/swFrameFactory.h>
#include <FrameFactory/swMdiFrameFactory.h>
#include <FrameFactory/swToolBarRegistry.h>

namespace {
    const wxString testDir(_T(TESTDIR));
}

using namespace swTst;


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( WxGuiTestEventSimulationHelperTest, "WxGuiTest" );


WxGuiTestEventSimulationHelperTest::WxGuiTestEventSimulationHelperTest ()
{
    sw::FrameFactory::SetInstance (new sw::MdiFrameFactory (new wxDocManager ()));
    wxXmlResource::Get()->InitAllHandlers();

    m_miniFrame = NULL;

    //wxLog::AddTraceMask (_T("wxGuiTestIdle"));
}


WxGuiTestEventSimulationHelperTest::~WxGuiTestEventSimulationHelperTest ()
{
    // Nothing to do? m_testFrame and m_testEvtHandler are deleted automatically
}


void WxGuiTestEventSimulationHelperTest::setUp ()
{
    const wxString xrcDir = _T(XRCDIR);
    wxXmlResource::Get()->Load (xrcDir + _T("/EvtSimHlpTest_wdr.xrc"));
    sw::MainFrame *mainFrame = sw::FrameFactory::GetInstance ()->GetMainFrame ();
    mainFrame->SetTitle (_T("EvtSimHlpFrame"));    
    m_testFrame = mainFrame->GetFrame ();
    m_testFrame->SetSize (250, 700);

    m_testEvtHandler = new WxGuiTestEvtSimHlpEvtHandler (m_testFrame);
    m_testFrame->PushEventHandler (m_testEvtHandler);
    
    wxMenuBar *menuBar = wxXmlResource::Get ()->LoadMenuBar (wxT("MenuBar"));
    wxASSERT (menuBar != NULL);
    m_testFrame->SetMenuBar (menuBar);

    // Because generic toolbars are only creatable by the frame factory for
    // registration only abuse symbolic IDs from XRC test file:
    sw::ToolBar *toolBar = sw::FrameFactory::GetInstance ()->CreateNamedToolBar (
            _T("ToolBar"), wxNO_BORDER | wxTB_FLAT | wxTB_HORIZONTAL);
    const unsigned int NMB_TOOLS = 2;
    wxBitmap *icon1 = new wxBitmap (wxImage (testDir + wxString(_T("/res/icon1.bmp"))));
    wxBitmap *icon2 = new wxBitmap (wxImage (testDir + wxString(_T("/res/icon2.bmp"))));
    toolBar->AddTool (XRCID ("Tool"), _T(""), *icon1, _T("Tool"));
    toolBar->AddTool (XRCID ("ToggleTool"), _T(""), *icon2, _T("ToggleTool"), true);
    delete icon1;
    delete icon2;
    toolBar->Realize ();

    m_miniFrame = new wxMiniFrame (m_testFrame, -1, _T("EvtSimHlpMiniFrame"));
    wxBoxSizer *topsizer = new wxBoxSizer (wxVERTICAL);
    wxPanel *panel = wxXmlResource::Get ()->LoadPanel (m_miniFrame, _T("EvtSimHlpTestPanel"));
    wxASSERT (panel != NULL);

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


void WxGuiTestEventSimulationHelperTest::tearDown ()
{
    m_miniFrame->Close ();
    sw::ToolBarRegistry::GetInstance ()->Unregister (_T("ToolBar"));
    m_testFrame->SetMenuBar (NULL);
    m_testFrame->SetToolBar (NULL);
    m_testFrame->SetSizer (NULL);
    m_testFrame->PopEventHandler ();
    sw::FrameFactory::GetInstance ()->DestroyMainFrame ();
    WxGuiTestHelper::FlushEventQueue ();
}


void WxGuiTestEventSimulationHelperTest::testSelectMenuItem ()
{
    WxGuiTestEventSimulationHelper::SelectMenuItem (XRCID("MenuItem"), m_testFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of menu item selection failed",
            m_testEvtHandler->HasMenuItemSelProcessed ());

    swTst::WxGuiTestTempInteractive interactive;
    interactive.ShowCurrentGui ();
}


void WxGuiTestEventSimulationHelperTest::testSelectCheckableMenuItem ()
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

    WxGuiTestEventSimulationHelper::SelectAndCheckMenuItem (XRCID("CheckableMenuItem"), m_testFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checking menu item selection failed",
            m_testEvtHandler->HasCheckableMenuItemProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checking menu item selection failed to check menu item",
            item->IsChecked ());

    m_testEvtHandler->Init ();

    WxGuiTestEventSimulationHelper::SelectAndCheckMenuItem (XRCID("CheckableMenuItem"), m_testFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of unchecking menu item selection failed",
            m_testEvtHandler->HasCheckableMenuItemProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of unchecking menu item selection failed to uncheck menu item",
            !item->IsChecked ());
}


void WxGuiTestEventSimulationHelperTest::testClickButton ()
{
    wxButton *button = XRCCTRL (*m_testFrame, "Button", wxButton);
    wxString name = button->GetName ();

    WxGuiTestEventSimulationHelper::ClickButton (XRCID("Button"), button);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of button clicking failed",
            m_testEvtHandler->HasButtonClickProcessed ());
}


void WxGuiTestEventSimulationHelperTest::testSetTextCtrlValue ()
{
    const wxString value = _T("VaLuE");

    wxTextCtrl *textCtrl = XRCCTRL (*m_testFrame, "TextCtrl", wxTextCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Text control not found", textCtrl != NULL);
    CPPUNIT_ASSERT_MESSAGE ("Text control value already correctly set",
            textCtrl->GetValue () != value);

    WxGuiTestEventSimulationHelper::SetTextCtrlValue (textCtrl, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of setting text control must generate an event",
            m_testEvtHandler->HasTextCtrlValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of text control value changing failed",
            textCtrl->GetValue () == value);
}




void WxGuiTestEventSimulationHelperTest::testSelectTreeItem ()
{
    wxTreeCtrl *treeCtrl = XRCCTRL (*m_testFrame, "TreeCtrl", wxTreeCtrl);
    wxTreeItemId root = treeCtrl->AddRoot (_T("Root"));
    wxTreeItemId item = treeCtrl->AppendItem (root, _T("item"));

    CPPUNIT_ASSERT_MESSAGE ("Tree item already selected",
        treeCtrl->GetSelection () != item);

    WxGuiTestEventSimulationHelper::SelectTreeItem (item, treeCtrl);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of tree item selection must generate an event",
            m_testEvtHandler->HasTreeItemSelProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of tree item selection failed",
        treeCtrl->GetSelection () == item);
}


void WxGuiTestEventSimulationHelperTest::testRightClickTreeItem ()
{
    wxTreeCtrl *treeCtrl = XRCCTRL (*m_testFrame, "TreeCtrl", wxTreeCtrl);
    wxTreeItemId root = treeCtrl->AddRoot (_T("Root"));
    wxTreeItemId item = treeCtrl->AppendItem (root, _T("item"));
    // Expand tree to show item required for bounding box calculation in right
    // click event simulation:
    treeCtrl->Expand (root);

    WxGuiTestEventSimulationHelper::RightClickTreeItem (item, treeCtrl);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of right clicking tree item must generate an event",
            m_testEvtHandler->HasTreeItemRightClickProcessed ());
}


void WxGuiTestEventSimulationHelperTest::testSelectNotebookPage ()
{
    m_testEvtHandler->Init ();

    const unsigned int page = 1;

    wxNotebook *notebook = XRCCTRL (*m_testFrame, "Notebook", wxNotebook);

    CPPUNIT_ASSERT_MESSAGE ("Notebook page already selected",
        notebook->GetSelection () != page);

    WxGuiTestEventSimulationHelper::SelectNotebookPage (notebook, page);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of notebook page selection must generate an event",
            m_testEvtHandler->HasNotebookPageSelProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of notebook page selection failed",
            notebook->GetSelection () == page);
}


void WxGuiTestEventSimulationHelperTest::testSelectChoiceItem ()
{
    const unsigned int index = 1;

    wxChoice *choice = XRCCTRL (*m_testFrame, "Choice", wxChoice);

    CPPUNIT_ASSERT_MESSAGE ("Choice item already selected",
        choice->GetSelection () != index);

    WxGuiTestEventSimulationHelper::SelectChoiceItem (choice, index);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of choice item selection must generate an event",
            m_testEvtHandler->HasChoiceSelProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of choice item selection failed",
            choice->GetSelection () == index);
}


void WxGuiTestEventSimulationHelperTest::testSetCheckboxState ()
{
    wxCheckBox *checkbox = XRCCTRL (*m_testFrame, "Checkbox", wxCheckBox);

    CPPUNIT_ASSERT_MESSAGE ("Checkbox already checked", !checkbox->IsChecked ());

    WxGuiTestEventSimulationHelper::SetCheckboxState (checkbox, true);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checkbox checking must generate an event",
            m_testEvtHandler->HasCheckboxCheckingProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checkbox checking failed",
            checkbox->IsChecked ());

    m_testEvtHandler->Init ();

    WxGuiTestEventSimulationHelper::SetCheckboxState (checkbox, false);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checkbox unchecking failed",
            !checkbox->IsChecked ());
}


void WxGuiTestEventSimulationHelperTest::testSelectRadioBoxItem ()
{
    wxRadioBox *radioBox = XRCCTRL (*m_testFrame, "RadioBox", wxRadioBox);

    unsigned int selection = 0;
    WxGuiTestEventSimulationHelper::SelectRadioBoxItem (radioBox, selection);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of radiobox checking must generate an event",
            m_testEvtHandler->HasRadioBoxSelProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of radiobox selection failed",
            radioBox->GetSelection () == selection);

    m_testEvtHandler->Init ();

    selection = 1;
    WxGuiTestEventSimulationHelper::SelectRadioBoxItem (radioBox, selection);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of radiobox selection failed",
            radioBox->GetSelection () == selection);

    m_testEvtHandler->Init ();

    selection = 2;
    WxGuiTestEventSimulationHelper::SelectRadioBoxItem (radioBox, selection);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of radiobox selection failed",
            radioBox->GetSelection () == selection);
}


void WxGuiTestEventSimulationHelperTest::testSetSliderValue ()
{
    wxSlider *slider = XRCCTRL (*m_testFrame, "Slider", wxSlider);
    CPPUNIT_ASSERT_MESSAGE ("No slider to test!", slider);

    unsigned int value = 10;
    WxGuiTestEventSimulationHelper::SetSliderValue (slider, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider must generate an event",
            m_testEvtHandler->HasSliderValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            slider->GetValue () == value);

    m_testEvtHandler->Init ();

    value = 1;
    WxGuiTestEventSimulationHelper::SetSliderValue (slider, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider must generate an event",
            m_testEvtHandler->HasSliderValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            slider->GetValue () == value);

    m_testEvtHandler->Init ();

    value = 5;
    WxGuiTestEventSimulationHelper::SetSliderValue (slider, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider must generate an event",
            m_testEvtHandler->HasSliderValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            slider->GetValue () == value);

}


void WxGuiTestEventSimulationHelperTest::testSetSpinCtrlValue ()
{
    wxSpinCtrl *spinCtrl = XRCCTRL (*m_testFrame, "SpinCtrl", wxSpinCtrl);
    CPPUNIT_ASSERT_MESSAGE ("No spintCtrl to test!", spinCtrl);

    unsigned int value = 10;
    WxGuiTestEventSimulationHelper::SetSpinCtrlValue (spinCtrl, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of spintCtrl must generate an event",
            m_testEvtHandler->HasSpinCtrlValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            spinCtrl->GetValue () == value);

    m_testEvtHandler->Init ();

    value = 1;
    WxGuiTestEventSimulationHelper::SetSpinCtrlValue (spinCtrl, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider checking must generate an event",
            m_testEvtHandler->HasSpinCtrlValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            spinCtrl->GetValue () == value);

    m_testEvtHandler->Init ();

    value = 5;
    WxGuiTestEventSimulationHelper::SetSpinCtrlValue (spinCtrl, value);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider checking must generate an event",
            m_testEvtHandler->HasSpinCtrlValChgProcessed ());
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of slider selection failed",
            spinCtrl->GetValue () == value);

}


void WxGuiTestEventSimulationHelperTest::testToggleTool ()
{
    WxGuiTestEventSimulationHelper::ToggleToolOnlyEvent (XRCID ("Tool"), true, m_testFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Event simulation of tool toggling failed",
            m_testEvtHandler->HasToolTogglingProcessed ());
}


void WxGuiTestEventSimulationHelperTest::testToggleCheckableTool ()
{
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxToolBar* wxtoolbar = topFrame->GetToolBar();
    CPPUNIT_ASSERT_MESSAGE ("Toolbar 'wxtoolbar' not found", wxtoolbar != 
            NULL);
    WxGuiTestEventSimulationHelper::ToggleTool (XRCID ("ToggleTool"), true, wxtoolbar, topFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Checkable tool should be toggled on",
            wxtoolbar->GetToolState(XRCID ("ToggleTool")));
    CPPUNIT_ASSERT_MESSAGE ("Event simulation of checkable tool toggling failed",
            m_testEvtHandler->HasCheckableToolTogglingProcessed ());

    m_testEvtHandler->Init ();

    WxGuiTestEventSimulationHelper::ToggleTool (XRCID ("ToggleTool"), false, wxtoolbar, m_testFrame);
    WxGuiTestHelper::FlushEventQueue ();

    CPPUNIT_ASSERT_MESSAGE ("Checkable tool should be toggled off",
            !wxtoolbar->GetToolState(XRCID ("ToggleTool")));
}


