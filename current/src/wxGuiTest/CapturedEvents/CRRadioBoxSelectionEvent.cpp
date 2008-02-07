///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRRadioBoxSelectionEvent.cpp
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
    #pragma implementation "CRRadioBoxSelectionEvent.h"
#endif

#include "CRRadioBoxSelectionEvent.h"

#include <wxGuiTest/CRWindowHierarchyHandler.h>
#include <wxGuiTest/CRCppEmitter.h>

using namespace wxTst;


CRRadioBoxSelectionEvent::CRRadioBoxSelectionEvent (wxEvent *event) :
CRCapturedEvent (event)
{
//    Nothing to do
}


CRRadioBoxSelectionEvent::~CRRadioBoxSelectionEvent ()
{
    // Nothing to do
}


void CRRadioBoxSelectionEvent::Process (CRCapturedEvent** WXUNUSED(pendingEvt))
{
    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);

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
    wxTst::EventSimulationHelper::SelectRadioBoxItem (radioBox,
            radioBoxSelection);
    wxTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *radioBoxWdw = evtSimHlpTestPanel->FindWindow ("RadioBox");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format (_T("radio box '%s'"), 
            m_radioBoxName.c_str ()));

    wxString radioBoxWdwVarName = emitter->MakeVarName (m_radioBoxName, 
            _T("Wdw"));

    wxString str;
    str << _T("wxWindow *") << radioBoxWdwVarName << _T(" = ") << 
            containerVarName << _T("->FindWindow (");
    str << _T("_T(\"") << m_radioBoxName << _T("\"));");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Window for radio box '") <<
            m_radioBoxName << _T("' not found\", ") << radioBoxWdwVarName <<
            _T(" != NULL);");
    emitter->AddCode (str);

    wxString radioBoxVarName = emitter->MakeVarName (m_radioBoxName);

    str.Clear ();
    str << _T("wxRadioBox *") << radioBoxVarName << _T(" = wxDynamicCast (") <<
            radioBoxWdwVarName << _T(", wxRadioBox);");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Converting window for radio box '") <<
            m_radioBoxName << _T("' failed\", ") << radioBoxVarName << 
            _T(" != NULL);");
    emitter->AddCode (str);
    
    wxString radioBoxSelTextVarName = emitter->MakeVarName (radioBoxVarName,
            _T("SelectionText"));

    str.Clear ();
    str << _T("const wxString ") << radioBoxSelTextVarName << _T(" (_(\"") <<
            m_radioBoxValue << _T("\"));");
    emitter->AddCode (str);

    wxString radioBoxSelVarName = emitter->MakeVarName (radioBoxVarName,
            _T("Selection"));

    str.Clear ();
    str << _T("int ") << radioBoxSelVarName << _T(" = ") << radioBoxVarName <<
            _T("->FindString (") << radioBoxSelTextVarName << _T(");");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("wxTst::EventSimulationHelper::SelectRadioBoxItem (") <<
            radioBoxVarName << _T(", ") << radioBoxSelVarName << _T(");");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("wxTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}

