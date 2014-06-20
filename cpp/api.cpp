#include <string>
#include "serpent/funcs.h"

#include "api.h"

const char *compileGo(char *code)
{
	return compile(std::string(code)).c_str();
}
