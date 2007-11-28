///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/VtkWxGuiTesting/CppTest/swCRVtkCaptureTest.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRVTKCAPTURETEST_H
#define SWCRVTKCAPTURETEST_H

#ifdef __GNUG__
    #pragma interface "swCRVtkCaptureTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

class wxVTKRenderWindowInteractor;

namespace swTst {


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

} // End namespace swTst

#endif // SWCRVTKCAPTURETEST_H

