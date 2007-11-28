///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swMdiFrameFactory.h
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWMDIFRAMEFACTORY_H
#define SWMDIFRAMEFACTORY_H

#ifdef __GNUG__
    #pragma interface "swMdiFrameFactory.h"
#endif

#include "Common.h"

#include <wx/docmdi.h>
#include <wx/docview.h>

#include <wx/cmdproc.h>

#include "swFrameFactory.h"

#include "swMdiMainFrame.h"

namespace sw {


class MdiFrameFactory : public FrameFactory
{
public:
	MdiFrameFactory (wxDocManager* manager);

	~MdiFrameFactory ();

	DefaultDialog *CreateDefaultDialog (const long style = wxDEFAULT_DIALOG_STYLE);

    ToolBar *CreateToolBar (const long style = wxNO_BORDER | wxTB_FLAT | wxTB_HORIZONTAL);

	MainFrame *GetMainFrame ();

	void DestroyMainFrame ();

private:
	MdiMainFrame *m_mainFrame;

    wxDocManager *m_documentManager;
};

} // End namespace sw

#endif // SWMDIFRAMEFACTORY_H
