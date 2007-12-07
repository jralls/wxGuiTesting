///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRCheckBoxClickEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRCHECKBOXCLICKEVENT_H
#define SWCRCHECKBOXCLICKEVENT_H

#ifdef __GNUG__
    #pragma interface "swCRCheckBoxClickEvent.h"
#endif

#include <wxGuiTest/Common.h>

#include "swCRCapturedEvent.h"

namespace swTst {


/*! \class CRCheckBoxClickEvent
    \brief Handle check box click events.
*/
class CRCheckBoxClickEvent : public CRCapturedEvent
{
public:
    /*! \fn CRCheckBoxClickEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRCheckBoxClickEvent (wxEvent *event);


    /*! \fn virtual ~CRCheckBoxClickEvent ()
        \brief Destructor
    */
    virtual ~CRCheckBoxClickEvent ();


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
    wxString m_checkBoxName;
    bool m_isChecked;
    bool m_isXRC;

private:
    // No copy and assignment constructor:
    CRCheckBoxClickEvent (const CRCheckBoxClickEvent &rhs);
    CRCheckBoxClickEvent & operator= (const CRCheckBoxClickEvent &rhs);
};

} // End namespace swTst

#endif // SWCRCHECKBOXCLICKEVENT_H

