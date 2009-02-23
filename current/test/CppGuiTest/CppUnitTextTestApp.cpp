///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/CppTextTestApp.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2009
// Modifications Copyright: (c) 2009 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

// For checking wxGuiTestCallTrace, see below:
//#include "wx/log.h"
#include <wx/cmdline.h>

#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/CppUnitWarningAsserter.h>
#include <wxGuiTest/InitWxGuiTest.h>
#ifdef __WXGTK__
#define OUTPUT std::cout
#else
#define OUTPUT std::cerr
#endif
namespace {
static const wxCmdLineEntryDesc l_cmdLineDesc[] =
{
    { wxCMD_LINE_SWITCH, _T("i"), _T("interactive"), _T("Allows the test to stop for user interaction") },
    { wxCMD_LINE_SWITCH, _T("w"), _T("warnings"), _T("Prevent popup warnings for failing wx assertions") },
    { wxCMD_LINE_SWITCH, _T("r"), _T("provoked"), _T("Check for provoked warnings") },
    { wxCMD_LINE_SWITCH, _T("m"), _T("dialognonmodal"), _T("Show specially written modal dialogs non modal") },
    { wxCMD_LINE_SWITCH, _T("p"), _T("popups"), _T("Show popup menus") },
    { wxCMD_LINE_OPTION, _T("t"), _T("trace"), _T("Log Trace Mask") },
    { wxCMD_LINE_NONE }
};
}

int main (int argc, char** argv)
{
    wxCmdLineParser parser(l_cmdLineDesc, argc, argv);
    int res = parser.Parse(false);
    if (res > 0) {
	OUTPUT << "Failed to parse the command line" << std::endl;
	exit(-1);
    }
    wxString mask;
    while (parser.Found(_T("t"), &mask))
	if (mask.empty())
	    wxLog::AddTraceMask(_T("wxGuiTestCallTrace"));
	else
	    wxLog::AddTraceMask (mask);

    // Configure unit testing:
    if (parser.Found(_T("m")))
	wxTst::WxGuiTestHelper::SetShowModalDialogsNonModalFlag (true);
    else
	wxTst::WxGuiTestHelper::SetShowModalDialogsNonModalFlag (false);
    if (parser.Found(_T("p")))
	wxTst::WxGuiTestHelper::SetShowPopupMenusFlag (true);
    else
	wxTst::WxGuiTestHelper::SetShowPopupMenusFlag (false);

    // Disable interactivity for really running automatic tests:
    if (parser.Found(_T("i")))
	wxTst::WxGuiTestHelper::SetDisableTestInteractivity (true);
    else
	wxTst::WxGuiTestHelper::SetDisableTestInteractivity (false);


    // Likewise, prevent pop-up warning message box on failing assertions:
    if (parser.Found(_T("w")))
	wxTst::WxGuiTestHelper::SetPopupWarningForFailingAssert (true);
    else
	wxTst::WxGuiTestHelper::SetPopupWarningForFailingAssert (false);

    // But do check provoked warnings in testing mode:
    if (parser.Found(_T("r"))) {
	wxTst::WxGuiTestHelper::SetCheckForProvokedWarnings (true);
    // Which requires the correct CppUnit warning asserter:
	wxTst::WxGuiTestHelper::SetWarningAsserter (
            new wxTst::CppUnitWarningAsserter ());
    }
    else {
	wxTst::WxGuiTestHelper::SetCheckForProvokedWarnings (false);
	wxTst::WxGuiTestHelper::SetWarningAsserter (NULL);
    }

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
