#pragma once
#include <string>
#include <iostream>

namespace Debug
{
    inline std::string last_error;
    inline std::string last_status;

    //-----------------------------------------<>-----------------------------------------//
    // Use this to log NONE-FATAL errors. Will print a message to the console in red text.
    // 
    // Params:
    //  bool condition - will only log the error when condition is false
    //  std::string error - the message to log to the console
    //  int line - use the __LINE__ macro always
    //  int file - use the __FILE__ macro always
    //-----------------------------------------<>-----------------------------------------//
    bool LogError(bool condition, const std::string& error, int line, std::string file);
    bool LogError(bool condition, const char* error, int line, std::string file);

   
    void LogStatus(const std::string& status);
    void LogStatus(const char* status);

    //-----------------------------------------<>-----------------------------------------//
    // Use this to log FATAL errors. Will print a message to the console in red text and 
    // call the assert() macro.
    // 
    // Params:
    //  bool condition - will only log the error when condition is false
    //  std::string error - the message to log to the console
    //  int line - use the __LINE__ macro always
    //  int file - use the __FILE__ macro always
    //-----------------------------------------<>-----------------------------------------//
    void Assert(bool condition, const std::string& error, int line, std::string file);
    void Assert(bool condition, const char* error, int line, std::string file);
};

