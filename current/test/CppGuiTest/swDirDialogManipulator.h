///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/swDirDialogManipulator.h
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef DIRDIALOGMANIPULATOR_H
#define DIRDIALOGMANIPULATOR_H

#ifdef __GNUG__
    #pragma interface "swDirDialogManipulator.h"
#endif

#include <wxGuiTest/ModalDialogInteractionInterface.h>

class wxDirDialog;

namespace wxTst {


/*! \class DirDialogManipulator
    \brief Manipulate DirDialog.
*/
class DirDialogManipulator : public ModalDialogInteractionInterface
{
public:
    /*! \fn DirDialogManipulator (wxDirDialog *dialog)
        \brief Constructor
    */
    DirDialogManipulator (wxDirDialog *dialog);
    
    
    /*! \fn virtual void Execute ()
        \brief Set the path of the DirDialog.
    */
    virtual void Execute ();

private:
    wxDirDialog *m_dialog;
};

} // End namespace wxTst

#endif // DIRDIALOGMANIPULATOR_H
