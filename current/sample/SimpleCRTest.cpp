///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/SimpleCRTest.cpp
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "SimpleCRTest.h"
#endif

#include "SimpleCRTest.h"

#include <wx/xrc/xmlres.h>
#include <wx/frame.h>
#include <wx/treectrl.h>

#include <wxGuiTest/swWxGuiTestHelper.h>
#include <wxGuiTest/swWxGuiTestEventSimulationHelper.h>
#include <wxGuiTest/swWxGuiTestTimedDialogEnder.h>
#include <wxGuiTest/swWxGuiTestTempInteractive.h>

#include <wxGuiTest/swCRCapture.h>

#include <wxGuiTest/Config/swConfigManager.h>
#include <wxGuiTest/Config/swConfig.h>

#include <wxGuiTest/Widget/swSpinCtrlDouble.h>

using sw::SpinCtrlDouble;

namespace {
    const wxString xrcDir(_T(XRCDIR));
}


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( SimpleCRTest, "WxGuiTest" );


void SimpleCRTest::setUp ()
{
    wxXmlResource::Get()->InitAllHandlers();
    wxXmlResource::Get()->Load (xrcDir + wxString(_T("/EvtSimHlpTest_wdr.xrc")));

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

    // For C&R:
    sw::Config *configInit = new sw::Config ();
    configInit->SetResourceDir (xrcDir);
    sw::ConfigManager::SetInstance (configInit);
}


void SimpleCRTest::tearDown ()
{
    sw::ConfigManager::SetInstance (NULL);

    wxWindow *topWdw = wxTheApp->GetTopWindow ();
    wxTheApp->SetTopWindow (NULL);
    topWdw->Hide ();
}


void SimpleCRTest::testCapture ()
{
    swTst::WxGuiTestTempInteractive interactive;

    // Do bootstrap capturing:
    CAPTURE
}
