///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/ProvokedWarningRegistry.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef PROVOKEDWARNINGREGISTRY_H
#define PROVOKEDWARNINGREGISTRY_H

#ifdef __GNUG__
    #pragma interface "ProvokedWarningRegistry.h"
#endif

#include <wxGuiTest/Common.h>

#include <map>

#include <wxGuiTest/ProvokedWarning.h>

namespace wxTst {


/*! \class ProvokedWarningRegistry
    \brief Manage registered provoked warnings allowing the detection of
    unexpected (real) test case failures.

    (Using Singleton pattern.)
*/
class ProvokedWarningRegistry
{
public:
    /*! \fn static ProvokedWarningRegistry & GetInstance ()
        \brief Get single private instance (Singleton pattern).

        \return single private registry instance
    */
    static ProvokedWarningRegistry & GetInstance ();


    /*! \fn static void Destroy ()
        \brief Threadsafe destruction of static singleton instance.
    */
    static void Destroy ();


    /*! \fn virtual void RegisterWarning (const ProvokedWarning &warning)
        \brief Register provoked/expected warning.

        \param warning provoked/expected warning to register
    */
    virtual void RegisterWarning (const ProvokedWarning &warning);


    /*! \fn virtual void UnregisterWarning (const ProvokedWarning &warning)
        \brief Unregister and remove provoked/expected warning from container.

        \param warning provoked/expected warning to unregister
    */
    virtual void UnregisterWarning (const ProvokedWarning &warning);


    /*! \fn virtual bool IsRegisteredAndInTime (const ProvokedWarning &warning) const
        \brief Check if provoked/expected warning is registered and time out
        interval has not exceeded.

        \param warning provoked/expected warning to check for registration
        \return true, if warning is registered and in time
    */
    virtual bool IsRegisteredAndInTime (const ProvokedWarning &warning) const;

    
    /*! \fn virtual bool WasDetected (const ProvokedWarning &warning) const
        \brief Check if this provoked/expected warning was detected.

        \param warning provoked/expected warning to check for detection
        \return true, if warning was detected within specified time out interval
    */
    virtual bool WasDetected (const ProvokedWarning &warning) const;


    /*! \fn virtual void SetWarningAsDetected (const ProvokedWarning &warning)
        \brief Set provoked/expected warning to has been detected.

        \param warning detected provoked/expected warning
    */
    virtual void SetWarningAsDetected (const ProvokedWarning &warning);


    /*! \fn virtual const ProvokedWarning* FindRegisteredWarning (const wxString &caption, const wxString &message = _T("")) const
        \brief Find first registerd warning fitting the specified caption and message.

        \param caption caption of provoked/expected warnings to find
        \param message message of provoked/expected warnings to find; leave empty if you don't care what about matching the message.
        \return corresponding registered warning if found, or NULL if there is
            no appropriate one
    */
    virtual const ProvokedWarning* FindRegisteredWarning (
	const wxString &caption, const wxString &message = _T("")) const;

protected:
    /*! \fn ProvokedWarningRegistry ()
        \brief Constructor
    */
    ProvokedWarningRegistry ();


    /*! \fn virtual ~ProvokedWarningRegistry ()
        \brief Destructor
    */
    virtual ~ProvokedWarningRegistry ();

private:
    static ProvokedWarningRegistry *ms_instance;
    // Key is provoked/expected warning, value if it was detected:
    typedef std::map< const ProvokedWarning *, bool > ProvokedWarningMap;
    ProvokedWarningMap warnings;

private:
    // No copy and assignment constructor:
    ProvokedWarningRegistry (const ProvokedWarningRegistry &rhs);
    ProvokedWarningRegistry & operator= (const ProvokedWarningRegistry &rhs);
};

} // End namespace wxTst

#endif // PROVOKEDWARNINGREGISTRY_H

