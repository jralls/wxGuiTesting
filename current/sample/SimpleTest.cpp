///////////////////////////////////////////////////////////////////////////////
// Name:        sample/SimpleTest.cpp
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "SimpleTest.h"
#endif

#include "SimpleTest.h"

#include <wx/xrc/xmlres.h>
#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/EventSimulationHelper.h>
#include <wxGuiTest/ModalDialogTimer.h>
#include <wxGuiTest/TempInteractive.h>

#ifdef __WXGTK__
#define MC "_"
#else
#define MC _T("&")
#endif


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( SimpleTest, "WxGuiTest" );

SimpleTest::SimpleTest() {
}
SimpleTest::~SimpleTest() { 
}

void SimpleTest::setUp ()
{
//    MyApp app;
//    MyFrame* frame = app.init();
//     wxWindow* frame = wxTheApp->GetTopWindow();
//     MyChild* childFrame = new MyChild(frame, _T("Test Child Window"));
//     childFrame->Activate();
    
//     wxTst::WxGuiTestHelper::Show (frame, true, false);
//     wxTst::WxGuiTestHelper::FlushEventQueue ();
}


void SimpleTest::tearDown () {
//     MyFrame* frame = dynamic_cast<MyFrame*>(wxTheApp->GetTopWindow());
//     wxASSERT_MSG(frame != NULL, _T("Top Window isn't a MyFrame"));
//     MyChild* childFrame = dynamic_cast<MyChild*>(frame->GetActiveChild());
//     wxASSERT_MSG(childFrame != NULL, _T("Active Child not a MyChild"));
//     childFrame->Destroy();
//     wxTheApp->SetTopWindow (NULL);
//     frame->Destroy(); 
//     wxTst::WxGuiTestHelper::FlushEventQueue();
}


void SimpleTest::testExample ()
{
    wxApp *app = wxTst::WxGuiTestApp::GetInstance ();

    wxLogDebug(_T("Application Name is %s"), wxTheApp->GetAppName().c_str());
    CPPUNIT_ASSERT_MESSAGE ("Application name is wrong",
            wxTheApp->GetAppName () == _("xrcdemo_test"));

    // Show current GUI:
    wxTst::WxGuiTestHelper::BreakTestToShowCurrentGui ();
}

void SimpleTest::testTrivial() {
    wxTst::TempInteractive interactive;
    wxTst::ModalDialogTimer timer(wxID_OK);
   // *** Loop up top level containers ***
    CPPUNIT_ASSERT_MESSAGE ("Application top window invalid", 
			    wxTheApp->GetTopWindow () != NULL);
    wxMDIParentFrame *topFrame = 
	dynamic_cast< wxMDIParentFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not an MDI Parent frame", 
			    topFrame != NULL);
    wxMenuBar *menuBar = topFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);

//    interactive.ShowCurrentGui (_T(__FILE__), __LINE__);

    // *** Check menu item ***
    int platformMenuItemId = menuBar->FindMenuItem (_("Advanced"), 
            MC _T("Platform Specific Example"));
    CPPUNIT_ASSERT_MESSAGE ("Menu item ID 'platformMenuItem' not found",
            platformMenuItemId != wxNOT_FOUND);
    wxMenuItem *platformMenuItem = menuBar->FindItem (
            platformMenuItemId);
    CPPUNIT_ASSERT_MESSAGE ("Menu item 'platformMenuItem' not found",
            platformMenuItem != NULL);
    wxTst::EventSimulationHelper::SelectMenuItem (
            platformMenuItemId, topFrame);
    wxTst::WxGuiTestHelper::FlushEventQueue ();
    wxWindow* wdw = topFrame->FindWindow(_T("platform_child"));
    if (wdw == NULL)
	wdw = wxWindow::FindWindowByName(_T("platform_child"));
    CPPUNIT_ASSERT_MESSAGE("First Child not found", wdw != NULL);
    wxMDIChildFrame* child1 = dynamic_cast<wxMDIChildFrame*>(wdw);
    CPPUNIT_ASSERT_MESSAGE("Window isn't an MDI Child", child1 != NULL);
    wxTst::WxGuiTestHelper::FlushEventQueue ();
    interactive.ShowCurrentGui (_T(__FILE__), __LINE__);

    wxTst::EventSimulationHelper::SelectMenuItem (
            platformMenuItemId, topFrame);
    wxTst::WxGuiTestHelper::FlushEventQueue ();

//    interactive.ShowCurrentGui (_T(__FILE__), __LINE__);

    wxMDIChildFrame* child2 = topFrame->GetActiveChild();
    CPPUNIT_ASSERT_MESSAGE("Second child not found", child2 != NULL);
    CPPUNIT_ASSERT_MESSAGE("Second child same as first ", child2 != child1);

    child2->Close();

    int derived_toolMenuItemId = menuBar->FindMenuItem (_("Advanced"),
            MC _T("Custom Class Example"));
    CPPUNIT_ASSERT_MESSAGE ("Menu item ID 'derived_toolMenuItem' not found",
            derived_toolMenuItemId != wxNOT_FOUND);
    wxMenuItem *derived_toolMenuItem = menuBar->FindItem (
            derived_toolMenuItemId);
    CPPUNIT_ASSERT_MESSAGE ("Menu item 'derived_toolMenuItem' not found",
            derived_toolMenuItem != NULL);
    wxTst::EventSimulationHelper::SelectMenuItem (
            derived_toolMenuItemId, topFrame);
    wxTst::WxGuiTestHelper::FlushEventQueue ();

     wxWindow *custom_child = 
	 wxWindow::FindWindowByName (_T("custom_class_child"));
     CPPUNIT_ASSERT_MESSAGE ("Container window for button 'wxID_OK' not found", 
 			    custom_child != NULL);
//    interactive.ShowCurrentGui (_T(__FILE__), __LINE__);
    wxWindow *wxID_OKWdw4 = custom_child->FindWindow (XRCID("wxID_OK"));
    CPPUNIT_ASSERT_MESSAGE ("Window for button 'wxID_OK' not found", 
            wxID_OKWdw4 != NULL);
    wxTst::EventSimulationHelper::ClickButton (wxID_OKWdw4->GetId (), 
            wxID_OKWdw4);
    wxTst::WxGuiTestHelper::FlushEventQueue ();
    CPPUNIT_ASSERT_MESSAGE("OK Button didn't hide Mac Specific Dialog",
			   custom_child->IsShown() == false);




}
