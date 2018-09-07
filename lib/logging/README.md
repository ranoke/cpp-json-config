# Logging Lib

Header only lib composed only by one header file

## Features
* Unlimited parameter list
* Sequential formatting
* Supports all types that can be printed on stdout with operator<< 

## Use

First include header
```cpp
#include <rickycorte/Logging.hpp>
```

Example use:
```cpp
int a = 1;
std::string msg = " is wrong";

// Print [DEBUG] test 1
RC_DEBUG("test ", a);

// Print [INFO] test 1
RC_INFO("test ", a);

// Print [WARNING] test 1
RC_WARNING("test ", a);

// Print [ERROR] test 1 is wrong
RC_ERROR("test ", a, msg);

// Print [CRITICAL] test 1
RC_CRITICAL("test ", a);
```

## Config

You can define two different variables to toggle INFO and DUBUG logs

* ```HIDE_DEBUG``` toggles DEBUG messages
* ```HIDE_INFO``` toggles INFO messages
* ```SHOW_LOG_TIME``` undefine this variable to hide log date
* ```LOG_SHOW_CURRENT_DAY``` set this variable to true to show current date (only works if SHOW_LOG_TIME is set)
* ```FORCE_THREAD_SAFE``` define this variable if you want to enforce thread safety

## Future improvements
* Write to system logs
* Write on log files