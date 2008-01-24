///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/VtkWxGuiTesting/CRVtkCaptureControl.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRVtkCaptureControl.h"
#endif

#include <wxGuiTest/VtkGuiTesting/CRVtkCaptureControl.h>

#include <vtkCamera.h>

#include <wx/xrc/xmlres.h>

#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/VtkGuiTesting/VtkWxGuiTestHelper.h>
#include <wxGuiTest/VtkGuiTesting/VtkInteractorEventRecorder.h>
#include <wxGuiTest/CRCppEmitter.h>

BEGIN_EVENT_TABLE(wxTst::CRVtkCaptureControl, CRCaptureControl)
    EVT_BUTTON( XRCID("ResetRecordingButton"), CRVtkCaptureControl::OnResetWxVtkRecording )
    EVT_BUTTON( XRCID("StartRecordingButton"), CRVtkCaptureControl::OnStartWxVtkRecording )
    EVT_BUTTON( XRCID("AddRecordingButton"), CRVtkCaptureControl::OnAddWxVtkRecording )
END_EVENT_TABLE()

namespace wxTst {


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
            wxTst::WxVtkInteractorEventRecorder *multiRecorder =
                    wxTst::VtkWxGuiTestHelper::GetInstance ()->GetWxVtkRecorder ("Multi");

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
				::wxLogTrace (_T("VtkWxwxGuiTest"), _T("Currently only one renderer per render window interactor is supported"));
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

            wxString recorderVarName = emitter->MakeVarName ((*it).first, _T("Recorder"));

            str << _T("wxTst::WxVtkInteractorEventRecorder *") << recorderVarName <<
                    _T(" = wxTst::VtkWxGuiTestHelper::GetInstance ()->GetWxVtkRecorder (_T(\"") <<
                    (*it).first << _T("\"));");
            emitter->AddCode (str);

            // Restore scene settings: size of render window, camera settings, ...
            wxString wdwStackVarName = emitter->MakeVarName (_T("wdwStack"));

            str.Clear ();
            str << _T("std::stack< wxWindow *, std::list< wxWindow * > > ") <<
                    wdwStackVarName << _T(";");
            emitter->AddCode (str);

            wxString wdwVarName = emitter->MakeVarName (_T("wdw"));

            str.Clear ();
            str << _T("wxWindow *") << wdwVarName << _T(" = NULL;");
            emitter->AddCode (str);

            const WxVtkInteractorEventRecorder::WxVtkMap & wxVtkMap =
                    wxVtkRec->GetWxVtkMap ();

            WxVtkInteractorEventRecorder::WxVtkMap::const_iterator it2;
            for (it2 = wxVtkMap.begin (); it2 != wxVtkMap.end (); it2++) {

                wxASSERT ((*it2).second->camera != NULL);

                // wx container position and sizes:
                wxString rwiVarName = emitter->MakeVarName ((*it2).first, _T("WxVtkRwi"));

                str.Clear ();
                str << _T("wxVTKRenderWindowInteractor * ") << rwiVarName <<
                        _T(" = ") << recorderVarName << _T("->GetInteractor (_T(\"") <<
                        (*it2).first << _T("\"));");
                emitter->AddCode (str);

                wxString rwiWdwVarName = emitter->MakeVarName ((*it2).first, _T("Wdw"));

                str.Clear ();
                str << _T("wxWindow *") << rwiWdwVarName << _T(" = ") << rwiVarName << _T(";");
                emitter->AddCode (str);

                str.Clear ();
                str << wdwVarName << _T(" = ") << rwiWdwVarName << _T(";");
                emitter->AddCode (str);

                str.Clear ();
                str << wdwStackVarName << _T(".push (") << wdwVarName << _T(");");
                emitter->AddCode (str);

                str.Clear ();
                str << _T("while (") << wdwVarName << _T("->GetParent () != NULL) {");
                emitter->AddCode (str);                

                emitter->AddCode (_T(""));

                str.Clear ();
                str << emitter->GetTab () << wdwVarName << _T(" = ") <<
                        wdwVarName << _T("->GetParent ();");
                emitter->AddCode (str);

                str.Clear ();
                str << emitter->GetTab () << wdwStackVarName << _T(".push (") <<
                        wdwVarName << _T(");");
                emitter->AddCode (str);

                emitter->AddCode (_T("}"));

                str.Clear ();
                str << wdwVarName << _T("->Move (") <<
                        (*it2).second->position.x << _T(", ") <<
                        (*it2).second->position.y << _T(");");
                emitter->AddCode (str);

                WxVtkInteractorEventRecorder::SizeList::const_iterator sizeIt =
                        (*it2).second->sizeList.begin ();
                while (sizeIt != (*it2).second->sizeList.end ()) {

                    str.Clear ();
                    str << wdwStackVarName << _T(".top ()->SetSize (") <<
                            (*sizeIt).GetWidth () << _T(", ") <<
                            (*sizeIt).GetHeight () << _T(");");
                    emitter->AddCode (str);

                    str.Clear ();
                    str << wdwStackVarName << _T(".pop ();");
                    emitter->AddCode (str);

                    sizeIt++;
                }

                str.Clear ();
                str << _T("wxASSERT (") << wdwStackVarName << _T(".empty ());");
                emitter->AddCode (str);

                // Camera:
                wxString renderersVarName = emitter->MakeVarName (_T("renderers"));

                str.Clear ();
                str << _T("vtkRendererCollection *") << renderersVarName <<
                        _T(" = ") << rwiVarName << _T("->GetRenderWindow ()->GetRenderers ();");
                emitter->AddCode (str);

                str.Clear ();
                str << _T("wxASSERT_MSG (") << renderersVarName << _T("->GetNumberOfItems () > 0, _T(\"At least one renderer must exist in each render window; and only the first one is fully supported.\"));");
                emitter->AddCode (str);

                str.Clear ();
                str << _T("if (") << renderersVarName << _T("->GetNumberOfItems () != 1) {");
                emitter->AddCode (str);

                str.Clear ();
                str << emitter->GetTab () << _T("::wxLogTrace (_T(\"VtkWxwxGuiTest\"), _T(\"Currently only one renderer per render window interactor is supported\"));");
                emitter->AddCode (str);

                str.Clear ();
                str << _T("}");
                emitter->AddCode (str);

                wxString cameraVarName = emitter->MakeVarName (_T("camera"));

                str.Clear ();
                str << _T("vtkCamera *") << cameraVarName << _T(" = ") <<
                        renderersVarName << _T("->GetFirstRenderer ()->GetActiveCamera ();");
                emitter->AddCode (str);

                str.Clear ();
                str << cameraVarName << _T("->SetParallelScale (") <<
                        (*it2).second->camera->GetParallelScale () << _T(");");
                emitter->AddCode (str);

                str.Clear ();
                str << cameraVarName << _T("->SetViewAngle (") <<
                        (*it2).second->camera->GetViewAngle () << _T(");");
                emitter->AddCode (str);

                double array[3];

                (*it2).second->camera->GetClippingRange (array);
                str.Clear ();
                str << cameraVarName << _T("->SetClippingRange (") << array[0] <<
                        _T(", ") << array[1] << _T(");");
                emitter->AddCode (str);

                (*it2).second->camera->GetFocalPoint (array);
                str.Clear ();
                str << cameraVarName << _T("->SetFocalPoint (") << array[0] <<
                        _T(", ") << array[1] << _T(", ") << array[2] << _T(");");
                emitter->AddCode (str);

                (*it2).second->camera->GetPosition (array);
                str.Clear ();
                str << cameraVarName << _T("->SetPosition (") << array[0] <<
                        _T(", ") << array[1] << _T(", ") << array[2] << _T(");");
                emitter->AddCode (str);

                (*it2).second->camera->GetViewUp (array);
                str.Clear ();
                str << cameraVarName << _T("->SetViewUp (") << array[0] <<
                        _T(", ") << array[1] << _T(", ") << array[2] << _T(");");
                emitter->AddCode (str);
            }

            str.Clear ();
            str << recorderVarName << _T("->ReadFromInputStringOn ();");
            emitter->AddCode (str);

            str.Clear ();
            str << recorderVarName << _T("->SetInputString (");
            emitter->AddCode (str);

            emitter->AddVerbatimStringWithLineBreaks (
                    wxVtkRec->GetRecordingAsEmitString (emitter->GetTab ()).RemoveLast ());

            str.Clear ();
            str << _T(");");
            emitter->AddCode (str);

            str.Clear ();
            str << recorderVarName << _T("->Play ();");
            emitter->AddCode (str);
        }
    }
}

} // End namespace wxTst
