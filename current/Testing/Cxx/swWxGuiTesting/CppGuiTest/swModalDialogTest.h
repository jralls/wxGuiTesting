///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swModalDialogTest.h
// Author:      Reinhold Füreder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWMODALDIALOGTEST_H
#define SWMODALDIALOGTEST_H

#ifdef __GNUG__
    #pragma interface "swModalDialogTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

#include <wx/timer.h>

namespace swTst {


/*! \class ModalDialogTest
    \brief Test modal dialog handling during testing.
*/
class ModalDialogTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( ModalDialogTest );

        CPPUNIT_TEST( testModalDialog );
        // Solution does not necessarily work for modal standard dialogs: e.g.
        // the wxDirDialog for MSW is based on SHBrowseForFolder function.
        // Possible solutions: (a) ignore modal standard dialogs, (b) look in
        // all implementations and potentially modify the behaviour if being in
        // test mode to do what?
        //CPPUNIT_TEST( testStdModalDialog );

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


    /*! \fn virtual void testModalDialog ()
        \brief Test handling of user-defined modal dialogs during testing.
    */
    virtual void testModalDialog ();


    /*! \fn virtual void testStdModalDialog ()
        \brief Test handling of predefined modal dialogs during testing.
    */
    virtual void testStdModalDialog ();

protected:

private:

};

} // End namespace swTst

#endif // SWMODALDIALOGTEST_H
