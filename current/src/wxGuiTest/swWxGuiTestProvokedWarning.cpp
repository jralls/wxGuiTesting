///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/GuiTestProvokedWarning.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "GuiTestProvokedWarning.h"
#endif

#include <wxGuiTest/GuiTestProvokedWarning.h>

namespace wxTst {


WxGuiTestProvokedWarning::WxGuiTestProvokedWarning (const wxString &caption,
        const wxString& message, const unsigned int timeout) :
m_caption (caption),
m_message (message)
{
    m_timeout.SetToCurrent ();
    m_timeout.Add (wxTimeSpan::Seconds (timeout));
}

const wxString& WxGuiTestProvokedWarning::GetCaption () const
{
    return m_caption;
}


const wxString& WxGuiTestProvokedWarning::GetMessage () const
{
    return m_message;
}


const wxDateTime& WxGuiTestProvokedWarning::GetTimeout () const
{
    return m_timeout;
}

} // End namespace wxTst

