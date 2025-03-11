#include "Log.h"
#include <cassert>

// ANSI escape codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

namespace Debug
{   
    bool LogError(bool condition, const std::string& error, int line, std::string file)
    {
        if (condition)
            return false;

        std::string filename = file.substr(file.find_last_of("/\\") + 1);

        std::string formatted_error = "[+]Error: " + filename + " " + "Line: " + std::to_string(line) + "\n    " + error + "\n";
        std::cout << RED << formatted_error << RESET;
        last_error = formatted_error;

        return true;
    }

    bool LogError(bool condition, const char* error, int line, std::string file)
    {
        return LogError(condition, std::string{ error }, line, file);
    }

    void LogStatus(const std::string& status)
    {
        std::string formatted_status = "[+]Status: " + status + "\n";
        std::cout << GREEN << formatted_status << RESET;
        last_status = formatted_status;
    }
    void LogStatus(const char* status)
    {
        LogStatus(std::string{ status });
    }

    void Assert(bool condition, const std::string& error, int line, std::string file)
    {
        if (condition)
            return;

        std::string filename = file.substr(file.find_last_of("/\\") + 1);

        std::string formatted_error = "[+]Error: " + filename + " " + "Line: " + std::to_string(line) + "\n    " + error + "\n";
        std::cout << RED << formatted_error << RESET;
        last_error = formatted_error;

        assert(condition);
    }

    void Assert(bool condition, const char* error, int line, std::string file)
    {
        Assert(condition, std::string{ error }, line, file);
    }
}