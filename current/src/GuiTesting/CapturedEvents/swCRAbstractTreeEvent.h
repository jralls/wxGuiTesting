///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRAbstractTreeEvent.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRABSTRACTTREEEVENT_H
#define SWCRABSTRACTTREEEVENT_H

#ifdef __GNUG__
    #pragma interface "CRAbstractTreeEvent.h"
#endif

#include <wxGuiTest/Common.h>

#include <list>

#include "CRCapturedEvent.h"

class wxTreeCtrl;
class wxTreeItemId;

namespace wxTst {


/*! \class CRAbstractTreeEvent
    \brief Abstract tree event class with common helper methods.

    How to identify tree items? Cache hierarchy of parents based on index of
    tree node in array of siblings from root to concrete tree item (leaf).
*/
class CRAbstractTreeEvent : public CRCapturedEvent
{
public:
    /*! \fn CRAbstractTreeEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRAbstractTreeEvent (wxEvent *event);


    /*! \fn virtual ~CRAbstractTreeEvent ()
        \brief Destructor
    */
    virtual ~CRAbstractTreeEvent ();

protected:
    /*! \fn virtual void BuildTreeItemSiblingIdxHierarchyList ()
        \brief Build sibling index hierarchy list to re-identify tree item.
    */
    virtual void BuildTreeItemSiblingIdxHierarchyList ();


    /*! \fn virtual unsigned int GetSiblingIdx (wxTreeCtrl *treeCtrl, const wxTreeItemId &id)
        \brief Calculate index of given tree item within siblings.

        Index is 1 based in analogy to TreeCtrl class which is used by the
        emitted code!

        \param treeCtrl tree control holding the tree item
        \param id tree item to find sibling index for
        \return index of tree item within siblings
    */
    virtual unsigned int GetSiblingIdx (wxTreeCtrl *treeCtrl,
            const wxTreeItemId &id);

protected:
    typedef std::list < unsigned int > UnsignedIntList;
    UnsignedIntList m_treeItemSiblingIdxHierarchyList;

private:

private:
    // No copy and assignment constructor:
    CRAbstractTreeEvent (const CRAbstractTreeEvent &rhs);
    CRAbstractTreeEvent & operator= (const CRAbstractTreeEvent &rhs);
};

} // End namespace wxTst

#endif // SWCRABSTRACTTREEEVENT_H

