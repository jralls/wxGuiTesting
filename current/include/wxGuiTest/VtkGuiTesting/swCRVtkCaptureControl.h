///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/VtkWxGuiTesting/swCRVtkCaptureControl.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWVTKCRCAPTURECONTROL_H
#define SWVTKCRCAPTURECONTROL_H

#ifdef __GNUG__
    #pragma interface "swCRVtkCaptureControl.h"
#endif

#include <wxGuiTest/Common.h>

#include <wxGuiTest/swCRCaptureControl.h>

namespace swTst {


/*! \class CRVtkCaptureControl
    \brief Handle events of capture dialog (controller in MVC concept).
*/
class CRVtkCaptureControl : public CRCaptureControl
{
    DECLARE_EVENT_TABLE()

public:
    /*! \fn CRVtkCaptureControl (wxDialog *dialog)
        \brief Constructor

        \param dialog dialog with button to continue unit testing
    */
    CRVtkCaptureControl (wxDialog *dialog);


    /*! \fn virtual ~CRVtkCaptureControl ()
        \brief Destructor
    */
    virtual ~CRVtkCaptureControl ();

protected:
    /*! \fn virtual void OnResetWxVtkRecording (wxCommandEvent &event)
        \brief User clicked on Reset button to reset wxVtk interaction recording.

        \param event button click event
    */
    virtual void OnResetWxVtkRecording (wxCommandEvent &event);


    /*! \fn virtual void OnStartWxVtkRecording (wxCommandEvent &event)
        \brief User clicked on Start button to start wxVtk interaction recording.

        \param event button click event
    */
    virtual void OnStartWxVtkRecording (wxCommandEvent &event);

    
    /*! \fn virtual void OnAddWxVtkRecording (wxCommandEvent &event)
        \brief User clicked on Add button to stop wxVtk interaction recording
            and add the recording to the test case.

        \param event button click event
    */
    virtual void OnAddWxVtkRecording (wxCommandEvent &event);

private:

};

} // End namespace swTst

#endif // SWVTKCRCAPTURECONTROL_H

