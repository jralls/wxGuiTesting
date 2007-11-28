///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swMdiDefaultDialog.h
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Fuereder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWMDIDEFAULTDIALOG_H
#define SWMDIDEFAULTDIALOG_H

#ifdef __GNUG__
    #pragma interface "swMdiDefaultDialog.h"
#endif

#include "Common.h"

#include <wx/docview.h>
#include <wx/dialog.h>

#include "swDefaultDialog.h"
#include "swMdiMainFrame.h"

namespace sw {


class MdiDefaultDialog : public DefaultDialog, public wxDialog
{
public:
	MdiDefaultDialog (MainFrame *parent, long style = wxDEFAULT_DIALOG_STYLE);
	virtual wxWindow *GetWindow ();
	virtual wxDialog *GetDialog ();

};

} // End namespace sw

#endif // SWMDIDEFAULTDIALOG_H
