///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRNotebookPageChangeEvent.h
// Author:      Reinhold F�reder
// Created:     2004
// Copyright:   (c) 2005 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRNOTEBOOKPAGECHANGEEVENT_H
#define SWCRNOTEBOOKPAGECHANGEEVENT_H

#ifdef __GNUG__
    #pragma interface "swCRNotebookPageChangeEvent.h"
#endif

#include "Common.h"

#include "swCRCapturedEvent.h"

namespace swTst {


/*! \class CRNotebookPageChangeEvent
    \brief Handle notebook page change events.
*/
class CRNotebookPageChangeEvent : public CRCapturedEvent
{
public:
    /*! \fn CRNotebookPageChangeEvent (wxEvent *event)
        \brief Constructor

        \param event event to handle
    */
    CRNotebookPageChangeEvent (wxEvent *event);


    /*! \fn virtual ~CRNotebookPageChangeEvent ()
        \brief Destructor
    */
    virtual ~CRNotebookPageChangeEvent ();


    /*! \fn virtual bool IsPending () const
        \brief Return true for the first event of the two identical created
        notebook events.

        \return true for the first of the two events
    */
    virtual bool IsPending () const;

    
    /*! \fn virtual void Process (CRCapturedEvent **pendingEvt)
        \brief Process event, only called after checking for handling ability.
    
        \param pendingEvt current pending event with respect to code emitting
            (or NULL if none is pending)
    */
    virtual void Process (CRCapturedEvent **pendingEvt);


    /*! \fn virtual void EmitCpp ()
        \brief Emit event simulation specific C++ code.
    */
    virtual void EmitCpp ();

protected:

private:
    bool m_isFirstAndPending;
    wxString m_containerName;
    wxString m_notebookName;
    wxString m_notebookPageText;

private:
    // No copy and assignment constructor:
    CRNotebookPageChangeEvent (const CRNotebookPageChangeEvent &rhs);
    CRNotebookPageChangeEvent & operator= (const CRNotebookPageChangeEvent &rhs);
};

} // End namespace swTst

#endif // SWCRNOTEBOOKPAGECHANGEEVENT_H

