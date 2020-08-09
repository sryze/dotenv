#include <cstdlib>
#include <fstream>
#include <vector>
#include "dotenv.h"

#ifdef _WIN32
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #include <windows.h>
#endif

namespace dotenv {

std::string get(const std::string &name, const std::string &default_value)
{
    const char *value = getenv(name.c_str());
    return value != nullptr ? std::string(value) : default_value;
}

void set(const std::string &name, const std::string &value)
{
#ifdef _WIN32
    auto var = name + "=" + value;
    (void)_putenv(var.c_str());
#else
    setenv(name.c_str(), value.c_str(), true);
#endif
}

void unset(const std::string &name)
{
#ifdef _WIN32
    SetEnvironmentVariableA(name.c_str(), NULL);
#else
    unsetenv(name.c_str());
#endif
}

void load(const std::string &filename)
{
    std::ifstream stream(filename);
    std::string line;

    while (std::getline(stream, line)) {
        auto sep_pos = line.find('=');
        if (sep_pos == std::string::npos) {
            continue;
        }
        set(line.substr(0, sep_pos), line.substr(sep_pos + 1));
    }
}

} // namespace dotenv
