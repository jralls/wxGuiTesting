///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/GuiTestProvokedWarningRegistry.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef WXGUITESTPROVOKEDWARNINGREGISTRY_H
#define WXGUITESTPROVOKEDWARNINGREGISTRY_H

#ifdef __GNUG__
    #pragma interface "GuiTestProvokedWarningRegistry.h"
#endif

#include <wxGuiTest/Common.h>

#include <map>

#include <wxGuiTest/GuiTestProvokedWarning.h>

namespace wxTst {


/*! \class WxGuiTestProvokedWarningRegistry
    \brief Manage registered provoked warnings allowing the detection of
    unexpected (real) test case failures.

    (Using Singleton pattern.)
*/
class WxGuiTestProvokedWarningRegistry
{
public:
    /*! \fn static WxGuiTestProvokedWarningRegistry & GetInstance ()
        \brief Get single private instance (Singleton pattern).

        \return single private registry instance
    */
    static WxGuiTestProvokedWarningRegistry & GetInstance ();


    /*! \fn static void Destroy ()
        \brief Threadsafe destruction of static singleton instance.
    */
    static void Destroy ();


    /*! \fn virtual void RegisterWarning (const WxGuiTestProvokedWarning &warning)
        \brief Register provoked/expected warning.

        \param warning provoked/expected warning to register
    */
    virtual void RegisterWarning (const WxGuiTestProvokedWarning &warning);


    /*! \fn virtual void UnregisterWarning (const WxGuiTestProvokedWarning &warning)
        \brief Unregister and remove provoked/expected warning from container.

        \param warning provoked/expected warning to unregister
    */
    virtual void UnregisterWarning (const WxGuiTestProvokedWarning &warning);


    /*! \fn virtual bool IsRegisteredAndInTime (const WxGuiTestProvokedWarning &warning) const
        \brief Check if provoked/expected warning is registered and time out
        interval has not exceeded.

        \param warning provoked/expected warning to check for registration
        \return true, if warning is registered and in time
    */
    virtual bool IsRegisteredAndInTime (const WxGuiTestProvokedWarning &warning) const;

    
    /*! \fn virtual bool WasDetected (const WxGuiTestProvokedWarning &warning) const
        \brief Check if this provoked/expected warning was detected.

        \param warning provoked/expected warning to check for detection
        \return true, if warning was detected within specified time out interval
    */
    virtual bool WasDetected (const WxGuiTestProvokedWarning &warning) const;


    /*! \fn virtual void SetWarningAsDetected (const WxGuiTestProvokedWarning &warning)
        \brief Set provoked/expected warning to has been detected.

        \param warning detected provoked/expected warning
    */
    virtual void SetWarningAsDetected (const WxGuiTestProvokedWarning &warning);


    /*! \fn virtual const WxGuiTestProvokedWarning* FindRegisteredWarning (const wxString &caption, const wxString &message = _T("")) const
        \brief Find first registerd warning fitting the specified caption and message.

        \param caption caption of provoked/expected warnings to find
        \param message message of provoked/expected warnings to find; leave empty if you don't care what about matching the message.
        \return corresponding registered warning if found, or NULL if there is
            no appropriate one
    */
    virtual const WxGuiTestProvokedWarning* FindRegisteredWarning (
	const wxString &caption, const wxString &message = _T("")) const;

protected:
    /*! \fn WxGuiTestProvokedWarningRegistry ()
        \brief Constructor
    */
    WxGuiTestProvokedWarningRegistry ();


    /*! \fn virtual ~WxGuiTestProvokedWarningRegistry ()
        \brief Destructor
    */
    virtual ~WxGuiTestProvokedWarningRegistry ();

private:
    static WxGuiTestProvokedWarningRegistry *ms_instance;
    // Key is provoked/expected warning, value if it was detected:
    typedef std::map< const WxGuiTestProvokedWarning *, bool > ProvokedWarningMap;
    ProvokedWarningMap warnings;

private:
    // No copy and assignment constructor:
    WxGuiTestProvokedWarningRegistry (const WxGuiTestProvokedWarningRegistry &rhs);
    WxGuiTestProvokedWarningRegistry & operator= (const WxGuiTestProvokedWarningRegistry &rhs);
};

} // End namespace wxTst

#endif // WXGUITESTPROVOKEDWARNINGREGISTRY_H

