///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRSpinCtrlUpdateEvent.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRSpinCtrlUpdateEvent.h"
#endif

#include "swCRSpinCtrlUpdateEvent.h"

#include "wx/spinctrl.h"

#include "swSpinCtrlDouble.h"

#include "swCRWindowHierarchyHandler.h"
#include "swCRCppEmitter.h"
#include "swCRTextUpdateEvent.h"

using sw::SpinCtrlDouble;

namespace swTst {


CRSpinCtrlUpdateEvent::CRSpinCtrlUpdateEvent (wxEvent *event) :
CRCapturedEvent (event)
{
    m_isDblType = false;
    m_isXRC = false;
}


CRSpinCtrlUpdateEvent::~CRSpinCtrlUpdateEvent ()
{
    // Nothing to do
}


void CRSpinCtrlUpdateEvent::Process (CRCapturedEvent **pendingEvt)
{
    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    // SpinCtrlDouble and wxSpinCtrl are very different internally:
    if (wdwEvtObject->IsKindOf (CLASSINFO(SpinCtrlDouble))) {

        m_isDblType = true;

    } else {

        wxASSERT (wdwEvtObject->IsKindOf (CLASSINFO(wxSpinCtrl)));
        m_isDblType = false;
    }

    // If pending event is a text update event on the same (!) control, then
    // destroy it to prevent undesirable code emitting:
    if (*pendingEvt != NULL) {

        CRTextUpdateEvent *pendingTextUpdateEvt =
                dynamic_cast< CRTextUpdateEvent * >(*pendingEvt);
        if (pendingTextUpdateEvt != NULL) {

            if (m_isDblType) {

                // The event object is not the spin control itself, but the
                // text control child:
                wxObject *textCtrlObj = pendingTextUpdateEvt->GetEvent ()->
                        GetEventObject ();
                wxASSERT (textCtrlObj != NULL);
                wxWindow *textCtrlWdw = wxDynamicCast (textCtrlObj, wxWindow);
                wxASSERT (textCtrlWdw != NULL);
                if (m_event->GetEventObject () == textCtrlWdw->GetParent ()) {

                    delete *pendingEvt;
                    *pendingEvt = NULL;
                }

            } else {

                if (m_event->GetEventObject () ==
                        pendingTextUpdateEvt->GetEvent ()->GetEventObject ()) {

                    delete *pendingEvt;
                    *pendingEvt = NULL;
                }
            }
        }
    }

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);

    if (hierarchy->FindXRCNode (wdwEvtObject, m_isDblType) != NULL) {

        m_isXRC = true;
    }
    m_spinCtrlName = wdwEvtObject->GetName ();
    m_containerName = hierarchy->FindContainerName (wdwEvtObject, m_isDblType);
    wxASSERT (!m_containerName.IsEmpty ());

    wxASSERT (m_event->IsCommandEvent ());
    wxCommandEvent *cmdEvt = wxDynamicCast (m_event, wxCommandEvent);
    wxASSERT (cmdEvt != NULL);
    if (m_isDblType) {

        bool isOk = cmdEvt->GetString ().ToDouble (&m_spinCtrlDblValue);
        wxASSERT (isOk);

    } else {

        m_spinCtrlValue = cmdEvt->GetInt ();
    }
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
    swTst::WxGuiTestEventSimulationHelper::SetSpinCtrlDblValueWithoutEvent (
            spinCtrlDbl, 0.6);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *spinCtrlDblWdw = evtSimHlpTestPanel->FindWindow ("SpinCtrlDbl");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format ("spin control '%s'",
            m_spinCtrlName.c_str ()));

    wxString spinCtrlWdwVarName = emitter->MakeVarName (m_spinCtrlName, "Wdw");

    wxString str;
    str << "wxWindow *" << spinCtrlWdwVarName << " = " << containerVarName <<
            "->FindWindow (";
    if (m_isXRC) {
        
        str << "XRCID(\"" << m_spinCtrlName << "\"));";

    } else {

        str << "\"" << m_spinCtrlName << "\");";
    }
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Window for spin control '" <<
            m_spinCtrlName << "' not found\", " << spinCtrlWdwVarName <<
            " != NULL);";
    emitter->AddCode (str);

    wxString spinCtrlVarName = emitter->MakeVarName (m_spinCtrlName);

    if (m_isDblType) {

        str.Clear ();
        str << "sw::SpinCtrlDouble *" << spinCtrlVarName << " = wxDynamicCast (" <<
                spinCtrlWdwVarName << ", SpinCtrlDouble);";
        emitter->AddCode (str);

    } else {

        str.Clear ();
        str << "wxSpinCtrl *" << spinCtrlVarName << " = wxDynamicCast (" <<
                spinCtrlWdwVarName << ", wxSpinCtrl);";
        emitter->AddCode (str);
    }

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Converting window for spin control '" <<
            m_spinCtrlName << "' failed\", " << spinCtrlVarName << " != NULL);";
    emitter->AddCode (str);

    if (m_isDblType) {

        str.Clear ();
        str << "swTst::WxGuiTestEventSimulationHelper::SetSpinCtrlDblValue (" <<
                spinCtrlVarName << ", " << m_spinCtrlDblValue << ");";
        emitter->AddCode (str);

    } else {

        str.Clear ();
        str << "swTst::WxGuiTestEventSimulationHelper::SetSpinCtrlValue (" <<
                spinCtrlVarName << ", " << m_spinCtrlValue << ");";
        emitter->AddCode (str);
    }

    str.Clear ();
    str << "swTst::WxGuiTestHelper::FlushEventQueue ();\n";
    emitter->AddCode (str);
}

} // End namespace swTst

