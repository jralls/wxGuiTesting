///////////////////////////////////////////////////////////////////////////////
// Name:        sample/SimpleCRTest.cpp
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "SimpleCRTest.h"
#endif

#include "SimpleCRTest.h"

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/notebook.h>

//#include <wx/xrc/xmlres.h>

#include <wxGuiTest/WxGuiTestHelper.h>
#include <wxGuiTest/EventSimulationHelper.h>
#include <wxGuiTest/TimedDialogEnder.h>
#include <wxGuiTest/TempInteractive.h>

#include <wxGuiTest/CRCapture.h>


#include "xrcdemo.h"
#include "myframe.h"
namespace {
    const wxString xrcDir(_T(XRCDIR));
}


// Register test suite with special name in order to be identifiable as test
// which must be run after GUI part of wxWidgets library is initialised:
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( SimpleCRTest, "WxGuiTest" );


void SimpleCRTest::setUp ()
{
//    MyApp app;
//    MyFrame* myFrame = app.init();
//    wxTheApp->SetTopWindow(myFrame);
//     wxWindow* myFrame = wxTheApp->GetTopWindow();
//     wxTst::WxGuiTestHelper::Show (myFrame, true, false);
//     wxTst::WxGuiTestHelper::FlushEventQueue ();

}


void SimpleCRTest::tearDown ()
{

//     wxWindow *topWdw = wxTheApp->GetTopWindow ();
//     wxTheApp->SetTopWindow (NULL);
//     topWdw->Destroy();
}


// void SimpleCRTest::testCapture ()
// {
//     wxTst::TempInteractive interactive;

//     // Do bootstrap capturing:
//     CAPTURE
// }
void SimpleCRTest::testCapture ()
{
    wxTst::TempInteractive interactive;

    // Do bootstrap capturing:

        wxApp *app = wxTheApp;                                                
        wxASSERT (app != NULL);                                               
        wxTst::WxGuiTestApp *guiTestApp = dynamic_cast< wxTst::WxGuiTestApp * >(app); 
        wxASSERT (guiTestApp != NULL);                    
		wxTst::CREventCaptureManager* capMgr = 
			wxTst::CREventCaptureManager::GetInstance ();
		capMgr->SetCategoryMask(wxTst::AllEvents ^ wxTst::SystemEvents ^ wxTst::MouseMotionEvents ^ wxTst::AppEvents ^ wxTst::WindowEvents);
        guiTestApp->SetEventFilter (capMgr); 
                                                                              
        std::string excMsg;						                              
        wxTst::CRCapture *capture = new wxTst::CRCapture ();                  
        try {                                                                 
            capture->Capture (__FILE__, __LINE__);                            
        } catch (std::exception &e) {                                         
            excMsg = e.what ();                                               
        } catch (...) {                                                       
            excMsg = "Unexpected capturing exception";                        
        }                                                                     
        guiTestApp->SetEventFilter (NULL);                                    
        delete capture;                                                       
        wxTst::CRCppEmitter::Destroy ();                                      
        if (!excMsg.empty ()) {                                               
            CPPUNIT_FAIL (excMsg.c_str ());                                   
        }                                                                     
}
