///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/NativeEvents/CRMSWEvent.cpp
// Author:      John Ralls
// Created:     2008
// Copyright:   (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////
#ifdef __WXMSW__
#ifdef __GNUG__
    #pragma implementation "CRMSWEvent.h"
#endif

#include "CRMSWEvent.h"
#include <wxGuiTest/CREventCaptureManager.h>
#include <wx/version.h>

using namespace wxTst;

Events CRMSWEvent::s_events;

inline void 
CRMSWEvent::pushEvent(UINT msg, wxEventType wxEvent) {
	std::map<wxEventType, CREvent>::const_iterator pos = CRNativeEvent::s_eventMap.find(wxEvent);
	if (pos == CRNativeEvent::s_eventMap.end()) return;
    s_events.insert(std::make_pair(msg, pos->second));
}

void
CRMSWEvent::initEvents() {
    pushEvent(WM_NULL, wxEVT_NULL);
    pushEvent(WM_SETFOCUS, wxEVT_COMMAND_SET_FOCUS);
    pushEvent(WM_KILLFOCUS, wxEVT_COMMAND_KILL_FOCUS);
    pushEvent(WM_PAINT, wxEVT_PAINT);
    pushEvent(WM_CLOSE, wxEVT_CLOSE_WINDOW);
    pushEvent(WM_SHOWWINDOW, wxEVT_SHOW);
    pushEvent(WM_KEYDOWN, wxEVT_KEY_DOWN);
    pushEvent(WM_KEYUP, wxEVT_KEY_UP);
    pushEvent(WM_CHAR, wxEVT_CHAR);
    pushEvent(WM_MENUSELECT, wxEVT_COMMAND_MENU_SELECTED);
    pushEvent(WM_MOUSEMOVE, wxEVT_MOTION);
    pushEvent(WM_LBUTTONDOWN, wxEVT_LEFT_DOWN);
    pushEvent(WM_LBUTTONUP, wxEVT_LEFT_UP);
    pushEvent(WM_LBUTTONDBLCLK, wxEVT_LEFT_DCLICK);
    pushEvent(WM_MBUTTONDOWN, wxEVT_MIDDLE_DOWN);
    pushEvent(WM_MBUTTONUP, wxEVT_MIDDLE_UP);
    pushEvent(WM_MBUTTONDBLCLK, wxEVT_MIDDLE_DCLICK);
    pushEvent(WM_RBUTTONDOWN, wxEVT_RIGHT_DOWN);
    pushEvent(WM_RBUTTONUP, wxEVT_RIGHT_UP);
    pushEvent(WM_RBUTTONDBLCLK, wxEVT_RIGHT_DCLICK);
#if ((_WIN32_WINNT >= 0x0500) && (wxCHECK_VERSION(2,9,0)))
    pushEvent(WM_XBUTTONDOWN, wxEVT_AUX1_DOWN);
    pushEvent(WM_XBUTTONUP, wxEVT_AUX1_UP);
    pushEvent(WM_XBUTTONDBLCLK, wxEVT_AUX1_DCLICK);
#endif
    pushEvent(WM_MOUSEWHEEL, wxEVT_MOUSEWHEEL);
    pushEvent(WM_MOUSELEAVE, wxEVT_LEAVE_WINDOW);
    pushEvent(WM_HOTKEY, wxEVT_HOTKEY);
    pushEvent(WM_NCMOUSEMOVE, wxEVT_NC_MOTION);
    pushEvent(WM_NCLBUTTONDOWN, wxEVT_NC_LEFT_DOWN);
    pushEvent(WM_NCLBUTTONUP, wxEVT_NC_LEFT_UP);
    pushEvent(WM_NCLBUTTONDBLCLK, wxEVT_NC_LEFT_DCLICK);
    pushEvent(WM_NCMBUTTONDOWN, wxEVT_NC_MIDDLE_DOWN);
    pushEvent(WM_NCMBUTTONUP, wxEVT_NC_MIDDLE_UP);
    pushEvent(WM_NCMBUTTONDBLCLK, wxEVT_NC_MIDDLE_DCLICK);
    pushEvent(WM_NCRBUTTONDOWN, wxEVT_NC_RIGHT_DOWN);
    pushEvent(WM_NCRBUTTONUP, wxEVT_NC_RIGHT_UP);
    pushEvent(WM_NCRBUTTONDBLCLK, wxEVT_NC_RIGHT_DCLICK);
}

CREvent
CRMSWEvent::getCREvent(MSG msg) {
    if (CRNativeEvent::s_eventMap.empty())
	CRNativeEvent::initEventMap();
    if (s_events.empty())
	initEvents();

    Events::const_iterator pos = s_events.find(msg.message);
    if (pos == s_events.end()) {
		CREventMap::const_iterator ut = s_eventMap.find(wxEVT_NOT_TRANSLATED);
		return ut->second;
    }
    return pos->second;
}

CRMSWEvent::CRMSWEvent(MSG msg) : 
    CRNativeEvent(getCREvent(msg)), 
    m_event(msg) 
{
//Get the details about the MSG and convert them to the appropriate
//additional parameters
}

CRMSWEvent::CRMSWEvent(const wxEvent& evt) :
    CRNativeEvent(evt.GetEventType()) {
//Convert the evt parameters and fill in the MSG
}

CRMSWEvent::CRMSWEvent(const wxString& evt) : CRNativeEvent(evt)
{
//CRNativeEvent will convert the string into a wxEvent, just convert
//that into a MSG
}

void*
CRMSWEvent::getNativeEvent() {
    return static_cast<void*>(&m_event);
}

//Obviously this needs some elaboration...
wxString
CRMSWEvent::serialize() {
    if (getEventType() != wxEVT_NOT_TRANSLATED)
	return m_wxevent.m_name;
    switch (m_event.message) {
	case WM_COMMAND:
	return _T("Not Translated: Command");
    case WM_TIMER:
	return _T("Not Translated: Timer");
    case WM_TIMECHANGE:
	return _T("Not Translated: Time Change");
    case WM_ENTERMENULOOP:
	return _T("Not Translated: Enter Menu Loop");
    case WM_EXITMENULOOP:
	return _T("Not Translated: Exit Menu Loop");
    case WM_PARENTNOTIFY:
	return _T("Not Translated: Parent Notification");
    case WM_CREATE:
	return _T("Not Translated: Create");
    case WM_DESTROY:
	return _T("Not Translated: Destroy");
    case WM_ACTIVATE:
	return _T("Not Translated: Activate");
    case WM_INITDIALOG:
	return _T("Not Translated: Init Dialog");
    case WM_INITMENU:
	return _T("Not Translated: Init Menu");
    case WM_INITMENUPOPUP:
	return _T("Not Translated: Init Popup Menu");
    case 0x0118:
	return _T("Microsoft Private System Timer");

    default:
		return wxString::Format(_T("%#.4X"), m_event.message);
    }
}






#endif //__WXMSW__
