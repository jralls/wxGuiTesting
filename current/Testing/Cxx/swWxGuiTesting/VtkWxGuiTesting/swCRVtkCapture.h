///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/VtkWxGuiTesting/swCRVtkCapture.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRVTKCAPTURE_H
#define SWCRVTKCAPTURE_H

#ifdef __GNUG__
    #pragma interface "swCRVtkCapture.h"
#endif

#include "Common.h"

#include "swWxGuiTestApp.h"
#include "swCRCapture.h"

namespace swTst {


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


    /*! \file swCRVtkCapture.h
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
        swTst::WxGuiTestApp *guiTestApp = dynamic_cast< swTst::WxGuiTestApp * >(app); \
        wxASSERT (guiTestApp != NULL);                                        \
        guiTestApp->SetEventFilter (swTst::CREventCaptureManager::GetInstance ()); \
                                                                              \
        std::string excMsg;                                                   \
        swTst::CRVtkCapture *capture = new swTst::CRVtkCapture ();            \
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

protected:
    /*! \fn virtual wxEvtHandler * CreateEvtHandler () const
        \brief Create event handler for capturing dialog.

        \return new event handler for capturing dialog
    */
    virtual wxEvtHandler * CreateEvtHandler () const;


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

} // End namespace swTst

#endif // SWCRVTKCAPTURE_H

