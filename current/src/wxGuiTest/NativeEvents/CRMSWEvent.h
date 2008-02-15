///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/NativeEvents/CRMSWEvent.h
// Author:      John Ralls
// Created:     2008
// Copyright:   (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id: CREventCaptureManager.cpp 77 2008-02-07 00:32:52Z jralls $
///////////////////////////////////////////////////////////////////////////////
#ifndef __CRMSWEVENT_H__
#define __CRMSWEVENT_H__

#ifdef __GNUG__
    #pragma interface "CRMSWEvent.h"
#endif

#include "Windows.h"
#include <wxGuiTest/CRNativeEvents.h>
#include <map>

namespace wxTst {

    typedef std::map<UINT, CREvent> Events;
    

/// \class CRMSWEvent
/// \brief Encapsulates Win32 native event interpretation, recording, and emission.

    class CRMSWEvent : public CRNativeEvent {
    public:
/// \fn CRMSWEvent(MSG msg)
/// \brief Constructor from MSW message
	CRMSWEvent(MSG msg);
/// \fn CRMSWEvent(wxEvent evt)
/// \brief Constructor from wxEvent
	CRMSWEvent(const wxEvent& evt);
/// \fn CRMSWEvent(const wxString& evt)
/// \brief Constructor from cross-platform native event serialization
	CRMSWEvent(const wxString& evt);
/// \fn wxString serialize()
/// \brief Serialize the MSG data into a portable string version for later use.
	wxString serialize();
/// \fn void* getNativeEvent()
/// \brief return a pointer to the MSG. Note that the receiver must either
/// use it before this is destroyed or make a copy.
	void* getNativeEvent();


    private:
	CRMSWEvent(); 
	static void initEvents();
	static CREvent getCREvent(MSG);
	static Events s_events;
	MSG m_event;

	static inline void pushEvent(UINT msg, wxEventType wxEvent);
    }; //class CRMSWEvent

}//namespace wxTst

#endif //__CRMSWEVENT_H__
