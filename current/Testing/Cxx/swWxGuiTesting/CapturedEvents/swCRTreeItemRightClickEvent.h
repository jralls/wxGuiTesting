///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRTreeItemRightClickEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRTREEITEMRIGHTCLICKEVENT_H
#define SWCRTREEITEMRIGHTCLICKEVENT_H

#ifdef __GNUG__
    #pragma interface "swCRTreeItemRightClickEvent.h"
#endif

#include "Common.h"

#include "swCRAbstractTreeEvent.h"

namespace swTst {


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
    bool m_isXRC;

private:
    // No copy and assignment constructor:
    CRTreeItemRightClickEvent (const CRTreeItemRightClickEvent &rhs);
    CRTreeItemRightClickEvent & operator= (const CRTreeItemRightClickEvent &rhs);
};

} // End namespace swTst

#endif // SWCRTREEITEMRIGHTCLICKEVENT_H

