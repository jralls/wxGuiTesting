///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swCRWindowHierarchyHandlerTest.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRWINDOWHIERARCHYHANDLERTEST_H
#define SWCRWINDOWHIERARCHYHANDLERTEST_H

#ifdef __GNUG__
    #pragma interface "swCRWindowHierarchyHandlerTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

namespace swTst {


/*! \class CRWindowHierarchyHandlerTest
    \brief Test window hierarchy handler class to uniquely identify controls
    and top level containers symbolically.
*/
class CRWindowHierarchyHandlerTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CRWindowHierarchyHandlerTest );

        CPPUNIT_TEST( testFindXRCNode );
        CPPUNIT_TEST( testFindWindowContainer );
        CPPUNIT_TEST( testFindWindowContainerName );

    CPPUNIT_TEST_SUITE_END();

public:
    /*! \fn virtual void setUp ()
        \brief Set up context before running a test.
    */
    virtual void setUp ();


    /*! \fn virtual void tearDown ()
        \brief Clean up after the test run.
    */
    virtual void tearDown ();


    /*! \fn virtual void testFindXRCNode ()
        \brief Example test finding a (control's) XRC node.
    */
    virtual void testFindXRCNode ();


    /*! \fn virtual void testFindWindowContainer ()
        \brief Example test finding a (control's) window container.
    */
    virtual void testFindWindowContainer ();


    /*! \fn virtual void testFindWindowContainerName ()
        \brief Example test finding a (control's) window container name.
    */
    virtual void testFindWindowContainerName ();

protected:

private:

};

} // End namespace swTst

#endif // SWCRWINDOWHIERARCHYHANDLERTEST_H

