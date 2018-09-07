# Hikari Config Lib

Load/Save settings on json files

## Features

* Global settings file
* Default value save
* No need to generate/ship a default config (automatic generation at runtime)
* Dynamic config generation (keys are added only when you need
* Nested json support

## Use

First ```#include "config/Config.hpp"```

### Global Config

```cpp
using namespace RickyCorte;

std::string res; // get function returns only strings

// You should first call Config::Global::Init()
// This call can be omited, the first call of a get/set will also call Init()

// get the key "i love"
res = Config::Global::Get("i love");   
 
// get the key "i love", if missing return "lewding lolies"            
res = Config::Global::Get("i love", "lewding lolies");

// set the key "test" to "Sono un baka :3"        
Config::Global::Set("test", "Sono un baka :3");

// Works well also with nested jsons
Config::Global::Set("fbi/is/watching", "me");
Config::Global::Set("fbi/is/looking", "into my phone");

Config::Global::Get("fbi/will/not/take/me")

// Clean up global config variables   
Config::Global::Dispose();
```

### Local Config

```cpp

std::string res; // get function returns only strings

// open a config file named "myfile"
// if it exist this loads the content
// Note: this class insance will be bindend to myfile untill disposed
ConfigFile conf("myfile");

// get the key "test"
res = conf.Get("test");   
 
// get the key "test", if missing return "rip"            
res = conf.Get("test", "rip");

// set the key "test" to "Sono un baka :3"        
conf.Set("test", "Sono un baka :3");

// set and get also accept nested json paths
// refer to Global config to see how paths are formatted

```

## Dependencies 
* [nlohmann Json Library](https://github.com/nlohmann/json)

## Limitations

* Only string values for both input and output