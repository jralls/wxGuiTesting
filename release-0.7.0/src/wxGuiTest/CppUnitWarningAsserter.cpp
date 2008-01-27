///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CppUnitWarningAsserter.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CppUnitWarningAsserter.h"
#endif

#include <wxGuiTest/CppUnitWarningAsserter.h>

#include <cppunit/Asserter.h>

namespace wxTst {


void CppUnitWarningAsserter::FailAssert (const wxString &file,
        const int line, const wxString &shortDescription,
        const wxString &message) const
{
    CPPUNIT_NS::SourceLine sourceLine;

    if ((!file.IsEmpty ()) || (line != -1)) {

        sourceLine = CPPUNIT_NS::SourceLine (std::string(
                (file).mb_str(*wxConvCurrent)), line);
    }

	CPPUNIT_NS::Asserter::fail (CPPUNIT_NS::Message (
	        std::string((shortDescription).mb_str(*wxConvCurrent)),
	        std::string((message).mb_str(*wxConvCurrent))), sourceLine);
}

} // End namespace wxTst

