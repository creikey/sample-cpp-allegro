#ifndef HPP_ERROR
#define HPP_ERROR

#include <exception>
#include <string>

#define INITERROR(...) throw InitError(__LINE__, __FILE__, __VA_ARGS__)

class InitError : std::exception
{
  public:
    const char *what() { return errStr.c_str(); };
    InitError(int line, std::string file, std::string function, std::string args) : errStr("Failed to initialize in function " + function + " with args " + args + " line " + std::to_string(line) + " in file " + file){};
    InitError(int line, std::string file, std::string function) : errStr("Failed to initialize in function " + function + " line " + std::to_string(line) + " file " + file){};

  private:
    std::string errStr;
};

class MouseButtonError : std::exception
{
  public:
    const char *what() { return errStr.c_str(); };
    MouseButtonError(int inButton, int maxButton) : errStr("Mouse button " + std::to_string(inButton) + " greater than maximum " + std::to_string(maxButton)){};

  private:
    std::string errStr;
};

#endif // HPP_ERROR