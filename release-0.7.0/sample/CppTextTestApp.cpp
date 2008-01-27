///////////////////////////////////////////////////////////////////////////////
// Name:        CppTextTestApp.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

// For checking wxGuiTestCallTrace, see below:
//#include "wx/log.h"

#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/CppUnitWarningAsserter.h>
#include <wxGuiTest/InitWxGuiTest.h>

#ifdef __WXGTK__
#define OUTPUT std::cout
#else
#define OUTPUT std::cerr
#endif

#include "xrcdemo.h"

int main (int argc, char* argv[])
{
    //wxLog::AddTraceMask (_T("wxGuiTestCallTrace"));

    // Configure unit testing:
    wxTst::WxGuiTestHelper::SetShowModalDialogsNonModalFlag (true);
    wxTst::WxGuiTestHelper::SetShowPopupMenusFlag (false);
    // Disable interactivity for really running automatic tests:
    //wxTst::WxGuiTestHelper::SetDisableTestInteractivity (true);
    // Likewise, prevent pop-up warning message box on failing assertions:
    //wxTst::WxGuiTestHelper::SetPopupWarningForFailingAssert (false);
    // But do check provoked warnings in testing mode:
	wxTst::WxGuiTestHelper::SetCheckForProvokedWarnings (true);
    // Which requires the correct CppUnit warning asserter:
    wxTst::WxGuiTestHelper::SetWarningAsserter (
            new wxTst::CppUnitWarningAsserter ());

    // Record wxVtk interaction:
    //wxTst::VtkWxGuiTestHelper::SetUseWxVtkInteractionRecording (true);

    // Create AUT:
    MyApp* myApp = new MyApp ();
    
    // wxTst::InitWxGuiTest, which "packs" all registered wxWidgets GUI tests
    // into decorated shape, must not use CPPUNIT_TEST_SUITE_REGISTRATION macro
    // when WxGuiTesting is built as an independent and reusable library.
    // Thus, in order to use the remaining standard infrastructure, we create a
    // new test suite named equal to the usual top level registry or suite name
    // "All Tests". Then all registered wxGui tests are added to it by means of
    // directly using InitWxGuiTest class:
    CPPUNIT_NS::TestSuite *suite = new CPPUNIT_NS::TestSuite ("All Tests");
    suite->addTest (wxTst::InitWxGuiTest::suite ());

    // Adds the test to the list of test to run
    CPPUNIT_NS::TextUi::TestRunner runner;
    runner.addTest (suite);

    // Change the default outputter to a compiler error format outputter
     runner.setOutputter (new CPPUNIT_NS::CompilerOutputter (&runner.result (),
             OUTPUT));

    // Run the test - don't close window in debug mode at the end
    bool wasSucessful = runner.run ();

    // Return error code 1 if the one of test failed.
    return wasSucessful ? 0 : 1;
}
