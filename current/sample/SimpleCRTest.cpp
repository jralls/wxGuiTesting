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

#include <wxGuiTest/swWxGuiTestHelper.h>
#include <wxGuiTest/swWxGuiTestEventSimulationHelper.h>
#include <wxGuiTest/swWxGuiTestTimedDialogEnder.h>
#include <wxGuiTest/swWxGuiTestTempInteractive.h>

#include <wxGuiTest/swCRCapture.h>

#include <wxGuiTest/Config/swConfigManager.h>
#include <wxGuiTest/Config/swConfig.h>

#include "xrcdemo.h"
#include "myframe.h"
namespace {
    const wxString xrcDir(_T(XRCDIR));
}


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( SimpleCRTest, "WxGuiTest" );


void SimpleCRTest::setUp ()
{
//    MyApp app;
//    MyFrame* myFrame = app.init();
//    wxTheApp->SetTopWindow(myFrame);
//     wxWindow* myFrame = wxTheApp->GetTopWindow();
//     swTst::WxGuiTestHelper::Show (myFrame, true, false);
//     swTst::WxGuiTestHelper::FlushEventQueue ();

//     // For C&R:
    sw::Config *configInit = new sw::Config ();
    configInit->SetResourceDir (xrcDir);
    sw::ConfigManager::SetInstance (configInit);
}


void SimpleCRTest::tearDown ()
{
     sw::ConfigManager::SetInstance (NULL);

//     wxWindow *topWdw = wxTheApp->GetTopWindow ();
//     wxTheApp->SetTopWindow (NULL);
//     topWdw->Destroy();
}


void SimpleCRTest::testCapture ()
{
    swTst::WxGuiTestTempInteractive interactive;

    // Do bootstrap capturing:
    CAPTURE
}
