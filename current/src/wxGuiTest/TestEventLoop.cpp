///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/TestEventLoop.cpp
// Author:      John Ralls
// Created:     2009
// Copyright:   (c) 2009 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#include <wxGuiTest/TestEventLoop.h>
#incldue "EventQueue.h"

using namespace wxTst;

int
wxTestEventLoop::Run() {
    if (m_exitCode) 
	return doExitCode();
    wxTestGuiApp* app = dynamic_cast<wxTestGuiApp>(wxTheApp);
    wxASSERT_MSG(app, 
		 _T("Attempting to run TestEventLoop with a regular wxApp"));
    app->popEventQueue();
    while (!m_exitCode && Dispatch());
    return doExitCode();
}

void
wxTestEventLoop::Exit(int exitCode) {
    m_exitCode = exitCode;
}

bool
wxTestEventLoop::Pending() const {
    if (wxPendingEvents && !wxPendingEvents->IsEmpty())
	return true;
    wxTestGuiApp* app = dynamic_cast<wxTestGuiApp>(wxTheApp);
    wxASSERT_MSG(app, 
		 _T("Attempting to run TestEventLoop with a regular wxApp"));
    return app->pending();
}

bool 
wxTestEventLoop::Dispatch() {
    wxTestGuiApp* app = dynamic_cast<wxTestGuiApp>(wxTheApp);
    wxASSERT_MSG(app, 
		 _T("Attempting to run TestEventLoop with a regular wxApp"));
    if (wxPendingEvents && !wxPendingEvents->IsEmpty()) {
    wxList::compatibility_iterator node = wxPendingEvents->GetFirst();
    if (node) {
	wxEvtHandler* handler = (wxEvtHandler*)node->GetData();
	wxPendingEvents->Erase(node);
	handler->ProcessPendingEvents();
	if (wxPendingEvents->IsEmpty() && !app->pending())
	    return false;
	else return true;
    }
    if (!app->pending()) return false;
    app->postNextEvent();
    return this->Dispatch();
}
