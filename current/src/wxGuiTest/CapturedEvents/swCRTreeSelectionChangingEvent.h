///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRTreeSelectionChangingEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRTREESELECTIONCHANGINGEVENT_H
#define SWCRTREESELECTIONCHANGINGEVENT_H

#ifdef __GNUG__
    #pragma interface "CRTreeSelectionChangingEvent.h"
#endif

#include <wxGuiTest/Common.h>

#include "CRAbstractTreeEvent.h"

namespace wxTst {


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

private:
    // No copy and assignment constructor:
    CRTreeSelectionChangingEvent (const CRTreeSelectionChangingEvent &rhs);
    CRTreeSelectionChangingEvent & operator= (const CRTreeSelectionChangingEvent &rhs);
};

} // End namespace wxTst

#endif // SWCRTREESELECTIONCHANGINGEVENT_H

