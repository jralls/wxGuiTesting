///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/VtkWxGuiTesting/swVtkWxGuiTestHelper.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swVtkWxGuiTestHelper.h"
#endif

#include "swVtkWxGuiTestHelper.h"

#include "swWxVtkInteractorEventRecorder.h"

namespace swTst {


// Init single instance:
VtkWxGuiTestHelper *VtkWxGuiTestHelper::ms_instance = NULL;

// Set default settings for normal application logic:
bool VtkWxGuiTestHelper::ms_useWxVtkInteractionRecording = false;


VtkWxGuiTestHelper::VtkWxGuiTestHelper ()
{
    // Nothing to do
}


VtkWxGuiTestHelper::~VtkWxGuiTestHelper ()
{
    RecorderMap::iterator it;
    for (it = m_recorderMap.begin (); it != m_recorderMap.end (); it++) {

        (*it).second->Off ();
        (*it).second->Delete ();
    }
    m_recorderMap.clear ();
}


VtkWxGuiTestHelper * VtkWxGuiTestHelper::GetInstance ()
{
    if (ms_instance == NULL) {

        ms_instance = new VtkWxGuiTestHelper ();
    }
    return ms_instance;
}


void VtkWxGuiTestHelper::Destroy ()
{
    if (ms_instance != NULL) {

        delete ms_instance;
        ms_instance = NULL;
    }
}


void VtkWxGuiTestHelper::SetUseWxVtkInteractionRecording (bool use)
{
    ms_useWxVtkInteractionRecording = use;
}

    
bool VtkWxGuiTestHelper::GetUseWxVtkInteractionRecording ()
{
    return ms_useWxVtkInteractionRecording;
}


void VtkWxGuiTestHelper::RegisterForRecording (
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
        recorder->SetFileName (wxString::Format ("%s_wxVtk.rec", recorderId.c_str ()));
    }
    wxASSERT (recorder != NULL);
    recorder->AddInteractor (wxVtkId, wxVtkRwi);
}


WxVtkInteractorEventRecorder * VtkWxGuiTestHelper::GetWxVtkRecorder (
        const wxString &recorderId) const
{
    RecorderMap::const_iterator it;

    it = m_recorderMap.find (recorderId);
    return (it == m_recorderMap.end () ? NULL : (*it).second);
}


VtkWxGuiTestHelper::RecorderMap & VtkWxGuiTestHelper::GetWxVtkRecorders ()
{
    return m_recorderMap;
}

} // End namespace swTst
