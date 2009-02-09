///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/WxGuiTestHelper.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2009
// Modifications Copyright: (c) 2009 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////
//! \file
#ifndef WXGUITESTHELPER_H
#define WXGUITESTHELPER_H

#ifdef __GNUG__
    #pragma interface "WxGuiTestHelper.h"
#endif

#include <wxGuiTest/Common.h>

#include <map>


/*! \def IMPLEMENT_APP(appname)
If the special symbol _USE_WX_APP_GUI_TESTING is defined in the sources
CMakeLists.txt, for instance by:
  ADD_DEFINITIONS (-D_USE_WX_APP_GUI_TESTING)
the sources application won't be recognised as such, but can be used for
wxAppGuiTesting:
*/
#ifdef USE_WXGUITESTING
    #ifdef IMPLEMENT_APP
        #undef IMPLEMENT_APP
    #endif
    #define IMPLEMENT_APP(appname)
#endif


namespace wxTst {

class WarningAsserterInterface;


/*! \class WxGuiTestHelper
    \brief Provides some convenience or helper methods for wxGui test cases.
    
    Mainly to (a) configure the behaviour of WxGuiTestApp class (e.g. showing
    modal dialogs non-modal), and (b) facilitate the usage of some common
    features (e.g. flushing the event queue, or making the test temporary
    interactive for manual visual checks during GUI test implementation).

    GUI events are run by pushing them onto a wxEventHandler's event
    queue using wxPostEvent and, once the events for a test have been
    set up in sequence, calling (via wxTestApp::MainLoop, which makes
    sure that the AUT can't start a real event loop with calls from
    functions like wxDialog::ShowModal) wxProcessEvents. When
    s_interactive is true, wxTestApp::MainLoop will call
    wxApp::MainLoop instead, allowing the AUT to respond to regular
    events. Note that functions which launch a platform event loop
    (e.g., wxMessageBox) evade this system, so test dummies are needed
    for those functions.

    The flag s_isGuiLessUnitTest (and getter/setter method) can be used to
    prevent any showing of dialogs -- if the actual call to someDialog->Show()
    is diverted to ::Show() method of this class! Thus, it only works for own
    code, and wxMessageBox as well as wxWidgets standard dialogs are of course
    an exception.

    Finally, s_showModalDialogsNonModal (and getter/setter method) can be used
    to show modal dialogs non-modal. This is critical for unit tests, as modal
    dialogs have their own message processing loop, blocking for some user
    input.

    "Temporary interactive tests" are provided in two different shapes:
        - if inspection is enough and no interaction is desired a standard
        wxMessageBox as used by BreakTestToShowCurrentGui() is enough.
        - if interaction is necessary, use TempInteractive though.
	This temporary interactivity in (and breaking of) tests can be disabled
	completely for real test runs by means of s_disableTestInteractivity flag
	and the corresponding getter/setter method.
    Likewise failing assertions are popping-up a message box by default, thus
    for real automation of test running the flag s_popupWarningForFailingAssert
    should be set to false via the corresponding setter method.

    Of course, some additonal more complex functionality requires its own
    classes and is therefore not accessible via this class, e.g.:
        - TimedDialogEnder to automatically close message boxes (or
            in general modal dialogs)
        - "Temporary interactive tests" by means of TempInteractive

    Finally, the occurence of unexpected or unprovoked warnings via
    App::DisplayWarning() method calls can be detected based on calling
    WxGuiTestHelper::IsProvokedWarning() at the beginning of the
    aforementioned method in the application under test (AUT): such a warning
    means the test case has failed.
*/
class WxGuiTestHelper
{
public:
    /*! \fn WxGuiTestHelper ()
        \brief Constructor
    */
    WxGuiTestHelper ();


    /*! \fn virtual ~WxGuiTestHelper ()
        \brief Destructor
    */
    virtual ~WxGuiTestHelper ();


    /*! \fn static int FlushEventQueue ()
        \brief Flushes event queue in wxWidgets main loop.

        As this functionality requires changing some of the flags, they will be
        stored temporarily and set back at the end to their initial values.

        \return return value of run main loop
    */
    static int FlushEventQueue ();


    /*! \fn static int Show (wxWindow *wdw, bool show, bool isModal)
        \brief Show frames, dialogs conditionally using global s_isGuiLessUnitTest flag.

        \param wdw dialog or frame pointer
        \param show true, if wdw should be shown (taking s_isGuiLessUnitTest into accout)
        \param isModal for dialogs intended to be shown in modal style (taking s_showModalDialogsNonModal into account)
        \return -1 default, otherwise return values of standard Show()/ShowModal() methods
    */
    static int Show (wxWindow *wdw, bool show, bool isModal);


    /*! \fn static int Show (wxWindow *wdw, bool show, bool isModal, bool isGuiLessUnitTest)
        \brief Show frames, dialogs conditionally using isGuiLessUnitTest flag.

        \param wdw dialog or frame handle
        \param show true, if wdw should be shown (taking isGuiLessUnitTest into accout)
        \param isModal for dialogs intended to be shown in modal style (taking s_showModalDialogsNonModal into account)
        \param isGuiLessUnitTest "overwriting" global s_isGuiLessUnitTest flag
        \return -1 default, otherwise return values of standard Show()/ShowModal() methods
    */
    static int Show (wxWindow *wdw, bool show, bool isModal,
            bool isGuiLessUnitTest);


    /*! \fn static bool PopupMenu (wxWindow *wdw, wxMenu *menu, const wxPoint &pos, const wxString &cacheMapKey)
        \brief Pop up menus conditionally using global s_isGuiLessUnitTest flag.

        \param wdw parent component to pop up menu
        \param menu menu to pop up
        \param pos position of menu
        \param cacheMapKey key under which the pop-up menu is cached for subsequent finding in test code
        \return wxWindow::PopupMenu() return value if called, or false otherwise
    */
    static bool PopupMenu (wxWindow *wdw, wxMenu *menu, const wxPoint &pos,
            const wxString &cacheMapKey);


    /*! \fn static bool PopupMenu (wxWindow *wdw, wxMenu *menu, const wxPoint &pos, const wxString &cacheMapKey, bool isGuiLessUnitTest)
        \brief Pop up menus conditionally using global s_isGuiLessUnitTest flag.

        \param wdw parent component to pop up menu
        \param menu menu to pop up
        \param pos position of menu
        \param cacheMapKey key under which the pop-up menu is cached for subsequent finding in test code
        \param isGuiLessUnitTest "overwriting" global s_isGuiLessUnitTest flag
        \return wxWindow::PopupMenu() return value if called, or false otherwise
    */
    static bool PopupMenu (wxWindow *wdw, wxMenu *menu, const wxPoint &pos,
            const wxString &cacheMapKey, bool isGuiLessUnitTest);


    /*! \fn static void BreakTestToShowCurrentGui ()
        \brief Break test and show current GUI and query user for continuation.

        Using a standard wxMessageBox the user can inspect the current GUI
        without interaction. Testing is continued when confirming the popup
        message.
        In fact, only windows/dialogs/frames really "shown" (cf.
        s_isGuiLessUnitTest flag) can be shown.
    */
    static void BreakTestToShowCurrentGui ();

    /*! \fn static void SetIsGuiLessUnitTestFlag (bool isGuiLess)
        \brief Set flag indicating if no GUI should be shown at all.

        This is "only" used in ::Show() method which should be employed for all
        own code with the need for showing a dialog.

        \param isGuiLess if true, no GUI should be shown at all
    */
    static void SetIsGuiLessUnitTestFlag (bool isGuiLess);

    
    /*! \fn static bool IsGuiLessUnitTestFlag ()
        \brief Get flag indicating if no GUI should be shown at all.

        \return true, if no GUI should be shown at all
    */
    static bool IsGuiLessUnitTestFlag ();


    /*! \fn static void SetShowModalDialogsNonModalFlag (bool showNonModal)
        \brief Set flag indicating modal dialogs should be shown non-modal.

        Again, this is "only" used in ::Show() method which should be employed
        for all own code with the need for showing a dialog.

        \param showNonModal if true, modal dialogs are shown non-modal
    */
    static void SetShowModalDialogsNonModalFlag (bool showNonModal);

    
    /*! \fn static bool GetShowModalDialogsNonModalFlag ()
        \brief Get flag indicating modal dialogs should be shown non-modal.

        Again, this is "only" used in ::Show() method which should be employed
        for all own code with the need for showing a dialog.

        \return true, if modal dialogs are shown non-modal
    */
    static bool GetShowModalDialogsNonModalFlag ();


    /*! \fn static void SetShowPopupMenusFlag (bool showPopupMenus)
        \brief Set flag indicating popup menu showing.

        This is "only" used in PopupMenu() method which should be employed
        for all own code with the need of popping up a menu.

        \param showPopupMenus if true, pop-up menus are actually shown
    */
    static void SetShowPopupMenusFlag (bool showPopupMenus);

    
    /*! \fn static bool GetShowPopupMenusFlag ()
        \brief Get flag indicating popup menu showing.

        This is "only" used in PopupMenu() method which should be employed
        for all own code with the need of popping up a menu.

        \return true, if pop-up menus are actually shown
    */

    static bool GetShowPopupMenusFlag ();

/// @fn static void SetInteractive
/// @brief Will the AUT accept and process user interaction events?
/// 
/// Will only allow interaction if s_disableTestInteractivity is false
/// @param interactive true if the AUT is to be interactive. 
///
    static void SetInteractive(bool interactive);

/// @fn static bool GetInteractive
/// @brief Returns the current value of s_interactive.
///
/// @return true if the AUT is to accept user interaction.
///
    static bool GetInteractive();
    
    /*! \fn static void SetDisabletestinteracticity (bool disable)
        \brief Set flag indicating disable status of interactive tests.

        Is used by all methods allowing to either break or temorary making a
		test interactive.

        \param enable if true, no breaking of, or temporary interactivity in tests is allowed
    */
	static void SetDisableTestInteractivity (bool disable);


    /*! \fn static bool GetDisabletestinteracticity ()
        \brief Get flag indicating disable status of interactive tests.

        \return true, if no breaking of, or temporary interactivity in tests is allowed
    */
	static bool GetDisableTestInteractivity ();


    /*! \fn static void SetPopupWarningForFailingAssert (bool popup)
        \brief Set flag indicating if failing assertions should pop-up the
        default warning dialog allowing to break debugging.

        Is only used when testing in debug mode.
        For real test automation the associated flag
        s_popupWarningForFailingAssert should be set to false; as well as
        s_disableTestInteractivity should be set to true.

        \param popup if true, failing assertions pop-up the warning message box
    */
	static void SetPopupWarningForFailingAssert (bool popup);


    /*! \fn static bool GetPopupWarningForFailingAssert ()
        \brief Get flag indicating if failing assertions should pop-up the
        default warning dialog allowing to break debugging.

        \return true, if failing assertions pop-up the warning message box
    */
	static bool GetPopupWarningForFailingAssert ();


    /*! \fn static wxMenu *FindPopupMenu (const wxString &key)
        \brief Look for with key specified pop-up menu in cached pop-up menu map.

        \param key string specifying pop-up menu (used during PopupMenu() method)
        \return pop-up menu cached under specified key, or NULL
    */
    static wxMenu *FindPopupMenu (const wxString &key);


    /*! \fn static wxString FindPopupMenuKey (wxMenu *menu)
        \brief Look for key of given pop-up menu in cached pop-up menu map.

        Only used for capturing & replay!

        \param menu pop-up menu to look up map key
        \return key string of given pop-up menu (used during PopupMenu() method)
    */
    static wxString FindPopupMenuKey (wxMenu *menu);


    /*! \fn static wxWindow *FindPopupMenuEvtHandlerWdw (const wxString &key)
        \brief Look for with key specified pop-up menu event handler window in
        cached pop-up menu map.

        Only used for capturing & replay!

        \param key string specifying pop-up menu event handler window (used
            during PopupMenu() method)
        \return pop-up menu event handler window, or NULL
    */
    static wxWindow *FindPopupMenuEvtHandlerWdw (const wxString &key);


    /*! \fn static bool IsProvokedWarning (const wxString &caption, const wxString &message)
        \brief In testing mode check if this warning is a provoked one to test
        for some non-functional case, or some unfulfilled condition leading to
        a warning.

        Allow detection of unexpected/unprovoked warnings which means a failing
        test case. Internally ProvokedWarningRegistry is used.

        \param caption caption of occured warning
        \param message message of occured warning
        \return true, if warning is a provoked one (i.e. registered)
    */
    static bool IsProvokedWarning (const wxString &caption, const wxString &message);


    /*! \fn static void SetCheckForProvokedWarnings (bool check)
        \brief Set flag indicating check for unexpected warnings.

        \param check if true, means unexpected warnings will lead to test case
            failure in CheckForProvokedWarning() method
    */
	static void SetCheckForProvokedWarnings (bool check);


    /*! \fn static bool GetCheckForProvokedWarnings ()
        \brief Get flag indicating check for unexpected warnings.

        \return true, if unexpected warnings will lead to test case failure in
            CheckForProvokedWarning() method
    */
	static bool GetCheckForProvokedWarnings ();


    /*! \fn static void SetWarningAsserter (WarningAsserterInterface *warningAsserter)
        \brief Set warning asserter to be used in testing mode.

        \param warningAsserter asserter to be used in testing mode
    */
    static void SetWarningAsserter (WarningAsserterInterface *warningAsserter);


    static void AddTestFailure (const wxString &file, const int line,
            const wxString &shortDescription, const wxString &message);

private:
    static bool s_isGuiLessUnitTest;

    static bool s_showModalDialogsNonModal;
    static bool s_showPopupMenus;

    static bool s_interactive;
    static bool s_disableTestInteractivity;

    static bool s_popupWarningForFailingAssert;

    typedef std::pair< wxMenu *, wxWindow * > MenuWdwPair;
    typedef std::map< wxString, MenuWdwPair > PopupMenuMap;
    static PopupMenuMap s_popupMenuMap;

    static bool s_checkForProvokedWarnings;

    static WarningAsserterInterface *s_warningAsserter;

    // For storing test case failures due to failing assertions and unexpected
    // warnings:
    static wxString s_fileOfFirstTestFailure;
    static int s_lineNmbOfFirstTestFailure;
    static wxString s_shortDescriptionOfFirstTestFailure;
    static wxString s_accTestFailures;
};

} // End namespace wxTst

#endif // WXGUITESTHELPER_H

