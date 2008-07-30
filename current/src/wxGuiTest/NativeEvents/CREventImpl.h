///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/NativeEvents/CREventImpl.h
// Author:      John Ralls
// Created:     2 Feb 2008
// Copyright:   (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef CREVENTIMPL_H
#define CREVENTIMPL_H

#ifdef __GNUG__
    #pragma interface "CREventImpl.h"
#endif

#include <wxGuiTest/Common.h>
#include <wx/defs.h>
#include <wx/event.h>
#include <map>
#include <wxGuiTest/CREvent.h>

extern const wxEventType wxEVT_NOT_TRANSLATED;

namespace wxTst {
//Forward decls for CREventImpl
	struct CREventMap;
	typedef std::map<wxEventType, CREventMap> CRCatMap;

	enum ModType { ctrl 	= 0x1,
				   shift 	= 0x1 << 1,
				   alt 		= 0x1 << 2,
				   meta 	= 0x1 << 3,
				   left 	= 0x1 << 4,
				   middle 	= 0x1 << 5,
				   right 	= 0x1 << 6,
				   aux1 	= 0x1 << 7, //aux mouse buttons supported only 
				   aux2 	= 0x1 << 8};//in wxWidgets 2.9.0 and later

	typedef unsigned short ModMask;
/**
 * @class IntVal
 *
 * Encapsulates a long (or an int) for use as a member in an CREventImpl
 * subclass
 */
	class IntVal {
	public:
		IntVal() { }
		IntVal(long v, const wxString& f) : m_val(v), m_flag(f) {}
		IntVal(const wxString& evtStr, const wxString& f);
		wxString serialize();
		inline long getVal() { return m_val; }
		inline bool operator<(const long& val) { return m_val < val; }
		inline bool operator>(const long& val) { return m_val > val; }
		inline bool operator==(const long& val) { return m_val == val; }
	private:
		long m_val;
		wxString m_flag;
	};

/**
 * @class IntPair
 *
 * Encapsulates a pair of integers, which generalizes wxPoint, wxSize, and
 * wxPosition, for use as CREventImpl subclass members.
 */

	class IntPair {
	public:
		IntPair() { }
		IntPair(long x, long y, const wxString& f) : 
			m_x(x), m_y(y), m_flag(f) {}
		IntPair(const wxPoint& p, const wxString& f) : 
			m_x(p.x), m_y(p.y), m_flag(f) {}
		IntPair(const wxSize& p, const wxString& f) : 
			m_x(p.GetWidth()), m_y(p.GetHeight()), m_flag(f) {}
#if wxCHECK_VERSION(2,9,0)
		IntPair(const wxPosition& p, const wxString& f) : 
			m_x(p.GetRow()), m_y(p.GetColumn()), m_flag(f) {}
#endif
		IntPair(const wxString& evtStr, const wxString& flag);

		inline long getX() { return m_x; }
		inline long getY() { return m_y; }
		wxString serialize();

	private:
		long m_x;
		long m_y;
		wxString m_flag;

		static const wxString xflag;
		static const wxString yflag;
		static const wxString comma;
	};

/**
 * @class WinQual
 *
 * Encapsulates the toplevel->parent->widget hierarchy for event objects so
 * that it can be serialized and recovered from text.
 */


	class WinQual {
	public:
		WinQual() {}
		WinQual(wxWindow* win);
		WinQual(const wxString& winstr);
		wxWindow* getWindow() { return m_window; }
		wxString serialize();
	private:
		wxWindow* m_window;
		wxWindow* m_parent;
		wxWindow* m_toplvl;

		static const wxString objflag;
		static const wxString objsep;
	};

/**
* @class CREventImpl
*
* Implementation class for CREvent and base class for specific event
* classes. wxWidgets has a huge number of classes derived from wxEvent, and
* they serve a variety of purposes. Like Microsoft Windows, wxWidgets
* confounds what other platforms distinguish as events (low-level
* interactions from the user, like mouse button clicks) and signals
* (higher-level indications from a widget that it is preparing to do
* something or has already done it). What's more, there are also events
* which have nothing to do with the GUI (e.g., wxProcessEvent,
* wxSocketEvent, and wxDialupEvent).
*
* Of these myriad events, we're really interested in two kinds:
* wxCommandEvents and its subclasses, which are used by wxWidgets to tell
* itself and the application that something has (or is about to) happen, and
* native platform interaction events, which trigger behaviors in wxWidgets,
* in many cases leading to wxCommandEvents.
*/
    class CREventImpl {
		friend class CREvent;
	public:
		CREventImpl();

/**
*  @param type a wxEvcntType; creates a CREvent with no object
*/
		CREventImpl(const wxEventType type);
/**
*  @param evt a wxEvent&
*/
		CREventImpl(const wxEvent& evt);
/** 
 * @param type A wxEventType
 * @param win  The window which will receive the event
 * @param name A name to use for the event; useful with wxEVT_NOT_TRANSLATED
 */
		CREventImpl(const wxEventType type, wxWindow* win, bool native = false,
					const wxString& name = _T(""));

/**
* @param evtString a string emitted by serialize()
*/
		CREventImpl(const wxString& evtString);
		virtual ~CREventImpl() {} //Just to make it virtual

/**
*  @return a parameterized string for storage of the event
*/
		virtual wxString serialize();
/**
*  @return a human-readable string for inserting into logs
*/
		virtual wxString report();
/** 
 * Post a wxEvent constructed from this to the current event queue (using
 * wxPostEvent).
 *
 * @return true if successful, false otherwise.
 */
		virtual bool postWxEvent();
/** 
 * Post a native event constructed from this on the current event queue.
 * 
 * @return true if successful, false otherwise
 */
		virtual bool postNativeEvent();
/** 
 * Checks whether an event type is in the catmask 
 * 
 * @param type The wxEventType to check 
 * @param catmask A uint16_t bitmask composed of CREventCats
 * 
 * @return True if the category stored for type is in the catmask
 */
		bool check(uint16_t catmask);

	protected:
/** 
 * Adds an event type to the static category map so that the factory routine
 * in CREvent knows what kind of event object to create.
 * 
 * @param type wxEventType; the key for retrieving records
 * @param name Human-readable (and serializable) name of the event type
 * @param wxclass wxEvent subclass responsible for the event type
 * @param crclass CREventImpl subclass responsible for the event type
 * @param cat Category for masking events during capture
 */
		static void registerEvent(const wxEventType type, 
								  const wxString& name,
								  const wxString& wxclass, 
								  const wxString& crclass, 
								  const CREventCat cat);

		static const wxString modFlag; 
		static const wxString nativeFlag;
		wxEventType m_type;
		WinQual m_win;
		wxString m_name;
		bool m_isNative;

	private:
		static CRCatMap s_catMap;
		static void initCatMap();

/**
*  Finds the CREvent subclass appropriate for the wxEventType
*
* @param wxEventType of the event class
*
* @return wxString name of the CREventImpl class
*/
		static wxString getClass(const wxEventType);
/**
* @fn wxString getClass(const wxString&)
*
* @brief Finds the CREvent subclass appropriate for the wxEventType
*
* @param wxString name of the event type
*
* @return wxString name of the CREventImpl class
*/
		static wxString getClass(const wxString&);
/** 
 * @fn static wxEventType extractType(const wxEventType& evtString);
 *
 * @brief Extract the type part of a serialized event string.
 * 
 * @param evtString 
 * 
 * @return wxEventType
 */		
		static wxEventType extractType(const wxString& evtString);

/** 
 * Find the CREventMap having the given wxEventType name.
 * 
 * @param evtName the event type name 
 * 
 * @return a CREventMap; The Untranslated entry is returned if the name
 * isn't found.
 */
		static CREventMap findMapByName(const wxString& evtName);


		static const wxString typeflag;
		static const wxString nameflag;
    };
/**
 * @class CRCommandEventImpl
 *
 * CREventImpl subclass for wxCommandEvents. Note that wxCommandEvents are
 * by-and-large not translatable to native events.
 * 
 */

	class CRCommandEventImpl : public CREventImpl {
	public:
		CRCommandEventImpl();
		CRCommandEventImpl(wxEventType type);
		CRCommandEventImpl(const wxCommandEvent& evt);
		CRCommandEventImpl(const wxEventType type, wxWindow* win,
						   const wxString& command, int int1, long int2);
		CRCommandEventImpl(const wxString& eventStr);
		virtual wxString serialize();
		virtual wxString report();
		virtual bool postWxEvent();
		virtual bool postNativeEvent();
	private:
		wxString m_cmdString;
		IntVal m_cmdInt;
		IntVal m_cmdXLong;

		static const wxString cmdStrFlag;
		static const wxString cmdIntFlag;
		static const wxString cmdXLFlag;
	};

/**
 * @class CRMouseEventImpl
 *
 * CREventImpl subclass for mouse events. We must be careful about emitting
 * these as wxEvents, because most widgets handle only native mouse events
 * and can't handle them coming from wx.
 */

	class CRMouseEventImpl : public CREventImpl {
	public:

		CRMouseEventImpl();
		CRMouseEventImpl(wxEventType type);
		CRMouseEventImpl(const wxMouseEvent& evt);
		CRMouseEventImpl(const wxEventType type, wxWindow* win,
						 ModMask mod, int clickcount, wxPoint coord,
						 bool isNative, int delta = 0, int lines = 0 );
		CRMouseEventImpl(const wxString& eventStr);
		virtual wxString serialize();
		virtual wxString report();
		virtual bool postWxEvent();
		virtual bool postNativeEvent();
		bool isNative() { return m_isNative; }
	private:
		ModMask m_buttonMask;
		IntVal m_clickCount;
		IntPair m_coord;
		IntVal m_wheelDelta;
		IntVal m_wheelLines;

		static const wxString clickFlag;
		static const wxString coordFlag;
		static const wxString deltaFlag;
		static const wxString linesFlag;

	};

/**
 * @class CRKeyEventImpl
 * 
 * CREventImpl subclass for key(board) events
 */

	class CRKeyEventImpl : public CREventImpl {
	public:
		CRKeyEventImpl();
		CRKeyEventImpl(wxEventType type);
		CRKeyEventImpl(const wxKeyEvent& evt);
		CRKeyEventImpl(const wxEventType type, wxWindow* win,
					   ModMask mod, long keycode, bool isNative);
		CRKeyEventImpl(const wxString& eventStr);
		virtual wxString serialize();
		virtual wxString report();
		virtual bool postWxEvent();
		virtual bool postNativeEvent();
		bool isNative() { return m_isNative; }
	private:
		ModMask m_modkey;
		IntVal m_keycode;

		ModMask fromWx(int);


		static const wxString keyFlag;
	};



}; //namespace wxTst

#endif //CREVENTIMPL_H
