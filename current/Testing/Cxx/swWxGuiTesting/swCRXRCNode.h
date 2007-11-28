///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRXRCNode.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRXRCNODE_H
#define SWCRXRCNODE_H

#ifdef __GNUG__
    #pragma interface "swCRXRCNode.h"
#endif

#include "Common.h"

namespace swTst {


/*! \class CRXRCNode
    \brief Abstract node definition of XRC node.

    Each node has a reference to its parent, a name and a class; each of these
    can be a NULL pointer or an empty string respectively.
*/
class CRXRCNode
{
public:
    /*! \fn CRXRCNode (const wxString &name, const wxString &className, CRXRCNode *parentNode = NULL)
        \brief Constructor

        \param name name of XRC element
        \param className name of class of XRC element
        \param parentNode parent node
    */
    CRXRCNode (const wxString &name, const wxString &className,
            CRXRCNode *parentNode = NULL);


    /*! \fn virtual ~CRXRCNode ()
        \brief Destructor
    */
    virtual ~CRXRCNode ();


    /*! \fn virtual const wxString & GetName () const
        \brief Get name of XRC element.

        \return name of XRC element
    */
    virtual const wxString & GetName () const;


    /*! \fn virtual const wxString & GetClass () const
        \brief Get name of class of XRC element.

        \return name of class of XRC element
    */
    virtual const wxString & GetClass () const;


    /*! \fn virtual void AddChild (CRXRCNode *child) = 0
        \brief Add a child XRC element.

        \param child child element to add
    */
    virtual void AddChild (CRXRCNode *child) = 0;


    /*! \fn virtual unsigned int GetNmbChildren () const = 0
        \brief Get number of child XRC elements.

        \return number of child elements
    */
    virtual unsigned int GetNmbChildren () const = 0;


    /*! \fn virtual CRXRCNode * GetChild (unsigned int idx) const = 0
        \brief Get a child XRC element identified by index.

        \param idx index of child element in container
        \return child element identified by index
    */
    virtual CRXRCNode * GetChild (unsigned int idx) const = 0;


    /*! \fn virtual CRXRCNode * GetParent () const
        \brief Get parent XRC element.

        \return parent element
    */
    virtual CRXRCNode * GetParent () const;

protected:

private:
    wxString m_name;
    wxString m_class;

    CRXRCNode *m_parentNode;

private:
    // No copy and assignment constructor:
    CRXRCNode (const CRXRCNode &rhs);
    CRXRCNode & operator= (const CRXRCNode &rhs);
};

} // End namespace swTst

#endif // SWCRXRCNODE_H

