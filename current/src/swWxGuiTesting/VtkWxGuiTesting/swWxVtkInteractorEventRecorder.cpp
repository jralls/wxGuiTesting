///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/VtkWxGuiTesting/swWxVtkInteractorEventRecorder.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swWxVtkInteractorEventRecorder.h"
#endif

#include <wxGuiTest/VtkGuiTesting/swWxVtkInteractorEventRecorder.h>

#include <vtkCallbackCommand.h>
#include <vtkObjectFactory.h>
#include <vtkRenderWindowInteractor.h>

#include <vtkCamera.h>
#include <vtkRenderWindow.h>
#include <vtkRendererCollection.h>

#include <stack>
#include <string>
#include <sstream>
#include <cstdio>

#include <wx/window.h>

#include <wxVTKRenderWindowInteractor.h>

namespace swTst {


vtkCxxRevisionMacro(WxVtkInteractorEventRecorder, "$Revision: 1.5 $");
vtkStandardNewMacro(WxVtkInteractorEventRecorder);

float WxVtkInteractorEventRecorder::StreamVersion = 2.0;


WxVtkInteractorEventRecorder::WxVtkInteractorEventRecorder ()
{
    //take over the processing of delete and keypress events from the superclass
    this->KeyPressCallbackCommand->SetCallback (
            WxVtkInteractorEventRecorder::ProcessCharEvent);

    this->Priority = VTK_LARGE_FLOAT; //get events first
    this->EventCallbackCommand->SetCallback (
            WxVtkInteractorEventRecorder::ProcessEvents);

    this->FileName = NULL;

    this->State = WxVtkInteractorEventRecorder::Start;
    this->InputStream = NULL;
    this->OutputStream = NULL;

    this->ReadFromInputString = 0;
    this->InputString = NULL;
}


WxVtkInteractorEventRecorder::~WxVtkInteractorEventRecorder ()
{
    this->ClearInteractors ();

    if (this->FileName) {

        delete [] this->FileName;
    }

    if (this->InputStream) {

        delete this->InputStream;
        this->InputStream = NULL;
    }

    if (this->OutputStream) {

        delete this->OutputStream;
        this->OutputStream = NULL;
    }

    if (this->InputString) {

        delete [] this->InputString;
        this->InputString = NULL;
    }

    // wxVtkRwi as part of m_wxVtkMap is deleted elsewhere:
    WxVtkMap::iterator it;
    for (it = m_wxVtkMap.begin (); it != m_wxVtkMap.end (); it++) {

        if ((*it).second->camera != NULL) {

            (*it).second->camera->Delete ();
            (*it).second->camera = NULL;
        }

        (*it).second->wxVtkRwi = NULL;
        delete (*it).second;
    }
    m_wxVtkMap.clear ();
}


void WxVtkInteractorEventRecorder::SetEnabled (int enabling)
{
    if (m_wxVtkMap.empty ()) {

        vtkErrorMacro (<< "Interactors must be set prior to enabling/disabling widget");
        return;
    }

    if (enabling) //----------------------------------------------------------
    {
        
        vtkDebugMacro(<< "Enabling widget");

        if (this->Enabled) {//already enabled, just return
    
            return;
        }

        this->Enabled = 1;

        // listen to any event
        WxVtkMap::iterator it;
        for (it = m_wxVtkMap.begin (); it != m_wxVtkMap.end (); it++) {

            (*it).second->wxVtkRwi->AddObserver (vtkCommand::AnyEvent,
                    this->EventCallbackCommand, this->Priority);
        }

        this->InvokeEvent (vtkCommand::EnableEvent, NULL);

    } else {//disabling-----------------------------------------------------------
    
        vtkDebugMacro (<< "Disabling widget");

        if (!this->Enabled) {//already disabled, just return

            return;
        }

        this->Enabled = 0;

        // don't listen for events any more
        WxVtkMap::iterator it;
        for (it = m_wxVtkMap.begin (); it != m_wxVtkMap.end (); it++) {

            (*it).second->wxVtkRwi->RemoveObserver (this->EventCallbackCommand);
        }

        this->InvokeEvent (vtkCommand::DisableEvent, NULL);
    }
}


void WxVtkInteractorEventRecorder::Record()
{
    if (this->State == WxVtkInteractorEventRecorder::Start) {

        if (!this->OutputStream) {//need to open file

            this->OutputStream = new ofstream (this->FileName, ios::out);
            if (this->OutputStream->fail ()) {

                vtkErrorMacro (<< "Unable to open file: " << this->FileName);
                delete this->OutputStream;
                this->OutputStream = NULL;
                return;
            }
            *this->OutputStream << "# StreamVersion " <<
                    WxVtkInteractorEventRecorder::StreamVersion << "\n";
        }

        vtkDebugMacro (<< "Recording");
        this->State = WxVtkInteractorEventRecorder::Recording;

        // Save scene settings: size of render window, camera settings, ...
        //-----------------------------
        WxVtkMap::iterator it;
        for (it = m_wxVtkMap.begin (); it != m_wxVtkMap.end (); it++) {

            if ((*it).second->camera != NULL) {

                (*it).second->camera->Delete ();
                (*it).second->camera = NULL;
            }

            wxWindow *interactorWdw = (*it).second->wxVtkRwi;
            // Save size of wx containers up to the top level container (first):
            wxWindow *wdw = interactorWdw;
            (*it).second->sizeList.push_front (wdw->GetSize ());
            while (wdw->GetParent () != NULL) {
                    
                wdw = wdw->GetParent ();
                (*it).second->sizeList.push_front (wdw->GetSize ());
            }
            // Position of rootWdw = top level container:
            (*it).second->position = wdw->GetPosition ();
            // And camera:
            vtkRenderWindow *renderWdw = (*it).second->wxVtkRwi->GetRenderWindow ();
            vtkRendererCollection *renderers = renderWdw->GetRenderers ();
            wxASSERT_MSG (renderers->GetNumberOfItems () > 0,
                    _T("At least one renderer must exist in each render window; and only the first one is fully supported."));
			if (renderers->GetNumberOfItems () != 1) {

                ::wxLogTrace (_T("VtkWxGuiTesting"),
                        _T("Currently only one renderer per render window interactor is supported"));
			}
            vtkRenderer *renderer = renderers->GetFirstRenderer ();
            vtkCamera *activeCamera = renderer->GetActiveCamera ();
            (*it).second->camera = vtkCamera::New ();
            (*it).second->camera->SetParallelScale (activeCamera->GetParallelScale ());
            (*it).second->camera->SetViewAngle (activeCamera->GetViewAngle ());
            (*it).second->camera->SetClippingRange (activeCamera->GetClippingRange ());
            (*it).second->camera->SetFocalPoint (activeCamera->GetFocalPoint ());
            (*it).second->camera->SetPosition (activeCamera->GetPosition ());
            (*it).second->camera->SetViewUp (activeCamera->GetViewUp ());
        }
        //-----------------------------
    }
}


void WxVtkInteractorEventRecorder::RestoreWxVtkSettings ()
{
    WxVtkMap::iterator it;
    for (it = m_wxVtkMap.begin (); it != m_wxVtkMap.end (); it++) {

        wxASSERT ((*it).second->camera != NULL);

        wxWindow *interactorWdw = (*it).second->wxVtkRwi;
        // Restoring sizes must happend from top level container to wxVtkRwi:
        std::stack< wxWindow *, std::list< wxWindow * > > wdwStack;

        wxWindow *wdw = interactorWdw;
        wdwStack.push (wdw);
        while (wdw->GetParent () != NULL) {

            wdw = wdw->GetParent ();
            wdwStack.push (wdw);
        }
        // Position of rootWdw = top level container:
        wdw->SetPosition ((*it).second->position);

        // Save size of wx containers up to the top level container (first):
        SizeList::const_iterator sizeIt = (*it).second->sizeList.begin ();
        while ((!wdwStack.empty ()) &&
                (sizeIt != (*it).second->sizeList.end ())) {

            wdwStack.top ()->SetSize (*sizeIt);
            wdwStack.pop ();
            sizeIt++;
        }
        // And camera:
        vtkRenderWindow *renderWdw = (*it).second->wxVtkRwi->GetRenderWindow ();
        vtkRendererCollection *renderers = renderWdw->GetRenderers ();
        wxASSERT_MSG (renderers->GetNumberOfItems () > 0,
                _T("At least one renderer must exist in each render window; and only the first one is fully supported."));
		if (renderers->GetNumberOfItems () != 1) {

            ::wxLogTrace (_T("VtkWxGuiTesting"),
                    _T("Currently only one renderer per render window interactor is supported"));
		}
        vtkRenderer *renderer = renderers->GetFirstRenderer ();
        vtkCamera *activeCamera = renderer->GetActiveCamera ();
        renderer->GetActiveCamera ()->SetParallelScale ((*it).second->camera->GetParallelScale ());
        renderer->GetActiveCamera ()->SetViewAngle ((*it).second->camera->GetViewAngle ());
        renderer->GetActiveCamera ()->SetClippingRange ((*it).second->camera->GetClippingRange ());
        renderer->GetActiveCamera ()->SetFocalPoint ((*it).second->camera->GetFocalPoint ());
        renderer->GetActiveCamera ()->SetPosition ((*it).second->camera->GetPosition ());
        renderer->GetActiveCamera ()->SetViewUp ((*it).second->camera->GetViewUp ());
    }
}


const WxVtkInteractorEventRecorder::WxVtkMap &
WxVtkInteractorEventRecorder::GetWxVtkMap () const
{
    return m_wxVtkMap;
}


void WxVtkInteractorEventRecorder::Play ()
{
    if (this->State == WxVtkInteractorEventRecorder::Start) {

        if (this->ReadFromInputString) {

            vtkDebugMacro (<< "Reading from InputString");
            int len;
            if ((this->InputString == NULL) ||
                    (len = strlen (this->InputString) <= 0)) {
        
                vtkErrorMacro (<< "No input string specified");
                return;
            }
            this->InputStream = new istrstream (this->InputString, len);
            if (this->InputStream->fail ()) {

                vtkErrorMacro (<< "Unable to read from string");
                delete this->InputStream;
                this->InputStream = NULL;
                return;
            }

        } else {

            if (!this->InputStream) {//need to open file

                this->InputStream = new ifstream (this->FileName, ios::in);
                if (this->InputStream->fail ()) {

                    vtkErrorMacro (<< "Unable to open file: "<< this->FileName);
                    delete this->InputStream;
                    this->InputStream = NULL;
                    return;
                }
            }
        }

        // Restore scene settings: size of render window, camera settings, ...
        //-----------------------------
/*        WxVtkMap::iterator it;
        for (it = m_wxVtkMap.begin (); it != m_wxVtkMap.end (); it++) {

            wxASSERT ((*it).second->camera != NULL);

            wxWindow *interactorWdw = (*it).second->wxVtkRwi;
            // Restoring sizes must happend from top level container to wxVtkRwi:
            std::stack< wxWindow *, std::list< wxWindow * > > wdwStack;

            wxWindow *wdw = interactorWdw;
            wdwStack.push (wdw);
            while (wdw->GetParent () != NULL) {
    
                wdw = wdw->GetParent ();
                wdwStack.push (wdw);
            }
            // Position of rootWdw = top level container:
            wdw->SetPosition ((*it).second->position);

            // Save size of wx containers up to the top level container (first):
            SizeList::const_iterator sizeIt = (*it).second->sizeList.begin ();
            while ((!wdwStack.empty ()) &&
                    (sizeIt != (*it).second->sizeList.end ())) {

                wdwStack.top ()->SetSize (*sizeIt);
                wdwStack.pop ();
                sizeIt++;
            }
            // And camera:
            vtkRenderWindow *renderWdw = (*it).second->wxVtkRwi->GetRenderWindow ();
            vtkRendererCollection *renderers = renderWdw->GetRenderers ();
            wxASSERT_MSG (renderers->GetNumberOfItems () > 0,
                    _T("At least one renderer must exist in each render window; and only the first one is fully supported."));
			if (renderers->GetNumberOfItems () != 1) {

				::wxLogTrace (_T("VtkWxGuiTesting"),
						_T("Currently only one renderer per render window interactor is supported"));
			}
            vtkRenderer *renderer = renderers->GetFirstRenderer ();
            vtkCamera *activeCamera = renderer->GetActiveCamera ();
            renderer->GetActiveCamera ()->SetParallelScale ((*it).second->camera->GetParallelScale ());
            renderer->GetActiveCamera ()->SetViewAngle ((*it).second->camera->GetViewAngle ());
            renderer->GetActiveCamera ()->SetClippingRange ((*it).second->camera->GetClippingRange ());
            renderer->GetActiveCamera ()->SetFocalPoint ((*it).second->camera->GetFocalPoint ());
            renderer->GetActiveCamera ()->SetPosition ((*it).second->camera->GetPosition ());
            renderer->GetActiveCamera ()->SetViewUp ((*it).second->camera->GetViewUp ());
        }
*/
        //-----------------------------

        vtkDebugMacro (<< "Playing");
        this->State = WxVtkInteractorEventRecorder::Playing;

        // Read events and invoke them on the object in question
        char event[128], keySym[64], buffer[512], wxVtkId[60];
        int pos[2], ctrlKey, shiftKey, keyCode, repeatCount;
        float stream_version = 0.0, tempf;

        while (!this->InputStream->eof ()) {

            this->InputStream->width (256);
            *this->InputStream >> event;

            // Quick skip comment
            if (*event == '#') {

                this->InputStream->getline (buffer, 512);
                // Parse the StreamVersion (not using >> since comment could be empty)
                // Expecting: # StreamVersion x.y
                if ((strlen (buffer) > 15) &&
                        (!strncmp (buffer, " StreamVersion ", 15))) {

                    int res = sscanf (buffer + 15, "%f", &tempf);
                    if (res && res != EOF) {

                        stream_version = tempf;
                    }
                }

            } else {

                unsigned long ievent = vtkCommand::GetEventIdFromString (event);
                if (ievent == vtkCommand::NoEvent) {

                    this->InputStream->ignore (512, '\n');

                } else {

                    if (stream_version >= 1.1) {

                        // We could grab the time info here
                    }
                    *this->InputStream >> pos[0];
                    *this->InputStream >> pos[1];
                    *this->InputStream >> ctrlKey;
                    *this->InputStream >> shiftKey;
                    *this->InputStream >> keyCode;
                    *this->InputStream >> repeatCount;
                    *this->InputStream >> keySym;
                    *this->InputStream >> wxVtkId;

                    wxVTKRenderWindowInteractor *wxVtkRwi =
                            WxVtkInteractorEventRecorder::GetInteractor (
                            wxString (wxVtkId, *wxConvCurrent));
                    wxASSERT (wxVtkRwi != NULL);

                    wxVtkRwi->SetEventPosition (pos);
                    wxVtkRwi->SetControlKey (ctrlKey);
                    wxVtkRwi->SetShiftKey (shiftKey);
                    wxVtkRwi->SetKeyCode (keyCode);
                    wxVtkRwi->SetRepeatCount (repeatCount);
                    wxVtkRwi->SetKeySym (keySym);

                    wxVtkRwi->InvokeEvent (ievent, NULL);
                }
            }
        }
    }

    this->State = WxVtkInteractorEventRecorder::Start;
}


void WxVtkInteractorEventRecorder::Stop()
{
    this->State = WxVtkInteractorEventRecorder::Start;
    this->Modified ();
}


void WxVtkInteractorEventRecorder::Rewind()
{
    if (!this->InputStream) {//need to already have an open file

        vtkGenericWarningMacro (<< "No input file opened to rewind...");
    }
    this->InputStream->clear ();
    this->InputStream->seekg (0);
}


// This adds the keypress event observer and the delete event observer
void WxVtkInteractorEventRecorder::SetInteractor (vtkRenderWindowInteractor *i)
{
    wxFAIL_MSG (_T("Change of class interface: use AddInteractor() method instead!"));

  if (i == this->Interactor)
    {
    return;
    }

  // if we already have an Interactor then stop observing it
  if (this->Interactor)
    {
    this->SetEnabled(0); //disable the old interactor
    this->Interactor->RemoveObserver(this->KeyPressCallbackCommand);
    }

  this->Interactor = i;

  // add observers for each of the events handled in ProcessEvents
  if (i)
    {
    i->AddObserver(vtkCommand::CharEvent, 
                   this->KeyPressCallbackCommand, this->Priority);
    i->AddObserver(vtkCommand::DeleteEvent, 
                   this->KeyPressCallbackCommand, this->Priority);
    }
  
  this->Modified();
}


void WxVtkInteractorEventRecorder::AddInteractor (const wxString &wxVtkId,
        wxVTKRenderWindowInteractor *wxVtkRwi)
{
    WxVtkMap::const_iterator it;
    
    it = m_wxVtkMap.find (wxVtkId);
    wxASSERT (it == m_wxVtkMap.end ());

    WxVtk *wxVtk = new WxVtk ();
    wxVtk->wxVtkRwi = wxVtkRwi;
    wxVtk->camera = NULL;
    m_wxVtkMap[wxVtkId] = wxVtk;

    // See SetInteractor() method for required cleaner implementation in case
    // of supporting RemoveInteractor() functionality.
    wxVtkRwi->AddObserver (vtkCommand::CharEvent,
            this->KeyPressCallbackCommand, this->Priority);
    wxVtkRwi->AddObserver (vtkCommand::DeleteEvent, 
            this->KeyPressCallbackCommand, this->Priority);

    this->Modified();
}


wxVTKRenderWindowInteractor * WxVtkInteractorEventRecorder::GetInteractor (
        const wxString &wxVtkId) const
{
    WxVtkMap::const_iterator it = m_wxVtkMap.find (wxVtkId);

    return (it == m_wxVtkMap.end () ? NULL : (*it).second->wxVtkRwi);
}


wxString WxVtkInteractorEventRecorder::GetInteractorId (
            wxVTKRenderWindowInteractor *wxVtkRwi) const
{
    bool found = false;
    WxVtkMap::const_iterator it = m_wxVtkMap.begin ();
    while ((!found) && (it != m_wxVtkMap.end ())) {

        if ((*it).second->wxVtkRwi == wxVtkRwi) {

            found = true;

        } else {

            it++;
        }
    }

    return (it == m_wxVtkMap.end () ? _T("") : (*it).first);
}


void WxVtkInteractorEventRecorder::ClearInteractors ()
{
    this->SetEnabled (0); //disable the old interactors

    WxVtkMap::iterator it;
    for (it = m_wxVtkMap.begin (); it != m_wxVtkMap.end (); it++) {

        if ((*it).second->camera != NULL) {

            (*it).second->camera->Delete ();
            (*it).second->camera = NULL;
        }
        if ((*it).second->wxVtkRwi != NULL) {

            (*it).second->wxVtkRwi->RemoveObserver (this->KeyPressCallbackCommand);
            (*it).second->wxVtkRwi = NULL;
        }
        delete (*it).second;
    }
    m_wxVtkMap.clear ();

    this->Modified();
}


void WxVtkInteractorEventRecorder::ProcessCharEvent (vtkObject *object,
        unsigned long event, void* clientData, void* vtkNotUsed(callData))
{
    WxVtkInteractorEventRecorder *self = 
            reinterpret_cast< WxVtkInteractorEventRecorder * >(clientData);
    vtkRenderWindowInteractor *rwi =
            static_cast< vtkRenderWindowInteractor * >(object);

    switch (event) {

    case vtkCommand::DeleteEvent:
        // if the interactor is being deleted then remove the event handlers
        //self->SetInteractor(0);      //self->Interactor = NULL; //its going bye bye
        self->ClearInteractors ();
        break;

    case vtkCommand::CharEvent:
        if (self->KeyPressActivation) {

            if (rwi->GetKeyCode () == self->KeyPressActivationValue) {

                if (!self->Enabled) {

                    self->On ();

                } else {

                    self->Off();
                }
            }//event not aborted
        }//if activation enabled
    }
}


void WxVtkInteractorEventRecorder::ProcessEvents (vtkObject *object, 
        unsigned long event, void *clientData, void *vtkNotUsed(callData))
{
    WxVtkInteractorEventRecorder * self = 
            reinterpret_cast< WxVtkInteractorEventRecorder * >(clientData);
    wxVTKRenderWindowInteractor * wxVtkRwi = 
            dynamic_cast< wxVTKRenderWindowInteractor * >(object);
    wxString wxVtkId = self->GetInteractorId (wxVtkRwi);

    // all events are processed
    if (self->State == WxVtkInteractorEventRecorder::Recording) {

        switch (event) {

        case vtkCommand::ModifiedEvent: //dont want these
            break;

        default:
            self->WriteEvent (vtkCommand::GetStringFromEventId (event),
                    wxVtkRwi->GetEventPosition (), wxVtkRwi->GetControlKey (), 
                    wxVtkRwi->GetShiftKey (), wxVtkRwi->GetKeyCode (),
                    wxVtkRwi->GetRepeatCount (), wxVtkRwi->GetKeySym (),
                    wxConvCurrent->cWX2MB(wxVtkId));
        }
        self->OutputStream->flush ();
    }
}


void WxVtkInteractorEventRecorder::WriteEvent (const char *event, int pos[2],
        int ctrlKey, int shiftKey, int keyCode, int repeatCount, char *keySym,
        const char *wxVtkId)
{
    if (keySym == NULL) {

        keySym = "i";
    }

    *this->OutputStream << event << " " << pos[0] << " " << pos[1] << " "
                        << ctrlKey << " " << shiftKey << " "
                        << keyCode << " " << repeatCount << " "
                        << keySym << " " << wxVtkId << "\n";
}
 
 
void WxVtkInteractorEventRecorder::ReadEvent ()
{
    // Nothing to do (?)
}


void WxVtkInteractorEventRecorder::PrintSelf (ostream &os, vtkIndent indent)
{
    this->Superclass::PrintSelf (os,indent);

    if (this->FileName) {

        os << indent << "File Name: " << this->FileName << "\n";
    }

    os << indent << "ReadFromInputString: " <<
            (this->ReadFromInputString ? "On\n" : "Off\n");

    if (this->InputString) {

        os << indent << "Input String: " << this->InputString << "\n";

    } else {

        os << indent << "Input String: (None)\n";
    }
}


bool WxVtkInteractorEventRecorder::HasInputStream () const
{
    return (this->InputStream != NULL);
}


bool WxVtkInteractorEventRecorder::IsEmptyRecording () const
{
    return (!::wxFileExists (wxString(this->FileName, *wxConvCurrent)));
}


wxString WxVtkInteractorEventRecorder::GetRecordingAsEmitString (
        const wxString &tab) const
{
    std::string line;
    wxString fileContent;

    std::ifstream *inStr = new std::ifstream (this->FileName, ios::in);
    wxASSERT (!inStr->fail ());

    while (std::getline (*inStr, line)) {

        fileContent << tab << tab << tab << _T("\"") <<
                wxString (line.c_str (), *wxConvCurrent) << _T("\\n\"\n");
    }
    inStr->close ();

    return fileContent;
}


void WxVtkInteractorEventRecorder::ResetRecording ()
{
    if (this->OutputStream) {

        delete this->OutputStream;
        this->OutputStream = NULL;
    }
    if (this->InputStream) {

        delete this->InputStream;
        this->InputStream = NULL;
    }
    if (::wxFileExists (wxString (this->FileName, *wxConvCurrent))) {

        int ret = remove (this->FileName);
        wxASSERT (ret == 0);
    }

    WxVtkMap::iterator it;
    for (it = m_wxVtkMap.begin (); it != m_wxVtkMap.end (); it++) {

        if ((*it).second->camera != NULL) {

            (*it).second->camera->Delete ();
            (*it).second->camera = NULL;
        }
        (*it).second->sizeList.clear ();
    }
}

} // End namespace swTst
