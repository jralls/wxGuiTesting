///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CRLogInterface.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef CRLOGINTERFACE_H
#define CRLOGINTERFACE_H

#ifdef __GNUG__
//    #pragma interface "CRLogInterface.h"
#endif

#include <wxGuiTest/Common.h>

namespace wxTst {


/*! \class CRLogInterface
    \brief Logging target interface.
*/
class CRLogInterface
{
public:
    virtual ~CRLogInterface() {}
    /*! \var virtual void Log (const wxString &text) = 0
        \brief Log some text.

        \param text text to log
    */
    virtual void Log (const wxString &text) = 0;


};

} // End namespace wxTst

#endif // CRLOGINTERFACE_H

