///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swWxGuiTestTempInteractive.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWWXGUITESTTEMPINTERACTIVE_H
#define SWWXGUITESTTEMPINTERACTIVE_H

#ifdef __GNUG__
    #pragma interface "swWxGuiTestTempInteractive.h"
#endif

#include <wxGuiTest/Common.h>

class wxDialog;

namespace swTst {


/*! \class WxGuiTestTempInteractive
    \brief Make the wxWidgets GUI test temporarily interactive.

    In contrast to WxGuiTestHelper::BreakTestToShowCurrentGui() interactivity
    with the current GUI is possible, but it has to be kept in mind that this
    may lead to side effects with the subsequent continuation of test case code!

    For the sake of convenience the test can be made interactive several times,
    e.g.:
        // Create some GUI ...
        WxGuiTestTempInteractive interactive;
        interactive.ShowCurrentGui ();
        // Manipulate created GUI and inspect result ...
        interactive.ShowCurrentGui ();    
*/
class WxGuiTestTempInteractive
{
public:
    /*! \fn WxGuiTestTempInteractive ()
        \brief Constructor
    */
    WxGuiTestTempInteractive () {}


    /*! \fn virtual ~WxGuiTestTempInteractive ()
        \brief Destructor

        Pop + delete event handler and destroy used dialog.
    */
    virtual ~WxGuiTestTempInteractive () {}


    /*! \file swWxGuiTestTempInteractive.h
        \brief Providing easy to use macro for temporary interactivity.
    
        Doxygen documentation only needed for #define TEMP_INTERACTIVE_GUI_TEST.
    */
    /*! \def TEMP_INTERACTIVE_GUI_TEST
        \brief Macro allowing easy temporary test interactivity with precise
        file and line number output.
        
	WARNING! This macro can be used only once in a scope because it
	declares the interactive variable.
    */
    #define TEMP_INTERACTIVE_GUI_TEST                                         \
    {                                                                         \
        swTst::WxGuiTestTempInteractive interactive;                          \
        interactive.ShowCurrentGui (_T(__FILE__), __LINE__);		\
    };


    /*! \fn virtual void ShowCurrentGui (const char *file, int line)
        \brief Show current GUI and query user for continuation, showing file and line info.

        \param file name of affected GUI test case file
        \param line line number of affected GUI test case file
    */
    virtual void ShowCurrentGui (const wxString& file = _T(""), int line = -1);

protected:
    /*! \fn virtual void CreateDialog ()
        \brief Create the simplest dialog ever.
    */
    virtual wxDialog* CreateDialog (const wxString& file, int line);

private:

};

} // End namespace swTst

#endif // SWWXGUITESTTEMPINTERACTIVE_H

