///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swWindow.h
// Author:      Yann Rouillard, Viet Bui Xuan
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWWINDOW_H
#define SWWINDOW_H

#ifdef __GNUG__
    #pragma interface "swWindow.h"
#endif

#include <wxGuiTest/Common.h>

#include <wx/docview.h>
#include <wx/event.h>

namespace sw {


class Window 
{
public:
	Window ();
	virtual ~Window ();

	virtual wxWindow *GetWindow() const = 0;

	virtual void SetConfigPrefix (const wxString &configPrefix);

	virtual wxString GetConfigPrefix ();

	virtual void SaveState ();

	virtual void RestoreState ();

	void SetAutoSave (bool autoSave);

	bool GetAutoSave ();

	virtual bool Show(bool show);
	
	virtual void SetSizer(wxSizer* sizer);

	virtual void SetAutoLayout(bool autoLayout);

	virtual void Layout();

	virtual void Move(int x, int y);

	virtual void Move(const wxPoint& pt);

	virtual void SetSizeHints(int minW=-1, int minH=-1, int maxW=-1, int maxH=-1, int incW=-1, int incH=-1);

	virtual void SetTitle(const wxString& title);

	virtual void PushEventHandler(wxEvtHandler* handler);

	virtual wxEvtHandler* PopEventHandler(bool deleteHandler = FALSE) const;

	virtual bool RemoveEventHandler(wxEvtHandler *handler);

	virtual void GetSize(int* width, int* height) const;

	virtual wxSize GetSize() const;

	virtual void SetSize(int x, int y, int width, int height, int sizeFlags = wxSIZE_AUTO);

	virtual void SetSize(const wxRect& rect);

	virtual void SetSize(int width, int height);

	virtual void SetSize(const wxSize& size);

	virtual void GetPosition(int* x, int* y) const;

	virtual wxPoint GetPosition() const;

protected:
	wxString GetConfigKey (const wxString &keySuffix);

	wxString m_configPrefix;
	bool m_autoSave;

};

} // End namespace sw

#endif // Window_H
