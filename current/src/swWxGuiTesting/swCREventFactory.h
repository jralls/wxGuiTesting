///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCREventFactory.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCREVENTFACTORY_H
#define SWCREVENTFACTORY_H

#ifdef __GNUG__
    #pragma interface "swCREventFactory.h"
#endif

#include <wxGuiTest/Common.h>

namespace swTst {

class CRCapturedEvent;


/*! \class CREventFactory
    \brief Factory for creating appropriate event instances depending on the
    given concrete event type.

    Singleton and Factory pattern.
*/
class CREventFactory
{
public:
    /*! \fn static CREventFactory * GetInstance ()
        \brief Get single private instance (Singleton pattern).

        \return single private instance
    */
    static CREventFactory * GetInstance ();


    /*! \fn static void Destroy ()
        \brief Threadsafe destruction of static singleton instance.
    */
    static void Destroy ();


    /*! \fn virtual CRCapturedEvent * CreateEvent (const wxEvent &event) const
        \brief Create appropriate CRCapturedEvent subclass instance.

        \param event event to create handling event instance for
        \return appropriate event handling instance
    */
    virtual CRCapturedEvent * CreateEvent (const wxEvent &event) const;

protected:
    /*! \fn CREventFactory ()
        \brief Constructor
    */
    CREventFactory ();


    /*! \fn virtual ~CREventFactory ()
        \brief Destructor
    */
    virtual ~CREventFactory ();

private:
    static CREventFactory *ms_instance;

private:
    // No copy and assignment constructor:
    CREventFactory (const CREventFactory &rhs);
    CREventFactory & operator= (const CREventFactory &rhs);
};

} // End namespace swTst

#endif // SWCREVENTFACTORY_H

