///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/GUI/swToolGuiObject.h
// Author:      Reinhold Fuereder
// Created:     2005
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWTOOLGUIOBJECT_H
#define SWTOOLGUIOBJECT_H

#ifdef __GNUG__
//    #pragma interface "swToolGuiObject.h"
#endif

#include <wxGuiTest/Common.h>

#include "swGuiObject.h"
#include "swToolBar.h"

namespace sw {


/*! \class ToolGuiObject
    \brief Extend GuiObject by support for toolbars.

    If the GUI object knows how to add itself as tool (CanAddTool() method
    returns true), AddTool() should be called with IoC principle.
    Otherwise ToolGuiObjectManager creates standard tool by using
    GetToolIcon() method.
*/
class ToolGuiObject : public GuiObject
{
public:
	/*! \fn virtual bool CanAddTool () const = 0
		\brief Indicate if this GUI object is able to add itself to toolbar.
		
		\return true, if GUI object knows how to add itself to toolbar
	*/
    virtual bool CanAddTool () const = 0;


	/*! \fn virtual void AddTool (const int toolId, ToolBar &toolBar) = 0
		\brief Add GUI object as tool to toolbar with IoC principle.
		
        \param toolId ID of tool in toolbar, may be the ID of the control behind
        \param toolBar toolBar to add itself as tool
	*/
    virtual void AddTool (const int toolId, ToolBar &toolBar) = 0;


	/*! \fn virtual const wxBitmap & GetToolIcon () const = 0
		\brief Returns icon for standard tool implementation (= flat bitmap
        button).
		
        \return icon for standard tool
	*/
    virtual const wxBitmap & GetToolIcon () const = 0;


	/*! \fn virtual bool IsToggle () const = 0
		\brief Indicate that this GUI object is togglable, i.e. can stay in
        pressed state.
		
		\return true, if GUI object is togglable
	*/
    virtual bool IsToggle () const = 0;

};

} // End namespace sw

#endif // SWTOOLGUIOBJECT_H
