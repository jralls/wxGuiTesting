///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRTextUpdateEvent.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRTextUpdateEvent.h"
#endif

#include "swCRTextUpdateEvent.h"

#include "swSpinCtrlDouble.h"

#include "swCRWindowHierarchyHandler.h"
#include "swCRCppEmitter.h"
#include "swWxGuiTestEventSimulationHelper.h"

using sw::SpinCtrlDouble;

namespace swTst {


CRTextUpdateEvent::CRTextUpdateEvent (wxEvent *event) :
CRCapturedEvent (event)
{
    m_isIrrelevant = false;
    m_isXRC = false;
}


CRTextUpdateEvent::~CRTextUpdateEvent ()
{
    // Nothing to do
}


bool CRTextUpdateEvent::IsPending () const
{
    return true;
}


bool CRTextUpdateEvent::IsIrrelevant () const
{
    return m_isIrrelevant;
}


void CRTextUpdateEvent::Process (CRCapturedEvent **pendingEvt)
{
    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    // Text updates of double typed spin controls are irrelevant:
    if (wdwEvtObject->GetParent () != NULL) {

        if (wdwEvtObject->GetParent ()->IsKindOf (CLASSINFO(SpinCtrlDouble))) {

            m_isIrrelevant = true;
            return;

        } else if (wdwEvtObject->IsKindOf (CLASSINFO(wxSpinCtrl))) {
        
            if (!WxGuiTestEventSimulationHelper::IsSettingSpinCtrlValue ()) {

                m_isIrrelevant = true;
                // Standard wxSpinCtrl do NOT trigger a spin control event when
                // text, i.e. the integer value, is entered -> simulate spin
                // control update event:
                wxSpinCtrl *spinCtrl = wxDynamicCast (wdwEvtObject, wxSpinCtrl);
                wxASSERT (spinCtrl != NULL);
                WxGuiTestEventSimulationHelper::SetSpinCtrlValue (spinCtrl,
                        spinCtrl->GetValue ());
            }
            return;
        }
    }

    // If pending event is another text update event on the same (!) control,
    // then destroy it to prevent undesirable code emitting:
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

    if (hierarchy->FindXRCNode (wdwEvtObject) != NULL) {

        m_isXRC = true;
    }
    m_textCtrlName = wdwEvtObject->GetName ();
    m_containerName = hierarchy->FindContainerName (wdwEvtObject);
    wxASSERT (!m_containerName.IsEmpty ());

    wxASSERT (m_event->IsCommandEvent ());
    wxCommandEvent *cmdEvt = wxDynamicCast (m_event, wxCommandEvent);
    wxASSERT (cmdEvt != NULL);
    m_textCtrlValue = cmdEvt->GetString ();
}


void CRTextUpdateEvent::EmitCpp ()
{
    // Expected emitting (XRC):
    /*
    wxWindow *evtSimHlpTestPanel = wxWindow::FindWindowByName
            ("EvtSimHlpTestPanel");
    CPPUNIT_ASSERT_MESSAGE ("Container window for text control 'TextCtrl' not \
            found", evtSimHlpTestPanel != NULL);
    wxWindow *textCtrlWdw = evtSimHlpTestPanel->FindWindow (XRCID("TextCtrl"));
    CPPUNIT_ASSERT_MESSAGE ("Window for text control 'TextCtrl' not found",
            textCtrlWdw != NULL);
    wxTextCtrl *textCtrl = wxDynamicCast (textCtrlWdw, wxTextCtrl);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for text control 'TextCtrl' \
            failed", textCtrl != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetTextCtrlValue (textCtrl,
            "abc");
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *textCtrlWdw = evtSimHlpTestPanel->FindWindow ("TextControl");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format ("text control '%s'",
            m_textCtrlName.c_str ()));

    wxString textCtrlWdwVarName = emitter->MakeVarName (m_textCtrlName, "Wdw");

    wxString str;
    str << "wxWindow *" << textCtrlWdwVarName << " = " << containerVarName <<
            "->FindWindow (";
    if (m_isXRC) {
        
        str << "XRCID(\"" << m_textCtrlName << "\"));";

    } else {

        str << "\"" << m_textCtrlName << "\");";
    }
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Window for text control '" <<
            m_textCtrlName << "' not found\", " << textCtrlWdwVarName <<
            " != NULL);";
    emitter->AddCode (str);

    wxString textCtrlVarName = emitter->MakeVarName (m_textCtrlName);

    str.Clear ();
    str << "wxTextCtrl *" << textCtrlVarName << " = wxDynamicCast (" <<
            textCtrlWdwVarName << ", wxTextCtrl);";
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Converting window for text control '" <<
            m_textCtrlName << "' failed\", " << textCtrlVarName << " != NULL);";
    emitter->AddCode (str);

    str.Clear ();
    str << "swTst::WxGuiTestEventSimulationHelper::SetTextCtrlValue (" <<
            textCtrlVarName << ", \"" << this->GetEscaped (m_textCtrlValue) <<
            "\");";
    emitter->AddCode (str);

    str.Clear ();
    str << "swTst::WxGuiTestHelper::FlushEventQueue ();\n";
    emitter->AddCode (str);
}


wxString CRTextUpdateEvent::GetEscaped (const wxString &str) const
{
    wxString escaped;

    for (int i = 0; i < str.Length (); i++) {

        if (str[i] == 92) { // '\'

            escaped.Append ("\\\\");

        } else {

            escaped.Append (str[i]);
        }
    }

    return escaped;
}

} // End namespace swTst

