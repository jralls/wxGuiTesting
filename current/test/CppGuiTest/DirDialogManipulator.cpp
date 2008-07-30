///////////////////////////////////////////////////////////////////////////////
// Name:        test/CppGuiTest/DirDialogManipulator.cpp
// Author:      Reinhold Fuereder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "DirDialogManipulator.h"
#endif

#include "DirDialogManipulator.h"

#include <wx/dialog.h>
#include <wx/dirdlg.h>

namespace wxTst {


DirDialogManipulator::DirDialogManipulator (wxDirDialog *dialog)
{
    m_dialog = dialog;
}


void DirDialogManipulator::Execute ()
{
    // C2027 error for wx 2.7.0.1 under M and VS6! But no problem because the
    // concept of testing standard modal dialogs fails in any case :-|
    //m_dialog->SetPath ("z:\\test");
#ifdef __WXGTK__
	m_dialog->SetPath(_T("~/"));
#endif
}

} // End namespace wxTst
