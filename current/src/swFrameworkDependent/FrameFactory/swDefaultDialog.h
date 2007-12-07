///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swDefaultDialog.h
// Author:      Viet Bui Xuan
// Created:     2002
// Copyright:   (c) 2002 Viet Bui Xuan
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWDEFAULTDIALOG_H
#define SWDEFAULTDIALOG_H

#ifdef __GNUG__
    #pragma interface "swDefaultDialog.h"
#endif

#include <wxGuiTest/Common.h>

#include <wx/docview.h>

#include "swMainFrame.h"

namespace sw {


// TODO make difference between FLDefaultDialog and MDIDefaultDialog
class DefaultDialog
{
public:
	DefaultDialog ();
	~DefaultDialog ();

	virtual wxWindow *GetWindow () = 0;
	virtual wxDialog *GetDialog () = 0;

};

} // End namespace sw

#endif // SWDEFAULTDIALOG_H
