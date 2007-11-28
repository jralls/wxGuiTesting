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
            m_containerName, wxString::Format (_T("button '%s'"), m_buttonName.c_str ()));

    wxString buttonWdwVarName = emitter->MakeVarName (m_buttonName, _T("Wdw"));

    wxString str;
    str << _T("wxWindow *") << buttonWdwVarName << _T(" = ") << containerVarName <<
            _T("->FindWindow (");
    if (m_isXRC) {
        
        str << _T("XRCID(\"") << m_buttonName << _T("\"));");

    } else {

        str << _T("\"") << m_buttonName << _T("\");");
    }
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Window for button '") << m_buttonName <<
	_T("' not found\", ") << buttonWdwVarName << _T(" != NULL);");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("swTst::WxGuiTestEventSimulationHelper::ClickButton (") <<
            buttonWdwVarName << _T("->GetId (), ") << buttonWdwVarName << _T(");");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("swTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}

} // End namespace swTst

