///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRCheckBoxClickEvent.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRCheckBoxClickEvent.h"
#endif

#include "CRCheckBoxClickEvent.h"

#include <wxGuiTest/CRWindowHierarchyHandler.h>
#include <wxGuiTest/CRCppEmitter.h>

using namespace wxTst;


CRCheckBoxClickEvent::CRCheckBoxClickEvent (wxEvent *event) :
    CRCapturedEvent (event), m_isChecked(false)
{
//Nothing to do
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
    wxTst::WxGuiTestEventSimulationHelper::SetCheckboxState (checkbox, true);
    wxTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *checkboxWdw = evtSimHlpTestPanel->FindWindow ("Checkbox");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format (_T("check box '%s'"), m_checkBoxName.c_str ()));

    wxString checkBoxWdwVarName = emitter->MakeVarName (m_checkBoxName, _T("Wdw"));

    wxString str;
    str << _T("wxWindow *") << checkBoxWdwVarName << _T(" = ") << containerVarName <<
            _T("->FindWindow (");
    str << _T("_T(\"") << m_checkBoxName << _T("\"));");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Window for check box '") <<
            m_checkBoxName << _T("' not found\", ") <<
            checkBoxWdwVarName << _T(" != NULL);");
    emitter->AddCode (str);

    wxString checkBoxVarName = emitter->MakeVarName (m_checkBoxName);

    str.Clear ();
    str << _T("wxCheckBox *") << checkBoxVarName << _T(" = wxDynamicCast (") <<
            checkBoxWdwVarName << _T(", wxCheckBox);");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Converting window for check box '") <<
            m_checkBoxName << _T("' failed\", ") << checkBoxVarName << _T(" != NULL);");
    emitter->AddCode (str);

    wxString isCheckedBoolStr = m_isChecked ? _T("true") : _T("false");
    str.Clear ();
    str << _T("wxTst::WxGuiTestEventSimulationHelper::SetCheckboxState (") <<
            checkBoxVarName << _T(", ") << isCheckedBoolStr << _T(");");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("wxTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}

