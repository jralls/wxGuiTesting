///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/ModalDialogManipulator.h
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef MODALDIALOGMANIPULATOR_H
#define MODALDIALOGMANIPULATOR_H

#ifdef __GNUG__
    #pragma interface "ModalDialogManipulator.h"
#endif

#include <wxGuiTest/ModalDialogInteractionInterface.h>

#include <wx/textctrl.h>

namespace wxTst {


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

} // End namespace wxTst

#endif // MODALDIALOGMANIPULATOR_H
