#include "busycircleInterface.h"


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
Resources_t *initResources(void){
	Resources_t *res = malloc(sizeof(Resources_t));
    //register exit handler
    //atexit(freeResources);

    initDiscPlotter(256, 16, 4);

    //following init functions exit when error occurs
    performSDLInit();
    performTTFInit();
    font = openFont();
    window = createSDLWin("Busy circle!");
    res->rend = SDL_getRenderer(window);

    //SDL_renderDisc(renderer, font, textColor);
    res->tex = SDL_renderDisc(res->rend, font, 0x00ffffff);
    closeFont(font);
    return res;
}

//frees the resources again
void freeResources(Resources_t *res){
    if (window){
        SDL_DestroyWindow(window);
    }
    if (res->rend){
        SDL_DestroyRenderer(res->rend);
    }
    if (res->tex){
        SDL_DestroyTexture(res->tex);
    }
	free(res);
    terminateDiscPlotter();

    SDL_Quit();
    if (getError()){
        fprintf(stderr, "Press enter to go on.");
        getchar();
    }
}


