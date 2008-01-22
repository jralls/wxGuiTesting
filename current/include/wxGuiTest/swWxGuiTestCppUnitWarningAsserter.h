///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CppUnitWarningAsserter.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef WXGUITESTCPPUNITWARNINGASSERTER_H
#define WXGUITESTCPPUNITWARNINGASSERTER_H

#ifdef __GNUG__
    #pragma interface "CppUnitWarningAsserter.h"
#endif

#include <wxGuiTest/Common.h>

#include <wxGuiTest/WarningAsserterInterface.h>

namespace wxTst {


/*! \class CppUnitWarningAsserter
    \brief Prevent the need to link to CppUnit by removing #include dependency.
*/
class CppUnitWarningAsserter : public WarningAsserterInterface
{
public:
    virtual ~CppUnitWarningAsserter() {}
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

