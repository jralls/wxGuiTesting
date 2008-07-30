///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/NativeEvents/CRGTKEvent.cpp
// Author:      John Ralls
// Created:     2008
// Copyright:   (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __WXGTK__

#include "CREventImpl.h"

#include <wxGuiTest/CREventCaptureManager.h>
#include <wx/version.h>
#include <wx/gtk/window.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

using namespace wxTst;


static CREventImpl* getButtonEvent(const GdkEventButton*, wxWindow*);
static CREventImpl* getClientEvent(const GdkEventClient*, wxWindow*);
static CREventImpl* getConfigEvent(const GdkEventConfigure*, wxWindow*);
static CREventImpl* getCrossingEvent(const GdkEventCrossing*, wxWindow*);
static CREventImpl* getDNDEvent(const GdkEventDND*, wxWindow*);
static CREventImpl* getExposeEvent(const GdkEventExpose*, wxWindow*);
static CREventImpl* getFocusEvent(const GdkEventFocus*, wxWindow*);
static CREventImpl* getGrabEvent(const GdkEventGrabBroken*, wxWindow*);
static CREventImpl* getKeyEvent(const GdkEventKey*, wxWindow*);
static CREventImpl* getMotionEvent(const GdkEventMotion*, wxWindow*);
static CREventImpl* getNoExposeEvent(const GdkEventNoExpose*, wxWindow*);
static CREventImpl* getOwnerChangeEvent(const GdkEventOwnerChange*, 
										wxWindow*);
static CREventImpl* getPropertyEvent(const GdkEventProperty*, wxWindow*);
static CREventImpl* getVisibilityEvent(const GdkEventVisibility*, wxWindow*);
static CREventImpl* getProximityEvent(const GdkEventProximity*, 
									  wxWindow*);
static CREventImpl* getScrollEvent(const GdkEventScroll*, wxWindow*);
static CREventImpl* getSelectEvent(const GdkEventSelection*, wxWindow*);
static CREventImpl* getSettingEvent(const GdkEventSetting*, wxWindow*);
static CREventImpl* getWinStateEvent(const GdkEventWindowState*, 
									 wxWindow*);
static CREventImpl* getMapEvent(const GdkEvent*, wxWindow*);
static CREventImpl* unknownEvent(const GdkEvent*, wxWindow*);
static GdkEventType getGDKEventType(wxEventType);
static long wxTranslateGDKValToWXKey(guint keysym, bool isChar);
static guint translateWXKeyToGDKVal(long keyCode);

static ModMask
getModMask(guint state) {
	ModMask mods = 0;
	if (state & GDK_SHIFT_MASK)
		mods |= shift;
	if (state & GDK_CONTROL_MASK)
		mods |= ctrl;
	if (state & GDK_MOD1_MASK)
		mods |= alt;
	if (state & GDK_MOD2_MASK)
		mods |= meta;
	if (state & GDK_BUTTON1_MASK)
		mods |= left;
	if (state & GDK_BUTTON2_MASK)
		mods |= middle;
	if (state & GDK_BUTTON3_MASK)
		mods |= right;

	return mods;
}

static guint
setState(ModMask mods) {
	guint state = 0;
	if (mods & shift)
		state |= GDK_SHIFT_MASK;
	if (mods & ctrl)
		state |= GDK_CONTROL_MASK;
	if (mods & alt)
		state |= GDK_MOD1_MASK;
	if (mods & meta)
		state |= GDK_MOD2_MASK;
	if (mods & left)
		state |= GDK_BUTTON1_MASK;
	if (mods & middle)
		state |= GDK_BUTTON2_MASK;
	if (mods & right)
		state |= GDK_BUTTON3_MASK;

	return state;
}

CREvent::CREvent(void* evt, wxObject* obj) :
	m_impl(NULL), m_refcount(new unsigned short(1))  {
	GdkEvent* gdk_evt = reinterpret_cast<GdkEvent*>(evt);
	wxWindow* win = dynamic_cast<wxWindow*>(obj);
	if (obj == NULL || obj == wxTheApp) //Obj can be wxApp with generic controls
		win = wxTheApp->GetTopWindow();
//A bug in wxGTK found by Reinhold causes the event object for wxEVT_MENU to
//be the menu instead of the window. Vadim fixed this bug in trunk 3NOV2007;
//what follows is a workaround.
#if !wxCHECK_VERSION(2,9,0)
	if (obj != NULL && win == NULL) { 
		wxMenu* menu = dynamic_cast<wxMenu*>(obj);
		wxASSERT(menu != NULL);
		win = menu->GetMenuBar();
	}
#else
	wxASSERT(win != NULL);
#endif

	switch (gdk_evt->type) {
	case GDK_KEY_PRESS:
	case GDK_KEY_RELEASE:
		m_impl = getKeyEvent(reinterpret_cast<const GdkEventKey*>(gdk_evt), win);
		break;
	case GDK_BUTTON_PRESS:
	case GDK_2BUTTON_PRESS:
	case GDK_3BUTTON_PRESS:
	case GDK_BUTTON_RELEASE:
		m_impl = getButtonEvent(reinterpret_cast<const GdkEventButton*>(gdk_evt), win);
		break;
    case GDK_SCROLL:
		m_impl = getScrollEvent(reinterpret_cast<const GdkEventScroll*>(gdk_evt), win);
		break;
	case GDK_MOTION_NOTIFY:
		m_impl = getMotionEvent(reinterpret_cast<const GdkEventMotion*>(gdk_evt), win);
		break;
	case GDK_EXPOSE:
		m_impl = getExposeEvent(reinterpret_cast<const GdkEventExpose*>(gdk_evt), win);
		break;
	case GDK_ENTER_NOTIFY:
	case GDK_LEAVE_NOTIFY:
		m_impl = getCrossingEvent(reinterpret_cast<const GdkEventCrossing*>(gdk_evt), win);
		break;
	case GDK_FOCUS_CHANGE:
		m_impl = getFocusEvent(reinterpret_cast<const GdkEventFocus*>(gdk_evt), win);
		break;
	case GDK_MAP:
	case GDK_UNMAP:
		m_impl = getMapEvent(gdk_evt, win);
		break;
	case GDK_CONFIGURE:
		m_impl = getConfigEvent(reinterpret_cast<const GdkEventConfigure*>(gdk_evt), win);
		break;
	case GDK_PROPERTY_NOTIFY:
		m_impl = getPropertyEvent(reinterpret_cast<const GdkEventProperty*>(gdk_evt), win);
		break;
	case GDK_VISIBILITY_NOTIFY:
		m_impl = getVisibilityEvent(reinterpret_cast<const GdkEventVisibility*>(gdk_evt), win);
		break;
	case GDK_SELECTION_CLEAR:
	case GDK_SELECTION_NOTIFY:
	case GDK_SELECTION_REQUEST:
		m_impl = getSelectEvent(reinterpret_cast<const GdkEventSelection*>(gdk_evt), win);
		break;
	case GDK_DRAG_ENTER:
	case GDK_DRAG_LEAVE:
	case GDK_DRAG_MOTION:
	case GDK_DRAG_STATUS:
	case GDK_DROP_START:
	case GDK_DROP_FINISHED:
		m_impl = getDNDEvent(reinterpret_cast<const GdkEventDND*>(gdk_evt), win);
		break;
	case GDK_PROXIMITY_IN:
	case GDK_PROXIMITY_OUT:
		m_impl = getProximityEvent(reinterpret_cast<const GdkEventProximity*>(gdk_evt), win);
		break;
	case GDK_CLIENT_EVENT:
		m_impl = getClientEvent(reinterpret_cast<const GdkEventClient*>(gdk_evt), win);
		break;
	case GDK_NO_EXPOSE:
		m_impl = getNoExposeEvent(reinterpret_cast<const GdkEventNoExpose*>(gdk_evt), win);
		break;
	case GDK_WINDOW_STATE:
		m_impl = getWinStateEvent(reinterpret_cast<const GdkEventWindowState*>(gdk_evt), win);
		break;
	case GDK_SETTING:
		m_impl = getSettingEvent(reinterpret_cast<const GdkEventSetting*>(gdk_evt), win);
		break;
	case GDK_OWNER_CHANGE:
		m_impl = getOwnerChangeEvent(reinterpret_cast<const GdkEventOwnerChange*>(gdk_evt), win);
		break;
	case GDK_GRAB_BROKEN:
		m_impl = getGrabEvent(reinterpret_cast<const GdkEventGrabBroken*>(gdk_evt), win);
		break;
	default:
		m_impl = unknownEvent(gdk_evt, win);
	}

}

template<typename T> wxPoint getMouseCoord(const T* event, wxWindow* win)
{
	wxPoint position = win->GetClientAreaOrigin();
	wxPoint mouse(event->x, event->y);
	return mouse - position;
}

static wxPoint 
setMouseCoord(IntPair mouse, wxWindow* win) {
	wxPoint position = win->GetClientAreaOrigin();
	wxPoint coord(mouse.getX(), mouse.getY());
	return coord + position;
}




bool
CREventImpl::postNativeEvent() {
	if (m_type == wxEVT_NOT_TRANSLATED) {
		wxLogDebug(_T("CREventImpl::postNativeEvent: %s isn't translated and cannot be posted"), m_name.c_str());
		return false;
	}
	GdkEventType type = getGDKEventType(m_type);
	if (type == GDK_NOTHING) {
		wxLogDebug(_T("CREventImpl::postNativeEvent: %s doesn't have a corresponding GDK event type and cannot be posted"), m_name.c_str());
		return false;
	}
	GdkEvent* evt = gdk_event_new(type);
	wxWindowGTK* wingtk = dynamic_cast<wxWindowGTK*>(m_win.getWindow());
	if (wingtk == NULL) {
		wxLogDebug(_T("CRGTKEvent CREventImpl::postNativeEvent(): Window %s didn't convert to a wxWindowGTK"), m_win.getWindow()->GetName().c_str());
		return false;
	}
	GtkWidget* widg = wingtk->GetConnectWidget();
	evt->any.window = widg->window;
	gdk_event_put(evt);
	gdk_event_free(evt);
	return true;
}

template <typename T> void
setMouseEvents(T* event, wxPoint coord, guint state) {
	event->state = state;
	event->x = coord.x;
	event->y = coord.y;
}

bool
CRMouseEventImpl::postNativeEvent() {
	if (m_type == wxEVT_NOT_TRANSLATED) {
		wxLogDebug(_T("CRMouseEventImpl::postNativeEvent: %s isn't translated and cannot be posted"), m_name.c_str());
		return false;
	}
	GdkEventType type;
	GdkEvent* evt = NULL;
	wxPoint coord = setMouseCoord(m_coord, m_win.getWindow());
	if (!m_isNative)
		wxLogDebug(_T("CRMouseEventImpl::postNativeEvent: Event recorded from wxEvent"));

	if (m_type == wxEVT_LEFT_UP || m_type == wxEVT_NC_LEFT_UP ||
		m_type == wxEVT_MIDDLE_UP || m_type == wxEVT_NC_MIDDLE_UP ||
		m_type == wxEVT_RIGHT_UP || m_type == wxEVT_NC_RIGHT_UP) {
		type = GDK_BUTTON_RELEASE;
		evt = gdk_event_new(type);
		GdkEventButton* bevt = reinterpret_cast<GdkEventButton*>(evt);
		setMouseEvents(bevt, coord, setState(m_buttonMask));
		bevt->button = (m_buttonMask & left ? 1 : 
						(m_buttonMask & middle ? 2 : 
						 (m_buttonMask & right ? 3 : 0)));
	}
	if (m_type == wxEVT_LEFT_DOWN || m_type == wxEVT_NC_LEFT_DOWN ||
		m_type == wxEVT_MIDDLE_DOWN || m_type == wxEVT_NC_MIDDLE_DOWN ||
		m_type == wxEVT_RIGHT_DOWN || m_type == wxEVT_NC_RIGHT_DOWN) {
		type = GDK_BUTTON_PRESS;
		evt = gdk_event_new(type);
		GdkEventButton* bevt = reinterpret_cast<GdkEventButton*>(evt);
		setMouseEvents(bevt, coord, setState(m_buttonMask));
		bevt->button = (m_buttonMask & left ? 1 : 
						(m_buttonMask & middle ? 2 : 
						 (m_buttonMask & right ? 3 : 0)));
	}
	if (m_type == wxEVT_LEFT_DCLICK || m_type == wxEVT_NC_LEFT_DCLICK ||
		m_type == wxEVT_MIDDLE_DCLICK || m_type == wxEVT_NC_MIDDLE_DCLICK ||
		m_type == wxEVT_RIGHT_DCLICK || m_type == wxEVT_NC_RIGHT_DCLICK) {
		type = GDK_2BUTTON_PRESS;
		evt = gdk_event_new(type);
		GdkEventButton* bevt = reinterpret_cast<GdkEventButton*>(evt);
		setMouseEvents(bevt, coord, setState(m_buttonMask));
		bevt->button = (m_buttonMask & left ? 1 : 
						(m_buttonMask & middle ? 2 : 
						 (m_buttonMask & right ? 3 : 0)));
	}
	if (m_type == wxEVT_MOUSEWHEEL) {
		type = GDK_SCROLL;
		evt = gdk_event_new(type);
		GdkEventScroll* sevt = reinterpret_cast<GdkEventScroll*>(evt);
		setMouseEvents(sevt, coord, setState(m_buttonMask));
		sevt->direction = (m_clickCount < 0 ? GDK_SCROLL_UP : GDK_SCROLL_DOWN);
	}
	if (m_type == wxEVT_MOTION) {
		type = GDK_MOTION_NOTIFY;
		evt = gdk_event_new(type);
		GdkEventMotion* mevt = reinterpret_cast<GdkEventMotion*>(evt);
		setMouseEvents(mevt, coord, setState(m_buttonMask));
	}
	if (m_type == wxEVT_ENTER_WINDOW) {
		type = GDK_ENTER_NOTIFY;
		evt = gdk_event_new(type);
		GdkEventCrossing* cevt = reinterpret_cast<GdkEventCrossing*>(evt);
		setMouseEvents(cevt, coord, setState(m_buttonMask));
	}
	if (m_type == wxEVT_LEAVE_WINDOW) {
		type = GDK_LEAVE_NOTIFY;
		evt = gdk_event_new(type);
		GdkEventCrossing* cevt = reinterpret_cast<GdkEventCrossing*>(evt);
		setMouseEvents(cevt, coord, setState(m_buttonMask));
	}
	GtkWidget* widg = m_win.getWindow()->GetConnectWidget();
	evt->any.window = widg->window;
	gdk_event_put(evt);
	gdk_event_free(evt);
	return true;
}

bool
CRKeyEventImpl::postNativeEvent() {
	if (m_type == wxEVT_NOT_TRANSLATED) {
		wxLogDebug(_T("CRKeyEventImpl::postNativeEvent: %s isn't translated and cannot be posted"), m_name.c_str());
		return false;
	}
	GdkEventType type = getGDKEventType(m_type);
	if (type == GDK_NOTHING) {
		wxLogDebug(_T("CRKeyEventImpl::postNativeEvent: %s doesn't have a corresponding GDK event type and cannot be posted"), m_name.c_str());
		return false;
	}
	if (!m_isNative)
		wxLogDebug(_T("CRKeyEventImpl::postNativeEvent: Event recorded from wxEvent"));
	GdkEvent* g_evt = gdk_event_new(type);
	GdkEventKey* evt = reinterpret_cast<GdkEventKey*>(g_evt);
	GtkWidget* widg = m_win.getWindow()->GetConnectWidget();
	evt->window = widg->window;
	evt->state = setState(m_modkey);
	evt->keyval = translateWXKeyToGDKVal(m_keycode.getVal());
	gdk_event_put(g_evt);
	gdk_event_free(g_evt);
	return true;
}

bool
CRCommandEventImpl::postNativeEvent() {
	wxLogDebug(_T("CRCommandEventImpl::postNativeEvent: Command Events don't translate to GDK Events"));
	return false;
}




static bool
isClient(wxWindow* win, wxPoint mouse) {
	if (win->GetHandle() == NULL)
		return true;
	wxSize clSize = win->GetClientSize();
	return (mouse.x >= 0 && mouse.y >= 0 
			&& mouse.x < clSize.x && mouse.y < clSize.y);
}

CREventImpl*
getKeyEvent(const GdkEventKey* evt, wxWindow* win) {
	ModMask mask = getModMask(evt->state);
	wxEventType type = wxEVT_KEY_DOWN;
	if (evt->type == GDK_KEY_RELEASE)
		type = wxEVT_KEY_UP;
	else if (evt->type == GDK_KEY_PRESS)
		type = wxEVT_KEY_DOWN;
	else
		wxFAIL_MSG(_T("getKeyEvent: Invalid Event Type"));
	long keycode = wxTranslateGDKValToWXKey(evt->keyval, false);
	return new CRKeyEventImpl(type, win, mask, keycode, true);
}





CREventImpl*
getButtonEvent(const GdkEventButton* evt, wxWindow* win) {

	ModMask mask = getModMask(evt->state);
	int click = 0;
	wxEventType type = wxEVT_NULL;
	WinQual wq(win);
	wxPoint mouse = getMouseCoord(evt, win);
	bool client = isClient(win, mouse);

	switch (evt->type) {
	case GDK_2BUTTON_PRESS:
		click =2;
		break;
	case GDK_3BUTTON_PRESS:
		click = 3;
		break;
	case GDK_BUTTON_PRESS:
		click = 1;
		break;
	case GDK_BUTTON_RELEASE:
		break; //click stays 0
	default:
		wxFAIL_MSG(_T("getButtonEvent: Invalid Event Type"));
	};
	switch (evt->button) {
	case 2:
		if (click == 0)
			type = (client ? wxEVT_MIDDLE_UP : wxEVT_NC_MIDDLE_UP);
		else if (click == 1)
			type = (client ? wxEVT_MIDDLE_DOWN : wxEVT_NC_MIDDLE_DOWN);
		else 
			type = (client ? wxEVT_MIDDLE_DCLICK : wxEVT_NC_MIDDLE_DCLICK); //wx doesn't handle triple-clicks
		mask |= middle;
		break;
	case 3:
		if (click == 0)
			type = (client ? wxEVT_RIGHT_UP : wxEVT_NC_RIGHT_UP);
		else if (click == 1)
			type = (client ? wxEVT_RIGHT_DOWN : wxEVT_NC_RIGHT_DOWN);
		else 
			type = (client ? wxEVT_RIGHT_DCLICK : wxEVT_NC_RIGHT_DCLICK);
		mask |= right;
		break;
#if wxCHECK_VERSION(2, 9, 0)
	case 4:
		if (click == 0)
			type = wxEVT_AUX1_UP;
		else if (click == 1)
			type = wxEVT_AUX1_DOWN;
		else 
			type = wxEVT_AUX1_DCLICK;
		mask |= aux1;
		break;
	case 5:
		if (click == 0)
			type = wxEVT_AUX2_UP;
		else if (click == 1)
			type = wxEVT_AUX2_DOWN;
		else 
			type = wxEVT_AUX2_DCLICK;
		mask |= aux2;
		break;
#endif
	default:
	case 1:
		mask |= left;
		if (click == 0)
			type = (client ? wxEVT_LEFT_UP : wxEVT_NC_LEFT_UP);
		else if (click == 1)
			type = (client ? wxEVT_LEFT_DOWN : wxEVT_NC_LEFT_DOWN);
		else 
			type = (client ? wxEVT_LEFT_DCLICK : wxEVT_NC_LEFT_DCLICK);
		mask |= right;
		break;
		break;
	};
	return new CRMouseEventImpl(type, win, mask, click, mouse, true);
}

CREventImpl*
getScrollEvent(const GdkEventScroll* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_SCROLL);
	ModMask mask = getModMask(evt->state);
	int click = 0;
	switch (evt->direction) {
	case GDK_SCROLL_UP:
		click = -1;
		break;
	case GDK_SCROLL_DOWN:
		click = 1;
		break;
	default:
		click = 0;
	}
	wxEventType type = wxEVT_MOUSEWHEEL;
	wxPoint mouse = getMouseCoord(evt, win);
//Note that the delta and lines values are hardcoded in
//wxWidgets/src/gtk/window.cpp
	return new CRMouseEventImpl(type, win, mask, click, mouse, true, 
								click * 120, 3);
}

CREventImpl*
getMotionEvent(const GdkEventMotion* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_MOTION_NOTIFY);
	ModMask mask = getModMask(evt->state);
	int click = 0;
	wxEventType type = wxEVT_MOTION;
	wxPoint mouse = getMouseCoord(evt, win);
	return new CRMouseEventImpl(type, win, mask, click, mouse, true);
}

CREventImpl*
getExposeEvent(const GdkEventExpose* evt, wxWindow* win) {
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true, _T("GDK_EXPOSE"));
}


CREventImpl* 
getCrossingEvent(const GdkEventCrossing* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_ENTER_NOTIFY || evt->type == GDK_LEAVE_NOTIFY);
	ModMask mask = getModMask(evt->state);
	int click = 0;
	wxEventType type = (evt->type == GDK_ENTER_NOTIFY ? wxEVT_ENTER_WINDOW :
						wxEVT_LEAVE_WINDOW);
	wxPoint mouse = getMouseCoord(evt, win);
	return new CRMouseEventImpl(type, win, mask, click, mouse, true);
}

CREventImpl*
getFocusEvent(const GdkEventFocus* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_FOCUS_CHANGE);
	wxEventType type = (evt->in ? wxEVT_SET_FOCUS : wxEVT_KILL_FOCUS);
	return new CREventImpl(type, win, true);
}

CREventImpl*
getConfigEvent(const GdkEventConfigure* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_CONFIGURE);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true, _T("GDK_CONFIGURE"));
}

CREventImpl* 
getPropertyEvent(const GdkEventProperty* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_PROPERTY_NOTIFY);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true,
							 _T("GDK_PROPERTY_NOTIFY"));
}

CREventImpl* 
getVisibilityEvent(const GdkEventVisibility* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_VISIBILITY_NOTIFY);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true,
							 _T("GDK_VISIBILITY_NOTIFY"));
}

CREventImpl* 
getSelectEvent(const GdkEventSelection* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_SELECTION_CLEAR 
			 || evt->type == GDK_SELECTION_NOTIFY 
			 || evt->type == GDK_SELECTION_REQUEST);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true, _T("GDK_SELECTION"));
}

CREventImpl* 
getDNDEvent(const GdkEventDND* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_DRAG_ENTER
			 || evt->type == GDK_DRAG_LEAVE
			 || evt->type == GDK_DRAG_MOTION
			 || evt->type == GDK_DRAG_STATUS
			 || evt->type == GDK_DROP_START
			 || evt->type == GDK_DROP_FINISHED);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true, _T("GDK_DRAG_DROP"));
}

CREventImpl* 
getProximityEvent(const GdkEventProximity* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_PROXIMITY_IN
			 || evt->type == GDK_PROXIMITY_OUT);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, _T("GDK_PROXIMITY"));
}

CREventImpl* 
getClientEvent(const GdkEventClient* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_CLIENT_EVENT);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true,
						   _T("GDK_CLIENT_EVENT"));
}

CREventImpl* 
getNoExposeEvent(const GdkEventNoExpose* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_NO_EXPOSE);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true, _T("GDK_NO_EXPOSE"));
}

CREventImpl* 
getWinStateEvent(const GdkEventWindowState* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_WINDOW_STATE);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true, 
						   _T("GDK_WINDOW_STATE"));
}

CREventImpl* 
getSettingEvent(const GdkEventSetting* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_SETTING);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true, _T("GDK_SETTING"));
}

CREventImpl* 
getOwnerChangeEvent(const GdkEventOwnerChange* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_OWNER_CHANGE);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true, 
						   _T("GDK_OWNER_CHANGE"));
}

CREventImpl* 
getGrabEvent(const GdkEventGrabBroken* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_GRAB_BROKEN);
	return new CREventImpl(wxEVT_NOT_TRANSLATED, win, true, 
						   _T("GDK_GRAB_BROKEN"));
}

CREventImpl*
getMapEvent(const GdkEvent* evt, wxWindow* win) {
	wxASSERT(evt->type == GDK_MAP || evt->type == GDK_UNMAP);
	wxEventType type;
	wxString name;
	if (evt->type == GDK_MAP) {
		name = _T("Mapped Window");
		type = wxEVT_CREATE;
	}
	else {
		name = _T("Unmapped Window");
		type = wxEVT_DESTROY;
	}
	return new CREventImpl(type, win, true, name);
}


CREventImpl*
unknownEvent(const GdkEvent* evt, wxWindow* win) {
	wxString name = _T("Unknown GDK Event Type: ");
	name << evt->type;
	return new CREventImpl(wxEVT_NULL, win, true, name);
}


//Lifted whole from wxWidgets/src/gtk/window.cpp
long 
wxTranslateGDKValToWXKey(guint keysym, bool isChar)
{
    long key_code;
	enum { maxASCII = 256 };

    switch ( keysym )
    {
        // Shift, Control and Alt don't generate the CHAR events at all
        case GDK_Shift_L:
        case GDK_Shift_R:
            key_code = isChar ? 0 : WXK_SHIFT;
            break;
        case GDK_Control_L:
        case GDK_Control_R:
            key_code = isChar ? 0 : WXK_CONTROL;
            break;
        case GDK_Meta_L:
        case GDK_Meta_R:
        case GDK_Alt_L:
        case GDK_Alt_R:
        case GDK_Super_L:
        case GDK_Super_R:
            key_code = isChar ? 0 : WXK_ALT;
            break;

        // neither do the toggle modifies
        case GDK_Scroll_Lock:
            key_code = isChar ? 0 : WXK_SCROLL;
            break;

        case GDK_Caps_Lock:
            key_code = isChar ? 0 : WXK_CAPITAL;
            break;

        case GDK_Num_Lock:
            key_code = isChar ? 0 : WXK_NUMLOCK;
            break;


        // various other special keys
        case GDK_Menu:
            key_code = WXK_MENU;
            break;

        case GDK_Help:
            key_code = WXK_HELP;
            break;

        case GDK_BackSpace:
            key_code = WXK_BACK;
            break;

        case GDK_ISO_Left_Tab:
        case GDK_Tab:
            key_code = WXK_TAB;
            break;

        case GDK_Linefeed:
        case GDK_Return:
            key_code = WXK_RETURN;
            break;

        case GDK_Clear:
            key_code = WXK_CLEAR;
            break;

        case GDK_Pause:
            key_code = WXK_PAUSE;
            break;

        case GDK_Select:
            key_code = WXK_SELECT;
            break;

        case GDK_Print:
            key_code = WXK_PRINT;
            break;

        case GDK_Execute:
            key_code = WXK_EXECUTE;
            break;

        case GDK_Escape:
            key_code = WXK_ESCAPE;
            break;

        // cursor and other extended keyboard keys
        case GDK_Delete:
            key_code = WXK_DELETE;
            break;

        case GDK_Home:
            key_code = WXK_HOME;
            break;

        case GDK_Left:
            key_code = WXK_LEFT;
            break;

        case GDK_Up:
            key_code = WXK_UP;
            break;

        case GDK_Right:
            key_code = WXK_RIGHT;
            break;

        case GDK_Down:
            key_code = WXK_DOWN;
            break;

        case GDK_Prior:     // == GDK_Page_Up
            key_code = WXK_PAGEUP;
            break;

        case GDK_Next:      // == GDK_Page_Down
            key_code = WXK_PAGEDOWN;
            break;

        case GDK_End:
            key_code = WXK_END;
            break;

        case GDK_Begin:
            key_code = WXK_HOME;
            break;

        case GDK_Insert:
            key_code = WXK_INSERT;
            break;


        // numpad keys
        case GDK_KP_0:
        case GDK_KP_1:
        case GDK_KP_2:
        case GDK_KP_3:
        case GDK_KP_4:
        case GDK_KP_5:
        case GDK_KP_6:
        case GDK_KP_7:
        case GDK_KP_8:
        case GDK_KP_9:
            key_code = (isChar ? static_cast<long>('0') : WXK_NUMPAD0 + keysym - GDK_KP_0);
            break;

        case GDK_KP_Space:
            key_code = isChar ? static_cast<long>(' ') : WXK_NUMPAD_SPACE;
            break;

        case GDK_KP_Tab:
            key_code = isChar ? WXK_TAB : WXK_NUMPAD_TAB;
            break;

        case GDK_KP_Enter:
            key_code = isChar ? WXK_RETURN : WXK_NUMPAD_ENTER;
            break;

        case GDK_KP_F1:
            key_code = isChar ? WXK_F1 : WXK_NUMPAD_F1;
            break;

        case GDK_KP_F2:
            key_code = isChar ? WXK_F2 : WXK_NUMPAD_F2;
            break;

        case GDK_KP_F3:
            key_code = isChar ? WXK_F3 : WXK_NUMPAD_F3;
            break;

        case GDK_KP_F4:
            key_code = isChar ? WXK_F4 : WXK_NUMPAD_F4;
            break;

        case GDK_KP_Home:
            key_code = isChar ? WXK_HOME : WXK_NUMPAD_HOME;
            break;

        case GDK_KP_Left:
            key_code = isChar ? WXK_LEFT : WXK_NUMPAD_LEFT;
            break;

        case GDK_KP_Up:
            key_code = isChar ? WXK_UP : WXK_NUMPAD_UP;
            break;

        case GDK_KP_Right:
            key_code = isChar ? WXK_RIGHT : WXK_NUMPAD_RIGHT;
            break;

        case GDK_KP_Down:
            key_code = isChar ? WXK_DOWN : WXK_NUMPAD_DOWN;
            break;

        case GDK_KP_Prior: // == GDK_KP_Page_Up
            key_code = isChar ? WXK_PAGEUP : WXK_NUMPAD_PAGEUP;
            break;

        case GDK_KP_Next: // == GDK_KP_Page_Down
            key_code = isChar ? WXK_PAGEDOWN : WXK_NUMPAD_PAGEDOWN;
            break;

        case GDK_KP_End:
            key_code = isChar ? WXK_END : WXK_NUMPAD_END;
            break;

        case GDK_KP_Begin:
            key_code = isChar ? WXK_HOME : WXK_NUMPAD_BEGIN;
            break;

        case GDK_KP_Insert:
            key_code = isChar ? WXK_INSERT : WXK_NUMPAD_INSERT;
            break;

        case GDK_KP_Delete:
            key_code = isChar ? WXK_DELETE : WXK_NUMPAD_DELETE;
            break;

        case GDK_KP_Equal:
            key_code = isChar ? static_cast<long>('=') : WXK_NUMPAD_EQUAL;
            break;

        case GDK_KP_Multiply:
            key_code = isChar ? static_cast<long>('*') : WXK_NUMPAD_MULTIPLY;
            break;

        case GDK_KP_Add:
            key_code = isChar ? static_cast<long>('+') : WXK_NUMPAD_ADD;
            break;

        case GDK_KP_Separator:
            // FIXME: what is this?
            key_code = isChar ? static_cast<long>('.') : WXK_NUMPAD_SEPARATOR;
            break;

        case GDK_KP_Subtract:
            key_code = isChar ? static_cast<long>('-') : WXK_NUMPAD_SUBTRACT;
            break;

        case GDK_KP_Decimal:
            key_code = isChar ? static_cast<long>('.') : WXK_NUMPAD_DECIMAL;
            break;

        case GDK_KP_Divide:
            key_code = isChar ? static_cast<long>('/') : WXK_NUMPAD_DIVIDE;
            break;


        // function keys
        case GDK_F1:
        case GDK_F2:
        case GDK_F3:
        case GDK_F4:
        case GDK_F5:
        case GDK_F6:
        case GDK_F7:
        case GDK_F8:
        case GDK_F9:
        case GDK_F10:
        case GDK_F11:
        case GDK_F12:
            key_code = WXK_F1 + keysym - GDK_F1;
            break;

        default:
            key_code = 0;
    }
	if (!key_code && keysym < maxASCII ) {
		guint upper = gdk_keyval_to_upper(keysym);
		key_code = (upper ? upper : key_code);
	}

   return key_code;
}

guint 
translateWXKeyToGDKVal(long keyCode) {
	guint sym;
	switch (keyCode) {
	case WXK_SHIFT:
		sym = GDK_Shift_L;
		break;
	case WXK_CONTROL:
		sym = GDK_Control_L;
		break;
	case WXK_ALT:
		sym = GDK_Alt_L;
		break;
	case WXK_SCROLL:
		sym = GDK_Scroll_Lock;
		break;
	case WXK_CAPITAL:
		sym = GDK_Caps_Lock;
		break;
	case WXK_NUMLOCK:
		sym = GDK_Num_Lock;
		break;
	case WXK_MENU:
		sym = GDK_Menu;
		break;
	case WXK_HELP:
		sym = GDK_Help;
		break;
	case WXK_TAB:
		sym = GDK_Tab;
		break;
	case WXK_RETURN:
		sym = GDK_Return;
		break;
	case WXK_CLEAR:
		sym = GDK_Clear;
		break;
	case WXK_PAUSE:
		sym = GDK_Pause;
		break;
	case WXK_SELECT:
		sym = GDK_Select;
		break;
	case WXK_PRINT:
		sym = GDK_Print;
		break;
	case WXK_EXECUTE:
		sym = GDK_Execute;
		break;
	case WXK_ESCAPE:
		sym = GDK_Escape;
		break;
	case WXK_DELETE:
		sym = GDK_Delete;
		break;
	case WXK_HOME:
		sym = GDK_Home;
		break;
	case WXK_LEFT:
		sym = GDK_Left;
		break;
	case WXK_UP:
		sym = GDK_Up;
		break;
	case WXK_RIGHT:
		sym = GDK_Right;
		break;
	case WXK_DOWN:
		sym = GDK_Down;
		break;
	case WXK_PAGEUP:
		sym = GDK_Prior;
		break;
	case WXK_PAGEDOWN:
		sym = GDK_Next;
		break;
	case WXK_END:
		sym = GDK_End;
		break;
	case WXK_INSERT:
		sym = GDK_Insert;
		break;
	case WXK_NUMPAD0:
	case WXK_NUMPAD1:
	case WXK_NUMPAD2:
	case WXK_NUMPAD3:
	case WXK_NUMPAD4:
	case WXK_NUMPAD5:
	case WXK_NUMPAD6:
	case WXK_NUMPAD7:
	case WXK_NUMPAD8:
	case WXK_NUMPAD9:
		sym = GDK_KP_0 + keyCode - WXK_NUMPAD0;
		break;
	case WXK_NUMPAD_SPACE:
		sym = GDK_KP_Space;
		break;
	case WXK_NUMPAD_TAB:
		sym = GDK_KP_Tab;
		break;
	case WXK_NUMPAD_F1:
		sym = GDK_KP_F1;
		break;
	case WXK_NUMPAD_F2:
		sym = GDK_KP_F2;
		break;
	case WXK_NUMPAD_F3:
		sym = GDK_KP_F3;
		break;
	case WXK_NUMPAD_F4:
		sym = GDK_KP_F4;
		break;
	case WXK_NUMPAD_HOME:
		sym=GDK_KP_Home;
		break;
	case WXK_NUMPAD_LEFT:
		sym = GDK_KP_Left;
		break;
	case WXK_NUMPAD_RIGHT:
		sym = GDK_KP_Right;
		break;
	case WXK_NUMPAD_UP:
		sym = GDK_KP_Up;
		break;
	case WXK_NUMPAD_DOWN:
		sym = GDK_KP_Down;
		break;
	case WXK_NUMPAD_PAGEUP:
		sym = GDK_KP_Prior;
		break;
	case WXK_NUMPAD_PAGEDOWN:
		sym = GDK_KP_Next;
		break;
	case WXK_NUMPAD_END:
		sym = GDK_KP_End;
		break;
	case WXK_NUMPAD_BEGIN:
		sym = GDK_KP_Begin;
		break;
	case WXK_NUMPAD_INSERT:
		sym = GDK_KP_Insert;
		break;
	case WXK_NUMPAD_DELETE:
		sym = GDK_KP_Delete;
		break;
	case WXK_NUMPAD_EQUAL:
		sym = GDK_KP_Equal;
		break;
	case WXK_NUMPAD_MULTIPLY:
		sym = GDK_KP_Multiply;
		break;
	case WXK_NUMPAD_ADD:
		sym = GDK_KP_Add;
		break;
	case WXK_NUMPAD_SEPARATOR:
		sym = GDK_KP_Separator;
		break;
	case WXK_NUMPAD_SUBTRACT:
		sym = GDK_KP_Subtract;
		break;
	case WXK_NUMPAD_DECIMAL:
		sym = GDK_KP_Decimal;
		break;
	case WXK_NUMPAD_DIVIDE:
		sym = GDK_KP_Divide;
		break;
	case WXK_F1:
	case WXK_F2:
	case WXK_F3:
	case WXK_F4:
	case WXK_F5:
	case WXK_F6:
	case WXK_F7:
	case WXK_F8:
	case WXK_F9:
	case WXK_F10:
	case WXK_F11:
	case WXK_F12:
		sym = GDK_F1 + keyCode - WXK_F1;
		break;
	default:
		sym = keyCode;
	}
	return sym;
}

GdkEventType 
getGDKEventType(wxEventType type) {
	if (type == wxEVT_KEY_DOWN)
		return GDK_KEY_PRESS;
	if (type == wxEVT_KEY_UP)
		return GDK_KEY_RELEASE;
	if (type == wxEVT_LEFT_UP || type == wxEVT_NC_LEFT_UP ||
		type == wxEVT_MIDDLE_UP || type == wxEVT_NC_MIDDLE_UP ||
#if wxCHECK_VERSION(2, 9, 0)
		type == wxEVT_AUX1_UP || type == wxEVT_NC_AUX1_UP ||
		type == wxEVT_AUX2_UP || type == wxEVT_NC_AUX2_UP ||
#endif
		type == wxEVT_RIGHT_UP || type == wxEVT_NC_RIGHT_UP )
		return GDK_BUTTON_RELEASE;
	if (type == wxEVT_LEFT_DOWN || type == wxEVT_NC_LEFT_DOWN ||
		type == wxEVT_MIDDLE_DOWN || type == wxEVT_NC_MIDDLE_DOWN ||
#if wxCHECK_VERSION(2, 9, 0)
		type == wxEVT_AUX1_DOWN || type == wxEVT_NC_AUX1_DOWN ||
		type == wxEVT_AUX2_DOWN || type == wxEVT_NC_AUX2_DOWN ||
#endif
		type == wxEVT_RIGHT_DOWN || type == wxEVT_NC_RIGHT_DOWN )
		return GDK_BUTTON_PRESS;
	if (type == wxEVT_LEFT_DCLICK || type == wxEVT_NC_LEFT_DCLICK ||
		type == wxEVT_MIDDLE_DCLICK || type == wxEVT_NC_MIDDLE_DCLICK ||
#if wxCHECK_VERSION(2, 9, 0)
		type == wxEVT_AUX1_DCLICK || type == wxEVT_NC_AUX1_DCLICK ||
		type == wxEVT_AUX2_DCLICK || type == wxEVT_NC_AUX2_DCLICK ||
#endif
		type == wxEVT_RIGHT_DCLICK || type == wxEVT_NC_RIGHT_DCLICK )
		return GDK_2BUTTON_PRESS;
	if (type == wxEVT_MOUSEWHEEL)
		return GDK_SCROLL;
	if (type == wxEVT_MOTION)
		return GDK_MOTION_NOTIFY;
	if (type == wxEVT_ENTER_WINDOW)
		return GDK_ENTER_NOTIFY;
	if (type == wxEVT_LEAVE_WINDOW)
		return GDK_LEAVE_NOTIFY;
	if (type == wxEVT_SET_FOCUS || type == wxEVT_KILL_FOCUS)
		return GDK_FOCUS_CHANGE;
	return GDK_NOTHING;
}
#endif //__WXGTK__
