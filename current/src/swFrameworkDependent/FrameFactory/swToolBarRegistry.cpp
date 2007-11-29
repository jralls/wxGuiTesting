///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swToolBarRegistry.cpp
// Author:      Reinhold Fuereder
// Created:     2005
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swToolBarRegistry.h"
#endif

#include "swToolBarRegistry.h"

namespace sw {


ToolBarRegistry* ToolBarRegistry::ms_instance = NULL;


ToolBarRegistry::ToolBarRegistry ()
{
	wxASSERT (ms_instance == NULL);
}


ToolBarRegistry::~ToolBarRegistry ()
{
    m_toolBarMap.clear ();

	if (ms_instance == this) {

		ms_instance = NULL;
	}
}


ToolBarRegistry * ToolBarRegistry::GetInstance ()
{
    if (ms_instance == NULL) {

        ms_instance = new ToolBarRegistry ();
    }
	return ms_instance;
}


void ToolBarRegistry::Destroy ()
{
    if (ms_instance != NULL) {

        delete ms_instance;
        ms_instance = NULL;
    }
}


bool ToolBarRegistry::Register (ToolBar *toolbar, const wxString &name)
{
    if (m_toolBarMap.find (name) != m_toolBarMap.end ()) {

        return false;
    }
    m_toolBarMap[name] = toolbar;
    return true;
}


bool ToolBarRegistry::Unregister (const wxString &name)
{
    ToolBarMap::iterator it;

    it = m_toolBarMap.find (name); 
    if (it == m_toolBarMap.end ()) {

        return false;
    }

    m_toolBarMap.erase (name);
    return true;
}


ToolBar * ToolBarRegistry::FindToolBarByName (const wxString &name) const
{
    ToolBarMap::const_iterator it;

    it = m_toolBarMap.find (name);

    return (it != m_toolBarMap.end ()) ? it->second : NULL;
}


wxString ToolBarRegistry::FindToolBarNameByWdwPtr (wxWindow *wdw) const
{
    ToolBarMap::const_iterator it;

    it = m_toolBarMap.begin ();
    bool found = false;
    while ((!found) && (it != m_toolBarMap.end ())) {

        if ((*it).second->GetWindow () == wdw) {

            found = true;

        } else {

            it++;
        }
    }

    return (it != m_toolBarMap.end ()) ? it->first : _T("");
}

} // End namespace sw
