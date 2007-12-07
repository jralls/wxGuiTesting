///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRLogInterface.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRLOGINTERFACE_H
#define SWCRLOGINTERFACE_H

#ifdef __GNUG__
//    #pragma interface "swCRLogInterface.h"
#endif

#include <wxGuiTest/Common.h>

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

