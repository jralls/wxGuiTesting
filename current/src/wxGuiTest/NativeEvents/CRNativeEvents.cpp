///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/NativeEvents/CRNativeEvent.cpp
// Author:      John Ralls
// Created:     2008
// Copyright:   (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id: CRNativeEvent.cpp 69 2008-01-24 21:16:37Z john $
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRNativeEvents.h"
#endif

#include <wxGuiTest/CRNativeEvents.h>
#include <wx/version.h>
#include <algorithm>

using namespace wxTst;

const wxString CRNativeEvent::s_delim(_T("::"));
const wxString CRNativeEvent::s_inDelim(_T(","));
CREventMask CRNativeEvent::s_eventMask = 0;
CREventMap CRNativeEvent::s_eventMap;
DEFINE_EVENT_TYPE(wxEVT_NOT_TRANSLATED);

//Functor class for searching s_eventMap for name values.
class CREventName_Equals {
public:
    CREventName_Equals(wxString name) : m_name(name) {}
	bool operator() (std::pair<wxEventType, CREvent> elem) {
		return elem.second.m_name == m_name;
    }
private:
    wxString m_name;
};

CREvent::CREvent(const wxEventType type, const wxString name, 
		       const CREventCat cat) :
    m_name(name), m_evt(type), m_cat(cat) {}

inline void 
CRNativeEvent::pushEvent(const wxEventType type, const wxString name, 
			     const CREventCat cat) {
    s_eventMap.insert(std::make_pair(type, CREvent(type, name, cat)));
}

CRNativeEvent::CRNativeEvent() {
    if (s_eventMap.empty())
	initEventMap();
}

CRNativeEvent::CRNativeEvent(CREvent evt) :
    m_wxevent(evt) {
    if (s_eventMap.empty())
	initEventMap();
}

CRNativeEvent::CRNativeEvent(wxEventType type) {
    if (s_eventMap.empty())
	initEventMap();
    CREventMap::const_iterator pos = s_eventMap.find(type);
    if (pos == s_eventMap.end()) return;
    m_wxevent = pos->second;
}

CRNativeEvent::CRNativeEvent(const wxString& name) {
    if (s_eventMap.empty())
	initEventMap();
	CREventMap::const_iterator pos = std::find_if(s_eventMap.begin(), 
					     s_eventMap.end(),
					     CREventName_Equals(name));
    if (pos == s_eventMap.end()) return;
    m_wxevent = pos->second;
}

void
CRNativeEvent::initEventMap() {
    pushEvent(wxEVT_NULL, _T("Null"), System);
    pushEvent(wxEVT_COMMAND_BUTTON_CLICKED, _T("Button Click"), Command);
    pushEvent(wxEVT_COMMAND_CHECKBOX_CLICKED, _T("Checkbox Click"), Command);
    pushEvent(wxEVT_COMMAND_CHOICE_SELECTED, _T("Choice Select"), Command);
    pushEvent(wxEVT_COMMAND_LISTBOX_SELECTED, _T("Listbox Select"), Command);
    pushEvent(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, _T("Listbox Doubleclick"), 
	      Command);
    pushEvent(wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, _T("Checklistbox Toggle"), 
	      Command);
    pushEvent(wxEVT_COMMAND_MENU_SELECTED, _T("Menu Select"), MenuEvent);
    pushEvent(wxEVT_COMMAND_SLIDER_UPDATED, _T("Slider Update"), Command);
    pushEvent(wxEVT_COMMAND_RADIOBOX_SELECTED, _T("Radiobox Select"), Command);
    pushEvent(wxEVT_COMMAND_RADIOBUTTON_SELECTED, _T("Radiobutton Select"), 
	      Command);
    pushEvent(wxEVT_COMMAND_VLBOX_SELECTED, _T("VLbox Select"), Command);
    pushEvent(wxEVT_COMMAND_COMBOBOX_SELECTED, _T("Combobox Select"), Command);
    pushEvent(wxEVT_COMMAND_TOOL_RCLICKED, _T("Tool Right Click"), Command);
#if (wxCHECK_VERSION(2,9,0))
    pushEvent(wxEVT_COMMAND_TOOL_DROPDOWN_CLICKED, _T("Tool Dropdown Click"),
	      Command);
#endif
    pushEvent(wxEVT_COMMAND_TOOL_ENTER, _T("Tool Entry"), Command);
    pushEvent(wxEVT_COMMAND_SPINCTRL_UPDATED, _T("Spinctrl Update"), Command);
    pushEvent(wxEVT_LEFT_DOWN, _T("Mouse Left Down"), MouseEvent);
    pushEvent(wxEVT_LEFT_UP, _T("Mouse Left Up"), MouseEvent);
    pushEvent(wxEVT_LEFT_DCLICK, _T("Mouse Left Double Click"), MouseEvent);
    pushEvent(wxEVT_MIDDLE_DOWN, _T("Mouse Middle Down"), MouseEvent);
    pushEvent(wxEVT_MIDDLE_UP, _T("Mouse Middle Up"), MouseEvent);
    pushEvent(wxEVT_MIDDLE_DCLICK, _T("Mouse Middle Double Click"), MouseEvent);
    pushEvent(wxEVT_RIGHT_DOWN, _T("Mouse Right Down"), MouseEvent);
    pushEvent(wxEVT_RIGHT_UP, _T("Mouse Right Up"), MouseEvent);
    pushEvent(wxEVT_RIGHT_DCLICK, _T("Mouse Right Double Click"), MouseEvent);
#if (wxCHECK_VERSION(2,9,0))
	pushEvent(wxEVT_AUX1_DOWN, _T("Mouse Aux1 Down"), MouseEvent);
    pushEvent(wxEVT_AUX1_UP, _T("Mouse Aux1 Up"), MouseEvent);
    pushEvent(wxEVT_AUX1_DCLICK, _T("Mouse Aux1 Double Click"), MouseEvent);
    pushEvent(wxEVT_AUX2_DOWN, _T("Mouse Aux2 Down"), MouseEvent);
    pushEvent(wxEVT_AUX2_UP, _T("Mouse Aux2 Up"), MouseEvent);
    pushEvent(wxEVT_AUX2_DCLICK, _T("Mouse Aux2 Double Click"), MouseEvent);
#endif
    pushEvent(wxEVT_MOTION, _T("Mouse Motion"), MouseEvent);
    pushEvent(wxEVT_ENTER_WINDOW, _T("Mouse Enter"), MouseEvent);
    pushEvent(wxEVT_LEAVE_WINDOW, _T("Mouse Exit"), MouseEvent);
    pushEvent(wxEVT_MOUSEWHEEL, _T("Mouse Wheel"), MouseEvent);
    pushEvent(wxEVT_NC_LEFT_DOWN, _T("Mouse Non-client Left Down"), MouseEvent);
    pushEvent(wxEVT_NC_LEFT_UP, _T("Mouse Non-client Left Up"), MouseEvent);
    pushEvent(wxEVT_NC_LEFT_DCLICK, _T("Mouse Non-client Left Double Click"), 
	      MouseEvent);
    pushEvent(wxEVT_NC_MIDDLE_DOWN, _T("Mouse Non-client Middle Down"), 
	      MouseEvent);
    pushEvent(wxEVT_NC_MIDDLE_UP, _T("Mouse Non-client Middle Up"), MouseEvent);
    pushEvent(wxEVT_NC_MIDDLE_DCLICK, 
	      _T("Mouse Non-client Middle Double Click"), MouseEvent);
    pushEvent(wxEVT_NC_RIGHT_DOWN, _T("Mouse Non-client Right Down"), 
	      MouseEvent);
    pushEvent(wxEVT_NC_RIGHT_UP, _T("Mouse Non-client Right Up"), MouseEvent);
    pushEvent(wxEVT_NC_RIGHT_DCLICK, _T("Mouse Non-client Right Double Click"),
	      MouseEvent);
    pushEvent(wxEVT_NC_ENTER_WINDOW, _T("Mouse Non-client Enter"), MouseEvent);
    pushEvent(wxEVT_NC_LEAVE_WINDOW, _T("Mouse Non-client Exit"), MouseEvent);
    pushEvent(wxEVT_CHAR, _T("Character"), TextEvent);
    pushEvent(wxEVT_NAVIGATION_KEY, _T("Navigation Key"), KeyEvent);
    pushEvent(wxEVT_KEY_DOWN, _T("Key Down"), KeyEvent);
    pushEvent(wxEVT_KEY_UP, _T("Key Up"), KeyEvent);
    pushEvent(wxEVT_HOTKEY, _T("Hot Key"), KeyEvent);
    pushEvent(wxEVT_SIZE, _T("Window Size"), WindowManipulation);
    pushEvent(wxEVT_MOVE, _T("Window Move"), WindowManipulation);
    pushEvent(wxEVT_CLOSE_WINDOW, _T("Window Close"), WindowManipulation);
    pushEvent(wxEVT_ACTIVATE, _T("Window Activate"), WindowManipulation);
    pushEvent(wxEVT_CREATE, _T("Window Create"), WindowManipulation);
    pushEvent(wxEVT_DESTROY, _T("Window Destroy"), WindowManipulation);
    pushEvent(wxEVT_SHOW, _T("Window Show"), WindowManipulation);
    pushEvent(wxEVT_PAINT, _T("Window Paint"), WindowManipulation);
    pushEvent(wxEVT_MENU_OPEN, _T("Menu Open"), MenuEvent);
    pushEvent(wxEVT_MENU_CLOSE, _T("Menu Close"), MenuEvent);
    pushEvent(wxEVT_MENU_HIGHLIGHT, _T("Menu Highlight"), MenuEvent);
    pushEvent(wxEVT_COMMAND_LEFT_CLICK, _T("Command Left Click"), Command);
    pushEvent(wxEVT_COMMAND_LEFT_DCLICK, _T("Command Left Double Click"), 
	      Command);
    pushEvent(wxEVT_COMMAND_RIGHT_CLICK, _T("Command Right Click"), Command);
    pushEvent(wxEVT_COMMAND_RIGHT_DCLICK, _T("Command Right Double Click"), 
	      Command);
    pushEvent(wxEVT_COMMAND_SET_FOCUS, _T("Command Set Focus"), Command);
    pushEvent(wxEVT_COMMAND_KILL_FOCUS, _T("Command Kill Focus"), Command);
    pushEvent(wxEVT_COMMAND_ENTER, _T("Command Enter"), Command);
    pushEvent(wxEVT_NOT_TRANSLATED, _T("Untranslated Event"), Undefined);
}

const wxString
CRNativeEvent::getEventString() const {
    return m_wxevent.m_name;
}



