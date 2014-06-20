#include <string>
#include "serpent/funcs.h"

#include "api.h"
#include <iostream>

const char *compileGo(char *code, int *err)
{
    try {
        std::string c = binToHex(compile(std::string(code)));

        return c.c_str();
    }
    catch(std::string &error) {
        *err = 1;
        return error.c_str();
    }
    catch(...) {
        return "Unknown error";
    }
}
