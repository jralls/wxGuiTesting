///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppTest/swWxGuiTestProvokedWarningRegistryTest.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swWxGuiTestProvokedWarningRegistryTest.h"
#endif

#include "swWxGuiTestProvokedWarningRegistryTest.h"

#include "swWxGuiTestProvokedWarningRegistry.h"

namespace swTst {


// Register test suite:
CPPUNIT_TEST_SUITE_REGISTRATION( WxGuiTestProvokedWarningRegistryTest );


void WxGuiTestProvokedWarningRegistryTest::setUp ()
{
    // Nothing to do
}


void WxGuiTestProvokedWarningRegistryTest::tearDown ()
{
    WxGuiTestProvokedWarningRegistry::Destroy ();
}


void WxGuiTestProvokedWarningRegistryTest::testUnRegister ()
{
    swTst::WxGuiTestProvokedWarning warning (
            _("Direct CAD Voxelisation Warning"), NULL, 2);
    swTst::WxGuiTestProvokedWarningRegistry &provWarningRegistry =
            swTst::WxGuiTestProvokedWarningRegistry::GetInstance ();
    provWarningRegistry.RegisterWarning (warning);

    CPPUNIT_ASSERT_MESSAGE ("Warning is not registered",
            provWarningRegistry.IsRegisteredAndInTime (warning));
    CPPUNIT_ASSERT_MESSAGE ("Warning was already detected",
            !provWarningRegistry.WasDetected (warning));

    provWarningRegistry.UnregisterWarning (warning);

    CPPUNIT_ASSERT_MESSAGE ("Warning is registered",
            !provWarningRegistry.IsRegisteredAndInTime (warning));
    CPPUNIT_ASSERT_MESSAGE ("Warning was already detected",
            !provWarningRegistry.WasDetected (warning));
}


void WxGuiTestProvokedWarningRegistryTest::testTimeout ()
{
    swTst::WxGuiTestProvokedWarning warning (
            _("Direct CAD Voxelisation Warning"), NULL, 2);
    swTst::WxGuiTestProvokedWarningRegistry &provWarningRegistry =
            swTst::WxGuiTestProvokedWarningRegistry::GetInstance ();
    provWarningRegistry.RegisterWarning (warning);

    CPPUNIT_ASSERT_MESSAGE ("Warning is not registered",
            provWarningRegistry.IsRegisteredAndInTime (warning));
    CPPUNIT_ASSERT_MESSAGE ("Warning was already detected",
            !provWarningRegistry.WasDetected (warning));

    // Kinda unregistration due to timeout exceeding:
    ::wxSleep (3);

    CPPUNIT_ASSERT_MESSAGE ("Warning is registered",
            !provWarningRegistry.IsRegisteredAndInTime (warning));
    CPPUNIT_ASSERT_MESSAGE ("Warning was already detected",
            !provWarningRegistry.WasDetected (warning));
}


void WxGuiTestProvokedWarningRegistryTest::testDetection ()
{
    swTst::WxGuiTestProvokedWarning warning (
            _("Direct CAD Voxelisation Warning"), NULL, 2);
    swTst::WxGuiTestProvokedWarningRegistry &provWarningRegistry =
            swTst::WxGuiTestProvokedWarningRegistry::GetInstance ();
    provWarningRegistry.RegisterWarning (warning);

    CPPUNIT_ASSERT_MESSAGE ("Warning is not registered",
            provWarningRegistry.IsRegisteredAndInTime (warning));
    CPPUNIT_ASSERT_MESSAGE ("Warning was already detected",
            !provWarningRegistry.WasDetected (warning));

    // Set warning to have been detected:
    provWarningRegistry.SetWarningAsDetected (warning);

    CPPUNIT_ASSERT_MESSAGE ("Warning is not registered",
            provWarningRegistry.IsRegisteredAndInTime (warning));
    CPPUNIT_ASSERT_MESSAGE ("Warning was not detected",
            provWarningRegistry.WasDetected (warning));
}


void WxGuiTestProvokedWarningRegistryTest::testFinding ()
{
    swTst::WxGuiTestProvokedWarning warning (
            _("Direct CAD Voxelisation Warning"), NULL, 2);
    swTst::WxGuiTestProvokedWarningRegistry &provWarningRegistry =
            swTst::WxGuiTestProvokedWarningRegistry::GetInstance ();
    provWarningRegistry.RegisterWarning (warning);

    const swTst::WxGuiTestProvokedWarning * knownWarning =
            provWarningRegistry.FindRegisteredWarning (
		_("Direct CAD Voxelisation Warning"), _T("bla"));

    CPPUNIT_ASSERT_MESSAGE ("Warning was not found",
            knownWarning != NULL);
    CPPUNIT_ASSERT_MESSAGE ("Warning is not registered",
            provWarningRegistry.IsRegisteredAndInTime (*knownWarning));
    CPPUNIT_ASSERT_MESSAGE ("Warning was already detected",
            !provWarningRegistry.WasDetected (*knownWarning));

    const swTst::WxGuiTestProvokedWarning * unknownWarning =
            provWarningRegistry.FindRegisteredWarning (
		_("Unknown Direct CAD Voxelisation Warning"), _T("bla"));

    CPPUNIT_ASSERT_MESSAGE ("Warning was found",
            unknownWarning == NULL);
}
} // End namespace swTst

