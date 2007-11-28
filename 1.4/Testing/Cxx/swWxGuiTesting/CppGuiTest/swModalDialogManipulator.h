///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swModalDialogManipulator.h
// Author:      Reinhold Füreder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWMODALDIALOGMANIPULATOR_H
#define SWMODALDIALOGMANIPULATOR_H

#ifdef __GNUG__
    #pragma interface "swModalDialogManipulator.h"
#endif

#include "swModalDialogInteractionInterface.h"

#include <wx/textctrl.h>

namespace swTst {


/*! \class ModalDialogManipulator
    \brief Demonstrate interaction with modal dialog.
*/
class ModalDialogManipulator : public ModalDialogInteractionInterface
{
public:
    /*! \fn ModalDialogManipulator (wxTextCtrl *textCtrl)
        \brief Constructor
    */
    ModalDialogManipulator (wxTextCtrl *textCtrl);


    /*! \fn virtual void Execute ()
        \brief Manipulate, or interact with modal dialog before dismissing it.
    */
    virtual void Execute ();

private:
    wxTextCtrl *m_textCtrl;

};

} // End namespace swTst

#endif // SWMODALDIALOGMANIPULATOR_H
