///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppTest/swCRXRCReaderTest.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRXRCReaderTest.h"
#endif

#include "swCRXRCReaderTest.h"

#include <iostream>

#include "swWxLogicErrorException.h"

#include "swCRXRCReader.h"

namespace swTst {


// Register test suite:
CPPUNIT_TEST_SUITE_REGISTRATION( CRXRCReaderTest );


void CRXRCReaderTest::setUp ()
{
    // Nothing to do
}


void CRXRCReaderTest::tearDown ()
{
    // Nothing to do
}


/*
// Just for visual debugging:
void writeTree (Tst::CRXRCNode *node, const char *indent)
{
    if (node != NULL) {

        std::cout << indent << node->GetName ().c_str () << " (" << node->GetClass ().c_str () << ")" << std::endl;
        for (int i = 0; i < node->GetNmbChildren (); i++) {

            writeTree (node->GetChild (i), wxString::Format ("   %s", indent.c_str ()).c_str ());
        }
    }
}
*/

void CRXRCReaderTest::testReadingXRC ()
{
    const wxString xrcDir(_T(XRCDIR));
    wxString xrcFilename = xrcDir + _T("/CapturePanel_wdr.xrc");
    swTst::CRXRCReader *reader = new swTst::CRXRCReader (xrcFilename);

    swTst::CRXRCResource *xrcResource = reader->GetResource ();
    CPPUNIT_ASSERT_MESSAGE ("XRC resource is NULL", xrcResource != NULL);
    const wxString resName = xrcResource->GetName ();
    CPPUNIT_ASSERT_MESSAGE ("First element of XRC resource is not <resource>", 
            resName == _T("resource"));

    CPPUNIT_ASSERT_MESSAGE ("XRC resource must have one child", 1 == xrcResource->GetNmbChildren ());
    // wxPanel
    swTst::CRXRCNode *node = xrcResource->GetChild (0);
    CPPUNIT_ASSERT_MESSAGE ("Node is NULL", node != NULL);
    CPPUNIT_ASSERT_MESSAGE ("Node must have one child", 1 == node->GetNmbChildren ());
    // wxBoxSizer
    node = node->GetChild (0);
    CPPUNIT_ASSERT_MESSAGE ("Node is NULL", node != NULL);
    CPPUNIT_ASSERT_MESSAGE ("Node must have three children", 3 == node->GetNmbChildren ());
    // sizeritem
    node = node->GetChild (0);
    CPPUNIT_ASSERT_MESSAGE ("Node is NULL", node != NULL);
    CPPUNIT_ASSERT_MESSAGE ("Node must have one child", 1 == node->GetNmbChildren ());
    // wxBoxSizer
    node = node->GetChild (0);
    CPPUNIT_ASSERT_MESSAGE ("Node is NULL", node != NULL);
    CPPUNIT_ASSERT_MESSAGE ("Node must have two children", 2 == node->GetNmbChildren ());

    //writeTree (xrcResource, "");
}


void CRXRCReaderTest::testResPathReadingXRC ()
{
    wxString xrcPath = _T("../../../TestData/xrc");
    swTst::CRXRCReader *reader = new swTst::CRXRCReader (xrcPath);

    swTst::CRXRCResource *xrcResource = reader->GetResource ();
    CPPUNIT_ASSERT_MESSAGE ("XRC resource is NULL", xrcResource != NULL);
    const wxString resName = xrcResource->GetName ();
    CPPUNIT_ASSERT_MESSAGE ("First element of XRC resource is not <resource>", 
            resName == _T("resource"));

    CPPUNIT_ASSERT_MESSAGE ("XRC resource must have three children", 3 == xrcResource->GetNmbChildren ());
}

} // End namespace swTst

