///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/SimpleCRTest.cpp
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "ReplayTest.h"
#endif

#include "ReplayTest.h"

#include <wx/notebook.h>
#include <wx/xrc/xmlres.h>

#include <wxGuiTest/swWxGuiTestHelper.h>
#include <wxGuiTest/swWxGuiTestEventSimulationHelper.h>
#include <wxGuiTest/swWxGuiTestTimedDialogEnder.h>
#include <wxGuiTest/swWxGuiTestTempInteractive.h>

#include <wxGuiTest/swCRCapture.h>

#include "xrcdemo.h"
#include "myframe.h"
namespace {
    const wxString xrcDir(_T(XRCDIR));
}

#ifdef __WXGTK__
#define MC "_"
#else
#define MC _T("&")
#endif


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( ReplayTest, "WxGuiTest" );


void ReplayTest::setUp ()
{
//    MyApp app;
//    MyFrame* myFrame = app.init();
//    wxTheApp->SetTopWindow(myFrame);
//     wxWindow* myFrame = wxTheApp->GetTopWindow();
//     swTst::WxGuiTestHelper::Show (myFrame, true, false);
//     swTst::WxGuiTestHelper::FlushEventQueue ();

}


void ReplayTest::tearDown ()
{

//     wxWindow *topWdw = wxTheApp->GetTopWindow ();
//     wxTheApp->SetTopWindow (NULL);
//     topWdw->Destroy();
}


void ReplayTest::testDialog ()
{
    swTst::WxGuiTestTempInteractive interactive;

    // Do bootstrap capturing:
    // Dialog
    CPPUNIT_ASSERT_MESSAGE ("Application top window invalid", wxTheApp->
            GetTopWindow () != NULL);
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxMenuBar *menuBar = topFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);
    int derivedDialogExampleMenuItemId = menuBar->FindMenuItem (_("Basic"), 
            MC _T("Derived Dialog Example"));
    CPPUNIT_ASSERT_MESSAGE ("Menu item ID '&Derived Dialog Example' not found", 
            derivedDialogExampleMenuItemId != wxNOT_FOUND);
    swTst::WxGuiTestEventSimulationHelper::SelectMenuItem (
            derivedDialogExampleMenuItemId, topFrame);
    swTst::WxGuiTestHelper::FlushEventQueue ();

 //    wxWindow *derived_dialog = wxWindow::FindWindowByName (_T("derived_dialog"));
     wxWindow *derived_dialog = topFrame->FindWindow (_T("derived_dialog"));
   CPPUNIT_ASSERT_MESSAGE ("Container window for button 'my_button' not found",
             derived_dialog != NULL);
    wxWindow *my_buttonWdw = derived_dialog->FindWindow (XRCID("my_button"));
    CPPUNIT_ASSERT_MESSAGE ("Window for button 'my_button' not found", 
            my_buttonWdw != NULL);
    swTst::WxGuiTestEventSimulationHelper::ClickButton (my_buttonWdw->GetId (), 
            my_buttonWdw);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    wxWindow *my_checkboxWdw = derived_dialog->FindWindow (XRCID(
            "my_checkbox"));
    CPPUNIT_ASSERT_MESSAGE ("Window for check box 'my_checkbox' not found", 
            my_checkboxWdw != NULL);
    wxCheckBox *my_checkbox = wxDynamicCast (my_checkboxWdw, wxCheckBox);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for check box 'my_checkbox' "
            "failed", my_checkbox != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetCheckboxState (my_checkbox, true);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    wxWindow *my_textctrlWdw = derived_dialog->FindWindow (XRCID(
            "my_textctrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for text control 'my_textctrl' not found", 
            my_textctrlWdw != NULL);
    wxTextCtrl *my_textctrl = wxDynamicCast (my_textctrlWdw, wxTextCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for text control 'my_textctrl' "
            "failed", my_textctrl != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetTextCtrlValue (my_textctrl, _T(
            "foo"));
    swTst::WxGuiTestHelper::FlushEventQueue ();

//     wxWindow *art_provider_dialog = wxWindow::FindWindowByName (_T(
//             "art_provider_dialog"));
//     CPPUNIT_ASSERT_MESSAGE ("Container window for button 'wxID_OK' not found", 
//             art_provider_dialog != NULL);
     wxWindow *wxID_OKWdw = derived_dialog->FindWindow (XRCID("wxID_OK"));
     CPPUNIT_ASSERT_MESSAGE ("Window for button 'wxID_OK' not found", wxID_OKWdw 
             != NULL);
     swTst::WxGuiTestEventSimulationHelper::ClickButton (wxID_OKWdw->GetId (), 
             wxID_OKWdw);
     swTst::WxGuiTestHelper::FlushEventQueue ();
    CPPUNIT_ASSERT_MESSAGE("OK Button didn't hide Derived Dialog",
			   derived_dialog->IsShown() == false);
//     derived_dialog->Destroy();
//     art_provider_dialog->Destroy();
}
    // Uncentered
void ReplayTest::testUncentered() {
    CPPUNIT_ASSERT_MESSAGE ("Application top window invalid", wxTheApp->
            GetTopWindow () != NULL);
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxMenuBar *menuBar = topFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);
    int uncenteredExampleMenuItemId = menuBar->FindMenuItem (_("Basic"), 
            MC _T("Uncentered Example"));
    CPPUNIT_ASSERT_MESSAGE ("Menu item ID '&Uncentered Example' not found", 
            uncenteredExampleMenuItemId != wxNOT_FOUND);
    swTst::WxGuiTestEventSimulationHelper::SelectMenuItem (
            uncenteredExampleMenuItemId, topFrame);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    wxWindow *uncentered_dialog = wxWindow::FindWindowByName (_T(
            "uncentered_dialog"));
    CPPUNIT_ASSERT_MESSAGE ("Container window for button 'wxID_OK' not found", 
            uncentered_dialog != NULL);
    wxWindow *wxID_OKWdw1 = uncentered_dialog->FindWindow (XRCID("wxID_OK"));
    CPPUNIT_ASSERT_MESSAGE ("Window for button 'wxID_OK' not found", 
            wxID_OKWdw1 != NULL);
    swTst::WxGuiTestEventSimulationHelper::ClickButton (wxID_OKWdw1->GetId (), 
            wxID_OKWdw1);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    CPPUNIT_ASSERT_MESSAGE("OK Button didn't hide Uncentered Dialog",
			   uncentered_dialog->IsShown() == false);
//     uncentered_dialog->Destroy();
}
    // Art Provider
void ReplayTest::testArtProvider() {
    CPPUNIT_ASSERT_MESSAGE ("Application top window invalid", wxTheApp->
            GetTopWindow () != NULL);
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxMenuBar *menuBar = topFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);
    int wxArtProviderExampleMenuItemId = menuBar->FindMenuItem (_("Advanced"), 
            _T("wx") MC _T("ArtProvider Example"));
    CPPUNIT_ASSERT_MESSAGE ("Menu item ID 'wx&ArtProvider Example' not found", 
            wxArtProviderExampleMenuItemId != wxNOT_FOUND);
    swTst::WxGuiTestEventSimulationHelper::SelectMenuItem (
            wxArtProviderExampleMenuItemId, topFrame);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    wxWindow *art_provider_dialog = wxWindow::FindWindowByName (_T(
            "art_provider_dialog"));
    CPPUNIT_ASSERT_MESSAGE ("Container window for button 'wxID_OK' not found", 
            art_provider_dialog != NULL);
    wxWindow *dont_show_checkboxWdw = art_provider_dialog->FindWindow (XRCID(
            "dont_show_checkbox"));
    CPPUNIT_ASSERT_MESSAGE ("Window for check box 'dont_show_checkbox' not "
            "found", dont_show_checkboxWdw != NULL);
    wxCheckBox *dont_show_checkbox = wxDynamicCast (dont_show_checkboxWdw, 
            wxCheckBox);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for check box "
            "'dont_show_checkbox' failed", dont_show_checkbox != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetCheckboxState (dont_show_checkbox,
             true);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    wxWindow *wxID_OKWdw2 = art_provider_dialog->FindWindow (XRCID("wxID_OK"));
    CPPUNIT_ASSERT_MESSAGE ("Window for button 'wxID_OK' not found", 
            wxID_OKWdw2 != NULL);
    swTst::WxGuiTestEventSimulationHelper::ClickButton (wxID_OKWdw2->GetId (), 
            wxID_OKWdw2);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    CPPUNIT_ASSERT_MESSAGE("OK Button didn't hide Art Provider Dialog",
			   art_provider_dialog->IsShown() == false);
//    art_provider_dialog->Destroy();
}

// Platform Specific
void ReplayTest::testPlatformSpecific() {
    swTst::WxGuiTestTempInteractive interactive;
    CPPUNIT_ASSERT_MESSAGE ("Application top window invalid", wxTheApp->
            GetTopWindow () != NULL);
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxMenuBar *menuBar = topFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);
    int platformSpecificExampleMenuItemId = menuBar->FindMenuItem (_(
            "Advanced"), MC _T("Platform Specific Example"));
    CPPUNIT_ASSERT_MESSAGE ("Menu item ID '&Platform Specific Example' not "
            "found", platformSpecificExampleMenuItemId != wxNOT_FOUND);
    swTst::WxGuiTestEventSimulationHelper::SelectMenuItem (
            platformSpecificExampleMenuItemId, topFrame);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    wxWindow *platform_notebookWdw = wxWindow::FindWindowByName (_T(
            "platform_notebook"));
    CPPUNIT_ASSERT_MESSAGE ("Container window for notebook 'platform_notebook' "
            "not found", platform_notebookWdw != NULL);
    wxNotebook *platform_notebook = wxDynamicCast (platform_notebookWdw, 
            wxNotebook);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for notebook 'platform_notebook' "
            "failed", platform_notebook != NULL);
    const wxString platform_notebookPageText (_("Shared options"));
    int platform_notebookPage = 0;
    while ((platform_notebookPage < platform_notebook->GetPageCount ()) && (
            platform_notebook->GetPageText (platform_notebookPage) != 
            platform_notebookPageText)) {

        platform_notebookPage++;
    }
    CPPUNIT_ASSERT_MESSAGE ("Page of notebook 'platform_notebook' not found", 
            platform_notebookPage < platform_notebook->GetPageCount ());
    swTst::WxGuiTestEventSimulationHelper::SelectNotebookPage (
            platform_notebook, platform_notebookPage);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    wxWindow *shared_tab = wxWindow::FindWindowByName (_T("shared_tab"));
    CPPUNIT_ASSERT_MESSAGE ("Container window for check box 'shared_checkbox' "
            "not found", shared_tab != NULL);
    wxWindow *shared_checkboxWdw = shared_tab->FindWindow (XRCID(
            "shared_checkbox"));
    CPPUNIT_ASSERT_MESSAGE ("Window for check box 'shared_checkbox' not found", 
            shared_checkboxWdw != NULL);
    wxCheckBox *shared_checkbox = wxDynamicCast (shared_checkboxWdw, 
            wxCheckBox);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for check box 'shared_checkbox' "
            "failed", shared_checkbox != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetCheckboxState (shared_checkbox, 
            true);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    wxNotebook *platform_notebook1 = wxDynamicCast (platform_notebookWdw, 
            wxNotebook);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for notebook 'platform_notebook' "
            "failed", platform_notebook1 != NULL);
    const wxString platform_notebook1PageText (_("Macintosh options"));
    int platform_notebook1Page = 0;
    while ((platform_notebook1Page < platform_notebook1->GetPageCount ()) && (
            platform_notebook1->GetPageText (platform_notebook1Page) != 
            platform_notebook1PageText)) {

        platform_notebook1Page++;
    }
    CPPUNIT_ASSERT_MESSAGE ("Page of notebook 'platform_notebook' not found", 
            platform_notebook1Page < platform_notebook1->GetPageCount ());
    swTst::WxGuiTestEventSimulationHelper::SelectNotebookPage (
            platform_notebook1, platform_notebook1Page);
    swTst::WxGuiTestHelper::FlushEventQueue ();

    wxWindow *mac_specific = wxWindow::FindWindowByName (_T("mac_specific"));
    CPPUNIT_ASSERT_MESSAGE ("Container window for check box 'mac_checkbox' not "
            "found", mac_specific != NULL);
    wxWindow *mac_checkboxWdw = mac_specific->FindWindow (XRCID(
            "mac_checkbox"));
    CPPUNIT_ASSERT_MESSAGE ("Window for check box 'mac_checkbox' not found", 
            mac_checkboxWdw != NULL);
    wxCheckBox *mac_checkbox = wxDynamicCast (mac_checkboxWdw, wxCheckBox);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for check box 'mac_checkbox' "
            "failed", mac_checkbox != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetCheckboxState (mac_checkbox, 
            true);
    swTst::WxGuiTestHelper::FlushEventQueue ();

 //     wxWindow *platform_property_dialog = 
//  	wxWindow::FindWindowByName (_T("platform_child"));
//      CPPUNIT_ASSERT_MESSAGE ("Container window for button 'wxID_OK' not found", 
//  			    platform_property_dialog != NULL);
// //    interactive.ShowCurrentGui (_T(__FILE__), __LINE__);
//     wxWindow *wxID_OKWdw4 = platform_property_dialog->FindWindow (XRCID("wxID_OK"));
//     CPPUNIT_ASSERT_MESSAGE ("Window for button 'wxID_OK' not found", 
//             wxID_OKWdw4 != NULL);
//     swTst::WxGuiTestEventSimulationHelper::ClickButton (wxID_OKWdw4->GetId (), 
//             wxID_OKWdw4);
//     swTst::WxGuiTestHelper::FlushEventQueue ();
//     CPPUNIT_ASSERT_MESSAGE("OK Button didn't hide Mac Specific Dialog",
// 			   platform_property_dialog->IsShown() == false);

}

