///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRXRCNode.cpp
// Author:      Reinhold F�reder
// Created:     2004
// Copyright:   (c) 2005 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRXRCNode.h"
#endif

#include "swCRXRCNode.h"

namespace swTst {


CRXRCNode::CRXRCNode (const wxString &name, const wxString &className,
        CRXRCNode *parentNode) :
m_name (name),
m_class (className),
m_parentNode (parentNode)
{
    // Nothing to do
}


CRXRCNode::~CRXRCNode ()
{
    // Nothing to do
}


const wxString & CRXRCNode::GetName () const
{
    return m_name;
}


const wxString & CRXRCNode::GetClass () const
{
    return m_class;
}


CRXRCNode * CRXRCNode::GetParent () const
{
    return m_parentNode;
}

} // End namespace swTst

