///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Config/swConfigManager.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swConfigManager.h"
#endif

#include "swConfigManager.h"

namespace sw {


// Init single instance:
ConfigInterface *ConfigManager::ms_config = NULL;


ConfigManager::ConfigManager ()
{
    // Nothing to do
}


ConfigManager::~ConfigManager ()
{
    // Nothing to do
}


void ConfigManager::SetInstance (ConfigInterface *config)
{
    ConfigManager::Destroy ();
    ConfigManager::ms_config = config;
}


ConfigInterface * ConfigManager::GetInstance ()
{
    return ConfigManager::ms_config;
}


void ConfigManager::Destroy ()
{
    if (ConfigManager::ms_config != NULL) {

        delete ConfigManager::ms_config;
        ConfigManager::ms_config = NULL;
    }
}

} // End namespace sw

