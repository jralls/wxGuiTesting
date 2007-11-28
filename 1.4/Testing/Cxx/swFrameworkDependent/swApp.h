///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/swApp.h
// Author:      Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Created:     2002
// Copyright:   (c) 2002 Yann Rouillard, Viet Bui Xuan, Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWAPP_H
#define SWAPP_H

#ifdef __GNUG__
    #pragma interface "swApp.h"
#endif

#include "Common.h"

#include <wx/docview.h>

namespace sw {


/*! \class App
	\brief Application.
*/
class App: public wxApp
{
public:
    /*! \fn static App * GetInstance ()
		\brief Get single instance of application (Singleton pattern).

		\return application instance
	*/
	static App * GetInstance ();


    /*! \fn static void SetInstance (App *app)
		\brief [TEST] Set single instance of application (Singleton pattern).

        Only required for testing!

		\param app application instance to set
	*/
	static void SetInstance (App *app);


    /*! \fn static void Nullify ()
        \brief [TEST] Pseudo destruction of application.

        Only required for testing!

        In fact only sets ms_instance to NULL, thus allowing to instantiate a
        PseudoApp() object.
    */
    static void Nullify ();


	/*! \fn virtual bool DisplayWarning (const wxString &caption, const wxString &message, bool canBypass) = 0
		\brief Method to use to display a warning to the user.

		\param caption caption of message dialog
		\param message warning message to display
		\param canBypass must be TRUE if the user can have the possibility to bypass this warning
		\return true, if user has clicked on OK
	*/
	virtual bool DisplayWarning (const wxString &caption, const wxString &message, bool canBypass) = 0;


	/*! \fn virtual void DisplayDocInfo (const wxString &docInfo) = 0
		\brief Method to use to display document information.

		Note that this method does not know the format to display the information.
		It merely displays the wxString at the right place.

		\param docInfo String to be displayed.
	*/
	virtual void DisplayDocInfo (const wxString &docInfo) = 0;


	/*! \fn virtual void DisplayHint (const wxString &hint) = 0
		\brief Method to use to display hints such as tooltips.

		Note that this method does not know the format to display the information.
		It merely displays the wxString at the right place.

		\param hint String to be displayed.
	*/
	virtual void DisplayHint (const wxString &hint) = 0;


	/*! \fn virtual void StartProgressInfo (unsigned int maxProgress, const wxString &progressInfo) = 0
		\brief Method to use to start displaying progress info.

		\param maxProgress Maximum of the progress value to be displayed.
		\param progressInfo Information about the operation being monitored.
	*/
	virtual void StartProgressInfo (unsigned int maxProgress, const wxString &progressInfo) = 0;


	/*! \fn virtual void DisplayProgressInfo (unsigned int currentProgress, const wxString &progressInfo) = 0
		\brief Method to use to display progress info (GuiMethods::StartProgressInfo() should be called first).

		\param currentProgress Current value of the progress information to be displayed.
		\param progressInfo Information about the operation being monitored.
	*/
	virtual void DisplayProgressInfo (unsigned int currentProgress, const wxString &progressInfo) = 0;


	/*! \fn virtual void EndProgressInfo (const wxString &progressInfo, bool realEnd = FALSE) = 0
		\brief Method to use to stop displaying progress info (GuiMethods::StartProgressInfo() should have been called before).

		\param progressInfo Information about the operation being monitored.
		\param realEnd To specify when this is really the last call to EndProgressInfo.
	*/
	virtual void EndProgressInfo (const wxString &progressInfo, bool realEnd = FALSE) = 0;


	/*! \fn virtual void DisplayAbout () = 0
		\brief Method to display the world famous about dialog.
	*/
	virtual void DisplayAbout () = 0;

protected:
    /*! \fn App ()
		\brief Constructor (hidden because of Singleton pattern)
	*/
	App ();


    /*! \fn virtual ~App ()
		\brief Destructor (hidden because of Singleton pattern)
	*/
	virtual ~App ();

private:
	static App *ms_instance;
};

} // End namespace sw

#endif // SWDOCUMENTFRAME_H

