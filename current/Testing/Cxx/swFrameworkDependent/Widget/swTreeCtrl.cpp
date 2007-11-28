///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Widget/swTreeCtrl.cpp
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Fuereder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swTreeCtrl.h"
#endif

#include "swTreeCtrl.h"

#include "wx/imaglist.h"

namespace sw {


BEGIN_EVENT_TABLE(TreeCtrl, wxTreeCtrl)
	EVT_TREE_ITEM_RIGHT_CLICK (-1, TreeCtrl::OnTreeRightClick)
	EVT_RIGHT_UP (TreeCtrl::OnRightClick)
	EVT_RIGHT_DOWN (TreeCtrl::OnRightClick)
	EVT_TREE_BEGIN_LABEL_EDIT(-1, TreeCtrl::OnBeginLabelEdit)
END_EVENT_TABLE()

IMPLEMENT_DYNAMIC_CLASS (TreeCtrl, wxTreeCtrl)

TreeCtrl::TreeCtrl(wxWindow* parent, 
					   wxWindowID id,
					   const wxPoint& pos,
					   const wxSize& size,
					   long style,
					   const wxValidator& validator,
					   const wxString& name) :
	wxTreeCtrl (parent, id, pos, size, style | wxTR_EDIT_LABELS | wxTR_HAS_BUTTONS | wxTR_TWIST_BUTTONS , validator, name)
{
}

TreeCtrl::TreeCtrl()
{
}


TreeCtrl::~TreeCtrl()
{
}


unsigned int TreeCtrl::GetSiblingIndex (const wxTreeItemId& siblingId, const wxTreeItemId &parentId)
{
	long j;
	unsigned int i = 1;
	
	if (GetFirstChild (parentId, (void *&)j) == siblingId) {

		return i;
	}
	i++;
	while (GetNextChild (parentId, (void *&)j) != siblingId 
		&& i <= GetChildrenCount(parentId, FALSE)) {

		i++;
	}

	return i <= GetChildrenCount(parentId, FALSE) ? i : 0;
}


unsigned int TreeCtrl::GetSiblingIndex (const wxTreeItemId& siblingId)
{
	return GetSiblingIndex (siblingId, GetRootItem ());
}


unsigned int TreeCtrl::GetSiblingCount (const wxTreeItemId &parentId)
{
	long j;
	unsigned int i = 1;
	
	if (GetFirstChild (parentId, (void *&)j) == GetLastChild (parentId)) {

		return i;
	}
	i++;
	while (GetNextChild (parentId, (void *&)j) != GetLastChild (parentId) 
		&& i <= GetChildrenCount(parentId, FALSE)) {

		i++;
	}

	return i <= GetChildrenCount(parentId, FALSE) ? i : 0;
}


unsigned int TreeCtrl::GetSiblingCount ()
{
	return GetSiblingCount (GetRootItem ());
}


wxTreeItemId TreeCtrl::GetNthSibling (unsigned int index, const wxTreeItemId &parentId)
{
	long cookie;
	wxTreeItemId sibling;
	
	if (index == 0) {

		return parentId;
	}
	
	sibling = GetFirstChild (parentId, (void *&)cookie);
	for ( unsigned int i = 1; i != index && i <= GetChildrenCount(parentId, FALSE); i++) {
		
		sibling = GetNextChild (parentId, (void *&)cookie);
	}

	return sibling;
}


wxTreeItemId TreeCtrl::GetNthSibling (unsigned int index)
{
	return GetNthSibling (index, GetRootItem ());
}


unsigned int TreeCtrl::GetDepth (const wxTreeItemId &id)
{
	wxTreeItemId parentId = GetItemParent (id);
    if (parentId == wxTreeItemId ()) { // id is already the root

        return 0;

    } else if (parentId == GetRootItem ()) {
	
		return 1;

	} else {

		return GetDepth (parentId) + 1;
	}
}


void TreeCtrl::SetChildrenNumber (const wxTreeItemId &parentId, unsigned int childrenNumber)
{
    wxTreeItemId childToDeleteId;

	int diff = childrenNumber - GetChildrenCount (parentId, FALSE);
	if (diff > 0) {

	    AppendItem (parentId, _T(""));
	    SetChildrenNumber (parentId, childrenNumber);

	} else if (diff < 0) {

        childToDeleteId = GetNthSibling (GetChildrenCount (parentId, FALSE), parentId);

        DeleteChildren (childToDeleteId);
		Delete (childToDeleteId);

		SetChildrenNumber (parentId, childrenNumber);
	}
	ReduceChildrenToMinimumStyle (parentId);
}


void TreeCtrl::ReduceToMinimumStyle (const wxTreeItemId &id)
{
	if (id.IsOk ()) {
		
		SetItemBackgroundColour (id, wxNullColour);
		SetItemBold (id, FALSE);
		SetItemTextColour (id, wxSystemSettings::GetColour (wxSYS_COLOUR_WINDOWTEXT));
		SetChildrenNumber (id, 0);
		SetItemImage (id, GetSiblingIndex (id), wxTreeItemIcon_Normal);
		SetItemImage (id, GetSiblingIndex (id), wxTreeItemIcon_Selected);
		SetItemImage (id, GetSiblingIndex (id), wxTreeItemIcon_Expanded);
		SetItemImage (id, GetSiblingIndex (id), wxTreeItemIcon_SelectedExpanded );
	}
}


void TreeCtrl::ReduceChildrenToMinimumStyle (const wxTreeItemId &id)
{
	long cookie;
	wxTreeItemId siblingId = GetFirstChild (id, (void *&)cookie);
	while (siblingId.IsOk ()) {

		ReduceToMinimumStyle (siblingId);
		siblingId = GetNextChild (id, (void *&)cookie);
	}
}


void TreeCtrl::OnRightClick (wxMouseEvent &event)
{
	event.Skip ();
}


void TreeCtrl::OnTreeRightClick (wxTreeEvent &event)
{
	event.Skip ();
}


void TreeCtrl::OnBeginLabelEdit (wxTreeEvent &event)
{
	event.Skip ();
}


void TreeCtrl::OnEndLabelEdit (wxTreeEvent &event)
{
	event.Skip ();
}


void TreeCtrl::SetBitmapColor (const wxTreeItemId &id, wxColour &colour, unsigned int i)
{
	wxBitmap *colorBitmap1 = new wxBitmap (12, 12);
	wxMemoryDC temp_dc;
	temp_dc.SelectObject(*colorBitmap1);
	temp_dc.SetBrush (wxBrush (colour, wxSOLID));
	temp_dc.FloodFill (1, 1, *wxBLACK);
	temp_dc.SelectObject (wxNullBitmap);
	wxBitmap *colorBitmap2 = new wxBitmap (12, 12);
	temp_dc.SelectObject(*colorBitmap2);
	temp_dc.SetBrush (wxBrush (colour, wxSOLID));
	temp_dc.FloodFill (1, 1, *wxBLACK);
	temp_dc.SelectObject (wxNullBitmap);
	wxBitmap *colorBitmap3 = new wxBitmap (12, 12);
	temp_dc.SelectObject(*colorBitmap3);
	temp_dc.SetBrush (wxBrush (colour, wxSOLID));
	temp_dc.FloodFill (1, 1, *wxBLACK);
	temp_dc.SelectObject (wxNullBitmap);
	wxBitmap *colorBitmap4 = new wxBitmap (12, 12);
	temp_dc.SelectObject(*colorBitmap4);
	temp_dc.SetBrush (wxBrush (colour, wxSOLID));
	temp_dc.FloodFill (1, 1, *wxBLACK);
	temp_dc.SelectObject (wxNullBitmap);

  
	wxImageList *imageList = GetImageList ();
	if (imageList == NULL) {

		imageList = new wxImageList (12, 12);
		SetImageList (imageList);
	}
	if (imageList->GetImageCount () / 4 < i + 1) {

		imageList->Add (*colorBitmap1);
		imageList->Add (*colorBitmap2);
		imageList->Add (*colorBitmap3);
		imageList->Add (*colorBitmap4);

	} else {
	
		imageList->Replace (4 * i, *colorBitmap1);
		imageList->Replace (4 * i + 1, *colorBitmap2);
		imageList->Replace (4 * i + 2, *colorBitmap3);
		imageList->Replace (4 * i + 3, *colorBitmap4);
	}

	SetImageList (GetImageList ());
	SetStateImageList (GetImageList ());

	SetItemImage (id, 4 * i, wxTreeItemIcon_Normal);
	SetItemImage (id, 4 * i + 1, wxTreeItemIcon_Selected);
	SetItemImage (id, 4 * i + 2, wxTreeItemIcon_Expanded);
	SetItemImage (id, 4 * i + 3, wxTreeItemIcon_SelectedExpanded );
}


void TreeCtrl::DeleteBitmapList ()
{
	wxImageList *imageList;
	imageList = GetImageList ();
	if (imageList != NULL) {

		imageList->RemoveAll();
	}
	while (!m_bitmapList.empty ()) {

		delete m_bitmapList.front ();
		m_bitmapList.pop_front ();
	}
}


wxTreeItemId TreeCtrl::GetNthChild (wxTreeCtrl *treeCtrl, unsigned int idx,
        const wxTreeItemId &id)
{
    wxASSERT (idx > 0);

    wxTreeItemId cur;
    wxTreeItemIdValue cookie;
    cur = treeCtrl->GetFirstChild (id, cookie);
    for (int i = 1; i < idx; i++) {

        cur = treeCtrl->GetNextChild (id, cookie);
    }
    
    return cur;
}

} // End namespace sw
