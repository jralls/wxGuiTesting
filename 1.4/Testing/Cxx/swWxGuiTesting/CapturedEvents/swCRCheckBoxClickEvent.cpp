///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRCheckBoxClickEvent.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRCheckBoxClickEvent.h"
#endif

#include "swCRCheckBoxClickEvent.h"

#include "swCRWindowHierarchyHandler.h"
#include "swCRCppEmitter.h"

namespace swTst {


CRCheckBoxClickEvent::CRCheckBoxClickEvent (wxEvent *event) :
CRCapturedEvent (event)
{
    m_isChecked = false;
    m_isXRC = false;
}


CRCheckBoxClickEvent::~CRCheckBoxClickEvent ()
{
// Nothing to do
}


void CRCheckBoxClickEvent::Process (CRCapturedEvent **pendingEvt)
{
    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);

    if (hierarchy->FindXRCNode (wdwEvtObject) != NULL) {

        m_isXRC = true;
    }
    m_checkBoxName = wdwEvtObject->GetName ();
    m_containerName = hierarchy->FindContainerName (wdwEvtObject);
    wxASSERT (!m_containerName.IsEmpty ());

    wxASSERT (m_event->IsCommandEvent ());
    wxCommandEvent *cmdEvt = wxDynamicCast (m_event, wxCommandEvent);
    wxASSERT (cmdEvt != NULL);
    m_isChecked = cmdEvt->IsChecked ();
}


void CRCheckBoxClickEvent::EmitCpp ()
{
    // Expected emitting (XRC):
    /*
    wxWindow *evtSimHlpTestPanel = wxWindow::FindWindowByName (
            "EvtSimHlpTestPanel");
    CPPUNIT_ASSERT_MESSAGE ("Container window for check box 'Checkbox' not \
            found", evtSimHlpTestPanel != NULL);
    wxWindow *checkboxWdw = evtSimHlpTestPanel->FindWindow (XRCID("Checkbox"));
    CPPUNIT_ASSERT_MESSAGE ("Window for check box 'Checkbox' not found",
            checkboxWdw != NULL);
    wxCheckBox *checkbox = wxDynamicCast (checkboxWdw, wxCheckBox);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for check box 'Checkbox' \
            failed", checkbox != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetCheckboxState (checkbox, true);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *checkboxWdw = evtSimHlpTestPanel->FindWindow ("Checkbox");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format ("check box '%s'", m_checkBoxName.c_str ()));

    wxString checkBoxWdwVarName = emitter->MakeVarName (m_checkBoxName, "Wdw");

    wxString str;
    str << "wxWindow *" << checkBoxWdwVarName << " = " << containerVarName <<
            "->FindWindow (";
    if (m_isXRC) {
        
        str << "XRCID(\"" << m_checkBoxName << "\"));";

    } else {

        str << "\"" << m_checkBoxName << "\");";
    }
    emitter->AddCode (str);
    
    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Window for check box '" <<
            m_checkBoxName << "' not found\", " << checkBoxWdwVarName <<
            " != NULL);";
    emitter->AddCode (str);

    wxString checkBoxVarName = emitter->MakeVarName (m_checkBoxName);

    str.Clear ();
    str << "wxCheckBox *" << checkBoxVarName << " = wxDynamicCast (" <<
            checkBoxWdwVarName << ", wxCheckBox);";
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Converting window for check box '" <<
            m_checkBoxName << "' failed\", " << checkBoxVarName << " != NULL);";
    emitter->AddCode (str);

    wxString isCheckedBoolStr = m_isChecked ? "true" : "false";
    str.Clear ();
    str << "swTst::WxGuiTestEventSimulationHelper::SetCheckboxState (" <<
            checkBoxVarName << ", " << isCheckedBoolStr << ");";
    emitter->AddCode (str);
    
    str.Clear ();
    str << "swTst::WxGuiTestHelper::FlushEventQueue ();\n";
    emitter->AddCode (str);
}

} // End namespace swTst

