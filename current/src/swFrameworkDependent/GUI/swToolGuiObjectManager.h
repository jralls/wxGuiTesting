///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/GUI/swToolGuiObjectManager.h
// Author:      Reinhold Fuereder
// Created:     2005
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWTOOLGUIOBJECTMANAGER_H
#define SWTOOLGUIOBJECTMANAGER_H

#ifdef __GNUG__
    #pragma interface "swToolGuiObjectManager.h"
#endif

#include "Common.h"

#include "swGuiObjectManager.h"

namespace sw {

class ToolGuiObject;
class ToolBar;


/*! \class ToolGuiObjectManager
    \brief Extend standard GuiObjectManager with support for toolbars.
*/
class ToolGuiObjectManager : public GuiObjectManager
{
public:
    /*! \fn ToolGuiObjectManager ()
        \brief Constructor
    */
    ToolGuiObjectManager ();


    /*! \fn virtual ~ToolGuiObjectManager ()
        \brief Destructor
    */
    virtual ~ToolGuiObjectManager ();


    /*! \fn GuiObject * UnregisterGuiObject (GuiObject *guiObject)
        \brief Extends unregistering by removing tool if it is a ToolGuiObject.

        \param guiObject GUI object to unregister
    */
    GuiObject * UnregisterGuiObject (GuiObject *guiObject);


    /*! \fn virtual void AddTool (ToolGuiObject &toolGuiObject, ToolBar &toolBar)
        \brief Add GUI object to toolbar.

        \param toolGuiObject GUI object to add to toolbar
        \param toolBar toolBar where GUI object should be added
    */
    virtual void AddTool (ToolGuiObject &toolGuiObject, ToolBar &toolBar);


    /*! \fn virtual void UpdateStatus (GuiObject *guiObject)
		\brief Update status of GUI objects GUI appearance WRT toggle state of tools.

        \param guiObject whose status is changed
	*/
	virtual void UpdateStatus (GuiObject *guiObject);

protected:
    /*! \fn virtual void UpdateGuiEnableStatus (GuiObject *guiObject, const bool enable)
		\brief Enable/disable GUI status appearance of GUI object (toolbar).

        \param guiObject GUI object to update status for
        \param enable enable/disable status
	*/
    virtual void UpdateGuiEnableStatus (GuiObject *guiObject, const bool enable);

protected:
    typedef std::map< ToolGuiObject *, ToolBar * > ToolList;
    ToolList m_toolList;

private:

};

} // End namespace sw

#endif // SWTOOLGUIOBJECTMANAGER_H
