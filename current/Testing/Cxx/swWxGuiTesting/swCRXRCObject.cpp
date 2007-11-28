///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRXRCObject.cpp
// Author:      Reinhold F�reder
// Created:     2004
// Copyright:   (c) 2005 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRXRCObject.h"
#endif

#include "swCRXRCObject.h"

namespace swTst {


CRXRCObject::CRXRCObject (const wxString &name, const wxString &className,
        CRXRCNode *parentNode) :
CRXRCResource (name, className, parentNode)
{
    // Nothing to do
}


CRXRCObject::~CRXRCObject ()
{
    // Nothing to do
}

} // End namespace swTst

