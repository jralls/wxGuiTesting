///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRButtonClickEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRBUTTONCLICKEVENT_H
#define SWCRBUTTONCLICKEVENT_H

#ifdef __GNUG__
    #pragma interface "CRButtonClickEvent.h"
#endif

#include <wxGuiTest/Common.h>

#include "CRCapturedEvent.h"

namespace wxTst {


/*! \class CRButtonClickEvent
    \brief Handles button click events.
*/
class CRButtonClickEvent : public CRCapturedEvent
{
public:
    /*! \fn CRButtonClickEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRButtonClickEvent (wxEvent *event);


    /*! \fn virtual ~CRButtonClickEvent ()
        \brief Destructor
    */
    virtual ~CRButtonClickEvent ();


    /*! \fn virtual void Process (CRCapturedEvent **pendingEvt)
        \brief Process event, only called after checking for handling ability.
    
        \param pendingEvt current pending event with respect to code emitting
            (or NULL if none is pending)
    */
    virtual void Process (CRCapturedEvent **pendingEvt);


    /*! \fn virtual void EmitCpp ()
        \brief Emit event simulation specific C++ code.
    */
    virtual void EmitCpp ();

protected:

private:
    wxString m_containerName;
    wxString m_buttonName;

    // No copy and assignment constructor:
    CRButtonClickEvent (const CRButtonClickEvent &rhs);
    CRButtonClickEvent & operator= (const CRButtonClickEvent &rhs);
};

} // End namespace wxTst

#endif // SWCRBUTTONCLICKEVENT_H

