///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swWxGuiTestCppUnitWarningAsserter.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swWxGuiTestCppUnitWarningAsserter.h"
#endif

#include "swWxGuiTestCppUnitWarningAsserter.h"

#include "cppunit/Asserter.h"

namespace swTst {


void WxGuiTestCppUnitWarningAsserter::FailAssert (const wxString &file,
        const int line, const wxString &shortDescription,
        const wxString &message) const
{
    CPPUNIT_NS::SourceLine sourceLine;

    if ((!file.IsEmpty ()) || (line != -1)) {

        sourceLine = CPPUNIT_NS::SourceLine (file.c_str (), line);
    }

    CPPUNIT_NS::Asserter::fail (
            CPPUNIT_NS::Message (shortDescription.c_str (), message.c_str ()),
            sourceLine);
}

} // End namespace swTst

