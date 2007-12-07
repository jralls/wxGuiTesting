///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRWindowHierarchyHandler.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRWindowHierarchyHandler.h"
#endif

#include <wxGuiTest/swCRWindowHierarchyHandler.h>

#include <wx/xrc/xmlres.h>

#include <Exception/swWxLogicErrorException.h>
#include <Config/swConfigManager.h>

#include "swCRXRCResource.h"
#include "swCRXRCReader.h"

namespace swTst {


// Init single instance:
CRWindowHierarchyHandler *CRWindowHierarchyHandler::ms_instance = NULL;


CRWindowHierarchyHandler::CRWindowHierarchyHandler ()
{
    m_xrcResource = NULL;
    m_configCached = NULL;

    m_contMap[_T("wxDialog")] = _T("dialog");
    m_contMap[_T("wxFrame")] = _T("frame");
    m_contMap[_T("wxPanel")] = _T("panel");
    m_contMap[_T("wxNotebook")] = _T("notebook");
}


CRWindowHierarchyHandler::~CRWindowHierarchyHandler ()
{
    if (m_xrcResource != NULL) {

        delete m_xrcResource;
        m_xrcResource = NULL;
    }

    m_contMap.clear ();
}


CRWindowHierarchyHandler * CRWindowHierarchyHandler::GetInstance ()
{
    if (ms_instance == NULL) {

        ms_instance = new CRWindowHierarchyHandler ();
    }
    return ms_instance;
}


void CRWindowHierarchyHandler::Destroy ()
{
    if (ms_instance != NULL) {

        delete ms_instance;
        ms_instance = NULL;
    }
}


wxString CRWindowHierarchyHandler::FindContainerName (wxWindow *window,
        bool isUnknownCtrl)
{
    wxASSERT (window != NULL);

    // 1. Is it an XRC resource?
    if (this->FindXRCNode (window, isUnknownCtrl) != NULL) {

        CRXRCNode *wdwXrcNode = this->FindContainerXRCNode (window, isUnknownCtrl);
        if (wdwXrcNode != NULL) {

            return wdwXrcNode->GetName ();

        } else {

            // Something went wrong
            return _T("");
        }
    }
    // 2. Maybe it should have been looked after an unknown control?
    if (!isUnknownCtrl) {

        if (this->FindXRCNode (window, true) != NULL) {

            CRXRCNode *wdwXrcNode = this->FindContainerXRCNode (window, true);
            if (wdwXrcNode != NULL) {

                return wdwXrcNode->GetName ();

            } else {

                // Something went wrong
                return _T("");
            }
        }
    }
    // 3. Just go up parent after parent until we find a container with a
    // proper name:
    bool found = false;
    wxWindow *containerWdw = window;
    while ((!found) && (containerWdw != NULL)) {

        wxClassInfo *classInfo = containerWdw->GetClassInfo ();
        wxASSERT (classInfo != NULL);

        ContainerMap::iterator it;
        it = m_contMap.find (classInfo->GetClassName ());
        if ((it != m_contMap.end ()) && (it->second != containerWdw->GetName ())) {

            found = true;

        } else {

            containerWdw = containerWdw->GetParent ();
        }
    }

    return (found ? containerWdw->GetName () : _T(""));
}


CRXRCNode * CRWindowHierarchyHandler::FindXRCNode (wxWindow *window,
        bool isUnknownCtrl)
{
    wxASSERT (window != NULL);

    this->ParseXRC ();

    return this->FindXRCNode (m_xrcResource, window, isUnknownCtrl);
}


CRXRCNode * CRWindowHierarchyHandler::FindContainerXRCNode (
        wxWindow *window, bool isUnknownCtrl)
{
    wxASSERT (window != NULL);

    this->ParseXRC ();

    CRXRCNode *wdwXrcNode = this->FindXRCNode (m_xrcResource, window,
            isUnknownCtrl);
    wxASSERT (wdwXrcNode != NULL);
    CRXRCNode *node = wdwXrcNode;
    bool found = false;
    while ((!found) && (node != NULL)) {

        ContainerMap::iterator it;
        it = m_contMap.find (node->GetClass ());
        if ((it != m_contMap.end ()) && (it->second != node->GetName ())) {

            found = true;

        } else {

            node = node->GetParent ();
        }
    }

    return (found ? node : NULL);
}


CRXRCNode * CRWindowHierarchyHandler::FindXRCNode (CRXRCNode *parent,
        wxWindow *window, bool isUnknownCtrl)
{
    wxASSERT (parent != NULL);
    wxASSERT (window != NULL);

    CRXRCNode *node = NULL;
    wxClassInfo *wdwClassInfo = window->GetClassInfo ();
    wxASSERT (wdwClassInfo != NULL);

    for (int i = 0; i < parent->GetNmbChildren (); i++) {

        node = parent->GetChild (i);
        wxASSERT (node != NULL);

        CRXRCNode *foundNode = this->FindXRCNode (node, window,
                isUnknownCtrl);
        if (foundNode != NULL) {
         
            return foundNode;

        } else if (isUnknownCtrl && (node->GetName () == window->GetName ()) &&
                (node->GetClass () == _T("unknown"))) {

            // "Double-check":
            wxASSERT (wxXmlResource::GetXRCID (node->GetName ()) == window->GetId ());

            return node;

        } else if ((node->GetName () == window->GetName ()) &&
                ((node->GetClass () == wdwClassInfo->GetClassName ()) ||
                (wxString (wdwClassInfo->GetClassName ()).StartsWith (
                node->GetClass ())))) {
            // StartsWith: wdwClassInfo->GetClassName (): wxSlider95,
            //   but node->GetClass (): wxSlider

            // "Double-check":
            wxASSERT (wxXmlResource::GetXRCID (node->GetName ()) == 
                    window->GetId ());

            return node;
        }
    }
    return NULL;
}


void CRWindowHierarchyHandler::ParseXRC ()
{
    wxASSERT (sw::ConfigManager::GetInstance () != NULL);

    wxString resDir;
    sw::ConfigManager::GetInstance ()->GetResourceDir (resDir);

    if ((m_xrcResource == NULL) ||
            (m_configCached != sw::ConfigManager::GetInstance ()) ||
            (m_resDirCached != resDir)) {

        m_configCached = sw::ConfigManager::GetInstance ();
        if (!m_configCached->GetResourceDir (m_resDirCached)) {
        
            throw sw::WxLogicErrorException (
                    _("Resource directory not found in config file"));
        }
        wxASSERT (!m_resDirCached.IsEmpty ());

        CRXRCReader *reader = new swTst::CRXRCReader (m_resDirCached);
        m_xrcResource = reader->GetResource ();
        delete reader;
        wxASSERT (m_xrcResource != NULL);
    }
}

} // End namespace swTst
