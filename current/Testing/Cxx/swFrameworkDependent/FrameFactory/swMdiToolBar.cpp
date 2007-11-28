///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swMdiToolBar.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swMdiToolBar.h"
#endif

#include "swMdiToolBar.h"

#include "swMainFrame.h"

namespace sw {


MdiToolBar::MdiToolBar (MainFrame *mainFrame, const long style)
{
    // It seems that by default only one toolbar is allowed per frame?
    wxASSERT (mainFrame->GetFrame ()->GetToolBar () == NULL);
    m_realToolBar = new WxToolBar (mainFrame->GetWindow (), -1,
				   wxDefaultPosition, wxDefaultSize, style, 
				   _T("MdiToolBar"));
    mainFrame->GetFrame ()->SetToolBar (m_realToolBar);
}


MdiToolBar::~MdiToolBar ()
{
    // Nothing to do
}


wxWindow * MdiToolBar::GetWindow () const
{
    return m_realToolBar;
}


void MdiToolBar::AddTool (const int toolId, const wxString &label,
            const wxBitmap &bitmap, const wxString &toolTip,
            bool isToggle, bool isToggleOffable)
{
    wxItemKind kind = (isToggle ? wxITEM_CHECK : wxITEM_NORMAL);
    m_realToolBar->AddTool (toolId, label, bitmap, wxNullBitmap, kind,
			    toolTip, _T(""), NULL, isToggleOffable);
}


void MdiToolBar::AddControl (wxWindow *control)
{
    wxASSERT (control != NULL);
    wxControl *realControl = dynamic_cast< wxControl * >(control);
    wxASSERT_MSG (realControl != NULL, _T("Takes only wxControl"));
    m_realToolBar->AddControl (realControl);
}


void MdiToolBar::AddSeparator ()
{
    m_realToolBar->AddSeparator ();
}


void MdiToolBar::EnableTool (const int toolId, const bool enable)
{
    m_realToolBar->EnableTool (toolId, enable);
}


void MdiToolBar::RemoveTool (const int toolId)
{
    m_realToolBar->DeleteTool (toolId);
}


void MdiToolBar::ToggleTool (const int toolId, const bool enable)
{
    m_realToolBar->ToggleTool (toolId, enable);
}


bool MdiToolBar::IsToggledOn (const int toolId)
{
    return m_realToolBar->GetToolState (toolId);
}


void MdiToolBar::Realize (cbDimInfo *dimInfo, int alignment)
{
    m_realToolBar->Realize ();
    if (m_realToolBar->GetWindowStyle () & wxTB_HORIZONTAL) {

        m_realToolBar->SetRows (1);
    }
}


bool MdiToolBar::Show (bool show)
{
    return m_realToolBar->Show (show);
}

} // End namespace sw

