///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swFrameFactory.cpp
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swFrameFactory.h"
#endif

#include "swFrameFactory.h"

#include "swToolBarRegistry.h"

namespace sw {


FrameFactory *FrameFactory::ms_instance = NULL;


FrameFactory::FrameFactory ()
{
    // Nothing to do
}


FrameFactory::~FrameFactory ()
{
	if (ms_instance == this) {

		ms_instance = NULL;
	}
}


FrameFactory * FrameFactory::GetInstance ()
{
	return ms_instance;
}


void FrameFactory::SetInstance (FrameFactory *frameFactory)
{
	if (ms_instance != NULL) {

		delete ms_instance;
	}
	ms_instance = frameFactory;
}


ToolBar * FrameFactory::CreateNamedToolBar (const wxString &name,
            const long style)
{
    ToolBar *toolbar = this->CreateToolBar (style);
    wxASSERT (toolbar != NULL);

    ToolBarRegistry::GetInstance ()->Register (toolbar, name);

    return toolbar;
}

} // End namespace sw
