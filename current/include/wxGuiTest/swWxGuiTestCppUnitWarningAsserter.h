///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/GuiTestCppUnitWarningAsserter.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef WXGUITESTCPPUNITWARNINGASSERTER_H
#define WXGUITESTCPPUNITWARNINGASSERTER_H

#ifdef __GNUG__
    #pragma interface "GuiTestCppUnitWarningAsserter.h"
#endif

#include <wxGuiTest/Common.h>

#include <wxGuiTest/GuiTestWarningAsserterInterface.h>

namespace wxTst {


/*! \class WxGuiTestCppUnitWarningAsserter
    \brief Prevent the need to link to CppUnit by removing #include dependency.
*/
class WxGuiTestCppUnitWarningAsserter : public WxGuiTestWarningAsserterInterface
{
public:
    virtual ~WxGuiTestCppUnitWarningAsserter() {}
    /*! \fn virtual void FailAssert (const wxString &file, const int line, const wxString &shortDescription, const wxString &message) const
        \brief Execute a failing CppUnit framework asserter call.

        \param file file where first failure occured
        \param line line number where first failure occured
        \param shortDescription short description of first failure
        \param message message of occured failure
    */
    virtual void FailAssert (const wxString &file, const int line,
            const wxString &shortDescription, const wxString &message) const;

};

} // End namespace wxTst

#endif // WXGUITESTCPPUNITWARNINGASSERTER_H

