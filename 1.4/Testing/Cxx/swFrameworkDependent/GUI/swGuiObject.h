///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/GUI/swGuiObject.h
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWGUIOBJECT_H
#define SWGUIOBJECT_H

#ifdef __GNUG__
//    #pragma interface "swGuiObject.h"
#endif

#include "Common.h"

namespace sw {


class GuiObject 
{
public:
	virtual ~GuiObject () {};

	virtual void Init () = 0;

	virtual bool IsExclusive () const = 0;
	virtual bool IsInteractive () const = 0;

	virtual const wxString &GetCategory () const = 0;
	virtual const wxString &GetName () const = 0;

	virtual void Enable (bool enable) = 0;
	virtual bool IsEnabled () const = 0;

	virtual void LoadSettings () = 0;
	virtual void SaveSettings () = 0;
};

} // End namespace sw

#endif // SWGUIOBJECT_H
