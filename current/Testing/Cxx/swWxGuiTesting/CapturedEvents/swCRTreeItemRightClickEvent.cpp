///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRTreeItemRightClickEvent.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRTreeItemRightClickEvent.h"
#endif

#include "swCRTreeItemRightClickEvent.h"

#include "swCRWindowHierarchyHandler.h"
#include "swCRCppEmitter.h"

namespace swTst {


CRTreeItemRightClickEvent::CRTreeItemRightClickEvent (wxEvent *event) :
CRAbstractTreeEvent (event)
{
    m_isXRC = false;
}


CRTreeItemRightClickEvent::~CRTreeItemRightClickEvent ()
{
    // Nothing to do
}


void CRTreeItemRightClickEvent::Process (CRCapturedEvent **pendingEvt)
{
    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);

    if (hierarchy->FindXRCNode (wdwEvtObject) != NULL) {

        m_isXRC = true;
    }
    m_treeCtrlName = wdwEvtObject->GetName ();
    m_containerName = hierarchy->FindContainerName (wdwEvtObject);
    wxASSERT (!m_containerName.IsEmpty ());

    this->BuildTreeItemSiblingIdxHierarchyList ();
}


void CRTreeItemRightClickEvent::EmitCpp ()
{
    // Expected emitting (XRC):
    /*
    wxWindow *evtSimHlpTestPanel = wxWindow::FindWindowByName (
            "EvtSimHlpTestPanel");
    CPPUNIT_ASSERT_MESSAGE ("Container window for tree control 'TreeCtrl' not \
            found", evtSimHlpTestPanel != NULL);
    wxWindow *treeCtrlWdw = evtSimHlpTestPanel->FindWindow (XRCID("TreeCtrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for tree control 'TreeCtrl' not found",
            treeCtrlWdw != NULL);
    wxTreeCtrl *treeCtrl = wxDynamicCast (treeCtrlWdw, wxTreeCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for tree control 'TreeCtrl' \
            failed", treeCtrl != NULL);
    wxTreeItemId rootId = treeCtrl->GetRootItem ();
    CPPUNIT_ASSERT_MESSAGE ("Tree control root item is invalid", rootId.IsOk (
            ));
    treeCtrl->Expand (rootId);
    wxTreeItemId treeItemId1 = sw::TreeCtrl::GetNthChild (treeCtrl, 2, rootId);
    CPPUNIT_ASSERT_MESSAGE ("Tree control item is invalid", treeItemId1.IsOk (
            ));
    swTst::WxGuiTestEventSimulationHelper::RightClickTreeItem (treeItemId1,
            treeCtrl);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *treeCtrlWdw = evtSimHlpTestPanel->FindWindow ("TreeCtrl");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format ("tree control '%s'",
            m_treeCtrlName.c_str ()));

    wxString treeCtrlWdwVarName = emitter->MakeVarName (m_treeCtrlName, "Wdw");

    wxString str;
    str << "wxWindow *" << treeCtrlWdwVarName << " = " << containerVarName <<
            "->FindWindow (";
    if (m_isXRC) {
        
        str << "XRCID(\"" << m_treeCtrlName << "\"));";

    } else {

        str << "\"" << m_treeCtrlName << "\");";
    }
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Window for tree control '" <<
            m_treeCtrlName << "' not found\", " << treeCtrlWdwVarName <<
            " != NULL);";
    emitter->AddCode (str);

    wxString treeCtrlVarName = emitter->MakeVarName (m_treeCtrlName);

    str.Clear ();
    str << "wxTreeCtrl *" << treeCtrlVarName << " = wxDynamicCast (" <<
            treeCtrlWdwVarName << ", wxTreeCtrl);";
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Converting window for tree control '" <<
            m_treeCtrlName << "' failed\", " << treeCtrlVarName << " != NULL);";
    emitter->AddCode (str);

    wxString rootIdVarName = "rootId";

    str.Clear ();
    str << "wxTreeItemId " << rootIdVarName << " = " << treeCtrlVarName <<
            "->GetRootItem ();";
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Tree control root item is invalid\", " <<
            rootIdVarName << ".IsOk ());";
    emitter->AddCode (str);

    wxString parentItemIdVarName = rootIdVarName;

    unsigned int cnt;
    UnsignedIntList::const_iterator it;
    for (it = m_treeItemSiblingIdxHierarchyList.begin (), cnt = 1;
            it != m_treeItemSiblingIdxHierarchyList.end (); it++, cnt++) {

        // Right click event simulation requires the visibility of the tree
        // item due to bounding box calculations:
        str.Clear ();
        str << treeCtrlVarName << "->Expand (" << parentItemIdVarName << ");";
        emitter->AddCode (str);

        wxString curTreeItemIdVarName = emitter->MakeVarName (
                wxString::Format ("treeItemId%d", cnt));

        str.Clear ();
        str << "wxTreeItemId " << curTreeItemIdVarName <<
                " = sw::TreeCtrl::GetNthChild (" << treeCtrlVarName << ", " <<
                (*it) << ", " << parentItemIdVarName << ");";
        emitter->AddCode (str);

        str.Clear ();
        str << "CPPUNIT_ASSERT_MESSAGE (\"Tree control item is invalid\", " <<
                curTreeItemIdVarName << ".IsOk ());";
        emitter->AddCode (str);

        parentItemIdVarName = curTreeItemIdVarName;
    }

    str.Clear ();
    str << "swTst::WxGuiTestEventSimulationHelper::RightClickTreeItem (" <<
            parentItemIdVarName << ", " << treeCtrlVarName << ");";
    emitter->AddCode (str);

    str.Clear ();
    str << "swTst::WxGuiTestHelper::FlushEventQueue ();\n";
    emitter->AddCode (str);
}

} // End namespace swTst

