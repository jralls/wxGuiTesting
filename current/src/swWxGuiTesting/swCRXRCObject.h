///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRXRCObject.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRXRCOBJECT_H
#define SWCRXRCOBJECT_H

#ifdef __GNUG__
    #pragma interface "swCRXRCObject.h"
#endif

#include <wxGuiTest/Common.h>

#include "swCRXRCResource.h"

namespace swTst {


/*! \class CRXRCObject
    \brief Concrete XRC object node definition.
*/
class CRXRCObject : public CRXRCResource
{
public:
    /*! \fn CRXRCObject (const wxString &name, const wxString &className, CRXRCNode *parentNode = NULL)
        \brief Constructor

        \param name name of XRC element
        \param className name of class of XRC element
        \param parentNode parent node
    */
    CRXRCObject (const wxString &name, const wxString &className,
            CRXRCNode *parentNode = NULL);


    /*! \fn virtual ~CRXRCObject ()
        \brief Destructor
    */
    virtual ~CRXRCObject ();

protected:

private:

private:
    // No copy and assignment constructor:
    CRXRCObject (const CRXRCObject &rhs);
    CRXRCObject & operator= (const CRXRCObject &rhs);
};

} // End namespace swTst

#endif // SWCRXRCOBJECT_H

