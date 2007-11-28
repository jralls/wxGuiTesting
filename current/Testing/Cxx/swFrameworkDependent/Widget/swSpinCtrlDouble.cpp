/////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Widget/swSpinCtrlDouble.cpp
// Author:      John Labenski
// Created:     11/05/02
// Copyright:   John Labenski, 2002
// Modified:    Viet Bui Xuan, Reinhold Fuereder
// License:     wxWindows v2
/////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swSpinCtrlDouble.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include "swSpinCtrlDouble.h"
#include <wx/valtext.h>     // for wxTextValidator

namespace sw {

//----------------------------------------------------------------------------
// SpinCtrlDouble
//----------------------------------------------------------------------------

// the textctrl used for the SpinCtrlDouble, needed for keypresses
class wxSpinCtrlDbl_TextCtrl: public wxTextCtrl
{
public:
    wxSpinCtrlDbl_TextCtrl() {}
    wxSpinCtrlDbl_TextCtrl( wxWindow *parent,
                 wxWindowID id,
                 const wxString &value = wxEmptyString,
                 const wxPoint &pos = wxDefaultPosition,
                 const wxSize &size = wxDefaultSize,
                 const wxString &name = wxTextCtrlNameStr);

    SpinCtrlDouble *m_parent;
    void OnChar( wxKeyEvent &event );     // pass chars to SpinCtrlDouble
    void OnMouseRight( wxMouseEvent &event ); // reset to default value
    void OnKillFocus( wxFocusEvent &event );  // sync the spin to textctrl
    
private:
    DECLARE_DYNAMIC_CLASS(wxSpinCtrlDbl_TextCtrl)
    DECLARE_EVENT_TABLE()
};

IMPLEMENT_DYNAMIC_CLASS( wxSpinCtrlDbl_TextCtrl, wxTextCtrl )

BEGIN_EVENT_TABLE(wxSpinCtrlDbl_TextCtrl,wxTextCtrl)
//  EVT_TEXT_ENTER( -1, wxSpinCtrlDbl_TextCtrl::OnTextEnter ) // get them from spinctrldbl
//  EVT_TEXT( -1, wxSpinCtrlDbl_TextCtrl::OnTextUpdate )  // get them from spinctrldbl
    EVT_CHAR( wxSpinCtrlDbl_TextCtrl::OnChar )
    EVT_KILL_FOCUS( wxSpinCtrlDbl_TextCtrl::OnKillFocus )
    EVT_RIGHT_DOWN( wxSpinCtrlDbl_TextCtrl::OnMouseRight )
END_EVENT_TABLE()

wxSpinCtrlDbl_TextCtrl::wxSpinCtrlDbl_TextCtrl( wxWindow *parent,
                 wxWindowID id, const wxString &value,
                 const wxPoint &pos, const wxSize &size,
                 const wxString &name)
                :wxTextCtrl( parent, id, value, pos, size, 
                             wxTE_NOHIDESEL|wxTE_PROCESS_ENTER, 
                             wxTextValidator(wxFILTER_NUMERIC, NULL), name)
{
    m_parent = (SpinCtrlDouble*)parent;
}

void wxSpinCtrlDbl_TextCtrl::OnChar( wxKeyEvent &event ) 
{
    m_parent->OnChar( event );
    event.Skip();
}

void wxSpinCtrlDbl_TextCtrl::OnKillFocus( wxFocusEvent &event )
{
    m_parent->SyncSpinToText(TRUE);
    event.Skip();
}

void wxSpinCtrlDbl_TextCtrl::OnMouseRight( wxMouseEvent &event )
{
    m_parent->SetDefaultValue();
    m_parent->SendEvent();
    event.Skip();
}

//----------------------------------------------------------------------------
// SpinCtrlDouble
//----------------------------------------------------------------------------

IMPLEMENT_DYNAMIC_CLASS( SpinCtrlDouble, wxControl )

BEGIN_EVENT_TABLE(SpinCtrlDouble,wxControl)
    EVT_SPIN_UP   ( -1, SpinCtrlDouble::OnSpinUp    )
    EVT_SPIN_DOWN ( -1, SpinCtrlDouble::OnSpinDown  )
    EVT_TEXT_ENTER( -1, SpinCtrlDouble::OnTextEnter )
    EVT_SET_FOCUS ( SpinCtrlDouble::OnFocus     )
    EVT_KILL_FOCUS( SpinCtrlDouble::OnKillFocus )
END_EVENT_TABLE()

bool SpinCtrlDouble::Create(wxWindow *parent, wxWindowID id,
                        const wxString& value,
                        const wxPoint& pos, const wxSize& size, long style,
                        double min, double max,
                        double initial,
                        double increment, int digits,
                        const wxString& name)
{
    int width = size.GetWidth(), height = size.GetHeight();
    
    wxSize best_size( DoGetBestSize() );
    if (width < 20) width = best_size.GetWidth();
    if (height < 10) height = best_size.GetHeight();

    m_spinbutt = new wxSpinButton( this, id, wxPoint(0,0),
                                    wxSize(-1, height), 
                                    wxSP_ARROW_KEYS|wxSP_VERTICAL|wxSP_WRAP);
    m_textctrl = new wxSpinCtrlDbl_TextCtrl( this, id, value, wxPoint(0,0),
                                wxSize(width-m_spinbutt->GetSize().GetWidth(), height));

    DoSetSize( pos.x, pos.y, width, height );

    m_min = min;
    m_max = max;
    m_value = initial;
    m_default_value = initial;
    m_increment = increment;
    SetDigits( digits );

    // set the value here without generating an event
    if (value != _T("")) SetValue( value );
    else SetValue( initial );

    return TRUE;
}

SpinCtrlDouble::~SpinCtrlDouble()
{
}

void SpinCtrlDouble::DoSetSize(int x, int y, int width, int height, int sizeFlags)
{
    wxSize best_size( DoGetBestSize() );
    if (width < 20) width = best_size.GetWidth();
    if (height < 10) height = best_size.GetHeight();

    wxWindow::DoSetSize(x, y, width, height, sizeFlags);
    
    int spinwidth, spinheight;
    m_spinbutt->GetSize( &spinwidth, &spinheight );

    m_textctrl->SetSize( 0, 0, width - spinwidth, height );
    m_spinbutt->SetSize( width-spinwidth, 0, -1, height );
}

static wxSize s_spinctrldbl_bestSize(-999,-999);

wxSize SpinCtrlDouble::DoGetBestSize() const
{
    if ((s_spinctrldbl_bestSize.GetWidth() == -999) || (s_spinctrldbl_bestSize.GetHeight() == -999))
    {
        wxSpinCtrl spin(GetParent()); // use parent, this function is const
        s_spinctrldbl_bestSize = spin.GetSize();
        if (s_spinctrldbl_bestSize.GetWidth()  < 20) s_spinctrldbl_bestSize.SetWidth(95);
        if (s_spinctrldbl_bestSize.GetHeight() < 10) s_spinctrldbl_bestSize.SetHeight(22);
    }
    
    return s_spinctrldbl_bestSize;
}

void SpinCtrlDouble::SendEvent()
{
    // wxSpinCtrl event, taken from src/gtk/spinctrl.cpp
    wxCommandEvent event( wxEVT_COMMAND_SPINCTRL_UPDATED, GetId());
    event.SetEventObject( this );
    event.SetInt( (int)(m_value+0.5) );
    event.SetString( m_textctrl->GetValue() );
    GetEventHandler()->ProcessEvent( event );
}

// EVT_SPIN_UP
void SpinCtrlDouble::OnSpinUp( wxSpinEvent &event )
{
    if ( m_textctrl->IsModified() ) SyncSpinToText(FALSE);
    if ( (m_value + m_increment) <= m_max )
    {
        m_value += m_increment;
        SetValue( m_value );
        SendEvent();
    }
}

// EVT_SPIN_DOWN
void SpinCtrlDouble::OnSpinDown( wxSpinEvent &event )
{
    if ( m_textctrl->IsModified() ) SyncSpinToText(FALSE);
    if ( (m_value - m_increment) >= m_min )
    {
        m_value -= m_increment;
        SetValue( m_value );
        SendEvent();
    }
}

// EVT_TEXT_ENTER - for wxTextCtrl - <ENTER> pressed in textctrl
void SpinCtrlDouble::OnTextEnter( wxCommandEvent &event )
{
    SyncSpinToText(TRUE);
}

// process up-down arrows, pg-up-pg-down from textctrl, passed back from wxTextCtrl
void SpinCtrlDouble::OnChar( wxKeyEvent &event )
{
    double modifier = 1.0;
    if ( event.m_shiftDown ) modifier = 2.0;
    if ( event.m_controlDown ) modifier *= 10.0;
    if ( event.m_altDown ) modifier *= 100.0;
    // event.m_metaDown is NUMLOCK!
    switch ( event.GetKeyCode() )
    {
        case WXK_UP :
        {
            if ( m_textctrl->IsModified() ) SyncSpinToText(FALSE);
            SetValue( m_value + m_increment * modifier );
            SendEvent();
            break;
        }
        case WXK_DOWN :
        {
            if ( m_textctrl->IsModified() ) SyncSpinToText(FALSE);
            SetValue( m_value - m_increment * modifier );
            SendEvent();
            break;
        }
        case WXK_PAGEUP :
        {
            if ( m_textctrl->IsModified() ) SyncSpinToText(FALSE);
            SetValue( m_value + m_increment * 10.0 * modifier );
            SendEvent();
            break;
        }
        case WXK_PAGEDOWN :
        {
            if ( m_textctrl->IsModified() ) SyncSpinToText(FALSE);
            SetValue( m_value - m_increment * 10.0 * modifier );
            SendEvent();
            break;
        }
        case WXK_SPACE :
        {
            SetDefaultValue();
            SendEvent();
            break;
        }
        case WXK_ESCAPE :
        {
            SetValue(m_value);
            break;
        }
        default: break;
    }

    if ( event.GetKeyCode() == WXK_TAB )
    {
        wxNavigationKeyEvent new_event;
        new_event.SetEventObject( GetParent() );
        new_event.SetDirection( !event.ShiftDown() );
        // CTRL-TAB changes the (parent) window, i.e. switch notebook page
        new_event.SetWindowChange( event.ControlDown() );
        new_event.SetCurrentFocus( this );
        GetParent()->GetEventHandler()->ProcessEvent( new_event );
    }

    event.Skip();
}

// set the value of the control
void SpinCtrlDouble::SetValue( double value )
{
    //wxCHECK_RET((value >= m_min) && (value <= m_max), "Spin value out of range");
    if (!((value >= m_min) && (value <= m_max))) return;

    wxString wxstr;
    if ((wxstr.Printf(m_text_format.c_str(), value)) != m_textctrl->GetValue())
    {
        m_textctrl->SetValue( wxstr );
        wxstr.ToDouble( &m_value );    // wysiwyg for textctrl
    }
}

void SpinCtrlDouble::SetValue( const wxString& text, bool force )
{
    if ( force ) 
        m_textctrl->SetValue( text );
    else
    {
        double value;
        if ( text.ToDouble(&value) ) SetValue( value );
    }
}

// set the max and min range of the control
void SpinCtrlDouble::SetRange( double minVal, double maxVal )
{
    m_min = minVal;
    m_max = maxVal;

    if (m_value > m_max) SetValue(m_max);
    else if (m_value < m_min) SetValue(m_min);
}

// set the value to step by when spinbutton pressed, a min increment
// also set the format of the spinctrl to this many decimals
void SpinCtrlDouble::SetIncrement( double increment )
{
    m_increment = increment;
    SetValue(m_value);
}

void SpinCtrlDouble::SetDigits( int digits, bool exponential )
{
    if ( digits == -1 )
    {
        wxString wxstr;
        int lastplace = -1, extra_digits = 0;
        if (exponential) 
        {
            wxstr.Printf( _T("%le"), m_increment );
            wxstr.LowerCase();
            lastplace = wxstr.Find('e') - 2;
            long places;
            if (wxstr.AfterFirst('e').ToLong(&places))
                extra_digits = int(labs(places));
        }
        else
        {
            wxstr.Printf( _T("%lf"), m_increment );
            lastplace = wxstr.Len()-1;
        }
        int decimalplace = wxstr.Find('.');

        int i = 0;
        
        for ( i=lastplace; i>decimalplace; i-- )
        {
            if ( wxstr.GetChar(i) != '0' )
            {
                m_digits = extra_digits + i-decimalplace;
                if (exponential) m_text_format.Printf( _T("%%.%dle"), m_digits );
                else             m_text_format.Printf( _T("%%.%dlf"), m_digits );
                SetValue(m_value);
                return;
            }
        }
        m_digits = 0;  // no digits, I guess
        if (exponential) m_text_format.Printf( _T("%%.%dle"), m_digits );
        else             m_text_format.Printf( _T("%%.%dlf"), m_digits );
    }
    else
    {
        m_digits = digits;
        if (exponential) m_text_format.Printf( _T("%%.%dle"), m_digits );
        else             m_text_format.Printf( _T("%%.%dlf"), m_digits );
    }
    SetValue(m_value);
}

// force the format of the textctrl to something else
void SpinCtrlDouble::SetFormat( wxString format )
{
    wxString wxstr;
    double testdouble = 123456.123456;
    if ( wxstr.Printf(format.c_str(), testdouble) > 0 ) m_text_format = format;
    SetValue(m_value);
}

void SpinCtrlDouble::SetDefaultValue( double default_value )
{
    if ( (default_value > m_min) && (default_value < m_max) )
    {
        m_default_value = default_value;
        SetDefaultValue();
    }
}

void SpinCtrlDouble::OnFocus( wxFocusEvent &event )
{
    m_textctrl->SetFocus(); // this is to pass TAB navigation
    event.Skip();
}

void SpinCtrlDouble::OnKillFocus( wxFocusEvent &event )
{
    SyncSpinToText(TRUE);
    event.Skip();
}

void SpinCtrlDouble::SyncSpinToText(bool send_event)
{
    double temp_value;
    if ( m_textctrl->GetValue().ToDouble( &temp_value ) )
    {
        if ( (temp_value >= m_min) && (temp_value <= m_max))
        {
            if ( m_value != temp_value )
            {
                SetValue( temp_value );
                m_value = temp_value;
                if (send_event) SendEvent();
            }
        }
        else SetValue( m_value );
    }
    else SetValue( m_value );
}


void SpinCtrlDouble::SetToolTip (const wxString &tip)
{
    wxControl::SetToolTip (tip);
    m_textctrl->SetToolTip (tip);
}


void SpinCtrlDouble::SetToolTip (wxToolTip *tip)
{
    wxControl::SetToolTip (tip);
    m_textctrl->SetToolTip (tip);
}

} // End namespace sw
