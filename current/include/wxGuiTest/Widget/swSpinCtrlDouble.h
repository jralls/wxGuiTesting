/////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Widget/swSpinCtrlDouble.h
// Author:      John Labenski
// Created:     11/05/02
// Copyright:   John Labenski, 2002
// Modified:    Viet Bui Xuan, Reinhold Fuereder
// License:     wxWindows v2
/////////////////////////////////////////////////////////////////////////////

/* 
swSpinCtrlDouble is a double valued wxSpinCtrl using non native (wxWindows) widgets

It consists of a wxSpinButton and a wxTextCtrl on a wxControl and can be used
as a drop in replacement for the wxSpinCtrl. It's been tested in GTK and MSW
and should work with MAC, but you may need to fix the sizing perhaps. It 
will not work in Motif as there is no wxSpinButton in Motif.

Differences to wxSpinCtrl:

    It remembers the initial value as a default value, or call SetDefaultValue

    Shift + Arrow = *2 increment value
    Ctrl  + Arrow = *10 increment value
    Alt   + Arrow = *100 increment value
    combinations of Shift, Ctrl, Alt increment by the product of the factors

    Esc sets the control's value to the it's last valid state
    
    Right Click & Space set the control to the default value

    PgUp & PgDn = *10 increment * the product of the Shift, Ctrl, Alt factors

    SetDigits controls the format of the text, # decimal places
        exponential uses the %.Xle format otherwise %.Xlf, where places = X
        for arbitray formats subclass control and override SyncSpinToText()
        for proper behavior when a user types in a value
*/


#ifndef SWSPINCTRLDOUBLE_H
#define SWSPINCTRLDOUBLE_H

#ifdef __GNUG__
    #pragma interface "swSpinCtrlDouble.h"
#endif

//#ifndef WX_PRECOMP
//  #include <wx/wx.h>
//#endif

#include <wx/defs.h>
#include <wx/spinbutt.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h> // for EVT_SPINCTRL

namespace sw {


class wxSpinCtrlDbl_TextCtrl;

class SpinCtrlDouble : public wxControl
{

	DECLARE_DYNAMIC_CLASS(SpinCtrlDouble)
    DECLARE_EVENT_TABLE()

public:
    SpinCtrlDouble() {}
    
    SpinCtrlDouble(wxWindow *parent, wxWindowID id = -1,
                 const wxString &value = _T(""),
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxSize(95,-1),
                 long style = wxNO_BORDER,
                 double min = 0.0, double max = 100.0,
                 double initial = 0.0,
                 double increment = 1.0, int digits = -1,
                 const wxString& name = _T("SpinCtrlDouble"))
                 :wxControl( parent, id, pos, size, style, wxDefaultValidator, name)
    {
        Create(parent, id, value, pos, size, style,
               min, max, initial, increment, digits, name);
    }

    // wxSpinCtrl compatibility, call SetIncrement(increment,digits) after
    SpinCtrlDouble(wxWindow *parent, wxWindowID id = -1,
                 const wxString &value = _(""),
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxSize(95,-1),
                 long style = wxNO_BORDER,
                 int min = 0, int max = 100,
                 int initial = 0,
                 const wxString& name = _T("SpinCtrlDouble"))
                 :wxControl( parent, id, pos, size, style, wxDefaultValidator, name)
    {
        Create(parent, id, value, pos, size, style,
               (double)min, (double)max, (double)initial, 1.0, -1, name);
    }

    bool Create(wxWindow *parent,
                wxWindowID id = -1,
                const wxString &value = _T(""),
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxSize(100,-1),
                long style = wxNO_BORDER,
                double min = 0.0, double max = 100.0,
                double initial = 0.0,
                double increment = 1.0, int digits = -1,
                const wxString& name = _T("SpinCtrlDouble"));

    virtual ~SpinCtrlDouble();

    // -----------------------------------------------------------------------
    // Public (normal usage) functions
    virtual void SetValue( double value );
    virtual void SetValue( double value, double max, double min, double increment, int digits = -1, bool exponential=FALSE )
        { SetRange(max, min); SetIncrement(increment); SetDigits(digits, exponential); SetValue(value); }
    virtual void SetValue( const wxString& text, bool force = FALSE ); //if force then set text as is
    virtual void SetRange( double minVal, double maxVal );
    virtual void SetIncrement( double increment );
    virtual void SetIncrement( double increment, int digits, bool exponential=FALSE )
        { SetIncrement(increment); SetDigits(digits, exponential); }
    // # digits to show, -1 is autodetect from increment
    virtual void SetDigits( int digits = -1, bool exponential=FALSE ); 
    virtual void SetFormat( wxString format ); // ie. format="%.2d" for .01
    virtual void SetDefaultValue() { SetValue( m_default_value ); }
    virtual void SetDefaultValue( double default_value );

    virtual double GetValue() const { return m_value; }
    virtual double GetMin() const { return m_min; }
    virtual double GetMax() const { return m_max; }
    virtual double GetIncrement() const { return m_increment; }
    virtual int GetDigits() const { return m_digits; }
    virtual wxString GetFormat() const { return m_text_format; }
    virtual double GetDefaultValue() const { return m_default_value; }

    virtual bool IsDefaultValue() const { return (m_value == m_default_value); }

    // for setting font... and maybe other stuff
    wxTextCtrl *GetTextCtrl() { return (wxTextCtrl*)m_textctrl; }


    /*! \fn void SetToolTip(const wxString &tip)
		\brief Override tool tip and assign it to "internal" text control as well.

		\param tip tool tip
	*/
    void SetToolTip (const wxString &tip);


    /*! \fn void SetToolTip(wxToolTip *tip)
		\brief Override tool tip and assign it to "internal" text control as well.

		\param tip tool tip
	*/
    void SetToolTip (wxToolTip *tip);

protected:
    virtual void OnSpinUp( wxSpinEvent &event );
    virtual void OnSpinDown( wxSpinEvent &event );
    virtual void OnTextEnter( wxCommandEvent &event );

    // the textctrl is subclassed to get at pgup/dn and then sent here
    virtual void OnChar( wxKeyEvent &event );

    void SyncSpinToText(bool send_event = TRUE);  
    
    void SendEvent();                     // send an event based on current state
    
private:
    virtual void DoSetSize(int x, int y, int width, int height,
                           int sizeFlags = wxSIZE_AUTO);
    
    virtual wxSize DoGetBestSize() const;

    void OnFocus( wxFocusEvent& event );  // pass focus to textctrl, for wxTAB_TRAVERSAL
    void OnKillFocus( wxFocusEvent &event );
    
    wxSpinButton *m_spinbutt;
    wxSpinCtrlDbl_TextCtrl *m_textctrl;

    double m_min;           // min allowed value
    double m_max;           // max allowed value
    double m_value;         // current value
    double m_default_value; // initial value, or SetDefaultValue(value)
    double m_increment;     // how much to to add per spin
    int m_digits;           // number of digits displayed after decimal point
    wxString m_text_format; // used as wxString.Printf(m_text_format.c_str(), m_value);

    friend class wxSpinCtrlDbl_TextCtrl;


};


} // End namespace sw

#endif  // SWSPINCTRLDOUBLE_H

