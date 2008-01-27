///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/ProvokedWarning.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "ProvokedWarning.h"
#endif

#include <wxGuiTest/ProvokedWarning.h>

namespace wxTst {


ProvokedWarning::ProvokedWarning (const wxString &caption,
        const wxString& message, const unsigned int timeout) :
m_caption (caption),
m_message (message)
{
    m_timeout.SetToCurrent ();
    m_timeout.Add (wxTimeSpan::Seconds (timeout));
}

const wxString& ProvokedWarning::GetCaption () const
{
    return m_caption;
}


const wxString& ProvokedWarning::GetMessage () const
{
    return m_message;
}


const wxDateTime& ProvokedWarning::GetTimeout () const
{
    return m_timeout;
}

} // End namespace wxTst

