///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Config/swConfig.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCONFIG_H
#define SWCONFIG_H

#ifdef __GNUG__
    #pragma interface "swConfig.h"
#endif

#include "Common.h"

#include "swConfigInterface.h"

namespace sw {


/*! \class Config
    \brief Default config implementation
*/
class Config : public ConfigInterface
{
public:
    /*! \fn Config ()
        \brief Constructor
    */
    Config ();


    /*! \fn virtual ~Config ()
        \brief Destructor
    */
    virtual ~Config ();


    /*! \fn virtual void SetResourceDir (const wxString &resDir)
        \brief Set resource directory.

        \param resDir resource directory
    */
    virtual void SetResourceDir (const wxString &resDir);

    
    /*! \fn virtual bool GetResourceDir (wxString &resDir)
        \brief Get resource directory from config.

        \param resDir resource directory
        \return true, if found
    */
    virtual bool GetResourceDir (wxString &resDir);


    /*! \fn virtual bool GetStrConfigProperty (const wxString &key, wxString &value)
        \brief Get string typed property from config.

        \param key key identifying config property
        \param value string typed config property value for given key
        \return true, if found
    */
    virtual bool GetStrConfigProperty (const wxString &key, wxString &value);

protected:

private:
    wxString m_resDir;

private:
    // No copy and assignment constructor:
    Config (const Config &rhs);
    Config & operator= (const Config &rhs);
};

} // End namespace sw

#endif // SWCONFIG_H

