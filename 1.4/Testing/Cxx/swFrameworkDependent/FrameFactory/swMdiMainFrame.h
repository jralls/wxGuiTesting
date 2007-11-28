///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swMdiMainFrame.h
// Author:      Yann Rouillard, Viet Bui Xuan
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWMDIMAINFRAME_H
#define SWMDIMAINFRAME_H

#ifdef __GNUG__
    #pragma interface "swMdiMainFrame.h"
#endif

#include "Common.h"

#include <wx/docview.h>
#include <wx/docmdi.h>

#include "swMainFrame.h"

namespace sw {


class MdiMainWindow: public wxDocMDIParentFrame
{
DECLARE_CLASS (MdiMainWindow)
DECLARE_EVENT_TABLE()

public:
	MdiMainWindow (	wxDocManager* manager, 
						wxFrame *parent, 
						wxWindowID id, 
						const wxString& title, 
						const wxPoint& pos, 
						const wxSize& size,
						long style,
						const wxString& name);
	~MdiMainWindow ();

	void SetMainFrame (MainFrame *mainFrame);

	void OnSize(wxSizeEvent& event);
	void OnMove(wxMoveEvent& event);

	wxSize &GetMainWindowSize ();
	wxPoint &GetMainWindowPosition ();
	bool IsMainWindowMaximized ();

private:
	MainFrame *m_mainFrame;
	wxPoint m_mainWindowPosition;
	wxSize m_mainWindowSize;
	bool m_mainWindowMaximize;

};




class MdiMainFrame : public MainFrame
{
public:
	MdiMainFrame(wxDocManager *docManager);
	~MdiMainFrame();

	virtual wxFrame *GetFrame() const;

	void SaveState ();
	void RestoreState ();

private:
	MdiMainWindow *m_window;

};

} // End namespace sw

#endif // SWMDIMAINFRAME_H
