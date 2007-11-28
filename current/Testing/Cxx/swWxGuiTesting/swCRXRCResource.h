///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRXRCResource.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRXRCRESOURCE_H
#define SWCRXRCRESOURCE_H

#ifdef __GNUG__
    #pragma interface "swCRXRCResource.h"
#endif

#include "Common.h"

#include <list>

#include "swCRXRCNode.h"

namespace swTst {


/*! \class CRXRCResource
    \brief Concrete XRC resource node definition (1 resource per XRC file).
*/
class CRXRCResource : public CRXRCNode
{
public:
    /*! \fn CRXRCResource ()
        \brief Constructor
    */
    CRXRCResource ();


    /*! \fn CRXRCResource (const wxString &name, const wxString &className, CRXRCNode *parentNode = NULL)
        \brief Constructor (for CRXRCObject construction).

        \param name name of XRC element
        \param className name of class of XRC element
        \param parentNode parent node
    */
    CRXRCResource (const wxString &name, const wxString &className,
            CRXRCNode *parentNode = NULL);


    /*! \fn virtual ~CRXRCResource ()
        \brief Destructor
    */
    virtual ~CRXRCResource ();


    /*! \fn virtual void AddChild (CRXRCNode *child)
        \brief Add a child XRC element.

        \param child child element to add
    */
    virtual void AddChild (CRXRCNode *child);


    /*! \fn virtual unsigned int GetNmbChildren () const
        \brief Get number of child XRC elements.

        \return number of child elements
    */
    virtual unsigned int GetNmbChildren () const;


    /*! \fn virtual CRXRCNode * GetChild (unsigned int idx) const
        \brief Get a child XRC element identified by index.

        \param idx index of child element in container
        \return child element identified by index
    */
    virtual CRXRCNode * GetChild (unsigned int idx) const;

protected:
    typedef std::list < CRXRCNode * > NodeList;
    NodeList m_nodeList;

private:

private:
    // No copy and assignment constructor:
    CRXRCResource (const CRXRCResource &rhs);
    CRXRCResource & operator= (const CRXRCResource &rhs);
};

} // End namespace swTst

#endif // SWCRXRCRESOURCE_H

