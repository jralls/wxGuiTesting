///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRChoiceSelectionEvent.cpp
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
    #pragma implementation "CRChoiceSelectionEvent.h"
#endif

#include "CRChoiceSelectionEvent.h"

#include <wxGuiTest/CRWindowHierarchyHandler.h>
#include <wxGuiTest/CRCppEmitter.h>

using namespace wxTst;


CRChoiceSelectionEvent::CRChoiceSelectionEvent (wxEvent *event) :
CRCapturedEvent (event)
{
//    m_isXRC = false;
}


CRChoiceSelectionEvent::~CRChoiceSelectionEvent ()
{
    // Nothing to do
}


void CRChoiceSelectionEvent::Process (CRCapturedEvent **pendingEvt)
{
    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);

    m_choiceName = wdwEvtObject->GetName ();
    m_containerName = hierarchy->FindContainerName (wdwEvtObject);
    wxASSERT (!m_containerName.IsEmpty ());

    wxASSERT (m_event->IsCommandEvent ());
    wxCommandEvent *cmdEvt = wxDynamicCast (m_event, wxCommandEvent);
    wxASSERT (cmdEvt != NULL);
    int choiceSel = cmdEvt->GetSelection ();
    wxChoice *choice = wxDynamicCast (wdwEvtObject, wxChoice);
    wxASSERT (choice != NULL);
    m_choiceValue = choice->GetString (choiceSel);
}


void CRChoiceSelectionEvent::EmitCpp ()
{
    // Expected emitting (XRC):
    /*
    wxWindow *evtSimHlpTestPanel = wxWindow::FindWindowByName (
            "EvtSimHlpTestPanel");
    CPPUNIT_ASSERT_MESSAGE ("Container window for choice 'Choice' not found",
            evtSimHlpTestPanel != NULL);
    wxWindow *choiceWdw = evtSimHlpTestPanel->FindWindow (XRCID("Choice"));
    CPPUNIT_ASSERT_MESSAGE ("Window for choice 'Choice' not found", choiceWdw
            != NULL);
    wxChoice *choice = wxDynamicCast (choiceWdw, wxChoice);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for choice 'Choice' failed",
            choice != NULL);
    const wxString choiceSelectionText (_("Item2"));
    int choiceSelection = choice->FindString (choiceSelectionText);
    wxTst::EventSimulationHelper::SelectChoiceItem (choice,
            choiceSelection);
    wxTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *choiceWdw = evtSimHlpTestPanel->FindWindow ("Choice");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format (_T("choice '%s'"), 
            m_choiceName.c_str ()));

    wxString choiceWdwVarName = emitter->MakeVarName (m_choiceName, _T("Wdw"));

    wxString str;
    str << _T("wxWindow *") << choiceWdwVarName << _T(" = ") << 
            containerVarName << _T("->FindWindow (");
    str << _T("_T(\"") << m_choiceName << _T("\"));");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Window for choice '") << m_choiceName <<
            _T("' not found\", ") << choiceWdwVarName << _T(" != NULL);");
    emitter->AddCode (str);

    wxString choiceVarName = emitter->MakeVarName (m_choiceName);

    str.Clear ();
    str << _T("wxChoice *") << choiceVarName << _T(" = wxDynamicCast (") <<
            choiceWdwVarName << _T(", wxChoice);");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Converting window for choice '") <<
            m_choiceName << _T("' failed\", ") << choiceVarName << _T(" != NULL);");
    emitter->AddCode (str);
    
    wxString choiceSelTextVarName = emitter->MakeVarName (choiceVarName,
            _T("SelectionText"));

    str.Clear ();
    str << _T("const wxString ") << choiceSelTextVarName << _T(" (_(\"") <<
            m_choiceValue << _T("\"));");
    emitter->AddCode (str);

    wxString choiceSelVarName = emitter->MakeVarName (choiceVarName,
            _T("Selection"));

    str.Clear ();
    str << _T("int ") << choiceSelVarName << _T(" = ") << choiceVarName <<
            _T("->FindString (") << choiceSelTextVarName << _T(");");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("wxTst::EventSimulationHelper::SelectChoiceItem (") <<
            choiceVarName << _T(", ") << choiceSelVarName << _T(");");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("wxTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}



