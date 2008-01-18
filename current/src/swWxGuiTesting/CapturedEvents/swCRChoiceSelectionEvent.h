///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRChoiceSelectionEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRCHOICESELECTIONEVENT_H
#define SWCRCHOICESELECTIONEVENT_H

#ifdef __GNUG__
    #pragma interface "swCRChoiceSelectionEvent.h"
#endif

#include <wxGuiTest/Common.h>

#include "swCRCapturedEvent.h"

namespace swTst {


/*! \class CRChoiceSelectionEvent
    \brief Handle choice selection events.
*/
class CRChoiceSelectionEvent : public CRCapturedEvent
{
public:
    /*! \fn CRChoiceSelectionEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRChoiceSelectionEvent (wxEvent *event);


    /*! \fn virtual ~CRChoiceSelectionEvent ()
        \brief Destructor
    */
    virtual ~CRChoiceSelectionEvent ();


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
    wxString m_choiceName;
    wxString m_choiceValue;

private:
    // No copy and assignment constructor:
    CRChoiceSelectionEvent (const CRChoiceSelectionEvent &rhs);
    CRChoiceSelectionEvent & operator= (const CRChoiceSelectionEvent &rhs);
};

} // End namespace swTst

#endif // SWCRCHOICESELECTIONEVENT_H

