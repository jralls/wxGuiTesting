///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Widget/swNewBitmapButton.h
// Author:      Reinhold Füreder
// Created:     2005
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWNEWBITMAPBUTTON_H
#define SWNEWBITMAPBUTTON_H

#ifdef __GNUG__
    #pragma interface "swNewBitmapButton.h"
#endif

#include "Common.h"

#include "wx/button.h"
#include "wx/string.h"

// defaults
#define NB_DEFAULT_MARGIN 2

// button label-text alignment types
#define NB_ALIGN_TEXT_RIGHT  0
#define NB_ALIGN_TEXT_BOTTOM 1
#define NB_NO_TEXT           2
#define NB_NO_IMAGE          3


namespace sw {


/*! \class NewBitmapButton
    \brief Slightly enhanced version of FL's wxNewBitmapButton.

    Enhancement:
        - Toggling support improved
        - Pressing tool, moving out, moving in, releasing is correctly visualised

    Usage: As mentioned in the original implementation this is an alternative
      class to wxBitmapButton. It is (or should be) used for dynamic toolbars.
*/
class NewBitmapButton : public wxPanel
{
    DECLARE_DYNAMIC_CLASS (NewBitmapButton)

protected:

    int      mTextToLabelGap;
    int      mMarginX;
    int      mMarginY;
    int      mTextAlignment;
    bool     mIsSticky;
    bool     mIsToggleOffable;
    bool     mIsFlat;

    wxString mLabelText;
    wxString mImageFileName;
    wxBitmapType mImageFileType;

    wxBitmap mDepressedBmp; // source image for rendering
                            // labels for particular state

    wxBitmap mFocusedBmp;   // may not be always present -
                            // only if mHasFocusedBmp is true

    wxBitmap* mpDepressedImg;
    wxBitmap* mpPressedImg;
    wxBitmap* mpDisabledImg;
    wxBitmap* mpFocusedImg;

    // button state variables;
    bool      mDragStarted;
    bool      mIsPressed;
    bool      mIsInFocus;
    bool      mIsToggled;

    // When pressing mouse button on tool, but leaving tool without releasing
    // the mouse button, and eventually entering the tool again, the visual
    // feedback is wrong (it does not appear depressed or pressed, while the
    // actual action is okay: releasing the mouse button now in the tool is
    // really toggling the tool. => Extra member for this intermediate state.
    bool      m_isPseudoPressed;

    bool      mHasFocusedBmp;

    // type of event which is fired upon depression of this button
    int       mFiredEventType;

    // pens for drawing decorations (borders)
    wxPen     mBlackPen;
    wxPen     mDarkPen;
    wxPen     mGrayPen;
    wxPen     mLightPen;

    bool      mIsCreated;
    int       mSizeIsSet;

protected:

        // Internal function for destroying labels.
    void DestroyLabels();

        // Returns the label that matches the current button state.
    virtual wxBitmap* GetStateLabel();

        // Draws shading on the button.
    virtual void DrawShade( int outerLevel,
                            wxDC&  dc,
                            wxPen& upperLeftSidePen,
                            wxPen& lowerRightSidePen );

        // Returns true if the given point is in the window.
    bool IsInWindow( int x, int y );

    virtual void OnIdle(wxIdleEvent& event);
    // (EVT_UPDATE_UI handler)
    virtual void DoButtonUpdate();

public:

        // Constructor.
    NewBitmapButton( const wxBitmap& labelBitmap = wxNullBitmap,
                       const wxString& labelText   = wxT(""),
                       int   alignText             = NB_ALIGN_TEXT_BOTTOM,
                       bool  isFlat                = true,
                       // this is the default type of fired events
                       int firedEventType = wxEVT_COMMAND_MENU_SELECTED,
                       int marginX        = NB_DEFAULT_MARGIN,
                       int marginY        = NB_DEFAULT_MARGIN,
                       int textToLabelGap = 2,
                       bool isSticky      = false,
                       bool isToggleOffable = true
                     );

        // Use this constructor if buttons have to be persistant
    NewBitmapButton( const wxString& bitmapFileName,
                       const wxBitmapType bitmapFileType = wxBITMAP_TYPE_BMP,
                       const wxString& labelText         = wxT(""),
                       int alignText                     = NB_ALIGN_TEXT_BOTTOM,
                       bool  isFlat                      = true,
                       // this is the default type of fired events
                       int firedEventType = wxEVT_COMMAND_MENU_SELECTED,
                       int marginX        = NB_DEFAULT_MARGIN,
                       int marginY        = NB_DEFAULT_MARGIN,
                       int textToLabelGap = 2,
                       bool isSticky      = false,
                       bool isToggleOffable = true
                      );

        // Destructor.
    ~NewBitmapButton();

        // This function should be called after Create. It renders the labels, having
        // reloaded the button image if necessary.
    virtual void Reshape();

        // Sets the label and optionally label text.
    virtual void SetLabel(const wxBitmap& labelBitmap, const wxString& labelText = wxT("") );

        // Unhide method from parents.

    virtual void SetLabel(const wxString& label)
                         { wxPanel::SetLabel(label); };

        // Sets the text alignment and margins.
    virtual void SetAlignments( int alignText = NB_ALIGN_TEXT_BOTTOM,
                                int marginX        = NB_DEFAULT_MARGIN,
                                int marginY        = NB_DEFAULT_MARGIN,
                                int textToLabelGap = 2);

        // Draws the decorations.
    virtual void DrawDecorations( wxDC& dc );

        // Draws the label.
    virtual void DrawLabel( wxDC& dc );

        // Renders the label image.
    virtual void RenderLabelImage( wxBitmap*& destBmp, wxBitmap* srcBmp, 
                                   bool isEnabled = true,
                                   bool isPressed = false);

        // Renders label images.
    virtual void RenderLabelImages();

        // Renders label images.
    virtual void RenderAllLabelImages();

        // Enables/disables button
    virtual bool Enable(bool enable);

        // Depress button
    virtual bool Toggle(bool enable);

        // Returns toggling state (true = toggled on = pressed)
    bool IsToggled () const;

        // Responds to a left mouse button down event.
    void OnLButtonDown( wxMouseEvent& event );

        // Responds to a left mouse button up event.
    void OnLButtonUp( wxMouseEvent& event );

        // Responds to mouse enter to window.
    void OnMouseEnter( wxMouseEvent& event );

        // Responds to mouse leave from window.
    void OnMouseLeave( wxMouseEvent& event );

        // Responds to a size event.
    void OnSize( wxSizeEvent& event );

        // Responds to a paint event.
    void OnPaint( wxPaintEvent& event );

        // Responds to an erase background event.
    void OnEraseBackground( wxEraseEvent& event );

        // Responds to a kill focus event.
    void OnKillFocus( wxFocusEvent& event );

    DECLARE_EVENT_TABLE()
};

} // End namespace sw

#endif // SWNEWBITMAPBUTTON_H

