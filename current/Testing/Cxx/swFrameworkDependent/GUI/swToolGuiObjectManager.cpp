///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/GUI/swToolGuiObjectManager.cpp
// Author:      Reinhold Füreder
// Created:     2005
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swToolGuiObjectManager.h"
#endif

#include "swToolGuiObjectManager.h"

#include "swToolGuiObject.h"
#include "swToolBar.h"

namespace sw {


ToolGuiObjectManager::ToolGuiObjectManager ()
{
    // Nothing to do?
}


ToolGuiObjectManager::~ToolGuiObjectManager ()
{
    //TODO: delete all toolbars from m_toolList?
    //  GuiObjects will be deleted in ~GuiObjectManager() already
}


GuiObject * ToolGuiObjectManager::UnregisterGuiObject (GuiObject *guiObject)
{
    ToolGuiObject *toolGuiObject = dynamic_cast< ToolGuiObject * >(guiObject);
    if (toolGuiObject != NULL) {

        int id = FindId (toolGuiObject);
        m_toolList[toolGuiObject]->RemoveTool (id);
	    m_toolList.erase (toolGuiObject);
    }

    return GuiObjectManager::UnregisterGuiObject (guiObject);
}


void ToolGuiObjectManager::AddTool (ToolGuiObject &toolGuiObject,
        ToolBar &toolBar)
{
    // Use same ID as for menu allowing reuse of menu event handler:
    int id = this->FindId (&toolGuiObject);
    if (toolGuiObject.CanAddTool ()) {

        toolGuiObject.AddTool (id, toolBar);

    } else {

        // We assume:
        //   (a) the label gives enough information as tooltip.
        //   (b) an exclusive tool must be toggleable.
        toolBar.AddTool (id, _T(""), toolGuiObject.GetToolIcon (),
                toolGuiObject.GetName (), toolGuiObject.IsToggle (),
                !toolGuiObject.IsExclusive ());
    }

    m_toolList[&toolGuiObject] = &toolBar;
}


void ToolGuiObjectManager::UpdateStatus (GuiObject *guiObject)
{
    GuiObjectManager::UpdateStatus (guiObject);

    ToolGuiObject *toolGuiObject = dynamic_cast< ToolGuiObject * >(guiObject);
    if (toolGuiObject != NULL) {

	    bool enabled = toolGuiObject->IsEnabled ();
	    int id = FindId (toolGuiObject);

        m_toolList[toolGuiObject]->ToggleTool (id, enabled);
    }
}


void ToolGuiObjectManager::UpdateGuiEnableStatus (GuiObject *guiObject,
        const bool enable)
{
    GuiObjectManager::UpdateGuiEnableStatus (guiObject, enable);

    ToolGuiObject *toolGuiObject = dynamic_cast< ToolGuiObject * >(guiObject);
    if (toolGuiObject != NULL) {

        int id = FindId (toolGuiObject);
        m_toolList[toolGuiObject]->EnableTool (id, enable);
    }
}

} // End namespace sw
