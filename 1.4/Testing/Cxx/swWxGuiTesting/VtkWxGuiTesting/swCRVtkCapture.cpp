///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/VtkWxGuiTesting/swCRVtkCapture.cpp
// Author:      Reinhold F�reder
// Created:     2004
// Copyright:   (c) 2005 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRVtkCapture.h"
#endif

#include "swCRVtkCapture.h"

#include "wx/xrc/xmlres.h"

#include "swCRVtkCaptureControl.h"

// VTK capture panel XRC file is compiled into a c++ file with embedded resources:
extern void InitVtkCapturePanelXRC ();

namespace swTst {


CRVtkCapture::CRVtkCapture ()
{
    // Nothing to do
}


CRVtkCapture::~CRVtkCapture ()
{
    // Nothing to do
}


wxEvtHandler * CRVtkCapture::CreateEvtHandler () const
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
    return wxXmlResource::Get ()->LoadPanel (m_dialog, "VtkCapturePanel");
}

} // End namespace swTst
