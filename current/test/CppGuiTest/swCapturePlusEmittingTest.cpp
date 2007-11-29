/////////////////////////////////////////////////////////////////////////////
// $RCSfile: swCapturePlusEmittingTest.cpp,v $
// Original Author/Owner: reinhold
//
// $Revision: 1.5 $ $Name:  $ $State: Exp $
//
// $Date: 2007/11/21 19:53:04 $ $Author: reinhold $
//
/////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCapturePlusEmittingTest.h"
#endif

#include "swCapturePlusEmittingTest.h"

#include "wx/xrc/xmlres.h"
#include "wx/frame.h"
#include "wx/treectrl.h"

#include "swWxGuiTestHelper.h"
#include "swWxGuiTestEventSimulationHelper.h"
#include "swWxGuiTestTimedDialogEnder.h"
#include "swWxGuiTestTempInteractive.h"

#include "swConfigManager.h"
#include "swConfig.h"

#include "swCREventCaptureManager.h"
#include "swCRCppEmitter.h"

// Only to make C&R demonstrations easier:
#include "wx/notebook.h"
#include "swSpinCtrlDouble.h"
#include "swTreeCtrl.h"

using sw::SpinCtrlDouble;


namespace swTst {


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( CapturePlusEmittingTest, "WxGuiTest" );


const wxString CapturePlusEmittingTest::FILENAME = _T("../../../TestData/OnlyCapture.cpp");
const int CapturePlusEmittingTest::LINE_NMB = 1;

// Macros for easier asserting/self-testing of reproducing capture plus emitting:
#define START int start = __LINE__;
#define END   int end   = __LINE__; \
              checkEmittedCode (_T(__FILE__), start, end);


void CapturePlusEmittingTest::setUp ()
{
    // 1. Setup test application:
    wxXmlResource::Get()->InitAllHandlers();
    wxXmlResource::Get()->Load (_T("../../../TestData/xrc/CaptureTest/EvtSimHlpTest_wdr.xrc"));

    wxFrame *frame = new wxFrame (NULL, -1, _T("EvtSimHlpFrame"));

    wxMenuBar *menuBar = wxXmlResource::Get ()->LoadMenuBar (wxT("MenuBar"));
    wxASSERT (menuBar != NULL);
    frame->SetMenuBar (menuBar);
    
    wxBoxSizer *topsizer = new wxBoxSizer (wxVERTICAL);
    wxPanel *panel = wxXmlResource::Get ()->LoadPanel (frame, 
            _T("EvtSimHlpTestPanel"));
    wxASSERT (panel != NULL);
    sw::SpinCtrlDouble *spinCtrl = new sw::SpinCtrlDouble (
            frame,
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
    WxGuiTestHelper::Show (frame, true, false);
    WxGuiTestHelper::FlushEventQueue ();

    wxString xrcDir = _T("../../../TestData/xrc/CaptureTest/");
    sw::Config *configInit = new sw::Config ();
    configInit->SetResourceDir (xrcDir);
    sw::ConfigManager::SetInstance (configInit);

    // 2. Setup capturing mode:
    getGuiTestApp ()->SetEventFilter (CREventCaptureManager::GetInstance ());

    CRCppEmitter::GetInstance ()->SetTestCaseFileContext (FILENAME, LINE_NMB);
}


void CapturePlusEmittingTest::tearDown ()
{
    // 1. Tear down capturing mode:
    CREventCaptureManager::GetInstance ()->Off ();

    getGuiTestApp ()->SetEventFilter (NULL);
    CRCppEmitter::Destroy ();

    // 2. Tear down test application:
    sw::ConfigManager::SetInstance (NULL);

    wxWindow *topWdw = wxTheApp->GetTopWindow ();
    wxTheApp->SetTopWindow (NULL);
    topWdw->Hide ();
}


void CapturePlusEmittingTest::testSelectAndCheckTopLevelWindowMenuBarMenuItem ()
{
    // Start capturing mode:
    CREventCaptureManager::GetInstance ()->On ();

    // Simulate event + check emitted code (END macro):
    START
    CPPUNIT_ASSERT_MESSAGE ("Application top window invalid", wxTheApp->
            GetTopWindow () != NULL);
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxMenuBar *menuBar = topFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);
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
    swTst::WxGuiTestEventSimulationHelper::SelectAndCheckMenuItem (
            checkableMenuItemMenuItemId, topFrame);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    END
}


void CapturePlusEmittingTest::testSelectAndCheckTopLevelWindowMenuBarMenuItem2 ()
{
    // Start capturing mode:
    CREventCaptureManager::GetInstance ()->On ();

    // Simulate event + check emitted code (END macro):
    START
    CPPUNIT_ASSERT_MESSAGE ("Application top window invalid", wxTheApp->
            GetTopWindow () != NULL);
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxMenuBar *menuBar = topFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);
    int checkableMenuItemMenuItemId = menuBar->FindMenuItem (_("Menu"), _(
            "CheckableMenuItem"));
    CPPUNIT_ASSERT_MESSAGE ("Menu item ID 'CheckableMenuItem' not found", 
            checkableMenuItemMenuItemId != wxNOT_FOUND);
    wxMenu *menuMenu;
    wxMenuItem *checkableMenuItemMenuItem = menuBar->FindItem (
            checkableMenuItemMenuItemId, &menuMenu);
    CPPUNIT_ASSERT_MESSAGE ("Menu item 'CheckableMenuItem' not found", 
            checkableMenuItemMenuItem != NULL);
    CPPUNIT_ASSERT_MESSAGE ("Menu for menu item 'CheckableMenuItem' not found", 
            menuMenu != NULL);
    // Check if checkable menu item is not already checked?
    // if (!checkableMenuItemMenuItem->IsChecked ()) { ...
    swTst::WxGuiTestEventSimulationHelper::SelectAndCheckMenuItem (
            checkableMenuItemMenuItemId, menuMenu);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    END
}


WxGuiTestApp * CapturePlusEmittingTest::getGuiTestApp ()
{
    wxApp *app = wxTheApp;
    wxASSERT (app != NULL);
    WxGuiTestApp *guiTestApp = dynamic_cast< WxGuiTestApp * >(app);
    wxASSERT (guiTestApp != NULL);

    return guiTestApp;
}


void CapturePlusEmittingTest::checkEmittedCode(const wxString &expectedFilename,
        int startLineNmb, int endLineNmb) const
{
    wxTextFile expFile, newFile;
    CPPUNIT_ASSERT_MESSAGE ("Could not open expected (test case) file",
            expFile.Open (expectedFilename));
    CPPUNIT_ASSERT_MESSAGE ("Could not open captured file",
            newFile.Open (CRCppEmitter::GetInstance()->GetCaptureFilename()));

    // Note: There may be empty lines at end of emitted code!
    int i = 0;
    while ((startLineNmb + i) < expFile.GetLineCount () &&
            i < (endLineNmb - 1 - startLineNmb) &&
            i < newFile.GetLineCount ()) {

        wxString expLine = expFile.GetLine (startLineNmb + i);
        wxString newLine = newFile.GetLine (i);
        CPPUNIT_ASSERT_EQUAL_MESSAGE ("Expected emitted code is wrong",
                expLine, newLine);
        i++;
    }
}

} // End namespace swTst
