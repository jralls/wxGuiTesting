///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/NativeEvents/CREvent.cpp
// Author:      John Ralls
// Created:     2008
// Copyright:   (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CREvent.h"
#endif

#include <wxGuiTest/CREvent.h>
#include "CREventImpl.h"

DEFINE_EVENT_TYPE(wxEVT_NOT_TRANSLATED);


using namespace wxTst;

CREvent::CREvent() : 
	m_impl(new CREventImpl), m_refcount(new unsigned short(1)) {}

CREvent::CREvent(const wxEventType type) : 
	m_impl(NULL), m_refcount(new unsigned short(1)) {
	wxString evtClass = CREventImpl::getClass(type);
	if (evtClass == _T("CRCommandEventImpl"))
		m_impl = new CRCommandEventImpl(type);
	else if (evtClass == _T("CRMouseEventImpl"))
		m_impl = new CRMouseEventImpl(type);
	else if (evtClass == _T("CRKeyEventImpl"))
		m_impl = new CRKeyEventImpl(type);
	else
		m_impl = new CREventImpl(type);
}

CREvent::CREvent(const wxEvent& evt) : 
	m_impl(NULL), m_refcount(new unsigned short(1)) {
	wxString evtClass = CREventImpl::getClass(evt.GetEventType());
	if (evtClass == _T("CRCommandEventImpl")) {
		try {
			m_impl = 
				new CRCommandEventImpl(dynamic_cast<const wxCommandEvent&>(evt));
		}
		catch(std::bad_cast& e) {
			wxLogDebug(_T("Failed to cast event type %s to wxCommandEvent"),
						evt.GetClassInfo()->GetClassName());
			m_impl = new CREventImpl(evt);
		}
	}
	else if (evtClass == _T("CRMouseEventImpl")) {
		try {
			m_impl = new CRMouseEventImpl(dynamic_cast<const wxMouseEvent&>(evt));
		}
		catch(std::bad_cast& e) {
			wxLogDebug(_T("Failed to cast event type %s to wxMouseEvent"),
						evt.GetClassInfo()->GetClassName());
			m_impl = new CREventImpl(evt);
		}
	}
	else if (evtClass == _T("CRKeyEventImpl")) {
		try {
			m_impl = new CRKeyEventImpl(dynamic_cast<const wxKeyEvent&>(evt));
		}
		catch(std::bad_cast& e) {
			wxLogDebug(_T("Failed to cast event type %s to wxKeyEvent"),
						evt.GetClassInfo()->GetClassName());
			m_impl = new CREventImpl(evt);
		}
	}
	else
		m_impl = new CREventImpl(evt);
}

CREvent::CREvent(const wxString& evtString) : 
	m_impl(NULL), m_refcount(new unsigned short(1)) {
	wxEventType type = CREventImpl::extractType(evtString);
	wxString evtClass = CREventImpl::getClass(type);
	if (evtClass == _T("CRCommandEventImpl"))
		m_impl = new CRCommandEventImpl(evtString);
	else if (evtClass == _T("CRMouseEventImpl"))
		m_impl = new CRMouseEventImpl(evtString);
	else if (evtClass == _T("CRKeyEventImpl"))
		m_impl = new CRKeyEventImpl(evtString);
	else
		m_impl = new CREventImpl(evtString);
}

CREvent::CREvent(const CREvent& evt) : 
	m_impl(evt.m_impl), m_refcount(evt.m_refcount) {
	++(*m_refcount);
}

CREvent::~CREvent() {
	--(*m_refcount);
	if (*m_refcount == 0) {
		delete m_impl;
		delete m_refcount;
	}
}

CREvent&
CREvent::operator=(const CREvent& evt) {
	--(*m_refcount);
	if (*m_refcount == 0) {
		delete m_impl;
		delete m_refcount;
	}
	m_refcount = evt.m_refcount;
	++(*m_refcount);
	m_impl = evt.m_impl;
	return *this;
}

wxString
CREvent::serialize() { return m_impl->serialize(); }

wxString 
CREvent::report() { return m_impl->report(); }

bool
CREvent::postWxEvent() { return m_impl->postWxEvent(); }

bool
CREvent::postNativeEvent() { return m_impl->postNativeEvent(); }

bool 
CREvent::check(uint16_t catmask) { return m_impl->check(catmask); }
