///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCREventFactory.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCREventFactory.h"
#endif

#include "swCREventFactory.h"

#include <wx/notebook.h>
#include <wx/treectrl.h>

#include "CapturedEvent/swCRButtonClickEvent.h"
#include "CapturedEvent/swCRMenuSelectionEvent.h"
#include "CapturedEvent/swCRTextUpdateEvent.h"
#include "CapturedEvent/swCRNotebookPageChangeEvent.h"
#include "CapturedEvent/swCRChoiceSelectionEvent.h"
#include "CapturedEvent/swCRRadioBoxSelectionEvent.h"
#include "CapturedEvent/swCRCheckBoxClickEvent.h"
#include "CapturedEvent/swCRSliderUpdateEvent.h"
#include "CapturedEvent/swCRSpinCtrlUpdateEvent.h"
#include "CapturedEvent/swCRTreeSelectionChangingEvent.h"
#include "CapturedEvent/swCRTreeItemRightClickEvent.h"

namespace swTst {


// Init single instance:
CREventFactory *CREventFactory::ms_instance = NULL;


CREventFactory::CREventFactory ()
{
    // Nothing to do
}


CREventFactory::~CREventFactory ()
{
    // Nothing to do
}


CREventFactory * CREventFactory::GetInstance ()
{
    if (ms_instance == NULL) {

        ms_instance = new CREventFactory ();
    }
    return ms_instance;
}


void CREventFactory::Destroy ()
{
    if (ms_instance != NULL) {

        delete ms_instance;
        ms_instance = NULL;
    }
}


CRCapturedEvent * CREventFactory::CreateEvent (const wxEvent &event) const
{
    int type = event.GetEventType ();
    if (type == wxEVT_COMMAND_BUTTON_CLICKED) {

        return new CRButtonClickEvent (event.Clone ());

    } else if (type == wxEVT_COMMAND_MENU_SELECTED) {

        return new CRMenuSelectionEvent (event.Clone ());

    } else if (type == wxEVT_COMMAND_TEXT_UPDATED) {

        return new CRTextUpdateEvent (event.Clone ());

    } else if (type == wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED) {

        // Clone() method not implemented:
        //return new CRNotebookPageChangeEvent (new wxNoteevent.Clone ());
        //wxNotebookEvent *orig = wxDynamicCast (event, wxNotebookEvent);
        wxNotebookEvent &orig = (wxNotebookEvent &)(event);
        wxNotebookEvent *clone = new wxNotebookEvent (orig.GetEventType (),
                orig.GetId (), orig.GetSelection (), orig.GetOldSelection ());
        clone->SetEventObject (orig.GetEventObject ());
        return new CRNotebookPageChangeEvent (clone);

    } else if (type == wxEVT_COMMAND_CHOICE_SELECTED) {

        return new CRChoiceSelectionEvent (event.Clone ());

    } else if (type == wxEVT_COMMAND_RADIOBOX_SELECTED) {

        return new CRRadioBoxSelectionEvent (event.Clone ());

    } else if (type == wxEVT_COMMAND_CHECKBOX_CLICKED) {

        return new CRCheckBoxClickEvent (event.Clone ());

    } else if (type == wxEVT_COMMAND_SLIDER_UPDATED) {

        return new CRSliderUpdateEvent (event.Clone ());

    } else if (type == wxEVT_COMMAND_SPINCTRL_UPDATED) {

        return new CRSpinCtrlUpdateEvent (event.Clone ());

    } else if (type == wxEVT_COMMAND_TREE_SEL_CHANGING) {

        // Clone() method not implemented:
        //return return new CRTreeSelectionChangingEvent (event.Clone ());
        //wxTreeEvent *orig = wxDynamicCast (event, wxTreeEvent);
        wxTreeEvent &orig = (wxTreeEvent &)(event);
        // It seems that right clicking on an unselected tree item first
        // creates a changing event without setting the affected tree item:
        if (orig.GetItem ().IsOk ()) {

            wxTreeEvent *clone = new wxTreeEvent (orig.GetEventType (),
                    orig.GetId ());
            clone->SetItem (orig.GetItem ());
            clone->SetPoint (orig.GetPoint ());
            clone->SetLabel (orig.GetLabel ());
            clone->SetEventObject (orig.GetEventObject ());
            return new CRTreeSelectionChangingEvent (clone);
        }

    } else if (type == wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK) {

        // Clone() method not implemented:
        //return return new CRTreeItemRightClickEvent (event.Clone ());
        //wxTreeEvent *orig = wxDynamicCast (event, wxTreeEvent);
        wxTreeEvent &orig = (wxTreeEvent &)(event);
        // It seems that right clicking on an unselected tree item first
        // creates a changing event without setting the affected tree item:
        if (orig.GetItem ().IsOk ()) {

            wxTreeEvent *clone = new wxTreeEvent (orig.GetEventType (),
                    orig.GetId ());
            clone->SetItem (orig.GetItem ());
            clone->SetPoint (orig.GetPoint ());
            clone->SetLabel (orig.GetLabel ());
            clone->SetEventObject (orig.GetEventObject ());
            return new CRTreeItemRightClickEvent (clone);
        }
    }

    return NULL;
}

} // End namespace swTst

