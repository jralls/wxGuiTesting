///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppTest/GuiTestProvokedWarningRegistryTest.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "GuiTestProvokedWarningRegistryTest.h"
#endif

#include "GuiTestProvokedWarningRegistryTest.h"

#include <wxGuiTest/GuiTestProvokedWarningRegistry.h>

namespace wxTst {


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
    wxTst::WxGuiTestProvokedWarning warning (
	_("Direct CAD Voxelisation Warning"), _("bla"), 2);
    wxTst::WxGuiTestProvokedWarningRegistry &provWarningRegistry =
            wxTst::WxGuiTestProvokedWarningRegistry::GetInstance ();
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
    wxTst::WxGuiTestProvokedWarning warning (
	_("Direct CAD Voxelisation Warning"), _("bla"), 2);
    wxTst::WxGuiTestProvokedWarningRegistry &provWarningRegistry =
            wxTst::WxGuiTestProvokedWarningRegistry::GetInstance ();
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
    wxTst::WxGuiTestProvokedWarning warning (
	_("Direct CAD Voxelisation Warning"), _("bla"), 2);
    wxTst::WxGuiTestProvokedWarningRegistry &provWarningRegistry =
            wxTst::WxGuiTestProvokedWarningRegistry::GetInstance ();
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
    wxTst::WxGuiTestProvokedWarning warning (
            _("Direct CAD Voxelisation Warning"), _T("bla"), 2);
    wxTst::WxGuiTestProvokedWarningRegistry &provWarningRegistry =
            wxTst::WxGuiTestProvokedWarningRegistry::GetInstance ();
    provWarningRegistry.RegisterWarning (warning);

    const wxTst::WxGuiTestProvokedWarning * knownWarning =
            provWarningRegistry.FindRegisteredWarning (
            _("Direct CAD Voxelisation Warning"), _T("bla"));

    CPPUNIT_ASSERT_MESSAGE ("Warning was not found",
            knownWarning != NULL);
    CPPUNIT_ASSERT_MESSAGE ("Warning is not registered",
            provWarningRegistry.IsRegisteredAndInTime (*knownWarning));
    CPPUNIT_ASSERT_MESSAGE ("Warning was already detected",
            !provWarningRegistry.WasDetected (*knownWarning));

    const wxTst::WxGuiTestProvokedWarning * unknownWarning =
            provWarningRegistry.FindRegisteredWarning (
            _("Unknown Direct CAD Voxelisation Warning"), _T("bla"));

    CPPUNIT_ASSERT_MESSAGE ("Warning was found",
            unknownWarning == NULL);
}
} // End namespace wxTst
