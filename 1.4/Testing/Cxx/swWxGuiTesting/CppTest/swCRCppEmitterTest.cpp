///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppTest/swCRCppEmitterTest.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRCppEmitterTest.h"
#endif

#include "swCRCppEmitterTest.h"

#include "swCRCppEmitter.h"

namespace swTst {


// Register test suite:
CPPUNIT_TEST_SUITE_REGISTRATION( CRCppEmitterTest );


void CRCppEmitterTest::setUp ()
{
    // Nothing to do
}


void CRCppEmitterTest::tearDown ()
{
    // Nothing to do
}


void CRCppEmitterTest::testExample ()
{
    char *filename = "../../../Cxx/swWxGuiTesting/CppGuiTest/swCRCaptureTest.cpp";

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();
    CPPUNIT_ASSERT_MESSAGE ("No emitter returned", emitter != NULL);
    emitter->SetTestCaseFileContext (filename);

    wxString captureFilename = emitter->GetCaptureFilename();

    emitter->AddComment ("Short comment");
    wxArrayString expectedCode;
    expectedCode.Add ("    // Short comment");
    checkEmittedCode (captureFilename, expectedCode);

    emitter->AddComment ("Thisisaveryveryverylongcommentexceedingthe80characterslinelengtheasilyMoreoveritcontainsnoblankswhichmightbeslightlydump");
    expectedCode.Clear ();
    expectedCode.Add ("    // Thisisaveryveryverylongcommentexceedingthe80characterslinelengtheasilyMor");
    expectedCode.Add ("    // eoveritcontainsnoblankswhichmightbeslightlydump");
    checkEmittedCode (captureFilename, expectedCode);

    emitter->AddComment ("This is a very, very, very long comment exceeding the 80 characters line length easily. Moreover it contains a, range,special!characters?a.b,c?d!e:f.g,checking: the. correct, line? break.");
    expectedCode.Clear ();
    expectedCode.Add ("    // This is a very, very, very long comment exceeding the 80 characters line");
    expectedCode.Add ("    // length easily. Moreover it contains a, range,special!characters?a.b,c?d!");
    expectedCode.Add ("    // e:f.g,checking: the. correct, line? break.");
    checkEmittedCode (captureFilename, expectedCode);

    emitter->AddCode ("Method (\"This is a very, very, very long comment exceeding the 80 characters line length easily. Moreover it contains a, range,special!characters?a.b,c?d!e:f.g,checking: the. correct, line? break.\")");
    expectedCode.Clear ();
    expectedCode.Add ("    Method (\"This is a very, very, very long comment exceeding the 80 \"");
    expectedCode.Add ("            \"characters line length easily. Moreover it contains a, range,\"");
    expectedCode.Add ("            \"special!characters?a.b,c?d!e:f.g,checking: the. correct, line? \"");
    expectedCode.Add ("            \"break.\")");
    checkEmittedCode (captureFilename, expectedCode);

    // Fix C&R: line break in emitting of non-integer numbers in code (e.g. "0.5" => "0.\n5").
    emitter->AddCode ("Method (\"Check line break in emitting of non-integer numbers          \", 0.5);");
    expectedCode.Clear ();
    expectedCode.Add ("    Method (\"Check line break in emitting of non-integer numbers          \", ");
    expectedCode.Add ("            0.5);");
    checkEmittedCode (captureFilename, expectedCode);

    CRCppEmitter::Destroy ();
}


void CRCppEmitterTest::checkEmittedCode(const wxString &captureFilename,
        const wxArrayString &expectedCode) const
{
    wxTextFile newFile;
    newFile.Open (captureFilename);

    int lineCount = newFile.GetLineCount ();

    for (int i = expectedCode.GetCount (); i > 0; i--) {
        wxString line = newFile.GetLine (lineCount - i);

        CPPUNIT_ASSERT_EQUAL_MESSAGE ("Expected emitted code is wrong",
                expectedCode[expectedCode.GetCount () - i], line);
    }
}


} // End namespace swTst

