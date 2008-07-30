///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/NativeEvents/CREventImpl.cpp
// Author:      John Ralls
// Created:     2008
// Copyright:   (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CREventImpl.h"
#endif

#include "CREventImpl.h"
#include <wxGuiTest/CRWindowHierarchyHandler.h>
#include <wx/wx.h>
//Additional includes for their DECLARE_EVENT_TYPE statements
#include <algorithm>
#if wxUSE_TREECTRL
#include <wx/treectrl.h>
#endif
#if wxUSE_SPLITTER
#include <wx/splitter.h>
#endif
#if wxUSE_CALENDARCTRL
#include <wx/calctrl.h>
#endif
#if wxUSE_AUI
#include <wx/aui/aui.h>
#endif
#if wxUSE_COLOURPICKERCTRL
#include <wx/clrpicker.h>
#endif
#if wxUSE_COLLPANE && wxuSE_BUTTON && wxUSE_STATLINE
#include <wx/collpane.h>
#endif
#if wxUSE_FONTPICKERCTRL
#include <wx/fontpicker.h>
#endif
#if wxUSE_FILEPICKERCTRL || wxUSE_DIRPICKERCTRL
#include <wx/filepicker.h>
#endif
#if wxUSE_DATAVIEWCTRL
#include <wx/dataview.h>
#endif
#if wxUSE_FINDREPLDLG
#include <wx/fdrepdlg.h>
#endif
#if wxUSE_HYPERLINKCTRL
#include <wx/hyperlink.h>
#endif
#if wxUSE_HTML
#include <wx/html/htmlwin.h>
#endif
#if wxUSE_LISTCTRL
#include <wx/listctrl.h>
#endif
#if wxUSE_NOTEBOOK
#include <wx/notebook.h>
#endif
#if wxUSE_RICHTEXT
#include <wx/richtext/richtextctrl.h>
#endif
#if wxUSE_SEARCHCTRL
#include <wx/srchctrl.h>
#endif
#if wxUSE_TOGGLEBTN
#include <wx/tglbtn.h>
#endif
#if wxUSE_TAB_DIALOG
#include <wx/tabctrl.h>
#endif
#if wxUSE_DIALUP_MANAGER
#include <wx/dialup.h>
#endif
#if wxUSE_GRID
#include <wx/grid.h>
#endif
#if wxUSE_MEDIACTRL
#include <wx/mediactrl.h>
#endif
#ifdef wxHAS_POWER_EVENTS
#include <wx/power.h>
#endif
#if wxUSE_SASH
#include <wx/sashwin.h>
#endif
#ifdef wxHAS_TASK_BAR_ICON
#include <wx/taskbar.h>
#endif
#if wxUSE_WIZARDDLG
#include <wx/wizard.h>
#endif

using namespace wxTst;
//struct for mapping wxEventTypes to their EventNames, wxEvent Classes,
//CREventImpl Classes, and CREventCat categories 
struct wxTst::CREventMap {
	wxEventType m_type;
	wxString m_name;
	wxString m_wxClass;
	wxString m_crClass;
	CREventCat m_cat;
	CREventMap() {}
	CREventMap(wxEventType type, const wxString& name, const wxString& wxclass,
			   const wxString& crclass, CREventCat cat) :
		m_type(type), m_name(name), m_wxClass(wxclass), m_crClass(crclass),
		m_cat(cat) {}
};

//Flags and separators for serialized events.
const wxString WinQual::objflag(_T("object="));
const wxString WinQual::objsep(_T("->"));
const wxString CREventImpl::typeflag(_T("type="));
const wxString CREventImpl::nameflag(_T("name="));
const wxString CRCommandEventImpl::cmdStrFlag(_T("cmdStr="));
const wxString CRCommandEventImpl::cmdIntFlag(_T("cmdInt="));
const wxString CRCommandEventImpl::cmdXLFlag(_T("cmdXLong="));
const wxString CREventImpl::modFlag(_T("modMask="));
const wxString CRMouseEventImpl::clickFlag(_T("numClicks="));
const wxString CRMouseEventImpl::coordFlag(_T("coords="));
const wxString CREventImpl::nativeFlag(_T("native="));
const wxString CRMouseEventImpl::deltaFlag(_T("delta="));
const wxString CRMouseEventImpl::linesFlag(_("lines="));
const wxString CRKeyEventImpl::keyFlag(_T("key="));

static const wxString sep(_T(":"));


const wxString IntPair::xflag(_T("x="));
const wxString IntPair::yflag(_T("y="));
const wxString IntPair::comma(_T(","));

static wxString
extractString(const wxString& ref, const wxString& flag, 
			  const wxString& term = sep) {
	wxString result;
	size_t begin = ref.find(flag);
	if (begin == wxString::npos) return result;
	size_t end;
	if (term.length() == 0 || (end = ref.find(term, begin)) == wxString::npos)
		end = ref.length();
	begin += flag.length();
	result = ref.substr(begin, end);
	return result;
}


IntVal::IntVal(const wxString& evtStr, const wxString& flag) :
	m_val(0), m_flag(flag) {
	wxString str = extractString(evtStr, flag, sep);
	if (str.length() == 0) {
		wxLogDebug (_T("IntVal::IntVal(string): No value for %s in %s"), 
					flag.c_str(), evtStr.c_str());
		m_val = 0;
	}
	if (!str.ToLong(&m_val))
		wxLogDebug(_T("IntVal::IntVal(string): Failed to extract value for %s from %s"), flag.c_str(), str.c_str());
}

wxString
IntVal::serialize() {
	wxString str;
	str << sep << m_flag << m_val;
	return str;
}

IntPair::IntPair(const wxString& evtStr, const wxString& flag) : 
	m_x(0), m_y(0), m_flag(flag) {
	wxString pair = extractString(evtStr, flag);
	wxString xstr = extractString(pair, xflag, comma);
	wxString ystr = extractString(pair, yflag, comma);
	if ( !(xstr.ToLong(&m_x) && ystr.ToLong(&m_y)))
		wxLogDebug(_T("IntPair::IntPair(string): Failed to extract number for %s from %s"), flag.c_str(), evtStr.c_str());

}

wxString
IntPair::serialize() {
	wxString evtString;
	evtString << sep << m_flag << xflag << m_x << comma << yflag << m_y;
	return evtString;
}

namespace wxTst {
//Functor class for searching s_eventMap for name values.
class CREventImplName_Equals {
public:
    CREventImplName_Equals(const wxString& name) : m_name(name) {}
	bool operator() (std::pair<wxEventType, CREventMap> elem) {
		return elem.second.m_name == m_name;
    }
private:
    wxString m_name;
};

}; //namespace wxTst


WinQual::WinQual(wxWindow* object) :
	m_window(object), m_parent(NULL), m_toplvl(NULL) {
	CRWindowHierarchyHandler* wh = CRWindowHierarchyHandler::GetInstance();
	wxString parent = wh->FindContainerName(m_window);
	m_toplvl = wxGetTopLevelParent(m_window);
	m_parent = wxWindow::FindWindowByName(parent, m_toplvl);
}

WinQual::WinQual(const wxString& evtString) :
	m_window(NULL), m_parent(NULL), m_toplvl(NULL) {
	wxString winStr = extractString(evtString, objflag, sep);
	if (winStr.length() == 0) {
		wxLogDebug(_T("WinQual::WinQual(string): No object found in %s"), 
				   evtString.c_str());
		return;
	}
	wxString object(_T("")) ;
	wxString toplvl(_T(""));
	wxString parent(_T(""));
	size_t end = evtString.find(objsep, 0);
	bool noparent = false;
	toplvl = winStr.substr(0, end);
	if (end == wxString::npos) {
		wxLogDebug(_T("WinQual::WinQual(string): No %s found in %s"), 
				   objsep.c_str(), winStr.c_str());
		return;
	}
	size_t pos = end + objsep.length();
	end = winStr.find(objsep, pos);
	parent = winStr.substr(pos, end);
	if (end == wxString::npos) {
		object = parent;
		noparent = true;
	}
	else {
		pos = end + objsep.length();
		end = winStr.find(sep, pos);
		object = winStr.substr(pos, end);
	}
	if (toplvl == _T("No Top Window"))
		m_toplvl = NULL;
	else {
		m_toplvl = wxWindow::FindWindowByName(toplvl);
		if (m_toplvl == NULL) {
			wxLogDebug(_T("WinQual::WinQual(string): No Window %s found"), 
					   toplvl.c_str());
			return;
		}
	}
	if (parent == _T("No Window"))
		m_parent = NULL;
	else {
		m_parent = wxWindow::FindWindowByName(parent, m_toplvl);
		if (m_parent == NULL) {
			wxLogDebug(_T("WinQual::WinQual(string): No Window %s found in %s"),
					   parent.c_str(), toplvl.c_str());
			return;
		}
	}
	if (noparent) {
		m_window = m_parent;
		return;
	}
	m_window = wxWindow::FindWindowByName(object, m_parent);
	if (m_window == NULL) 
		wxLogDebug(_T("WinQual::WinQual(string): No Window %s found in %s -> %s"),
				   object.c_str(), toplvl.c_str(), parent.c_str());

}

wxString 
WinQual::serialize() {
	wxString outstr(_T(""));
	if (m_toplvl == NULL) 
		outstr << _T("No top level");
	else
		outstr << m_toplvl->GetName();
	if (m_parent != NULL && m_parent != m_window)
		outstr << objsep << m_parent->GetName();
	if (m_window == NULL)
		outstr << objsep << _T("No Window");
	else
		outstr << objsep << m_window->GetName();
	return outstr;
}

CRCatMap CREventImpl::s_catMap;

CREventImpl::CREventImpl() {
	if (s_catMap.empty())
		initCatMap();
}

CREventImpl::CREventImpl(wxEventType type) : m_type(type) {
    if (s_catMap.empty())
		initCatMap();
}

CREventImpl::CREventImpl(const wxEvent& evt) : 
	m_type(evt.GetEventType()), m_isNative(false) {
    if (s_catMap.empty())
		initCatMap();
	wxObject* obj = evt.GetEventObject();
	wxWindow* win = dynamic_cast<wxWindow*>(obj);
	if (win != NULL) {
		m_win = WinQual(win);
		return;
	}
	wxMenu* menu = dynamic_cast<wxMenu*>(obj);
	if (menu != NULL) {
		m_win = WinQual(menu->GetMenuBar());
		return;
	}
	m_win = WinQual(wxTheApp->GetTopWindow());
}

CREventImpl::CREventImpl(const wxEventType type, wxWindow* win, bool native,
						 const wxString& name) :
	m_type(type), m_win(win), m_name(name), m_isNative(native) {
    if (s_catMap.empty())
		initCatMap();
}

CREventImpl::CREventImpl(const wxString& eventStr) :
	m_type(extractType(eventStr)),	m_win(eventStr) {
    if (s_catMap.empty())
		initCatMap();

}


wxString
CREventImpl::serialize() {
	wxString evtString;
	CRCatMap::const_iterator map = s_catMap.find(m_type);
	if (map == s_catMap.end()) 
		evtString = _T("Null");
	else
		evtString = map->second.m_name;
	evtString << sep << m_win.serialize();
	return evtString;
}

wxString
CREventImpl::report() {
	wxString evtString;
	CRCatMap::const_iterator map = s_catMap.find(m_type);
	if (m_isNative) 
		evtString << _T("Native ");

	if (map == s_catMap.end()) 
		evtString << _T("Invalid Event Type");
	else
		evtString << map->second.m_name;
	if (m_type == wxEVT_NOT_TRANSLATED && !m_name.empty())
		evtString << _T(" ") << m_name;
	if (m_type == wxEVT_NULL)
		evtString << _T("/") << m_name;
	evtString << _T(" For wxWidget ") << m_win.serialize();
	return evtString;
}

bool
CREventImpl::check(uint16_t catmask) {
	CRCatMap::const_iterator map = s_catMap.find(m_type);
	if (map == s_catMap.end())
		return false;
	CREventCat cat = map->second.m_cat;
	if ((catmask & cat) != 0)
		return true;
	return false;
}

CREventMap
CREventImpl::findMapByName(const wxString& evtName) {

	CRCatMap::const_iterator pos = std::find_if(s_catMap.begin(), 
					     s_catMap.end(),
					     CREventImplName_Equals(evtName));
    if (pos == s_catMap.end()) {
		pos = s_catMap.find(wxEVT_NOT_TRANSLATED);
		if (pos == s_catMap.end()) {
			wxLogDebug(_T("CREventImpl::findMapByName: wxEVT_NOT_TRANSLATED not in category map."));
			CREventMap evt;
			return evt;
		}
	}
	return pos->second;
}

wxEventType 
CREventImpl::extractType(const wxString& evtString) {
	wxString evtName = extractString(evtString, typeflag, sep);
	return findMapByName(evtName).m_type;
}

wxString
CREventImpl::getClass(const wxEventType type) {
	CRCatMap::const_iterator pos = s_catMap.find(type);
	wxString retval;
	if (pos == s_catMap.end()) {
		wxLogDebug(_T("CREventImpl::getClass: Unable to find event type %d in category map"), type);
		return retval;
	}
	const CREventMap& map = pos->second;
	return map.m_crClass;
}


inline void 
CREventImpl::registerEvent(const wxEventType type, const wxString& name, 
					   const wxString& wxclass, const wxString& crclass, 
					   const CREventCat cat) {
    s_catMap.insert(
		std::make_pair(type, CREventMap(type, name, wxclass, crclass, cat)));
}


void
CREventImpl::initCatMap() {
//first the events in common/eventcmn.cpp:

    registerEvent(wxEVT_NULL, _T("Null"), _T("wxEvent"), _T("CREventImpl"), 
				  UndefinedEvents);
    registerEvent(wxEVT_IDLE, _T("Idle"), _T("wxEvent"), _T("CREventImpl"), 
				  AppEvents);
    registerEvent(wxEVT_SOCKET, _T("Socket"), _T("wxEvent"), _T("CREventImpl"), 
				  SystemEvents);
    registerEvent(wxEVT_TIMER, _T("Timer"), _T("wxEvent"), _T("CREventImpl"), 
				  SystemEvents);

    registerEvent(wxEVT_COMMAND_BUTTON_CLICKED, _T("Button Click"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_CHECKBOX_CLICKED, _T("Checkbox Click"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_CHOICE_SELECTED, _T("Choice Select"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_LISTBOX_SELECTED, _T("Listbox Select"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, 
				  _T("Listbox Doubleclick"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, _T("Checklistbox Toggle"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_MENU_SELECTED, _T("Menu Select"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_SLIDER_UPDATED, _T("Slider Update"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_RADIOBOX_SELECTED, _T("Radiobox Select"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_RADIOBUTTON_SELECTED, _T("Radiobutton Select"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_VLBOX_SELECTED, _T("VLbox Select"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_COMBOBOX_SELECTED, _T("Combobox Select"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_TOOL_RCLICKED, _T("Tool Right Click"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_TOOL_ENTER, _T("Tool Entry"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_SPINCTRL_UPDATED, _T("Spinctrl Update"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
#if (wxCHECK_VERSION(2,9,0))
	registerEvent(wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, 
				  _T("SpinctrlDouble Update"), _T("wxCommandEvent"), 
				  _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_TOOL_DROPDOWN_CLICKED, 
				  _T("Tool Dropdown Click"), _T("wxCommandEvent"), 
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
    registerEvent(wxEVT_LEFT_DOWN, _T("Mouse Left Down"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_LEFT_UP, _T("Mouse Left Up"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_LEFT_DCLICK, _T("Mouse Left Double Click"),  
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_MIDDLE_DOWN, _T("Mouse Middle Down"), 
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_MIDDLE_UP, _T("Mouse Middle Up"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_MIDDLE_DCLICK, _T("Mouse Middle Double Click"),  
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_RIGHT_DOWN, _T("Mouse Right Down"), _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_RIGHT_UP, _T("Mouse Right Up"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_RIGHT_DCLICK, _T("Mouse Right Double Click"),  
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
#if (wxCHECK_VERSION(2,9,0))
	registerEvent(wxEVT_AUX1_DOWN, _T("Mouse Aux1 Down"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_AUX1_UP, _T("Mouse Aux1 Up"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_AUX1_DCLICK, _T("Mouse Aux1 Double Click"),  
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_AUX2_DOWN, _T("Mouse Aux2 Down"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseButtonEvent);
    registerEvent(wxEVT_AUX2_UP, _T("Mouse Aux2 Up"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_AUX2_DCLICK, _T("Mouse Aux2 Double Click"),  
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
#endif
    registerEvent(wxEVT_MOTION, _T("Mouse Motion"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseMotionEvents);
    registerEvent(wxEVT_ENTER_WINDOW, _T("Mouse Enter"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseMotionEvents);
    registerEvent(wxEVT_LEAVE_WINDOW, _T("Mouse Exit"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseMotionEvents);
    registerEvent(wxEVT_SET_FOCUS, _T("Set Focus"), _T("wxFocusEvent"), 
			  _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_KILL_FOCUS, _T("Kill Focus"), _T("wxFocusEvent"), 
			  _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_CHILD_FOCUS, _T("Child Focus"), _T("wxChildFocusEvent"),
			  _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_MOUSEWHEEL, _T("Mouse Wheel"),  _T("wxMouseEvent"), 
			  _T("CRMouseEventImpl"), MouseWheelEvents);
    registerEvent(wxEVT_NC_LEFT_DOWN, _T("Mouse Non-client Left Down"),  
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_NC_LEFT_UP, _T("Mouse Non-client Left Up"),  
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_NC_LEFT_DCLICK, 
				  _T("Mouse Non-client Left Double Click"), 
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_NC_MIDDLE_DOWN, _T("Mouse Non-client Middle Down"), 
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_NC_MIDDLE_UP, _T("Mouse Non-client Middle Up"),  
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_NC_MIDDLE_DCLICK, 
				  _T("Mouse Non-client Middle Double Click"),
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_NC_RIGHT_DOWN, _T("Mouse Non-client Right Down"), 
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_NC_RIGHT_UP, _T("Mouse Non-client Right Up"),  
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_NC_RIGHT_DCLICK, 
				  _T("Mouse Non-client Right Double Click"), _T("wxMouseEvent"),
				  _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_NC_ENTER_WINDOW, _T("Mouse Non-client Enter"),  
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
    registerEvent(wxEVT_NC_LEAVE_WINDOW, _T("Mouse Non-client Exit"),  
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);

    registerEvent(wxEVT_CHAR, _T("Character"), _T("wxKeyEvent"), 
			  _T("CRKeyEventImpl"), TextEvents);
	registerEvent(wxEVT_CHAR_HOOK, _T("Character Hook"), _T("wxKeyEvent"), 
			  _T("CRKeyEventImpl"), TextEvents);
	registerEvent(wxEVT_NAVIGATION_KEY, _T("Navigation Key"), _T("wxKeyEvent"), 
			  _T("CRKeyEventImpl"), KeyEvents);
    registerEvent(wxEVT_KEY_DOWN, _T("Key Down"),  _T("wxKeyEvent"), 
			  _T("CRKeyEventImpl"), KeyEvents);
    registerEvent(wxEVT_KEY_UP, _T("Key Up"),  _T("wxKeyEvent"), 
			  _T("CRKeyEventImpl"), KeyEvents);
#if wxUSE_HOTKEY
    registerEvent(wxEVT_HOTKEY, _T("Hot Key"),  _T("wxKeyEvent"), 
			  _T("CRKeyEventImpl"), HotKeyEvents);
#endif

	registerEvent(wxEVT_SET_CURSOR, _T("Set Cursor"),  _T("wxEvent"), 
			  _T("CREventImpl"), MouseMotionEvents); //User code only

// wxScrollbar and wxSlider event identifiers (wxScrollEvent, wxSpinEvent
	registerEvent(wxEVT_SCROLL_TOP, _T("Scroll Top"),  _T("wxScrollEvent"), 
				  _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLL_BOTTOM, _T("Scroll Bottom"),
				  _T("wxScrollEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLL_LINEUP, _T("Scroll Line Up"),
				  _T("wxScrollEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLL_LINEDOWN, _T("Scroll Line Down"),
				  _T("wxScrollEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLL_PAGEUP, _T("Scroll Page Up"),
				  _T("wxScrollEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLL_PAGEDOWN, _T("Scroll Page Down"),
				  _T("wxScrollEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLL_THUMBTRACK, _T("Scroll Thumbtrack"),
				  _T("wxScrollEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLL_THUMBRELEASE, _T("Scroll Thumb Release"),
				  _T("wxScrollEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLL_CHANGED, _T("Scroll Changed"),
				  _T("wxScrollEvent"), _T("CREventImpl"), WindowEvents);

// Scroll events from wxWindow (wxScrollWinEvent)(msw, gtk, generic only)
	registerEvent(wxEVT_SCROLLWIN_TOP, _T("Scroll Window Top"),
			  _T("wxScrollWinEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLLWIN_BOTTOM, _T("Scroll Window Bottom"), 
				  _T("wxScrollWinEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLLWIN_LINEUP, _T("Scroll Window Line Up"), 
				  _T("wxScrollWinEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLLWIN_LINEDOWN, _T("Scroll Window Line Down"),
				  _T("wxScrollWinEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLLWIN_PAGEUP, _T("Scroll Window Page Up"),  
				  _T("wxScrollWinEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLLWIN_PAGEDOWN, _T("Scroll Window Page Down"),
				  _T("wxScrollWinEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLLWIN_THUMBTRACK, _T("Scroll Window Thumbtrack"),
				  _T("wxScrollWinEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_SCROLLWIN_THUMBRELEASE, _T("Scroll Window Thumb Rel"),
				  _T("wxScrollWinEvent"), _T("CREventImpl"), WindowEvents);

    registerEvent(wxEVT_SIZE, _T("Window Size"), _T("wxSizeEvent"), 
			  _T("CREventImpl"), WindowEvents);
    registerEvent(wxEVT_SIZING, _T("Window Sizing"), _T("wxSizeEvent"), 
			  _T("CREventImpl"), WindowEvents);
    registerEvent(wxEVT_MOVE, _T("Window Move"), _T("wxMoveEvent"), 
			  _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_MOVING, _T("Window Moving"), _T("wxMoveEvent"), 
			  _T("CREventImpl"), WindowEvents);
#if wxCHECK_VERSION(2, 9, 0)
	registerEvent(wxEVT_MOVE_START, _T("Window Start Moving"),
				  _T("wxMoveEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_MOVE_END, _T("Window End Moving"), _T("wxMoveEvent"), 
				  _T("CREventImpl"), WindowEvents);
#endif
	registerEvent(wxEVT_CLOSE_WINDOW, _T("Window Close"), _T("wxCloseEvent"), 
				  _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_END_SESSION, _T("End Session"),
				  _T("wxEvent"), _T("CREventImpl"), AppEvents);
	registerEvent(wxEVT_QUERY_END_SESSION, _T("Query End Session"),
				  _T("wxEvent"), _T("CREventImpl"), AppEvents);
	registerEvent(wxEVT_HIBERNATE, _T("Hibernate"),
				  _T("wxEvent"), _T("CREventImpl"), SystemEvents);
	registerEvent(wxEVT_ACTIVATE_APP, _T("Activate App"),
				  _T("wxEvent"), _T("CREventImpl"), AppEvents);
    registerEvent(wxEVT_ACTIVATE, _T("Window Activate"), _T("wxActivateEvent"), 
				  _T("CREventImpl"), WindowEvents);
    registerEvent(wxEVT_CREATE, _T("Window Create"), _T("wxWindowCreateEvent"), 
			  _T("CREventImpl"), WindowEvents);
    registerEvent(wxEVT_DESTROY, _T("Window Destroy"),
				  _T("wxWindowDestroyEvent"), _T("CREventImpl"), WindowEvents);
    registerEvent(wxEVT_SHOW, _T("Window Show"), _T("wxShowEvent"), 
			  _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_ICONIZE, _T("Window Iconize"),
				  _T("wxIconizeEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_MAXIMIZE, _T("Window Maximize"),
				  _T("wxMaximizeEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_MOUSE_CAPTURE_CHANGED, _T("Mouse Capture Changed"),
				  _T("wxMouseCaptureChangedEvent"), _T("CRMouseEventImpl"),
				  UndefinedEvents);
	registerEvent(wxEVT_MOUSE_CAPTURE_LOST, _T("Window Capture Lost"),
				  _T("wxMouseCaptureLostEvent"), _T("CRMouseEventImpl"),
				  UndefinedEvents);
    registerEvent(wxEVT_PAINT, _T("Window Paint"), _T("wxPaintEvent"), 
			  _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_ERASE_BACKGROUND, _T("Window Erase Background"),
				  _T("wxEraseEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_NC_PAINT, _T("Window NonClient Paint"),
				  _T("wxNcPaintEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_PAINT_ICON, _T("Window Paint Icon"),
				  _T("wxPaintEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_MENU_OPEN, _T("Menu Open"),  _T("wxMenuEvent"), 
				  _T("CREventImpl"), MenuEvents);
    registerEvent(wxEVT_MENU_CLOSE, _T("Menu Close"),  _T("wxMenuEvent"), 
				  _T("CREventImpl"), MenuEvents);
    registerEvent(wxEVT_MENU_HIGHLIGHT, _T("Menu Highlight"), _T("wxMenuEvent"),
				  _T("CREventImpl"), MenuEvents);
	registerEvent(wxEVT_CONTEXT_MENU, _T("Menu Highlight"), _T("wxMenuEvent"),
				  _T("CREventImpl"), MenuEvents);
	registerEvent(wxEVT_SYS_COLOUR_CHANGED, _T("Color Changed"),
				  _T("wxSysColourChangedEvent"), _T("CREventImpl"), 
				  SystemEvents);
	registerEvent(wxEVT_DISPLAY_CHANGED, _T("Display Changed"),
				  _T("wxDisplayChangedEvent"), _T("CREventImpl"), SystemEvents);
	registerEvent(wxEVT_SETTING_CHANGED, _T("Setting Changed"),
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_QUERY_NEW_PALETTE, _T("Query New Palette"),
			  _T("wxQueryNewPaletteEvent"), _T("CREventImpl"), SystemEvents);
	registerEvent(wxEVT_PALETTE_CHANGED, _T("Palette Changed"),
				  _T("wxPaletteChangedEvent"), _T("CREventImpl"), SystemEvents);
	registerEvent(wxEVT_JOY_BUTTON_DOWN, _T("Joystick Button Down"),
			  _T("wxMouseEvent"), _T("CRMouseEventImpl"), MouseButtonEvents);
	registerEvent(wxEVT_JOY_BUTTON_UP, _T("Joystick Button Up"),
				  _T("wxJoystickEvent"), _T("CRMouseEventImpl"), 
				  MouseButtonEvents);
	registerEvent(wxEVT_JOY_MOVE, _T("Joystick Motion"),  _T("wxJoystickEvent"),
				  _T("CRMouseEventImpl"), MouseMotionEvents);
	registerEvent(wxEVT_JOY_ZMOVE, _T("Joystick Z Motion"),
				  _T("wxJoystickEvent"), 
				  _T("CRJoystickEventImpl"), MouseMotionEvents);
	registerEvent(wxEVT_DROP_FILES, _T("Window Drop Files"),
				  _T("wxDropFilesEvent"), _T("CREventImpl"), WindowEvents);
	registerEvent(wxEVT_DRAW_ITEM, _T("Draw Item"),
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_MEASURE_ITEM, _T("Measure Item"),
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_COMPARE_ITEM, _T("Compare Item"),
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_INIT_DIALOG, _T("Init Dialog"),
				  _T("wxInitDialogEvent"), _T("CREventImpl"), AppEvents);
	registerEvent(wxEVT_UPDATE_UI, _T("Update UI"),
				  _T("wxUpdateUIEvent"), _T("CREventImpl"), SystemEvents);
	registerEvent(wxEVT_COMMAND_TEXT_COPY, _T("Command Text Copy"),  
				  _T("wxClipboardTextEvent"), _T("CRCommandEventImpl"),
				  ClipboardEvents);
	registerEvent(wxEVT_COMMAND_TEXT_CUT, _T("Command Text Cut"),  
				  _T("wxClipboardTextEvent"), _T("CRCommandEventImpl"),
				  ClipboardEvents);
	registerEvent(wxEVT_COMMAND_TEXT_PASTE, _T("Command Text Paste"),  
				  _T("wxClipboardTextEvent"), _T("CRCommandEventImpl"),
				  ClipboardEvents);
    registerEvent(wxEVT_COMMAND_LEFT_CLICK, _T("Command Left Click"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_LEFT_DCLICK, _T("Command Left Double Click"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_RIGHT_CLICK, _T("Command Right Click"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_RIGHT_DCLICK, _T("Command Right Double Click"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_SET_FOCUS, _T("Command Set Focus"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_KILL_FOCUS, _T("Command Kill Focus"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
    registerEvent(wxEVT_COMMAND_ENTER, _T("Command Enter"),  
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_HELP, _T("Help"),
				  _T("wxHelpyEvent"), _T("CREventImpl"), AppEvents);
	registerEvent(wxEVT_DETAILED_HELP, _T("Detailed Help"),
				  _T("wxHelpEvent"), _T("CREventImpl"), AppEvents);
    registerEvent(wxEVT_NOT_TRANSLATED, _T("Untranslated Event"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);

//Following events are defined in various implementation files

#if defined __WXMSW__ && wxUSE_ACTIVEX
	registerEvent(wxEVT_ACTIVEX, _T("ActiveX"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
#endif
#if 0
	registerEvent(wxEVT_QUERY_LAYOUT_INFO, _T("Layout Info"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_CALCULATE_LAYOUT, _T("Layout Calc"), _T("wxEvent"),
				  _T("CREventImpl"), UndefinedEvents);
#endif
#if wxUSE_CALENDARCTRL
	registerEvent(wxEVT_CALENDAR_SEL_CHANGED, _T("Calendar Sel Chg"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_CALENDAR_DAY_CHANGED, _T("Calendar Day Chg"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_CALENDAR_YEAR_CHANGED, _T("Calendar Year Chg"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_CALENDAR_DOUBLECLICKED, _T("Calendar DClick"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_CALENDAR_WEEKDAY_CLICKED, _T("Calendar Weekday"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
#endif
#if wxUSE_AUI
	registerEvent(wxEVT_AUI_PANE_BUTTON, _T("AUI Btn"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_AUI_PANE_CLOSE, _T("AUI Close"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_AUI_PANE_MAXIMIZE, _T("AUI Max"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_AUI_PANE_RESTORE, _T("AUI Restore"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_AUI_RENDER, _T("AUI Render"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_AUI_FIND_MANAGER, _T("AUI Mgr"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSE, 
				  _T("AUINotebook Page Closing"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSED, 
				  _T("AUINotebook Page Closed"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED, 
				  _T("AUINotebook Page Change"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGING, 
				  _T("AUINotebook Page Changing"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_BUTTON, 
				  _T("AUINotebook Button"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_BEGIN_DRAG, 
				  _T("AUINotebook Drag Begin"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_END_DRAG, 
				  _T("AUINotebook Drag End"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_DRAG_MOTION, 
				  _T("AUINotebook Drag Motion"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_ALLOW_DND, 
				  _T("AUINotebook DND"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_BG_DCLICK, 
				  _T("AUINotebook BG Click"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_DRAG_DONE, 
				  _T("AUINotebook Drag Done"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_TAB_MIDDLE_UP, 
				  _T("AUINotebook Tab MUp"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_TAB_MIDDLE_DOWN, 
				  _T("AUINotebook Tab MDown"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_TAB_RIGHT_UP, 
				  _T("AUINotebook Tab RUp"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_AUINOTEBOOK_TAB_RIGHT_DOWN, 
				  _T("AUINotebook Tab RDown"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_COLOURPICKERCTRL
	registerEvent(wxEVT_COMMAND_COLOURPICKER_CHANGED, 
				  _T("ColourPicker"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_COLLPANE && wxuSE_BUTTON && wxUSE_STATLINE
	registerEvent(wxEVT_COMMAND_COLLPANE_CHANGED, 
				  _T("CollPane"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_FONTPICKERCTRL
	registerEvent(wxEVT_COMMAND_FONTPICKER_CHANGED, 
				  _T("FontPicker"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_FILEPICKERCTRL || wxUSE_DIRPICKERCTRL
	registerEvent(wxEVT_COMMAND_FILEPICKER_CHANGED, 
				  _T("FilePicker"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_DIRPICKER_CHANGED, 
				  _T("DirPicker"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_DATAVIEWCTRL
	registerEvent(wxEVT_COMMAND_DATAVIEW_ROW_SELECTED, 
				  _T("DataView Row Sel"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_DATAVIEW_ROW_ACTIVATED, 
				  _T("DataView Row Active"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_DATAVIEW_COLUMN_HEADER_CLICK, 
				  _T("DataView Header Click"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_DATAVIEW_COLUMN_HEADER_RIGHT_CLICK, 
				  _T("DataView RClick"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_FINDREPLDLG
	registerEvent(wxEVT_COMMAND_FIND, _T("Find"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_FIND_NEXT, _T("Find Next"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_FIND_REPLACE, _T("Find Repl"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_FIND_REPLACE_ALL, _T("Find Repl All"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_FIND_CLOSE, _T("Find Close"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_HYPERLINKCTRL
	registerEvent(wxEVT_COMMAND_HYPERLINK, 
				  _T("Hyperlink"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_HTML
	registerEvent(wxEVT_COMMAND_HTML_CELL_CLICKED, 
				  _T("HTML Cell Click"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_HTML_CELL_HOVER, 
				  _T("HTML Cell Moved"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_HTML_LINK_CLICKED, 
				  _T("HTML Link Click"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_LISTCTRL
	registerEvent(wxEVT_COMMAND_LIST_BEGIN_DRAG, 
				  _T("ListCtrl Drag Begin"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_BEGIN_RDRAG, 
				  _T("ListCtrl RDrag Begin"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_BEGIN_LABEL_EDIT, 
				  _T("ListCtrl Label Ed Begin"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_END_LABEL_EDIT, 
				  _T("ListCtrl Label Ed End"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_DELETE_ITEM, 
				  _T("ListCtrl Item Del"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS, 
				  _T("ListCtrl All Del"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#if WXWIN_COMPATIBILITY_2_4
	registerEvent(wxEVT_COMMAND_LIST_GET_INFO, 
				  _T("ListCtrl Get Info"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_SET_INFO, 
				  _T("ListCtrl Set Info"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
	registerEvent(wxEVT_COMMAND_LIST_ITEM_SELECTED, 
				  _T("ListCtrl Item Sel"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_ITEM_DESELECTED, 
				  _T("ListCtrl Item Desel"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_INSERT_ITEM, 
				  _T("ListCtrl Insert"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_KEY_DOWN, 
				  _T("ListCtrl Key Dn"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_COL_CLICK, 
				  _T("ListCtrl Col Click"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, 
				  _T("ListCtrl Col RClick"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_COL_BEGIN_DRAG, 
				  _T("ListCtrl Col Drag Begin"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_COL_DRAGGING, 
				  _T("ListCtrl Col Dragging"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_COL_END_DRAG, 
				  _T("ListCtrl Col Drag End"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_ITEM_ACTIVATED, 
				  _T("ListCtrl Activate"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, 
				  _T("ListCtrl Item RClick"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_ITEM_MIDDLE_CLICK, 
				  _T("ListCtrl Item MClick"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_ITEM_FOCUSED, 
				  _T("ListCtrl Item Focus"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_LIST_CACHE_HINT, 
				  _T("ListCtrl Cache Hint"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_NOTEBOOK
	registerEvent(wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, 
				  _T("Notebook Page Changed"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, 
				  _T("Notebook Page Changing"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_RICHTEXT
	registerEvent(wxEVT_COMMAND_RICHTEXT_LEFT_CLICK, _T("Richtext LClick"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_MIDDLE_CLICK, _T("Richtext MClick"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_RIGHT_CLICK, _T("Richtext RClick"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_LEFT_DCLICK, _T("Richtext LDClick"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_RETURN, _T("Richtext Return"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_CHARACTER, _T("Richtext Char"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_DELETE, _T("Richtext Del"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_STYLESHEET_REPLACING, 
				  _T("Richtext Stylesheet Replacing"), _T("wxCommandEvent"), 
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_STYLESHEET_REPLACED, 
				  _T("Richtext Stylesheet Replaced"), _T("wxCommandEvent"), 
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_STYLESHEET_CHANGING, 
				  _T("Richtext Stylesheet Changing"), _T("wxCommandEvent"), 
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_STYLESHEET_CHANGED, 
				  _T("Richtext Stylesheet Changed"), _T("wxCommandEvent"), 
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_CONTENT_INSERTED, _T("Richtext Ins"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_CONTENT_DELETED, 
				  _T("Richtext Content Del"), _T("wxCommandEvent"), 
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_STYLE_CHANGED, _T("Richtext Style"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_RICHTEXT_SELECTION_CHANGED, _T("Richtext Sel"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
#if 0 && wxABI_VERSION >= 20808
	registerEvent(wxEVT_COMMAND_RICHTEXT_BUFFER_RESET, _T("Richtext Reset"), 
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
#endif
#endif
#if wxUSE_SEARCHCTRL
	registerEvent(wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, _T("Search Cancel"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, _T("Search"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_SPLITTER
	registerEvent(wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED, 
				  _T("Splitter Changed"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGING, 
				  _T("Splitter Changing"), _T("wxCommandEvent"), 
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_SPLITTER_DOUBLECLICKED, _T("Splitter DClick"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_SPLITTER_UNSPLIT, _T("Splitter Unsplit"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_TAB_DIALOG
	registerEvent(wxEVT_COMMAND_TAB_SEL_CHANGED, _T("Tab Changed"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TAB_SEL_CHANGING, _T("Tab Changing"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_TEXTCTRL
	registerEvent(wxEVT_COMMAND_TEXT_UPDATED, _T("Text Updated"), 
				 _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TEXT_ENTER,_T("Text Entry"), 
				 _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TEXT_URL, _T("Text URL"), _T("wxCommandEvent"),
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TEXT_MAXLEN,_T("Text MaxLen"), 
				 _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_TOGGLEBTN
	registerEvent(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,_T("Togglebtn"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_TREECTRL
	registerEvent(wxEVT_COMMAND_TREE_BEGIN_DRAG, _T("Tree Begin Drag"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents );
	registerEvent(wxEVT_COMMAND_TREE_BEGIN_RDRAG, _T("Tree Begin RDrag"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT, _T("Tree Begin Ed"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_END_LABEL_EDIT, _T("Tree End Ed"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_DELETE_ITEM, _T("Tree Item Del"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_GET_INFO, _T("Tree Get Info"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_SET_INFO, _T("Tree Set Info"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_ITEM_EXPANDED, _T("Tree Item Expand"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_ITEM_EXPANDING, _T("Tree Item Expanding"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_ITEM_COLLAPSED, _T("Tree Item Collapse"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_ITEM_COLLAPSING, 
				  _T("Tree Item Collapsing"), _T("wxCommandEvent"), 
				  _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_SEL_CHANGED, _T("Tree Sel Chg"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_SEL_CHANGING, _T("Tree Sel Chging"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_KEY_DOWN, _T("Tree Key Dn"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_ITEM_ACTIVATED, _T("Tree Item Act"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK, _T("Tree Item RClick"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_ITEM_MIDDLE_CLICK, _T("Tree Item MClick"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_END_DRAG, _T("Tree End Drag"),	
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_STATE_IMAGE_CLICK, _T("Tree Img DClick"),
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_ITEM_GETTOOLTIP, _T("Tree Item Tip"),
				 _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
	registerEvent(wxEVT_COMMAND_TREE_ITEM_MENU, _T("Tree Item Menu"),
				 _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents);
#endif
#if wxUSE_DIALUP_MANAGER
	registerEvent(wxEVT_DIALUP_CONNECTED, _T("Dialup Connect"),	
			  _T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents );
	registerEvent(wxEVT_DIALUP_DISCONNECTED, _T("Dialup Disconnected"),
				_T("wxCommandEvent"), _T("CRCommandEventImpl"), CommandEvents );
#endif
#if wxUSE_GRID
	registerEvent(wxEVT_GRID_CELL_LEFT_CLICK, _T("Grid Cell LClick"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_CELL_RIGHT_CLICK, _T("Grid Cell RClick"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_CELL_LEFT_DCLICK, _T("Grid Cell LDClick"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_CELL_RIGHT_DCLICK, _T("Grid Cell RDClick"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_CELL_BEGIN_DRAG, _T("Grid Cell Drag"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_CELL_CHANGE, _T("Grid Cell Change"), _T("wxEvent"),
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_SELECT_CELL, _T("Grid Cell Sel"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_LABEL_LEFT_CLICK, _T("Grid Label LClick"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_LABEL_RIGHT_CLICK, _T("Grid LabelRClick"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_LABEL_LEFT_DCLICK, _T("Grid LabelLDClick"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_LABEL_RIGHT_DCLICK, _T("Grid Label RDClick"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_ROW_SIZE, _T("Grid Row Size"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_COL_SIZE, _T("Grid Col Size"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_COL_MOVE, _T("Grid Col Move"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_RANGE_SELECT, _T("Grid Range Sel"), _T("wxEvent"),
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_EDITOR_SHOWN, _T("Grid Editor Show"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_EDITOR_HIDDEN, _T("Grid Editor Hide"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_GRID_EDITOR_CREATED, _T("Grid Editor Create"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
#endif
#if wxUSE_MEDIACTRL
	registerEvent(wxEVT_MEDIA_STATECHANGED, _T("Media State Changed"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_MEDIA_PLAY, _T("Media Play"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_MEDIA_PAUSE, _T("Media Pause"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_MEDIA_FINISHED, _T("Media Finished"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_MEDIA_LOADED, _T("Media Loaded"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_MEDIA_STOP, _T("Media Stop"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
#endif
#ifdef wxHAS_POWER_EVENTS
	registerEvent(wxEVT_POWER_SUSPENDING, _T("Power Suspending"), _T("wxEvent"),
				  _T("CREventImpl"), SystemEvents);
	registerEvent(wxEVT_POWER_SUSPENDED, _T("Power Suspended"), _T("wxEvent"),
				  _T("CREventImpl"), SystemEvents);
	registerEvent(wxEVT_POWER_SUSPEND_CANCEL, _T("Power Cancel"), _T("wxEvent"),
				  _T("CREventImpl"), SystemEvents);
	registerEvent(wxEVT_POWER_RESUME, _T("Power Resume"), _T("wxEvent"),
				  _T("CREventImpl"), SystemEvents);
#endif
#if 0
	registerEvent(wxEVT_END_PROCESS, _T("EndProcess"), _T("wxEvent"),
				  _T("CREventImpl"), AppEvents);
#endif
#if wxUSE_SASH
	registerEvent(wxEVT_SASH_DRAGGED, _T("Sash Dragged "), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
#endif
#if 0 && wxUSE_SOUND && wxUSE_LIBSDL //No header, event declared in implementation file
	registerEvent(wxEVT_SOUND_BACKEND_SDL_NOTIFICATION, _T("SDL Notify"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
#endif
#ifdef wxHAS_TASK_BAR_ICON
	registerEvent(wxEVT_TASKBAR_MOVE, _T("Taskbar Move"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_TASKBAR_LEFT_DOWN, _T("Taskbar LDown"), _T("wxEvent"),
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_TASKBAR_RIGHT_DOWN, _T("Taskbar RDown"), _T("wxEvent"),
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_TASKBAR_LEFT_UP, _T("Taskbar LUp"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_TASKBAR_RIGHT_UP, _T("Taskbar RUp"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_TASKBAR_LEFT_DCLICK, _T("Taskbar LDClick"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_TASKBAR_RIGHT_DCLICK, _T("Taskbar RDClick "), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
#endif
#if wxUSE_WIZARDDLG
	registerEvent(wxEVT_WIZARD_PAGE_CHANGED, _T("Wizard Changed"),
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_WIZARD_PAGE_CHANGING, _T("Wizard Changing"), 
				  _T("wxEvent"), _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_WIZARD_CANCEL, _T("Wizard Cancel"), _T("wxEvent"),
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_WIZARD_FINISHED, _T("Wizard Finish"), _T("wxEvent"),
				  _T("CREventImpl"), UndefinedEvents);
	registerEvent(wxEVT_WIZARD_HELP, _T("Wizard Help"), _T("wxEvent"), 
				  _T("CREventImpl"), UndefinedEvents);
#endif
}

bool
CREventImpl::postWxEvent() {
	if (m_type == wxEVT_NULL || m_type == wxEVT_NOT_TRANSLATED) {
		wxLogDebug(_T("CREventImpl::postWxEvent: Can't post a wxEVT_NULL or a wxEVT_NOT_TRANSLATED: %s"), m_name.c_str());
		return false;
	}
	if (m_type == wxEVT_SIZE)
	{
		wxSize size; //FIXME: This needs to come from somewhere
		wxSizeEvent evt(size); 
		evt.SetEventObject(m_win.getWindow());
		::wxPostEvent(m_win.getWindow(), evt);
		return true;
	}
	if (m_type == wxEVT_MOVE)
	{
		wxPoint place; //FIXME: This needs to come from somewhere
		wxMoveEvent evt(place); //Need to store wxPoint place
		evt.SetEventObject(m_win.getWindow());
		::wxPostEvent(m_win.getWindow(), evt);
		return true;
	}
	if (m_type == wxEVT_CLOSE_WINDOW)
	{
		wxCloseEvent evt; //Note provision for CanVeto
		evt.SetEventObject(m_win.getWindow());
		::wxPostEvent(m_win.getWindow(), evt);
		return true;
	}
	if (m_type == wxEVT_ACTIVATE)
	{
		wxActivateEvent evt; //Note this event can also handle wxEVT_ACTIVATE_APP and wxEVT_HIBERNATE
		evt.SetEventObject(m_win.getWindow());
		::wxPostEvent(m_win.getWindow(), evt);
		return true;
	}
//Kinda hard to imagine how posting this event makes sense...
//Note also that it's derived from wxCommandEvent
	if (m_type == wxEVT_CREATE)
	{
		wxWindowCreateEvent evt;
		evt.SetEventObject(m_win.getWindow());
		::wxPostEvent(m_win.getWindow(), evt);
		return true;
	}
//This one's a bit odd to post, too
//And it's a kid of wxCommandEvent
	if (m_type == wxEVT_DESTROY)
	{
		wxWindowDestroyEvent evt;
				evt.SetEventObject(m_win.getWindow());
		::wxPostEvent(m_win.getWindow(), evt);
		return true;
	}
//And here it would be better to just call Show on the window
	if (m_type == wxEVT_SHOW)
	{
		wxShowEvent evt; //Needs a bool for "show"
		evt.SetEventObject(m_win.getWindow());
		::wxPostEvent(m_win.getWindow(), evt);
		return true;
	}
//This is really all we need to do
	if (m_type == wxEVT_PAINT)
	{
		wxPaintEvent evt;
		evt.SetEventObject(m_win.getWindow());
		::wxPostEvent(m_win.getWindow(), evt);
		return true;
	}
	if (m_type == wxEVT_SET_FOCUS || m_type == wxEVT_KILL_FOCUS) 
	{
		wxFocusEvent evt(m_type);
		evt.SetEventObject(m_win.getWindow());
		::wxPostEvent(m_win.getWindow(), evt);
		return true;
	}
	if (m_type == wxEVT_MENU_OPEN
		|| m_type == wxEVT_MENU_CLOSE
		|| m_type == wxEVT_MENU_HIGHLIGHT)
	{
		wxMenuEvent evt(m_type);
		evt.SetEventObject(m_win.getWindow());
		::wxPostEvent(m_win.getWindow(), evt);
		return true;
	}
	wxLogDebug(_T("CREventImpl::postWxEvent: Unknown Event Type %d"), m_type);
	return false;
}

CRCommandEventImpl::CRCommandEventImpl() { }

CRCommandEventImpl::CRCommandEventImpl(wxEventType type) : CREventImpl(type) { }

CRCommandEventImpl::CRCommandEventImpl(const wxCommandEvent& evt) :
	CREventImpl(evt), m_cmdString(evt.GetString()), 
	m_cmdInt(evt.GetInt(), cmdIntFlag),
	m_cmdXLong(evt.GetExtraLong(), cmdXLFlag) {}

CRCommandEventImpl::CRCommandEventImpl(const wxEventType type, wxWindow* win,
									   const wxString& command, int int1, 
									   long int2 ) :
	CREventImpl(type, win), m_cmdString(command), m_cmdInt(int1, cmdIntFlag), 
	m_cmdXLong(int2, cmdXLFlag) { }

CRCommandEventImpl::CRCommandEventImpl(const wxString& evtString) : 
	CREventImpl(evtString), 
	m_cmdString(extractString(evtString, cmdStrFlag, sep)),
	m_cmdInt(evtString, cmdIntFlag),
	m_cmdXLong(evtString, cmdXLFlag) { }


wxString 
CRCommandEventImpl::serialize() {
	wxString evtStr = CREventImpl::serialize();
	evtStr << sep << cmdStrFlag << m_cmdString << m_cmdInt.serialize() 
		   << m_cmdXLong.serialize();
	return evtStr;
}

wxString 
CRCommandEventImpl::report() {
	wxString rpt = CREventImpl::report();
	rpt << _T(" command: ") << m_cmdString;
	return rpt;
}

bool
CRCommandEventImpl::postWxEvent() {
	wxCommandEvent evt(m_type, m_win.getWindow()->GetId());
	evt.SetString(m_cmdString);
	evt.SetInt(m_cmdInt.getVal());
	evt.SetExtraLong(m_cmdXLong.getVal());
	evt.SetEventObject(m_win.getWindow());
	::wxPostEvent(m_win.getWindow(), evt);
	return true;
}

CRMouseEventImpl::CRMouseEventImpl() { }

CRMouseEventImpl::CRMouseEventImpl(wxEventType type) : CREventImpl(type) { }

static inline bool 
isDClick(const wxEventType type) {
	return (type == wxEVT_LEFT_DCLICK || 
			type == wxEVT_MIDDLE_DCLICK || 
			type == wxEVT_RIGHT_DCLICK);
}

CRMouseEventImpl::CRMouseEventImpl(const wxMouseEvent& evt) :
	CREventImpl(evt), m_clickCount((isDClick(m_type) ? 2 : 1), clickFlag), 
	m_coord(evt.GetPosition(), coordFlag) { 
	m_buttonMask = evt.Button(wxMOUSE_BTN_RIGHT) << 6 +
		evt.Button(wxMOUSE_BTN_MIDDLE ) << 5 +
		evt.Button(wxMOUSE_BTN_LEFT) << 4 +
		evt.MetaDown() << 3 +
		evt.AltDown() << 2 +
		evt.ShiftDown() << 1 +
		evt.ControlDown();
	if (m_type == wxEVT_MOUSEWHEEL) {
		m_clickCount = IntVal((evt.GetWheelRotation() > 0 ? 1 : -1), clickFlag);
		m_wheelDelta = IntVal(evt.GetWheelDelta(), deltaFlag);
		m_wheelLines = IntVal(evt.GetLinesPerAction(), linesFlag);
	}
}

CRMouseEventImpl::CRMouseEventImpl(const wxEventType type, wxWindow* win,
								   ModMask mod, int clickcount, 
								   wxPoint coord, bool native, int delta, 
								   int lines) :
	CREventImpl(type, win, native), m_buttonMask(mod), 
	m_clickCount(clickcount, clickFlag),
	m_coord(coord, coordFlag), m_wheelDelta(delta, deltaFlag), 
	m_wheelLines(lines, linesFlag) { 
}

CRMouseEventImpl::CRMouseEventImpl(const wxString& eventStr) :
	CREventImpl(eventStr),
	m_clickCount(eventStr, clickFlag),
	m_coord(eventStr, coordFlag),
	m_wheelDelta(eventStr, deltaFlag),
	m_wheelLines(eventStr, linesFlag) {
	unsigned long l = 0;
	if (extractString(eventStr, modFlag).ToULong(&l))
		m_buttonMask = l;
	if (extractString(eventStr, nativeFlag).ToULong(&l))
		m_isNative = l;
}

wxString
CRMouseEventImpl::serialize() {
	wxString evt = CREventImpl::serialize();
	evt << sep << modFlag << m_buttonMask << m_clickCount.serialize()
		<< m_coord.serialize();
		evt << m_wheelDelta.serialize() << m_wheelLines.serialize();
	return evt;
}

wxString
CRMouseEventImpl::report() {
	wxString evt = CREventImpl::report();
	if (m_type == wxEVT_MOTION && m_buttonMask & (left | middle | right)) {
		evt << _T(" with Button(s)");
		if (m_buttonMask & left)
			evt << _T(" LEFT");
		if (m_buttonMask & middle)
			evt << _T(" MIDDLE");
		if (m_buttonMask & right)
			evt << _T(" RIGHT");
	}
	if (m_type == wxEVT_MOUSEWHEEL) {
		if (m_clickCount < 0)
			evt << _T(" UP");
		else
			evt << _T(" DOWN");
	}
	if (m_buttonMask & (ctrl | shift | alt | meta)) {
		if (m_type == wxEVT_MOTION && m_buttonMask & (left | middle | right))
			evt << _T(" and Modifier Keys");
		else
			evt << _T(" with Modifier Keys");
		if (m_buttonMask & ctrl)
			evt << _T(" CTRL");
		if (m_buttonMask & shift)
			evt << _T(" SHIFT");
		if (m_buttonMask & alt)
			evt << _T(" ALT");
		if (m_buttonMask & meta)
			evt << _T(" META");
	}
	evt << _T(" at ") << m_coord.serialize();

	return evt;
}

bool
CRMouseEventImpl::postWxEvent() {
	if (m_isNative) {
		wxLogDebug(_T("CRMouseEventImpl:postWxEvent: This event is native"));
		return false;
	}
	wxMouseEvent evt(m_type);
	evt.m_leftDown = (m_buttonMask & left) > 0;
	evt.m_middleDown = (m_buttonMask & middle) > 0;
	evt.m_rightDown = (m_buttonMask & right) > 0;
	evt.m_controlDown = (m_buttonMask & ctrl) > 0;
	evt.m_shiftDown = (m_buttonMask & shift) > 0;
	evt.m_altDown = (m_buttonMask & alt) > 0;
	evt.m_metaDown = (m_buttonMask & meta) > 0;
	if (m_type == wxEVT_MOUSEWHEEL) {
		evt.m_wheelRotation = m_clickCount.getVal();
		evt.m_wheelDelta = m_wheelDelta.getVal();
		evt.m_linesPerAction = m_wheelLines.getVal();
	}
	evt.m_x = m_coord.getX();
	evt.m_y = m_coord.getY();
	::wxPostEvent(m_win.getWindow(), evt);
	return true;
}

CRKeyEventImpl::CRKeyEventImpl() { }

CRKeyEventImpl::CRKeyEventImpl(wxEventType type) : CREventImpl(type) { }

CRKeyEventImpl::CRKeyEventImpl(const wxKeyEvent& evt) : 
	CREventImpl(evt), 
	m_modkey(fromWx(evt.GetModifiers())), 
	m_keycode(evt.GetKeyCode(), keyFlag)
{ }

CRKeyEventImpl::CRKeyEventImpl(const wxEventType type, wxWindow* win,
							   ModMask mod, long keycode, bool native) :
	CREventImpl(type, win, native), 
	m_modkey(mod), 
	m_keycode(keycode, keyFlag)
{}

CRKeyEventImpl::CRKeyEventImpl(const wxString& evtStr) : 
	CREventImpl(evtStr), m_keycode(evtStr, keyFlag) { 
	long l = 0;
	if (extractString(evtStr, modFlag).ToLong(&l))
		m_modkey = l;
}


wxString
CRKeyEventImpl::serialize() {
	wxString evt = CREventImpl::serialize();
	evt << modFlag << m_modkey << m_keycode.serialize();
	return evt;
}

wxString
CRKeyEventImpl::report() {
	wxString evt = CREventImpl::report();
	evt << _T(" Keycode ") << m_keycode.getVal();
	if (m_modkey & (ctrl | shift | alt | meta)) {
			evt << _T(" with Modifier Keys");
		if (m_modkey & ctrl)
			evt << _T(" CTRL");
		if (m_modkey & shift)
			evt << _T(" SHIFT");
		if (m_modkey & alt)
			evt << _T(" ALT");
		if (m_modkey & meta)
			evt << _T(" META");
	}
	return evt;
}


bool
CRKeyEventImpl::postWxEvent() {
	if (m_isNative) {
		wxLogDebug(_T("CRKeyEventImpl:postWxEvent: This event is native"));
		return false;
	}
	wxKeyEvent evt(m_type);
	evt.m_controlDown = (m_modkey & ctrl) > 0;
	evt.m_shiftDown = (m_modkey & shift) > 0;
	evt.m_altDown = (m_modkey & alt) > 0;
	evt.m_metaDown = (m_modkey & meta) > 0;
	evt.m_keyCode = m_keycode.getVal();
//	evt.m_x = m_coord.getX();
//	evt.m_y = m_coord.getY();
	::wxPostEvent(m_win.getWindow(), evt);
	return true;
}

ModMask
CRKeyEventImpl::fromWx(int mod) {
	return 
		((mod & wxMOD_CONTROL) > 0 ? ctrl : 0) |
		((mod & wxMOD_SHIFT) > 0 ? shift : 0) |
		((mod & wxMOD_META) > 0 ? meta : 0) |
		((mod & wxMOD_ALT) > 0 ? alt : 0) ;
}
