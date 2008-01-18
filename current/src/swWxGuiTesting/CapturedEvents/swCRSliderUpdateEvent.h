///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRSliderUpdateEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRSLIDERUPDATEEVENT_H
#define SWCRSLIDERUPDATEEVENT_H

#ifdef __GNUG__
    #pragma interface "swCRSliderUpdateEvent.h"
#endif

#include <wxGuiTest/Common.h>

#include "swCRCapturedEvent.h"

namespace swTst {


/*! \class CRSliderUpdateEvent
    \brief Handle slider update events.

    Understandably, moving the slider creates several events -- intermediate
    positions are taken into account as well; cf. text control text update
    events. Moreover, a range of different events are created:
      - wxEVT_COMMAND_SLIDER_UPDATED, wxEVT_SCROLL_THUMBTRACK continuously;
      - wxEVT_SCROLL_THUMBRELEASE and wxEVT_SCROLL_ENDSCROLL (only MS Windows)
        at the end.

    TODO: Maybe sometimes it is desirable to create intermediate events, so capturing
    wxEVT_SCROLL_THUMBRELEASE should be used in general, and for in special
    cases (where intermediate events are of interest) this behaviour should be
    switched to on???
*/
class CRSliderUpdateEvent : public CRCapturedEvent
{
public:
    /*! \fn CRSliderUpdateEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRSliderUpdateEvent (wxEvent *event);


    /*! \fn virtual ~CRSliderUpdateEvent ()
        \brief Destructor
    */
    virtual ~CRSliderUpdateEvent ();


    /*! \fn virtual bool IsPending () const
        \brief Return true because slider update events are assembled into one.

        \return true
    */
    virtual bool IsPending () const;

    
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
    wxString m_sliderName;
    int m_sliderValue;

    // No copy and assignment constructor:
    CRSliderUpdateEvent (const CRSliderUpdateEvent &rhs);
    CRSliderUpdateEvent & operator= (const CRSliderUpdateEvent &rhs);
};

} // End namespace swTst

#endif // SWCRSLIDERUPDATEEVENT_H

