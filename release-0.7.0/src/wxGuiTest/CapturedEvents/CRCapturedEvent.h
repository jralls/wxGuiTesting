///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRCapturedEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRCAPTUREDEVENT_H
#define SWCRCAPTUREDEVENT_H

#ifdef __GNUG__
    #pragma interface "CRCapturedEvent.h"
#endif

#include <wxGuiTest/Common.h>

namespace wxTst {


/*! \class CRCapturedEvent
    \brief Abstract parent class for all events to capture of interest.

    Implemented using Strategy pattern.
*/
class CRCapturedEvent
{
public:
    /*! \fn CRCapturedEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRCapturedEvent (wxEvent *event);


    /*! \fn virtual ~CRCapturedEvent ()
        \brief Destructor
    */
    virtual ~CRCapturedEvent ();


    /*! \fn virtual wxEvent * GetEvent ()
        \brief Get real wxEvent.

        \return real wxEvent
    */
    virtual wxEvent * GetEvent ();


    /*! \fn virtual bool IsPending () const
        \brief Return true, if this event might be part of a series of events.

        E.g. Entering text in text controls creates wxEVT_COMMAND_TEXT_UPDATED
        events for every key stroke. Thus, they should be assembled into one.

        Process() method is called before, allowing investigating the context.

        \return true, if this event is not stand-alone
    */
    virtual bool IsPending () const;


    /*! \fn virtual bool IsIrrelevant () const
        \brief Return true for irrelevant events which should not be emitted.

        E.g. text updates of double typed spin controls.

        \return true, if this event is irrelevant
    */
    virtual bool IsIrrelevant () const;


    /*! \fn virtual void Process (CRCapturedEvent **pendingEvt) = 0
        \brief Process event, only called after checking for handling ability.

        By handing over the current pending event assembling a series of events
        before actual code emitting is allowed, cf. IsPending() method.

        The pending event will be emitted and subsequently destroyed right
        after returning control from this method. Thus, if a pending event
        should not be emitted, because it is assembled in this new event it
        must be deleted within this method.

        \param pendingEvt current pending event with respect to code emitting
            (or NULL if none is pending)
    */
    virtual void Process (CRCapturedEvent **pendingEvt) = 0;


    /*! \fn virtual void EmitCpp () = 0
        \brief Emit event simulation specific C++ code using CRCppEmitter.
    */
    virtual void EmitCpp () = 0;

protected:
    wxEvent *m_event;

private:

private:
    // No copy and assignment constructor:
    CRCapturedEvent (const CRCapturedEvent &rhs);
    CRCapturedEvent & operator= (const CRCapturedEvent &rhs);
};

} // End namespace wxTst

#endif // SWCRCAPTUREDEVENT_H

