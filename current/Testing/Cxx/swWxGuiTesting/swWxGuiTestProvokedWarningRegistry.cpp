///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swWxGuiTestProvokedWarningRegistry.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swWxGuiTestProvokedWarningRegistry.h"
#endif

#include "swWxGuiTestProvokedWarningRegistry.h"

namespace swTst {


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
        const WxGuiTestProvokedWarning &warning) const
{
    ProvokedWarningMap::const_iterator it;
    it = warnings.find (&warning);

    if (it == warnings.end ()) {

        return false;

    } else {

        const WxGuiTestProvokedWarning *warning = (*it).first;
        wxDateTime now = wxDateTime::Now();
        if (now.IsLaterThan (warning->GetTimeout ())) {

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
WxGuiTestProvokedWarningRegistry::FindRegisteredWarning (
        const wxString &caption, const wxString &message) const
{
    bool found = false;
    ProvokedWarningMap::const_iterator it = warnings.begin ();
    while ((!found) && (it != warnings.end ())) {

        const WxGuiTestProvokedWarning *warning = (*it).first;

        if (warning->GetCaption () == caption) {

            if (warning->GetMessage () != NULL) {

            } else {

                found = true;
            }
        }

        if (!found) {

            it++;
        }
    }

    if (found) {

        return (*it).first;

    } else {

        return NULL;
    }
}

} // End namespace swTst

