///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/swApp.cpp
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swApp.h"
#endif

#include "swApp.h"

namespace sw {


App* App::ms_instance = NULL;


App::App ()
{
	wxASSERT (ms_instance == NULL);

	ms_instance = this;
}


App::~App ()
{
    // Nothing to do
}


App *App::GetInstance ()
{
	return ms_instance;
}


void App::SetInstance (App *app)
{
    wxASSERT (app != NULL);

    App::Nullify ();
    ms_instance = app;
}


void App::Nullify ()
{
    if (ms_instance != NULL) {

        // This causes an exception:
        //delete ms_instance;
        ms_instance = NULL;
    }
}

} // End namespace sw
