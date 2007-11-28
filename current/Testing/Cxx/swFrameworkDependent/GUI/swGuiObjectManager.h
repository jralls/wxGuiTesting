///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/GUI/swGuiObjectManager.h
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWGUIOBJECTMANAGER_H
#define SWGUIOBJECTMANAGER_H

#ifdef __GNUG__
    #pragma interface "swGuiObjectManager.h"
#endif

#include "Common.h"

#include "swGuiObject.h"

#include <map>
#include <list>

namespace sw {


class GuiObjectManager: public wxEvtHandler
{
    DECLARE_EVENT_TABLE()

public:
    /*! \fn ~GuiObjectManager ()
		\brief Destructor.
	*/
	~GuiObjectManager ();


    /*! \fn static GuiObjectManager * GetInstance ()
		\brief Get single instance.

        \return single Gui object manager instance
	*/
	static GuiObjectManager * GetInstance ();


    /*! \fn void RegisterGuiObject (GuiObject *guiObject, const int enableGroupIdx = -1)
		\brief Register GUI object to be managed.

        All registered GUI objects with the same enableGroupIdx parameter
        value >= 0 form a group concerning enabling/disabling. Initially it
        was intended (although not restricted) to be enabled/disabled depending
        on the existence of at least one document. E.g. selecting only makes
        sense if there is something to select.
        Because this concept is useful in more general form an indefinite
        number of groups is supported now. Use EnableGroup() method.

        \param guiObject GUI object to be managed
        \param enableGroupIdx if >= 0, this GUI object belongs to a group which
            can be enabled/disabled with EnableGroup() method.
	*/

    void RegisterGuiObject (GuiObject *guiObject, const int enableGroupIdx = -1);
    
    /*! \fn void UnregisterGuiObject (GuiObject *guiObject)
		\brief Unregister a GUI object.

        \param guiObject GUI object to be unregistered
	*/
	GuiObject * UnregisterGuiObject (GuiObject *guiObject);


    /*! \fn GuiObject * FindGuiObject (const wxString &name) const
		\brief Find registered GUI objects by name.

        Initially only for testing added!

        \param name name of guiObject to find
        \return first registered guiObject with specified name, or NULL
	*/
    GuiObject * FindGuiObject (const wxString &name) const;

    /*! \fn void UseMenu (wxMenu *menu, const wxString &category)
		\brief Specify which menu should be used for the given category.

        \param menu wxMenu to use.
        \param category name of the category that should be using the given menu.
	*/
	void UseMenu (wxMenu *menu, const wxString &category);

	void RemoveMenu (wxMenu *menu, wxString &category);

	void PermanentlyRemoveMenu (wxMenuBar *menuBar, wxString &category);

	virtual void OnMenuEvent (wxCommandEvent &event);

    //TODO: extend help menu and refactor it
    void OnAbout (wxCommandEvent& event);

    /*! \fn void Enable (GuiObject *guiObject, bool enable = TRUE)
		\brief Enable/disable a GUI objects.

        \param guiObject Gui object of which status needs to be changed.
        \param enable TRUE will enable the gui object, FALSE will disabled it.
	*/
	void Enable (GuiObject *guiObject, bool enable = TRUE);

    /*! \fn void EnableMenu (wxMenu *menu, bool enable = TRUE)
		\brief Enable/disable a menu.

        \param menu Menu of which status needs to be changed.
        \param enable TRUE will enable the menu, FALSE will disabled it.
	*/
	void EnableMenu (wxMenu *menu, bool enable = TRUE);


    /*! \fn virtual void EnableGroup (const unsigned int groupIdx, bool enable = TRUE)
		\brief Enable/disable group of GUI objects.

        \param groupIdx key in m_groupEnableMap to specify group
        \param enable enable/disable all group members
	*/
	virtual void EnableGroup (const unsigned int groupIdx, bool enable = TRUE);


    /*! \fn virtual void UpdateStatus (GuiObject *guiObject)
		\brief Update status of GUI objects GUI appearance WRT check state of menu items.

        \param guiObject whose status is changed
	*/
	virtual void UpdateStatus (GuiObject *guiObject);


    /*! \fn long FindId (GuiObject *guiObject)
		\brief Find ID for GUI object.

        Made public for testability, otherwise protected visibility is enough.

        \param guiObject to find ID for
        \return ID of given GUI object
	*/
	long FindId (GuiObject *guiObject);


    /*! \fn wxString FindName (long id) const;
		\brief Find GUI object name for given ID.

        Only used for Capture & Replay!

        \param id ID of guiObject to find name for
        \return name of GUI object identified by id
	*/
	wxString FindName (long id) const;

    /*! \fn void LoadSettings ()
		\brief Loads the settings in order to reproduce a certain state previously
        saved thanks to SaveSettings.
	*/
    void LoadSettings ();

    /*! \fn void SaveSettings ()
		\brief Saves current gui settings in order to reproduce a 
        certain state later on when LoadSettings is called.
	*/    
    void SaveSettings ();

protected:
    /*! \fn virtual void UpdateGuiEnableStatus (GuiObject *guiObject, const bool enable)
		\brief Enable/disable GUI status appearance of GUI object (toolbar).

        \param guiObject GUI object to update status for
        \param enable enable/disable status
	*/
    virtual void UpdateGuiEnableStatus (GuiObject *guiObject, const bool enable);

private:
	void AddToMenu (GuiObject *guiObject, long id);

	void AddToMenu (wxMenu *menu, GuiObject *guiObject, long id);

	void RemoveFromMenu (GuiObject *guiObject, long id);

	void RegisterCategory (const wxString &category);

	typedef std::map < long, GuiObject * > GuiObjectList;
	typedef std::list < wxMenu * > MenuList;

	typedef std::map < wxString, MenuList *> MenuListList;

	MenuListList m_menuListList;

protected:
	static GuiObjectManager *ms_instance;

	GuiObjectManager ();
	typedef std::map < wxString, GuiObjectList *> GuiObjectListList;
	GuiObjectListList m_guiObjectListList;

    typedef std::list< GuiObject * > RealGuiObjectList;
    typedef std::map< signed char, RealGuiObjectList > GuiObjectListMap;
    GuiObjectListMap m_groupEnableMap;

};

} // End namespace sw

#endif // SWGUIOBJECTMANAGER_H

