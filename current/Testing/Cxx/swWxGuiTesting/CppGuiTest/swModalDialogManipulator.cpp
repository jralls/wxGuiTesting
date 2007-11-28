///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swModalDialogManipulator.cpp
// Author:      Reinhold Füreder
// Created:     2006
// Copyright:   (c) 2006 Reinhold Füreder
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
    m_textCtrl->SetValue ("hello");
}

} // End namespace swTst
