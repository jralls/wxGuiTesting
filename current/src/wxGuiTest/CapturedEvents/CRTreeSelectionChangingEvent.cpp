///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRTreeSelectionChangingEvent.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRTreeSelectionChangingEvent.h"
#endif

#include "CRTreeSelectionChangingEvent.h"

#include <wxGuiTest/CRWindowHierarchyHandler.h>
#include <wxGuiTest/CRCppEmitter.h>

using namespace wxTst;


CRTreeSelectionChangingEvent::CRTreeSelectionChangingEvent (wxEvent *event) :
CRAbstractTreeEvent (event)
{
//    Nothing to do
}


CRTreeSelectionChangingEvent::~CRTreeSelectionChangingEvent ()
{
    // Nothing to do
}


void CRTreeSelectionChangingEvent::Process (CRCapturedEvent** WXUNUSED(pendingEvt))
{
    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);
    m_treeCtrlName = wdwEvtObject->GetName ();
    m_containerName = hierarchy->FindContainerName (wdwEvtObject);
    wxASSERT (!m_containerName.IsEmpty ());

    this->BuildTreeItemSiblingIdxHierarchyList ();
}


void CRTreeSelectionChangingEvent::EmitCpp ()
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
    wxTreeItemId treeItemId1 = wxTst::EventSimulationHelper::GetNthTreeChild (treeCtrl, 2, rootId);
    CPPUNIT_ASSERT_MESSAGE ("Tree control item is invalid", treeItemId1.IsOk (
            ));
    wxTst::EventSimulationHelper::SelectTreeItem (treeItemId1,
            treeCtrl);
    wxTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *treeCtrlWdw = evtSimHlpTestPanel->FindWindow ("TreeCtrl");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format (_T("tree control '%s'"),
            m_treeCtrlName.c_str ()));

    wxString treeCtrlWdwVarName = emitter->MakeVarName (m_treeCtrlName, 
            _T("Wdw"));

    wxString str;
    str << _T("wxWindow *") << treeCtrlWdwVarName << _T(" = ") << 
            containerVarName << _T("->FindWindow (");
        str << _T("_T(\"") << m_treeCtrlName << _T("\"));");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Window for tree control '") <<
            m_treeCtrlName << _T("' not found\", ") << treeCtrlWdwVarName <<
            _T(" != NULL);");
    emitter->AddCode (str);

    wxString treeCtrlVarName = emitter->MakeVarName (m_treeCtrlName);

    str.Clear ();
    str << _T("wxTreeCtrl *") << treeCtrlVarName << _T(" = wxDynamicCast (") <<
            treeCtrlWdwVarName << _T(", wxTreeCtrl);");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Converting window for tree control '") <<
            m_treeCtrlName << _T("' failed\", ") << treeCtrlVarName << 
            _T(" != NULL);");
    emitter->AddCode (str);

    wxString rootIdVarName = _T("rootId");

    str.Clear ();
    str << _T("wxTreeItemId ") << rootIdVarName << _T(" = ") << treeCtrlVarName <<
            _T("->GetRootItem ();");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Tree control root item is invalid\", ")
            << rootIdVarName << _T(".IsOk ());");
    emitter->AddCode (str);

    wxString parentItemIdVarName = rootIdVarName;

    unsigned int cnt;
    UnsignedIntList::const_iterator it;
    for (it = m_treeItemSiblingIdxHierarchyList.begin (), cnt = 1;
            it != m_treeItemSiblingIdxHierarchyList.end (); it++, cnt++) {

        wxString curTreeItemIdVarName = emitter->MakeVarName (
                wxString::Format (_T("treeItemId%d"), cnt));

        str.Clear ();
        str << _T("wxTreeItemId ") << curTreeItemIdVarName 
	    << _T(" = wxTst::EventSimulationHelper::GetNthTreeChild (") 
	    << treeCtrlVarName << _T(", ") << (*it) << _T(", ") 
	    << parentItemIdVarName << _T(");");
        emitter->AddCode (str);

        str.Clear ();
        str << _T("CPPUNIT_ASSERT_MESSAGE (\"Tree control item is invalid\", ") <<
                curTreeItemIdVarName << _T(".IsOk ());");
        emitter->AddCode (str);

        parentItemIdVarName = curTreeItemIdVarName;
    }

    str.Clear ();
    str << _T("wxTst::EventSimulationHelper::SelectTreeItem (") <<
            parentItemIdVarName << _T(", ") << treeCtrlVarName << _T(");");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("wxTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}



