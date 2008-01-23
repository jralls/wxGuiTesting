///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CREventCaptureManager.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CREventCaptureManager.h"
#endif

#include <wxGuiTest/CREventCaptureManager.h>

#include <fstream>

#include <wx/xrc/xmlres.h>
#include <wx/notebook.h>
#include <wx/listbase.h>
#include <wx/splitter.h>
#include <wx/treebase.h>
#include <wx/tglbtn.h>

#include <wxGuiTest/CRLogInterface.h>
#include "CapturedEvents/CRCapturedEvent.h"
#include "CREventFactory.h"
#include <wxGuiTest/CRCppEmitter.h>

namespace wxTst {


// Init single instance:
CREventCaptureManager *CREventCaptureManager::ms_instance = NULL;


CREventCaptureManager::CREventCaptureManager ()
{
    m_ignoreWdw = NULL;
    m_isOn = false;
    m_event = NULL;
    m_log = NULL;
    m_logStream = new std::ofstream ();
    m_logStream->open ("CREventCaptureManager.log");

    m_pendingEvent = NULL;
}


CREventCaptureManager::~CREventCaptureManager ()
{
    if (m_logStream != NULL) {

        m_logStream->close ();
        m_logStream = NULL;
    }

    // Emit pending event, if existing, before destruction:
    this->EmitPendingEvent();

    //EventList::const_iterator it;
    //for (it = m_eventList.begin (); it != m_eventList.end (); it++) {
    //
    //    delete (*it);
    //}
    //m_eventList.clear ();

    ms_instance = NULL;
}


CREventCaptureManager * CREventCaptureManager::GetInstance ()
{
    if (ms_instance == NULL) {

        ms_instance = new CREventCaptureManager ();
    }
    return ms_instance;
}


void CREventCaptureManager::Destroy ()
{
    if (ms_instance != NULL) {

        delete ms_instance;
        ms_instance = NULL;
    }
}


void CREventCaptureManager::IgnoreWindow (wxWindow *wdw)
{
    m_ignoreWdw = wdw;
}


void CREventCaptureManager::On ()
{
    m_isOn = true;
}


void CREventCaptureManager::Off ()
{
    m_isOn = false;
}


bool CREventCaptureManager::IsOn () const
{
    return m_isOn;
}


void CREventCaptureManager::SetLogger (CRLogInterface *log)
{
    m_log = log;
}


void CREventCaptureManager::FilterEvent (wxEvent &event)
{
    if (this->IsOn ()) {

        // Check if event stems from capture dialog:
        if (this->CanIgnore (event)) {

            return;
        }
        // Check if event has already been processed:
        if ((m_event != NULL) && (&event == m_event)) {

            return;
        }
/*
        if ((!m_eventList.empty ()) &&
                (&event == m_eventList.back ()->GetEvent ())) {

            return;
        }
*/
        m_event = &event;

/*
wxEvent *listEndEvt, *evt;
if (!m_eventList.empty ())
  listEndEvt = m_eventList.back ()->GetEvent ();
*/
        CRCapturedEvent *captureEvt = CREventFactory::GetInstance ()->
                CreateEvent (event);
        if (captureEvt) {

            // Do we really need the list of events? Right now we are emitting
            // as early as possible:
            //m_eventList.push_back (captureEvt);

            captureEvt->Process (&m_pendingEvent);
            // Finish handling potentially pending event:
            this->EmitPendingEvent();

            if (captureEvt->IsIrrelevant ()) {

                delete captureEvt;

            } else if (captureEvt->IsPending ()) {

                m_pendingEvent = captureEvt;

            } else {

                captureEvt->EmitCpp ();
                delete captureEvt;
            }

        } else {

            wxString evtDesc = this->GetDescForUnsupportedEvent (event);
            if (!evtDesc.IsEmpty ()) {

                CRCppEmitter::GetInstance ()->AddComment (
                        wxString::Format (_T("Unsupported event %s %s\n"),
                        evtDesc.c_str (), this->GetEventDetails (event).c_str ()));
                this->LogEventDetails (event, wxString::Format (
                        _T("Unsupported event %s"), evtDesc.c_str ()));
            }
        }
        // Log all events to file:
        wxString evtDesc = this->GetEventDesc (event);
        if (!evtDesc.IsEmpty ()) {

            (*m_logStream) << evtDesc.c_str () << _T(": ") <<
                    this->GetEventDetails (event).c_str () << std::endl;
        }
    }
}


bool CREventCaptureManager::CanIgnore (wxEvent &event)
{
    // Ignore events from capture dialog:
    // Seems to be correct while missing the detection in some situations.
    // Not used in favour of the hierarchy method, because it is in 99.?%
    // of the cases slower:
    /*
    wxWindow *child = wxWindow::FindWindowById (event.GetId (), m_ignoreWdw);
    if (child) {

        //std::cout << _T("child:") << child << _T(" - ");
        return true;
    }
    */
    wxWindow *wdw = wxDynamicCast (event.GetEventObject (), wxWindow);
    if (wdw != NULL) {

        if (wdw == m_ignoreWdw) {

            //std::cout << _T("wdw: ") << wdw << std::endl;
            return true;
        }
        wxWindow *parent = wdw->GetParent ();
        if (parent) {

            if (parent == m_ignoreWdw) {

                //std::cout << _T("parent:") << parent << std::endl;
                return true;
            }

            wxWindow *grandParent = wdw->GetGrandParent ();
            if (grandParent && grandParent == m_ignoreWdw) {

                //std::cout << _T("grandParent:") << grandParent << std::endl;
                return true;
            }
        }
    }

    return false;
}


void CREventCaptureManager::EmitPendingEvent ()
{
    if (m_pendingEvent != NULL) {

        m_pendingEvent->EmitCpp ();
        delete m_pendingEvent;
        m_pendingEvent = NULL;
    }
}


wxString CREventCaptureManager::GetDescForUnsupportedEvent (
        wxEvent &event) const
{
#define UNSUPPORTED_EVENT_DESC(eventtype) \
    if (et == eventtype) \
        return _T(#eventtype);

    int et = event.GetEventType ();

    UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LISTBOX_SELECTED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_CHECKLISTBOX_TOGGLED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_RADIOBUTTON_SELECTED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_SCROLLBAR_UPDATED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_VLBOX_SELECTED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_COMBOBOX_SELECTED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TOOL_RCLICKED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TOOL_ENTER)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_SPLITTER_DOUBLECLICKED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_SPLITTER_UNSPLIT)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_BEGIN_DRAG)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_BEGIN_RDRAG)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_BEGIN_LABEL_EDIT)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_END_LABEL_EDIT)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_DELETE_ITEM)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS)
 //   else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_GET_INFO)
 //   else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_SET_INFO)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_SELECTED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_DESELECTED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_KEY_DOWN)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_INSERT_ITEM)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_COL_CLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_MIDDLE_CLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_ACTIVATED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_CACHE_HINT)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_COL_RIGHT_CLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_COL_BEGIN_DRAG)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_COL_DRAGGING)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_COL_END_DRAG)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_FOCUSED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_BEGIN_DRAG)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_BEGIN_RDRAG)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_END_LABEL_EDIT)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_DELETE_ITEM)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_GET_INFO)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_SET_INFO)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_EXPANDED)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_EXPANDING)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_COLLAPSED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_COLLAPSING)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_SEL_CHANGED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_KEY_DOWN)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_ACTIVATED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_MIDDLE_CLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_END_DRAG)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TREE_STATE_IMAGE_CLICK)
/*  
    else UNSUPPORTED_EVENT_DESC(wxEVT_LEFT_DOWN)
    else UNSUPPORTED_EVENT_DESC(wxEVT_LEFT_UP)
    else UNSUPPORTED_EVENT_DESC(wxEVT_MIDDLE_DOWN)
    else UNSUPPORTED_EVENT_DESC(wxEVT_MIDDLE_UP)
    else UNSUPPORTED_EVENT_DESC(wxEVT_RIGHT_DOWN)
    else UNSUPPORTED_EVENT_DESC(wxEVT_RIGHT_UP)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_MOTION)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_ENTER_WINDOW)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_LEAVE_WINDOW)
    else UNSUPPORTED_EVENT_DESC(wxEVT_LEFT_DCLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_MIDDLE_DCLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_RIGHT_DCLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SET_FOCUS)
    else UNSUPPORTED_EVENT_DESC(wxEVT_KILL_FOCUS)
    else UNSUPPORTED_EVENT_DESC(wxEVT_CHILD_FOCUS)
    else UNSUPPORTED_EVENT_DESC(wxEVT_MOUSEWHEEL)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_LEFT_DOWN)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_LEFT_UP)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_MIDDLE_DOWN)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_MIDDLE_UP)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_RIGHT_DOWN)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_RIGHT_UP)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_MOTION)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_ENTER_WINDOW)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_LEAVE_WINDOW)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_LEFT_DCLICK)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_MIDDLE_DCLICK)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_NC_RIGHT_DCLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_CHAR)
    //else UNSUPPORTED_EVENT_DESC(wxEVT_CHAR_HOOK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_NAVIGATION_KEY)
    else UNSUPPORTED_EVENT_DESC(wxEVT_KEY_DOWN)
    else UNSUPPORTED_EVENT_DESC(wxEVT_KEY_UP)
*/
#if wxUSE_HOTKEY
    else UNSUPPORTED_EVENT_DESC(wxEVT_HOTKEY)
#endif
    // Seems to be never used at all:
    //else UNSUPPORTED_EVENT_DESC(wxEVT_SET_CURSOR)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLL_TOP)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLL_BOTTOM)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLL_LINEUP)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLL_LINEDOWN)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLL_PAGEUP)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLL_PAGEDOWN)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLL_THUMBTRACK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLL_THUMBRELEASE)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLL_CHANGED)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLLWIN_TOP)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLLWIN_BOTTOM)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLLWIN_LINEUP)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLLWIN_LINEDOWN)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLLWIN_PAGEUP)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLLWIN_PAGEDOWN)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLLWIN_THUMBTRACK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_SCROLLWIN_THUMBRELEASE)
/*  
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LEFT_CLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_LEFT_DCLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_RIGHT_CLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_RIGHT_DCLICK)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_SET_FOCUS)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_KILL_FOCUS)
*/
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_ENTER)
    else UNSUPPORTED_EVENT_DESC(wxEVT_HELP)
    else UNSUPPORTED_EVENT_DESC(wxEVT_DETAILED_HELP)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TEXT_ENTER)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TEXT_URL)
    else UNSUPPORTED_EVENT_DESC(wxEVT_COMMAND_TEXT_MAXLEN)       
    else
        return _T("");
}


wxString CREventCaptureManager::GetEventDesc (wxEvent &event) const
{
#define EVENT_DESC(eventtype) \
    if (et == eventtype) \
        desc = _T(#eventtype);

    int et = event.GetEventType ();
    wxString desc;

    EVENT_DESC(wxEVT_COMMAND_BUTTON_CLICKED)
    else EVENT_DESC(wxEVT_COMMAND_MENU_SELECTED)
    else EVENT_DESC(wxEVT_COMMAND_TEXT_UPDATED)
    else EVENT_DESC(wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED)
    else EVENT_DESC(wxEVT_COMMAND_CHOICE_SELECTED)
    else EVENT_DESC(wxEVT_COMMAND_RADIOBOX_SELECTED)
    else EVENT_DESC(wxEVT_COMMAND_CHECKBOX_CLICKED)
    else EVENT_DESC(wxEVT_COMMAND_SLIDER_UPDATED)
    else EVENT_DESC(wxEVT_COMMAND_SPINCTRL_UPDATED)
    else EVENT_DESC(wxEVT_COMMAND_TREE_SEL_CHANGING)
    else EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK)
    else EVENT_DESC(wxEVT_COMMAND_LISTBOX_SELECTED)
    else EVENT_DESC(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED)
    else EVENT_DESC(wxEVT_COMMAND_CHECKLISTBOX_TOGGLED)
    else EVENT_DESC(wxEVT_COMMAND_RADIOBUTTON_SELECTED)
    else EVENT_DESC(wxEVT_COMMAND_SCROLLBAR_UPDATED)
    else EVENT_DESC(wxEVT_COMMAND_VLBOX_SELECTED)
    else EVENT_DESC(wxEVT_COMMAND_COMBOBOX_SELECTED)
    else EVENT_DESC(wxEVT_COMMAND_TOOL_RCLICKED)
    else EVENT_DESC(wxEVT_COMMAND_TOOL_ENTER)
    else EVENT_DESC(wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED)
    else EVENT_DESC(wxEVT_COMMAND_SPLITTER_DOUBLECLICKED)
    else EVENT_DESC(wxEVT_COMMAND_SPLITTER_UNSPLIT)
    else EVENT_DESC(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED)
    else EVENT_DESC(wxEVT_COMMAND_LIST_BEGIN_DRAG)
    else EVENT_DESC(wxEVT_COMMAND_LIST_BEGIN_RDRAG)
    else EVENT_DESC(wxEVT_COMMAND_LIST_BEGIN_LABEL_EDIT)
    else EVENT_DESC(wxEVT_COMMAND_LIST_END_LABEL_EDIT)
    else EVENT_DESC(wxEVT_COMMAND_LIST_DELETE_ITEM)
    else EVENT_DESC(wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS)
//    else EVENT_DESC(wxEVT_COMMAND_LIST_GET_INFO)
//    else EVENT_DESC(wxEVT_COMMAND_LIST_SET_INFO)
    else EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_SELECTED)
    else EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_DESELECTED)
    else EVENT_DESC(wxEVT_COMMAND_LIST_KEY_DOWN)
    else EVENT_DESC(wxEVT_COMMAND_LIST_INSERT_ITEM)
    else EVENT_DESC(wxEVT_COMMAND_LIST_COL_CLICK)
    else EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK)
    else EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_MIDDLE_CLICK)
    else EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_ACTIVATED)
    else EVENT_DESC(wxEVT_COMMAND_LIST_CACHE_HINT)
    else EVENT_DESC(wxEVT_COMMAND_LIST_COL_RIGHT_CLICK)
    else EVENT_DESC(wxEVT_COMMAND_LIST_COL_BEGIN_DRAG)
    else EVENT_DESC(wxEVT_COMMAND_LIST_COL_DRAGGING)
    else EVENT_DESC(wxEVT_COMMAND_LIST_COL_END_DRAG)
    else EVENT_DESC(wxEVT_COMMAND_LIST_ITEM_FOCUSED)
    else EVENT_DESC(wxEVT_COMMAND_TREE_BEGIN_DRAG)
    else EVENT_DESC(wxEVT_COMMAND_TREE_BEGIN_RDRAG)
    else EVENT_DESC(wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT)
    else EVENT_DESC(wxEVT_COMMAND_TREE_END_LABEL_EDIT)
    //else EVENT_DESC(wxEVT_COMMAND_TREE_DELETE_ITEM)
    //else EVENT_DESC(wxEVT_COMMAND_TREE_GET_INFO)
    //else EVENT_DESC(wxEVT_COMMAND_TREE_SET_INFO)
    //else EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_EXPANDED)
    //else EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_EXPANDING)
    else EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_COLLAPSED)
    else EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_COLLAPSING)
    else EVENT_DESC(wxEVT_COMMAND_TREE_SEL_CHANGED)
    else EVENT_DESC(wxEVT_COMMAND_TREE_KEY_DOWN)
    else EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_ACTIVATED)
    else EVENT_DESC(wxEVT_COMMAND_TREE_ITEM_MIDDLE_CLICK)
    else EVENT_DESC(wxEVT_COMMAND_TREE_END_DRAG)
    else EVENT_DESC(wxEVT_COMMAND_TREE_STATE_IMAGE_CLICK)
/*  
    else EVENT_DESC(wxEVT_LEFT_DOWN)
    else EVENT_DESC(wxEVT_LEFT_UP)
    else EVENT_DESC(wxEVT_MIDDLE_DOWN)
    else EVENT_DESC(wxEVT_MIDDLE_UP)
    else EVENT_DESC(wxEVT_RIGHT_DOWN)
    else EVENT_DESC(wxEVT_RIGHT_UP)
    //else EVENT_DESC(wxEVT_MOTION)
    //else EVENT_DESC(wxEVT_ENTER_WINDOW)
    //else EVENT_DESC(wxEVT_LEAVE_WINDOW)
    else EVENT_DESC(wxEVT_LEFT_DCLICK)
    else EVENT_DESC(wxEVT_MIDDLE_DCLICK)
    else EVENT_DESC(wxEVT_RIGHT_DCLICK)
    else EVENT_DESC(wxEVT_SET_FOCUS)
    else EVENT_DESC(wxEVT_KILL_FOCUS)
    else EVENT_DESC(wxEVT_CHILD_FOCUS)
    else EVENT_DESC(wxEVT_MOUSEWHEEL)
    //else EVENT_DESC(wxEVT_NC_LEFT_DOWN)
    //else EVENT_DESC(wxEVT_NC_LEFT_UP)
    //else EVENT_DESC(wxEVT_NC_MIDDLE_DOWN)
    //else EVENT_DESC(wxEVT_NC_MIDDLE_UP)
    //else EVENT_DESC(wxEVT_NC_RIGHT_DOWN)
    //else EVENT_DESC(wxEVT_NC_RIGHT_UP)
    //else EVENT_DESC(wxEVT_NC_MOTION)
    //else EVENT_DESC(wxEVT_NC_ENTER_WINDOW)
    //else EVENT_DESC(wxEVT_NC_LEAVE_WINDOW)
    //else EVENT_DESC(wxEVT_NC_LEFT_DCLICK)
    //else EVENT_DESC(wxEVT_NC_MIDDLE_DCLICK)
    //else EVENT_DESC(wxEVT_NC_RIGHT_DCLICK)
    else EVENT_DESC(wxEVT_CHAR)
    //else EVENT_DESC(wxEVT_CHAR_HOOK)
    else EVENT_DESC(wxEVT_NAVIGATION_KEY)
    else EVENT_DESC(wxEVT_KEY_DOWN)
    else EVENT_DESC(wxEVT_KEY_UP)
*/
#if wxUSE_HOTKEY
    else EVENT_DESC(wxEVT_HOTKEY)
#endif
    // Seems to be never used at all:
    //else EVENT_DESC(wxEVT_SET_CURSOR)
    else EVENT_DESC(wxEVT_SCROLL_TOP)
    else EVENT_DESC(wxEVT_SCROLL_BOTTOM)
    else EVENT_DESC(wxEVT_SCROLL_LINEUP)
    else EVENT_DESC(wxEVT_SCROLL_LINEDOWN)
    else EVENT_DESC(wxEVT_SCROLL_PAGEUP)
    else EVENT_DESC(wxEVT_SCROLL_PAGEDOWN)
    else EVENT_DESC(wxEVT_SCROLL_THUMBTRACK)
    else EVENT_DESC(wxEVT_SCROLL_THUMBRELEASE)
    else EVENT_DESC(wxEVT_SCROLL_CHANGED)
    else EVENT_DESC(wxEVT_SCROLLWIN_TOP)
    else EVENT_DESC(wxEVT_SCROLLWIN_BOTTOM)
    else EVENT_DESC(wxEVT_SCROLLWIN_LINEUP)
    else EVENT_DESC(wxEVT_SCROLLWIN_LINEDOWN)
    else EVENT_DESC(wxEVT_SCROLLWIN_PAGEUP)
    else EVENT_DESC(wxEVT_SCROLLWIN_PAGEDOWN)
    else EVENT_DESC(wxEVT_SCROLLWIN_THUMBTRACK)
    else EVENT_DESC(wxEVT_SCROLLWIN_THUMBRELEASE)
/*  
    else EVENT_DESC(wxEVT_COMMAND_LEFT_CLICK)
    else EVENT_DESC(wxEVT_COMMAND_LEFT_DCLICK)
    else EVENT_DESC(wxEVT_COMMAND_RIGHT_CLICK)
    else EVENT_DESC(wxEVT_COMMAND_RIGHT_DCLICK)
    else EVENT_DESC(wxEVT_COMMAND_SET_FOCUS)
    else EVENT_DESC(wxEVT_COMMAND_KILL_FOCUS)
*/
    else EVENT_DESC(wxEVT_COMMAND_ENTER)
    else EVENT_DESC(wxEVT_HELP)
    else EVENT_DESC(wxEVT_DETAILED_HELP)
    else EVENT_DESC(wxEVT_COMMAND_TEXT_ENTER)
    else EVENT_DESC(wxEVT_COMMAND_TEXT_URL)
    else EVENT_DESC(wxEVT_COMMAND_TEXT_MAXLEN)       

#undef EVENT_DESC

    return desc;
}


wxString CREventCaptureManager::GetEventDetails (wxEvent& event) const
{
    wxString evtObjName, evtObjHierarchy;
    // Print name of event object - is this XRC string ID?
    wxObject *obj = event.GetEventObject ();
    if ((event.GetEventType () == wxEVT_COMMAND_MENU_SELECTED) ||
            (event.GetEventType () == wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED)) {

        wxWindow *wdw = wxDynamicCast (obj, wxWindow);
        if (wdw != NULL) {

            evtObjName = wdw->GetName ();

            //wxASSERT (event.GetId () == XRCID (evtObjName));

            wxWindow *parent = wdw->GetParent ();
            if (parent) {

                evtObjHierarchy += _T("-> ") + parent->GetName ();
            }
            parent = wdw->GetGrandParent ();
            if (parent) {

                evtObjHierarchy += _T(" -> ") + parent->GetName ();
            }

        } else {

            // Menus are different, they do not inherit from wxWindow:
            wxMenu *menu = wxDynamicCast (obj, wxMenu);
            if (menu != NULL) {

                evtObjName = menu->GetTitle ();
            }
        }

    } else if (obj != NULL) {

        wxWindow *wdw = wxDynamicCast (obj, wxWindow);
        if (wdw != NULL) {

            evtObjName = wdw->GetName ();

            // For command events this assertion is too strong, the event object
            // can also be a parent component!
            //wxASSERT (event.GetId () == XRCID (evtObjName));
            if (event.IsCommandEvent ()) {

                //wxWindow *child = wxWindow::FindWindowById (event.GetId (), wdw);
                wxWindow *child = wxWindow::FindWindowById (event.GetId ());
                wxASSERT ((event.GetId () == wxXmlResource::GetXRCID (evtObjName))
                        || (child != NULL));

            } else {

                wxASSERT (event.GetId () == wxXmlResource::GetXRCID (evtObjName));
            }

            wxWindow *parent = wdw->GetParent ();
            if (parent) {

                evtObjHierarchy += _T("-> ") + parent->GetName ();
            }
            parent = wdw->GetGrandParent ();
            if (parent) {

                evtObjHierarchy += _T(" -> ") + parent->GetName ();
            }
        } else {

            // Menus are different, they do not inherit from wxWindow:
            wxMenu *menu = wxDynamicCast (obj, wxMenu);
            if (menu != NULL) {

                evtObjName = menu->GetTitle ();
            }
        }
    }

    // Timestamp is mostly 0 and therefore irrelevant; if it is a command event
    // or not is not important:
    //wxString evtInfo = wxString::Format (_T("[%d]: id %d cmd %d - EvtObj '%s' %s"),
    wxString evtInfo = wxString::Format (_T("id %d, EvtObj '%s' %s"),
            //event.GetTimestamp (),
            event.GetId (),
            //event.IsCommandEvent (),
            evtObjName.c_str (),
            evtObjHierarchy.c_str ());

    return evtInfo;
}


void CREventCaptureManager::LogEventDetails (wxEvent& event,
        const wxString &prefix)
{
    // Was:
    //wxASSERT (m_log != NULL);
    if (m_log) {
    
        m_log->Log (prefix + _T(" ") + this->GetEventDetails (event) + _T("\n"));
    }
}

} // End namespace wxTst

