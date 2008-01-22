///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/GuiTestEventSimulationHelperTest.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef WXGUITESTEVENTSIMULATIONHELPERTEST_H
#define WXGUITESTEVENTSIMULATIONHELPERTEST_H

#ifdef __GNUG__
    #pragma interface "GuiTestEventSimulationHelperTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

#include "GuiTestEvtSimHlpEvtHandler.h"

class wxMiniFrame;

namespace wxTst {


/*! \class WxGuiTestEventSimulationHelperTest
    \brief Test event simulation helper class in order to detect changes (i.e.
    corrections) of the partly inconsistent behaviour in future wxWidgets
    versions.
*/
class WxGuiTestEventSimulationHelperTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( WxGuiTestEventSimulationHelperTest );

        CPPUNIT_TEST( testSelectMenuItem );
        CPPUNIT_TEST( testSelectCheckableMenuItem );
        CPPUNIT_TEST( testClickButton );
        CPPUNIT_TEST( testSetTextCtrlValue );
        CPPUNIT_TEST( testSelectTreeItem );
        CPPUNIT_TEST( testRightClickTreeItem );
        CPPUNIT_TEST( testSelectNotebookPage );
        CPPUNIT_TEST( testSelectChoiceItem );
        CPPUNIT_TEST( testSetCheckboxState );
        CPPUNIT_TEST( testSelectRadioBoxItem );
        CPPUNIT_TEST( testSetSliderValue );
        CPPUNIT_TEST( testSetSpinCtrlValue );
        CPPUNIT_TEST( testToggleTool );
        CPPUNIT_TEST( testToggleCheckableTool );

    CPPUNIT_TEST_SUITE_END();

public:
    /*! \fn WxGuiTestEventSimulationHelperTest ()
        \brief Constructor.
    */
    WxGuiTestEventSimulationHelperTest ();


    /*! \fn virtual ~WxGuiTestEventSimulationHelperTest ()
        \brief Destructor.
    */
    virtual ~WxGuiTestEventSimulationHelperTest ();


    /*! \fn virtual void setUp ()
        \brief Set up context before running a test.
    */
    virtual void setUp ();


    /*! \fn virtual void tearDown ()
        \brief Clean up after the test run.
    */
    virtual void tearDown ();


    /*! \fn virtual void testSelectMenuItem ()
        \brief Test selection of menu item.
    */
    virtual void testSelectMenuItem ();


    /*! \fn virtual void testSelectCheckableMenuItem ()
        \brief Test selection of checkable menu item.
    */
    virtual void testSelectCheckableMenuItem ();


    /*! \fn virtual void testClickButton ()
        \brief Test clicking on a button.
    */
    virtual void testClickButton ();


    /*! \fn virtual void testSetTextCtrlValue ()
        \brief Test setting a text control value.
    */
    virtual void testSetTextCtrlValue ();


    /*! \fn virtual void testSelectTreeItem ()
        \brief Test selecting a tree item.
    */
    virtual void testSelectTreeItem ();


    /*! \fn virtual void testRightClickTreeItem ()
        \brief Test right clicking on a tree item.
    */
    virtual void testRightClickTreeItem ();

    
    /*! \fn virtual void testSelectNotebookPage ()
        \brief Test selecting a notebook page.
    */
    virtual void testSelectNotebookPage ();


    /*! \fn virtual void testSelectChoiceItem ()
        \brief Test selecting a choice item.
    */
    virtual void testSelectChoiceItem ();


    /*! \fn virtual void testSetCheckboxState ()
        \brief Test setting the checkbox state.
    */
    virtual void testSetCheckboxState ();

    /*! \fn virtual void testSelectRadioBoxItem ()
        \brief Test setting the radiobox item.
    */
    virtual void testSelectRadioBoxItem ();

    
    /*! \fn virtual void testSetSliderValue ()
        \brief Test setting the slider value.
    */
    virtual void testSetSliderValue ();


    /*! \fn virtual void testSetSpinCtrlValue ()
        \brief Test setting the spinctrl value.
    */
    virtual void testSetSpinCtrlValue ();


    /*! \fn virtual void testToggleTool ()
        \brief Test toggling a tool.
    */
    virtual void testToggleTool ();


    /*! \fn virtual void testToggleCheckableTool ()
        \brief Test toggling a checkable tool.
    */
    virtual void testToggleCheckableTool ();

protected:

private:
    wxFrame *m_testFrame;
    WxGuiTestEvtSimHlpEvtHandler *m_testEvtHandler;
    wxMiniFrame *m_miniFrame;

};

} // End namespace wxTst

#endif // WXGUITESTEVENTSIMULATIONHELPERTEST_H

