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
            m_containerName, wxString::Format (_T("check box '%s'"), m_checkBoxName.c_str ()));

    wxString checkBoxWdwVarName = emitter->MakeVarName (m_checkBoxName, _T("Wdw"));

    wxString str;
    str << _T("wxWindow *") << checkBoxWdwVarName << _T(" = ") << containerVarName <<
            _T("->FindWindow (");
    if (m_isXRC) {
        
        str << _T("XRCID(\"") << m_checkBoxName << _T("\"));");

    } else {

	str << _T("\"") << m_checkBoxName << _T("\");");
    }
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Window for check box '") <<
	m_checkBoxName << _T("' not found\", ") << checkBoxWdwVarName <<
	_T(" != NULL);");
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
    str << _T("swTst::WxGuiTestEventSimulationHelper::SetCheckboxState (") <<
            checkBoxVarName << _T(", ") << isCheckedBoolStr << _T(");");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("swTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}

} // End namespace swTst

