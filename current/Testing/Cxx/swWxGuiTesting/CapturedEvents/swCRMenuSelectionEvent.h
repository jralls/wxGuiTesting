///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRMenuSelectionEvent.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRMENUSELECTIONEVENT_H
#define SWCRMENUSELECTIONEVENT_H

#ifdef __GNUG__
    #pragma interface "swCRMenuSelectionEvent.h"
#endif

#include "Common.h"

#include "swCRCapturedEvent.h"

namespace swTst {


/*! \class CRMenuSelectionEvent
    \brief Handles menu (item) selection events.

    Becaue toolbar tools use the same event type identifier, this class has to
    handle tools as well.
*/
class CRMenuSelectionEvent : public CRCapturedEvent
{
public:
    /*! \fn CRMenuSelectionEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRMenuSelectionEvent (wxEvent *event);


    /*! \fn virtual ~CRMenuSelectionEvent ()
        \brief Destructor
    */
    virtual ~CRMenuSelectionEvent ();


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
    bool m_isTool;
    
    bool m_isFromMainFrameMenuBar;
    bool m_isFromTopWindow;
    bool m_isFromPopupMenu;
    bool m_isChecked;

    wxString m_menuLabel;
    wxString m_menuItemLabel;
    wxString m_popupMenuKey;
    wxString m_popupMenuContainerName;

    bool m_isStdId;
    wxString m_toolbarName;
    wxString m_guiObjName;

private:
    // No copy and assignment constructor:
    CRMenuSelectionEvent (const CRMenuSelectionEvent &rhs);
    CRMenuSelectionEvent & operator= (const CRMenuSelectionEvent &rhs);
};

} // End namespace swTst

#endif // SWCRMENUSELECTIONEVENT_H

