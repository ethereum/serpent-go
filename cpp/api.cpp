#include <string>

#include "serpent/lllparser.h"
#include "serpent/bignum.h"
#include "serpent/util.h"
#include "serpent/tokenize.h"
#include "serpent/parser.h"
#include "serpent/compiler.h"
#include "serpent/funcs.h"

#include "cpp/api.h"

void free( void* ptr ) {
	std::free(ptr);
}

const char *compileGo(char *code, int *err)
{
    try {
        std::string c = binToHex(compile(std::string(code)));
		char *compiled = (char*)malloc(sizeof(char) * c.size());
		strcpy(compiled, c.c_str());
        return compiled;
    }
    catch(std::string &error) {
        *err = 1;
		char *error_ = (char*)malloc(sizeof(char) * error.size());
		strcpy(error_, error.c_str());
        return error_;
    }
    catch(...) {
		char *error_ = (char*)malloc(sizeof(char) * 13);
		strcpy(error_, "Unknown error");
        return error_;
    }
}
