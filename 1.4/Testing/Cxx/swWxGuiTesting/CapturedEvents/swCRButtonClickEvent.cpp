///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRButtonClickEvent.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRButtonClickEvent.h"
#endif

#include "swCRButtonClickEvent.h"

#include "swCRWindowHierarchyHandler.h"
#include "swCRCppEmitter.h"

namespace swTst {


CRButtonClickEvent::CRButtonClickEvent (wxEvent *event) :
CRCapturedEvent (event)
{
    m_isXRC = false;
}


CRButtonClickEvent::~CRButtonClickEvent ()
{
    // Nothing to do
}


void CRButtonClickEvent::Process (CRCapturedEvent **pendingEvt)
{
    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);

    if (hierarchy->FindXRCNode (wdwEvtObject) != NULL) {

        m_isXRC = true;
    }
    m_buttonName = wdwEvtObject->GetName ();
    m_containerName = hierarchy->FindContainerName (wdwEvtObject);
    wxASSERT (!m_containerName.IsEmpty ());
}


void CRButtonClickEvent::EmitCpp ()
{
    // Expected emitting (XRC):
    /*
    wxWindow *evtSimHlpTestPanel = wxWindow::FindWindowByName
            ("EvtSimHlpTestPanel");
    CPPUNIT_ASSERT_MESSAGE ("Container window for button 'Button' not found",
            evtSimHlpTestPanel != NULL);
    wxWindow *buttonWdw = evtSimHlpTestPanel->FindWindow (XRCID("Button"));
    CPPUNIT_ASSERT_MESSAGE ("Window for button 'Button' not found", buttonWdw
            != NULL);
    swTst::WxGuiTestEventSimulationHelper::ClickButton (buttonWdw->GetId (),
            buttonWdw);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *buttonWdw = evtSimHlpTestPanel->FindWindow ("Button");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format ("button '%s'", m_buttonName.c_str ()));

    wxString buttonWdwVarName = emitter->MakeVarName (m_buttonName, "Wdw");

    wxString str;
    str << "wxWindow *" << buttonWdwVarName << " = " << containerVarName <<
            "->FindWindow (";
    if (m_isXRC) {
        
        str << "XRCID(\"" << m_buttonName << "\"));";

    } else {

        str << "\"" << m_buttonName << "\");";
    }
    emitter->AddCode (str);
    
    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Window for button '" << m_buttonName <<
            "' not found\", " << buttonWdwVarName << " != NULL);";
    emitter->AddCode (str);
    
    str.Clear ();
    str << "swTst::WxGuiTestEventSimulationHelper::ClickButton (" <<
            buttonWdwVarName << "->GetId (), " << buttonWdwVarName << ");";
    emitter->AddCode (str);
    
    str.Clear ();
    str << "swTst::WxGuiTestHelper::FlushEventQueue ();\n";
    emitter->AddCode (str);
}

} // End namespace swTst

