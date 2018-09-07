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

#ifndef JSONCONFIGLIB_CONFIGFILE_H
#define JSONCONFIGLIB_CONFIGFILE_H

#include <string>

#include <nlohmann/json.hpp>

namespace RickyCorte
{
/**
 * Represents a json config file
 * This is a helper class the enables fast and easy config load/save
 *
 * NO THREAD SAFE
 */
    class ConfigFile
    {
    public:

        /**
         * Create a config file instance that loads/saves the specified file
         *
         * @param cfg_file file to open
         */
        ConfigFile(const std::string &cfg_file);


        /**
         * Get the value of the specified key
         *
         * @param key key to search
         * @return key value if found or ""
         */
        std::string Get(const std::string &key);


        /**
         * Get the value of the specified key, if missing creates a new one with the default value
         *
         * @param key key to search
         * @param default_value default key value
         * @return key value if found, default_value if not found
         */
        std::string Get(const std::string &key, const std::string default_value);


        /**
         * Edit key value and save changes to file
         *
         * @param key key to edit
         * @param value new key value
         * @return false on error
         */
        bool Set(const std::string &key, const std::string &value);

    private:

        /**
         * Loads json data from file
         * In case of errors returns a empty json
         *
         * @param file_name file to load
         * @return json loaded from file, empty object on errors
         */
        nlohmann::json loadJsonFromFile(const std::string& file_name);


        /**
         * Saves json to a file
         *
         * @param file_name file to save
         * @param json json to save
         * @return false on error
         */
        bool saveJsonToFile(const std::string& file_name, const nlohmann::json& json);

        std::string _file_name;
        nlohmann::json _json;

    };
}


#endif
