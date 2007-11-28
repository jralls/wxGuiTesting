///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRTreeSelectionChangingEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRTREESELECTIONCHANGINGEVENT_H
#define SWCRTREESELECTIONCHANGINGEVENT_H

#ifdef __GNUG__
    #pragma interface "swCRTreeSelectionChangingEvent.h"
#endif

#include "Common.h"

#include "swCRAbstractTreeEvent.h"

namespace swTst {


/*! \class CRTreeSelectionChangingEvent
    \brief Handle tree selection changing events - note: changed vs. changing.

    It seems that just changing the selected tree item is only generating the
    changing event, but not the changed event?
*/
class CRTreeSelectionChangingEvent : public CRAbstractTreeEvent
{
public:
    /*! \fn CRTreeSelectionChangingEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRTreeSelectionChangingEvent (wxEvent *event);


    /*! \fn virtual ~CRTreeSelectionChangingEvent ()
        \brief Destructor
    */
    virtual ~CRTreeSelectionChangingEvent ();


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
    wxString m_treeCtrlName;
    bool m_isXRC;

private:
    // No copy and assignment constructor:
    CRTreeSelectionChangingEvent (const CRTreeSelectionChangingEvent &rhs);
    CRTreeSelectionChangingEvent & operator= (const CRTreeSelectionChangingEvent &rhs);
};

} // End namespace swTst

#endif // SWCRTREESELECTIONCHANGINGEVENT_H

