///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRAbstractTreeEvent.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRAbstractTreeEvent.h"
#endif

#include "CRAbstractTreeEvent.h"

#include <wx/treectrl.h>

namespace wxTst {


CRAbstractTreeEvent::CRAbstractTreeEvent (wxEvent *event) :
CRCapturedEvent (event)
{
    // Nothing to do
}


CRAbstractTreeEvent::~CRAbstractTreeEvent ()
{
    m_treeItemSiblingIdxHierarchyList.clear ();
}


void CRAbstractTreeEvent::BuildTreeItemSiblingIdxHierarchyList ()
{
    wxTreeEvent *treeEvt = wxDynamicCast (m_event, wxTreeEvent);
    wxASSERT (treeEvt != NULL);

    wxTreeCtrl *treeCtrl = wxDynamicCast (m_event->GetEventObject (), wxTreeCtrl);
    wxASSERT (treeCtrl != NULL);

    wxTreeItemId cur = treeEvt->GetItem ();
    while ((cur.IsOk ()) && (cur != treeCtrl->GetRootItem ())) {

        unsigned int siblingIdx = this->GetSiblingIdx (treeCtrl, cur);
        m_treeItemSiblingIdxHierarchyList.push_front (siblingIdx);
        cur = treeCtrl->GetItemParent (cur);
    }
}


unsigned int CRAbstractTreeEvent::GetSiblingIdx (
        wxTreeCtrl *treeCtrl, const wxTreeItemId &id)
{
    unsigned int idx = 0;
    wxTreeItemId cur = id;
    while (cur.IsOk ()) {

        cur = treeCtrl->GetPrevSibling (cur);
        idx++;
    }

    return idx;
}

} // End namespace wxTst

