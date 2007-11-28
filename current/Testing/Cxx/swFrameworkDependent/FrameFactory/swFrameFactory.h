///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swFrameFactory.h
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWFRAMEFACTORY_H
#define SWFRAMEFACTORY_H

#ifdef __GNUG__
    #pragma interface "swFrameFactory.h"
#endif

#include "Common.h"

#include "swMainFrame.h"
#include "swDefaultDialog.h"
#include "swToolBar.h"

namespace sw {


class FrameFactory
{
public:
	virtual ~FrameFactory ();

	static void SetInstance (FrameFactory *frameFactory);

	static FrameFactory *GetInstance ();


	/*! \fn virtual DefaultDialog *CreateDefaultDialog (const long style = wxDEFAULT_DIALOG_STYLE)
		\brief Returns a DefaultDialog associated with the FrameFactory.

        \param style dialog creation style
	*/
	virtual DefaultDialog *CreateDefaultDialog (const long style = wxDEFAULT_DIALOG_STYLE) = 0;


	/*! \fn virtual ToolBar *CreateToolBar (const long style = wxNO_BORDER | wxTB_FLAT | wxTB_HORIZONTAL) = 0
		\brief Returns a ToolBar associated with the FrameFactory.

        TODO: if one wants to add a toolbar not to the main frame for non-FL
          style, the actual parent frame will be another required parameter.

        \param style toolbar creation style
	*/
    virtual ToolBar *CreateToolBar (const long style = wxNO_BORDER | wxTB_FLAT | wxTB_HORIZONTAL) = 0;


	/*! \fn virtual ToolBar *CreateNamedToolBar (const wxString &name, const long style = wxNO_BORDER | wxTB_FLAT | wxTB_HORIZONTAL)
		\brief Returns a named ToolBar for later looking up.

        \param name name of toolbar for looking it up with ToolBarRegistry::FindToolBarByName() method
        \param style toolbar creation style
	*/
    virtual ToolBar *CreateNamedToolBar (const wxString &name,
            const long style = wxNO_BORDER | wxTB_FLAT | wxTB_HORIZONTAL);


	/*! \fn virtual MainFrame *GetMainFrame () = 0
		\brief Returns the main frame of the application.
	*/
	virtual MainFrame *GetMainFrame () = 0;

	virtual void DestroyMainFrame () = 0;

protected:
    FrameFactory ();  // Hide constructor

private:
	static FrameFactory *ms_instance;
};

} // End namespace sw

#endif // SWFRAMEFACTORY_H
