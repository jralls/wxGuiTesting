///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/InitWxGuiTest.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef INITWXGUITEST_H
#define INITWXGUITEST_H

#ifdef __GNUG__
    #pragma interface "InitWxGuiTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

namespace wxTst {


/*! \class InitWxGuiTest
    \brief "Package" all registered wxWidgets GUI tests in decorated shape.
    
    CppUnit test application is retrieving all registered test cases before
    TestRunner is actually running them by means of
    TestFactoryRegistry::getRegistry().makeTest() method. This method in turn
    will find and use static suite() methods returning tests.
    
    In contrast to regular test classes the suite() method of this class
    returns all wxWidgets GUI tests being registered in "WxGuiTest" named
    registry as one single test. In fact, it is a TestDecorator holding all
    these GUI tests allowing to initialise wxWidgets GUI library part exactly
    once before running tests, as well as helping in diversion the flow of
    control.
*/
class InitWxGuiTest : public CPPUNIT_NS::TestFixture
{
public:
    // Using CPPUNIT_TEST_SUITE, CPPUNIT_TEST and CPPUNIT_TEST_SUITE_END macros
    // interferes with the need of decorating wxGui tests:
    //CPPUNIT_TEST_SUITE( InitWxGuiTest );
    //    CPPUNIT_TEST( someTest );
    //CPPUNIT_TEST_SUITE_END();

    // Thus, implement non-standard decorating behaviour "by hand":
    /*! \fn static CPPUNIT_NS::Test * suite ()
        \brief Find and return decorater containing all wxWidgets GUI tests.

        \return decorater containing all wxWidgets GUI tests
    */
    static CPPUNIT_NS::Test * suite ();

public:
    /*! \fn InitWxGuiTest ()
        \brief Constructor
    */
    InitWxGuiTest ();


    /*! \fn virtual ~InitWxGuiTest ()
        \brief Destructor
    */
    virtual ~InitWxGuiTest ();


    /*! \fn virtual void setUp ()
        \brief Set up context before running a test.
    */
    virtual void setUp ();


    /*! \fn virtual void tearDown ()
        \brief Clean up after the test run.
    */
    virtual void tearDown ();

};

} // End namespace wxTst

#endif // INITWXGUITEST_H

