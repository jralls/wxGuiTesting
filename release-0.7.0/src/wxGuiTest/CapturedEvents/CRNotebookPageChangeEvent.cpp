///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CapturedEvents/CRNotebookPageChangeEvent.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "CRNotebookPageChangeEvent.h"
#endif

#include "CRNotebookPageChangeEvent.h"

#include <wx/notebook.h>

#include <wxGuiTest/CRWindowHierarchyHandler.h>
#include <wxGuiTest/CRCppEmitter.h>

namespace wxTst {


CRNotebookPageChangeEvent::CRNotebookPageChangeEvent (wxEvent *event) :
CRCapturedEvent (event)
{
    m_isFirstAndPending = true;
}


CRNotebookPageChangeEvent::~CRNotebookPageChangeEvent ()
{
    // Nothing to do
}


bool CRNotebookPageChangeEvent::IsPending () const
{
    return m_isFirstAndPending;
}


void CRNotebookPageChangeEvent::Process (CRCapturedEvent **pendingEvt)
{
    // If pending event is another notebook event on the same (!) control,
    // then destroy it to prevent undesirable code emitting:
    if (*pendingEvt != NULL) {

        CRNotebookPageChangeEvent *pendingNbPgChgEvt =
                dynamic_cast< CRNotebookPageChangeEvent * >(*pendingEvt);
        if (pendingNbPgChgEvt != NULL) {

            if (m_event->GetEventObject () ==
                    pendingNbPgChgEvt->GetEvent ()->GetEventObject ()) {

                m_isFirstAndPending = false;
                delete *pendingEvt;
                *pendingEvt = NULL;
            }
        }
    }

    wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (), wxWindow);
    wxASSERT (wdwEvtObject != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);

    m_notebookName = wdwEvtObject->GetName ();
    m_containerName = hierarchy->FindContainerName (wdwEvtObject);
    wxASSERT (!m_containerName.IsEmpty ());
    wxASSERT (m_notebookName == m_containerName);

    wxASSERT (m_event->IsCommandEvent ());
    wxNotebookEvent *nbEvt = wxDynamicCast (m_event, wxNotebookEvent);
    wxASSERT (nbEvt != NULL);
    int page = nbEvt->GetSelection ();
    wxNotebook *notebook = wxDynamicCast (wdwEvtObject, wxNotebook);
    wxASSERT (notebook != NULL);
    m_notebookPageText = notebook->GetPageText (page);
}


void CRNotebookPageChangeEvent::EmitCpp ()
{
    // Expected emitting (XRC):
    /*
    wxWindow *notebookWdw = wxWindow::FindWindowByName ("Notebook");
    CPPUNIT_ASSERT_MESSAGE ("Container window for notebook 'Notebook' not \
            found", notebookWdw != NULL);
    wxNotebook *notebook = wxDynamicCast (notebookWdw, wxNotebook);
    CPPUNIT_ASSERT_MESSAGE ("Converting window for notebook 'Notebook' failed",
            notebook != NULL);
    wxString notebookPageText (_("Page2"));
    int notebookPage = 0;
    while ((notebookPage < notebook->GetPageCount ()) && (notebook->GetPageText
            (notebookPage) != notebookPageText)) {

        notebookPage++;
    }
    CPPUNIT_ASSERT_MESSAGE ("Page of notebook 'Notebook' not found",
            notebookPage < notebook->GetPageCount ());
    wxTst::EventSimulationHelper::SelectNotebookPage (notebook,
            notebookPage);
    wxTst::WxGuiTestHelper::FlushEventQueue ();
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString notebookWdwVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format (_T("notebook '%s'"), m_notebookName.c_str ()),
            _T("Wdw"));

    wxString notebookVarName = emitter->MakeVarName (m_notebookName);

    wxString str;
    str.Clear ();
    str << _T("wxNotebook *") << notebookVarName << _T(" = wxDynamicCast (") <<
            notebookWdwVarName << _T(", wxNotebook);");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Converting window for notebook '") <<
            m_notebookName << _T("' failed\", ") << notebookVarName <<
            _T(" != NULL);");
    emitter->AddCode (str);
    
    wxString pageTextVarName = emitter->MakeVarName (notebookVarName,
            _T("PageText"));

    str.Clear ();
    str << _T("const wxString ") << pageTextVarName << _T(" (_(\"") << 
            m_notebookPageText << _T("\"));");
    emitter->AddCode (str);

    wxString pageVarName = emitter->MakeVarName (notebookVarName, _T("Page"));

    str.Clear ();
    str << _T("int ") << pageVarName << _T(" = 0;");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("while ((") << pageVarName << _T(" < ") << notebookVarName <<
            _T("->GetPageCount ()) && (") << notebookVarName << 
            _T("->GetPageText (") << pageVarName << _T(") != ") << pageTextVarName <<
            _T(")) {\n");
    emitter->AddCode (str);

    str.Clear ();
    str << emitter->GetTab () << pageVarName << _T("++;");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("}");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("CPPUNIT_ASSERT_MESSAGE (\"Page of notebook '") << m_notebookName <<
            _T("' not found\", ") << pageVarName << _T(" < ") << notebookVarName <<
            _T("->GetPageCount ());");
    emitter->AddCode (str);

    str.Clear ();
    str << _T("wxTst::EventSimulationHelper::SelectNotebookPage (") <<
            notebookVarName << _T(", ") << pageVarName << _T(");");
    emitter->AddCode (str);
    
    str.Clear ();
    str << _T("wxTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}

} // End namespace wxTst

