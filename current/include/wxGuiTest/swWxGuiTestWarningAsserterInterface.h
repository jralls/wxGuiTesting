///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/GuiTestWarningAsserterInterface.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef WXGUITESTWARNINGASSERTERINTERFACE_H
#define WXGUITESTWARNINGASSERTERINTERFACE_H

#ifdef __GNUG__
//    #pragma interface "GuiTestWarningAsserterInterface.h"
#endif

#include <wxGuiTest/Common.h>

namespace wxTst {


/*! \class WxGuiTestWarningAsserterInterface
    \brief Prevent the need to link to CppUnit by removing #include dependency.
*/
class WxGuiTestWarningAsserterInterface
{
public:
    virtual ~WxGuiTestWarningAsserterInterface() {}
    /*! \fn virtual void FailAssert (const wxString &file, const int line, const wxString &shortDescription, const wxString &message) const = 0
        \brief Execute a failing CppUnit framework asserter call.

        \param file file where first failure occured
        \param line line number where first failure occured
        \param shortDescription short description of first failure
        \param message message of occured failure
    */
    virtual void FailAssert (const wxString &file, const int line,
            const wxString &shortDescription, const wxString &message) const = 0;

};

} // End namespace wxTst

#endif // WXGUITESTWARNINGASSERTERINTERFACE_H

