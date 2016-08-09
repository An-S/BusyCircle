#include "busycircleInterface.h"

/** \brief wraps sdl init function and exits on error
 *
 * \param
 * \param
 * \return
 *
 */
void performSDLInit(void){
    if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0 ){
        printSDL_Error(__FUNCTION__);
        //fprintf(stderr, "SDL_Init() Error: %s\n", SDL_GetError());
        setErrorAndExit(SDL_INIT_ERR);
    }
}

/** \brief creates a windows for SDL output having a predefined screen size
 *
 * \param const char *name of the windows
 * \param
 * \return SDL_Window *reference to window struct
 *
 */
SDL_Window *createSDLWin(const char *name){
    SDL_Window *window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window){
        printSDL_Error(__FUNCTION__);
        setErrorAndExit(SDL_WINDOW_ERR);
    }
    return window;
}

/** \brief inits a renderer for grafic functions
 *
 * \param the window, where the rendered output should be directed to
 * \param
 * \return SDL_Renderer *reference to renderer
 *
 */
SDL_Renderer *SDL_getRenderer(SDL_Window *window){
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(!renderer) {
        printSDL_Error("SDL_CreateRenderer()");
        setErrorAndExit(SDL_RENDERER_ERR);
    }
    return renderer;
}

/** \brief check SDL event queue for quit event or equivalent escape key event
 *
 * \param
 * \param
 * \return bool quit
 *
 */
bool SDL_checkQuitEvent(void){
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return true;
        }
        else if(event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                return true;
            }
        }
    }
    return false;
}

//Change from an "int color" to an SDL_Color
SDL_Color SDL_translateColor(Uint32 int_color){
    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
    SDL_Color color =   {   (int_color & 0x00ff0000)/0x10000,
                            (int_color & 0x0000ff00)/0x100,
                            (int_color & 0x000000ff),
                            0
                        };
    #else
    SDL_Color color =   {   (int_color & 0x000000ff),
                            (int_color & 0x0000ff00)/0x100,
                            (int_color & 0x00ff0000)/0x10000,
                            0
                        };
    #endif
    return color;
}
