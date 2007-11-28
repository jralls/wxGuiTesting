///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRCapture.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRCAPTURE_H
#define SWCRCAPTURE_H

#ifdef __GNUG__
    #pragma interface "swCRCapture.h"
#endif

#include "Common.h"

#include "swWxGuiTestApp.h"
#include "swCRLogInterface.h"
#include "swCREventCaptureManager.h"
#include "swCRCppEmitter.h"
#include "swCRCaptureControl.h"

class wxDialog;

namespace swTst {


/*! \class CRCapture
    \brief Provides a way of capturing GUI interaction for future test cases.
*/
class CRCapture : public CRLogInterface
{
public:
    /*! \fn CRCapture ()
        \brief Constructor
    */
    CRCapture ();


    /*! \fn virtual ~CRCapture ()
        \brief Destructor
    */
    virtual ~CRCapture ();


    /*! \file swCRCapture.h
        \brief Providing easy to use macro for bootstrap capturing.
    
        Doxygen documentation only needed for #define CAPTURE.
    */
    /*! \def CAPTURE
        \brief Macro allowing bootstrap of capture & replay.
        
        Using "{...}" notation several capturings can be used in one single method.
    */
    #define CAPTURE                                                           \
    {                                                                         \
        wxApp *app = wxTheApp;                                                \
        wxASSERT (app != NULL);                                               \
        swTst::WxGuiTestApp *guiTestApp = dynamic_cast< swTst::WxGuiTestApp * >(app); \
        wxASSERT (guiTestApp != NULL);                                        \
        guiTestApp->SetEventFilter (swTst::CREventCaptureManager::GetInstance ()); \
                                                                              \
	std::string excMsg;						\
        swTst::CRCapture *capture = new swTst::CRCapture ();                  \
        try {                                                                 \
            capture->Capture (__FILE__, __LINE__);                            \
        } catch (std::exception &e) {                                         \
            excMsg = e.what ();                                               \
        } catch (...) {                                                       \
            excMsg = "Unexpected capturing exception";                        \
        }                                                                     \
        guiTestApp->SetEventFilter (NULL);                                    \
        delete capture;                                                       \
        swTst::CRCppEmitter::Destroy ();                                      \
        if (!excMsg.empty ()) {                                             \
            CPPUNIT_FAIL (excMsg.c_str ());                                   \
        }                                                                     \
    }


    /*! \fn virtual void Capture (const char *file, int line)
        \brief Capture events in GUI test case bootstrap mode.

        \param file name of affected GUI test case file
        \param line line number of affected GUI test case file
    */
    virtual void Capture (const char *file, int line);


    // Implement CRLogInterface:

    /*! \var virtual void Log (const wxString &text)
        \brief Log some text.

        \param text text to log
    */
    virtual void Log (const wxString &text);

protected:
    /*! \fn virtual void Show ()
        \brief Prepare capturing by showing dialog after configuring main loop.
    */
    virtual void Show ();


    /*! \fn virtual void CreateEvtHandler ()
        \brief Create event handler for capturing dialog.
    */
    virtual void CreateEvtHandler ();


    /*! \fn virtual void CreateDialog ()
        \brief Creates capturing dialog.
    */
    virtual void CreateDialog ();


    /*! \fn virtual wxPanel * LoadPanel ()
        \brief Load concrete capturing panel.

        \return loaded concrete capturing panel
    */
    virtual wxPanel * LoadPanel ();

protected:
    wxDialog *m_dialog;
    CRCaptureControl *m_control;

private:
    wxTextCtrl *m_logTextCtrl;
};

} // End namespace swTst

#endif // SWCRCAPTURE_H
