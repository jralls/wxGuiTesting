///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRNotebookPageChangeEvent.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRNotebookPageChangeEvent.h"
#endif

#include "swCRNotebookPageChangeEvent.h"

#include "wx/notebook.h"

#include "swCRWindowHierarchyHandler.h"
#include "swCRCppEmitter.h"

namespace swTst {


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
    swTst::WxGuiTestEventSimulationHelper::SelectNotebookPage (notebook,
            notebookPage);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();

    wxString notebookWdwVarName = emitter->AddContainerLookupCode (
            m_containerName, wxString::Format ("notebook '%s'", m_notebookName.c_str ()),
            "Wdw");

    wxString notebookVarName = emitter->MakeVarName (m_notebookName);

    wxString str;
    str.Clear ();
    str << "wxNotebook *" << notebookVarName << " = wxDynamicCast (" <<
            notebookWdwVarName << ", wxNotebook);";
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Converting window for notebook '" <<
            m_notebookName << "' failed\", " << notebookVarName << " != NULL);";
    emitter->AddCode (str);
    
    wxString pageTextVarName = emitter->MakeVarName (notebookVarName,
            "PageText");

    str.Clear ();
    str << "const wxString " << pageTextVarName << " (_(\"" << m_notebookPageText << "\"));";
    emitter->AddCode (str);

    wxString pageVarName = emitter->MakeVarName (notebookVarName, "Page");

    str.Clear ();
    str << "int " << pageVarName << " = 0;";
    emitter->AddCode (str);
    
    str.Clear ();
    str << "while ((" << pageVarName << " < " << notebookVarName <<
            "->GetPageCount ()) && (" << notebookVarName << "->GetPageText (" <<
            pageVarName << ") != " << pageTextVarName << ")) {\n";
    emitter->AddCode (str);

    str.Clear ();
    str << emitter->GetTab () << pageVarName << "++;";
    emitter->AddCode (str);

    str.Clear ();
    str << "}";
    emitter->AddCode (str);

    str.Clear ();
    str << "CPPUNIT_ASSERT_MESSAGE (\"Page of notebook '" << m_notebookName <<
            "' not found\", " << pageVarName << " < " << notebookVarName <<
            "->GetPageCount ());";
    emitter->AddCode (str);

    str.Clear ();
    str << "swTst::WxGuiTestEventSimulationHelper::SelectNotebookPage (" <<
            notebookVarName << ", " << pageVarName << ");";
    emitter->AddCode (str);
    
    str.Clear ();
    str << "swTst::WxGuiTestHelper::FlushEventQueue ();\n";
    emitter->AddCode (str);
}

} // End namespace swTst

