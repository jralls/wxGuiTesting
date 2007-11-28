///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRLogInterface.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRLOGINTERFACE_H
#define SWCRLOGINTERFACE_H

#ifdef __GNUG__
//    #pragma interface "swCRLogInterface.h"
#endif

#include "Common.h"

namespace swTst {


/*! \class CRLogInterface
    \brief Logging target interface.
*/
class CRLogInterface
{
public:
    /*! \var virtual void Log (const wxString &text) = 0
        \brief Log some text.

        \param text text to log
    */
    virtual void Log (const wxString &text) = 0;

};

} // End namespace swTst

#endif // SWCRLOGINTERFACE_H

