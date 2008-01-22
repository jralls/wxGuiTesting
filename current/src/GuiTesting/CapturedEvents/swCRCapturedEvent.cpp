///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRCapturedEvent.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRCapturedEvent.h"
#endif

#include "CRCapturedEvent.h"

namespace wxTst {


CRCapturedEvent::CRCapturedEvent (wxEvent *event) :
m_event (event)
{
    // Nothing to do
}


CRCapturedEvent::~CRCapturedEvent ()
{
    // Nothing to do
}


wxEvent * CRCapturedEvent::GetEvent ()
{
    return m_event;
}


bool CRCapturedEvent::IsPending () const
{
    return false;
}


bool CRCapturedEvent::IsIrrelevant () const
{
    return false;
}

} // End namespace wxTst

