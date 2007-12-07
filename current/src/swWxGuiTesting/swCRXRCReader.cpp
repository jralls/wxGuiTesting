///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRXRCReader.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRXRCReader.h"
#endif

#include "swCRXRCReader.h"

#include <wx/filename.h>
#include <wx/xml/xml.h>

#include <Exception/swWxLogicErrorException.h>

#include "swCRXRCObject.h"

#include <iostream>

namespace swTst {


CRXRCReader::CRXRCReader (const wxString &filename)
{
    wxASSERT (!filename.IsEmpty ());
    wxFileName filenameObj (filename);
    bool isOk = filenameObj.MakeAbsolute ();
    wxASSERT (isOk);
    m_filename = filenameObj.GetFullPath ();
}


CRXRCReader::~CRXRCReader ()
{
    // Nothing to do
}


CRXRCResource * CRXRCReader::GetResource ()
{
    wxXmlDocument doc;
    CRXRCResource *resource = NULL;
    bool isFailed = false;
    wxString failMsg;

    resource = new CRXRCResource ();

    try {
        
        if (::wxFileExists (m_filename)) {
    
            if (!doc.Load(m_filename)) {
                isFailed = true;
                failMsg = wxString::Format (_T("%s: %s"),
                        _("Given filename is not a valid xrc file"),
                        m_filename.c_str ());
            } else {
                ParseXmlDoc(resource, doc);
            }
    
        } else if (::wxDirExists (m_filename)) {
    
            // Should we restrict looking in sub directories?
            wxString file = ::wxFindFirstFile (m_filename + _T("/*.xrc") /*, wxFILE*/);
            while (!file.IsEmpty ()) {
                
                if (!doc.Load(file)) {
                    isFailed = true;
                    failMsg = wxString::Format (_T("%s: %s"),
                            _("Given filename is not a valid xrc file"),
                            file.c_str ());
                } else {
                    ParseXmlDoc(resource, doc);
                }
                file = ::wxFindNextFile ();
            }
    
        } else {
    
            isFailed = true;
            failMsg = wxString::Format (_T("%s: %s"),
                    _("Given filename is neither a valid file, nor a path"),
                    m_filename.c_str ());
        }

    } catch (std::exception &e) {

        isFailed = true;
        failMsg = wxString::Format (_T("%s: %s"), _("XML error"), e.what ());

    } catch (...) {

        isFailed = true;
        failMsg = wxString::Format (_T("%s"), _("XML error"));
    }

    if (isFailed) {

        throw sw::WxLogicErrorException (failMsg);
    }

    return resource;
}


void CRXRCReader::ParseXmlDoc (CRXRCResource *resource, wxXmlDocument &doc) const
{
    if (doc.GetRoot ()->GetName () != wxT("resource")) {
        
        throw sw::WxLogicErrorException (_("First element must be <resource>"));
    }
    
    wxXmlNode *child = doc.GetRoot ()->GetChildren ();
    
    RecursivelyParseXmlNode (child, resource);
}


void CRXRCReader::RecursivelyParseXmlNode(wxXmlNode *node, CRXRCNode *contextNode) const
{
    while (node) {

        if (node->GetName () == wxT("object")) {
         
            wxString objName;
            wxString objClass;
            
            node->GetPropVal (wxT("name"), &objName);
            node->GetPropVal (wxT("class"), &objClass);
    
            CRXRCObject *object = new CRXRCObject (objName, objClass, contextNode);
            contextNode->AddChild (object);
            
            wxXmlNode *child = node->GetChildren ();
            RecursivelyParseXmlNode (child, object);
        }
        
        node = node->GetNext ();
    }    
} 

} // End namespace swTst

