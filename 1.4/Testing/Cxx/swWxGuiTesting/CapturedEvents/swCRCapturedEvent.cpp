///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRCapturedEvent.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRCapturedEvent.h"
#endif

#include "swCRCapturedEvent.h"

namespace swTst {


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

} // End namespace swTst

