///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/InitWxGuiTest.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "InitWxGuiTest.h"
#endif

#include <wxGuiTest/InitWxGuiTest.h>

#include "InitWxGuiTestSetUp.h"

// Don't register test suite in WxGuiTesting framework library, but in actual
// console application running the tests:
//CPPUNIT_TEST_SUITE_REGISTRATION( Tst::InitWxGuiTest );

namespace wxTst {


InitWxGuiTest::InitWxGuiTest ()
{
    // Nothing to do
}


InitWxGuiTest::~InitWxGuiTest ()
{
    // Nothing to do
}


CPPUNIT_NS::Test * InitWxGuiTest::suite ()
{
    CPPUNIT_NS::TestSuite *suiteOfTests = new CPPUNIT_NS::TestSuite ();

    // Add all tests of specially named registry as well:
    CPPUNIT_NS::Test *wxGuiTestSuite = CPPUNIT_NS::TestFactoryRegistry::
            getRegistry ("WxGuiTest").makeTest ();
    suiteOfTests->addTest (wxGuiTestSuite);

    InitWxGuiTestSetUp *initWxGuiTestSetUp =
            new InitWxGuiTestSetUp (suiteOfTests);

    return initWxGuiTestSetUp;
}


void InitWxGuiTest::setUp ()
{
    ::wxLogTrace (_T("wxGuiTestCallTrace"), _T("void InitWxGuiTest::setUp ()"));
}


void InitWxGuiTest::tearDown ()
{
    ::wxLogTrace (_T("wxGuiTestCallTrace"), 
            _T("void InitWxGuiTest::tearDown ()"));
}

} // End namespace wxTst

