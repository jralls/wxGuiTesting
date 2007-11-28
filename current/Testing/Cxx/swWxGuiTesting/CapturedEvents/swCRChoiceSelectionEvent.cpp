///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRChoiceSelectionEvent.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRChoiceSelectionEvent.h"
#endif

#include "swCRChoiceSelectionEvent.h"

#include "swCRWindowHierarchyHandler.h"
#include "swCRCppEmitter.h"

namespace swTst {


CRChoiceSelectionEvent::CRChoiceSelectionEvent (wxEvent *event) :
CRCapturedEvent (event)
{
    m_isXRC = false;
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

    if (hierarchy->FindXRCNode (wdwEvtObject) != NULL) {

        m_isXRC = true;
    }
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
    swTst::WxGuiTestEventSimulationHelper::SelectChoiceItem (choice,
            choiceSelection);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *choiceWdw = evtSimHlpTestPanel->FindWindow ("Choice");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format ("choice '%s'", m_choiceName.c_str ()));

    wxString choiceWdwVarName = emitter->MakeVarName (m_choiceName, "Wdw");

    wxString str;
    str << "wxWindow *" << choiceWdwVarName << " = " << containerVarName <<
            "->FindWindow (";
    if (m_isXRC) {
        
        str << "XRCID(\"" << m_choiceName << "\"));";

    } else {

        str << "\"" << m_choiceName << "\");";
    }
    emitter->AddCode (str);
    
    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Window for choice '" << m_choiceName <<
            "' not found\", " << choiceWdwVarName << " != NULL);";
    emitter->AddCode (str);

    wxString choiceVarName = emitter->MakeVarName (m_choiceName);

    str.Clear ();
    str << "wxChoice *" << choiceVarName << " = wxDynamicCast (" <<
            choiceWdwVarName << ", wxChoice);";
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Converting window for choice '" <<
            m_choiceName << "' failed\", " << choiceVarName << " != NULL);";
    emitter->AddCode (str);
    
    wxString choiceSelTextVarName = emitter->MakeVarName (choiceVarName,
            "SelectionText");

    str.Clear ();
    str << "const wxString " << choiceSelTextVarName << " (_(\"" <<
            m_choiceValue << "\"));";
    emitter->AddCode (str);

    wxString choiceSelVarName = emitter->MakeVarName (choiceVarName,
            "Selection");

    str.Clear ();
    str << "int " << choiceSelVarName << " = " << choiceVarName <<
            "->FindString (" << choiceSelTextVarName << ");";
    emitter->AddCode (str);

    str.Clear ();
    str << "swTst::WxGuiTestEventSimulationHelper::SelectChoiceItem (" <<
            choiceVarName << ", " << choiceSelVarName << ");";
    emitter->AddCode (str);
    
    str.Clear ();
    str << "swTst::WxGuiTestHelper::FlushEventQueue ();\n";
    emitter->AddCode (str);
}

} // End namespace swTst

