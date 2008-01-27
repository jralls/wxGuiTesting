///////////////////////////////////////////////////////////////////////////////
// Name:        test/VtkWxGuiTesting/CppTest/CRVtkCaptureTest.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef CRVTKCAPTURETEST_H
#define CRVTKCAPTURETEST_H

#ifdef __GNUG__
    #pragma interface "CRVtkCaptureTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

class wxVTKRenderWindowInteractor;

namespace wxTst {


/*! \class CRVtkCaptureTest
    \brief Test capturing of GUI interaction.
*/
class CRVtkCaptureTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CRVtkCaptureTest );

        CPPUNIT_TEST( testVtkCapture );

    CPPUNIT_TEST_SUITE_END();

public:
    /*! \fn CRVtkCaptureTest ()
        \brief C'tor.
    */
    CRVtkCaptureTest ();


    /*! \fn virtual void setUp ()
        \brief Set up context before running a test.
    */
    virtual void setUp ();


    /*! \fn virtual void tearDown ()
        \brief Clean up after the test run.
    */
    virtual void tearDown ();


    /*! \fn virtual void testVtkCapture ()
        \brief Minimal wxVtk interaction capture test case.
    */
    virtual void testVtkCapture ();

protected:

private:
    wxVTKRenderWindowInteractor *m_iren1, *m_iren2;
};

} // End namespace wxTst

#endif // CRVTKCAPTURETEST_H

