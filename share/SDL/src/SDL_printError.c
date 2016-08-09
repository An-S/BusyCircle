
#include "busycircleInterface.h"


static int _exitcode;

void printSDL_Error(const char *errMsg, ...){
    const char *emsg;
    va_list va;
    va_start(va, errMsg);
    vfprintf(stderr, errMsg, va);
    emsg = SDL_GetError();
    if (emsg){
        fprintf(stderr, "/ SDL_Error: %s\n", emsg);
    }
    va_end(va);
}

void setErrorAndExit(int exitcode){
    _exitcode = exitcode;
    if (exitcode) exit(exitcode);
}

int getError(void){
    return _exitcode;
}
