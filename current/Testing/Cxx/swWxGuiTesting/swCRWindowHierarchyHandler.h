///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRWindowHierarchyHandler.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRWINDOWHIERARCHYHANDLER_H
#define SWCRWINDOWHIERARCHYHANDLER_H

#ifdef __GNUG__
    #pragma interface "swCRWindowHierarchyHandler.h"
#endif

#include "Common.h"

#include <map>

namespace sw {
    class ConfigInterface;
}

namespace swTst {

class CRXRCNode;
class CRXRCResource;


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
    virtual wxString FindContainerName (wxWindow *window,
            bool isUnknownCtrl = false);


    /*! \fn virtual CRXRCNode * FindXRCNode (wxWindow *window, bool isUnknownCtrl = false)
        \brief Find window specific XRC node in read-in XRC files.

        \param window window to find XRC node for
        \param isUnknownCtrl must be set to true for handling unknown/foreign
            controls
        \return XRC node in read-in XRC files
    */
    virtual CRXRCNode * FindXRCNode (wxWindow *window,
            bool isUnknownCtrl = false);


    /*! \fn virtual CRXRCNode * FindContainerXRCNode (wxWindow *window, bool isUnknownCtrl = false)
        \brief Find XRC node of container holding given window.

        \param window window to find container XRC node for
        \param isUnknownCtrl must be set to true for handling unknown/foreign
            controls
        \return container XRC node in read-in XRC files
    */
    virtual CRXRCNode * FindContainerXRCNode (wxWindow *window,
            bool isUnknownCtrl = false);

protected:
    /*! \fn CRWindowHierarchyHandler ()
        \brief Constructor
    */
    CRWindowHierarchyHandler ();


    /*! \fn virtual ~CRWindowHierarchyHandler ()
        \brief Destructor
    */
    virtual ~CRWindowHierarchyHandler ();


    /*! \fn virtual void ParseXRC ()
        \brief Read-in XRC files from resource directory identified with global Config.
    */
    virtual void ParseXRC ();


    /*! \fn virtual CRXRCNode * FindXRCNode (CRXRCNode *parent, wxWindow *window, bool isUnknownCtrl = false)
        \brief Find window specific XRC node as child of given parent.

        \param parent parent XRC node to start search
        \param window window to find XRC node for
        \param isUnknownCtrl must be set to true for handling unknown/foreign
            controls
        \return XRC node in read-in XRC files
    */
    virtual CRXRCNode * FindXRCNode (CRXRCNode *parent, wxWindow *window,
            bool isUnknownCtrl = false);

private:
    static CRWindowHierarchyHandler *ms_instance;

    CRXRCResource *m_xrcResource;
    sw::ConfigInterface *m_configCached;
    wxString m_resDirCached;

    typedef std::map< wxString, wxString > ContainerMap;
    ContainerMap m_contMap;

private:
    // No copy and assignment constructor:
    CRWindowHierarchyHandler (const CRWindowHierarchyHandler &rhs);
    CRWindowHierarchyHandler & operator= (const CRWindowHierarchyHandler &rhs);
};

} // End namespace swTst

#endif // SWCRWINDOWHIERARCHYHANDLER_H

