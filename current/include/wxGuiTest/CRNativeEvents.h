///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/NativeEvents/CRNativeEvents.h
// Author:      John Ralls
// Created:     2 Feb 2008
// Copyright:   (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id: CRCapturedEvent.h 69 2008-01-24 21:16:37Z john $
///////////////////////////////////////////////////////////////////////////////

#ifndef CRNATIVEEVENT_H
#define CRNATIVEEVENT_H

#ifdef __GNUG__
    #pragma interface "CRNativeEvents.h"
#endif

#include <wxGuiTest/Common.h>
#include <wx/defs.h>
#include <wx/event.h>
#include <map>

extern const wxEventType wxEVT_NOT_TRANSLATED;

namespace wxTst {

/// \enum CREventCat
/// \brief Mask values for setting event masks in platform event classes.
    enum CREventCat{
		Undefined			= 0x0,
		System 				= 0x1,	
		AppManipulation 	= 0x1 << 1,
		WindowManipulation 	= 0x1 << 2,
		MouseEvent			= 0x1 << 3,
		KeyEvent			= 0x1 << 4,
		HotKeyEvent			= 0x1 << 5,
		MenuEvent			= 0x1 << 6,
		MDIEvent			= 0x1 << 7,
		ClipboardEvent		= 0x1 << 8,
		Command				= 0x1 << 9,
		TextEvent			= 0x1 << 10

    };

    typedef unsigned int CREventMask;

/// \struct CREvent
/// \brief Correlate wxEventTypes with an event name and Event Category.
/// Used in platform event maps to relate the native event types to wxEvents
/// Note that with wx 2.9 event types are all dynamically assigned in 
/// common/events.cpp.

    struct CREvent {
		wxString m_name;
		wxEventType m_evt;
		CREventCat m_cat;

		CREvent() : m_name(_T("")), m_evt(0), m_cat(Undefined){}
		CREvent(const wxEventType, const wxString, const CREventCat);
    };

    typedef std::map<wxEventType, CREvent> CREventMap;

///
/// \class CRNativeEvent
/// \brief Abstract base class for native event data capture and synthesis
///

    class CRNativeEvent {
    public:
/// \fn CRNativeEvent()
/// \brief default constructor.
	CRNativeEvent();
/// 
/// \fn CRNativeEvent(CREvent);
/// \brief 	Constructor
	CRNativeEvent(CREvent);
/// \fn CRNativeEvent(wxEventType)
/// \brief Constructor from a wxEventType;
	CRNativeEvent(wxEventType);
/// \fn CRNativeEvent(const wxString& name)
/// \brief Constructor from an event name
/// \parameter name the name of the event used in the corresponding CREvent
	CRNativeEvent(const wxString&);
///  \fn virtual ~CRNativeEvent()
///  \brief Virtual destructor: No-op
///
	virtual ~CRNativeEvent() { }
/// \fn virtual wxString getEventString()
/// \brief get a string serialized with the information needed to recreate the event.
/// \return string containing event information
	virtual const wxString getEventString() const;
/// \fn virtual void* getNativeEvent()
/// \brief Return a void* to the native event, creating the native event if needed.
/// 
	virtual void* getNativeEvent() = 0;
/// \fn virtual wxEventType getEventType()
/// \brief return the Event Type of the corresponding wxEvent if there is one.
/// \return wxEventType
	virtual const wxEventType getEventType() { return m_wxevent.m_evt; } 
/// \fn static void setCREventMask(CREventMask mask)
/// \brief Set the static mask which determines (during construction) what 
/// events will be recorded, serialized, and emitted.
/// \param mask A bitmask composed by or-ing CRNativeEvent::EventCategory 
/// values.	
	static void setCREventMask(CREventMask mask) { s_eventMask = mask; }
/// \fn static const CREventMask getCREventMask()
/// \brief Return the CREventMask 
	static const CREventMask getCREventMask() { return s_eventMask; }

    protected:
	wxString m_eventString;
	static const wxString s_delim; //These may move to CRCarbonEvent
	static const wxString s_inDelim;
	static CREventMask s_eventMask;
	static CREventMap s_eventMap;
	CREvent m_wxevent;
	static void initEventMap();

    private:
	static inline void CRNativeEvent::pushEvent(const wxEventType, 
						    const wxString,
						    const CREventCat);
    };
}
#endif //CRNATIVEEVENT_H
