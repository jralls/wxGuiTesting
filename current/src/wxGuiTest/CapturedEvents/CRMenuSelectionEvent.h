///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRMenuSelectionEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRMENUSELECTIONEVENT_H
#define SWCRMENUSELECTIONEVENT_H

#ifdef __GNUG__
    #pragma interface "CRMenuSelectionEvent.h"
#endif

#include <wxGuiTest/Common.h>
#include <wx/frame.h>

#include "CRCapturedEvent.h"

namespace wxTst {


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
    
    bool m_isFromTopWindow;
    bool m_eventObjectIsMenu;
    bool m_isFromPopupMenu;
    bool m_isChecked;

    wxString m_menuLabel;
    wxString m_menuItemLabel;
    wxString m_popupMenuKey;
    wxString m_parentContainerName;

    wxString m_toolbarName;
    bool m_isControl;
    wxString m_controlName;

private:
    // No copy and assignment constructor:
    CRMenuSelectionEvent (const CRMenuSelectionEvent &rhs);
    CRMenuSelectionEvent & operator= (const CRMenuSelectionEvent &rhs);
    void processCheckable();
    void processMainMenu(wxMenuBar* menuBar);
    bool processPopUp (wxMenu* menu);
    bool processToolBar(wxToolBar *toolBar);
    bool processTopMenu(wxMenu* menu);
    bool processTopFrame(wxFrame* topFrame);
};

} // End namespace wxTst

#endif // SWCRMENUSELECTIONEVENT_H

