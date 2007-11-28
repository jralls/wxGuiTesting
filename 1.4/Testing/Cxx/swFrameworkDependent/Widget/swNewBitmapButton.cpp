///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Widget/swNewBitmapButton.cpp
// Author:      Reinhold Füreder
// Created:     2005
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swNewBitmapButton.h"
#endif

#include "swNewBitmapButton.h"

#include "wx/utils.h" // import wxMax macro

namespace sw {


///////////// button-label rendering helpers //////////////////

static int* create_array( int width, int height, int fill = 0 )
{
    int* array = new int[width*height];

    int len = width*height;
    int i;
    for ( i = 0; i != len; ++i )
        array[i] = fill;

    return array;
}

#define GET_ELEM(array,x,y) (array[width*(y)+(x)])

#define MIN_COLOR_DIFF 10

#define IS_IN_ARRAY(x,y) ( (x) < width && (y) < height && (x) >= 0 && (y) >= 0 )

#define GET_RED(col)    col        & 0xFF  
#define GET_GREEN(col) (col >> 8)  & 0xFF     
#define GET_BLUE(col)  (col >> 16) & 0xFF 

#define MAKE_INT_COLOR(red,green,blue) (     (red)                      | \
                                         ( ( (green) << 8 ) & 0xFF00  ) | \
                                         ( ( (blue)  << 16) & 0xFF0000) \
                                       )   

#define IS_GREATER(col1,col2) ( ( (GET_RED(col1)  ) > (GET_RED(col2)  ) + MIN_COLOR_DIFF ) && \
                                ( (GET_GREEN(col1)) > (GET_GREEN(col2)) + MIN_COLOR_DIFF ) &&  \
                                ( (GET_BLUE(col1) ) > (GET_BLUE(col2) ) + MIN_COLOR_DIFF )     \
                              )

#define MASK_BG    0
#define MASK_DARK  1
#define MASK_LIGHT 2

// helper function, used internally

static void gray_out_pixmap( int* src, int* dest, int width, int height )
{
    // assuming the pixels along the edges are of the background color

    int x = 0;
    int y = 1;

    do
    {
        int cur       = GET_ELEM(src,x,y);


        if ( IS_IN_ARRAY(x-1,y-1) )
        {
            int upperElem = GET_ELEM(src,x-1,y-1);

            // if the upper element is lighter than current
            if ( IS_GREATER(upperElem,cur) )
            {
                GET_ELEM(dest,x,y) = MASK_DARK;
            }
            else
            // if the current element is ligher than the upper
            if ( IS_GREATER(cur,upperElem) )
            {
                GET_ELEM(dest,x,y) = MASK_LIGHT;
            }
            else
            {
                if ( GET_ELEM(dest,x-1,y-1) == MASK_LIGHT )
                    
                    GET_ELEM(dest,x,y) = MASK_BG;

                if ( GET_ELEM(dest,x-1,y-1 ) == MASK_DARK )

                    GET_ELEM(dest,x,y) = MASK_DARK;
                else
                    GET_ELEM(dest,x,y) = MASK_BG;
            }
        }

        // go zig-zag

        if ( IS_IN_ARRAY(x+1,y-1) ) 
        {
            ++x;
            --y;
        }
        else
        {
            while ( IS_IN_ARRAY(x-1,y+1) ) 
            {
                --x;
                ++y;
            }

            if ( IS_IN_ARRAY(x,y+1) )
            {
                ++y;
                continue;
            }
            else
            {
                if ( IS_IN_ARRAY(x+1,y) )
                {
                    ++x;
                    continue;
                }
                else break;
            }
        }

    } while (1);
}

// algorithm for making the image look "grayed" (e.g. disabled button)
// NOTE:: used GetPixel(), which is Windows-Only!

void gray_out_image_on_dc( wxDC& dc, int width, int height )
{
    // assuming the pixels along the edges are of the background color
    wxColour bgCol;
    dc.GetPixel( 0, 0, &bgCol );

    wxPen darkPen ( wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW),1, wxSOLID );
    wxPen lightPen( wxSystemSettings::GetColour(wxSYS_COLOUR_3DHIGHLIGHT),1, wxSOLID );
    wxPen bgPen   ( bgCol,                1, wxSOLID );

    int* src  = create_array( width, height, MASK_BG );
    int* dest = create_array( width, height, MASK_BG );

    int x, y;
    for ( y = 0; y != height; ++y )
    {
        for ( x = 0; x != width; ++x )
        {
            wxColour col;
            dc.GetPixel( x,y, &col );

            GET_ELEM(src,x,y) = MAKE_INT_COLOR( col.Red(), col.Green(), col.Blue() );
        }
    }
    gray_out_pixmap( src, dest, width, height );

    for ( y = 0; y != height; ++y )
    {
        for ( x = 0; x != width; ++x )
        {
            int mask = GET_ELEM(dest,x,y);

            switch (mask)
            {
                case MASK_BG    : { dc.SetPen( bgPen ); 
                                    dc.DrawPoint( x,y ); break;
                                  }
                case MASK_DARK  : { dc.SetPen( darkPen ); 
                                    dc.DrawPoint( x,y ); break;
                                  }
                case MASK_LIGHT : { dc.SetPen( lightPen ); 
                                    dc.DrawPoint( x,y ); break;
                                  }
                default : break;
            }
        }
    }
    delete [] src;
    delete [] dest;
}

///////////////////////////////

/***** Implementation for class NewBitmapButton *****/

IMPLEMENT_DYNAMIC_CLASS(NewBitmapButton, wxPanel)

BEGIN_EVENT_TABLE( NewBitmapButton, wxPanel )

    EVT_LEFT_DOWN   ( NewBitmapButton::OnLButtonDown   )
    EVT_LEFT_UP     ( NewBitmapButton::OnLButtonUp     )
//    EVT_LEFT_DCLICK ( NewBitmapButton::OnLButtonDClick )
    EVT_LEFT_DCLICK ( NewBitmapButton::OnLButtonDown )
    EVT_ENTER_WINDOW( NewBitmapButton::OnMouseEnter    )
    EVT_LEAVE_WINDOW( NewBitmapButton::OnMouseLeave    )

    EVT_SIZE ( NewBitmapButton::OnSize  )
    EVT_PAINT( NewBitmapButton::OnPaint )

    //EVT_KILL_FOCUS( NewBitmapButton::OnKillFocus )

    EVT_ERASE_BACKGROUND( NewBitmapButton::OnEraseBackground )

    EVT_IDLE(NewBitmapButton::OnIdle)

END_EVENT_TABLE()

NewBitmapButton::NewBitmapButton( const wxBitmap& labelBitmap,
                                      const wxString& labelText,
                                      int  alignText,
                                      bool isFlat,
                                      int  firedEventType,
                                      int  marginX,
                                      int  marginY,
                                      int  textToLabelGap,
                                      bool isSticky,
                                      bool isToggleOffable)
    :   mTextToLabelGap  ( textToLabelGap ),
        mMarginX( marginX ),
        mMarginY( marginY ),
        mTextAlignment( alignText ),
        mIsSticky( isSticky ),
        mIsToggleOffable( isToggleOffable ),
        mIsFlat( isFlat ),
        mLabelText( labelText ),
        mImageFileType( wxBITMAP_TYPE_INVALID ),
        mDepressedBmp( labelBitmap ),

        mpDepressedImg( NULL ),
        mpPressedImg  ( NULL ),
        mpDisabledImg ( NULL ),
        mpFocusedImg  ( NULL ),


        mDragStarted  ( false ),
        mIsPressed    ( false ),
        mIsInFocus    ( false ),
        mIsToggled    ( false ),
        m_isPseudoPressed (false),
        mHasFocusedBmp( false ),
        mFiredEventType( firedEventType ),

        mBlackPen( wxColour(  0,  0,  0), 1, wxSOLID ),
        mDarkPen ( wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW), 1, wxSOLID ),
        mGrayPen ( wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE), 1, wxSOLID ),
        mLightPen( wxSystemSettings::GetColour(wxSYS_COLOUR_3DHIGHLIGHT), 1, wxSOLID ),

        mIsCreated( false ),
        mSizeIsSet( false )

{
}

NewBitmapButton::NewBitmapButton( const wxString& bitmapFileName,
                                      const wxBitmapType  bitmapFileType,
                                      const wxString& labelText,
                                      int  alignText,
                                      bool isFlat,
                                      int  WXUNUSED(firedEventType), 
                                      int  WXUNUSED(marginX),
                                      int  WXUNUSED(marginY),
                                      int  WXUNUSED(textToLabelGap),
                                      bool WXUNUSED(isSticky),
                                      bool WXUNUSED(isToggleOffable))

    :   mTextToLabelGap  ( 2 ),
        mMarginX( 2 ),
        mMarginY( 2 ),
        mTextAlignment( alignText ),
        mIsSticky( false ),
        mIsToggleOffable( true ),
        mIsFlat( isFlat ),
        mLabelText( labelText ),
        mImageFileName( bitmapFileName ),
        mImageFileType( bitmapFileType ),

        mpDepressedImg( NULL ),
        mpPressedImg  ( NULL ),
        mpDisabledImg ( NULL ),
        mpFocusedImg  ( NULL ),

        mDragStarted  ( false ),
        mIsPressed    ( false ),
        mIsInFocus    ( false ),
        mIsToggled    ( false ),
        m_isPseudoPressed (false),
        mHasFocusedBmp( false ),
        mFiredEventType( wxEVT_COMMAND_MENU_SELECTED ),

        mBlackPen( wxColour(  0,  0,  0), 1, wxSOLID ),
        mDarkPen ( wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW), 1, wxSOLID ),
        mGrayPen ( wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE), 1, wxSOLID ),
        mLightPen( wxSystemSettings::GetColour(wxSYS_COLOUR_3DHIGHLIGHT), 1, wxSOLID ),

        mIsCreated( false ),
        mSizeIsSet( false )

{
}

NewBitmapButton::~NewBitmapButton(void) 
{
    DestroyLabels();
}

void NewBitmapButton::DrawShade( int outerLevel,
                                   wxDC&  dc,
                                   wxPen& upperLeftSidePen,
                                   wxPen& lowerRightSidePen )
{
    wxBitmap* pBmp = GetStateLabel();

    int x = mMarginX - (outerLevel + 2);
    int y = mMarginY - (outerLevel + 2);

    int height = pBmp->GetHeight() + (outerLevel + 2)*2 - 1;
    int width  = pBmp->GetWidth()  + (outerLevel + 2)*2 - 1;

    dc.SetPen( upperLeftSidePen );
    dc.DrawLine( x,y, x + width, y  );
    dc.DrawLine( x,y, x, y + height );

    dc.SetPen( lowerRightSidePen );
    dc.DrawLine( x + width, y, x + width, y + height + 1  );
    dc.DrawLine( x, y + height, x + width, y + height );
}

void NewBitmapButton::DestroyLabels()
{
    if ( mpDepressedImg ) delete mpDepressedImg;
    if ( mpPressedImg   ) delete mpPressedImg;
    if ( mpDisabledImg  ) delete mpDisabledImg;
    if ( mpFocusedImg   ) delete mpFocusedImg;

    mpDepressedImg = NULL;
    mpPressedImg   = NULL;
    mpDisabledImg  = NULL;
    mpFocusedImg   = NULL;
}

wxBitmap* NewBitmapButton::GetStateLabel()
{
    if ( IsEnabled() )
    {
        if ( mIsPressed )
        {
            return mpPressedImg;
        }
        else
        {
            if ( mIsInFocus )
            {
                if ( mHasFocusedBmp )

                    return mpFocusedImg;
                else
                    return mpDepressedImg;
            }
            else
                return mpDepressedImg;
        }
    }
    else
        return mpDisabledImg;
}

static const unsigned char _gDisableImage[] = { 0x55,0xAA,0x55,0xAA,
                                              0x55,0xAA,0x55,0xAA,
                                              0x55,0xAA,0x55,0xAA,
                                              0x55,0xAA,0x55,0xAA
                                            };
void NewBitmapButton::RenderLabelImage( wxBitmap*& destBmp, wxBitmap* srcBmp,
                                          bool isEnabled, bool isPressed )
{
    if ( destBmp != 0 ) return;

    // render labels on-demand

    wxMemoryDC srcDc;
    srcDc.SelectObject( *srcBmp );

    bool hasText = ( mTextAlignment != NB_NO_TEXT ) &&
                   ( mLabelText.length() != 0 );

    bool hasImage = (mTextAlignment != NB_NO_IMAGE);

    wxSize destDim;
    wxPoint txtPos;
    wxPoint imgPos;

    if ( hasText )
    {
        long txtWidth, txtHeight;

        srcDc.SetFont( wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT) );
        srcDc.GetTextExtent( mLabelText, &txtWidth, &txtHeight );

        if ( mTextAlignment == NB_ALIGN_TEXT_RIGHT )
        {
            destDim.x = srcBmp->GetWidth() + 2*mTextToLabelGap + txtWidth;

            destDim.y =
                wxMax( srcBmp->GetHeight(), txtHeight );

            txtPos.x = srcBmp->GetWidth() + mTextToLabelGap;
            txtPos.y = (destDim.y - txtHeight)/2;
            imgPos.x = 0;
            imgPos.y = (destDim.y - srcBmp->GetHeight())/2;
        }
        else
        if ( mTextAlignment == NB_ALIGN_TEXT_BOTTOM )
        {
            destDim.x =
                wxMax( srcBmp->GetWidth(), txtWidth );

            destDim.y = srcBmp->GetHeight() + mTextToLabelGap + txtHeight;

            txtPos.x = (destDim.x - txtWidth)/2;
            txtPos.y = srcBmp->GetHeight() + mTextToLabelGap;
            imgPos.x = (destDim.x - srcBmp->GetWidth())/2;
            imgPos.y = 0;
        }
        else
        {
            wxFAIL_MSG(wxT("Unsupported FL alignment type detected in NewBitmapButton::RenderLabelImage()"));
        }
    }
    else
    {
        imgPos.x = 0;
        imgPos.y = 0;
        destDim.x = srcBmp->GetWidth();
        destDim.y = srcBmp->GetHeight();
    }

    destBmp = new wxBitmap( int(destDim.x), int(destDim.y) );

    wxMemoryDC destDc;
    destDc.SelectObject( *destBmp );

    wxBrush grayBrush( wxSystemSettings::GetColour( wxSYS_COLOUR_3DFACE), wxSOLID );
    wxPen   nullPen( wxColour(0,0,0), 1, wxTRANSPARENT );

    destDc.SetBrush( grayBrush );
    destDc.SetPen( nullPen );

    destDc.DrawRectangle( 0,0, destDim.x+1, destDim.y+1 );

    if ( isPressed )
    {
        ++imgPos.x; ++imgPos.y;
        ++txtPos.x; ++txtPos.y;
    }

    if ( hasImage )
    {

        destDc.Blit( imgPos.x, imgPos.y,
                 srcBmp->GetWidth()+1,
                 srcBmp->GetHeight()+1,
                 &srcDc, 0,0, wxCOPY,true );
    }

    if ( hasText )
    {
        wxWindow* pTopWnd = this;

        do
        {
            wxWindow* pParent = pTopWnd->GetParent();

            if ( pParent == 0 )
                break;

            pTopWnd = pParent;
        } while (1);

        destDc.SetFont( wxSystemSettings::GetFont( wxSYS_DEFAULT_GUI_FONT) );

        if ( isEnabled )
        {
            destDc.SetTextForeground( wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT) );
        }
        else
        {
            destDc.SetTextForeground( wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW) );
        }
        destDc.SetTextBackground( wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE) );

        destDc.DrawText( mLabelText, txtPos.x, txtPos.y );
    }

    if ( !isEnabled ){

#ifdef __WXMSW__ // This is currently MSW specific
        gray_out_image_on_dc( destDc, destDim.x, destDim.y );
#else
        wxBrush checkerBrush( wxBitmap( (const char*)_gDisableImage,8,8) );
        checkerBrush.SetColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
        destDc.SetBrush( checkerBrush );
        destDc.DrawRectangle( imgPos.x, imgPos.y, srcBmp->GetWidth()+1, srcBmp->GetHeight()+1);
#endif
    }
    // adjust button size to fit the new dimensions of the label
    if ( !mSizeIsSet && 0 )
    {
        mSizeIsSet = true;
        SetSize( -1, -1,
                 destBmp->GetWidth()  + mMarginX*2,
                 destBmp->GetHeight() + mMarginY*2, 0
            );
    }
    destDc.SelectObject( wxNullBitmap );

#if defined(__WXMSW__) && !defined(__WXUNIVERSAL__)
    // Map to system colours
    (void) wxToolBar::MapBitmap(destBmp->GetHBITMAP(), destBmp->GetWidth(), destBmp->GetHeight());
#endif
}

void NewBitmapButton::RenderAllLabelImages()
{
    if ( !mIsCreated )
        return;
    RenderLabelImage( mpDisabledImg, &mDepressedBmp, false );
    RenderLabelImage( mpPressedImg,   &mDepressedBmp, true, true );
    RenderLabelImage( mpDepressedImg, &mDepressedBmp, true, false );
    if ( mHasFocusedBmp )
    {
        RenderLabelImage( mpFocusedImg, &mFocusedBmp, true, false );
    }
}


void NewBitmapButton::RenderLabelImages()
{
    if ( !mIsCreated )
        return;

    if ( !IsEnabled() )
    {
        RenderLabelImage( mpDisabledImg, &mDepressedBmp, false );
    }
    else

    if ( mIsPressed )

        RenderLabelImage( mpPressedImg,   &mDepressedBmp, true, true );
    else
    {
        if ( mIsInFocus )
        {
            if ( mHasFocusedBmp )
                RenderLabelImage( mpFocusedImg, &mFocusedBmp, true, false );
            else
                RenderLabelImage( mpDepressedImg, &mDepressedBmp, true, false );
        }
        else
            RenderLabelImage( mpDepressedImg, &mDepressedBmp, true, false );
    }
}

bool NewBitmapButton::Toggle(bool enable)
{
    if ( mIsToggled == enable )
    {
        return false;
    }

    mIsToggled = enable;
    Refresh();

    return true;
}

bool NewBitmapButton::IsToggled () const
{
    return mIsToggled;
}

bool NewBitmapButton::Enable(bool enable)
{
    if ( enable != m_isEnabled )
    {
        if ( mIsInFocus )
        {
            mIsInFocus = false;
        }

        if ( mIsPressed )
        {
            mIsPressed = false;
        }

        Refresh();
    }

    return wxPanel::Enable( enable );
}

void NewBitmapButton::DrawDecorations( wxDC& dc )
{
    if ( mIsFlat )
    {
        DrawShade( 1, dc, mGrayPen,  mGrayPen  );
        if ( mIsToggled )
        {
            DrawShade( 0, dc, mDarkPen,  mLightPen  );
        }
        else if ( mIsInFocus )
        {
            if ( mIsPressed )
                DrawShade( 0, dc, mDarkPen,  mLightPen  );
            else
                DrawShade( 0, dc, mLightPen,  mDarkPen  );
        }
        else
            DrawShade( 0, dc, mGrayPen,  mGrayPen  );
    }
    else
    {
        if ( mIsPressed || mIsToggled )
        {
            DrawShade( 0, dc, mDarkPen,  mGrayPen  );
            DrawShade( 1, dc, mBlackPen, mLightPen );
        }
        else
        {
            DrawShade( 0, dc, mGrayPen,  mDarkPen  );
            DrawShade( 1, dc, mLightPen, mBlackPen );
        }
    }
}

void NewBitmapButton::SetLabel(const wxBitmap& labelBitmap,
                                 const wxString& labelText )
{
    DestroyLabels();

    mLabelText    = labelText;
    mDepressedBmp = labelBitmap;

    //RenderLabelImages();
    RenderAllLabelImages();
}

void NewBitmapButton::SetAlignments( int alignText,
                                       int marginX,
                                       int marginY,
                                       int textToLabelGap)
{
    DestroyLabels();

    mMarginX        = marginX;
    mMarginY        = marginY;
    mTextAlignment  = alignText;
    mTextToLabelGap = textToLabelGap;

    //RenderLabelImages();
    RenderAllLabelImages();
}

// event handlers

void NewBitmapButton::OnLButtonDown( wxMouseEvent& WXUNUSED(event) )
{
    mDragStarted      = true;
    mIsPressed        = true;
    m_isPseudoPressed = false;
    Refresh();

    this->CaptureMouse ();
}

void NewBitmapButton::OnLButtonUp( wxMouseEvent& event )
{
    if ( !mDragStarted )
        return;

    if (this->HasCapture ()) {

        this->ReleaseMouse ();
    }

    mDragStarted = false;
    mIsPressed   = false;
    m_isPseudoPressed = false;
    Refresh();

    if ( IsInWindow( event.m_x, event.m_y ) ) 
    {
        bool doFireEvent = true;
        if (mIsSticky) {

            if (mIsToggled && !mIsToggleOffable) {

                doFireEvent = false;

            } else {

                this->Toggle (!mIsToggled);
            }
        }

        //TODO: only fire event if toggle on?
        if ((doFireEvent) && ((!mIsSticky) || (mIsSticky && mIsToggled))) {

            // fire event, if mouse was released
            // within the bounds of button
            wxCommandEvent cmd( mFiredEventType, GetId () );

            cmd.SetEventObject (event.GetEventObject ());
            // we use SetInt() to make wxCommandEvent::IsChecked() return toggleDown
            cmd.SetInt ((int)mIsToggled);
            // and SetExtraLong() for backwards compatibility
            cmd.SetExtraLong((long)mIsToggled);

            GetParent()->ProcessEvent (cmd);
        }
    }
}

bool NewBitmapButton::IsInWindow( int x, int y )
{
    int width, height;
    GetSize( &width, &height );

    return ( x >= 0 && y >= 0 &&
             x < width &&
             y < height );
}

void NewBitmapButton::OnMouseEnter( wxMouseEvent& WXUNUSED(event) )
{
    bool prevIsInFocus = mIsInFocus;

    if ( !mIsInFocus )
    {
        mIsInFocus = true;
    }

    if (m_isPseudoPressed) {

        mIsPressed = true;
    }

    if ( prevIsInFocus != mIsInFocus )
    {
        Refresh();
    }
}

void NewBitmapButton::OnMouseLeave( wxMouseEvent& WXUNUSED(event) )
{
    bool prevIsInFocus = mIsInFocus;
    bool prevIsPressed = mIsPressed;
    
    if (mIsPressed) {

        m_isPseudoPressed = true;
    }

    if ( mIsInFocus )
    {
        mIsInFocus = false;
        mIsPressed = false;
    }
    if ( prevIsInFocus != mIsInFocus || prevIsPressed != mIsPressed )
    {
        Refresh();
    }
}

void NewBitmapButton::OnSize( wxSizeEvent& WXUNUSED(event) )
{
        //Reshape();
}

void NewBitmapButton::Reshape( )
{   
    bool wasCreated = mIsCreated;
    mIsCreated = true;

    if ( !wasCreated )
    {
        // in the case of loading button from stream, check if we
        // have non-empty image-file name, load if possible 

        if ( mImageFileName != wxT("") )
        {
            mDepressedBmp.LoadFile( mImageFileName, mImageFileType );

            //wxMessageBox("Image Loaded!!!");
        }

        //RenderLabelImages();
        RenderAllLabelImages();

        wxBitmap* pCurImg = GetStateLabel();

        int w = pCurImg->GetWidth(),
            h = pCurImg->GetHeight();

        SetSize( 0,0, w + mMarginX*2, h + mMarginY*2 , 0 );
    }
}

void NewBitmapButton::DrawLabel( wxDC& dc )
{
    wxBitmap* pCurBmp = GetStateLabel();

    if ( pCurBmp == NULL )
    {
        wxSizeEvent evt;
        OnSize( evt ); // fake it up!

        //RenderLabelImages();
        pCurBmp = GetStateLabel();
    }

    wxMemoryDC mdc;
    mdc.SelectObject( *pCurBmp );

    dc.Blit( mMarginX, mMarginY, 
             pCurBmp->GetWidth(),
             pCurBmp->GetHeight(),
             &mdc, 0,0, wxCOPY 
           );

    mdc.SelectObject( wxNullBitmap );
}

void NewBitmapButton::OnPaint( wxPaintEvent& WXUNUSED(event) )
{
    wxPaintDC dc(this);

    // first, make sure images for current state are prepared
    //RenderLabelImages();

    DrawLabel( dc );

    DrawDecorations( dc );
}

void NewBitmapButton::OnEraseBackground( wxEraseEvent& WXUNUSED(event) )
{
    // do nothing
}

void NewBitmapButton::OnKillFocus( wxFocusEvent& WXUNUSED(event) )
{
    // useless

    wxMessageBox(wxT("kill-focus for button!"));
}

// ----------------------------------------------------------------------------
// UI updates
// ----------------------------------------------------------------------------

void NewBitmapButton::OnIdle(wxIdleEvent& event)
{
    DoButtonUpdate();

    event.Skip();
}

// Do the toolbar button updates (check for EVT_UPDATE_UI handlers)
void NewBitmapButton::DoButtonUpdate()
{
    wxUpdateUIEvent event(GetId());
    event.SetEventObject(this);

    if ( GetParent()->ProcessEvent(event) )
    {
        if ( event.GetSetEnabled() )
        {
            bool enabled = event.GetEnabled();
            if ( enabled != IsEnabled() )
                Enable( enabled );
        }
        if ( event.GetSetChecked() )
            Toggle( event.GetChecked() );
    }
}

} // End namespace sw

