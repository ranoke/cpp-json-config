/*
 * C++ Json Config Lib
 *
 * Copyright (C) 2018 RickyCorte
 *
 * This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
 * This is free software, and you are welcome to redistribute it
 * under certain conditions; type `show c' for details.
 *
 */

#ifndef JSONCONFIGLIB_CONFIG_H
#define JSONCONFIGLIB_CONFIG_H

#define GLOBAL_CONFIG_FILE "global.conf"

#include <string>

#include <rickycorte/Logging.hpp>

#include "ConfigFile.hpp"

namespace RickyCorte
{
    namespace Config
    {

        namespace Global
        {
            /**
             * Initialize global configuration file
             */
            void Init();


            /**
             * Get key value from global config file
             *
             * @param key key to find
             * @param default_value default key value
             * @return key value or default_value if key is missing
             */
            std::string Get(const std::string& key, const std::string& default_value);


            /**
             * Get key value from global config file
             *
             * @param key key to find
             * @return key value or "" if key is missing
             */
            std::string Get(const std::string& key);


            /**
             * Set key valeu of global config
             *
             * @param key key to set
             * @param value value to set
             * @return false on errors
             */
            bool Set(const std::string& key, const std::string& value);


            /**
             * Clean up global save instance
             */
            void Dispose();

        }
    }
}

#endif
