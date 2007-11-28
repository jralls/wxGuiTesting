///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swWxGuiTestEvtSimHlpEvtHandler.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swWxGuiTestEvtSimHlpEvtHandler.h"
#endif

#include "swWxGuiTestEvtSimHlpEvtHandler.h"

#include "cppunit/TestAssert.h"

#include "wx/xrc/xmlres.h"

#include "wx/spinctrl.h"
#include "wx/notebook.h"

#include "swWxGuiTestHelper.h"
#include "swFrameFactory.h"
#include "swMdiFrameFactory.h"
#include "swToolBarRegistry.h"

BEGIN_EVENT_TABLE(swTst::WxGuiTestEvtSimHlpEvtHandler, wxEvtHandler)
    EVT_MENU( XRCID("MenuItem"), WxGuiTestEvtSimHlpEvtHandler::OnMenuItem )
    EVT_MENU( XRCID("CheckableMenuItem"), WxGuiTestEvtSimHlpEvtHandler::OnCheckableMenuItem )
    EVT_BUTTON( XRCID("Button"), WxGuiTestEvtSimHlpEvtHandler::OnButtonClick )
    EVT_TEXT( XRCID("TextCtrl"), WxGuiTestEvtSimHlpEvtHandler::OnTextCtrlChange )
    EVT_SPINCTRL( XRCID("SpinCtrlDbl"), WxGuiTestEvtSimHlpEvtHandler::OnSpinCtrlDblChange )
    EVT_TREE_SEL_CHANGED( XRCID("TreeCtrl"), WxGuiTestEvtSimHlpEvtHandler::OnTreeSelChange )
    EVT_TREE_ITEM_RIGHT_CLICK( XRCID("TreeCtrl"), WxGuiTestEvtSimHlpEvtHandler::OnTreeItemRightClick )
    EVT_NOTEBOOK_PAGE_CHANGED( XRCID("Notebook"), WxGuiTestEvtSimHlpEvtHandler::OnNotebookPageChange )
    EVT_CHOICE( XRCID("Choice"), WxGuiTestEvtSimHlpEvtHandler::OnChoiceSelChange )
    EVT_CHECKBOX( XRCID("Checkbox"), WxGuiTestEvtSimHlpEvtHandler::OnCheckboxChecking )
    EVT_RADIOBOX( XRCID("RadioBox"), WxGuiTestEvtSimHlpEvtHandler::OnRadioBoxSelChange )
    EVT_COMMAND_SCROLL( XRCID("Slider"), WxGuiTestEvtSimHlpEvtHandler::OnSliderChange )
    EVT_SPINCTRL( XRCID("SpinCtrl"), WxGuiTestEvtSimHlpEvtHandler::OnSpinCtrlChange )
    EVT_TOOL( XRCID("Tool"), WxGuiTestEvtSimHlpEvtHandler::OnToggleTool )
    EVT_TOOL( XRCID("ToggleTool"), WxGuiTestEvtSimHlpEvtHandler::OnToggleCheckableTool )
END_EVENT_TABLE()

namespace swTst {


WxGuiTestEvtSimHlpEvtHandler::WxGuiTestEvtSimHlpEvtHandler (wxFrame *frame)
{
    m_frame = frame;

    this->Init ();
}


WxGuiTestEvtSimHlpEvtHandler::~WxGuiTestEvtSimHlpEvtHandler ()
{
    // Nothing to do
}


void WxGuiTestEvtSimHlpEvtHandler::Init ()
{
    m_menuItemSelProcessed = false;
    m_chkMenuItemSelProcessed = false;
    m_buttonClickProcessed = false;
    m_textCtrlValChangeEvent = false;
    m_spinCtrlDblValChangeEvent = false;
    m_treeSelProcessed = false;
    m_treeItemRightClickProcessed = false;
    m_notebookPageSelProcessed = false;
    m_choiceSelProcessed = false;
    m_checkboxChkgProcessed = false;
    m_radioBoxSelProcessed = false;
    m_sliderChangeProcessed = false;
    m_spinCtrlChangeProcessed = false;
    m_toolTogglingProcessed = false;
    m_checkableToolTogglingProcessed = false;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasMenuItemSelProcessed () const
{
    return m_menuItemSelProcessed;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasCheckableMenuItemProcessed () const
{
    return m_chkMenuItemSelProcessed;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasButtonClickProcessed () const
{
    return m_buttonClickProcessed;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasTextCtrlValChgProcessed () const
{
    return m_textCtrlValChangeEvent;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasSpinCtrlDblValChgWithoutEvtProcessed () const
{
    return m_spinCtrlDblValChangeEvent;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasTreeItemSelProcessed () const
{
    return m_treeSelProcessed;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasTreeItemRightClickProcessed () const
{
    return m_treeItemRightClickProcessed;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasNotebookPageSelProcessed () const
{
    return m_notebookPageSelProcessed;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasChoiceSelProcessed () const
{
    return m_choiceSelProcessed;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasCheckboxCheckingProcessed () const
{
    return m_checkboxChkgProcessed;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasRadioBoxSelProcessed () const
{
    return m_radioBoxSelProcessed;
}

bool WxGuiTestEvtSimHlpEvtHandler::HasSliderValChgProcessed () const
{
    return m_sliderChangeProcessed;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasSpinCtrlValChgProcessed () const
{
    return m_spinCtrlChangeProcessed;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasToolTogglingProcessed () const
{
    return m_toolTogglingProcessed;
}


bool WxGuiTestEvtSimHlpEvtHandler::HasCheckableToolTogglingProcessed () const
{
    return m_checkableToolTogglingProcessed;
}


void WxGuiTestEvtSimHlpEvtHandler::OnMenuItem (wxCommandEvent& event)
{
    wxASSERT_MSG (m_menuItemSelProcessed == false,
            "Menu item event handler has already been processed");

    m_menuItemSelProcessed = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnCheckableMenuItem (wxCommandEvent& event)
{
    wxASSERT_MSG (m_chkMenuItemSelProcessed == false,
            "Checkable menu item event handler has already been processed");

    m_chkMenuItemSelProcessed = !m_chkMenuItemSelProcessed;
}


void WxGuiTestEvtSimHlpEvtHandler::OnButtonClick (wxCommandEvent& event)
{
    wxASSERT_MSG (m_buttonClickProcessed == false,
            "Button event handler has already been processed");

    m_buttonClickProcessed = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnTextCtrlChange (wxCommandEvent& event)
{
    wxASSERT_MSG (m_textCtrlValChangeEvent == false,
            "Text control event handler has already been processed");

    m_textCtrlValChangeEvent = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnSpinCtrlDblChange (wxSpinEvent& event)
{
    wxASSERT_MSG (m_spinCtrlDblValChangeEvent == false,
            "Double typed spin control event handler has already been processed");

    m_spinCtrlDblValChangeEvent = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnTreeSelChange (wxTreeEvent &event)
{
    // Under MSW this event is fired more than once:
//    wxASSERT_MSG (m_treeSelProcessed == false,
//            "Tree selection event handler has already been processed");
    m_treeSelProcessed = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnTreeItemRightClick (wxTreeEvent &event)
{
    wxASSERT_MSG (m_treeItemRightClickProcessed == false,
            "Tree item right click event handler has already been processed");

    m_treeItemRightClickProcessed = true;

    wxMenu *m = new wxMenu ("PopupMenu");
    m->Append (1234, "PopupMenuItem");
    wxPoint p (0, 0);
    WxGuiTestHelper::PopupMenu ((wxTreeCtrl *) event.GetEventObject (), m,
            event.GetPoint (), "sccDatasetBrowserPopupMenu");
}


void WxGuiTestEvtSimHlpEvtHandler::OnNotebookPageChange (wxNotebookEvent &event)
{
    wxASSERT_MSG (m_notebookPageSelProcessed == false,
            "Notebook page change event handler has already been processed");

    m_notebookPageSelProcessed = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnChoiceSelChange (wxCommandEvent &event)
{
    wxASSERT_MSG (m_choiceSelProcessed == false,
            "Choice selection change event handler has already been processed");

    m_choiceSelProcessed = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnCheckboxChecking (wxCommandEvent &event)
{
    wxASSERT_MSG (m_checkboxChkgProcessed == false,
            "Checkbox checking event handler has already been processed");

    m_checkboxChkgProcessed = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnRadioBoxSelChange (wxCommandEvent &event)
{
    wxASSERT_MSG (m_radioBoxSelProcessed == false,
            "Radio box selection event handler has already been processed");

    m_radioBoxSelProcessed = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnSliderChange (wxScrollEvent &event)
{
    wxASSERT_MSG (m_sliderChangeProcessed == false,
            "Slider change event handler has already been processed");

    m_sliderChangeProcessed = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnSpinCtrlChange (wxSpinEvent &event)
{
    wxASSERT_MSG (m_spinCtrlChangeProcessed == false,
            "Spin control change event handler has already been processed");

    m_spinCtrlChangeProcessed = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnToggleTool (wxCommandEvent& event)
{
    wxASSERT_MSG (m_toolTogglingProcessed == false,
            "Toggle tool event handler has already been processed");

    m_toolTogglingProcessed = true;
}


void WxGuiTestEvtSimHlpEvtHandler::OnToggleCheckableTool (wxCommandEvent& event)
{
    wxASSERT_MSG (m_checkableToolTogglingProcessed == false,
            "Checkable toggle tool event handler has already been processed");

    m_checkableToolTogglingProcessed = true;
}

} // End namespace swTst
