///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swWxGuiTestTimedDialogEnder.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWWXGUITESTTIMEDDIALOGENDER_H
#define SWWXGUITESTTIMEDDIALOGENDER_H

#ifdef __GNUG__
    #pragma interface "swWxGuiTestTimedDialogEnder.h"
#endif

#include "Common.h"

namespace swTst {


/*! \class WxGuiTestTimedDialogEnder
    \brief Periodical looking for a certain window (in fact a modal dialog
    identified by caption) to close/end.

    Internally a timer component is used to periodically check if a window with
    the given caption exists. If so, it is tried to close it with the given
    return code. After successfully closing the window, the timer is stopped
    and destroyed.
    The reason why this works for wxMessageBox is because it is inherited from
    wxMessageDialog class and popped up by calling ShowModal().

    Supports debug logging with trace mask "WxGuiTestTimedDialogEnder".

    TODO/REMARK: Works currently only under M$ Windows!
*/
class WxGuiTestTimedDialogEnder : public wxEvtHandler
{
    DECLARE_CLASS(WxGuiTestTimedDialogEnder)
    DECLARE_EVENT_TABLE()

public:
    /*! \fn WxGuiTestTimedDialogEnder (unsigned int milliseconds, const wxString &windowCaption, int returnCode)
        \brief Constructor

        \param milliseconds timer intervall
        \param windowCaption caption identifying the window to close/end
        \param returnCode code to return when closing window (because M$
            Windows SDK functions are used, returnCode must be one of:
            IDCANCEL, IDOK, IDYES, IDNO.
    */
    WxGuiTestTimedDialogEnder (unsigned int milliseconds,
            const wxString &windowCaption, int returnCode);


    /*! \fn virtual ~WxGuiTestTimedDialogEnder ()
        \brief Destructor
    */
    virtual ~WxGuiTestTimedDialogEnder ();


    /*! \fn virtual bool GetSuccess () const;
        \brief Get success status of timed dialog ender operation.

        Necessary to really know if for example a message box has popped up,
        i.e. a warning or error has occurred.

        \return success status of timed dialog ender operation
    */
    virtual bool GetSuccess () const;

protected:
    /*! \fn virtual void DestroyTimer ()
        \brief Stop and destroy timer.

        Moved out from destructor to allow reuse in case of successful closing
        of window.
    */
    virtual void DestroyTimer ();


    /*! \fn virtual void OnTimer (wxTimerEvent& event)
        \brief Timer event handling functionality with "main" functionality.

        \param event notifying timer event
    */
    virtual void OnTimer (wxTimerEvent& event);

private:
    wxTimer *m_timer;
    long m_timerId;

    wxString m_windowCaption;
    int m_returnCode;

    bool m_success;

};

} // End namespace swTst

#endif // SWWXGUITESTTIMEDDIALOGENDER_H

