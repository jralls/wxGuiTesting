///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Config/swConfig.cpp
// Author:      Reinhold F�reder
// Created:     2004
// Copyright:   (c) 2005 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swConfig.h"
#endif

#include "swConfig.h"

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
