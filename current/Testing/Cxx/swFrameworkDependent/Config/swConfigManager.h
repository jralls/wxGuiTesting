///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Config/swConfigManager.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCONFIGMANAGER_H
#define SWCONFIGMANAGER_H

#ifdef __GNUG__
    #pragma interface "swConfigManager.h"
#endif

#include "Common.h"

#include "swConfigInterface.h"

namespace sw {


/*! \class ConfigManager
    \brief Singleton instance of global config.
*/
class ConfigManager
{
public:
    /*! \fn static void SetInstance (ConfigInterface *config)
        \brief Set single private instance (Singleton pattern).

        Setting a NULL config destroys the current config; likewise, if any old
        config is active when a new one is set, the old one is destroyed.

        \param config single config instance
    */
    static void SetInstance (ConfigInterface *config);


    /*! \fn static ConfigInterface * GetInstance ()
        \brief Get single private instance (Singleton pattern).

        \return single private instance
    */
    static ConfigInterface * GetInstance ();


    /*! \fn static void Destroy ()
        \brief Threadsafe destruction of static singleton instance.
    */
    static void Destroy ();

protected:
    /*! \fn ConfigManager ()
        \brief Constructor
    */
    ConfigManager ();


    /*! \fn virtual ~ConfigManager ()
        \brief Destructor
    */
    virtual ~ConfigManager ();

private:
    static ConfigInterface *ms_config;

private:
    // No copy and assignment constructor:
    ConfigManager (const ConfigManager &rhs);
    ConfigManager & operator= (const ConfigManager &rhs);
};

} // End namespace sw

#endif // SWCONFIGMANAGER_H

