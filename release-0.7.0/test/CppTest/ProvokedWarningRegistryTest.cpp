///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppTest/GuiTestProvokedWarningRegistryTest.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "ProvokedWarningRegistryTest.h"
#endif

#include "ProvokedWarningRegistryTest.h"

#include <wxGuiTest/ProvokedWarningRegistry.h>

using namespace wxTst;


// Register test suite:
CPPUNIT_TEST_SUITE_REGISTRATION( ProvokedWarningRegistryTest );


void ProvokedWarningRegistryTest::setUp ()
{
    // Nothing to do
}


void ProvokedWarningRegistryTest::tearDown ()
{
    ProvokedWarningRegistry::Destroy ();
}


void ProvokedWarningRegistryTest::testUnRegister ()
{
    wxTst::ProvokedWarning warning (
	_("Direct CAD Voxelisation Warning"), _("bla"), 2);
    wxTst::ProvokedWarningRegistry &provWarningRegistry =
            wxTst::ProvokedWarningRegistry::GetInstance ();
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


void ProvokedWarningRegistryTest::testTimeout ()
{
    wxTst::ProvokedWarning warning (
	_("Direct CAD Voxelisation Warning"), _("bla"), 2);
    wxTst::ProvokedWarningRegistry &provWarningRegistry =
            wxTst::ProvokedWarningRegistry::GetInstance ();
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


void ProvokedWarningRegistryTest::testDetection ()
{
    wxTst::ProvokedWarning warning (
	_("Direct CAD Voxelisation Warning"), _("bla"), 2);
    wxTst::ProvokedWarningRegistry &provWarningRegistry =
            wxTst::ProvokedWarningRegistry::GetInstance ();
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


void ProvokedWarningRegistryTest::testFinding ()
{
    wxTst::ProvokedWarning warning (
            _("Direct CAD Voxelisation Warning"), _T("bla"), 2);
    wxTst::ProvokedWarningRegistry &provWarningRegistry =
            wxTst::ProvokedWarningRegistry::GetInstance ();
    provWarningRegistry.RegisterWarning (warning);

    const wxTst::ProvokedWarning * knownWarning =
            provWarningRegistry.FindRegisteredWarning (
            _("Direct CAD Voxelisation Warning"), _T("bla"));

    CPPUNIT_ASSERT_MESSAGE ("Warning was not found",
            knownWarning != NULL);
    CPPUNIT_ASSERT_MESSAGE ("Warning is not registered",
            provWarningRegistry.IsRegisteredAndInTime (*knownWarning));
    CPPUNIT_ASSERT_MESSAGE ("Warning was already detected",
            !provWarningRegistry.WasDetected (*knownWarning));

    const wxTst::ProvokedWarning * unknownWarning =
            provWarningRegistry.FindRegisteredWarning (
            _("Unknown Direct CAD Voxelisation Warning"), _T("bla"));

    CPPUNIT_ASSERT_MESSAGE ("Warning was found",
            unknownWarning == NULL);
}


