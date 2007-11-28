///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRRadioBoxSelectionEvent.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRRadioBoxSelectionEvent.h"
#endif

#include "swCRRadioBoxSelectionEvent.h"

#include "swCRWindowHierarchyHandler.h"
#include "swCRCppEmitter.h"

namespace swTst {


CRRadioBoxSelectionEvent::CRRadioBoxSelectionEvent (wxEvent *event) :
CRCapturedEvent (event)
{
    m_isXRC = false;
}


CRRadioBoxSelectionEvent::~CRRadioBoxSelectionEvent ()
{
    // Nothing to do
}


void CRRadioBoxSelectionEvent::Process (CRCapturedEvent **pendingEvt)
{
    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);

    if (hierarchy->FindXRCNode (wdwEvtObject) != NULL) {

        m_isXRC = true;
    }
    m_radioBoxName = wdwEvtObject->GetName ();
    m_containerName = hierarchy->FindContainerName (wdwEvtObject);
    wxASSERT (!m_containerName.IsEmpty ());

    wxASSERT (m_event->IsCommandEvent ());
    wxCommandEvent *cmdEvt = wxDynamicCast (m_event, wxCommandEvent);
    wxASSERT (cmdEvt != NULL);
    wxRadioBox *radioBox = wxDynamicCast (wdwEvtObject, wxRadioBox);
    wxASSERT (radioBox != NULL);
    m_radioBoxValue = radioBox->GetStringSelection ();
}


void CRRadioBoxSelectionEvent::EmitCpp ()
{
    // Expected emitting (XRC):
    /*
    wxWindow *evtSimHlpTestPanel = wxWindow::FindWindowByName (
            "EvtSimHlpTestPanel");
    CPPUNIT_ASSERT_MESSAGE ("Container window for radio box 'RadioBox' not \
            found", evtSimHlpTestPanel != NULL);
    wxWindow *radioBoxWdw = evtSimHlpTestPanel->FindWindow (XRCID("RadioBox"));
    CPPUNIT_ASSERT_MESSAGE ("Window for radio box 'RadioBox' not found",
            radioBoxWdw != NULL);
    wxRadioBox *radioBox = wxDynamicCast (radioBoxWdw, wxRadioBox);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for radio box 'RadioBox' failed",
            radioBox != NULL);
    const wxString radioBoxSelectionText (_("Radio2"));
    int radioBoxSelection = radioBox->FindString (radioBoxSelectionText);
    swTst::WxGuiTestEventSimulationHelper::SelectRadioBoxItem (radioBox,
            radioBoxSelection);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *radioBoxWdw = evtSimHlpTestPanel->FindWindow ("RadioBox");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format ("radio box '%s'", m_radioBoxName.c_str ()));

    wxString radioBoxWdwVarName = emitter->MakeVarName (m_radioBoxName, "Wdw");

    wxString str;
    str << "wxWindow *" << radioBoxWdwVarName << " = " << containerVarName <<
            "->FindWindow (";
    if (m_isXRC) {
        
        str << "XRCID(\"" << m_radioBoxName << "\"));";

    } else {

        str << "\"" << m_radioBoxName << "\");";
    }
    emitter->AddCode (str);
    
    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Window for radio box '" <<
            m_radioBoxName << "' not found\", " << radioBoxWdwVarName <<
            " != NULL);";
    emitter->AddCode (str);

    wxString radioBoxVarName = emitter->MakeVarName (m_radioBoxName);

    str.Clear ();
    str << "wxRadioBox *" << radioBoxVarName << " = wxDynamicCast (" <<
            radioBoxWdwVarName << ", wxRadioBox);";
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Converting window for radio box '" <<
            m_radioBoxName << "' failed\", " << radioBoxVarName << " != NULL);";
    emitter->AddCode (str);
    
    wxString radioBoxSelTextVarName = emitter->MakeVarName (radioBoxVarName,
            "SelectionText");

    str.Clear ();
    str << "const wxString " << radioBoxSelTextVarName << " (_(\"" <<
            m_radioBoxValue << "\"));";
    emitter->AddCode (str);

    wxString radioBoxSelVarName = emitter->MakeVarName (radioBoxVarName,
            "Selection");

    str.Clear ();
    str << "int " << radioBoxSelVarName << " = " << radioBoxVarName <<
            "->FindString (" << radioBoxSelTextVarName << ");";
    emitter->AddCode (str);

    str.Clear ();
    str << "swTst::WxGuiTestEventSimulationHelper::SelectRadioBoxItem (" <<
            radioBoxVarName << ", " << radioBoxSelVarName << ");";
    emitter->AddCode (str);
    
    str.Clear ();
    str << "swTst::WxGuiTestHelper::FlushEventQueue ();\n";
    emitter->AddCode (str);
}

} // End namespace swTst

