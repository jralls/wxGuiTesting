///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/VtkWxGuiTesting/VtkGuiTestHelper.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "VtkGuiTestHelper.h"
#endif

#include <wxGuiTest/VtkwxGuiTest/VtkGuiTestHelper.h>

#include <wxGuiTest/VtkwxGuiTest/VtkInteractorEventRecorder.h>

namespace wxTst {


// Init single instance:
VtkGuiTestHelper *VtkGuiTestHelper::ms_instance = NULL;

// Set default settings for normal application logic:
bool VtkGuiTestHelper::ms_useWxVtkInteractionRecording = false;


VtkGuiTestHelper::VtkGuiTestHelper ()
{
    // Nothing to do
}


VtkGuiTestHelper::~VtkGuiTestHelper ()
{
    RecorderMap::iterator it;
    for (it = m_recorderMap.begin (); it != m_recorderMap.end (); it++) {

        (*it).second->Off ();
        (*it).second->Delete ();
    }
    m_recorderMap.clear ();
}


VtkGuiTestHelper * VtkGuiTestHelper::GetInstance ()
{
    if (ms_instance == NULL) {

        ms_instance = new VtkGuiTestHelper ();
    }
    return ms_instance;
}


void VtkGuiTestHelper::Destroy ()
{
    if (ms_instance != NULL) {

        delete ms_instance;
        ms_instance = NULL;
    }
}


void VtkGuiTestHelper::SetUseWxVtkInteractionRecording (bool use)
{
    ms_useWxVtkInteractionRecording = use;
}

    
bool VtkGuiTestHelper::GetUseWxVtkInteractionRecording ()
{
    return ms_useWxVtkInteractionRecording;
}


void VtkGuiTestHelper::RegisterForRecording (
        wxVTKRenderWindowInteractor *wxVtkRwi, const wxString &recorderId,
        const wxString &wxVtkId)
{
    if (!ms_useWxVtkInteractionRecording) {

        return;
    }

    WxVtkInteractorEventRecorder *recorder = NULL;
    recorder = this->GetWxVtkRecorder (recorderId);
    if (recorder == NULL) {

        recorder = WxVtkInteractorEventRecorder::New ();
        m_recorderMap[recorderId] = recorder;
        recorder->SetFileName (wxConvCurrent->cWX2MB (wxString::Format (
                _T("%s_wxVtk.rec"), recorderId.c_str ())));
    }
    wxASSERT (recorder != NULL);
    recorder->AddInteractor (wxVtkId, wxVtkRwi);
}


WxVtkInteractorEventRecorder * VtkGuiTestHelper::GetWxVtkRecorder (
        const wxString &recorderId) const
{
    RecorderMap::const_iterator it;

    it = m_recorderMap.find (recorderId);
    return (it == m_recorderMap.end () ? NULL : (*it).second);
}


VtkGuiTestHelper::RecorderMap & VtkGuiTestHelper::GetWxVtkRecorders ()
{
    return m_recorderMap;
}

} // End namespace wxTst
