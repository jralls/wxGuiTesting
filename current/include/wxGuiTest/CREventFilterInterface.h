///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CREventFilterInterface.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef CREVENTFILTERINTERFACE_H
#define CREVENTFILTERINTERFACE_H

#ifdef __GNUG__
//    #pragma interface "CREventFilterInterface.h"
#endif

#include <wxGuiTest/Common.h>

namespace wxTst {


/*! \class CREventFilterInterface
    \brief Declare interface for event filtering required by capturing.
*/
class CREventFilterInterface
{
public:
    /*! \fn virtual ~CREventFilterInterface ()
        \brief Destructor
    */
    virtual ~CREventFilterInterface () { /* Nothing to do */ };


    /*! \fn virtual void FilterEvent (wxEvent& event) = 0
        \brief Filter all events in capturing mode.

        \param event event to process
    */
    virtual void FilterEvent (wxEvent& event) = 0;

};

} // End namespace wxTst

#endif // CREVENTFILTERINTERFACE_H

