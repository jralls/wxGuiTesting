///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/FrameFactory/swToolBarRegistry.h
// Author:      Reinhold Füreder
// Created:     2005
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWTOOLBARREGISTRY_H
#define SWTOOLBARREGISTRY_H

#ifdef __GNUG__
    #pragma interface "swToolBarRegistry.h"
#endif

#include "Common.h"

#include <map>

#include "swToolBar.h"

namespace sw {


/*! \class ToolBarRegistry
    \brief Registry for looking up toolbars at runtime (Singleton pattern).

    This is mainly necessary for GUI testing, but also because of using
    different frame factories and huge differences with respect to their
    respective toolbars. So, no general way of getting access to them is
    possible.
*/
class ToolBarRegistry
{
public:
    /*! \fn static ToolBarRegistry * GetInstance ()
		\brief Get single registry instance.

		\return registry instance
	*/
	static ToolBarRegistry * GetInstance ();


    /*! \fn static void Destroy ()
        \brief Threadsafe destruction of static singleton instance.
    */
    static void Destroy ();


    /*! \fn virtual bool Register (ToolBar *toolbar, const wxString &name)
		\brief Register a toolbar.

        \param toolbar toolbar to register
        \param name name of toolbar to register
		\return true, if registering succeeded
	*/
    virtual bool Register (ToolBar *toolbar, const wxString &name);


    /*! \fn virtual bool Unregister (const wxString &name)
		\brief Unregister a toolbar.

        Does not delete the toolbar instance!

        \param name name of toolbar to unregister
		\return true, if unregistering succeeded
	*/
    virtual bool Unregister (const wxString &name);


	/*! \fn virtual ToolBar * FindToolBarByName (const wxString &name) const
		\brief Find toolbar with given name.

        Initially required for testing, but might be helpful in other cases too.

        \param name name of toolbar to find
        \return toolbar with given name, or NULL
	*/
    virtual ToolBar * FindToolBarByName (const wxString &name) const;


	/*! \fn virtual wxString FindToolBarNameByWdwPtr (wxWindow *wdw) const
		\brief Find name of toolbar based on given window pointer.

        Only for Capture & Replay!

        \param wdw window pointer to toolbar to find
        \return name of toolbar with given window pointer address, or NULL
	*/
    virtual wxString FindToolBarNameByWdwPtr (wxWindow *wdw) const;

protected:
    /*! \fn ToolBarRegistry ()
        \brief Constructor (hidden because of Singleton pattern)
    */
    ToolBarRegistry ();


    /*! \fn virtual ~ToolBarRegistry ()
        \brief Destructor
    */
    virtual ~ToolBarRegistry ();

private:
    static ToolBarRegistry *ms_instance;

    typedef std::map < const wxString, ToolBar *> ToolBarMap;
	ToolBarMap m_toolBarMap;

private:
    ToolBarRegistry (const ToolBarRegistry&);  // Not implemented.
    void operator= (const ToolBarRegistry&);  // Not implemented.
};

} // End namespace sw

#endif // SWTOOLBARREGISTRY_H

