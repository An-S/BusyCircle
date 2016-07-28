#include "busycircle.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
TTF_Font *font = NULL;
SDL_Surface *surf = NULL;
SDL_Texture *texture = NULL;


SDL_Renderer *getRenderer(void){
    return renderer;
}

SDL_Texture *getTexture(void){
    return texture;
}

//aquires several SDL resources
void initResources(void){
    //register exit handler
    atexit(freeResources);

    initDiscPlotter(256, 16, 4);

    //following init functions exit when error occurs
    performSDLInit();
    performTTFInit();
    font = openFont();
    window = createSDLWin("Busy circle!");
    renderer = SDL_getRenderer(window);

    //SDL_renderDisc(renderer, font, textColor);
    texture = SDL_renderDisc(renderer, font, 0x00ffffff);
    closeFont(font);
}

//frees the resources again
void freeResources(void){
    if (window){
        SDL_DestroyWindow(window);
    }
    if (renderer){
        SDL_DestroyRenderer(renderer);
    }
    if (texture){
        SDL_DestroyTexture(texture);
    }

    terminateDiscPlotter();

    SDL_Quit();
    if (getError()){
        fprintf(stderr, "Press enter to go on.");
        getchar();
    }
}


