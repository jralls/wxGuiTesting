///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/swPseudoApp.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWPSEUDOAPP_H
#define SWPSEUDOAPP_H

#ifdef __GNUG__
    #pragma interface "swPseudoApp.h"
#endif

#include <wxGuiTest/Common.h>

#include <wxGuiTest/swApp.h>

namespace sw {


/*! \class PseudoApp
    \brief "Console application" allowing unit testing.

    Some code, for instance progress observers or all kind of display methods,
    depends on an actual application to be instantiated. Typically, this code
    starts with App::GetInstance ()->... Thus, unit tests of classes using
    these application dependent code bits require a pseudo application.

    Right now all outputs are done to the console or std::cout, but maybe it is
    more flexible to use debug logging instead? Output can be switched on/off
    by means of isVerbose.

    Debug logging is minimally supported in the shape of the "PseudoApp"
    trace mask.
*/
class PseudoApp : public App
{
public:
    /*! \fn PseudoApp (bool isVerbose = true)
        \brief Constructor

        \param isVerbose if false, there is no output to console
    */
    PseudoApp (bool isVerbose = true);


    /*! \fn virtual ~PseudoApp ()
        \brief Destructor
    */
    virtual ~PseudoApp ();


    /*! \fn static void SetPseudoAppInstance ()
        \brief Helper method facilitating the usage of psuedo applications.

        If doing unit testing it may be the case that there is already an
        application instance, thus it is necessary to call App::Destroy()
        method before calling this method.
    */
    static void SetPseudoAppInstance ();


	/*! \fn virtual bool DisplayWarning (const wxString &caption, const wxString &message, bool canBypass)
		\brief Method to use to display a warning to the user.

		\param caption caption of message dialog
		\param message warning message to display
		\param canBypass must be TRUE if the user can have the possibility to bypass this warning
		\return true, if user has clicked on OK
	*/
	virtual bool DisplayWarning (const wxString &caption, const wxString &message, bool canBypass);


	/*! \fn virtual void DisplayDocInfo (const wxString &docInfo)
		\brief Method to use to display document information.

		Note that this method does not know the format to display the information.
		It merely displays the wxString at the right place.

		\param docInfo String to be displayed.
	*/
	virtual void DisplayDocInfo (const wxString &docInfo);


	/*! \fn virtual void DisplayHint (const wxString &hint)
		\brief Method to use to display hints such as tooltips.

		Note that this method does not know the format to display the information.
		It merely displays the wxString at the right place.

		\param hint String to be displayed.
	*/
	virtual void DisplayHint (const wxString &hint);


	/*! \fn virtual void StartProgressInfo (unsigned int maxProgress, const wxString &progressInfo)
		\brief Method to use to start displaying progress info.

		\param maxProgress Maximum of the progress value to be displayed.
		\param progressInfo Information about the operation being monitored.
	*/
	virtual void StartProgressInfo (unsigned int maxProgress, const wxString &progressInfo);


	/*! \fn virtual void DisplayProgressInfo (unsigned int currentProgress, const wxString &progressInfo)
		\brief Method to use to display progress info (GuiMethods::StartProgressInfo() should be called first).

		\param currentProgress Current value of the progress information to be displayed.
		\param progressInfo Information about the operation being monitored.
	*/
	virtual void DisplayProgressInfo (unsigned int currentProgress, const wxString &progressInfo);


	/*! \fn void EndProgressInfo (const wxString &progressInfo, bool realEnd = false)
		\brief Method to use to stop displaying progress info (GuiMethods::StartProgressInfo() should have been called before).

		\param progressInfo Information about the operation being monitored.
		\param realEnd To specify when this is really the last call to EndProgressInfo.
	*/
	virtual void EndProgressInfo (const wxString &progressInfo, bool realEnd = false);


	/*! \fn virtual void DisplayAbout ()
		\brief Method to display the world famous about dialog.
	*/
	virtual void DisplayAbout ();


	/*! \fn virtual bool IsVerbose () const
		\brief Get verboseness of application output.

        \return true, if verbose
	*/
    virtual bool IsVerbose () const;


	/*! \fn virtual void SetIsVerbose (bool isVerbose)
		\brief Set verboseness of application output.

        \param isVerbose verboseness of application output
	*/
    virtual void SetIsVerbose (bool isVerbose);

protected:
	/*! \fn virtual void Write (const wxString &str) const
		\brief Write string to "standard" output (e.g. console or debug log).

        \param str string to write
	*/
    virtual void Write (const wxString &str) const;


	/*! \fn virtual void WriteLn (const wxString &str) const
		\brief Write string followed with line break to "standard" output.

        \param str string to write
	*/
    virtual void WriteLn (const wxString &str) const;

private:
    bool m_isVerbose;

};

} // End namespace sw

#endif // SWPSEUDOAPP_H

