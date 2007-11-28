/*=========================================================================

  Program:   Visualization Toolkit
  Module:    wxVTKRenderWindowInteractor.cpp
  Language:  C++

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

// Slightly modified version from Mathieu Malaterre's wxVTK project by
// Viet Bui Xuan and Reinhold F�reder.

#include "wxVTKRenderWindowInteractor.h"

//This is needed for vtk 3.1 :
#ifndef VTK_MAJOR_VERSION
#  include "vtkVersion.h"
#endif

#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
#  include "vtkCommand.h"
#else
#  include "vtkInteractorStyle.h"
#endif

//Keep this for compatibilty reason, this was introduced in wxGTK 2.4.0
#if (!wxCHECK_VERSION(2, 4, 0))
wxWindow* wxGetTopLevelParent(wxWindow *win)
{
    while ( win && !win->IsTopLevel() )
         win = win->GetParent();
    return win;
}
#endif

// To access objc calls on cocoa
#ifdef __WXCOCOA__
#ifdef VTK_USE_COCOA
#import <Cocoa/Cocoa.h>
// This trick is no longer need in VTK CVS, should get rid of that:
#define id Id
#else
#error Build mismatch you need both wxWidgets and VTK to be configure agains Cocoa to work
#endif //VTK_USE_COCOA
#endif //__WXCOCOA__

#ifdef __WXGTK__
#    include "gdk/gdkprivate.h"
#    include "gdk/gdkx.h"
#    include <wx/gtk/win_gtk.h>
#define GetXWindow(wxwin) (wxwin)->m_wxwindow ? \
                          GDK_WINDOW_XWINDOW(GTK_PIZZA((wxwin)->m_wxwindow)->bin_window) : \
                          GDK_WINDOW_XWINDOW((wxwin)->m_widget->window)
#endif

#ifdef __WXX11__
#include "wx/x11/privx.h"
#define GetXWindow(wxwin)   ((Window)(wxwin)->GetHandle())
#endif


//For more info on this class please go to:
//http://wxvtk.sf.net
//This hack is for some buggy wxGTK version:
#if wxCHECK_VERSION(2, 3, 2) && !wxCHECK_VERSION(2, 4, 1) && defined(__WXGTK__)
#  define WX_USE_X_CAPTURE 0
#else
#  define WX_USE_X_CAPTURE 1
#endif

#define ID_wxVTKRenderWindowInteractor_TIMER 1001

#ifdef __WXGTK__
IMPLEMENT_DYNAMIC_CLASS(wxVTKRenderWindowInteractor, wxGLCanvas)
#else
IMPLEMENT_DYNAMIC_CLASS(wxVTKRenderWindowInteractor, wxWindow)
#endif  //__WXGTK__

//---------------------------------------------------------------------------
#ifdef __WXGTK__
BEGIN_EVENT_TABLE(wxVTKRenderWindowInteractor, wxGLCanvas)
#else
BEGIN_EVENT_TABLE(wxVTKRenderWindowInteractor, wxWindow)
#endif //__WXGTK__
  //refresh window by doing a Render
  EVT_PAINT       (wxVTKRenderWindowInteractor::OnPaint)
  EVT_ERASE_BACKGROUND(wxVTKRenderWindowInteractor::OnEraseBackground)
  EVT_MOTION      (wxVTKRenderWindowInteractor::OnMotion)

  //Bind the events to the event converters
  EVT_LEFT_DOWN   (wxVTKRenderWindowInteractor::OnButtonDown)
  EVT_MIDDLE_DOWN (wxVTKRenderWindowInteractor::OnButtonDown)
  EVT_RIGHT_DOWN  (wxVTKRenderWindowInteractor::OnButtonDown)
  EVT_LEFT_UP     (wxVTKRenderWindowInteractor::OnButtonUp)
  EVT_MIDDLE_UP   (wxVTKRenderWindowInteractor::OnButtonUp)
  EVT_RIGHT_UP    (wxVTKRenderWindowInteractor::OnButtonUp)
#if !(VTK_MAJOR_VERSION == 3 && VTK_MINOR_VERSION == 1)
  EVT_ENTER_WINDOW(wxVTKRenderWindowInteractor::OnEnter)
  EVT_LEAVE_WINDOW(wxVTKRenderWindowInteractor::OnLeave)
// If we use EVT_KEY_DOWN instead of EVT_CHAR, capital versions
// of all characters are always returned.  EVT_CHAR also performs
// other necessary keyboard-dependent translations.
  EVT_KEY_DOWN    (wxVTKRenderWindowInteractor::OnKeyDown)
  EVT_CHAR        (wxVTKRenderWindowInteractor::OnChar)
  EVT_KEY_UP      (wxVTKRenderWindowInteractor::OnKeyUp)
#endif
  EVT_TIMER       (ID_wxVTKRenderWindowInteractor_TIMER, wxVTKRenderWindowInteractor::OnTimer)
  EVT_SIZE        (wxVTKRenderWindowInteractor::OnSize)
END_EVENT_TABLE()

//---------------------------------------------------------------------------
#ifdef __WXGTK__
wxVTKRenderWindowInteractor::wxVTKRenderWindowInteractor() : vtkRenderWindowInteractor(), wxGLCanvas(NULL, wxID_ANY, wxDefaultPosition)
#else
wxVTKRenderWindowInteractor::wxVTKRenderWindowInteractor() : vtkRenderWindowInteractor(), wxWindow()
#endif //__WXGTK__
      , timer(this, ID_wxVTKRenderWindowInteractor_TIMER)
      , ActiveButton(wxEVT_NULL)
      , RenderAllowed(0)
      , Stereo(0)
      , Handle(0)
      , Created(true)
      , RenderWhenDisabled(1)
      , UseCaptureMouse(0)
{
  this->RenderWindow = NULL;
  this->SetRenderWindow(vtkRenderWindow::New());
  this->RenderWindow->Delete();

  m_keyDown1 = 0;
  m_keyDown2 = 0;
  m_oldKeyDown = 0;
}
//---------------------------------------------------------------------------
wxVTKRenderWindowInteractor::wxVTKRenderWindowInteractor(wxWindow *parent,
                                                         wxWindowID id,
                                                         const wxPoint &pos,
                                                         const wxSize &size,
                                                         long style,
                                                         const wxString &name)
#ifdef __WXGTK__
      : vtkRenderWindowInteractor(), wxGLCanvas(parent, id, pos, size, style, name)
#else
      : vtkRenderWindowInteractor(), wxWindow(parent, id, pos, size, style, name)
#endif //__WXGTK__
      , timer(this, ID_wxVTKRenderWindowInteractor_TIMER)
      , ActiveButton(wxEVT_NULL)
      , RenderAllowed(0)
      , Stereo(0)
      , Handle(0)
      , Created(true)
      , RenderWhenDisabled(1)
      , UseCaptureMouse(0)
{
  this->RenderWindow = NULL;
  this->SetRenderWindow(vtkRenderWindow::New());
  this->RenderWindow->Delete();

  m_keyDown1 = 0;
  m_keyDown2 = 0;
  m_oldKeyDown = 0;
}
//---------------------------------------------------------------------------
wxVTKRenderWindowInteractor::~wxVTKRenderWindowInteractor()
{
}
//---------------------------------------------------------------------------
wxVTKRenderWindowInteractor * wxVTKRenderWindowInteractor::New()
{
  // we don't make use of the objectfactory, because we're not registered
  return new wxVTKRenderWindowInteractor;
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::Initialize()
{
  int *size = RenderWindow->GetSize();
  // enable everything and start rendering
  Enable();
  //RenderWindow->Start();

  // set the size in the render window interactor
  Size[0] = size[0];
  Size[1] = size[1];

  // this is initialized
  Initialized = 1;
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::Enable()
{
  // if already enabled then done
  if (Enabled)
    return;

  // that's it
  Enabled = 1;
#ifdef __WXGTK__
  this->SetCurrent();
#endif
  Modified();
}
//---------------------------------------------------------------------------
bool wxVTKRenderWindowInteractor::Enable(bool enable)
{
#ifdef __WXGTK__
  return wxGLCanvas::Enable(enable);
#else
  return wxWindow::Enable(enable);
#endif
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::Disable()
{
  // if already disabled then done
  if (!Enabled)
    return;

  // that's it (we can't remove the event handler like it should be...)
  Enabled = 0;
  Modified();
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::Start()
{
  // the interactor cannot control the event loop
  vtkErrorMacro(<<"wxVTKRenderWindowInteractor::Start() \
    interactor cannot control event loop.");
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::UpdateSize(int x, int y)
{
  if( RenderWindow )
  {
    // if the size changed tell render window
    if ( x != Size[0] || y != Size[1] )
    {
      // adjust our (vtkRenderWindowInteractor size)
      Size[0] = x;
      Size[1] = y;
      // and our RenderWindow's size
      RenderWindow->SetSize(x, y);
    }
  }
}
//---------------------------------------------------------------------------
int wxVTKRenderWindowInteractor::CreateTimer(int WXUNUSED(timertype))
{
  // it's a one shot timer
  if (!timer.Start(10, TRUE))
    assert(false);

  return 1;
  
}
//---------------------------------------------------------------------------
int wxVTKRenderWindowInteractor::DestroyTimer()
{
  // do nothing
  return 1;
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::OnTimer(wxTimerEvent& WXUNUSED(event))
{
  if (!Enabled)
    return;
    
#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
    InvokeEvent(vtkCommand::TimerEvent, NULL);
#else
    // old style
    InteractorStyle->OnTimer();
#endif
}
//---------------------------------------------------------------------------
// NOTE on implementation:
// Bad luck you ended up in the only tricky place of this code.
// A few note, wxWidgets still refuse to provide such convenient method
// so I have to maintain it myself, eventhough this is completely integrated
// in wxPython...
// Anyway if this happen to break for you then compare to a recent version of wxPython
// and look for the function long wxPyGetWinHandle(wxWindow* win)
// in wxPython/src/helpers.cpp
long wxVTKRenderWindowInteractor::GetHandleHack()
{
  //helper function to hide the MSW vs GTK stuff
  long handle_tmp = 0;

// __WXMSW__ is for Win32
//__WXMAX__ stands for using Carbon C-headers, using either the CarbonLib/CFM or the native Mach-O builds (which then also use the latest features available)
// __WXGTK__ is for both gtk 1.2.x and gtk 2.x
#if defined(__WXMSW__) || defined(__WXMAC__)
    handle_tmp = (long)this->GetHandle();
#endif //__WXMSW__

//__WXCOCOA__ stands for using the objective-c Cocoa API
#ifdef __WXCOCOA__
   // Here is how to find the NSWindow
   wxTopLevelWindow* toplevel = dynamic_cast<wxTopLevelWindow*>(
     wxGetTopLevelParent( this ) );
   if (toplevel != NULL )    
   {
     handle_tmp = (long)toplevel->GetNSWindow();
   }
   // The NSView will be deducted from 
   // [(NSWindow*)Handle contentView]
   // if only I knew how to write that in c++
#endif //__WXCOCOA__

    // Find and return the actual X-Window.
#if defined(__WXGTK__) || defined(__WXX11)
    return (long)GetXWindow(this);
#endif

//#ifdef __WXMOTIF__
//    handle_tmp = (long)this->GetXWindow();
//#endif

  return handle_tmp;
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::OnPaint(wxPaintEvent& WXUNUSED(event))
{
  //must always be here
  wxPaintDC pDC(this);

  //do it here rather than in the cstor: this is safer.
  if(!Handle)
  {
    Handle = GetHandleHack();
    RenderWindow->SetWindowId(reinterpret_cast<void *>(Handle));
#ifdef __WXMSW__
    RenderWindow->SetParentId(reinterpret_cast<void *>(this->GetParent()->GetHWND()));
#endif //__WXMSW__
  }
  // get vtk to render to the wxWindows
  Render();
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::OnEraseBackground(wxEraseEvent &event)
{
  //turn off background erase to reduce flickering on MSW
  event.Skip(false);
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::OnSize(wxSizeEvent& WXUNUSED(event))
{
  int w, h;
  GetClientSize(&w, &h);
  UpdateSize(w, h);

  if (!Enabled) 
    {
    return;
    }

#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
  InvokeEvent(vtkCommand::ConfigureEvent, NULL);
#endif
  //this will check for Handle
  //Render();
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::OnMotion(wxMouseEvent &event)
{
 if (!Enabled) 
    {
    return;
    }
#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
  SetEventInformationFlipY(event.GetX(), event.GetY(), 
    event.ControlDown(), event.ShiftDown(), '\0', 0, NULL);

  InvokeEvent(vtkCommand::MouseMoveEvent, NULL);
#else
  InteractorStyle->OnMouseMove(event.ControlDown(), event.ShiftDown(),
    event.GetX(), Size[1] - event.GetY() - 1);
#endif
}
//---------------------------------------------------------------------------
#if !(VTK_MAJOR_VERSION == 3 && VTK_MINOR_VERSION == 1)
void wxVTKRenderWindowInteractor::OnEnter(wxMouseEvent &event)
{
  if (!Enabled) 
    {
    return;
    }

#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
  SetEventInformationFlipY(event.GetX(), event.GetY(), 
      event.ControlDown(), event.ShiftDown(), '\0', 0, NULL);

  InvokeEvent(vtkCommand::EnterEvent, NULL);
#else
    // old style
  InteractorStyle->OnEnter(event.ControlDown(), event.ShiftDown(),
      event.GetX(), Size[1] - event.GetY() - 1);  
#endif
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::OnLeave(wxMouseEvent &event)
{
  if (!Enabled) 
    {
    return;
    }

#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
  SetEventInformationFlipY(event.GetX(), event.GetY(), 
      event.ControlDown(), event.ShiftDown(), '\0', 0, NULL);

  InvokeEvent(vtkCommand::LeaveEvent, NULL);
#else
    // old style
  InteractorStyle->OnLeave(event.ControlDown(), event.ShiftDown(),
      event.GetX(), Size[1] - event.GetY() - 1);  
#endif
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::OnKeyDown(wxKeyEvent &event)
{
  if (!Enabled) 
    {
    return;
    }

#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
  int keycode = event.GetKeyCode();
  char key = '\0';
  if (keycode < 256)
  {
    // TODO: Unicode in non-Unicode mode ??
    key = (char)keycode;
    // Correct key if it should be a lower case character:
    if ((!event.ShiftDown ()) && (keycode >= 65) && (keycode <= 90)) {

        key += 32;
    }
  }

  // Only create events if a new key down occurred:
  if (m_oldKeyDown != key) {

    m_oldKeyDown = key;

    SetEventInformationFlipY(event.GetX(), event.GetY(), 
      event.ControlDown(), event.ShiftDown(), key, 0, NULL);

    InvokeEvent(vtkCommand::KeyPressEvent, NULL);
    // We still need to create a vtk char event if key is inside the key down
    // range -> cf. event.Skip() call at the end of this method:
    if (this->IsInKeyDownRange (key)) {
      InvokeEvent(vtkCommand::CharEvent, NULL);
    }
  }
#else
  InteractorStyle->OnKeyDown(event.ControlDown(), event.ShiftDown(), 
    event.GetKeyCode(), 1);
#endif
  // Only skip event if key is outside specified range -> EVT_CHAR will be
  // created subsequently:
  if (!this->IsInKeyDownRange (key)) {
    event.Skip();
  }
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::OnChar(wxKeyEvent &event)
{
  if (!Enabled) 
    {
    return;
    }

#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
  int keycode = event.GetKeyCode();
  char key = '\0';
  if (keycode < 256)
  {
    // TODO: Unicode in non-Unicode mode ??
    key = (char)keycode;
  }

  SetEventInformationFlipY(event.GetX(), event.GetY(), 
    event.ControlDown(), event.ShiftDown(), key, 0, NULL);

  // Key press events are now separated:
  //InvokeEvent(vtkCommand::KeyPressEvent, NULL);
  InvokeEvent(vtkCommand::CharEvent, NULL);
#else
  InteractorStyle->OnKeyDown(event.ControlDown(), event.ShiftDown(), 
    event.GetKeyCode(), 1);
#endif
  event.Skip();
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::OnKeyUp(wxKeyEvent &event)
{
  if (!Enabled) 
    {
    return;
    }

#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
  int keycode = event.GetKeyCode();
  char key = '\0';
  if (keycode < 256)
  {
    // TODO: Unicode in non-Unicode mode ??
    key = (char)keycode;
    // Correct key if it should be a lower case character:
    if ((!event.ShiftDown ()) && (keycode >= 65) && (keycode <= 90)) {

        key += 32;
    }
  }
  // Reset pressing key check variable:
  m_oldKeyDown = 0;

  SetEventInformationFlipY(event.GetX(), event.GetY(), 
    event.ControlDown(), event.ShiftDown(), key, 0, NULL);
  InvokeEvent(vtkCommand::KeyReleaseEvent, NULL);
#else
  InteractorStyle->OnKeyUp(event.ControlDown(), event.ShiftDown(), 
    event.GetKeyCode(), 1);
#endif
  event.Skip();
}
#endif //!(VTK_MAJOR_VERSION == 3 && VTK_MINOR_VERSION == 1)
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::OnButtonDown(wxMouseEvent &event)
{
  if (!Enabled || (ActiveButton != wxEVT_NULL))
    {
    return;
    }
  ActiveButton = event.GetEventType();

#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
  SetEventInformationFlipY(event.GetX(), event.GetY(), 
    event.ControlDown(), event.ShiftDown(), '\0', 0, NULL);
#endif

  if(event.RightDown())
  {
#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
    InvokeEvent(vtkCommand::RightButtonPressEvent, NULL);
#else            
    // old style
    InteractorStyle->OnRightButtonDown(event.ControlDown(), event.ShiftDown(),
      event.GetX(), Size[1] - event.GetY() - 1);
#endif
  }
  else if(event.LeftDown())
  {
#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
    InvokeEvent(vtkCommand::LeftButtonPressEvent, NULL);
#else            
    // old style
    InteractorStyle->OnLeftButtonDown(event.ControlDown(),  event.ShiftDown(),
      event.GetX(), Size[1] - event.GetY() - 1);
#endif
  }
  else if(event.MiddleDown())
  {
#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
    InvokeEvent(vtkCommand::MiddleButtonPressEvent, NULL);
#else            
    // old style
    InteractorStyle->OnMiddleButtonDown(event.ControlDown(), event.ShiftDown(),
      event.GetX(), Size[1] - event.GetY() - 1);
#endif
  }
  //save the button and capture mouse until the button is released
  //Only if :
  //1. it is possible (WX_USE_X_CAPTURE)
  //2. user decided to.
  if ((ActiveButton != wxEVT_NULL) && WX_USE_X_CAPTURE && UseCaptureMouse)
  {
    CaptureMouse();
  }
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::OnButtonUp(wxMouseEvent &event)
{
  //EVT_xxx_DOWN == EVT_xxx_UP - 1
  //This is only needed if two mouse buttons are pressed at the same time.
  //In wxWindows 2.4 and later: better use of wxMOUSE_BTN_RIGHT or 
  //wxEVT_COMMAND_RIGHT_CLICK
  if (!Enabled || (ActiveButton != (event.GetEventType()-1))) 
    {
    return;
    }

#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
  SetEventInformationFlipY(event.GetX(), event.GetY(), 
    event.ControlDown(), event.ShiftDown(), '\0', 0, NULL);
#endif
  
  if(ActiveButton == wxEVT_RIGHT_DOWN)
  {
#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
    InvokeEvent(vtkCommand::RightButtonReleaseEvent, NULL);
#else            
    // old style
    InteractorStyle->OnRightButtonUp(event.ControlDown(), event.ShiftDown(),
      event.GetX(), Size[1] - event.GetY() - 1);
#endif
  }
  else if(ActiveButton == wxEVT_LEFT_DOWN)
  {
#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
    InvokeEvent(vtkCommand::LeftButtonReleaseEvent, NULL);
#else            
    // old style
    InteractorStyle->OnLeftButtonUp(event.ControlDown(), event.ShiftDown(),
      event.GetX(), Size[1] - event.GetY() - 1);
#endif
  }
  else if(ActiveButton == wxEVT_MIDDLE_DOWN)
  {
#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 0)
    // new style
    InvokeEvent(vtkCommand::MiddleButtonReleaseEvent, NULL);
#else            
    // old style
    InteractorStyle->OnMiddleButtonUp(event.ControlDown(), event.ShiftDown(),
      event.GetX(), Size[1] - event.GetY() - 1);
#endif
  }
  //if the ActiveButton is realeased, then release mouse capture
  if ((ActiveButton != wxEVT_NULL) && WX_USE_X_CAPTURE && UseCaptureMouse)
  {
    ReleaseMouse();
  }
  ActiveButton = wxEVT_NULL;
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::Render()
{
  RenderAllowed = 1;
  if (!RenderWhenDisabled)
    {
    //the user doesn't want us to render when the toplevel frame
    //is disabled - first find the top level parent
    wxWindow *topParent = wxGetTopLevelParent(this);
    if (topParent)
      {
      //if it exists, check whether it's enabled
      //if it's not enabeld, RenderAllowed will be false
      RenderAllowed = topParent->IsEnabled();
      }
    }

  if (RenderAllowed)
    {
    if(Handle && (Handle == GetHandleHack()) )
      {
      RenderWindow->Render();
      }
#if VTK_MAJOR_VERSION == 5 || (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION > 2)
    else if(GetHandleHack())
      {
      //this means the user has reparented us; let's adapt to the
      //new situation by doing the WindowRemap dance
      //store the new situation
      Handle = GetHandleHack();
      RenderWindow->SetNextWindowId(reinterpret_cast<void *>(Handle));
      RenderWindow->WindowRemap();
      RenderWindow->Render();
      }
#endif
    }
}
//---------------------------------------------------------------------------
void wxVTKRenderWindowInteractor::SetRenderWhenDisabled(int newValue)
{
  //Change value of __RenderWhenDisabled ivar.
  //If __RenderWhenDisabled is false (the default), this widget will not
  //call Render() on the RenderWindow if the top level frame (i.e. the
  //containing frame) has been disabled.

  //This prevents recursive rendering during wxSafeYield() calls.
  //wxSafeYield() can be called during the ProgressMethod() callback of
  //a VTK object to have progress bars and other GUI elements updated -
  //it does this by disabling all windows (disallowing user-input to
  //prevent re-entrancy of code) and then handling all outstanding
  //GUI events.
        
  //However, this often triggers an OnPaint() method for wxVTKRWIs,
  //resulting in a Render(), resulting in Update() being called whilst
  //still in progress.

  RenderWhenDisabled = (newValue != 0) ? true : false;
}
//---------------------------------------------------------------------------
//
// Set the variable that indicates that we want a stereo capable window
// be created. This method can only be called before a window is realized.
//
void wxVTKRenderWindowInteractor::SetStereo(int capable)
{
  if (Stereo != capable)
    {
    Stereo = capable;
    RenderWindow->StereoCapableWindowOn();
    RenderWindow->SetStereoTypeToCrystalEyes();
    Modified();
    }
}


void wxVTKRenderWindowInteractor::SetKeyDownKeyRange (char key1, char key2)
{
    m_keyDown1 = key1;
    m_keyDown2 = key2;
}


bool wxVTKRenderWindowInteractor::IsInKeyDownRange (char key) const
{
    return ((key >= m_keyDown1) && (key <= m_keyDown2));
}


//---------------------------------------------------------------------------
//
//
void wxVTKRenderWindowInteractor::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
