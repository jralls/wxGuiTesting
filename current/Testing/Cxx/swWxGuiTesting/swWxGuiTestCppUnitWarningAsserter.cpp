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
#ifdef UNICODE
	std::string filestr(wxConvCurrent->cWC2MB(file.c_str ()).data());
        sourceLine = CPPUNIT_NS::SourceLine (filestr, line);
#else
        sourceLine = CPPUNIT_NS::SourceLine (file.c_str (), line);
#endif
    }

#ifdef UNICODE
    std::string descstr(wxConvCurrent->cWC2MB(shortDescription.c_str()).data());
    std::string msgstr(wxConvCurrent->cWC2MB(message.c_str ()).data());
    CPPUNIT_NS::Asserter::fail (CPPUNIT_NS::Message (descstr, msgstr),
				sourceLine);
#else
     CPPUNIT_NS::Asserter::fail (
           CPPUNIT_NS::Message (shortDescription.c_str (), message.c_str ()),
	   sourceLine);
#endif
}

} // End namespace swTst

