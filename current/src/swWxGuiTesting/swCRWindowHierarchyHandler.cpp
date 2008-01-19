///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRWindowHierarchyHandler.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRWindowHierarchyHandler.h"
#endif

#include <wxGuiTest/swCRWindowHierarchyHandler.h>

#include <wx/xrc/xmlres.h>
#include <wx/dir.h>


using namespace swTst;

CRWindowHierarchyHandler::ContainerMap CRWindowHierarchyHandler::m_contMap;
// Init single instance:
CRWindowHierarchyHandler *CRWindowHierarchyHandler::ms_instance = NULL;


CRWindowHierarchyHandler::CRWindowHierarchyHandler ()
{
    m_contMap.clear();
    m_contMap.insert(std::make_pair(_T("wxDialog"),_T("dialog")));
    m_contMap.insert(std::make_pair(_T("wxFrame"), _T("frame")));
    m_contMap.insert(std::make_pair(_T("wxPanel"), _T("panel")));
    m_contMap.insert(std::make_pair(_T("wxNotebook"), _T("notebook")));
    m_contMap.insert(std::make_pair(_T("wxMDIChildFrame"), _T("frame")));
    m_contMap.insert(std::make_pair(_T("wxMDIParentFrame"), _T("frame")));
}


CRWindowHierarchyHandler::~CRWindowHierarchyHandler ()
{
//Shared pointers do the work
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


wxString CRWindowHierarchyHandler::FindContainerName (wxWindow *window)
{
    wxASSERT (window != NULL);
    bool found = false;
    wxWindow *containerWdw = window;
    while ((!found) && (containerWdw != NULL)) {

        wxClassInfo *classInfo = containerWdw->GetClassInfo ();
        wxASSERT (classInfo != NULL);

        ContainerMap::const_iterator it;
	wxString className(classInfo->GetClassName ());
        it = m_contMap.find (className);
        if ((it != m_contMap.end ()) && (it->second != containerWdw->GetName ())) {

            found = true;

        } else {

            containerWdw = containerWdw->GetParent ();
        }
    }

    return (found ? containerWdw->GetName () : _T(""));
}



