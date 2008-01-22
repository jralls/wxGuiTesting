///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRTreeItemRightClickEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRTREEITEMRIGHTCLICKEVENT_H
#define SWCRTREEITEMRIGHTCLICKEVENT_H

#ifdef __GNUG__
    #pragma interface "CRTreeItemRightClickEvent.h"
#endif

#include <wxGuiTest/Common.h>

#include "CRAbstractTreeEvent.h"

namespace wxTst {


/*! \class CRTreeItemRightClickEvent
    \brief Handle tree item right click events.
*/
class CRTreeItemRightClickEvent : public CRAbstractTreeEvent
{
public:
    /*! \fn CRTreeItemRightClickEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRTreeItemRightClickEvent (wxEvent *event);


    /*! \fn virtual ~CRTreeItemRightClickEvent ()
        \brief Destructor
    */
    virtual ~CRTreeItemRightClickEvent ();


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

    // No copy and assignment constructor:
    CRTreeItemRightClickEvent (const CRTreeItemRightClickEvent &rhs);
    CRTreeItemRightClickEvent & operator= (const CRTreeItemRightClickEvent &rhs);
};

} // End namespace wxTst

#endif // SWCRTREEITEMRIGHTCLICKEVENT_H

