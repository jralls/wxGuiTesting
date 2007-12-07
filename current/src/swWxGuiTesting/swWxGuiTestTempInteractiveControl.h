///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swWxGuiTestTempInteractiveControl.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWWXGUITESTTEMPINTERACTIVECONTROL_H
#define SWWXGUITESTTEMPINTERACTIVECONTROL_H

#ifdef __GNUG__
    #pragma interface "swWxGuiTestTempInteractiveControl.h"
#endif

#include <wxGuiTest/Common.h>

namespace swTst {


/*! \class WxGuiTestTempInteractiveControl
    \brief Handle events of dialog (controller in MVC concept).
*/
class WxGuiTestTempInteractiveControl : public wxEvtHandler
{
    DECLARE_EVENT_TABLE()

public:
    /*! \fn WxGuiTestTempInteractiveControl (wxDialog *dialog)
        \brief Constructor

        \param dialog dialog with button to continue unit testing
    */
    WxGuiTestTempInteractiveControl (wxDialog *dialog);


    /*! \fn virtual ~WxGuiTestTempInteractiveControl ()
        \brief Destructor
    */
    virtual ~WxGuiTestTempInteractiveControl ();

protected:
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
        \brief Finish temporary interactivity.
    */
    virtual void Finish ();


private:
    wxDialog *m_dialog;

};

} // End namespace swTst

#endif // SWWXGUITESTTEMPINTERACTIVECONTROL_H

