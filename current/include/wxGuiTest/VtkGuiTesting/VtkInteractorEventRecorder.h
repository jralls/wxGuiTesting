///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/VtkWxGuiTesting/VtkInteractorEventRecorder.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef WXVTKINTERACTOREVENTRECORDER_H
#define WXVTKINTERACTOREVENTRECORDER_H

#ifdef __GNUG__
    #pragma interface "VtkInteractorEventRecorder.h"
#endif

#include <wxGuiTest/Common.h>

#include <list>
#include <map>

#include <vtkInteractorObserver.h>

class wxVTKRenderWindowInteractor;
class vtkCamera;

namespace wxTst {


/*! \class WxVtkInteractorEventRecorder
    \brief Record and play VTK events passing through wxVtkRenderWindowInteractors.

    Heavily based on standard VTK class vtkInteractorEventRecorder, but with
    support for several render window interactors, i.e. allowing multiplexing.

    vtkInteractorEventRecorder:
      Records all VTK events invoked from a vtkRenderWindowInteractor. The
      events are recorded to a file. Those events can be played back by
      invocation on an vtkRenderWindowInteractor.
      The format of the event file is simple. It is:
        EventName X Y ctrl shift keycode repeatCount keySym

    WxVtkInteractorEventRecorder uses this file during recording, and extends
    the format by appending the wxVTKRenderWindowInteractor ID.
*/
class WxVtkInteractorEventRecorder : public vtkInteractorObserver
{
public:
    // Try to save scene settings: size of render window, camera settings:
    typedef std::list< wxSize > SizeList;
    struct WxVtkStruct {
	
        wxPoint position;
        SizeList sizeList;
		vtkCamera *camera;
        wxVTKRenderWindowInteractor *wxVtkRwi;

	};
    typedef WxVtkStruct WxVtk;

    typedef std::map < wxString, WxVtk * > WxVtkMap;
    
public:
    static WxVtkInteractorEventRecorder * New ();
    vtkTypeRevisionMacro (WxVtkInteractorEventRecorder, vtkInteractorObserver);
    void PrintSelf (ostream &os, vtkIndent indent);

    // Satisfy the superclass API. Enable/disable listening for events.
    virtual void SetEnabled (int);
    virtual void SetInteractor (vtkRenderWindowInteractor *iren);

    virtual void AddInteractor (const wxString &wxVtkId,
            wxVTKRenderWindowInteractor *wxVtkRwi);

    // Description:
    // Set/Get the name of a file events should be written to/from.
    vtkSetStringMacro (FileName);
    vtkGetStringMacro (FileName);

    // Description:
    // Invoke this method to begin recording events. The events will be
    // recorded to the filename indicated.
    void Record ();

    // Description:
    // Invoke this method to begin playing events from the current position.
    // The events will be played back from the filename indicated.
    void Play ();

    // Description:
    // Invoke this method to stop recording/playing events.
    void Stop ();

    // Description:
    // Rewind to the beginning of the file.
    void Rewind ();

    bool HasInputStream () const;

    // Allows to check if something has been recorded (i.e. file exists)
    bool IsEmptyRecording () const;

    wxString GetRecordingAsEmitString (const wxString &tab) const;

    void ResetRecording ();

    // Made public for emitting by C&R:
    virtual wxVTKRenderWindowInteractor * GetInteractor (
            const wxString &wxVtkId) const;

    // Only used for testing or playback, not from C&R:
    void RestoreWxVtkSettings ();

    // Only for emitting by C&R:
    const WxVtkMap & GetWxVtkMap () const;

    // Description:
    // Enable reading from an InputString as compared to the default
    // behavior, which is to read from a file.
    vtkSetMacro (ReadFromInputString, int);
    vtkGetMacro (ReadFromInputString, int);
    vtkBooleanMacro (ReadFromInputString, int);

    // Description:
    // Set/Get the string to read from.
    vtkSetStringMacro (InputString);
    vtkGetStringMacro (InputString);

protected:
    /*! \fn WxVtkInteractorEventRecorder ()
        \brief Constructor
    */
    WxVtkInteractorEventRecorder ();


    /*! \fn virtual ~WxVtkInteractorEventRecorder ()
        \brief Destructor
    */
    virtual ~WxVtkInteractorEventRecorder ();

    //methods for processing events
    static void ProcessCharEvent (vtkObject *object, unsigned long event,
            void *clientdata, void *calldata);
    static void ProcessEvents (vtkObject *object, unsigned long event,
            void *clientdata, void *calldata);

    virtual void WriteEvent (const char *event, int pos[2], int ctrlKey,
            int shiftKey, int keyCode, int repeatCount, char *keySym,
            const char *wxVtkId);

    virtual void ReadEvent();

    // file to read/write from
    char *FileName;

    // control whether to read from string
    int ReadFromInputString;
    char *InputString;

    // for reading and writing
    istream *InputStream;
    ostream *OutputStream;

    //BTX - manage the state of the recorder
    int State;
    enum WidgetState {
        Start=0,
        Playing,
        Recording
    };
    //ETX

    static float StreamVersion;

    // Supporting multiplexing functionality:
    virtual wxString GetInteractorId (
            wxVTKRenderWindowInteractor *wxVtkRwi) const;

    virtual void ClearInteractors ();

    WxVtkMap m_wxVtkMap;

private:
    // No copy and assignment constructor:
    WxVtkInteractorEventRecorder (const WxVtkInteractorEventRecorder &rhs);
    WxVtkInteractorEventRecorder & operator= (const WxVtkInteractorEventRecorder &rhs);
};

} // End namespace wxTst

#endif // WXVTKINTERACTOREVENTRECORDER_H
