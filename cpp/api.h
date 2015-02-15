#ifndef CPP_API_H
#define CPP_API_H

#ifdef __cplusplus
extern "C" {
#endif

void free(void *ptr);

const char *compileGo(char *code, int *err);

#ifdef __cplusplus
}
#endif
 
#endif
