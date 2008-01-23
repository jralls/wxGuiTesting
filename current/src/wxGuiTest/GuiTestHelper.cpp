///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/GuiTestHelper.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "GuiTestHelper.h"
#endif

#include <wxGuiTest/GuiTestHelper.h>

#include <wxGuiTest/WarningAsserterInterface.h>
#include <wxGuiTest/ProvokedWarningRegistry.h>

// #include <FrameFactory/swDefaultDialog.h>
// #include <FrameFactory/swFrameFactory.h>

namespace wxTst {

// Set default settings for normal application logic:
// "Single stepping" through unit test case code:
bool GuiTestHelper::s_useExitMainLoopOnIdle = true;
bool GuiTestHelper::s_doExitMainLoopOnIdle = true;
// Allow manual visual checking of GUI (cf. temporary interactive test):
bool GuiTestHelper::s_isGuiLessUnitTest = false;
// Unit testing will be blocked, but by default the app should act normaly:
bool GuiTestHelper::s_showModalDialogsNonModal = false;
bool GuiTestHelper::s_showPopupMenus = true;
// By default enable test interactivity:
bool GuiTestHelper::s_disableTestInteractivity = false;
// By default pop-up warning message box on failing assertions:
bool GuiTestHelper::s_popupWarningForFailingAssert = true;
// By default don't check the occurence of unexpected warnings:
bool GuiTestHelper::s_checkForProvokedWarnings = false;

WarningAsserterInterface *GuiTestHelper::s_warningAsserter = NULL;

GuiTestHelper::PopupMenuMap GuiTestHelper::s_popupMenuMap;

wxString GuiTestHelper::s_fileOfFirstTestFailure;
int GuiTestHelper::s_lineNmbOfFirstTestFailure = -1;
wxString GuiTestHelper::s_shortDescriptionOfFirstTestFailure;
wxString GuiTestHelper::s_accTestFailures;


GuiTestHelper::GuiTestHelper ()
{
    // Nothing to do
}


GuiTestHelper::~GuiTestHelper ()
{
    s_popupMenuMap.clear ();
    if (s_warningAsserter != NULL) {

        delete s_warningAsserter;
        s_warningAsserter = NULL;
    }
}


int GuiTestHelper::FlushEventQueue ()
{
    // Reset test case failure occurence store:
    s_fileOfFirstTestFailure.Clear ();
    s_lineNmbOfFirstTestFailure = -1;
    s_accTestFailures.Clear ();

    bool oldUseExitMainLoopOnIdle = s_useExitMainLoopOnIdle;
    bool oldDoExitMainLoopOnIdle = s_doExitMainLoopOnIdle;
    int retCode;

    s_useExitMainLoopOnIdle = true;
    s_doExitMainLoopOnIdle = true;

	// Check if really all events under GTK do not send an explicit additional idle event (instead of being lazy):
#ifdef __WXGTK__
    wxIdleEvent *idleEvt = new wxIdleEvent ();
    ::wxPostEvent (wxTheApp->GetTopWindow ()->GetEventHandler (), *idleEvt);
#endif

    retCode = wxTheApp->MainLoop ();

    s_useExitMainLoopOnIdle = oldUseExitMainLoopOnIdle;
    s_doExitMainLoopOnIdle = oldDoExitMainLoopOnIdle;

    // If a failure has occured, throw exception:
    if (!s_accTestFailures.IsEmpty ()) {

        wxASSERT (s_warningAsserter != NULL);
        s_warningAsserter->FailAssert (s_fileOfFirstTestFailure,
                s_lineNmbOfFirstTestFailure,
                s_shortDescriptionOfFirstTestFailure, s_accTestFailures);
    }

    return retCode;
}


int GuiTestHelper::Show (wxWindow *wdw, bool show, bool isModal)
{
    return GuiTestHelper::Show (wdw, show, isModal,
            GuiTestHelper::s_isGuiLessUnitTest);
}


int GuiTestHelper::Show (wxWindow *wdw, bool show, bool isModal,
        bool isGuiLessUnitTest)
{
    wxASSERT (wdw != NULL);

    int ret = -1;

    if (isModal) {

        // Only dialogs can be shown modal:
        wxDialog *dlg = wxDynamicCast (wdw, wxDialog);
        wxASSERT (dlg != NULL);

        if (isGuiLessUnitTest) {

            // Nothing to do/show.

        } else {

            if (show) {

                if (GuiTestHelper::s_showModalDialogsNonModal) {

                    ret = dlg->Show ();

                } else {

                    ret = dlg->ShowModal ();
                }

            } else {

                if (GuiTestHelper::s_showModalDialogsNonModal) {

                    ret = dlg->Hide ();

                } else {

                    dlg->EndModal (show);
                }
            }
        }

    } else {

        if (!isGuiLessUnitTest) {

            if (show) {

                ret = wdw->Show (show);

            } else {

                ret = wdw->Hide ();
            }
        }
    }

    return ret;
}


bool GuiTestHelper::PopupMenu (wxWindow *wdw, wxMenu *menu,
        const wxPoint &pos, const wxString &cacheMapKey)
{
    return GuiTestHelper::PopupMenu (wdw, menu, pos, cacheMapKey,
            GuiTestHelper::s_isGuiLessUnitTest);
}


bool GuiTestHelper::PopupMenu (wxWindow *wdw, wxMenu *menu,
        const wxPoint &pos, const wxString &cacheMapKey, bool isGuiLessUnitTest)
{
    bool ret = false;

    // Cache wxMenu for subsequent finding in test units:
    GuiTestHelper::s_popupMenuMap[cacheMapKey] = std::make_pair (menu, wdw);

    if (isGuiLessUnitTest) {

        // Do nothing

    } else {

        if (GuiTestHelper::s_showPopupMenus) {

            ret = wdw->PopupMenu (menu, pos);

        } else {

            // Do nothing
        }
    }

    return ret;
}


void GuiTestHelper::BreakTestToShowCurrentGui ()
{
	if (GuiTestHelper::GetDisableTestInteractivity ()) {

		return;
	}

    ::wxMessageBox (_T("Continue unit testing?"),
            _T("wxGui CppUnit Testing Suspended"), wxOK | wxICON_QUESTION);
}


void GuiTestHelper::SetUseExitMainLoopOnIdleFlag (bool use)
{
    s_useExitMainLoopOnIdle = use;
}

    
bool GuiTestHelper::GetUseExitMainLoopOnIdleFlag ()
{
    return s_useExitMainLoopOnIdle;
}


void GuiTestHelper::SetExitMainLoopOnIdleFlag (bool doExit)
{
    s_doExitMainLoopOnIdle = doExit;
}

    
bool GuiTestHelper::GetExitMainLoopOnIdleFlag ()
{
    return s_doExitMainLoopOnIdle;
}


void GuiTestHelper::SetIsGuiLessUnitTestFlag (bool isGuiLess)
{
    s_isGuiLessUnitTest = isGuiLess;
}

    
bool GuiTestHelper::IsGuiLessUnitTestFlag ()
{
    return s_isGuiLessUnitTest;
}


void GuiTestHelper::SetShowModalDialogsNonModalFlag (bool showNonModal)
{
    s_showModalDialogsNonModal = showNonModal;
}


bool GuiTestHelper::GetShowModalDialogsNonModalFlag ()
{
    return s_showModalDialogsNonModal;
}


void GuiTestHelper::SetShowPopupMenusFlag (bool showPopupMenus)
{
    s_showPopupMenus = showPopupMenus;
}


bool GuiTestHelper::GetShowPopupMenusFlag ()
{
    return s_showPopupMenus;
}


void GuiTestHelper::SetDisableTestInteractivity (bool disable)
{
	s_disableTestInteractivity = disable;
}


bool GuiTestHelper::GetDisableTestInteractivity ()
{
	return s_disableTestInteractivity;
}


void GuiTestHelper::SetPopupWarningForFailingAssert (bool popup)
{
    s_popupWarningForFailingAssert = popup;
}


bool GuiTestHelper::GetPopupWarningForFailingAssert ()
{
    return s_popupWarningForFailingAssert;
}


wxMenu *GuiTestHelper::FindPopupMenu (const wxString &key)
{
    PopupMenuMap::const_iterator it;

    it = s_popupMenuMap.find (key);
    return (it != s_popupMenuMap.end () ? (*it).second.first : NULL);
}


wxString GuiTestHelper::FindPopupMenuKey (wxMenu *menu)
{
    bool found = false;
    PopupMenuMap::const_iterator it = s_popupMenuMap.begin ();
    while ((!found) && (it != s_popupMenuMap.end ())) {

        if ((*it).second.first == menu) {

            found = true;

        } else {
        
            it++;
        }
    }
    return (found ? (*it).first : _T(""));
}


wxWindow *GuiTestHelper::FindPopupMenuEvtHandlerWdw (const wxString &key)
{
    PopupMenuMap::const_iterator it;

    it = s_popupMenuMap.find (key);
    return (it != s_popupMenuMap.end () ? (*it).second.second : NULL);
}


bool GuiTestHelper::IsProvokedWarning (const wxString &caption,
        const wxString &message)
{
    bool isProvoked = false;

    if (GuiTestHelper::GetCheckForProvokedWarnings ()) {

        ProvokedWarningRegistry &provWarningRegistry =
                ProvokedWarningRegistry::GetInstance ();
        const ProvokedWarning *warning =
                provWarningRegistry.FindRegisteredWarning (caption, message);
        if ((warning != NULL) && (
                provWarningRegistry.IsRegisteredAndInTime (*warning))) {

            // It is a provoked warning -> label it as detected:
            provWarningRegistry.SetWarningAsDetected (*warning);
            isProvoked = true;

        } else {

            // Unexpected warning -> test case failure:
            wxString failMsg = wxString::Format (
                    _T("Caption \"%s\", message \"%s\" occured"), caption.c_str (),
                    message.c_str ());
            GuiTestHelper::AddTestFailure (_T(""), -1,
                    _T("Unexpected App application warning detected"), failMsg);
            //GuiTestHelper::SetCheckForProvokedWarnings (false);
            wxTheApp->ExitMainLoop ();
        }
    }

    return isProvoked;
}


void GuiTestHelper::SetCheckForProvokedWarnings (bool check)
{
    GuiTestHelper::s_checkForProvokedWarnings = check;
}


bool GuiTestHelper::GetCheckForProvokedWarnings ()
{
    return GuiTestHelper::s_checkForProvokedWarnings;
}


void GuiTestHelper::SetWarningAsserter (
        WarningAsserterInterface *warningAsserter)
{
    // As a convenience we allow resetting the warning asserter with a NULL
    // pointer:
    //wxASSERT (warningAsserter != NULL);
    s_warningAsserter = warningAsserter;
}


void GuiTestHelper::AddTestFailure (const wxString &file, const int line,
        const wxString &shortDescription, const wxString &message)
{
    if (s_accTestFailures.IsEmpty ()) {

        s_fileOfFirstTestFailure = file;
        s_lineNmbOfFirstTestFailure = line;
        s_shortDescriptionOfFirstTestFailure = shortDescription;

    } else {

        s_accTestFailures += _T("\nAND SUBSEQUENTLY:");
        if (!shortDescription.IsEmpty ()) {

            s_accTestFailures += _T("\n");
            s_accTestFailures += shortDescription;
        }
    }
    s_accTestFailures += _T("\n");
    s_accTestFailures += message;
}

} // End namespace wxTst

