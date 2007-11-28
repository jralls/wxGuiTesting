///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swInitWxGuiTestSetUp.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWINITWXGUITESTSETUP_H
#define SWINITWXGUITESTSETUP_H

#ifdef __GNUG__
    #pragma interface "swInitWxGuiTestSetUp.h"
#endif

#include "Common.h"

#include <cppunit/extensions/TestSetUp.h>

namespace swTst {


/*! \class InitWxGuiTestSetUp
    \brief Initialise GUI part of wxWidgets library exactly once before running
    first GUI test.
    
    The GUI part of wxWidgets must only be initialised once due to wxWidgets
    heavy usage of static constructs. This is necessary as well, as CppUnit is
    text based and a wxWidgets "test application" is required to simulate the
    "single stepping" through the test case code.
    Thus, the code flow must be diverted so that the WxGuiTestApp object is
    in control of the code flow instead of the CppUnit test runner.
*/
class InitWxGuiTestSetUp : public CPPUNIT_NS::TestSetUp
{
public:
    /*! \fn InitWxGuiTestSetUp (CPPUNIT_NS::Test *test)
        \brief Constructor

        \param test test to decorate
    */
    InitWxGuiTestSetUp (CPPUNIT_NS::Test *test);


    /*! \fn virtual ~InitWxGuiTestSetUp ()
        \brief Destructor
    */
    virtual ~InitWxGuiTestSetUp ();


    /*! \fn virtual void run (CPPUNIT_NS::TestResult *result)
        \brief Do not call TestDecorator::run() directly as parent class TestSetUp.
        
        Override TestSetUp::run() because the flow of control must be diverted
        due to integrating the CppUnit test runs into a proper wxWidgets
        application.

        \param result object to save test results
    */
    virtual void run (CPPUNIT_NS::TestResult *result);


    /*! \fn virtual void RunAsDecorator ()
        \brief Make up for not called TestDecorator::run().
        
        Is called directly or indirectly from WxGuiTestApp::OnRun().
    */
    virtual void RunAsDecorator ();

protected:
    /*! \fn virtual void setUp ()
        \brief Initialise wxWidgets library GUI part by means of ::wxEntry().
    */
    virtual void setUp ();

    
    /*! \fn virtual void tearDown ()
        \brief Try to destruct wxWidgets library initialisation and "test application".
    */
    virtual void tearDown ();

private:
    // Store result sent to run() for latter call from WxGuiTestApp::OnRun():
    CPPUNIT_NS::TestResult *m_result; 

};

} // End namespace swTst

#endif // SWINITWXGUITESTSETUP_H

