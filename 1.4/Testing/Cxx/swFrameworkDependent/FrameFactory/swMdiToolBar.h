///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swMdiToolBar.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWMDITOOLBAR_H
#define SWMDITOOLBAR_H

#ifdef __GNUG__
    #pragma interface "swMdiToolBar.h"
#endif

#include "Common.h"

#include <vector>

#include "swToolBar.h"

namespace sw {

class MainFrame;


class WxToolBar : public wxToolBar
{
public:
    WxToolBar (wxWindow* parent, wxWindowID id,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTB_HORIZONTAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr) :
    wxToolBar (parent, id, pos, size, style, name)
    {
        // Nothing to do
    }


    ~WxToolBar ()
    {
        m_isToggleOffableVector.clear ();
    }


    virtual wxToolBarToolBase* AddTool (int toolId, const wxString &label,
            const wxBitmap& bitmap1,
            const wxBitmap& bitmap2 = wxNullBitmap,
            wxItemKind kind = wxITEM_NORMAL,            
            const wxString& shortHelpString = "",
            const wxString& longHelpString = "",
            wxObject* clientData = NULL,
            bool isToggleOffable = true)
    {
        m_isToggleOffableVector.push_back (isToggleOffable);
        return wxToolBar::AddTool (toolId, label, bitmap1, bitmap2, kind,
                shortHelpString, longHelpString, clientData);
    }


    bool DeleteTool (int toolId)
    {
        int pos = this->GetToolPos (toolId);
        wxASSERT (pos != wxNOT_FOUND);
        m_isToggleOffableVector.erase (m_isToggleOffableVector.begin () + pos - 1);
        return wxToolBar::DeleteTool (toolId);
    }


    virtual bool OnLeftClick (int toolId, bool toggleDown)
    {
        wxToolBarToolBase *tool = this->FindById (toolId);
        wxASSERT (tool != NULL);
        int pos = this->GetToolPos (toolId);
        wxASSERT (pos != wxNOT_FOUND);

        if ((!m_isToggleOffableVector[pos - 1]) &&
                ((tool->CanBeToggled ()) && (!toggleDown))) {

            return false;
        }
        return wxToolBar::OnLeftClick (toolId, toggleDown);
    }

private:
    typedef std::vector< bool > IsToggleOffableVector;
    IsToggleOffableVector m_isToggleOffableVector;
};


/*! \class MdiToolBar
    \brief Concrete ToolBar wrapping a wxToolBar.
*/
class MdiToolBar : public ToolBar
{
public:
    /*! \fn MdiToolBar (MainFrame *mainFrame, const long style)
        \brief Constructor

        \param mainFrame parent main frame
        \param style toolbar creation style
    */
    MdiToolBar (MainFrame *mainFrame, const long style);


    /*! \fn virtual ~MdiToolBar ()
        \brief Destructor
    */
    virtual ~MdiToolBar ();


    /*! \fn virtual wxWindow * GetWindow () const
        \brief Get wrapped toolbar as window to correctly parent + add tools.
    */
    virtual wxWindow * GetWindow () const;


    /*! \fn virtual void AddTool (const int toolId, const wxString &label, const wxBitmap &bitmap, const wxString &toolTip, bool isToggle = false, bool isToggleOffable = true)
        \brief Add tool to toolbar.

        \param toolId ID of tool (allows tool recognition for event handling)
        \param label text label of tool
        \param bitmap bitmap/icon of tool
        \param toolTip short help string as tooltip
        \param isToggle if true, tool stays pressed when clicked (cf. isSticky)
        \param isToggleOffable if true, clicking on a pressed tool does not change it's state
    */
    virtual void AddTool (const int toolId, const wxString &label,
            const wxBitmap &bitmap, const wxString &toolTip,
            bool isToggle = false, bool isToggleOffable = true);


    /*! \fn virtual void AddControl (wxWindow *control)
        \brief Add general control to toolbar.

        Does only accept wxControl!

        \param control general control to add as tool
    */
    virtual void AddControl (wxWindow *control);


    /*! \fn virtual void AddSeparator ()
        \brief Add separator to toolbar.
    */
    virtual void AddSeparator ();


    /*! \fn virtual void EnableTool (const int toolId, const bool enable = true)
        \brief Enable/disable tool of toolbar.

        \param toolId ID of tool
        \param enable enable/disable specified tool
    */
    virtual void EnableTool (const int toolId, const bool enable = true);


    /*! \fn virtual void RemoveTool (const int toolId)
        \brief Remove tool from toolbar.

        Deletes tool explicitly.

        \param toolId ID of tool
    */
    virtual void RemoveTool (const int toolId);


    /*! \fn virtual void ToggleTool (const int toolId, const bool enable)
        \brief Toggle tool from toolbar.

        \param toolId ID of tool
        \param enable if true, the tool appears in pressed state (= On)
    */
    virtual void ToggleTool (const int toolId, const bool enable);


    /*! \fn virtual bool IsToggledOn (const int toolId)
        \brief Get current toggling state of specified tool.

        \param toolId ID of tool
        \return true, if tool appears in pressed state (= On)
    */
    virtual bool IsToggledOn (const int toolId);

    
    /*! \fn virtual void Realize (cbDimInfo *dimInfo = NULL, int alignment = 0)
        \brief Finish construction of toolbar and show it for the first time, or
        after tools were added.

        \param dimInfo only taken into account for FL stuff
        \param alignment only taken into account for FL stuff
    */
    virtual void Realize (cbDimInfo *dimInfo = NULL, int alignment = 0);
    
    
    /*! \fn virtual bool Show (bool show)
        \brief Show/hide toolbar.

        TODO: never tested - does Show() really work?

        \param show show/hide toolbar
    */
    virtual bool Show (bool show);

protected:

private:
    WxToolBar *m_realToolBar;
};

} // End namespace sw

#endif // SWMDITOOLBAR_H

