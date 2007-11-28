/* /////////////////////////////////////////////////////////////////////////////// */
/* // Name:        swWxGuiTesting/CppGuiTest/swCRCaptureTest.h */
/* // Author:      Reinhold Füreder */
/* // Created:     2004 */
/* // Copyright:   (c) 2005 Reinhold Füreder */
/* // Licence:     wxWindows licence */
/* ////////////////////////////////////////////////////////////////////////////// */

//This file was entirely commented out in the distro, causing the
//associated code file to not build. WTF?

 #ifndef SWCRCAPTURETEST_H 
 #define SWCRCAPTURETEST_H 

#ifdef __GNUG__ 
     #pragma interface "swCRCaptureTest.h" 
#endif 

#include <cppunit/extensions/HelperMacros.h> 

namespace swTst {


/*! \class CRCaptureTest
    \brief Test capturing of GUI interaction.
*/
class CRCaptureTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CRCaptureTest );

        CPPUNIT_TEST( testCapture );

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


    /*! \fn virtual void testCapture ()
        \brief Minimal capture test case.
    */
    virtual void testCapture ();

protected:

private:

};

} // End namespace swTst

#endif // SWCRCAPT URETEST_H

