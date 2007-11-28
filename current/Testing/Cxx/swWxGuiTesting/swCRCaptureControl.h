///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRCaptureControl.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRCAPTURECONTROL_H
#define SWCRCAPTURECONTROL_H

#ifdef __GNUG__
    #pragma interface "swCRCaptureControl.h"
#endif

#include "Common.h"

namespace swTst {


/*! \class CRCaptureControl
    \brief Handle events of capture dialog (controller in MVC concept).
*/
class CRCaptureControl : public wxEvtHandler
{
    DECLARE_EVENT_TABLE()

public:
    /*! \fn CRCaptureControl (wxDialog *dialog)
        \brief Constructor

        \param dialog dialog with button to continue unit testing
    */
    CRCaptureControl (wxDialog *dialog);


    /*! \fn virtual ~CRCaptureControl ()
        \brief Destructor
    */
    virtual ~CRCaptureControl ();


    /*! \fn virtual void SetButtonStates (bool isInit = true) const
        \brief Enable/disable start/stop buttons accordingly.

        \param isInit if true, start button is enabled and stop button is
            disabled; and vice versa
    */
    virtual void SetButtonStates (bool isInit = true) const;

protected:
    /*! \fn virtual void OnStart (wxCommandEvent &event)
        \brief User clicked on Start button to start capturing.

        \param event button click event
    */
    virtual void OnStart (wxCommandEvent &event);


    /*! \fn virtual void OnStop (wxCommandEvent &event)
        \brief User clicked on Stop button to stop capturing.

        \param event button click event
    */
    virtual void OnStop (wxCommandEvent &event);


    /*! \fn virtual void OnAddComment (wxCommandEvent &event)
        \brief User wants to add a comment to bootstrap test case.

        \param event button click event
    */
    virtual void OnAddComment (wxCommandEvent &event);


    /*! \fn virtual void OnOK (wxCommandEvent &event)
        \brief User clicked on OK button to continue testing -> finish.

        \param event button click event
    */
    virtual void OnOK (wxCommandEvent &event);


    /*! \fn virtual void OnClose (wxCloseEvent &event)
        \brief Normal dialog closing callback -> finish.

        \param dialog close event
    */
    virtual void OnClose (wxCloseEvent &event);


    /*! \fn virtual void Finish ()
        \brief Finish capturing.
    */
    virtual void Finish ();
    
private:
    wxDialog *m_dialog;

};

} // End namespace swTst

#endif // SWCRCAPTURECONTROL_H

