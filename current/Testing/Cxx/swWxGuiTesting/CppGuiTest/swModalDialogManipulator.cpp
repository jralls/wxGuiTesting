///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swModalDialogManipulator.cpp
// Author:      Reinhold F�reder
// Created:     2006
// Copyright:   (c) 2006 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swModalDialogManipulator.h"
#endif

#include "swModalDialogManipulator.h"

namespace swTst {


ModalDialogManipulator::ModalDialogManipulator (wxTextCtrl *textCtrl)
{
    m_textCtrl = textCtrl;
}


void ModalDialogManipulator::Execute ()
{
    m_textCtrl->SetValue (_T("hello"));
}

} // End namespace swTst
