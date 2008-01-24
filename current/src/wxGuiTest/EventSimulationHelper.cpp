///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/EventSimulationHelper.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "EventSimulationHelper.h"
#endif

#include <wxGuiTest/EventSimulationHelper.h>

#include <cppunit/TestAssert.h>

#include <wx/treectrl.h>
#include <wx/notebook.h>
#include <wx/spinctrl.h>

using namespace wxTst;


bool EventSimulationHelper::s_isSettingSpinCtrlValue = false;


EventSimulationHelper::EventSimulationHelper ()
{
    // Nothing to do
}


EventSimulationHelper::~EventSimulationHelper ()
{
    // Nothing to do
}


void EventSimulationHelper::SelectMenuItem (int id, wxWindow *frame)
{
    wxCommandEvent evt (wxEVT_COMMAND_MENU_SELECTED, id);
    evt.SetEventObject (frame);
    ::wxPostEvent (frame->GetEventHandler (), evt);
    // Or, not/less recommend - processing event directly:
    //frame->GetEventHandler ()->ProcessEvent (evt);
}


void EventSimulationHelper::SelectMenuItem (int id,
        wxEvtHandler *evtHandler)
{
    wxCommandEvent evt (wxEVT_COMMAND_MENU_SELECTED, id);
    evt.SetEventObject (evtHandler);
    ::wxPostEvent (evtHandler, evt);
}


void EventSimulationHelper::SelectAndCheckMenuItem (int id,
        wxWindow *window, wxMenu **menu)
{
    // 1. GUI control state:
    wxMenuItem *menuItem = NULL;
    if (menu == NULL) {

        wxFrame *frame = wxDynamicCast (window, wxFrame);
        CPPUNIT_ASSERT_MESSAGE ("'window' is not a wxFrame, setting menu is required",
                frame != NULL);
        wxMenuBar *menuBar = frame->GetMenuBar ();
        CPPUNIT_ASSERT_MESSAGE ("'window' being a wxFrame does not contain a menu bar",
                menuBar != NULL);
        menuItem = menuBar->FindItem (id);
        CPPUNIT_ASSERT_MESSAGE ("Menu item specified with 'id' not found in menu bar",
                menuItem != NULL);

    } else {

        menuItem = (*menu)->FindItem (id, menu);
        CPPUNIT_ASSERT_MESSAGE ("Menu item specified with 'id' not found in 'menu'",
                menuItem != NULL);
    }
    menuItem->Check (!menuItem->IsChecked ());
    // 2. Event: (Code duplication WRT SelectMenuItem() method on purpose!)
    wxCommandEvent evt (wxEVT_COMMAND_MENU_SELECTED, id);
    evt.SetEventObject (window);
    evt.SetInt (1);
    ::wxPostEvent (window->GetEventHandler (), evt);
}


void EventSimulationHelper::SelectAndCheckMenuItem (int id, wxMenu *menu)
{
    // 1. GUI control state:
    wxMenuItem *menuItem = menu->FindItem (id, &menu);
    CPPUNIT_ASSERT_MESSAGE ("Menu item specified with 'id' not found in 'menu'",
            menuItem != NULL);
    menuItem->Check (!menuItem->IsChecked ());
    // 2. Event: (Code duplication WRT SelectMenuItem() method on purpose!)
    wxCommandEvent evt (wxEVT_COMMAND_MENU_SELECTED, id);
    evt.SetEventObject (menu);
    evt.SetInt (1);
    ::wxPostEvent (menu, evt);
}


void EventSimulationHelper::ClickButton (int id, wxWindow *parent)
{
    wxCommandEvent evt (wxEVT_COMMAND_BUTTON_CLICKED, id);
    evt.SetEventObject (parent);
    ::wxPostEvent (parent->GetEventHandler (), evt);
}


void EventSimulationHelper::SetTextCtrlValue (
        wxTextCtrl *textCtrl, const wxString &value)
{
    textCtrl->SetValue (value);
    // Additional event posting was necessary for wx2.7 Linux GTK, but no more for wx2.8:
#ifdef __WXGTK__
# if wxCHECK_VERSION(2, 7, 0)
#  if wxCHECK_VERSION(2, 8, 0)
#  else
    wxCommandEvent evt (wxEVT_COMMAND_TEXT_UPDATED, textCtrl->GetId ());
    evt.SetEventObject (textCtrl);
    evt.SetString (value);
    ::wxPostEvent (textCtrl->GetEventHandler (), evt);
#  endif
# endif
#endif
}


wxTreeItemId EventSimulationHelper::GetNthTreeChild (wxTreeCtrl *treeCtrl, unsigned int idx, const wxTreeItemId &id)
{
    wxASSERT (idx > 0);

    wxTreeItemId cur;
    wxTreeItemIdValue cookie;
    cur = treeCtrl->GetFirstChild (id, cookie);
    for (unsigned int i = 1; i < idx; i++) {

        cur = treeCtrl->GetNextChild (id, cookie);
    }
    
    return cur;
}


void EventSimulationHelper::SelectTreeItem (const wxTreeItemId &id,
        wxTreeCtrl *treeCtrl)
{
    wxTreeEvent evt (wxEVT_COMMAND_TREE_SEL_CHANGED, treeCtrl->GetId ());
    evt.SetItem (id);
    evt.SetEventObject (treeCtrl);
    // Somehow, tree control events need to be processed immediately, instead
    // of being posted - otherwise the event's properties are getting invalid.
    // Very strange!
    //::wxPostEvent (treeCtrl->GetEventHandler (), evt);
    //wxTst::WxGuiTestHelper::FlushEventQueue ();
    treeCtrl->GetEventHandler ()->ProcessEvent (evt);
    // Somehow the selection is not really carried out (not WRT GUI state; and
    // retrieval of current selection seems to be via GUI state):
    treeCtrl->SelectItem (id);
}


void EventSimulationHelper::RightClickTreeItem (
        const wxTreeItemId &id, wxTreeCtrl *treeCtrl)
{
    wxRect treeItemRect;
    bool isOk = treeCtrl->GetBoundingRect (id, treeItemRect, true);
    CPPUNIT_ASSERT_MESSAGE ("Tree item bounding box query failed", isOk);
    
    wxPoint treeItemCenter;
    treeItemCenter.x = treeItemRect.x + treeItemRect.width / 2;
    treeItemCenter.y = treeItemRect.y + treeItemRect.height / 2;

    wxTreeEvent evt (wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK, treeCtrl->GetId ());
    evt.SetItem (id);
    evt.SetPoint (treeItemCenter);
    evt.SetEventObject (treeCtrl);
    // Again, process event immediately:
    //::wxPostEvent (treeCtrl->GetEventHandler (), evt);
    //wxTst::WxGuiTestHelper::FlushEventQueue ();
    treeCtrl->GetEventHandler ()->ProcessEvent (evt);
}


void EventSimulationHelper::SelectNotebookPage (wxNotebook *notebook,
        unsigned int page)
{
    // Event is created automatically!
    notebook->SetSelection (page);
}


void EventSimulationHelper::SelectChoiceItem (wxChoice *choice,
        unsigned int item)
{
    // 1. GUI control state:
    choice->SetSelection (item);
    // 2. Event:
    wxCommandEvent evt (wxEVT_COMMAND_CHOICE_SELECTED, choice->GetId ());
    evt.SetInt (item);
    evt.SetEventObject (choice);
    evt.SetString (choice->GetString (item));
    ::wxPostEvent (choice->GetEventHandler (), evt);
}


void EventSimulationHelper::SetCheckboxState (wxCheckBox *checkbox,
        bool isChecked)
{
    // 1. GUI control state:
    checkbox->SetValue (isChecked);
    // 2. Event:
    wxCommandEvent evt (wxEVT_COMMAND_CHECKBOX_CLICKED, checkbox->GetId ());
    evt.SetEventObject (checkbox);
    evt.SetInt (isChecked);
    ::wxPostEvent (checkbox->GetEventHandler (), evt);
}


void EventSimulationHelper::SelectRadioBoxItem (wxRadioBox *radioBox,
        unsigned int item)
{
    // 1. GUI control state:
    radioBox->SetSelection (item);
    // 2. Event:
    wxCommandEvent evt (wxEVT_COMMAND_RADIOBOX_SELECTED, radioBox->GetId ());
    evt.SetEventObject (radioBox);
    evt.SetInt (item);
    evt.SetString (radioBox->GetString (item));
    ::wxPostEvent (radioBox->GetEventHandler (), evt);
}


void EventSimulationHelper::SetSliderValue (wxSlider *slider,
        unsigned int value)
{
    // 1. GUI control state:
    slider->SetValue (value);
    // 2. Events:
    wxCommandEvent evt2 (wxEVT_COMMAND_SLIDER_UPDATED, slider->GetId ());
    evt2.SetEventObject (slider);
    evt2.SetInt (value);
    ::wxPostEvent (slider->GetEventHandler (), evt2);

    wxCommandEvent evt (wxEVT_SCROLL_THUMBRELEASE, slider->GetId ());
    evt.SetEventObject (slider);
    evt.SetInt (value);
    ::wxPostEvent (slider->GetEventHandler (), evt);
}


void EventSimulationHelper::SetSpinCtrlValue (wxSpinCtrl *spinCtrl,
        int value)
{
    // 1. GUI control state:
    EventSimulationHelper::s_isSettingSpinCtrlValue = true;
    spinCtrl->SetValue (value);
    EventSimulationHelper::s_isSettingSpinCtrlValue = false;
    // 2. Event:
    wxCommandEvent evt (wxEVT_COMMAND_SPINCTRL_UPDATED, spinCtrl->GetId ());
    evt.SetEventObject (spinCtrl);
    evt.SetInt (value);
    ::wxPostEvent (spinCtrl->GetEventHandler (), evt);
}


bool EventSimulationHelper::IsSettingSpinCtrlValue ()
{
    return EventSimulationHelper::s_isSettingSpinCtrlValue;
}


void EventSimulationHelper::ToggleToolOnlyEvent (int id,
        bool enabled, wxWindow *parent)
{
    wxCommandEvent evt (wxEVT_COMMAND_TOOL_CLICKED, id);
    evt.SetEventObject (parent);
    evt.SetInt (enabled);
    ::wxPostEvent (parent->GetEventHandler (), evt);
}


void EventSimulationHelper::ToggleTool (int id, bool enabled,
        wxToolBar *toolbar, wxWindow *parent)
{
    // 1. GUI control state:
    toolbar->ToggleTool (id, enabled);
    // 2. Event:
    wxCommandEvent evt (wxEVT_COMMAND_TOOL_CLICKED, id);
    evt.SetEventObject (parent);
    evt.SetInt (enabled);//TODO: or 1?
    ::wxPostEvent (parent->GetEventHandler (), evt);
}
