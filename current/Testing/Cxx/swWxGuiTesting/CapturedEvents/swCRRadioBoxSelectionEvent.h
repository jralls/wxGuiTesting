///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRRadioBoxSelectionEvent.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRRADIOBOXSELECTIONEVENT_H
#define SWCRRADIOBOXSELECTIONEVENT_H

#ifdef __GNUG__
    #pragma interface "swCRRadioBoxSelectionEvent.h"
#endif

#include "Common.h"

#include "swCRCapturedEvent.h"

namespace swTst {


/*! \class CRRadioBoxSelectionEvent
    \brief Handle radio box selection events.
*/
class CRRadioBoxSelectionEvent : public CRCapturedEvent
{
public:
    /*! \fn CRRadioBoxSelectionEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRRadioBoxSelectionEvent (wxEvent *event);


    /*! \fn virtual ~CRRadioBoxSelectionEvent ()
        \brief Destructor
    */
    virtual ~CRRadioBoxSelectionEvent ();


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
    wxString m_radioBoxName;
    wxString m_radioBoxValue;
    bool m_isXRC;

private:
    // No copy and assignment constructor:
    CRRadioBoxSelectionEvent (const CRRadioBoxSelectionEvent &rhs);
    CRRadioBoxSelectionEvent & operator= (const CRRadioBoxSelectionEvent &rhs);
};

} // End namespace swTst

#endif // SWCRRADIOBOXSELECTIONEVENT_H

