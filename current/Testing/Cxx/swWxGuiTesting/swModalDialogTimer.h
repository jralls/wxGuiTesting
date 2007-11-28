///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swModalDialogTimer.h
// Author:      Reinhold Füreder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWMODALDIALOGTIMER_H
#define SWMODALDIALOGTIMER_H

#ifdef __GNUG__
    #pragma interface "swModalDialogTimer.h"
#endif

#include <wx/timer.h>

class wxDialog;

namespace swTst {

class ModalDialogInteractionInterface;


/*! \class ModalDialogTimer
    \brief When fired, the modal dialog interactor (if existing) is executed
        first, before the modal dialog is ended with the given return code.
*/
class ModalDialogTimer : public wxTimer
{
public:
    /*! \fn ModalDialogTimer (int retCode)
        \brief Constructor

        \param retCode return code to use for ending the modal dialog
    */
    ModalDialogTimer (int retCode);


    /*! \fn virtual ~ModalDialogTimer ()
        \brief Destructor

        Deletes the modal dialog interactor if available.
    */
    virtual ~ModalDialogTimer ();


    /*! \fn virtual void SetModalDialog (wxDialog *dialog)
        \brief Set modal dialog to interact with.

        \param dialog modal dialog to interact with
    */
    virtual void SetModalDialog (wxDialog *dialog);


    /*! \fn virtual void SetModalDialogInteractor (ModalDialogInteractionInterface *interactor)
        \brief Set modal dialog interactor -- will be called/executed before
        dismissing/closing the modal dialog.

        Note that the interactor will be destroyed in the d'tor.

        \param interactor actual code to carry out before dismissing the modal dialog
    */
    virtual void SetModalDialogInteractor (ModalDialogInteractionInterface *interactor);


    /*! \fn virtual bool Start(int milliseconds = -1, bool oneShot = true)
        \brief Overridden to disallow repeated firing - only oneShot is allowed.

        \param milliseconds timer timeout period
        \param oneShot      must be left unset, or set to true, otherwise an exception is thrown
    */
    virtual bool Start(int milliseconds = -1, bool oneShot = true);


    /*! \fn virtual void Notify()
        \brief Called when the time out actually expires.
    */
    virtual void Notify();

protected:
    /*! \fn virtual void EndDialog ()
        \brief Helper method required due to protected access to corresponding
        dialog method in wxWidgets 2.8; plus avoid duplication.
    */
    virtual void EndDialog ();

private:
    wxDialog * m_dialog;
    ModalDialogInteractionInterface * m_interactor;
    int m_retCode;

};

} // End namespace swTst

#endif // SWMODALDIALOGTIMER_H
