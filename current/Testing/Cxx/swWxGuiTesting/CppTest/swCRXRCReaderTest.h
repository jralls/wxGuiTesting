///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppTest/swCRXRCReaderTest.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRXRCREADERTEST_H
#define SWCRXRCREADERTEST_H

#ifdef __GNUG__
    #pragma interface "swCRXRCReaderTest.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

namespace swTst {


/*! \class CRXRCReaderTest
    \brief Test reading and parsing of XRC files.
*/
class CRXRCReaderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CRXRCReaderTest );

        CPPUNIT_TEST( testReadingXRC );
        CPPUNIT_TEST( testResPathReadingXRC );

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


    /*! \fn virtual void testReadingXRC ()
        \brief Test case for reading an XRC file.
    */
    virtual void testReadingXRC ();


    /*! \fn virtual void testResPathReadingXRC ()
        \brief Test case for reading all XRC files in the resource path.
    */
    virtual void testResPathReadingXRC ();

protected:

private:

};

} // End namespace swTst

#endif // SWCRXRCREADERTEST_H

