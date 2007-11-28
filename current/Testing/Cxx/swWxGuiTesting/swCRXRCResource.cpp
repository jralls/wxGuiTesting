///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRXRCResource.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRXRCResource.h"
#endif

#include "swCRXRCResource.h"

namespace swTst {


CRXRCResource::CRXRCResource () :
CRXRCNode (_T("resource"), _T(""))
{
    // Nothing to do
}


CRXRCResource::CRXRCResource (const wxString &name,
        const wxString &className, CRXRCNode *parentNode) :
CRXRCNode (name, className, parentNode)
{
    NodeList::const_iterator it;

    for (it = m_nodeList.begin (); it != m_nodeList.end (); it++) {

        delete (*it);
    }
    m_nodeList.clear ();
}


CRXRCResource::~CRXRCResource ()
{
    // Nothing to do
}


void CRXRCResource::AddChild (CRXRCNode *child)
{
    m_nodeList.push_back (child);
}


unsigned int CRXRCResource::GetNmbChildren () const
{
    return m_nodeList.size ();
}


CRXRCNode * CRXRCResource::GetChild (unsigned int idx) const
{
    NodeList::const_iterator it;

    wxASSERT (idx < this->GetNmbChildren ());
    it = m_nodeList.begin ();
    for (int i = 0; i < idx; i++) {

        it++;
    }

    return (*it);
}

} // End namespace swTst

