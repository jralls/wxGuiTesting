///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swWindow.cpp
// Author:      Yann Rouillard, Viet Bui Xuan
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swWindow.h"
#endif

#include "swWindow.h"

namespace sw {


Window::Window ()
{
	m_autoSave = FALSE;
}


Window::~Window ()
{
    // Nothing to do
}


void Window::SetConfigPrefix (const wxString &configPrefix)
{
	m_configPrefix = configPrefix;
}


wxString Window::GetConfigPrefix ()
{
	return m_configPrefix;
}


wxString Window::GetConfigKey (const wxString &keySuffix)
{
	wxString key = m_configPrefix;
	key << keySuffix;

	return key;
}


void Window::SetAutoSave (bool autoSave)
{
	m_autoSave = autoSave;
}


bool Window::GetAutoSave ()
{
	return m_autoSave;
}


void Window::SaveState ()
{
	// does nothing by default;
}


void Window::RestoreState ()
{
	// does nothing by default;
}


bool Window::Show(bool show)
{
	return GetWindow ()->Show (show);
}
	

void Window::SetSizer(wxSizer* sizer)
{
	GetWindow ()->SetSizer (sizer);
}


void Window::SetAutoLayout(bool autoLayout)
{
	GetWindow ()->SetAutoLayout(autoLayout);
}


void Window::Layout()
{
	GetWindow ()->Layout ();
}



void Window::Move(int x, int y)
{
	GetWindow ()->Move (x, y);
}


void Window::Move(const wxPoint& pt)
{
	GetWindow ()->Move (pt);
}



void Window::SetSizeHints(int minW, int minH, int maxW, int maxH, int incW, int incH)
{
	GetWindow ()->SetSizeHints(minW, minH, maxW, maxH, incW, incH);
}


void Window::SetTitle(const wxString& title)
{
    // Starting from wxWidgets 2.7 (if using default compatibility levels)
    // title seems to be replaced by label except for top level windows
	// (frame, dialog).
	//TODO: in order to use this method instance checks for type specific
	// actions are required. For now ignore it:
#if wxCHECK_VERSION(2, 7, 0)
	GetWindow ()->SetLabel (title);
#else
	GetWindow ()->SetTitle (title);
#endif
}



void Window::PushEventHandler(wxEvtHandler* handler)
{
	GetWindow ()->PushEventHandler (handler);
}


wxEvtHandler* Window::PopEventHandler(bool deleteHandler) const
{
	return GetWindow ()->PopEventHandler (deleteHandler);
}


bool Window::RemoveEventHandler(wxEvtHandler *handler)
{
	return GetWindow ()->RemoveEventHandler (handler);
}


void Window::GetSize(int* width, int* height) const
{
	GetWindow ()->GetSize(width, height);
}


wxSize Window::GetSize() const
{
	return GetWindow ()->GetSize ();
}


void Window::SetSize(int x, int y, int width, int height, int sizeFlags)
{
	GetWindow ()->SetSize (x, y, width, height, sizeFlags);
}


void Window::SetSize(const wxRect& rect)
{
	GetWindow ()->SetSize (rect);
}


void Window::SetSize(int width, int height)
{
	GetWindow ()->SetSize (width, height);
}


void Window::SetSize(const wxSize& size)
{
	GetWindow ()->SetSize (size);
}


void Window::GetPosition(int* x, int* y) const
{
	GetWindow ()->GetPosition (x, y);
}


wxPoint Window::GetPosition() const
{
	return GetWindow ()->GetPosition ();
}

} // End namespace sw
