///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swMainFrame.cpp
// Author:      Yann Rouillard, Viet Bui Xuan
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swMainFrame.h"
#endif

#include "swMainFrame.h"

namespace sw {


MainFrame::~MainFrame () 
{

}

wxWindow *MainFrame::GetWindow () const
{
	return GetFrame ();
}

} // End namespace sw
