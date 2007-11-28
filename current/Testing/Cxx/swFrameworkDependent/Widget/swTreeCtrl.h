//////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Widget/swTreeCtrl.h
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWTREECTRL_H
#define SWTREECTRL_H

#ifdef __GNUG__
    #pragma interface "swTreeCtrl.h"
#endif

#include "Common.h"

#include <wx/treectrl.h>
#include <list>

namespace sw {


class TreeCtrl: public wxTreeCtrl
{

DECLARE_DYNAMIC_CLASS (TreeCtrl)

DECLARE_EVENT_TABLE()

public:
	TreeCtrl ();
	
	TreeCtrl(wxWindow* parent,
			   wxWindowID id,
			   const wxPoint& pos = wxDefaultPosition,
			   const wxSize& size = wxDefaultSize,
			   long style = wxTR_EDIT_LABELS | wxTR_HAS_BUTTONS,
			   const wxValidator& validator = wxDefaultValidator,
			   const wxString& name = _T("listCtrl"));

	~TreeCtrl ();

	unsigned int GetSiblingIndex (const wxTreeItemId& siblingId, const wxTreeItemId &parentId);
	unsigned int GetSiblingIndex (const wxTreeItemId& siblingId);

	unsigned int GetSiblingCount (const wxTreeItemId &parentId);
	unsigned int GetSiblingCount ();

	wxTreeItemId GetNthSibling (unsigned int index, const wxTreeItemId &parentId);
	wxTreeItemId GetNthSibling (unsigned int index);

	unsigned int GetDepth (const wxTreeItemId &siblingId);	

	void SetChildrenNumber (const wxTreeItemId &parentId, unsigned int childrenNumber);

	void ReduceToMinimumStyle (const wxTreeItemId &id);
	void ReduceChildrenToMinimumStyle (const wxTreeItemId &id);

	virtual void OnRightClick (wxMouseEvent &event);
    virtual void OnTreeRightClick (wxTreeEvent &event);
	virtual void OnBeginLabelEdit (wxTreeEvent &event);
	virtual void OnEndLabelEdit (wxTreeEvent &event);

	void SetBitmapColor (const wxTreeItemId &id, wxColour &colour, unsigned int i);

	void DeleteBitmapList ();

    // Maybe this is not the best place for general wxTreeCtrl helper functions?

    /*! \fn static wxTreeItemId GetNthChild (wxTreeCtrl *treeCtrl, unsigned int idx, const wxTreeItemId &id)
        \brief Get n-th child of given tree item.

        \param treeCtrl tree control holding given tree item
        \param idx index of child to get (1 based)
        \param id tree item to get n-th child from
        \return n-th child of given tree item
    */
    static wxTreeItemId GetNthChild (wxTreeCtrl *treeCtrl, unsigned int idx,
            const wxTreeItemId &id);

private:
	typedef std::list <wxBitmap *> BitmapList;

	BitmapList m_bitmapList;

};

} // End namespace sw

#endif //SWTREECTRL_H
