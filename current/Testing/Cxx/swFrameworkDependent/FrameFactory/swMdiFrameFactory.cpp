///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swMdiFrameFactory.cpp
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swMdiFrameFactory.h"
#endif

#include "swMdiFrameFactory.h"

#include <wx/minifram.h>
#include <wx/config.h>

#include "swMdiDefaultDialog.h"
#include "swMdiToolBar.h"

namespace sw {


MdiFrameFactory::MdiFrameFactory (wxDocManager* manager)
{
	m_mainFrame = NULL;
    m_documentManager = manager;
}


MdiFrameFactory::~MdiFrameFactory ()
{
	if (m_documentManager != NULL) {

		delete m_documentManager;
	}
}


DefaultDialog *MdiFrameFactory::CreateDefaultDialog (const long style)
{
	return new MdiDefaultDialog (GetMainFrame (), style);
}


ToolBar *MdiFrameFactory::CreateToolBar (const long style)
{
    return new MdiToolBar (GetMainFrame (), style);
}


MainFrame *MdiFrameFactory::GetMainFrame ()
{
	if (m_mainFrame == NULL) {

		m_mainFrame = new MdiMainFrame (m_documentManager);
	}
	return m_mainFrame;
}


void MdiFrameFactory::DestroyMainFrame () 
{
  if (m_mainFrame != NULL) {
    m_mainFrame->GetWindow ()->Destroy();
    m_mainFrame = NULL;
  }
}

} // End namespace sw
