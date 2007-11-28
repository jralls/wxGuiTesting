///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/swPseudoApp.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swPseudoApp.h"
#endif

#include "swPseudoApp.h"

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

            ::wxLogTrace ("PseudoApp", "void PseudoApp::SetPseudoAppInstance (): Instance already set, type is PseudoApp");
            return;

        } else {

            // Should never be necessary:
            ::wxLogTrace ("PseudoApp", "void PseudoApp::SetPseudoAppInstance (): Instance already set, type is NOT PseudoApp");
            App::Nullify ();
            wxFAIL_MSG ("Instance already set, type is NOT PseudoApp");
        }
    }

    app = new PseudoApp ();

    // Initialise wxWidgets application - necessary for global objects like
    // wxTheColourDatabase:
    int argc = 0;
    char **argv = NULL;
    app->Initialize (argc, argv);
}


bool PseudoApp::DisplayWarning (const wxString &caption,
        const wxString &message, bool canBypass)
{
    WriteLn (_("[DisplayWarning] ") + caption + ":");
    WriteLn (wxString ("    ") + message);

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
    DisplayHint (progressInfo + wxString::Format (" (maxProgress: %d)",
            maxProgress));
}


void PseudoApp::DisplayProgressInfo (unsigned int currentProgress,
        const wxString &progressInfo)
{
    DisplayHint (progressInfo + wxString::Format (" (progress: %d)",
            currentProgress));
}


void PseudoApp::EndProgressInfo (const wxString &progressInfo, bool realEnd)
{
    DisplayHint (progressInfo + wxString::Format (" (realEnd: %d)",
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
    Write (str + "\n");
}

} // End namespace sw

