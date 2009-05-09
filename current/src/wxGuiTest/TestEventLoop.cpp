///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/TestEventLoop.cpp
// Author:      John Ralls
// Created:     2009
// Copyright:   (c) 2009 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////


#include <wxGuiTest/TestEventLoop.h>
#include <wxGuiTest/WxGuiTestApp.h>
#include <wx/event.h>
#include <wxGuiTest/EventQueue.h>

using namespace wxTst;

int
wxTestEventLoop::Run() {
    if (m_exitCode) 
	return doExitCode();
    WxGuiTestApp& app = wxGetApp();
//Clear any pending events
    while(Dispatch()) continue;
//Now retrieve events from the current queue and dispatch them, one at a time
    while (!m_exitCode && app.postNextEvent()) 
//A single queued event can cascade, so keep dispatching until done
	while (Dispatch()) continue;
//Get rid of the now-empty queue
    app.nextEventQueue();
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
    return wxGetApp().pending();
}

bool 
wxTestEventLoop::Dispatch() {
    if (wxPendingEvents == NULL || wxPendingEvents->IsEmpty()) 
	return false;
    wxList::compatibility_iterator node = wxPendingEvents->GetFirst();
    if (node == NULL) return false;
    wxEvtHandler* handler = (wxEvtHandler*)node->GetData();
    wxPendingEvents->Erase(node);
    handler->ProcessPendingEvents();
    if (wxPendingEvents->IsEmpty() && !wxGetApp().pending())
	return false;
    return true;
}
