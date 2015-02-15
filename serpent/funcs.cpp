#include <stdio.h>
#include <iostream>
#include <vector>
#include "funcs.h"
#include "bignum.h"
#include "util.h"
#include "parser.h"
#include "lllparser.h"
#include "compiler.h"
#include "rewriter.h"
#include "tokenize.h"
#include "preprocess.h"

Node compileToLLL(std::string input) {
    return rewrite(parseSerpent(input));
}

Node compileChunkToLLL(std::string input) {
    return rewriteChunk(parseSerpent(input));
}

std::string compile(std::string input) {
    return compileLLL(compileToLLL(input));
}

std::vector<Node> prettyCompile(std::string input) {
    return prettyCompileLLL(compileToLLL(input));
}

std::string compileChunk(std::string input) {
    return compileLLL(compileChunkToLLL(input));
}

std::vector<Node> prettyCompileChunk(std::string input) {
    return prettyCompileLLL(compileChunkToLLL(input));
}

std::string mkSignature(std::string input) {
    return mkExternLine(parseSerpent(input));
}

std::string mkFullSignature(std::string input) {
    return mkFullExtern(parseSerpent(input));
}
