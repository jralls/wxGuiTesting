///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/GuiTestProvokedWarningRegistry.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "GuiTestProvokedWarningRegistry.h"
#endif

#include <wxGuiTest/GuiTestProvokedWarningRegistry.h>

using namespace wxTst;


// Init single instance:
WxGuiTestProvokedWarningRegistry *WxGuiTestProvokedWarningRegistry::ms_instance = NULL;


WxGuiTestProvokedWarningRegistry::WxGuiTestProvokedWarningRegistry ()
{
    // Nothing to do
}


WxGuiTestProvokedWarningRegistry::~WxGuiTestProvokedWarningRegistry ()
{
    ProvokedWarningMap::iterator it = warnings.begin ();
    while (it != warnings.end ()) {

        this->UnregisterWarning (*((*it++).first));
    }
    warnings.clear ();
}


WxGuiTestProvokedWarningRegistry & WxGuiTestProvokedWarningRegistry::GetInstance ()
{
    if (ms_instance == NULL) {

        ms_instance = new WxGuiTestProvokedWarningRegistry ();
    }
    return *ms_instance;
}


void WxGuiTestProvokedWarningRegistry::Destroy ()
{
    if (ms_instance != NULL) {

        delete ms_instance;
        ms_instance = NULL;
    }
}


void WxGuiTestProvokedWarningRegistry::RegisterWarning (
        const WxGuiTestProvokedWarning &warning)
{
    wxASSERT (warnings.end () == warnings.find (&warning));
    warnings.insert (std::make_pair (&warning, false));
}


void WxGuiTestProvokedWarningRegistry::UnregisterWarning (
        const WxGuiTestProvokedWarning &warning)
{
    wxASSERT (warnings.end () != warnings.find (&warning));
    warnings.erase (&warning);
}


bool WxGuiTestProvokedWarningRegistry::IsRegisteredAndInTime (
        const WxGuiTestProvokedWarning& warning) const
{
    ProvokedWarningMap::const_iterator it;
    it = warnings.find (&warning);

    if (it == warnings.end ()) {

        return false;

    } else {

        const WxGuiTestProvokedWarning* newwarning = (*it).first;
        wxDateTime now = wxDateTime::Now();
        if (now.IsLaterThan (newwarning->GetTimeout ())) {

            return false;

        } else {

            return true;
        }
    }
}


bool WxGuiTestProvokedWarningRegistry::WasDetected (
        const WxGuiTestProvokedWarning &warning) const
{
    ProvokedWarningMap::const_iterator it;
    it = warnings.find (&warning);

    if (it == warnings.end ()) {

        return false;

    } else {

        return ((*it).second);
    }
}


void WxGuiTestProvokedWarningRegistry::SetWarningAsDetected (
        const WxGuiTestProvokedWarning &warning)
{
    wxASSERT (warnings.end () != warnings.find (&warning));
    ProvokedWarningMap::iterator it;
    it = warnings.find (&warning);
    (*it).second = true;
}


const WxGuiTestProvokedWarning *
WxGuiTestProvokedWarningRegistry::FindRegisteredWarning (const wxString &caption, 
							 const wxString &message) 
    const
{
    for (ProvokedWarningMap::const_iterator it = warnings.begin ();
	 it != warnings.end(); it++) {

        const WxGuiTestProvokedWarning *warning = it->first;
        if (warning->GetCaption () == caption && 
	    (message.empty() || warning->GetMessage() == message))
	    return it->first;
    }
    return NULL;
}


