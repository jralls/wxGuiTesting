///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/EvtSimHlpEvtHandler.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "EvtSimHlpEvtHandler.h"
#endif

#include "EvtSimHlpEvtHandler.h"

#include <cppunit/TestAssert.h>

#include <wx/xrc/xmlres.h>

#include <wx/spinctrl.h>
#include <wx/notebook.h>

#include <wxGuiTest/GuiTestHelper.h>

BEGIN_EVENT_TABLE(wxTst::EvtSimHlpEvtHandler, wxEvtHandler)
    EVT_MENU( XRCID("MenuItem"), EvtSimHlpEvtHandler::OnMenuItem )
    EVT_MENU( XRCID("CheckableMenuItem"), EvtSimHlpEvtHandler::OnCheckableMenuItem )
    EVT_BUTTON( XRCID("Button"), EvtSimHlpEvtHandler::OnButtonClick )
    EVT_TEXT( XRCID("TextCtrl"), EvtSimHlpEvtHandler::OnTextCtrlChange )
    EVT_TREE_SEL_CHANGED( XRCID("TreeCtrl"), EvtSimHlpEvtHandler::OnTreeSelChange )
    EVT_TREE_ITEM_RIGHT_CLICK( XRCID("TreeCtrl"), EvtSimHlpEvtHandler::OnTreeItemRightClick )
    EVT_NOTEBOOK_PAGE_CHANGED( XRCID("Notebook"), EvtSimHlpEvtHandler::OnNotebookPageChange )
    EVT_CHOICE( XRCID("Choice"), EvtSimHlpEvtHandler::OnChoiceSelChange )
    EVT_CHECKBOX( XRCID("Checkbox"), EvtSimHlpEvtHandler::OnCheckboxChecking )
    EVT_RADIOBOX( XRCID("RadioBox"), EvtSimHlpEvtHandler::OnRadioBoxSelChange )
    EVT_COMMAND_SCROLL( XRCID("Slider"), EvtSimHlpEvtHandler::OnSliderChange )
    EVT_SPINCTRL( XRCID("SpinCtrl"), EvtSimHlpEvtHandler::OnSpinCtrlChange )
    EVT_TOOL( XRCID("Tool"), EvtSimHlpEvtHandler::OnToggleTool )
    EVT_TOOL( XRCID("ToggleTool"), EvtSimHlpEvtHandler::OnToggleCheckableTool )
END_EVENT_TABLE()

using namespace wxTst;


EvtSimHlpEvtHandler::EvtSimHlpEvtHandler (wxFrame *frame) :
    m_frame(frame)
{
    this->Init ();
}


EvtSimHlpEvtHandler::~EvtSimHlpEvtHandler ()
{
    // Nothing to do
}


void EvtSimHlpEvtHandler::Init ()
{
    m_menuItemSelProcessed = false;
    m_chkMenuItemSelProcessed = false;
    m_buttonClickProcessed = false;
    m_textCtrlValChangeEvent = false;
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


bool EvtSimHlpEvtHandler::HasMenuItemSelProcessed () const
{
    return m_menuItemSelProcessed;
}


bool EvtSimHlpEvtHandler::HasCheckableMenuItemProcessed () const
{
    return m_chkMenuItemSelProcessed;
}


bool EvtSimHlpEvtHandler::HasButtonClickProcessed () const
{
    return m_buttonClickProcessed;
}


bool EvtSimHlpEvtHandler::HasTextCtrlValChgProcessed () const
{
    return m_textCtrlValChangeEvent;
}


bool EvtSimHlpEvtHandler::HasTreeItemSelProcessed () const
{
    return m_treeSelProcessed;
}


bool EvtSimHlpEvtHandler::HasTreeItemRightClickProcessed () const
{
    return m_treeItemRightClickProcessed;
}


bool EvtSimHlpEvtHandler::HasNotebookPageSelProcessed () const
{
    return m_notebookPageSelProcessed;
}


bool EvtSimHlpEvtHandler::HasChoiceSelProcessed () const
{
    return m_choiceSelProcessed;
}


bool EvtSimHlpEvtHandler::HasCheckboxCheckingProcessed () const
{
    return m_checkboxChkgProcessed;
}


bool EvtSimHlpEvtHandler::HasRadioBoxSelProcessed () const
{
    return m_radioBoxSelProcessed;
}

bool EvtSimHlpEvtHandler::HasSliderValChgProcessed () const
{
    return m_sliderChangeProcessed;
}


bool EvtSimHlpEvtHandler::HasSpinCtrlValChgProcessed () const
{
    return m_spinCtrlChangeProcessed;
}


bool EvtSimHlpEvtHandler::HasToolTogglingProcessed () const
{
    return m_toolTogglingProcessed;
}


bool EvtSimHlpEvtHandler::HasCheckableToolTogglingProcessed () const
{
    return m_checkableToolTogglingProcessed;
}


void EvtSimHlpEvtHandler::OnMenuItem (wxCommandEvent& event)
{
    wxASSERT_MSG (m_menuItemSelProcessed == false,
            _T("Menu item event handler has already been processed"));

    m_menuItemSelProcessed = true;
}


void EvtSimHlpEvtHandler::OnCheckableMenuItem (wxCommandEvent& event)
{
    wxASSERT_MSG (m_chkMenuItemSelProcessed == false,
            _T("Checkable menu item event handler has already been processed"));

    m_chkMenuItemSelProcessed = !m_chkMenuItemSelProcessed;
}


void EvtSimHlpEvtHandler::OnButtonClick (wxCommandEvent& event)
{
    wxASSERT_MSG (m_buttonClickProcessed == false,
            _T("Button event handler has already been processed"));

    m_buttonClickProcessed = true;
}


void EvtSimHlpEvtHandler::OnTextCtrlChange (wxCommandEvent& event)
{
    wxASSERT_MSG (m_textCtrlValChangeEvent == false,
            _T("Text control event handler has already been processed"));

    m_textCtrlValChangeEvent = true;
}




void EvtSimHlpEvtHandler::OnTreeSelChange (wxTreeEvent &event)
{
    // Under M this event is fired more than once:
//    wxASSERT_MSG (m_treeSelProcessed == false,
//            _T("Tree selection event handler has already been processed"));
    m_treeSelProcessed = true;
}


void EvtSimHlpEvtHandler::OnTreeItemRightClick (wxTreeEvent &event)
{
    wxASSERT_MSG (m_treeItemRightClickProcessed == false,
            _T("Tree item right click event handler has already been processed"));

    m_treeItemRightClickProcessed = true;

    wxMenu *m = new wxMenu (_T("PopupMenu"));
    m->Append (1234, _T("PopupMenuItem"));
    wxPoint p (0, 0);
    GuiTestHelper::PopupMenu ((wxTreeCtrl *) event.GetEventObject (), m,
            event.GetPoint (), _T("sccDatasetBrowserPopupMenu"));
}


void EvtSimHlpEvtHandler::OnNotebookPageChange (wxNotebookEvent &event)
{
    wxASSERT_MSG (m_notebookPageSelProcessed == false,
            _T("Notebook page change event handler has already been processed"));

    m_notebookPageSelProcessed = true;
}


void EvtSimHlpEvtHandler::OnChoiceSelChange (wxCommandEvent &event)
{
    wxASSERT_MSG (m_choiceSelProcessed == false,
            _T("Choice selection change event handler has already been processed"));

    m_choiceSelProcessed = true;
}


void EvtSimHlpEvtHandler::OnCheckboxChecking (wxCommandEvent &event)
{
    wxASSERT_MSG (m_checkboxChkgProcessed == false,
            _T("Checkbox checking event handler has already been processed"));

    m_checkboxChkgProcessed = true;
}


void EvtSimHlpEvtHandler::OnRadioBoxSelChange (wxCommandEvent &event)
{
    wxASSERT_MSG (m_radioBoxSelProcessed == false,
            _T("Radio box selection event handler has already been processed"));

    m_radioBoxSelProcessed = true;
}


void EvtSimHlpEvtHandler::OnSliderChange (wxScrollEvent &event)
{
    wxASSERT_MSG (m_sliderChangeProcessed == false,
            _T("Slider change event handler has already been processed"));

    m_sliderChangeProcessed = true;
}


void EvtSimHlpEvtHandler::OnSpinCtrlChange (wxSpinEvent &event)
{
    wxASSERT_MSG (m_spinCtrlChangeProcessed == false,
            _T("Spin control change event handler has already been processed"));

    m_spinCtrlChangeProcessed = true;
}


void EvtSimHlpEvtHandler::OnToggleTool (wxCommandEvent& event)
{
    wxASSERT_MSG (m_toolTogglingProcessed == false,
            _T("Toggle tool event handler has already been processed"));

    m_toolTogglingProcessed = true;
}


void EvtSimHlpEvtHandler::OnToggleCheckableTool (wxCommandEvent& event)
{
    wxASSERT_MSG (m_checkableToolTogglingProcessed == false,
            _T("Checkable toggle tool event handler has already been processed"));

    m_checkableToolTogglingProcessed = true;
}
