///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Config/swConfigInterface.h
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCONFIGINTERFACE_H
#define SWCONFIGINTERFACE_H

#ifdef __GNUG__
    #pragma interface "swConfigInterface.h"
#endif

#include "Common.h"

namespace sw {


/*! \class ConfigInterface
    \brief Config interface definition.

    Only resource directory config property is globally required. Other config
    properties are case dependent.
*/
class ConfigInterface
{
public:
    /*! \fn ConfigInterface ()
        \brief Constructor
    */
    ConfigInterface ();


    /*! \fn virtual ~ConfigInterface ()
        \brief Destructor
    */
    virtual ~ConfigInterface ();


    /*! \fn virtual bool GetResourceDir (wxString &resDir) = 0
        \brief Get resource directory from config.

        \param resDir resource directory
        \return true, if found
    */
    virtual bool GetResourceDir (wxString &resDir) = 0;


    /*! \fn virtual bool GetStrConfigProperty (const wxString &key, wxString &value) = 0
        \brief Get string typed property from config.

        \param key key identifying config property
        \param value string typed config property value for given key
        \return true, if found
    */
    virtual bool GetStrConfigProperty (const wxString &key, wxString &value) = 0;

protected:

private:

private:
    // No copy and assignment constructor:
    ConfigInterface (const ConfigInterface &rhs);
    ConfigInterface & operator= (const ConfigInterface &rhs);
};

} // End namespace sw

#endif // SWCONFIGINTERFACE_H

