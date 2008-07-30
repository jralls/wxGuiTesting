///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/NativeEvents/CREvent.h
// Author:      John Ralls
// Created:     2 Feb 2008
// Copyright:   (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id: CRCapturedEvent.h 69 2008-01-24 21:16:37Z john $
///////////////////////////////////////////////////////////////////////////////

#ifndef CREVENT_H
#define CREVENT_H

#ifdef __GNUG__
    #pragma interface "CREvent.h"
#endif

#include <wxGuiTest/Common.h>
#include <wx/defs.h>
#include <wx/event.h>
#include <map>

extern const wxEventType wxEVT_NOT_TRANSLATED;

namespace wxTst {

// Forward decls for class CREvent
	class CREventImpl;
	class NativeEvent;
/**
 * Mask values for setting event masks in CRCaptureManager.
 */
    enum CREventCat{
		KeyEvents			= 0x1,		//Keyboard keys: up, down
		MouseButtonEvents	= 0x1 << 1, //Mouse buttons
		MouseWheelEvents	= 0x1 << 2, //Mouse wheel (translated to buttons in X
		MouseMotionEvents	= 0x1 << 3, //Motion
		HotKeyEvents		= 0x1 << 4, //AKA Accelerators, shortcut keys: Emit menu
		MenuEvents			= 0x1 << 5, //Menu selections
		CommandEvents		= 0x1 << 6, //Non-menu command events
		TextEvents			= 0x1 << 7, //Characters resulting from keyboard events
		MDIEvents			= 0x1 << 8, //Multi-Document Interface
		WindowEvents	 	= 0x1 << 9, //Focus, Enter/Leave, Expose, Paint
		ClipboardEvents		= 0x1 << 10,//Cut, copy, and paste
		SystemEvents		= 0x1 << 11,//Timers, interupts, etc.	
		AppEvents		 	= 0x1 << 12,//Kill, Quit
		UserEvents			= 0x1 << 13,//AUT-specific 
		UndefinedEvents		= 0x1 << 15,
		AllEvents			= 0xffff

    };

/**
 * @class CREvent
 *
*   Encapsulate event details needed to create as needed wxEvents or Native
*   Events. This is a reference-counted pointer class; the real object is
*   CREventImpl and its derived classes.
*/
    class CREvent {
	public:
		CREvent();
		CREvent(const wxEventType);
		CREvent(const wxEvent&);
		CREvent(const wxString&);
		CREvent(const CREvent&);
		CREvent(void*, wxObject*);
		~CREvent();
		CREvent& operator=(const CREvent&);
/**
 * Allow transparent test for validity
 * 
 */

		virtual operator bool() { return m_impl != NULL; }

/** 
 * 
 * Serialize the event into a string sutiable for machine parsing
 * 
 */
		wxString serialize();
/** 
 * 
 * Serialize the event into a string suitable for a human to read, for
 * example in a log file.
 * 
 */
		wxString report();
/** 
 * Post a wxEvent.
 *
 * @param window wxWindow target of the event.
 *
 * @return success (true) or failure (false)
*/
		virtual bool postWxEvent();
/** 
 * Post a native event on the current event queue.
 * 
 * @param window The native window target of the event.
 *
 * @return success (true) or failure (false)
 */
		virtual bool postNativeEvent();

		bool check(uint16_t catmask);
	private:
		CREventImpl* m_impl;
		unsigned short* m_refcount;
    };

}; //namespace wxTst

#endif //CREVENT_H
