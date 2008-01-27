/////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/CapturePlusEmittingTest.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
/////////////////////////////////////////////////////////////////////////////

#ifndef CAPTUREPLUSEMITTINGTEST_H
#define CAPTUREPLUSEMITTINGTEST_H

#ifdef __GNUG__
    #pragma interface "CapturePlusEmittingTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

#include <wxGuiTest/WxGuiTestApp.h>

namespace wxTst {


/*! \class CapturePlusEmittingTest
    \brief Test platform dependent emitting of captured simulated events.

    Thus, the whole workflow is tested at once; this would have caught recent
    issues like inconsistencies between wx ports with respect to event
    handling (cf. menu item selection).
*/
class CapturePlusEmittingTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CapturePlusEmittingTest );

        CPPUNIT_TEST( testSelectAndCheckTopLevelWindowMenuBarMenuItem );
        CPPUNIT_TEST( testSelectAndCheckTopLevelWindowMenuBarMenuItem2 );

    CPPUNIT_TEST_SUITE_END();

// Methods:
public:
    /*! \fn virtual void setUp ()
        \brief Set up context before running a test.
    */
    virtual void setUp ();


    /*! \fn virtual void tearDown ()
        \brief Clean up after the test run.
    */
    virtual void tearDown ();


    /*! \fn virtual void testSelectAndCheckTopLevelWindowMenuBarMenuItem ()
        \brief Test select and check menu item from top level window menu bar.
    */
    virtual void testSelectAndCheckTopLevelWindowMenuBarMenuItem ();


    /*! \fn virtual void testSelectAndCheckTopLevelWindowMenuBarMenuItem2 ()
        \brief Test select and check menu item from top level window menu bar,
        whereas the event object is not the top level frame (like under wxM),
        but the menu (like under wxGTK until v2.8.6 and wxMac).
    */
    virtual void testSelectAndCheckTopLevelWindowMenuBarMenuItem2 ();

protected:
    /*! \fn virtual WxGuiTestApp * getGuiTestApp ()
        \brief Helper method to retrieve current application.

        \return current application
    */
    virtual WxGuiTestApp * getGuiTestApp ();


    /*! \fn void checkEmittedCode (const wxString &expectedFilename, int startLineNmb, int endLineNmb) const
        \brief Helper method to verify emitted code.

        \param expectedFilename name of test case file = reproducing reference
                or expected code emitting
        \param startLineNmb line number of start of emitted code to check
        \param endLineNmb line number of end of emitted code to check
    */
    virtual void checkEmittedCode (const wxString &expectedFilename,
        size_t startLineNmb, size_t endLineNmb) const;

};

} // End namespace wxTst

#endif // CAPTUREPLUSEMITTINGTEST_H
