
#include "busycircle.h"

void printSDL_Error(const char *errMsg, ...){
    va_list va;
    va_start(va, errMsg);
    vfprintf(stderr, errMsg, va);
    fprintf(stderr, ": %s", SDL_GetError());
    va_end(va);
}
