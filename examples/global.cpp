#include <iostream>

#include "config/Config.hpp"

int main()
{
    using namespace RickyCorte;

    // Calling a global config function will trigger automatic global initialization
    // This function will always return "" because we never set the key "test"
    // We could add it manually to the json file, but its boaring

    std::cout << "Get: " << Config::Global::Get("test") << std::endl;
    // We can instead tell the library to set a default value for a key
    // For example here we get a nested json key, but we specify a default value
    // This call will return "rip" when key is missing and will also write it on json file!
    // This is super useful to generate config files at runtime without worrying to ship a default one
    std::cout << "Get: " << Config::Global::Get("parent/inner", "rip") << std::endl;

    // Well we can actually set a key
    Config::Global::Set("not_test", "yep :3");

    // We can also set nested keys in the same sub-json!
    Config::Global::Set("parent/middle/alpha", "I love");
    Config::Global::Set("parent/middle/beta", "c++");

    // Just in case you need to deallocate global resources
    Config::Global::Dispose();

    return 0;
}