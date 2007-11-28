///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRTextUpdateEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRTEXTUPDATEEVENT_H
#define SWCRTEXTUPDATEEVENT_H

#ifdef __GNUG__
    #pragma interface "swCRTextUpdateEvent.h"
#endif

#include "Common.h"

#include "swCRCapturedEvent.h"

namespace swTst {


/*! \class CRTextUpdateEvent
    \brief Handles text update events.
*/
class CRTextUpdateEvent : public CRCapturedEvent
{
public:
    /*! \fn CRTextUpdateEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRTextUpdateEvent (wxEvent *event);


    /*! \fn virtual ~CRTextUpdateEvent ()
        \brief Destructor
    */
    virtual ~CRTextUpdateEvent ();


    /*! \fn virtual bool IsPending () const
        \brief Return true because text update events are assembled into one.

        \return true
    */
    virtual bool IsPending () const;


    /*! \fn virtual bool IsIrrelevant () const
        \brief Return true for text updates of double typed spin controls.

        \return true, if this event is irrelevant
    */
    virtual bool IsIrrelevant () const;

    
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
    /*! \fn virtual wxString GetEscaped (const wxString &str) const
        \brief Make given string escaped (e.g. "\" -> "\\"); used for emitting
        new text value.

        \param str string to escape
        \return escaped string
    */
    virtual wxString GetEscaped (const wxString &str) const;

private:
    wxString m_containerName;
    wxString m_textCtrlName;
    wxString m_textCtrlValue;
    bool m_isIrrelevant;
    bool m_isXRC;

private:
    // No copy and assignment constructor:
    CRTextUpdateEvent (const CRTextUpdateEvent &rhs);
    CRTextUpdateEvent & operator= (const CRTextUpdateEvent &rhs);
};

} // End namespace swTst

#endif // SWCRTEXTUPDATEEVENT_H

