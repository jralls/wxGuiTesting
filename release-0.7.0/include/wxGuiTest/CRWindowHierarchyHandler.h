///////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiTest/CRWindowHierarchyHandler.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
//
// $Id$
///////////////////////////////////////////////////////////////////////////////

#ifndef CRWINDOWHIERARCHYHANDLER_H
#define CRWINDOWHIERARCHYHANDLER_H

#ifdef __GNUG__
    #pragma interface "CRWindowHierarchyHandler.h"
#endif

#include <wxGuiTest/Common.h>

#include <map>
#include <vector>



namespace wxTst {

/*! \class CRWindowHierarchyHandler
    \brief Handles queries about window hierarchy allowing to uniquely
    symbolically identify controls for C&R (Singleton pattern).    
*/
class CRWindowHierarchyHandler
{
public:
    /*! \fn static CRWindowHierarchyHandler * GetInstance ()
        \brief Get single private instance (Singleton pattern).

        \return single private instance
    */
    static CRWindowHierarchyHandler * GetInstance ();


    /*! \fn static void Destroy ()
        \brief Threadsafe destruction of static singleton instance.
    */
    static void Destroy ();


    /*! \fn virtual wxString FindContainerName (wxWindow *window, bool isUnknownCtrl = false)
        \brief Find name of container holding given window.

        \param window window to find container name for
        \param isUnknownCtrl must be set to true for handling unknown/foreign
            controls
        \return name of first container being holding given window
    */
    virtual wxString FindContainerName (wxWindow *window);

protected:
    /*! \fn CRWindowHierarchyHandler ()
        \brief Constructor
    */
    CRWindowHierarchyHandler ();


    /*! \fn virtual ~CRWindowHierarchyHandler ()
        \brief Destructor
    */
    virtual ~CRWindowHierarchyHandler ();
private:
    static CRWindowHierarchyHandler *ms_instance;
    struct WxStrSort {
	bool operator() (const wxString left, const wxString right) const {
	    return (left.Cmp(right) < 0);
	}
    };

    typedef std::map< wxString, wxString, WxStrSort > ContainerMap;
    static ContainerMap m_contMap;

private:
    // No copy and assignment constructor:
    CRWindowHierarchyHandler (const CRWindowHierarchyHandler &rhs);
    CRWindowHierarchyHandler & operator= (const CRWindowHierarchyHandler &rhs);
};

} // End namespace wxTst

#endif // CRWINDOWHIERARCHYHANDLER_H

