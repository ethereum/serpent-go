#include <string>
#include "serpent/funcs.h"

#include "api.h"

const char *compileGo(char *code, int *err)
{
    try {
        return compile(std::string(code)).c_str();
    }
    catch(std::string &error) {
        *err = 1;
        return error.c_str();
    }
}
