///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/VtkWxGuiTesting/CRVtkCapture.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRVtkCapture.h"
#endif

#include <wxGuiTest/VtkGuiTesting/CRVtkCapture.h>

#include <wx/xrc/xmlres.h>

#include <wxGuiTest/VtkGuiTesting/CRVtkCaptureControl.h>

// VTK capture panel XRC file is compiled into a c++ file with embedded resources:
extern void InitVtkCapturePanelXRC ();

namespace wxTst {


CRVtkCapture::CRVtkCapture ()
{
    // Nothing to do
}


CRVtkCapture::~CRVtkCapture ()
{
    // Nothing to do
}


CRCaptureControl * CRVtkCapture::CreateEvtHandler () const
{
    return new CRVtkCaptureControl (m_dialog);
}


void CRVtkCapture::CreateDialog ()
{
    CRCapture::CreateDialog ();
    m_dialog->SetTitle (_("VTK Capture Dialog"));
}


wxPanel * CRVtkCapture::LoadPanel ()
{
    InitVtkCapturePanelXRC ();
    return wxXmlResource::Get ()->LoadPanel (m_dialog, _T("VtkCapturePanel"));
}

} // End namespace wxTst
