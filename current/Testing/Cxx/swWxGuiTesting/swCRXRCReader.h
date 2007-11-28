///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRXRCReader.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRXRCREADER_H
#define SWCRXRCREADER_H

#ifdef __GNUG__
    #pragma interface "swCRXRCReader.h"
#endif

#include "Common.h"

#include "swCRXRCResource.h"

class wxXmlDocument;
class wxXmlNode;


namespace swTst {


/*! \class CRXRCReader
    \brief Read in and parse XRC files; returns XRC node hierarchy.

    If given filename is pointing to a valid directory instead of a single file
    the returned node hierarchy contains the nodes from all files (regular
    expression: "filename/*.xrc").
*/
class CRXRCReader
{
public:
    /*! \fn CRXRCReader (const wxString &filename)
        \brief Constructor

        \param filename name of XRC file to read, or path holding several XRC
            files of interest
    */
    CRXRCReader (const wxString &filename);


    /*! \fn virtual ~CRXRCReader ()
        \brief Destructor
    */
    virtual ~CRXRCReader ();


    /*! \fn virtual CRXRCResource * GetResource ()
        \brief Initiates the XRC file parsing and returns XRC node hierarchy.

        \return pointer to XRC node hierarchy (= XRC resource node)
    */
    virtual CRXRCResource * GetResource ();

protected:
    /*! \fn virtual void ParseXmlDoc (CRXRCResource *resource, wxXmlDocument &doc) const
        \brief Does the actual XRC file parsing.

        \param resource root of XRC node hierarchy (= XRC resource node)
        \param doc      xml document to parse
    */
    virtual void ParseXmlDoc (CRXRCResource *resource, wxXmlDocument &doc) const;


    /*! \fn virtual void RecursivelyParseXmlNode (wxXmlNode *node, CRXRCNode *contextNode) const
        \brief Parse the given XRC XML node.

        \param node         XRC XML node to parse
        \param contextNode  current context node in created XRC node hierarchy
    */
    virtual void RecursivelyParseXmlNode (wxXmlNode *node,
            CRXRCNode *contextNode) const;

private:
    wxString m_filename;

private:
    // No copy and assignment constructor:
    CRXRCReader (const CRXRCReader &rhs);
    CRXRCReader & operator= (const CRXRCReader &rhs);
};

} // End namespace swTst

#endif // SWCRXRCREADER_H

