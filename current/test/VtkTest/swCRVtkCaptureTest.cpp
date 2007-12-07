///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/VtkWxGuiTesting/CppTest/swCRVtkCaptureTest.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRVtkCaptureTest.h"
#endif

#include "swCRVtkCaptureTest.h"

#include <stack>
#include <string>

#include <wx/xrc/xmlres.h>
#include <wx/frame.h>
#include <wx/treectrl.h>
#include <wx/statline.h>

#include <vtkXMLPolyDataReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRendererCollection.h>
#include <vtkCamera.h>

#include <wxGuiTest/swWxGuiTestHelper.h>
#include <wxGuiTest/swWxGuiTestEventSimulationHelper.h>
#include <wxGuiTest/swWxGuiTestTimedDialogEnder.h>
#include <wxGuiTest/swWxGuiTestTempInteractive.h>

#include <wxGuiTest/VtkGuiTesting/swCRVtkCapture.h>
#include <wxGuiTest/VtkGuiTesting/swVtkWxGuiTestHelper.h>
#include <wxGuiTest/VtkGuiTesting/swWxVtkInteractorEventRecorder.h>

#include <wxGuiTest/Config/swConfigManager.h>
#include <wxGuiTest/Config/swConfig.h>
#include <wxGuiTest/Widget/swSpinCtrlDouble.h>

#include <wxVTKRenderWindowInteractor.h>

namespace {
    const wxString xrcDir(_T(XRCDIR));
};

namespace swTst {


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( CRVtkCaptureTest, "WxGuiTest" );


CRVtkCaptureTest::CRVtkCaptureTest ()
{
    m_iren1 = NULL;
    m_iren2 = NULL;
}


void CRVtkCaptureTest::setUp ()
{
    wxString xrcPath (xrcDir + wxString(_T("/EvtSimHlpTest_wdr.xrc")));
    std::string vtkFilename(VTKDIR);
    vtkFilename += "/hipStl.vtp";

    wxXmlResource::Get()->InitAllHandlers();
    wxXmlResource::Get()->Load (xrcPath);

    wxFrame *frame = new wxFrame (NULL, -1, _T("EvtSimHlpFrame"));

    wxMenuBar *menuBar = wxXmlResource::Get ()->LoadMenuBar (wxT("MenuBar"));
    wxASSERT (menuBar != NULL);
    frame->SetMenuBar (menuBar);

    wxBoxSizer *topsizer = new wxBoxSizer (wxHORIZONTAL);
    wxPanel *panel = wxXmlResource::Get ()->LoadPanel (frame, _T("EvtSimHlpTestPanel"));
    wxASSERT (panel != NULL);
    // Include the unknown double spin control:
    sw::SpinCtrlDouble *spinCtrl = new sw::SpinCtrlDouble (frame,
            -1,
            _T(""),
            wxDefaultPosition,
            wxSize (80, 21),
            wxNO_BORDER,
            0.00000,
            9999.99999,
            0.5,
            0.1);
    spinCtrl->SetDigits (5, false);
    wxXmlResource::Get ()->AttachUnknownControl (_T("SpinCtrlDbl"), spinCtrl, frame);

    wxTreeCtrl *treeCtrl = XRCCTRL (*frame, "TreeCtrl", wxTreeCtrl);
    wxTreeItemId root = treeCtrl->AddRoot (_T("Root"));
    wxTreeItemId item = treeCtrl->AppendItem (root, _T("item"));
    wxTreeItemId item2 = treeCtrl->AppendItem (root, _T("item2"));

    // VTK stuff:
	vtkXMLPolyDataReader *reader = vtkXMLPolyDataReader::New ();
	reader->SetFileName (vtkFilename.c_str());
	vtkPolyDataMapper *mapper = vtkPolyDataMapper::New ();
	mapper->SetInput (reader->GetOutput ());
    reader->Delete ();
	vtkActor *actor = vtkActor::New ();
    actor->SetMapper (mapper);
    mapper->Delete ();

    m_iren1 = new wxVTKRenderWindowInteractor (frame, -1);
    m_iren1->UseCaptureMouseOn ();
    VtkWxGuiTestHelper::GetInstance ()->RegisterForRecording (m_iren1, _T("Multi"),
            _T("iren1"));

    m_iren2 = new wxVTKRenderWindowInteractor (frame, -1);
    m_iren2->UseCaptureMouseOn ();
    VtkWxGuiTestHelper::GetInstance ()->RegisterForRecording (m_iren2, _T("Multi"),
            _T("iren2"));

	vtkRenderer *renderer1 = vtkRenderer::New ();
    vtkRenderer *renderer2 = vtkRenderer::New ();
    
    renderer1->AddActor (actor);
    renderer2->AddActor (actor);
    actor->Delete ();

    m_iren1->GetRenderWindow ()->AddRenderer (renderer1);
    m_iren2->GetRenderWindow ()->AddRenderer (renderer2);

    renderer1->Delete ();
    renderer2->Delete ();
    // End VTK stuff

    topsizer->Add (panel, 1, wxGROW | wxADJUST_MINSIZE, 0);
    topsizer->Add (m_iren1, 1, wxGROW | wxADJUST_MINSIZE, 0);
    topsizer->Add (new wxStaticLine (frame, -1, wxDefaultPosition, wxDefaultSize,
            wxLI_VERTICAL), 0, wxALIGN_CENTRE | wxALL | wxGROW);
    topsizer->Add (m_iren2, 1, wxGROW | wxADJUST_MINSIZE, 0);
    topsizer->SetSizeHints (frame);
    frame->SetSizer (topsizer);
    frame->Show ();

    wxTheApp->SetTopWindow (frame);
    WxGuiTestHelper::Show (frame, true, false);
    WxGuiTestHelper::FlushEventQueue ();
}


void CRVtkCaptureTest::tearDown ()
{
    wxWindow *topWdw = wxTheApp->GetTopWindow ();
    wxTheApp->SetTopWindow (NULL);
    //topWdw->Destroy ();
    //WxGuiTestHelper::FlushEventQueue ();
    topWdw->Hide ();

    swTst::VtkWxGuiTestHelper::Destroy ();
    sw::ConfigManager::Destroy ();

    m_iren1->Delete ();
    m_iren2->Delete ();
}


void CRVtkCaptureTest::testVtkCapture ()
{
    sw::Config *configInit = new sw::Config ();
    configInit->SetResourceDir (xrcDir);
    sw::ConfigManager::SetInstance (configInit);
    sw::ConfigInterface *config = sw::ConfigManager::GetInstance ();
    wxASSERT (config != NULL);
    wxString resDir;
    bool ret = config->GetResourceDir (resDir);

    // Testing event capturing Cpp code emitting:
#define TESTCREMITTING
#ifdef TESTCREMITTING
    {
        wxApp *app = wxTheApp;
        wxASSERT (app != NULL);
        WxGuiTestApp *guiTestApp = dynamic_cast< WxGuiTestApp * >(app);
        wxASSERT (guiTestApp != NULL);
        guiTestApp->SetEventFilter (CREventCaptureManager::GetInstance ());
        CRCppEmitter::GetInstance ()->SetTestCaseFileContext (
                wxString (__FILE__, *wxConvCurrent));
        CREventCaptureManager::GetInstance ()->On ();

        try {
            // Put here the emitted code:
    swTst::WxVtkInteractorEventRecorder *multiRecorder = swTst::
            VtkWxGuiTestHelper::GetInstance ()->GetWxVtkRecorder (_T("Multi"));
    std::stack< wxWindow *, std::list< wxWindow * > > wdwStack;
    wxWindow *wdw = NULL;
    wxVTKRenderWindowInteractor * iren1WxVtkRwi = multiRecorder->GetInteractor 
            (_T("iren1"));
    wxWindow *iren1Wdw = iren1WxVtkRwi;
    wdw = iren1Wdw;
    wdwStack.push (wdw);
    while (wdw->GetParent () != NULL) {
    
        wdw = wdw->GetParent ();
        wdwStack.push (wdw);
    }
    wdw->Move (30, 25);
    wdwStack.top ()->SetSize (1036, 631);
    wdwStack.pop ();
    wdwStack.top ()->SetSize (342, 585);
    wdwStack.pop ();
    wxASSERT (wdwStack.empty ());
    vtkRendererCollection *renderers = iren1WxVtkRwi->GetRenderWindow ()->
            GetRenderers ();
    wxASSERT_MSG (renderers->GetNumberOfItems () == 1, _T("Currently only one ")
            _T("renderer per render window interactor is supported"));
    vtkCamera *camera = renderers->GetFirstRenderer ()->GetActiveCamera ();
    camera->SetParallelScale (87.6875);
    camera->SetViewAngle (30);
    camera->SetClippingRange (279.701, 414.007);
    camera->SetFocalPoint (-371.244, 252.214, 0);
    camera->SetPosition (-453.827, 190.15, 322.665);
    camera->SetViewUp (0.949353, 0.155696, 0.272924);
    wxVTKRenderWindowInteractor * iren2WxVtkRwi = multiRecorder->GetInteractor 
            (_T("iren2"));
    wxWindow *iren2Wdw = iren2WxVtkRwi;
    wdw = iren2Wdw;
    wdwStack.push (wdw);
    while (wdw->GetParent () != NULL) {
    
        wdw = wdw->GetParent ();
        wdwStack.push (wdw);
    }
    wdw->Move (30, 25);
    wdwStack.top ()->SetSize (1036, 631);
    wdwStack.pop ();
    wdwStack.top ()->SetSize (342, 585);
    wdwStack.pop ();
    wxASSERT (wdwStack.empty ());
    vtkRendererCollection *renderers1 = iren2WxVtkRwi->GetRenderWindow ()->
            GetRenderers ();
    wxASSERT_MSG (renderers1->GetNumberOfItems () == 1, _T("Currently only one ")
            _T("renderer per render window interactor is supported"));
    vtkCamera *camera1 = renderers1->GetFirstRenderer ()->GetActiveCamera ();
    camera1->SetParallelScale (87.6875);
    camera1->SetViewAngle (30);
    camera1->SetClippingRange (260.477, 438.206);
    camera1->SetFocalPoint (-371.244, 252.214, 0);
    camera1->SetPosition (-42.745, 286.958, 75.2683);
    camera1->SetViewUp (-0.113197, 0.992931, 0.0356974);
    multiRecorder->ReadFromInputStringOn ();
    multiRecorder->SetInputString (
            "# StreamVersion 2\n"
            "EnterEvent 11 42 0 0 0 0 i iren2\n"
            "MouseMoveEvent 11 42 0 0 0 0 i iren2\n"
            "MouseMoveEvent 22 105 0 0 0 0 i iren2\n"
            "MouseMoveEvent 28 135 0 0 0 0 i iren2\n"
            "MouseMoveEvent 34 162 0 0 0 0 i iren2\n"
            "MouseMoveEvent 49 186 0 0 0 0 i iren2\n"
            "MouseMoveEvent 55 213 0 0 0 0 i iren2\n"
            "MouseMoveEvent 61 231 0 0 0 0 i iren2\n"
            "MouseMoveEvent 76 252 0 0 0 0 i iren2\n"
            "MouseMoveEvent 80 267 0 0 0 0 i iren2\n"
            "MouseMoveEvent 83 273 0 0 0 0 i iren2\n"
            "MouseMoveEvent 83 278 0 0 0 0 i iren2\n"
            "MouseMoveEvent 83 281 0 0 0 0 i iren2\n"
            "MouseMoveEvent 83 282 0 0 0 0 i iren2\n"
            "MouseMoveEvent 81 284 0 0 0 0 i iren2\n"
            "MouseMoveEvent 79 285 0 0 0 0 i iren2\n"
            "MouseMoveEvent 79 287 0 0 0 0 i iren2\n"
            "MouseMoveEvent 78 288 0 0 0 0 i iren2\n"
            "MouseMoveEvent 79 288 0 0 0 0 i iren2\n"
            "MouseMoveEvent 80 290 0 0 0 0 i iren2\n"
            "MouseMoveEvent 83 291 0 0 0 0 i iren2\n"
            "MouseMoveEvent 86 294 0 0 0 0 i iren2\n"
            "MouseMoveEvent 89 297 0 0 0 0 i iren2\n"
            "MouseMoveEvent 92 299 0 0 0 0 i iren2\n"
            "MouseMoveEvent 95 300 0 0 0 0 i iren2\n"
            "MouseMoveEvent 98 303 0 0 0 0 i iren2\n"
            "MouseMoveEvent 103 306 0 0 0 0 i iren2\n"
            "MouseMoveEvent 107 308 0 0 0 0 i iren2\n"
            "MouseMoveEvent 110 311 0 0 0 0 i iren2\n"
            "MouseMoveEvent 115 312 0 0 0 0 i iren2\n"
            "MouseMoveEvent 118 315 0 0 0 0 i iren2\n"
            "MouseMoveEvent 119 317 0 0 0 0 i iren2\n"
            "MouseMoveEvent 122 317 0 0 0 0 i iren2\n"
            "MouseMoveEvent 122 318 0 0 0 0 i iren2\n"
            "MouseMoveEvent 124 320 0 0 0 0 i iren2\n"
            "MouseMoveEvent 123 320 0 0 0 0 i iren2\n"
            "MouseMoveEvent 123 321 0 0 0 0 i iren2\n"
            "MouseMoveEvent 121 321 0 0 0 0 i iren2\n"
            "MouseMoveEvent 120 321 0 0 0 0 i iren2\n"
            "MouseMoveEvent 118 323 0 0 0 0 i iren2\n"
            "MouseMoveEvent 117 323 0 0 0 0 i iren2\n"
            "MouseMoveEvent 115 323 0 0 0 0 i iren2\n"
            "MouseMoveEvent 114 323 0 0 0 0 i iren2\n"
            "MouseMoveEvent 112 323 0 0 0 0 i iren2\n"
            "MouseMoveEvent 111 323 0 0 0 0 i iren2\n"
            "MouseMoveEvent 111 324 0 0 0 0 i iren2\n"
            "MouseMoveEvent 109 324 0 0 0 0 i iren2\n"
            "MouseMoveEvent 108 324 0 0 0 0 i iren2\n"
            "MouseMoveEvent 108 326 0 0 0 0 i iren2\n"
            "MouseMoveEvent 106 326 0 0 0 0 i iren2\n"
            "LeftButtonPressEvent 106 326 0 0 0 0 i iren2\n"
            "TimerEvent 106 326 0 0 0 0 i iren2\n"
            "TimerEvent 106 326 0 0 0 0 i iren2\n"
            "TimerEvent 106 326 0 0 0 0 i iren2\n"
            "TimerEvent 106 326 0 0 0 0 i iren2\n"
            "TimerEvent 106 326 0 0 0 0 i iren2\n"
            "TimerEvent 106 326 0 0 0 0 i iren2\n"
            "TimerEvent 106 326 0 0 0 0 i iren2\n"
            "MouseMoveEvent 107 326 0 0 0 0 i iren2\n"
            "TimerEvent 107 326 0 0 0 0 i iren2\n"
            "MouseMoveEvent 109 326 0 0 0 0 i iren2\n"
            "TimerEvent 109 326 0 0 0 0 i iren2\n"
            "MouseMoveEvent 110 326 0 0 0 0 i iren2\n"
            "TimerEvent 110 326 0 0 0 0 i iren2\n"
            "MouseMoveEvent 110 325 0 0 0 0 i iren2\n"
            "TimerEvent 110 325 0 0 0 0 i iren2\n"
            "MouseMoveEvent 112 325 0 0 0 0 i iren2\n"
            "TimerEvent 112 325 0 0 0 0 i iren2\n"
            "MouseMoveEvent 113 325 0 0 0 0 i iren2\n"
            "TimerEvent 113 325 0 0 0 0 i iren2\n"
            "TimerEvent 113 325 0 0 0 0 i iren2\n"
            "MouseMoveEvent 115 325 0 0 0 0 i iren2\n"
            "TimerEvent 115 325 0 0 0 0 i iren2\n"
            "MouseMoveEvent 116 325 0 0 0 0 i iren2\n"
            "TimerEvent 116 325 0 0 0 0 i iren2\n"
            "MouseMoveEvent 116 323 0 0 0 0 i iren2\n"
            "MouseMoveEvent 118 323 0 0 0 0 i iren2\n"
            "TimerEvent 118 323 0 0 0 0 i iren2\n"
            "TimerEvent 118 323 0 0 0 0 i iren2\n"
            "MouseMoveEvent 119 323 0 0 0 0 i iren2\n"
            "TimerEvent 119 323 0 0 0 0 i iren2\n"
            "TimerEvent 119 323 0 0 0 0 i iren2\n"
            "TimerEvent 119 323 0 0 0 0 i iren2\n"
            "MouseMoveEvent 121 323 0 0 0 0 i iren2\n"
            "TimerEvent 121 323 0 0 0 0 i iren2\n"
            "TimerEvent 121 323 0 0 0 0 i iren2\n"
            "MouseMoveEvent 121 322 0 0 0 0 i iren2\n"
            "TimerEvent 121 322 0 0 0 0 i iren2\n"
            "MouseMoveEvent 122 322 0 0 0 0 i iren2\n"
            "MouseMoveEvent 124 322 0 0 0 0 i iren2\n"
            "TimerEvent 124 322 0 0 0 0 i iren2\n"
            "MouseMoveEvent 125 322 0 0 0 0 i iren2\n"
            "MouseMoveEvent 125 320 0 0 0 0 i iren2\n"
            "TimerEvent 125 320 0 0 0 0 i iren2\n"
            "MouseMoveEvent 127 320 0 0 0 0 i iren2\n"
            "TimerEvent 127 320 0 0 0 0 i iren2\n"
            "TimerEvent 127 320 0 0 0 0 i iren2\n"
            "MouseMoveEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "TimerEvent 128 320 0 0 0 0 i iren2\n"
            "MouseMoveEvent 130 320 0 0 0 0 i iren2\n"
            "TimerEvent 130 320 0 0 0 0 i iren2\n"
            "TimerEvent 130 320 0 0 0 0 i iren2\n"
            "TimerEvent 130 320 0 0 0 0 i iren2\n"
            "TimerEvent 130 320 0 0 0 0 i iren2\n"
            "TimerEvent 130 320 0 0 0 0 i iren2\n"
            "MouseMoveEvent 131 320 0 0 0 0 i iren2\n"
            "TimerEvent 131 320 0 0 0 0 i iren2\n"
            "MouseMoveEvent 131 319 0 0 0 0 i iren2\n"
            "TimerEvent 131 319 0 0 0 0 i iren2\n"
            "MouseMoveEvent 133 319 0 0 0 0 i iren2\n"
            "TimerEvent 133 319 0 0 0 0 i iren2\n"
            "MouseMoveEvent 133 317 0 0 0 0 i iren2\n"
            "MouseMoveEvent 134 317 0 0 0 0 i iren2\n"
            "TimerEvent 134 317 0 0 0 0 i iren2\n"
            "TimerEvent 134 317 0 0 0 0 i iren2\n"
            "MouseMoveEvent 134 316 0 0 0 0 i iren2\n"
            "MouseMoveEvent 136 316 0 0 0 0 i iren2\n"
            "TimerEvent 136 316 0 0 0 0 i iren2\n"
            "MouseMoveEvent 136 314 0 0 0 0 i iren2\n"
            "TimerEvent 136 314 0 0 0 0 i iren2\n"
            "TimerEvent 136 314 0 0 0 0 i iren2\n"
            "MouseMoveEvent 136 313 0 0 0 0 i iren2\n"
            "TimerEvent 136 313 0 0 0 0 i iren2\n"
            "TimerEvent 136 313 0 0 0 0 i iren2\n"
            "MouseMoveEvent 137 313 0 0 0 0 i iren2\n"
            "MouseMoveEvent 137 311 0 0 0 0 i iren2\n"
            "TimerEvent 137 311 0 0 0 0 i iren2\n"
            "MouseMoveEvent 137 310 0 0 0 0 i iren2\n"
            "TimerEvent 137 310 0 0 0 0 i iren2\n"
            "MouseMoveEvent 137 308 0 0 0 0 i iren2\n"
            "TimerEvent 137 308 0 0 0 0 i iren2\n"
            "MouseMoveEvent 137 307 0 0 0 0 i iren2\n"
            "TimerEvent 137 307 0 0 0 0 i iren2\n"
            "MouseMoveEvent 137 305 0 0 0 0 i iren2\n"
            "MouseMoveEvent 137 304 0 0 0 0 i iren2\n"
            "TimerEvent 137 304 0 0 0 0 i iren2\n"
            "MouseMoveEvent 137 302 0 0 0 0 i iren2\n"
            "TimerEvent 137 302 0 0 0 0 i iren2\n"
            "MouseMoveEvent 137 301 0 0 0 0 i iren2\n"
            "TimerEvent 137 301 0 0 0 0 i iren2\n"
            "MouseMoveEvent 139 301 0 0 0 0 i iren2\n"
            "MouseMoveEvent 139 299 0 0 0 0 i iren2\n"
            "TimerEvent 139 299 0 0 0 0 i iren2\n"
            "MouseMoveEvent 139 298 0 0 0 0 i iren2\n"
            "MouseMoveEvent 139 296 0 0 0 0 i iren2\n"
            "TimerEvent 139 296 0 0 0 0 i iren2\n"
            "MouseMoveEvent 140 296 0 0 0 0 i iren2\n"
            "MouseMoveEvent 140 295 0 0 0 0 i iren2\n"
            "TimerEvent 140 295 0 0 0 0 i iren2\n"
            "MouseMoveEvent 140 293 0 0 0 0 i iren2\n"
            "TimerEvent 140 293 0 0 0 0 i iren2\n"
            "MouseMoveEvent 142 293 0 0 0 0 i iren2\n"
            "MouseMoveEvent 142 292 0 0 0 0 i iren2\n"
            "TimerEvent 142 292 0 0 0 0 i iren2\n"
            "MouseMoveEvent 142 290 0 0 0 0 i iren2\n"
            "MouseMoveEvent 142 289 0 0 0 0 i iren2\n"
            "TimerEvent 142 289 0 0 0 0 i iren2\n"
            "MouseMoveEvent 143 289 0 0 0 0 i iren2\n"
            "MouseMoveEvent 143 287 0 0 0 0 i iren2\n"
            "TimerEvent 143 287 0 0 0 0 i iren2\n"
            "MouseMoveEvent 145 286 0 0 0 0 i iren2\n"
            "MouseMoveEvent 145 284 0 0 0 0 i iren2\n"
            "TimerEvent 145 284 0 0 0 0 i iren2\n"
            "MouseMoveEvent 145 283 0 0 0 0 i iren2\n"
            "TimerEvent 145 283 0 0 0 0 i iren2\n"
            "TimerEvent 145 283 0 0 0 0 i iren2\n"
            "MouseMoveEvent 146 283 0 0 0 0 i iren2\n"
            "MouseMoveEvent 146 281 0 0 0 0 i iren2\n"
            "TimerEvent 146 281 0 0 0 0 i iren2\n"
            "MouseMoveEvent 146 280 0 0 0 0 i iren2\n"
            "TimerEvent 146 280 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 280 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 278 0 0 0 0 i iren2\n"
            "TimerEvent 148 278 0 0 0 0 i iren2\n"
            "TimerEvent 148 278 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 277 0 0 0 0 i iren2\n"
            "MouseMoveEvent 149 277 0 0 0 0 i iren2\n"
            "TimerEvent 149 277 0 0 0 0 i iren2\n"
            "MouseMoveEvent 149 275 0 0 0 0 i iren2\n"
            "TimerEvent 149 275 0 0 0 0 i iren2\n"
            "MouseMoveEvent 149 274 0 0 0 0 i iren2\n"
            "TimerEvent 149 274 0 0 0 0 i iren2\n"
            "MouseMoveEvent 151 274 0 0 0 0 i iren2\n"
            "TimerEvent 151 274 0 0 0 0 i iren2\n"
            "MouseMoveEvent 151 272 0 0 0 0 i iren2\n"
            "TimerEvent 151 272 0 0 0 0 i iren2\n"
            "TimerEvent 151 272 0 0 0 0 i iren2\n"
            "MouseMoveEvent 152 272 0 0 0 0 i iren2\n"
            "TimerEvent 152 272 0 0 0 0 i iren2\n"
            "MouseMoveEvent 152 271 0 0 0 0 i iren2\n"
            "TimerEvent 152 271 0 0 0 0 i iren2\n"
            "TimerEvent 152 271 0 0 0 0 i iren2\n"
            "MouseMoveEvent 152 269 0 0 0 0 i iren2\n"
            "TimerEvent 152 269 0 0 0 0 i iren2\n"
            "MouseMoveEvent 154 269 0 0 0 0 i iren2\n"
            "TimerEvent 154 269 0 0 0 0 i iren2\n"
            "TimerEvent 154 269 0 0 0 0 i iren2\n"
            "MouseMoveEvent 154 268 0 0 0 0 i iren2\n"
            "TimerEvent 154 268 0 0 0 0 i iren2\n"
            "TimerEvent 154 268 0 0 0 0 i iren2\n"
            "TimerEvent 154 268 0 0 0 0 i iren2\n"
            "TimerEvent 154 268 0 0 0 0 i iren2\n"
            "MouseMoveEvent 154 266 0 0 0 0 i iren2\n"
            "MouseMoveEvent 155 266 0 0 0 0 i iren2\n"
            "TimerEvent 155 266 0 0 0 0 i iren2\n"
            "TimerEvent 155 266 0 0 0 0 i iren2\n"
            "MouseMoveEvent 155 265 0 0 0 0 i iren2\n"
            "TimerEvent 155 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "TimerEvent 157 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 158 265 0 0 0 0 i iren2\n"
            "TimerEvent 158 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 160 265 0 0 0 0 i iren2\n"
            "TimerEvent 160 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 161 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 163 265 0 0 0 0 i iren2\n"
            "TimerEvent 163 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 164 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 166 265 0 0 0 0 i iren2\n"
            "TimerEvent 166 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 169 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 170 265 0 0 0 0 i iren2\n"
            "TimerEvent 170 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 172 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 173 265 0 0 0 0 i iren2\n"
            "TimerEvent 173 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 175 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 176 265 0 0 0 0 i iren2\n"
            "TimerEvent 176 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 179 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 181 265 0 0 0 0 i iren2\n"
            "TimerEvent 181 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 182 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 184 265 0 0 0 0 i iren2\n"
            "TimerEvent 184 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 185 265 0 0 0 0 i iren2\n"
            "TimerEvent 185 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 187 265 0 0 0 0 i iren2\n"
            "TimerEvent 187 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 188 265 0 0 0 0 i iren2\n"
            "TimerEvent 188 265 0 0 0 0 i iren2\n"
            "TimerEvent 188 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 190 265 0 0 0 0 i iren2\n"
            "TimerEvent 190 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 191 265 0 0 0 0 i iren2\n"
            "TimerEvent 191 265 0 0 0 0 i iren2\n"
            "TimerEvent 191 265 0 0 0 0 i iren2\n"
            "TimerEvent 191 265 0 0 0 0 i iren2\n"
            "TimerEvent 191 265 0 0 0 0 i iren2\n"
            "TimerEvent 191 265 0 0 0 0 i iren2\n"
            "TimerEvent 191 265 0 0 0 0 i iren2\n"
            "TimerEvent 191 265 0 0 0 0 i iren2\n"
            "TimerEvent 191 265 0 0 0 0 i iren2\n"
            "TimerEvent 191 265 0 0 0 0 i iren2\n"
            "TimerEvent 191 265 0 0 0 0 i iren2\n"
            "TimerEvent 191 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 191 263 0 0 0 0 i iren2\n"
            "MouseMoveEvent 190 263 0 0 0 0 i iren2\n"
            "TimerEvent 190 263 0 0 0 0 i iren2\n"
            "MouseMoveEvent 189 263 0 0 0 0 i iren2\n"
            "TimerEvent 189 263 0 0 0 0 i iren2\n"
            "MouseMoveEvent 187 262 0 0 0 0 i iren2\n"
            "TimerEvent 187 262 0 0 0 0 i iren2\n"
            "MouseMoveEvent 186 262 0 0 0 0 i iren2\n"
            "TimerEvent 186 262 0 0 0 0 i iren2\n"
            "MouseMoveEvent 184 262 0 0 0 0 i iren2\n"
            "TimerEvent 184 262 0 0 0 0 i iren2\n"
            "MouseMoveEvent 183 260 0 0 0 0 i iren2\n"
            "TimerEvent 183 260 0 0 0 0 i iren2\n"
            "TimerEvent 183 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 181 260 0 0 0 0 i iren2\n"
            "TimerEvent 181 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 180 260 0 0 0 0 i iren2\n"
            "TimerEvent 180 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 178 260 0 0 0 0 i iren2\n"
            "TimerEvent 178 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 177 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 175 260 0 0 0 0 i iren2\n"
            "TimerEvent 175 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 174 260 0 0 0 0 i iren2\n"
            "TimerEvent 174 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 172 260 0 0 0 0 i iren2\n"
            "TimerEvent 172 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 171 260 0 0 0 0 i iren2\n"
            "TimerEvent 171 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 169 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 168 260 0 0 0 0 i iren2\n"
            "TimerEvent 168 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 166 260 0 0 0 0 i iren2\n"
            "TimerEvent 166 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 165 259 0 0 0 0 i iren2\n"
            "TimerEvent 165 259 0 0 0 0 i iren2\n"
            "MouseMoveEvent 163 259 0 0 0 0 i iren2\n"
            "TimerEvent 163 259 0 0 0 0 i iren2\n"
            "MouseMoveEvent 162 259 0 0 0 0 i iren2\n"
            "TimerEvent 162 259 0 0 0 0 i iren2\n"
            "MouseMoveEvent 160 259 0 0 0 0 i iren2\n"
            "TimerEvent 160 259 0 0 0 0 i iren2\n"
            "TimerEvent 160 259 0 0 0 0 i iren2\n"
            "TimerEvent 160 259 0 0 0 0 i iren2\n"
            "MouseMoveEvent 159 259 0 0 0 0 i iren2\n"
            "TimerEvent 159 259 0 0 0 0 i iren2\n"
            "TimerEvent 159 259 0 0 0 0 i iren2\n"
            "TimerEvent 159 259 0 0 0 0 i iren2\n"
            "TimerEvent 159 259 0 0 0 0 i iren2\n"
            "TimerEvent 159 259 0 0 0 0 i iren2\n"
            "MouseMoveEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "TimerEvent 157 259 0 0 0 0 i iren2\n"
            "MouseMoveEvent 156 259 0 0 0 0 i iren2\n"
            "TimerEvent 156 259 0 0 0 0 i iren2\n"
            "TimerEvent 156 259 0 0 0 0 i iren2\n"
            "TimerEvent 156 259 0 0 0 0 i iren2\n"
            "MouseMoveEvent 154 259 0 0 0 0 i iren2\n"
            "TimerEvent 154 259 0 0 0 0 i iren2\n"
            "TimerEvent 154 259 0 0 0 0 i iren2\n"
            "TimerEvent 154 259 0 0 0 0 i iren2\n"
            "MouseMoveEvent 154 260 0 0 0 0 i iren2\n"
            "TimerEvent 154 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 153 260 0 0 0 0 i iren2\n"
            "TimerEvent 153 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 153 261 0 0 0 0 i iren2\n"
            "MouseMoveEvent 151 261 0 0 0 0 i iren2\n"
            "TimerEvent 151 261 0 0 0 0 i iren2\n"
            "MouseMoveEvent 151 263 0 0 0 0 i iren2\n"
            "TimerEvent 151 263 0 0 0 0 i iren2\n"
            "MouseMoveEvent 150 263 0 0 0 0 i iren2\n"
            "TimerEvent 150 263 0 0 0 0 i iren2\n"
            "TimerEvent 150 263 0 0 0 0 i iren2\n"
            "TimerEvent 150 263 0 0 0 0 i iren2\n"
            "MouseMoveEvent 150 264 0 0 0 0 i iren2\n"
            "TimerEvent 150 264 0 0 0 0 i iren2\n"
            "TimerEvent 150 264 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 264 0 0 0 0 i iren2\n"
            "TimerEvent 148 264 0 0 0 0 i iren2\n"
            "TimerEvent 148 264 0 0 0 0 i iren2\n"
            "TimerEvent 148 264 0 0 0 0 i iren2\n"
            "TimerEvent 148 264 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 266 0 0 0 0 i iren2\n"
            "TimerEvent 148 266 0 0 0 0 i iren2\n"
            "MouseMoveEvent 147 266 0 0 0 0 i iren2\n"
            "TimerEvent 147 266 0 0 0 0 i iren2\n"
            "TimerEvent 147 266 0 0 0 0 i iren2\n"
            "TimerEvent 147 266 0 0 0 0 i iren2\n"
            "TimerEvent 147 266 0 0 0 0 i iren2\n"
            "MouseMoveEvent 147 267 0 0 0 0 i iren2\n"
            "TimerEvent 147 267 0 0 0 0 i iren2\n"
            "TimerEvent 147 267 0 0 0 0 i iren2\n"
            "MouseMoveEvent 147 269 0 0 0 0 i iren2\n"
            "TimerEvent 147 269 0 0 0 0 i iren2\n"
            "MouseMoveEvent 147 270 0 0 0 0 i iren2\n"
            "TimerEvent 147 270 0 0 0 0 i iren2\n"
            "MouseMoveEvent 147 272 0 0 0 0 i iren2\n"
            "MouseMoveEvent 147 273 0 0 0 0 i iren2\n"
            "TimerEvent 147 273 0 0 0 0 i iren2\n"
            "MouseMoveEvent 147 275 0 0 0 0 i iren2\n"
            "TimerEvent 147 275 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 276 0 0 0 0 i iren2\n"
            "TimerEvent 148 276 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 278 0 0 0 0 i iren2\n"
            "TimerEvent 148 278 0 0 0 0 i iren2\n"
            "TimerEvent 148 278 0 0 0 0 i iren2\n"
            "TimerEvent 148 278 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 279 0 0 0 0 i iren2\n"
            "TimerEvent 148 279 0 0 0 0 i iren2\n"
            "TimerEvent 148 279 0 0 0 0 i iren2\n"
            "TimerEvent 148 279 0 0 0 0 i iren2\n"
            "TimerEvent 148 279 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 281 0 0 0 0 i iren2\n"
            "TimerEvent 148 281 0 0 0 0 i iren2\n"
            "TimerEvent 148 281 0 0 0 0 i iren2\n"
            "TimerEvent 148 281 0 0 0 0 i iren2\n"
            "TimerEvent 148 281 0 0 0 0 i iren2\n"
            "TimerEvent 148 281 0 0 0 0 i iren2\n"
            "TimerEvent 148 281 0 0 0 0 i iren2\n"
            "TimerEvent 148 281 0 0 0 0 i iren2\n"
            "TimerEvent 148 281 0 0 0 0 i iren2\n"
            "TimerEvent 148 281 0 0 0 0 i iren2\n"
            "TimerEvent 148 281 0 0 0 0 i iren2\n"
            "MouseMoveEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "LeftButtonReleaseEvent 149 281 0 0 0 0 i iren2\n"
            "MouseMoveEvent 149 281 0 0 0 0 i iren2\n"
            "TimerEvent 149 281 0 0 0 0 i iren2\n"
            "MouseMoveEvent 149 282 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 282 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 281 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 278 0 0 0 0 i iren2\n"
            "MouseMoveEvent 148 277 0 0 0 0 i iren2\n"
            "MouseMoveEvent 147 272 0 0 0 0 i iren2\n"
            "MouseMoveEvent 145 269 0 0 0 0 i iren2\n"
            "MouseMoveEvent 142 265 0 0 0 0 i iren2\n"
            "MouseMoveEvent 141 260 0 0 0 0 i iren2\n"
            "MouseMoveEvent 138 256 0 0 0 0 i iren2\n"
            "MouseMoveEvent 136 251 0 0 0 0 i iren2\n"
            "MouseMoveEvent 133 245 0 0 0 0 i iren2\n"
            "MouseMoveEvent 132 239 0 0 0 0 i iren2\n"
            "MouseMoveEvent 129 224 0 0 0 0 i iren2\n"
            "MouseMoveEvent 124 209 0 0 0 0 i iren2\n"
            "MouseMoveEvent 121 203 0 0 0 0 i iren2\n"
            "MouseMoveEvent 118 185 0 0 0 0 i iren2\n"
            "MouseMoveEvent 115 179 0 0 0 0 i iren2\n"
            "MouseMoveEvent 112 173 0 0 0 0 i iren2\n"
            "MouseMoveEvent 109 155 0 0 0 0 i iren2\n"
            "MouseMoveEvent 106 149 0 0 0 0 i iren2\n"
            "MouseMoveEvent 106 131 0 0 0 0 i iren2\n"
            "MouseMoveEvent 105 125 0 0 0 0 i iren2\n"
            "MouseMoveEvent 105 119 0 0 0 0 i iren2\n"
            "MouseMoveEvent 103 98 0 0 0 0 i iren2\n"
            "MouseMoveEvent 103 83 0 0 0 0 i iren2\n"
            "MouseMoveEvent 103 68 0 0 0 0 i iren2\n"
            "MouseMoveEvent 103 53 0 0 0 0 i iren2\n"
            "MouseMoveEvent 103 38 0 0 0 0 i iren2\n"
            "MouseMoveEvent 104 32 0 0 0 0 i iren2\n"
            "MouseMoveEvent 104 26 0 0 0 0 i iren2\n"
            "MouseMoveEvent 104 20 0 0 0 0 i iren2\n"
            "LeaveEvent 106 16 0 0 0 0 i iren2\n"
    );
    multiRecorder->Play ();
            // End
        } catch (...) {
            guiTestApp->SetEventFilter (NULL);
            throw;
        }
        guiTestApp->SetEventFilter (NULL);
        CRCppEmitter::Destroy ();
    }
#endif


    // Do bootstrap capturing:
/*
    {
        wxApp *app = wxTheApp;
        wxASSERT (app != NULL);
        swTst::WxGuiTestApp *guiTestApp = dynamic_cast< swTst::WxGuiTestApp * >(app);
        wxASSERT (guiTestApp != NULL);
        guiTestApp->SetEventFilter (swTst::CREventCaptureManager::GetInstance ());

        swTst::CRCapture *capture = new swTst::CRCapture ();
        try {
            capture->Capture (__FILE__, __LINE__);
        } catch (...) {
            guiTestApp->SetEventFilter (NULL);
            throw;
        }
        guiTestApp->SetEventFilter (NULL);
        delete capture;
        swTst::CRCppEmitter::Destroy ();
    }
*/
    // Or use easier macro:
    VTK_CAPTURE

    swTst::WxGuiTestTempInteractive interactive;
    interactive.ShowCurrentGui ();

    // Using the {...} notation we can have several VTK_CAPTUREs in one method:
    //VTK_CAPTURE

    sw::ConfigManager::SetInstance (NULL);
}

} // End namespace swTst
