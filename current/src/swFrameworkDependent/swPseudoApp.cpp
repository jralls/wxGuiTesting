///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/swPseudoApp.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swPseudoApp.h"
#endif

#include <wxGuiTest/swPseudoApp.h>

#include <iostream>

namespace sw {


PseudoApp::PseudoApp (bool isVerbose)
{
    m_isVerbose = isVerbose;
}


PseudoApp::~PseudoApp ()
{
}


void PseudoApp::SetPseudoAppInstance ()
{
    App * app = App::GetInstance ();
    if (app != NULL) {

        if (dynamic_cast< PseudoApp * >(app)) {

            ::wxLogTrace (_T("PseudoApp"), _T("void PseudoApp::SetPseudoAppInstance (): Instance already set, type is PseudoApp"));
            return;

        } else {

            // Should never be necessary:
            ::wxLogTrace (_T("PseudoApp"), _T("void PseudoApp::SetPseudoAppInstance (): Instance already set, type is NOT PseudoApp"));
            App::Nullify ();
            wxFAIL_MSG (_T("Instance already set, type is NOT PseudoApp"));
        }
    }

    app = new PseudoApp ();

    // Initialise wxWidgets application - necessary for global objects like
    // wxTheColourDatabase:
    int argc = 0;
    wxChar **argv = NULL;
    app->Initialize (argc, argv);
}


bool PseudoApp::DisplayWarning (const wxString &caption,
        const wxString &message, bool canBypass)
{
    WriteLn (_T("[DisplayWarning] ") + caption + _T(":"));
    WriteLn (wxString (_T("    ")) + message);

    if (canBypass) {

        std::cout << "y/n?";
        char c;
        std::cin >> c;
        return (c == 'y');
    }
    return false;
}


void PseudoApp::DisplayDocInfo (const wxString &docInfo)
{
    WriteLn (_("[DisplayDocInfo] ") + docInfo);
}


void PseudoApp::DisplayHint (const wxString &hint)
{
    WriteLn (_("[DisplayHint] ") + hint);
}


void PseudoApp::StartProgressInfo (unsigned int maxProgress,
        const wxString &progressInfo)
{
    DisplayHint (progressInfo + wxString::Format (_T(" (maxProgress: %d)"),
            maxProgress));
}


void PseudoApp::DisplayProgressInfo (unsigned int currentProgress,
        const wxString &progressInfo)
{
    DisplayHint (progressInfo + wxString::Format (_T(" (progress: %d)"),
            currentProgress));
}


void PseudoApp::EndProgressInfo (const wxString &progressInfo, bool realEnd)
{
    DisplayHint (progressInfo + wxString::Format (_T(" (realEnd: %d)"),
            realEnd));
}


void PseudoApp::DisplayAbout ()
{
    WriteLn (_("[DisplayAbout]"));
}


bool PseudoApp::IsVerbose () const
{
    return m_isVerbose;
}


void PseudoApp::SetIsVerbose (bool isVerbose)
{
    m_isVerbose = isVerbose;
}


void PseudoApp::Write (const wxString &str) const
{
    std::cout << str.c_str ();
}


void PseudoApp::WriteLn (const wxString &str) const
{
    Write (str + _T('\n'));
}

} // End namespace sw

