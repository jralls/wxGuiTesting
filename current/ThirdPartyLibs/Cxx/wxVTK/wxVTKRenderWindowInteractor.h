/*=========================================================================

  Program:   Visualization Toolkit
  Module:    wxVTKRenderWindowInteractor.h
  Language:  C++

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

// .NAME  wxVTKRenderWindowInteractor - class to enable VTK to render to 
// and interact with wxWindow.
// .SECTION Description
//  wxVTKRenderWindowInteractor provide a VTK widget for wxWindow. This class
// was completely rewrote to have the 'Look & Feel' of the python version:
// wxVTKRenderWindowInteractor.py
// .SECTION Caveats 
//  - There is a know bug that prevent this class to works for more info see 
// WX_USE_X_CAPTURE. This bug only affect wxGTK from 2.3.2 to wxGTK 2.4.0.
//  - Furthermore this class is tempated over either wxWindows or wxGLCanvas,
// in wxWindows 2.3.1 and earlier, the wxGLCanvas had scroll bars, you can avoid
// this effect by playing with WX_BASE_CLASS at your risk (you might end up with
// lot of flickering.)
//  - This class might not be easily readable as it tried to work with VTK 3.2
//  and 4.x. This class doesn't support reparenting with VTK 4.2 and earlier.
// .SECTION see also
// wxVTKRenderWindowInteractor.py wxVTKRenderWindow.py
//
// Slightly modified version from Mathieu Malaterre's wxVTK project by
// Viet Bui Xuan and Reinhold Füreder.

#ifndef _wxVTKRenderWindowInteractor_h_
#define _wxVTKRenderWindowInteractor_h_

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#  pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/timer.h>
#include <wx/dcclient.h>

// vtk includes
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderWindow.h"

#ifdef __WXGTK__
#  if wxUSE_GLCANVAS
#    include <wx/glcanvas.h>
#  else
#    error "problem of wxGLCanvas, you need to build wxWidgets with opengl"
#  endif //wxUSE_GLCANVAS
#endif //__WXGTK__

// Motif version (renamed into wxX11 for wxWindow 2.4 and newer)
#if defined(__WXMOTIF__) 
# error This GUI is not supported by wxVTKRenderWindowInteractor for now
#endif

// wx forward declarations
class wxPaintEvent;
class wxMouseEvent;
class wxTimerEvent;
class wxKeyEvent;
class wxSizeEvent;

#ifdef __WXGTK__
class VTK_RENDERING_EXPORT wxVTKRenderWindowInteractor : public wxGLCanvas, virtual public vtkRenderWindowInteractor
#else
class VTK_RENDERING_EXPORT wxVTKRenderWindowInteractor : public wxWindow, virtual public vtkRenderWindowInteractor
#endif //__WXGTK__
{
  DECLARE_DYNAMIC_CLASS(wxVTKRenderWindowInteractor)
  
  public:
    //constructors
    wxVTKRenderWindowInteractor();

    wxVTKRenderWindowInteractor(wxWindow *parent,
                                wxWindowID id,
                                const wxPoint &pos = wxDefaultPosition,
                                const wxSize &size = wxDefaultSize,
                                long style = wxWANTS_CHARS | wxNO_FULL_REPAINT_ON_RESIZE,
                                const wxString &name = wxPanelNameStr);
	//vtk ::New()
    static wxVTKRenderWindowInteractor * New();
    void PrintSelf(ostream& os, vtkIndent indent);

	 //destructor
    ~wxVTKRenderWindowInteractor();

    // vtkRenderWindowInteractor overrides
    void Initialize();
    void Enable();
    bool Enable(bool enable);
    void Disable();
    void Start();
    void UpdateSize(int x, int y);
    int CreateTimer(int timertype);
    int DestroyTimer();
    void TerminateApp() {};

    // event handlers
    void OnPaint(wxPaintEvent &event);
    void OnEraseBackground (wxEraseEvent& event);
    void OnMotion(wxMouseEvent &event);

    void OnButtonDown(wxMouseEvent &event);
    void OnButtonUp(wxMouseEvent &event);
#if !(VTK_MAJOR_VERSION == 3 && VTK_MINOR_VERSION == 1)
    void OnEnter(wxMouseEvent &event);
    void OnLeave(wxMouseEvent &event);
    void OnKeyDown(wxKeyEvent &event);
    void OnChar(wxKeyEvent &event);
    void OnKeyUp(wxKeyEvent &event);
#endif
    void OnTimer(wxTimerEvent &event);
    void OnSize(wxSizeEvent &event);

    void Render();
    void SetRenderWhenDisabled(int newValue);

    // Description:
    // Prescribe that the window be created in a stereo-capable mode. This
    // method must be called before the window is realized. Default if off.
    vtkGetMacro(Stereo,int);
    vtkBooleanMacro(Stereo,int);
    virtual void SetStereo(int capable);

    // Description:
    // As CaptureMouse could be a problem sometimes on a window box
    // This method allow to set or not the CaptureMouse.
    // This method actually will works only if WX_USE_X_CAPTURE was set to 1
    vtkSetMacro(UseCaptureMouse,int);
    vtkBooleanMacro(UseCaptureMouse,int);


    /*! \fn void SetKeyDownKeyRange (char key1, char key2)
        \brief Keys in the given range will not create EVT_CHAR events!!!

        This is necessary as keeping keys pressed for constrained positioning
        does not work acceptable otherwise (too many interruptions?).

        wxWidgets documentation: "If a key down (EVT_KEY_DOWN) event is caught
          and the event handler does not call event.Skip() then the
          coresponding char event (EVT_CHAR) will not happen. This is by design
          and enables the programs that handle both types of events to be a bit
          simpler."

        \param key1 start of key range (includes key1)
        \param key2 end of key range (includes key2)
    */
    void SetKeyDownKeyRange (char key1, char key2);

  protected:
    wxTimer timer;
    int ActiveButton;
    int RenderAllowed;
    long GetHandleHack();
    int Stereo;


    /*! \fn bool IsInKeyDownRange (char key) const
        \brief Check if the given key is within the special key down range.

        \param key key to check
        \return true, if key is in specified key down range
    */
    bool IsInKeyDownRange (char key) const;
    
  private:
    long Handle;
    bool Created;
    int RenderWhenDisabled;
    int UseCaptureMouse;

    char m_keyDown1, m_keyDown2;
    char m_oldKeyDown;

    DECLARE_EVENT_TABLE()
};

#endif //_wxVTKRenderWindowInteractor_h_
