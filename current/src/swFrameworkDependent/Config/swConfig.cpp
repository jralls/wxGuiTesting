///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Config/swConfig.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swConfig.h"
#endif

#include <wxGuiTest/Config/swConfig.h>

namespace sw {


Config::Config ()
{
    // Nothing to do
}


Config::~Config ()
{
    // Nothing to do
}


void Config::SetResourceDir (const wxString &resDir)
{
    wxASSERT (!resDir.IsEmpty ());
    m_resDir = resDir;
}


bool Config::GetResourceDir (wxString &resDir)
{
    resDir = m_resDir;
    return true;
}


bool Config::GetStrConfigProperty (const wxString &key, wxString &value)
{
    return false;
}

} // End namespace sw
