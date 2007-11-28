///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/VtkWxGuiTesting/swCRVtkCaptureControl.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRVtkCaptureControl.h"
#endif

#include "swCRVtkCaptureControl.h"

#include "vtkCamera.h"

#include "wx/xrc/xmlres.h"

#include "swWxGuiTestHelper.h"
#include "swVtkWxGuiTestHelper.h"
#include "swWxVtkInteractorEventRecorder.h"
#include "swCRCppEmitter.h"

BEGIN_EVENT_TABLE(swTst::CRVtkCaptureControl, CRCaptureControl)
    EVT_BUTTON( XRCID("ResetRecordingButton"), CRVtkCaptureControl::OnResetWxVtkRecording )
    EVT_BUTTON( XRCID("StartRecordingButton"), CRVtkCaptureControl::OnStartWxVtkRecording )
    EVT_BUTTON( XRCID("AddRecordingButton"), CRVtkCaptureControl::OnAddWxVtkRecording )
END_EVENT_TABLE()

namespace swTst {


CRVtkCaptureControl::CRVtkCaptureControl (wxDialog *dialog) :
CRCaptureControl (dialog)
{
    // Nothing to do
}


CRVtkCaptureControl::~CRVtkCaptureControl ()
{
    // Nothing to do
}


void CRVtkCaptureControl::OnResetWxVtkRecording (wxCommandEvent &event)
{
    VtkWxGuiTestHelper::RecorderMap::iterator it;
    VtkWxGuiTestHelper::RecorderMap &recorders =
            VtkWxGuiTestHelper::GetInstance ()->GetWxVtkRecorders ();
    
    for (it = recorders.begin (); it != recorders.end (); it++) {

        (*it).second->ResetRecording ();
    }
}


void CRVtkCaptureControl::OnStartWxVtkRecording (wxCommandEvent &event)
{
    VtkWxGuiTestHelper::RecorderMap::iterator it;
    VtkWxGuiTestHelper::RecorderMap &recorders =
            VtkWxGuiTestHelper::GetInstance ()->GetWxVtkRecorders ();
    
    for (it = recorders.begin (); it != recorders.end (); it++) {

        (*it).second->On ();
        (*it).second->Record ();
    }
}


void CRVtkCaptureControl::OnAddWxVtkRecording (wxCommandEvent &event)
{
    VtkWxGuiTestHelper::RecorderMap &recorders =
            VtkWxGuiTestHelper::GetInstance ()->GetWxVtkRecorders ();

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    VtkWxGuiTestHelper::RecorderMap::iterator it;
    for (it = recorders.begin (); it != recorders.end (); it++) {

        WxVtkInteractorEventRecorder *wxVtkRec = (*it).second;
        wxVtkRec->Stop ();
        wxVtkRec->Off ();

        if (!wxVtkRec->IsEmptyRecording ()) {

            /*
            swTst::WxVtkInteractorEventRecorder *multiRecorder =
                    swTst::VtkWxGuiTestHelper::GetInstance ()->GetWxVtkRecorder ("Multi");

            std::stack< wxWindow *, std::list< wxWindow * > > wdwStack;
            wxWindow *wdw = NULL;

            //FOREACH
            wxVTKRenderWindowInteractor * view2DxWxVtkRwi = multiRecorder->GetInteractor ("2Dx");
            wxWindow *view2DxWdw = view2DxWxVtkRwi;
            wdw = view2DxWdw;
            wdwStack.push (wdw);
            while (wdw->GetParent () != NULL) {

                wdw = wdw->GetParent ();
                wdwStack.push (wdw);
            }
            wdw->Move (123, 456);
            // Another FOR
            wdwStack.top ()->SetSize (123, 456);
            wdwStack.pop ();
            wdwStack.top ()->SetSize (123, 456);
            wdwStack.pop ();
            // ...
            wxASSERT (wdwStack.empty ());
            // Camera
            vtkRendererCollection *renderers = view2DxWxVtkRwi->GetRenderWindow ()->GetRenderers ();
            wxASSERT_MSG (renderers->GetNumberOfItems () > 0,
                    "At least one renderer must exist in each render window; and only the first one is fully supported.");
			if (renderers->GetNumberOfItems () != 1) {
				::wxLogTrace (_T("VtkWxGuiTesting"), _T("Currently only one renderer per render window interactor is supported"));
			}
            vtkCamera *camera = renderers->GetFirstRenderer ()->GetActiveCamera ();
            camera->SetParallelScale (1.23);
            camera->SetViewAngle (1.23);
            camera->SetClippingRange (1.23, 4.56);
            camera->SetFocalPoint (1.23, 4.56, 7.89);
            camera->SetPosition (1.23, 4.56, 7.89);
            camera->SetViewUp (1.23, 4.56, 7.89);
            //END FOREACH

            multiRecorder->ReadFromInputStringOn ();
            multiRecorder->SetInputString ("...");// record file content
            multiRecorder->Play ();
            */

            wxString str;

            wxString recorderVarName = emitter->MakeVarName ((*it).first, "Recorder");

            str << "swTst::WxVtkInteractorEventRecorder *" << recorderVarName <<
                    " = swTst::VtkWxGuiTestHelper::GetInstance ()->GetWxVtkRecorder (\"" <<
                    (*it).first << "\");";
            emitter->AddCode (str);

            // Restore scene settings: size of render window, camera settings, ...
            wxString wdwStackVarName = emitter->MakeVarName ("wdwStack");

            str.Clear ();
            str << "std::stack< wxWindow *, std::list< wxWindow * > > " <<
                    wdwStackVarName << ";";
            emitter->AddCode (str);

            wxString wdwVarName = emitter->MakeVarName ("wdw");

            str.Clear ();
            str << "wxWindow *" << wdwVarName << " = NULL;";
            emitter->AddCode (str);

            const WxVtkInteractorEventRecorder::WxVtkMap & wxVtkMap =
                    wxVtkRec->GetWxVtkMap ();

            WxVtkInteractorEventRecorder::WxVtkMap::const_iterator it;
            for (it = wxVtkMap.begin (); it != wxVtkMap.end (); it++) {

                wxASSERT ((*it).second->camera != NULL);

                // wx container position and sizes:
                wxString rwiVarName = emitter->MakeVarName ((*it).first, "WxVtkRwi");

                str.Clear ();
                str << "wxVTKRenderWindowInteractor * " << rwiVarName <<
                        " = " << recorderVarName << "->GetInteractor (\"" <<
                        (*it).first << "\");";
                emitter->AddCode (str);

                wxString rwiWdwVarName = emitter->MakeVarName ((*it).first, "Wdw");

                str.Clear ();
                str << "wxWindow *" << rwiWdwVarName << " = " << rwiVarName << ";";
                emitter->AddCode (str);

                str.Clear ();
                str << wdwVarName << " = " << rwiWdwVarName << ";";
                emitter->AddCode (str);

                str.Clear ();
                str << wdwStackVarName << ".push (" << wdwVarName << ");";
                emitter->AddCode (str);

                str.Clear ();
                str << "while (" << wdwVarName << "->GetParent () != NULL) {";
                emitter->AddCode (str);                

                emitter->AddCode ("");

                str.Clear ();
                str << emitter->GetTab () << wdwVarName << " = " <<
                        wdwVarName << "->GetParent ();";
                emitter->AddCode (str);

                str.Clear ();
                str << emitter->GetTab () << wdwStackVarName << ".push (" <<
                        wdwVarName << ");";
                emitter->AddCode (str);

                emitter->AddCode ("}");

                str.Clear ();
                str << wdwVarName << "->Move (" <<
                        (*it).second->position.x << ", " <<
                        (*it).second->position.y << ");";
                emitter->AddCode (str);

                WxVtkInteractorEventRecorder::SizeList::const_iterator sizeIt =
                        (*it).second->sizeList.begin ();
                while (sizeIt != (*it).second->sizeList.end ()) {

                    str.Clear ();
                    str << wdwStackVarName << ".top ()->SetSize (" <<
                            (*sizeIt).GetWidth () << ", " <<
                            (*sizeIt).GetHeight () << ");";
                    emitter->AddCode (str);

                    str.Clear ();
                    str << wdwStackVarName << ".pop ();";
                    emitter->AddCode (str);

                    sizeIt++;
                }

                str.Clear ();
                str << "wxASSERT (" << wdwStackVarName << ".empty ());";
                emitter->AddCode (str);

                // Camera:
                wxString renderersVarName = emitter->MakeVarName ("renderers");

                str.Clear ();
                str << "vtkRendererCollection *" << renderersVarName <<
                        " = " << rwiVarName << "->GetRenderWindow ()->GetRenderers ();";
                emitter->AddCode (str);

                str.Clear ();
                str << "wxASSERT_MSG (" << renderersVarName << "->GetNumberOfItems () > 0, \"At least one renderer must exist in each render window; and only the first one is fully supported.\");";
                emitter->AddCode (str);

                str.Clear ();
                str << "if (" << renderersVarName << "->GetNumberOfItems () != 1) {";
                emitter->AddCode (str);

                str.Clear ();
                str << emitter->GetTab () << "::wxLogTrace (_T(\"VtkWxGuiTesting\"), _T(\"Currently only one renderer per render window interactor is supported\"));";
                emitter->AddCode (str);

                str.Clear ();
                str << "}";
                emitter->AddCode (str);

                wxString cameraVarName = emitter->MakeVarName ("camera");

                str.Clear ();
                str << "vtkCamera *" << cameraVarName << " = " <<
                        renderersVarName << "->GetFirstRenderer ()->GetActiveCamera ();";
                emitter->AddCode (str);

                str.Clear ();
                str << cameraVarName << "->SetParallelScale (" <<
                        (*it).second->camera->GetParallelScale () << ");";
                emitter->AddCode (str);

                str.Clear ();
                str << cameraVarName << "->SetViewAngle (" <<
                        (*it).second->camera->GetViewAngle () << ");";
                emitter->AddCode (str);

                double array[3];

                (*it).second->camera->GetClippingRange (array);
                str.Clear ();
                str << cameraVarName << "->SetClippingRange (" << array[0] <<
                        ", " << array[1] << ");";
                emitter->AddCode (str);

                (*it).second->camera->GetFocalPoint (array);
                str.Clear ();
                str << cameraVarName << "->SetFocalPoint (" << array[0] <<
                        ", " << array[1] << ", " << array[2] << ");";
                emitter->AddCode (str);

                (*it).second->camera->GetPosition (array);
                str.Clear ();
                str << cameraVarName << "->SetPosition (" << array[0] <<
                        ", " << array[1] << ", " << array[2] << ");";
                emitter->AddCode (str);

                (*it).second->camera->GetViewUp (array);
                str.Clear ();
                str << cameraVarName << "->SetViewUp (" << array[0] <<
                        ", " << array[1] << ", " << array[2] << ");";
                emitter->AddCode (str);
            }

            str.Clear ();
            str << recorderVarName << "->ReadFromInputStringOn ();";
            emitter->AddCode (str);

            str.Clear ();
            str << recorderVarName << "->SetInputString (";
            emitter->AddCode (str);

            emitter->AddVerbatimStringWithLineBreaks (
                    wxVtkRec->GetRecordingAsEmitString (emitter->GetTab ()).RemoveLast ());

            str.Clear ();
            str << ");";
            emitter->AddCode (str);

            str.Clear ();
            str << recorderVarName << "->Play ();";
            emitter->AddCode (str);
        }
    }
}

} // End namespace swTst
