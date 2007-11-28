///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRButtonClickEvent.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRBUTTONCLICKEVENT_H
#define SWCRBUTTONCLICKEVENT_H

#ifdef __GNUG__
    #pragma interface "swCRButtonClickEvent.h"
#endif

#include "Common.h"

#include "swCRCapturedEvent.h"

namespace swTst {


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
    bool m_isXRC;

private:
    // No copy and assignment constructor:
    CRButtonClickEvent (const CRButtonClickEvent &rhs);
    CRButtonClickEvent & operator= (const CRButtonClickEvent &rhs);
};

} // End namespace swTst

#endif // SWCRBUTTONCLICKEVENT_H

