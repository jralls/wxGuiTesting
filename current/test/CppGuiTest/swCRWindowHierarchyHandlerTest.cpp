///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swCRWindowHierarchyHandlerTest.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRWindowHierarchyHandlerTest.h"
#endif

#include "swCRWindowHierarchyHandlerTest.h"

#include <wx/xrc/xmlres.h>

#include <wxGuiTest/swWxGuiTestHelper.h>
#include <wxGuiTest/swWxGuiTestTempInteractive.h>

#include <wxGuiTest/Config/swConfigManager.h>
#include <wxGuiTest/Config/swConfig.h>
#include <wxGuiTest/Config/swCRWindowHierarchyHandler.h>
#include <wxGuiTest/swCRXRCNode.h>

namespace swTst {


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( CRWindowHierarchyHandlerTest, "WxGuiTest" );


void CRWindowHierarchyHandlerTest::setUp ()
{
    const wxString xrcDir = _T(XRCDIR);
    sw::Config *config = new sw::Config ();
    config->SetResourceDir (xrcDir);
    sw::ConfigManager::SetInstance (config);

    wxXmlResource::Get()->InitAllHandlers ();
    wxXmlResource::Get()->Load (xrcDir + _T("/CapturePanel_wdr.xrc"));
    wxXmlResource::Get()->Load (xrcDir + _T("/xrc_two_object_nodes.xrc"));
}


void CRWindowHierarchyHandlerTest::tearDown ()
{
    sw::ConfigManager::SetInstance (NULL);
}


void CRWindowHierarchyHandlerTest::testFindXRCNode ()
{
    wxDialog dialog (NULL, -1, _T("CRWindowHierarchyHandlerTest Dialog"),
            wxDefaultPosition);
#ifndef __WXGTK__
    WxGuiTestHelper::FlushEventQueue ();
#endif

    wxPanel *panel = wxXmlResource::Get ()->LoadPanel (&dialog, _T("CapturePanel"));
    CPPUNIT_ASSERT_MESSAGE ("Loading test panel failed", panel != NULL);
    wxButton *button = XRCCTRL (*panel, "ExitButton", wxButton);
    CPPUNIT_ASSERT_MESSAGE ("Test button not found", button != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    CRXRCNode *btnNode = hierarchy->FindXRCNode (button);
    CPPUNIT_ASSERT_MESSAGE ("Find button window failed", btnNode != NULL);

    CPPUNIT_ASSERT_MESSAGE ("Find button window failed (name)",
            button->GetName () == btnNode->GetName ());
    CPPUNIT_ASSERT_MESSAGE ("Find button window failed (class)",
            _T("wxButton") == btnNode->GetClass ());
}


void CRWindowHierarchyHandlerTest::testFindWindowContainer ()
{
    wxDialog dialog (NULL, -1, _T("CRWindowHierarchyHandlerTest Dialog"),
            wxDefaultPosition);
#ifndef __WXGTK__
    WxGuiTestHelper::FlushEventQueue ();
#endif

    wxPanel *panel = wxXmlResource::Get ()->LoadPanel (&dialog, _T("CapturePanel"));
    CPPUNIT_ASSERT_MESSAGE ("Loading test panel failed", panel != NULL);
    wxButton *button = XRCCTRL (*panel, "ExitButton", wxButton);
    CPPUNIT_ASSERT_MESSAGE ("Test button not found", button != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    CRXRCNode *btnContNode = hierarchy->FindContainerXRCNode (button);
    CPPUNIT_ASSERT_MESSAGE ("Find button window container failed", btnContNode != NULL);

    CPPUNIT_ASSERT_MESSAGE ("Find button window container failed (name)",
            panel->GetName () == btnContNode->GetName ());
    CPPUNIT_ASSERT_MESSAGE ("Find button window container failed (class)",
            _T("wxPanel") == btnContNode->GetClass ());
}


void CRWindowHierarchyHandlerTest::testFindWindowContainerName ()
{
    wxDialog dialog (NULL, -1, _T("CRWindowHierarchyHandlerTest Dialog"),
            wxDefaultPosition);
#ifndef __WXGTK__
    WxGuiTestHelper::FlushEventQueue ();
#endif

    wxSizer *topSizer = new wxBoxSizer (wxVERTICAL);
    wxPanel *upperPanel = new wxPanel (&dialog);
    upperPanel->SetName (_T("UpperPanel"));
    // XRC panel and button:
    wxPanel *panel = wxXmlResource::Get ()->LoadPanel (upperPanel, _T("CapturePanel"));
    CPPUNIT_ASSERT_MESSAGE ("Loading test panel failed", panel != NULL);
    wxButton *button = XRCCTRL (*panel, "ExitButton", wxButton);
    CPPUNIT_ASSERT_MESSAGE ("Test button not found", button != NULL);
    // "Manual panel and button:
    wxPanel *panel2 = new wxPanel (&dialog);
    panel2->SetName (_T("NonXRCPanel"));
    wxButton *button2 = new wxButton (panel2, -1, _T("Button2"));//, wxDefaultPosition
    button2->SetName (_T("NonXRCButton"));
    wxSizer *sizer = new wxBoxSizer (wxVERTICAL);
    sizer->Add (button2);
    panel2->SetSizer (sizer);
    // Finish dialog creation:
    topSizer->Add (upperPanel, 0, wxEXPAND| wxALL | wxGROW | wxADJUST_MINSIZE );
    topSizer->Add (panel2, 0, wxEXPAND| wxALL | wxGROW | wxADJUST_MINSIZE );
    dialog.SetSizer (topSizer);
    topSizer->SetSizeHints (&dialog);
    //dialog.Show ();
    //Tst::WxGuiTestTempInteractive interactive;
    //interactive.ShowCurrentGui ();

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    
    wxString btnContName = hierarchy->FindContainerName (button);
    CPPUNIT_ASSERT_MESSAGE ("Find button window container name failed",
            !btnContName.IsEmpty ());
    CPPUNIT_ASSERT_MESSAGE ("Find button window container returned wrong name",
            panel->GetName () == btnContName);

    wxString btnContName2 = hierarchy->FindContainerName (button2);
    CPPUNIT_ASSERT_MESSAGE ("Find button window container name failed (non XRC)",
            !btnContName2.IsEmpty ());
    CPPUNIT_ASSERT_MESSAGE ("Find button window container returned wrong name (non XRC)",
            panel2->GetName () == btnContName2);
}

} // End namespace swTst

