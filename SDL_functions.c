#include "busycircle.h"

void performSDLInit(void){
    if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0 ){
        printSDL_Error(__FUNCTION__);
        //fprintf(stderr, "SDL_Init() Error: %s\n", SDL_GetError());
        setErrorAndExit(SDL_INIT_ERR);
    }
}


SDL_Window *createSDLWin(const char *name){
    SDL_Window *window = NULL;//SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window){
        printSDL_Error(__FUNCTION__);
        setErrorAndExit(SDL_WINDOW_ERR);
    }
    return window;
}


