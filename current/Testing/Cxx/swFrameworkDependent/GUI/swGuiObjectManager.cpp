///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/GUI/swGuiObjectManager.cpp
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Fuereder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swGuiObjectManager.h"
#endif

#include "swGuiObjectManager.h"

#include "swApp.h"

namespace sw {


BEGIN_EVENT_TABLE(GuiObjectManager, wxEvtHandler)
    EVT_MENU(wxID_ABOUT, GuiObjectManager::OnAbout)
    EVT_MENU(-1, GuiObjectManager::OnMenuEvent)
END_EVENT_TABLE()


GuiObjectManager *GuiObjectManager::ms_instance = NULL;


GuiObjectManager::GuiObjectManager ()
{
	wxASSERT (ms_instance == NULL);
	ms_instance = this;
}


GuiObjectManager::~GuiObjectManager ()
{
	// We have to manually delete the elements of the list
	// as STL containers don't do this for us (and we don't
	// use smart pointer yet :( )

	GuiObjectListList::iterator guiObjectListIt = m_guiObjectListList.begin ();
	for (; guiObjectListIt != m_guiObjectListList.end (); guiObjectListIt++) {

		GuiObjectList::iterator guiObjectIt = guiObjectListIt->second->begin ();
		for	(; guiObjectIt != guiObjectListIt->second->end (); guiObjectIt++) {

			delete guiObjectIt->second;
			guiObjectIt->second = NULL;
		}

		delete guiObjectListIt->second;
		guiObjectListIt->second = NULL;
	}

	// We don't delete the wxMenu elements as they will be destroyed
	// when deleting the menu bar.

	MenuListList::iterator menuListIt = m_menuListList.begin ();
	for (; menuListIt != m_menuListList.end (); menuListIt++) {

		delete menuListIt->second;
		menuListIt->second = NULL;
	}

    GuiObjectListMap::iterator groupEnableIt;
    for (groupEnableIt = m_groupEnableMap.begin ();
            groupEnableIt != m_groupEnableMap.end (); groupEnableIt++) {

        (*groupEnableIt).second.clear ();
    }
    m_groupEnableMap.clear ();

	// next call to GetInstance must reinstantiate GuiObjectManager
	ms_instance = NULL;
}


GuiObjectManager * GuiObjectManager::GetInstance ()
{
	if (ms_instance == NULL) {

		new GuiObjectManager ();
	}

	return ms_instance;
}


void GuiObjectManager::RegisterCategory (const wxString &category)
{
	wxASSERT (!category.IsNull ());

	if (m_guiObjectListList[category] == NULL) {

		m_guiObjectListList[category] = new GuiObjectList ();
	}

	if (m_menuListList[category] == NULL) {

		m_menuListList[category] = new MenuList ();
	}

	wxASSERT (m_guiObjectListList[category] != NULL);
	wxASSERT (m_menuListList[category] != NULL);
}


void GuiObjectManager::RegisterGuiObject (GuiObject *guiObject,
        const int enableGroupIdx)
{
	wxASSERT (guiObject != NULL);
	wxASSERT (!guiObject->GetCategory ().IsNull ());

	RegisterCategory (guiObject->GetCategory ());

	GuiObjectList *guiObjectList = m_guiObjectListList[guiObject->GetCategory ()];
	long id = wxNewId ();

	(*guiObjectList)[id] = guiObject;

    if (enableGroupIdx >= 0) {

        // If no map entry for this group index exists, an empty default list
        // is inserted automatically:
        m_groupEnableMap[enableGroupIdx].push_back (guiObject);
    }

	AddToMenu (guiObject, id);

	guiObject->Init ();
}


GuiObject *GuiObjectManager::UnregisterGuiObject (GuiObject *guiObject)
{
	wxASSERT (guiObject != NULL);
	wxASSERT (!guiObject->GetCategory ().IsNull ());

	GuiObjectList *guiObjectList = m_guiObjectListList[guiObject->GetCategory ()];
	wxASSERT (guiObjectList != NULL);

	guiObjectList->erase (FindId(guiObject));

	RemoveFromMenu (guiObject, FindId (guiObject));

	return guiObject;
}


GuiObject * GuiObjectManager::FindGuiObject (const wxString &name) const
{
    GuiObjectListList::const_iterator mapIt;
    GuiObject *foundGuiObject = NULL;

    mapIt = m_guiObjectListList.begin ();
    while ((mapIt != m_guiObjectListList.end ()) && (foundGuiObject == NULL)) {

	    GuiObjectList::const_iterator it;

        it = (*mapIt).second->begin ();
        while ((it != (*mapIt).second->end ()) && (foundGuiObject == NULL)) {

            if ((*it).second->GetName () == name) {

                foundGuiObject = (*it).second;
            }

            it++;
	    }

        mapIt++;
    }

    return foundGuiObject;
}


void GuiObjectManager::UseMenu (wxMenu *menu, const wxString &category)
{
	wxASSERT (!category.IsNull ());

	RegisterCategory (category);

	MenuList *menuList = m_menuListList[category];
	menuList->push_front(menu);

	// we now add all objects of the same category in this menu.
	GuiObjectList *guiObjectList = m_guiObjectListList[category];
	GuiObjectList::iterator guiObjectIt = guiObjectList->begin ();
	for (; guiObjectIt != guiObjectList->end (); guiObjectIt++) {

		AddToMenu (menu, guiObjectIt->second, guiObjectIt->first);
	}
}


void GuiObjectManager::RemoveMenu (wxMenu *menu, wxString &category)
{
    MenuList *menuList = m_menuListList[category];
	wxASSERT (menuList != NULL);

	menuList->remove (menu);

	GuiObjectList *guiObjectList = m_guiObjectListList[category];
	GuiObjectList::iterator guiObjectIt = guiObjectList->begin ();
	for (; guiObjectIt != guiObjectList->end (); guiObjectIt++) {

		menu->Enable (guiObjectIt->first, false);
    }
}


void GuiObjectManager::PermanentlyRemoveMenu (wxMenuBar *menuBar, wxString &category)
{
    int menuID;
    wxMenu *menu;

    MenuList *menuList = m_menuListList[category];
	wxASSERT (menuList != NULL);

    menuID = menuBar->FindMenu (category);
    menu = menuBar->GetMenu (menuID);
	menuList->remove (menu);

	GuiObjectList *guiObjectList = m_guiObjectListList[category];
	GuiObjectList::iterator guiObjectIt = guiObjectList->begin ();
	for (; guiObjectIt != guiObjectList->end (); guiObjectIt++) {

		menu->Enable (guiObjectIt->first, false);
        // Destroy menuitem permanently
        menu->Destroy (guiObjectIt->first);
    }

    // Remove menu from menubar permanently
    wxMenu *menuToDelete = menuBar->Remove (menuID);
    if (menuToDelete != NULL) {

        delete menuToDelete;
    }
}


void GuiObjectManager::AddToMenu (GuiObject *guiObject, long id)
{
	MenuList *menuList = m_menuListList[guiObject->GetCategory ()];

	MenuList::iterator menuIt = menuList->begin ();
	for (; menuIt != menuList->end(); menuIt++) {

		AddToMenu (*menuIt, guiObject, id);
	}
}


void GuiObjectManager::AddToMenu (wxMenu *menu, GuiObject *guiObject, long id)
{
    wxString helpString( _T(""));
	wxString title (guiObject->GetName ());

	bool isCheckable = guiObject->IsExclusive () || guiObject->IsInteractive ();

	if (!guiObject->IsInteractive ()) {
	    title << _T("...");
	}

	menu->Append (id, title, helpString, isCheckable);

	if (isCheckable) {
		menu->Check (id, guiObject->IsEnabled ());
	}
}


void GuiObjectManager::RemoveFromMenu (GuiObject *guiObject, long id)
{
	MenuList *menuList = m_menuListList[guiObject->GetCategory ()];
	MenuList::iterator MenuIt = menuList->begin();
	for (; MenuIt != menuList->end (); MenuIt++) {
		(*MenuIt)->Destroy (id);
	}
}


void GuiObjectManager::UpdateStatus (GuiObject *guiObject)
{
	MenuList *menuList = m_menuListList[guiObject->GetCategory ()];
	wxASSERT_MSG (menuList != NULL, 
		      _T("guiObject has not been registered !!"));

	bool enabled = guiObject->IsEnabled ();
	int id = FindId (guiObject);

	MenuList::iterator menuIt = menuList->begin ();
	for (; menuIt != menuList->end(); menuIt++) {

		(*menuIt)->Check (id, enabled);
	}

	// only one exclusive gui object must be active
	if (guiObject->IsExclusive () && guiObject->IsEnabled ()) {

		GuiObjectList *guiObjectList = m_guiObjectListList[guiObject->GetCategory ()];
		GuiObjectList::iterator guiObjectIt = guiObjectList->begin ();
		for (; guiObjectIt != guiObjectList->end (); guiObjectIt++) {

			if (guiObjectIt->second != guiObject) {

				guiObjectIt->second->Enable (FALSE);
			}
		}
	}
}


void GuiObjectManager::UpdateGuiEnableStatus (GuiObject *guiObject,
        const bool enable)
{
	int id = FindId (guiObject);
	MenuList *menuList = m_menuListList[guiObject->GetCategory ()];
	MenuList::iterator MenuIt = menuList->begin();
	for (; MenuIt != menuList->end (); MenuIt++) {

		(*MenuIt)->Enable (id, enable);
	}
}


void GuiObjectManager::OnMenuEvent (wxCommandEvent& event)
{
    GuiObjectListList::iterator guiObjectListIt = m_guiObjectListList.begin ();

	for (; guiObjectListIt != m_guiObjectListList.end (); guiObjectListIt++) {

		GuiObjectList *guiObjectList = guiObjectListIt->second;
		GuiObjectList::iterator guiObjectIt = guiObjectList->find (event.GetId ());

		if (guiObjectIt != guiObjectList->end ()) {

			if (guiObjectIt->second->IsExclusive () && guiObjectIt->second->IsEnabled ()) {

				UpdateStatus (guiObjectIt->second);

			} else {

				Enable (guiObjectIt->second, event.IsChecked ());
			}
			return;
		}
	}

	event.Skip ();
}


//TODO: extend help menu and refactor it
void GuiObjectManager::OnAbout (wxCommandEvent& event)
{
    App::GetInstance ()->DisplayAbout ();
}


long GuiObjectManager::FindId (GuiObject *guiObject)
{
	GuiObjectList *guiObjectList = m_guiObjectListList[guiObject->GetCategory ()];

	GuiObjectList::iterator guiObjectIt = guiObjectList->begin ();
	for (; guiObjectIt != guiObjectList->end (); guiObjectIt++) {

		if (guiObjectIt->second == guiObject) {
			return guiObjectIt->first;
		}
	}

	wxCHECK_MSG(FALSE, wxNOT_FOUND, _T("guiObject not registered !!"));
}


wxString GuiObjectManager::FindName (long id) const
{
    GuiObjectListList::const_iterator mapIt;
    wxString name;

    mapIt = m_guiObjectListList.begin ();
    while ((mapIt != m_guiObjectListList.end ()) && (name.IsEmpty ())) {

	    GuiObjectList::const_iterator it;

        it = (*mapIt).second->begin ();
        while ((it != (*mapIt).second->end ()) && (name.IsEmpty ())) {

            if ((*it).first == id) {

                name = (*it).second->GetName ();
            }

            it++;
	    }

        mapIt++;
    }

    return name;
}


void GuiObjectManager::Enable (GuiObject *guiObject, bool enable)
{
	guiObject->Enable (enable);
}


void GuiObjectManager::EnableMenu (wxMenu *menu, bool enable)
{
    for (wxMenuItemList::Node *node = menu->GetMenuItems ().GetFirst (); node; node = node->GetNext ()) {

        wxMenuItem *menuItem = node->GetData();
        menuItem->Enable (enable);
    }
}


void GuiObjectManager::EnableGroup (const unsigned int groupIdx, bool enable)
{
    RealGuiObjectList::iterator it;

    if (m_groupEnableMap.find (groupIdx) != m_groupEnableMap.end ()) {

        for (it = m_groupEnableMap[groupIdx].begin ();
                it != m_groupEnableMap[groupIdx].end (); it++) {

            this->UpdateGuiEnableStatus (*it, enable);
        }
    }
}


void GuiObjectManager::LoadSettings ()
{
	GuiObjectListList::iterator guiObjectListIt = m_guiObjectListList.begin ();
	for (; guiObjectListIt != m_guiObjectListList.end (); guiObjectListIt++) {

		GuiObjectList *guiObjectList = guiObjectListIt->second;
		GuiObjectList::iterator guiObjectIt = guiObjectList->begin ();
		for (; guiObjectIt != guiObjectList->end (); guiObjectIt++) {

			guiObjectIt->second->LoadSettings ();
		}
	}
}


void GuiObjectManager::SaveSettings ()
{
	GuiObjectListList::iterator guiObjectListIt = m_guiObjectListList.begin ();
	for (; guiObjectListIt != m_guiObjectListList.end (); guiObjectListIt++) {

		GuiObjectList *guiObjectList = guiObjectListIt->second;
		GuiObjectList::iterator guiObjectIt = guiObjectList->begin ();
		for (; guiObjectIt != guiObjectList->end (); guiObjectIt++) {

			guiObjectIt->second->SaveSettings ();
		}
	}
}

} // End namespace sw
