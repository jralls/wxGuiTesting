///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/TempInteractiveControl.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWTEMPINTERACTIVECONTROL_H
#define SWTEMPINTERACTIVECONTROL_H

#ifdef __GNUG__
    #pragma interface "TempInteractiveControl.h"
#endif

#include <wxGuiTest/Common.h>

namespace wxTst {


/*! \class TempInteractiveControl
    \brief Handle events of dialog (controller in MVC concept).
*/
class TempInteractiveControl : public wxEvtHandler
{
    DECLARE_EVENT_TABLE()

public:
    /*! \fn TempInteractiveControl (wxDialog *dialog)
        \brief Constructor

        \param dialog dialog with button to continue unit testing
    */
    TempInteractiveControl (wxDialog *dialog);


    /*! \fn virtual ~TempInteractiveControl ()
        \brief Destructor
    */
    virtual ~TempInteractiveControl ();

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

} // End namespace wxTst

#endif // SWTEMPINTERACTIVECONTROL_H

