///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/VtkWxGuiTesting/CRVtkCapture.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef CRVTKCAPTURE_H
#define CRVTKCAPTURE_H

#ifdef __GNUG__
    #pragma interface "CRVtkCapture.h"
#endif

#include <wxGuiTest/Common.h>

#include <wxGuiTest/WxGuiTestApp.h>
#include <wxGuiTest/CRCapture.h>

namespace wxTst {


/*! \class CRVtkCapture
    \brief Provides a way of capturing GUI interaction for future test cases.
*/
class CRVtkCapture : public CRCapture
{
public:
    /*! \fn CRVtkCapture ()
        \brief Constructor
    */
    CRVtkCapture ();


    /*! \fn virtual ~CRVtkCapture ()
        \brief Destructor
    */
    virtual ~CRVtkCapture ();


    /*! \file CRVtkCapture.h
        \brief Providing easy to use macro for bootstrap capturing.

        Doxygen documentation only needed for #define VTK_CAPTURE.
    */
    /*! \def VTK_CAPTURE
        \brief Macro allowing bootstrap of capture & replay.

        Using "{...}" notation several capturings can be used in one single method.
    */
    #define VTK_CAPTURE                                                       \
    {                                                                         \
        wxApp *app = wxTheApp;                                                \
        wxASSERT (app != NULL);                                               \
        wxTst::WxGuiTestApp *guiTestApp = dynamic_cast< wxTst::WxGuiTestApp * >(app); \
        wxASSERT (guiTestApp != NULL);                                        \
        guiTestApp->SetEventFilter (wxTst::CREventCaptureManager::GetInstance ()); \
                                                                              \
        std::string excMsg;                                                   \
        wxTst::CRVtkCapture *capture = new wxTst::CRVtkCapture ();            \
        try {                                                                 \
            capture->Capture (__FILE__, __LINE__);                            \
        } catch (std::exception &e) {                                         \
            excMsg = e.what ();                                               \
        } catch (...) {                                                       \
            excMsg = "Unexpected capturing exception";                        \
        }                                                                     \
        guiTestApp->SetEventFilter (NULL);                                    \
        delete capture;                                                       \
        wxTst::CRCppEmitter::Destroy ();                                      \
        if (!excMsg.empty ()) {                                               \
            CPPUNIT_FAIL (excMsg.c_str ());                                   \
        }                                                                     \
    }

protected:
    /*! \fn virtual CRCaptureControl * CreateEvtHandler () const
        \brief Create event handler for capturing dialog.

        \return new event handler for capturing dialog
    */
    virtual CRCaptureControl * CreateEvtHandler () const;


    /*! \fn virtual void CreateDialog ()
        \brief Creates capturing dialog.
    */
    virtual void CreateDialog ();


    /*! \fn virtual wxPanel * LoadPanel ()
        \brief Load concrete capturing panel.

        \return loaded concrete capturing panel
    */
    virtual wxPanel * LoadPanel ();

private:

};

} // End namespace wxTst

#endif // CRVTKCAPTURE_H

