///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/ProvokedWarningRegistry.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "ProvokedWarningRegistry.h"
#endif

#include <wxGuiTest/ProvokedWarningRegistry.h>

using namespace wxTst;


// Init single instance:
ProvokedWarningRegistry *ProvokedWarningRegistry::ms_instance = NULL;


ProvokedWarningRegistry::ProvokedWarningRegistry ()
{
    // Nothing to do
}


ProvokedWarningRegistry::~ProvokedWarningRegistry ()
{
    ProvokedWarningMap::iterator it = warnings.begin ();
    while (it != warnings.end ()) {

        this->UnregisterWarning (*((*it++).first));
    }
    warnings.clear ();
}


ProvokedWarningRegistry & ProvokedWarningRegistry::GetInstance ()
{
    if (ms_instance == NULL) {

        ms_instance = new ProvokedWarningRegistry ();
    }
    return *ms_instance;
}


void ProvokedWarningRegistry::Destroy ()
{
    if (ms_instance != NULL) {

        delete ms_instance;
        ms_instance = NULL;
    }
}


void ProvokedWarningRegistry::RegisterWarning (
        const ProvokedWarning &warning)
{
    wxASSERT (warnings.end () == warnings.find (&warning));
    warnings.insert (std::make_pair (&warning, false));
}


void ProvokedWarningRegistry::UnregisterWarning (
        const ProvokedWarning &warning)
{
    wxASSERT (warnings.end () != warnings.find (&warning));
    warnings.erase (&warning);
}


bool ProvokedWarningRegistry::IsRegisteredAndInTime (
        const ProvokedWarning& warning) const
{
    ProvokedWarningMap::const_iterator it;
    it = warnings.find (&warning);

    if (it == warnings.end ()) {

        return false;

    } else {

        const ProvokedWarning* newwarning = (*it).first;
        wxDateTime now = wxDateTime::Now();
        if (now.IsLaterThan (newwarning->GetTimeout ())) {

            return false;

        } else {

            return true;
        }
    }
}


bool ProvokedWarningRegistry::WasDetected (
        const ProvokedWarning &warning) const
{
    ProvokedWarningMap::const_iterator it;
    it = warnings.find (&warning);

    if (it == warnings.end ()) {

        return false;

    } else {

        return ((*it).second);
    }
}


void ProvokedWarningRegistry::SetWarningAsDetected (
        const ProvokedWarning &warning)
{
    wxASSERT (warnings.end () != warnings.find (&warning));
    ProvokedWarningMap::iterator it;
    it = warnings.find (&warning);
    (*it).second = true;
}


const ProvokedWarning *
ProvokedWarningRegistry::FindRegisteredWarning (const wxString &caption, 
							 const wxString &message) 
    const
{
    for (ProvokedWarningMap::const_iterator it = warnings.begin ();
	 it != warnings.end(); it++) {

        const ProvokedWarning *warning = it->first;
        if (warning->GetCaption () == caption && 
	    (message.empty() || warning->GetMessage() == message))
	    return it->first;
    }
    return NULL;
}


