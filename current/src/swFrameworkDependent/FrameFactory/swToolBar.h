///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swToolBar.h
// Author:      Reinhold Fuereder
// Created:     2005
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWTOOLBAR_H
#define SWTOOLBAR_H

#ifdef __GNUG__
    #pragma interface "swToolBar.h"
#endif

#include <wxGuiTest/Common.h>

class cbDimInfo;

namespace sw {


/*! \class ToolBar
    \brief Abstract tool bar class for frame factory.

    After a toolbar is created, you use methods (e.g. ToolBar::AddTool(),
    ToolBar::AddSeparator(), etc.) to add tools, and then you must call
    ToolBar::Realize() to construct and display the toolbar tools.

    Note: When adding general controls to the tool bar specify size instead of
      using wxDefaultSize, as this can cause wrong layouting.

    TODO: Should it be inherited from Window? Or a still to create potential
      parent class of Window (e.g. without SetTitle() method etc.)?
*/
class ToolBar
{
public:
    /*! \fn ToolBar ()
        \brief Constructor
    */
    ToolBar ();


    /*! \fn virtual ~ToolBar ()
        \brief Destructor
    */
    virtual ~ToolBar ();


    /*! \fn virtual wxWindow * GetWindow () const = 0
        \brief Get wrapped toolbar as window to correctly parent + add tools.

        \return toolbar (real widget) as simple window pointer
    */
    virtual wxWindow * GetWindow () const = 0;


    /*! \fn virtual void AddTool (const int toolId, const wxString &label, const wxBitmap &bitmap, const wxString &toolTip, bool isToggle = false, bool isToggleOffable = true) = 0
        \brief Add tool to toolbar.

        If not isToggle it will be a flat bitmap button, otherwise a toggle
        button.
        Note: Currently there is no toggle bitmap button for FL!

        \param toolId ID of tool (allows tool recognition for event handling)
        \param label text label of tool
        \param bitmap bitmap/icon of tool
        \param toolTip short help string as tooltip
        \param isToggle if true, tool stays pressed when clicked (cf. isSticky)
        \param isToggleOffable if true, clicking on a pressed tool does not change it's state
    */
    virtual void AddTool (const int toolId, const wxString &label,
            const wxBitmap &bitmap, const wxString &toolTip,
            bool isToggle = false, bool isToggleOffable = true) = 0;

    
    /*! \fn virtual void AddControl (wxWindow *control) = 0
        \brief Add general control to toolbar.

        Due to FL's wxNewBitmapButton being not a wxControl, but AddTool()
        accepting any wxWindow, this method also accepts a wxWindow, but the
        ordinary wxToolBar does not!

        \param control general control to add as tool
    */
    virtual void AddControl (wxWindow *control) = 0;

    
    /*! \fn virtual void AddSeparator () = 0
        \brief Add separator to toolbar.
    */
    virtual void AddSeparator () = 0;


    /*! \fn virtual void EnableTool (const int toolId, const bool enable = true) = 0
        \brief Enable/disable tool of toolbar.

        \param toolId ID of tool
        \param enable enable/disable specified tool
    */
    virtual void EnableTool (const int toolId, const bool enable = true) = 0;


    /*! \fn virtual void RemoveTool (const int toolId) = 0
        \brief Remove tool from toolbar.

        \param toolId ID of tool
    */
    virtual void RemoveTool (const int toolId) = 0;


    /*! \fn virtual void ToggleTool (const int toolId, const bool enable) = 0
        \brief Toggle tool from toolbar.

        \param toolId ID of tool
        \param enable if true, the tool appears in pressed state (= On)
    */
    virtual void ToggleTool (const int toolId, const bool enable) = 0;


    /*! \fn virtual bool IsToggledOn (const int toolId) = 0
        \brief Get current toggling state of specified tool.

        \param toolId ID of tool
        \return true, if tool appears in pressed state (= On)
    */
    virtual bool IsToggledOn (const int toolId) = 0;


    /*! \fn virtual void Realize (cbDimInfo *dimInfo = NULL, int alignment = 0) = 0
        \brief Finish construction of toolbar and show it for the first time, or
        after tools were added.

        \param dimInfo only taken into account for FL stuff
        \param alignment only taken into account for FL stuff
    */
    virtual void Realize (cbDimInfo *dimInfo = NULL, int alignment = 0) = 0;


    /*! \fn virtual bool Show (bool show = true) = 0
        \brief Show/hide toolbar.

        \param show show/hide toolbar
        \return true if okay?
    */
    virtual bool Show (bool show = true) = 0;

};

} // End namespace sw

#endif // SWTOOLBAR_H

