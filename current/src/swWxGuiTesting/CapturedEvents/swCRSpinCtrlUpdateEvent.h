///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRSpinCtrlUpdateEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRSPINCTRLUPDATEEVENT_H
#define SWCRSPINCTRLUPDATEEVENT_H

#ifdef __GNUG__
    #pragma interface "swCRSpinCtrlUpdateEvent.h"
#endif

#include <wxGuiTest/Common.h>

#include "swCRCapturedEvent.h"

namespace swTst {


/*! \class CRSpinCtrlUpdateEvent
    \brief Handle spin control update events (standard + double typed one).
*/
class CRSpinCtrlUpdateEvent : public CRCapturedEvent
{
public:
    /*! \fn CRSpinCtrlUpdateEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRSpinCtrlUpdateEvent (wxEvent *event);


    /*! \fn virtual ~CRSpinCtrlUpdateEvent ()
        \brief Destructor
    */
    virtual ~CRSpinCtrlUpdateEvent ();


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
    wxString m_spinCtrlName;
    double m_spinCtrlDblValue;
    int m_spinCtrlValue;

private:
    // No copy and assignment constructor:
    CRSpinCtrlUpdateEvent (const CRSpinCtrlUpdateEvent &rhs);
    CRSpinCtrlUpdateEvent & operator= (const CRSpinCtrlUpdateEvent &rhs);
};

} // End namespace swTst

#endif // SWCRSPINCTRLUPDATEEVENT_H

