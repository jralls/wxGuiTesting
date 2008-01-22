///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/CRWindowHierarchyHandlerTest.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef CRWINDOWHIERARCHYHANDLERTEST_H
#define CRWINDOWHIERARCHYHANDLERTEST_H

#ifdef __GNUG__
    #pragma interface "CRWindowHierarchyHandlerTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

namespace wxTst {


/*! \class CRWindowHierarchyHandlerTest
    \brief Test window hierarchy handler class to uniquely identify controls
    and top level containers symbolically.
*/
class CRWindowHierarchyHandlerTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CRWindowHierarchyHandlerTest );

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


    /*! \fn virtual void testFindWindowContainerName ()
        \brief Example test finding a (control's) window container name.
    */
    virtual void testFindWindowContainerName ();

protected:

private:

};

} // End namespace wxTst

#endif // CRWINDOWHIERARCHYHANDLERTEST_H

