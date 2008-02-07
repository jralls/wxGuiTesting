///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRButtonClickEvent.cpp
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
    #pragma implementation "CRButtonClickEvent.h"
#endif

#include "CRButtonClickEvent.h"

#include <wxGuiTest/CRWindowHierarchyHandler.h>
#include <wxGuiTest/CRCppEmitter.h>

using namespace wxTst;


CRButtonClickEvent::CRButtonClickEvent (wxEvent *event) :
CRCapturedEvent (event)
{
//    Nothing to do
}


CRButtonClickEvent::~CRButtonClickEvent ()
{
    // Nothing to do
}


void CRButtonClickEvent::Process (CRCapturedEvent** WXUNUSED(pendingEvt))
{
    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance();
    wxASSERT (hierarchy != NULL);
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
    wxTst::EventSimulationHelper::ClickButton (buttonWdw->GetId (),
            buttonWdw);
    wxTst::WxGuiTestHelper::FlushEventQueue ();
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
    str << _T("_T(\"") << m_buttonName << _T("\"));");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Window for button '") << m_buttonName <<
            _T("' not found\", ") << buttonWdwVarName << _T(" != NULL);");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("wxTst::EventSimulationHelper::ClickButton (") <<
            buttonWdwVarName << _T("->GetId (), ") << buttonWdwVarName << _T(");");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("wxTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}

