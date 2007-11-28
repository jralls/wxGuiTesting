///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swMdiMainFrame.cpp
// Author:      Yann Rouillard, Viet Bui Xuan
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swMdiMainFrame.h"
#endif

#include "swMdiMainFrame.h"

#include <wx/config.h> 

#include "swApp.h"

namespace sw {


IMPLEMENT_CLASS (MdiMainWindow, wxDocMDIParentFrame)

BEGIN_EVENT_TABLE(MdiMainWindow, wxDocMDIParentFrame)
	EVT_SIZE (MdiMainWindow::OnSize)
	EVT_MOVE (MdiMainWindow::OnMove)
END_EVENT_TABLE()


MdiMainWindow::MdiMainWindow (wxDocManager* manager, 
									wxFrame *parent, 
									wxWindowID id, 
									const wxString& title, 
									const wxPoint& pos, 
									const wxSize& size,
									long style,
									const wxString& name) :
	wxDocMDIParentFrame (manager, parent, id, title, pos, size, style, name)
{
	m_mainFrame = NULL;
	m_mainWindowMaximize = FALSE;
}

	
MdiMainWindow::~MdiMainWindow ()
{
	wxASSERT (m_mainFrame != NULL);
	delete m_mainFrame;
}


void MdiMainWindow::SetMainFrame (MainFrame *mainFrame)
{
	m_mainFrame = mainFrame;
}


void MdiMainWindow::OnSize(wxSizeEvent& event)
{
	if (IsMaximized ()) {
		
		m_mainWindowMaximize = TRUE;
		
	} else {

		m_mainWindowSize = GetSize ();
		m_mainWindowMaximize = FALSE;
	}

	event.Skip ();
}


void MdiMainWindow::OnMove(wxMoveEvent& event)
{
	if (!IsMaximized ()) {
	
		m_mainWindowPosition = GetPosition ();
	}
}


wxSize &MdiMainWindow::GetMainWindowSize ()
{
	return m_mainWindowSize;
}


wxPoint &MdiMainWindow::GetMainWindowPosition ()
{
	return m_mainWindowPosition;
}



bool MdiMainWindow::IsMainWindowMaximized ()
{
	return m_mainWindowMaximize;
}


MdiMainFrame::MdiMainFrame(wxDocManager *docManager) 
{
	m_window = new MdiMainWindow (
	    docManager, NULL, -1, _T("title set in MdiMainFrame constructor"),
	    wxDefaultPosition, wxDefaultSize,
	    wxDEFAULT_FRAME_STYLE | wxNO_FULL_REPAINT_ON_RESIZE, _T(""));
	m_window->SetMainFrame (this);
}



MdiMainFrame::~MdiMainFrame() 
{
	if (GetAutoSave ()) {

		SaveState ();
	}
}


wxFrame *MdiMainFrame::GetFrame() const
{
	return m_window;
}



void MdiMainFrame::SaveState ()
{
	if (!m_configPrefix.IsEmpty ()) {

        if (m_window->GetMainWindowPosition ().x < 0 ||
            m_window->GetMainWindowPosition ().y < 0) {

            return;
        }

        wxConfig::Get ()->Write (GetConfigKey(_T("MdiWidth")), 
				 m_window->GetMainWindowSize ().GetWidth ());	
	wxConfig::Get ()->Write (GetConfigKey(_T("MdiHeight")), 
				 m_window->GetMainWindowSize ().GetHeight ());	
	if (!m_window->IsMainWindowMaximized ()) {
			
	    wxConfig::Get ()->Write (GetConfigKey(_T("MdiX")),
				     m_window->GetMainWindowPosition ().x);
	    wxConfig::Get ()->Write (GetConfigKey(_T("MdiY")), 
				     m_window->GetMainWindowPosition ().y);
	}
	wxConfig::Get ()->Write (GetConfigKey(_T("MdiMaximized")), 
				 m_window->IsMainWindowMaximized ());
	}
}


void MdiMainFrame::RestoreState () 
{
	if (!m_configPrefix.IsEmpty ()) {

		int width = GetWindow ()->GetSize ().GetWidth ();
		int height = GetWindow ()->GetSize ().GetWidth ();

		wxConfig::Get ()->Read (GetConfigKey(_T("MdiWidth")), &width);
		wxConfig::Get ()->Read (GetConfigKey(_T("MdiHeight")), &height);

		GetWindow ()->SetSize (width, height);

		wxPoint position = GetWindow ()->GetPosition ();

		wxConfig::Get ()->Read (GetConfigKey(_T("MdiX")), &position.x);
		wxConfig::Get ()->Read (GetConfigKey(_T("MdiY")), &position.y);
	
		GetWindow ()->Move (position);

		bool isMaximized = FALSE;

		if (wxConfig::Get ()->Read (GetConfigKey(_T("MdiMaximized")),
					    &isMaximized) && isMaximized) {

			GetFrame ()->Maximize (TRUE);
		}
	}
}

} // End namespace sw
