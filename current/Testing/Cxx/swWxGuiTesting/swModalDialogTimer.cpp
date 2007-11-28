///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swModalDialogTimer.cpp
// Author:      Reinhold F�reder
// Created:     2006
// Copyright:   (c) 2006 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swModalDialogTimer.h"
#endif

#include "swModalDialogTimer.h"

#include <wx/dialog.h>

#include "swModalDialogInteractionInterface.h"

#include "swWxLogicErrorException.h"


namespace swTst {


ModalDialogTimer::ModalDialogTimer (int retCode) :
m_retCode (retCode)
{
    m_interactor = NULL;
}


ModalDialogTimer::~ModalDialogTimer ()
{
    if (m_interactor) {

        delete m_interactor;
    }
}


void ModalDialogTimer::SetModalDialog (wxDialog *dialog)
{
    m_dialog = dialog;
}


void ModalDialogTimer::SetModalDialogInteractor (ModalDialogInteractionInterface *interactor)
{
    m_interactor = interactor;
}


bool ModalDialogTimer::Start (int milliseconds, bool oneShot)
{
    if (oneShot == false) {

        throw sw::WxLogicErrorException ("Only one-shot timer is allowed");
    }
    return wxTimer::Start (milliseconds, oneShot);
}


void ModalDialogTimer::Notify ()
{
    // GUI interaction is only allowed if the timer is actually fired in the
    // main thread:
    if (!wxThread::IsMain()) {
        throw sw::WxLogicErrorException ("not main thread");
    }

    if (m_interactor) {

        m_interactor->Execute ();
    }

    wxCommandEvent event;
    if (m_retCode == wxID_CANCEL) {
    
        // Cannot access protected in wxWidgets 2.8:
        //m_dialog->EndDialog (m_retCode);
        this->EndDialog ();

    } else if (m_retCode == wxID_OK) {

        // Cannot access protected in wxWidgets 2.8:
		//m_dialog->AcceptAndClose ();
        if (m_dialog->Validate () && m_dialog->TransferDataFromWindow ()) {

            this->EndDialog ();
        }

    } else {

        wxFAIL_MSG ("Invalid return code");
    }
}
 

void ModalDialogTimer::EndDialog ()
{
    if (m_dialog->IsModal ())
        m_dialog->EndModal (m_retCode);
    else
        m_dialog->Hide ();
}

} // End namespace swTst
