///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swMainFrame.h
// Author:      Yann Rouillard, Viet Bui Xuan
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWMAINFRAME_H
#define SWMAINFRAME_H

#ifdef __GNUG__
    #pragma interface "swMainFrame.h"
#endif

#include <wxGuiTest/Common.h>

#include "swWindow.h"

namespace sw {


class MainFrame: public Window
{
public:
	virtual ~MainFrame ();

	wxWindow *GetWindow () const;
	virtual wxFrame *GetFrame() const = 0;

};

} // End namespace sw

#endif // SWMAINFRAME_H
