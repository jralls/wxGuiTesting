///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRSpinCtrlUpdateEvent.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRSpinCtrlUpdateEvent.h"
#endif

#include "CRSpinCtrlUpdateEvent.h"

#include <wx/spinctrl.h>

#include <wxGuiTest/CRWindowHierarchyHandler.h>
#include <wxGuiTest/CRCppEmitter.h>
#include "CRTextUpdateEvent.h"


using namespace wxTst;


CRSpinCtrlUpdateEvent::CRSpinCtrlUpdateEvent (wxEvent *event) :
    CRCapturedEvent (event)
{
    // Nothing to do
}


CRSpinCtrlUpdateEvent::~CRSpinCtrlUpdateEvent ()
{
    // Nothing to do
}


void CRSpinCtrlUpdateEvent::Process (CRCapturedEvent **pendingEvt)
{
    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    // If pending event is a text update event on the same (!) control, then
    // destroy it to prevent undesirable code emitting:
    if (*pendingEvt != NULL) {

        CRTextUpdateEvent *pendingTextUpdateEvt =
	    dynamic_cast< CRTextUpdateEvent * >(*pendingEvt);
        if (pendingTextUpdateEvt != NULL) {
	    if (m_event->GetEventObject () ==
		pendingTextUpdateEvt->GetEvent ()->GetEventObject ()) {

		delete *pendingEvt;
		*pendingEvt = NULL;
	    }
        }
    }

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);

    m_spinCtrlName = wdwEvtObject->GetName ();
    m_containerName = hierarchy->FindContainerName (wdwEvtObject);
    wxASSERT (!m_containerName.IsEmpty ());

    wxASSERT (m_event->IsCommandEvent ());
    wxCommandEvent *cmdEvt = wxDynamicCast (m_event, wxCommandEvent);
    wxASSERT (cmdEvt != NULL);
    m_spinCtrlValue = cmdEvt->GetInt ();
}


void CRSpinCtrlUpdateEvent::EmitCpp ()
{
    // Expected emitting (XRC):
    // Requires: "using sw::SpinCtrlDouble;"
    /*
    wxWindow *evtSimHlpTestPanel = wxWindow::FindWindowByName (
            "EvtSimHlpTestPanel");
    CPPUNIT_ASSERT_MESSAGE ("Container window for spin control 'SpinCtrlDbl' \
            not found", evtSimHlpTestPanel != NULL);
    wxWindow *spinCtrlDblWdw = evtSimHlpTestPanel->FindWindow (XRCID(
            "SpinCtrlDbl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for spin control 'SpinCtrlDbl' not found",
            spinCtrlDblWdw != NULL);
    sw::SpinCtrlDouble *spinCtrlDbl = wxDynamicCast (spinCtrlDblWdw,
            SpinCtrlDouble);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for spin control 'SpinCtrlDbl' \
            failed", spinCtrlDbl != NULL);
    wxTst::EventSimulationHelper::SetSpinCtrlDblValueWithoutEvent (
            spinCtrlDbl, 0.6);
    wxTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *spinCtrlDblWdw = evtSimHlpTestPanel->FindWindow ("SpinCtrlDbl");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format (_T("spin control '%s'"),
            m_spinCtrlName.c_str ()));

    wxString spinCtrlWdwVarName = emitter->MakeVarName(m_spinCtrlName, _T("Wdw"));

    wxString str;
    str << _T("wxWindow *") << spinCtrlWdwVarName << _T(" = ") << 
	containerVarName << _T("->FindWindow (");
    str << _T("_T(\"") << m_spinCtrlName << _T("\"));");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Window for spin control '") <<
	m_spinCtrlName << _T("' not found\", ") << spinCtrlWdwVarName <<
	_T(" != NULL);");
    emitter->AddCode (str);

    wxString spinCtrlVarName = emitter->MakeVarName (m_spinCtrlName);

    str.Clear ();
    str << _T("wxSpinCtrl *") << spinCtrlVarName << 
	_T(" = wxDynamicCast (") << spinCtrlWdwVarName << 
	_T(", wxSpinCtrl);");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Converting window for spin control '") <<
	m_spinCtrlName << _T("' failed\", ") << spinCtrlVarName << 
	_T(" != NULL);");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("wxTst::EventSimulationHelper::SetSpinCtrlValue (") <<
	spinCtrlVarName << _T(", ") << m_spinCtrlValue << _T(");");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("wxTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}


