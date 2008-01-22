///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/InitWxGuiTestSetUp.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "InitWxGuiTestSetUp.h"
#endif

#include "InitWxGuiTestSetUp.h"
#include <wxGuiTest/GuiTestApp.h>

// Declaration for wxWidgets GUI initialisation:
#ifdef WIN32
    extern int wxEntry (HINSTANCE hInstance, HINSTANCE hPrevInstance,
            char *pCmdLine, int nCmdShow);
#endif


namespace wxTst {


InitWxGuiTestSetUp::InitWxGuiTestSetUp (CPPUNIT_NS::Test *test) :
TestSetUp (test)
{
    m_result = NULL;
}


InitWxGuiTestSetUp::~InitWxGuiTestSetUp ()
{
    // m_result is deleted elsewhere
}


void InitWxGuiTestSetUp::run (CPPUNIT_NS::TestResult *result)
{
    ::wxLogTrace (_T("wxGuiTestCallTrace"), 
            _T("void InitWxGuiTestSetUp::run (CPPUNIT_NS::TestResult *result)"));

    // Store result for latter call (direct or indirect) from
    // WxGuiTestApp::OnRun() allowing us to make up for call of
    // TestDecorator::run(result):
    m_result = result;

    this->setUp ();
    // Do NOT call because flow of control must be diverted:
    //TestDecorator::run (result);
    this->tearDown ();
}


void InitWxGuiTestSetUp::RunAsDecorator ()
{
    ::wxLogTrace (_T("wxGuiTestCallTrace"), 
            _T("void InitWxGuiTestSetUp::RunAsDecorator ()"));

    TestDecorator::run (m_result);
}


void InitWxGuiTestSetUp::setUp ()
{
    ::wxLogTrace (_T("wxGuiTestCallTrace"),
            _T("void InitWxGuiTestSetUp::setUp ()"));

    // If there would be additional non GUI test cases/suites requiring the
    // initialisation of an PseudoApp instance beforehand, it would be
    // necessary to "clear/uninitialise/replace" this singleton instance. In
    // fact, this is the case for wxAppGuiTesting:
    //   There is already an App instance which is supposed to be the real
    // application under test (AUT). Otherwise "only" wxGuiTesting should
    // carried out:
    wxApp *app = WxGuiTestApp::GetInstance ();
    if (app != NULL) {

        WxGuiTestApp::Nullify ();
    }

    WxGuiTestApp *wxGuiTestApp = new WxGuiTestApp (app);
    // This is not really necessary, as done automatically by code from the
    // macro expansion; but it improves understanding:
    wxApp::SetInstance (wxGuiTestApp);
    // And re-establish AUT as single App instance (if it is not just a GUI test):
    if (app != NULL) {

        WxGuiTestApp::SetInstance (app);
    }

    // Store this instance for running tests from WxGuiTestApp::OnRun():
    wxGuiTestApp->SetTestRunnerProxy (*this);
    
    #if defined (WIN32)
        #if !defined (__BUILTIN__)
            ::wxEntry (GetModuleHandle (NULL), NULL, NULL, SW_SHOWNORMAL);
        #else
            ::wxEntry (GetModuleHandle (NULL), NULL, NULL, SW_SHOW);
        #endif
    #else
        int argc = 1;
        char *argv[1] = {"bla"};
        ::wxEntry (argc, argv);
    #endif

    // Trying to re-initialise wxWidgets lib does not work because of the usual
    // problem - heavy usage of static data components which get destructed in
    // during the unavoidable (except when dramatically modifying wxWidgets
    // internally) application clean up.
    // Thus, this would case a crash:
    //::wxInitialize ();

    // Setting an PseudoApp instance would work (unless it wants to do the
    // same re-initialisation as well), but does not really help for the, right
    // now, single benefit of having a wx logging target:
    //App::Destroy ();
    //sw::PseudoApp::SetPseudoAppInstance ();
}


void InitWxGuiTestSetUp::tearDown ()
{
    // While this method is called as expected due to the wxWidgets library
    // uninitialisation the debug logging trace is no more "processed":
    //::wxLogTrace (_T("wxGuiTestCallTrace"), 
    //        _T("void InitWxGuiTestSetUp::tearDown ()"));
}

} // End namespace wxTst
