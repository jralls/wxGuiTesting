///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRSliderUpdateEvent.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRSliderUpdateEvent.h"
#endif

#include "CRSliderUpdateEvent.h"

#include <wxGuiTest/CRWindowHierarchyHandler.h>
#include <wxGuiTest/CRCppEmitter.h>

using namespace wxTst;


CRSliderUpdateEvent::CRSliderUpdateEvent (wxEvent *event) :
CRCapturedEvent (event)
{
//    Nothing to do
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

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance();
    wxASSERT (hierarchy != NULL);
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
    wxTst::EventSimulationHelper::SetSliderValue (slider, 30);
    wxTst::WxGuiTestHelper::FlushEventQueue ();
    */
    // Or non-XRC:
    /*
    ...
    wxWindow *sliderWdw = evtSimHlpTestPanel->FindWindow ("Slider");
    ...
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString containerVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format (_T("slider '%s'"),
            m_sliderName.c_str ()));

    wxString sliderWdwVarName = emitter->MakeVarName (m_sliderName, _T("Wdw"));

    wxString str;
    str << _T("wxWindow *") << sliderWdwVarName << _T(" = ") << 
            containerVarName << _T("->FindWindow (");
    str << _T("_T(\"") << m_sliderName << _T("\"));");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Window for slider '") <<
            m_sliderName << _T("' not found\", ") << sliderWdwVarName <<
            _T(" != NULL);");
    emitter->AddCode (str);

    wxString sliderVarName = emitter->MakeVarName (m_sliderName);

    str.Clear ();
    str << _T("wxSlider *") << sliderVarName << _T(" = wxDynamicCast (") <<
            sliderWdwVarName << _T(", wxSlider);");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Converting window for slider '") <<
            m_sliderName << _T("' failed\", ") << sliderVarName << _T(" != NULL);");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("wxTst::EventSimulationHelper::SetSliderValue (") <<
            sliderVarName << _T(", ") << m_sliderValue << _T(");");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("wxTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}
