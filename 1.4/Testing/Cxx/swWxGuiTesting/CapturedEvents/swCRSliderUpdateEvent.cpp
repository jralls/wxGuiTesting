///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRSliderUpdateEvent.cpp
// Author:      Reinhold F�reder
// Created:     2004
// Copyright:   (c) 2005 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRSliderUpdateEvent.h"
#endif

#include "swCRSliderUpdateEvent.h"

#include "swCRWindowHierarchyHandler.h"
#include "swCRCppEmitter.h"

namespace swTst {


CRSliderUpdateEvent::CRSliderUpdateEvent (wxEvent *event) :
CRCapturedEvent (event)
{
    m_isXRC = false;
}


CRSliderUpdateEvent::~CRSliderUpdateEvent ()
{
    // Nothing to do
}


bool CRSliderUpdateEvent::IsPending () const
{
    return true;
}


void CRSliderUpdateEvent::Process (CRCapturedEvent **pendingEvt)
{
    // If pending event is another slider update event on the same (!) control,
    // then destroy it to prevent undesirable code emitting:
    if (*pendingEvt != NULL) {

        CRSliderUpdateEvent *pendingSliderUpdateEvt =
                dynamic_cast< CRSliderUpdateEvent * >(*pendingEvt);
        if (pendingSliderUpdateEvt != NULL) {

            if (m_event->GetEventObject () ==
                    pendingSliderUpdateEvt->GetEvent ()->GetEventObject ()) {

                delete *pendingEvt;
                *pendingEvt = NULL;
            }
        }
    }

    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);

    if (hierarchy->FindXRCNode (wdwEvtObject) != NULL) {

        m_isXRC = true;
    }
    m_sliderName = wdwEvtObject->GetName ();
    m_containerName = hierarchy->FindContainerName (wdwEvtObject);
    wxASSERT (!m_containerName.IsEmpty ());

    wxASSERT (m_event->IsCommandEvent ());
    wxCommandEvent *cmdEvt = wxDynamicCast (m_event, wxCommandEvent);
    wxASSERT (cmdEvt != NULL);
    m_sliderValue = cmdEvt->GetInt ();
}


void CRSliderUpdateEvent::EmitCpp ()
{
    // Expected emitting (XRC):
    /*
    wxWindow *evtSimHlpTestPanel = wxWindow::FindWindowByName (
            "EvtSimHlpTestPanel");
    CPPUNIT_ASSERT_MESSAGE ("Container window for slider 'Slider' not found",
            evtSimHlpTestPanel != NULL);
    wxWindow *sliderWdw = evtSimHlpTestPanel->FindWindow (XRCID("Slider"));
    CPPUNIT_ASSERT_MESSAGE ("Window for slider 'Slider' not found", sliderWdw
            != NULL);
    wxSlider *slider = wxDynamicCast (sliderWdw, wxSlider);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for slider 'Slider' failed",
            slider != NULL);
    swTst::WxGuiTestEventSimulationHelper::SetSliderValue (slider, 30);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *sliderWdw = evtSimHlpTestPanel->FindWindow ("Slider");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format ("slider '%s'",
            m_sliderName.c_str ()));

    wxString sliderWdwVarName = emitter->MakeVarName (m_sliderName, "Wdw");

    wxString str;
    str << "wxWindow *" << sliderWdwVarName << " = " << containerVarName <<
            "->FindWindow (";
    if (m_isXRC) {
        
        str << "XRCID(\"" << m_sliderName << "\"));";

    } else {

        str << "\"" << m_sliderName << "\");";
    }
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Window for slider '" <<
            m_sliderName << "' not found\", " << sliderWdwVarName <<
            " != NULL);";
    emitter->AddCode (str);

    wxString sliderVarName = emitter->MakeVarName (m_sliderName);

    str.Clear ();
    str << "wxSlider *" << sliderVarName << " = wxDynamicCast (" <<
            sliderWdwVarName << ", wxSlider);";
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Converting window for slider '" <<
            m_sliderName << "' failed\", " << sliderVarName << " != NULL);";
    emitter->AddCode (str);

    str.Clear ();
    str << "swTst::WxGuiTestEventSimulationHelper::SetSliderValue (" <<
            sliderVarName << ", " << m_sliderValue << ");";
    emitter->AddCode (str);

    str.Clear ();
    str << "swTst::WxGuiTestHelper::FlushEventQueue ();\n";
    emitter->AddCode (str);
}

} // End namespace swTst

