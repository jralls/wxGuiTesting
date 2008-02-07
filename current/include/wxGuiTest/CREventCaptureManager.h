///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CREventCaptureManager.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef CREVENTCAPTUREMANAGER_H
#define CREVENTCAPTUREMANAGER_H

#ifdef __GNUG__
    #pragma interface "CREventCaptureManager.h"
#endif

#include <wxGuiTest/Common.h>

#include <list>

#include <wxGuiTest/CREventFilterInterface.h>

namespace wxTst {

class CRLogInterface;
class CRCapturedEvent;


/*! \class CREventCaptureManager
    \brief Manages the event filtering for C&R capturing (Singleton pattern).
*/
class CREventCaptureManager : public CREventFilterInterface
{
public:
    /*! \fn static CREventCaptureManager * GetInstance ()
        \brief Get single private instance (Singleton pattern).

        \return single private instance
    */
    static CREventCaptureManager * GetInstance ();


    /*! \fn static void Destroy ()
        \brief Threadsafe destruction of static singleton instance.
    */
    static void Destroy ();


    /*! \fn virtual void IgnoreWindow (wxWindow *wdw)
        \brief Events from/on dialog used in capturing for user interaction
        must be ignored.

        \param wdw capturing dialog to ignore events from
    */
    virtual void IgnoreWindow (wxWindow *wdw);

    
    /*! \fn virtual void On ()
        \brief Switch on event capturing (called by CRCaptureControl class).
    */
    virtual void On ();


    /*! \fn virtual void Off ()
        \brief Switch off event capturing (called by CRCaptureControl class).
    */
    virtual void Off ();

    
    /*! \fn virtual bool IsOn () const
        \brief Get status of event capturing switch.

        \return true, if event capturing is switched on
    */
    virtual bool IsOn () const;


    /*! \var virtual void SetLogger (CRLogInterface *log)
        \brief Set logging target.

        \param log logging target
    */    
    virtual void SetLogger (CRLogInterface *log);


    // Implement CREventFilterInterface:

    /*! \fn virtual void FilterEvent (wxEvent &event)
        \brief Filter all events in capturing mode.

        \param event event to process
    */
    virtual void FilterEvent (wxEvent &event);
    
    /*! \fn virtual void EmitPendingEvent ()
        \brief Emit pending event, if existing.
    */
    virtual void EmitPendingEvent ();

/*! \fn virtual void LogNativeEvent(const wxString& eventString)
    \brief Log a native event to the event log
    \param eventString the serialization string from the NativeEvent class
*/
    virtual void LogNativeEvent(const wxString& eventString);

protected:
    /*! \fn CREventCaptureManager ()
        \brief Constructor
    */
    CREventCaptureManager ();


    /*! \fn virtual ~CREventCaptureManager ()
        \brief Destructor
    */
    virtual ~CREventCaptureManager ();


    /*! \fn virtual bool CanIgnore (wxEvent &event)
        \brief Returns if given event must be ignored.

        That is, the event stems from the capturing dialog itself.

        \param event event to check for being ignored
    */
    virtual bool CanIgnore (wxEvent &event);


    /*! \fn virtual wxString GetDescForUnsupportedEvent (wxEvent &event) const
        \brief Returns descriptive name for given event, if unsupported.

        \param event event to get descriptive name for
        \return descriptive name for given event, if unsupported; or empty
            string otherwise
    */
    virtual wxString GetDescForUnsupportedEvent (wxEvent &event) const;

    
    /*! \fn virtual wxString GetEventDesc (wxEvent &event) const
        \brief Returns descriptive name for given event.

        \param event event to get descriptive name for
        \return descriptive name for given event
    */
    virtual wxString GetEventDesc (wxEvent &event) const;


    /*! \fn virtual wxString GetEventDetails (wxEvent& event) const
        \brief Get descriptive string with event details.

        \param event event to get descriptive name for
        \return descriptive string with event details
    */
    virtual wxString GetEventDetails (wxEvent& event) const;


    /*! \fn virtual void LogEventDetails (wxEvent& event, const wxString &prefix);
        \brief Log event details (only called for unsupported event).

        \param event event to log details for
        \param prefix logging output prefix
    */
    virtual void LogEventDetails (wxEvent& event, const wxString &prefix);


private:
    static CREventCaptureManager *ms_instance;

    wxWindow *m_ignoreWdw;

    bool m_isOn;
    wxEvent *m_event;

    CRLogInterface *m_log;
    std::ofstream *m_logStream;

    //typedef std::list< CRCapturedEvent * > EventList;
    //EventList m_eventList;

    CRCapturedEvent *m_pendingEvent;

private:
    // No copy and assignment constructor:
    CREventCaptureManager (const CREventCaptureManager &rhs);
    CREventCaptureManager & operator= (const CREventCaptureManager &rhs);
};

} // End namespace wxTst

#endif // CREVENTCAPTUREMANAGER_H

