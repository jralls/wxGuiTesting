///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swMdiDefaultDialog.cpp
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold F�reder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swMdiDefaultDialog.h"
#endif

#include "swMdiDefaultDialog.h"

namespace sw {


MdiDefaultDialog::MdiDefaultDialog(MainFrame *parent, long style)
	: wxDialog((wxWindow *) (parent->GetFrame()), -1,
            "title set in MdiDefaultDialog constructor", wxDefaultPosition,
            wxDefaultSize, style)
{
	// Nothing to do
}

wxWindow *MdiDefaultDialog::GetWindow()
{
	return (wxWindow *)this;
}


wxDialog *MdiDefaultDialog::GetDialog()
{
	return (wxDialog *)this;
}

} // End namespace sw
