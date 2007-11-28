///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swDirDialogManipulator.cpp
// Author:      Reinhold F�reder
// Created:     2006
// Copyright:   (c) 2006 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swDirDialogManipulator.h"
#endif

#include "swDirDialogManipulator.h"

#include "wx/dirdlg.h"

namespace swTst {


DirDialogManipulator::DirDialogManipulator (wxDirDialog *dialog)
{
    m_dialog = dialog;
}


void DirDialogManipulator::Execute ()
{
    // C2027 error for wx 2.7.0.1 under MSW and VS6! But no problem because the
    // concept of testing standard modal dialogs fails in any case :-|
    //m_dialog->SetPath ("z:\\test");
}

} // End namespace swTst
